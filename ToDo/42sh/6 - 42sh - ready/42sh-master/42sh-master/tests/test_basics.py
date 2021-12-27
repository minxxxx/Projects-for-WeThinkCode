import os
import subprocess
import unittest
import tools

BINARY_NAME = "42sh"


class TestBasics(unittest.TestCase):
    tests_dir = os.path.split(__file__)[0]
    binary = "%s/../%s" % (tests_dir, BINARY_NAME)
    prompt = ""
    valgrind = False

    @classmethod
    def setUpClass(cls):
        if os.path.isfile(cls.binary) is False:
            raise IOError("Make the project: %s not here\n" % cls.binary)
        cls.prompt = cls.get_prompt(cls.binary)
        try:
            if os.getenv("VALGRIND") == "TRUE" and subprocess.call(["valgrind", "--version"]) == 0:
                cls.valgrind = True
        except OSError:
            os.write(2, "WARNING: No valgrind\n")

    @staticmethod
    def get_prompt(binary):
        cmd_list = ["/bin/echo", "-n"]
        p_command = subprocess.Popen(cmd_list, stdout=subprocess.PIPE)
        p_minishell = subprocess.Popen(
            ["%s" % binary], stdin=p_command.stdout, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        p_command.stdout.close()
        stdout, stderr = p_minishell.communicate()
        return stdout

    def execute_my_shell(self, command):
        """
        Here my shell
        :param command: list of command like ["/bin/ls", "-l"]
        :return:
        """
        cmd_list = ["/bin/echo", "-n"] + command
        p_command = subprocess.Popen(cmd_list, stdout=subprocess.PIPE)
        p_minishell = subprocess.Popen(
            ["%s" % self.binary], stdin=p_command.stdout, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        p_command.stdout.close()
        stdout, stderr = p_minishell.communicate()

        stdout = stdout.replace("%s\n" % self.prompt, "")
        stdout = stdout.replace("%s" % self.prompt, "")

        if self.valgrind:
            tools.valgrind_wrapper(self.binary, command)

        return stdout, stderr

    @staticmethod
    def execute_real_shell(command):
        """
        Here the real shell
        :param command: list of command like ["/bin/ls", "-l"]
        :return:
        """
        cmd_list = ["/bin/echo"] + command
        p_command = subprocess.Popen(cmd_list, stdout=subprocess.PIPE)
        p_real_shell = subprocess.Popen(
            ["/bin/bash"], stdin=p_command.stdout, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        p_command.stdout.close()
        stdout, stderr = p_real_shell.communicate()
        return stdout, stderr.replace("/bin/bash: line 1: ", "")  # because of bash piping

    def compare_shells(self, command):
        real_std = self.execute_real_shell(command)
        my_std = self.execute_my_shell(command)
        self.assertEqual(real_std, my_std)

    def test_00_prompt_is_removed(self):
        stdout, stderr = self.execute_my_shell([""])
        self.assertEqual("", stdout)
        self.assertEqual("", stderr)

    def test_ls_00(self):
        self.compare_shells(["ls"])

    def test_ls_01(self):
        self.compare_shells(["/bin/ls"])

    def test_ls_02(self):
        self.compare_shells(["/bin/ls", "-r"])

    def test_ls_03(self):
        self.compare_shells(["/bin/ls", "-rt"])

    def test_ls_04(self):
        self.compare_shells(["/bin/ls", "-r", "-l"])

    def test_ls_05(self):
        self.compare_shells(["/bin/ls", "-r", "-l", "."])

    def test_ls_06(self):
        self.compare_shells(["/bin/ls", "-r", "-l", "notherefile"])

    def test_ls_07(self):
        self.compare_shells(["  ls"])

    def test_ls_08(self):
        self.compare_shells(["  ls    "])

    def test_ls_09(self):
        self.compare_shells(["  ls    ", "  -r  "])

    def test_env_00(self):
        my_env = self.execute_my_shell(["env"])[0]
        self.assertIn("PATH=", my_env)
        self.assertIn("PWD=", my_env)

    def test_env_01(self):
        my_env = self.execute_my_shell(["env", "-i"])
        self.assertEqual(("", ""), my_env)

    def test_setenv_00(self):
        my_shell = self.execute_my_shell(["setenv", "key", "value"])
        self.assertEqual(("", ""), my_shell)

    def test_setenv_01(self):
        my_shell = self.execute_my_shell(["setenv"])
        self.assertEqual(("", ""), my_shell)

    def test_setenv_02(self):
        my_shell = self.execute_my_shell(["setenv", "one_arg"])
        self.assertEqual(("", ""), my_shell)

    def test_setenv_03(self):
        my_shell = self.execute_my_shell(["setenv", "one", "two", "more"])
        self.assertEqual(("", ""), my_shell)

    def test_setenv_04(self):
        my_shell = self.execute_my_shell(["setenv", "one", "two", "more", "more"])
        self.assertEqual(("", ""), my_shell)

    def test_nocommand_00(self):
        cmd = "inexistcommandinpathandbuiltin"
        my_shell = self.execute_my_shell([cmd])
        self.assertEqual(("", "42sh: command not found: %s\n" % cmd), my_shell)

    def test_nocommand_01(self):
        cmd = "inexistcommandinpathandbuiltin"
        my_shell = self.execute_my_shell([cmd, "-flag"])
        self.assertEqual(("", "42sh: command not found: %s\n" % cmd), my_shell)

    def test_exit_00(self):
        self.compare_shells(["exit"])

    def test_exit_01(self):
        self.compare_shells(["exit", "0"])

    def test_exit_02(self):
        self.compare_shells(["exit", "1"])

    def test_exit_03(self):
        my_shell = self.execute_my_shell(["exit", "not numeric"])
        self.assertEqual(("", ""), my_shell)

    def test_cd_00(self):
        home = "/tmp"
        os.environ["HOME"] = home
        my_shell = self.execute_my_shell(["cd"])
        self.assertIn(home, my_shell[0])

    def test_cd_01(self):
        oldpwd = "/tmp"
        os.environ["OLDPWD"] = oldpwd
        my_shell = self.execute_my_shell(["cd", "-"])
        self.assertIn(oldpwd, my_shell[0])

    def test_cd_02(self):
        my_shell = self.execute_my_shell(["cd", "."])
        self.assertEqual("", my_shell[0])

    def test_cd_03(self):
        my_shell = self.execute_my_shell(["cd", "////"])
        self.assertIn("/", my_shell[0])

    def test_cd_04(self):
        dot_dot = "/../.." * 50
        my_shell = self.execute_my_shell(["cd", dot_dot])
        self.assertIn("/", my_shell[0])

    def test_exec_dir_00(self):
        directory = "/bin"
        my_shell = self.execute_my_shell([directory])
        self.assertEqual("42sh: permission denied: %s\n" % directory, my_shell[1])
        self.assertEqual("", my_shell[0])

    def test_exec_fake_00(self):
        exe = "./fakeexec"
        if os.path.isfile(exe):
            os.remove(exe)
        with open(exe, "w") as f:
            f.write("fake exec\n")
        os.chmod(exe, 0755)
        my_shell = self.execute_my_shell([exe])
        os.remove(exe)
        self.assertEqual("42sh: exec format error: %s\n" % exe, my_shell[1])

    def test_exec_fake_01(self):
        exe = "./fakeexec"
        if os.path.isfile(exe):
            os.remove(exe)
        with open(exe, "w") as f:
            f.write("fake exec\n")
        os.chmod(exe, 0000)
        my_shell = self.execute_my_shell([exe])
        os.remove(exe)
        self.assertEqual("42sh: permission denied: %s\n" % exe, my_shell[1])

    def test_exec_fake_02(self):
        exe = "./fakeexec"
        if os.path.isfile(exe):
            os.remove(exe)
        with open(exe, "w") as f:
            f.write("fake exec\n")
        os.chmod(exe, 0444)
        my_shell = self.execute_my_shell([exe])
        os.remove(exe)
        self.assertEqual("42sh: permission denied: %s\n" % exe, my_shell[1])

    def test_exec_fake_03(self):
        exe = "./fakeexec"
        if os.path.isfile(exe):
            os.remove(exe)
        with open(exe, "w") as f:
            f.write("fake exec\n")
        os.chmod(exe, 0666)
        my_shell = self.execute_my_shell([exe])
        os.remove(exe)
        self.assertEqual("42sh: permission denied: %s\n" % exe, my_shell[1])

    def test_exec_fake_04(self):
        exe = "./fakeexec"
        if os.path.isfile(exe):
            os.remove(exe)
        with open(exe, "w") as f:
            f.write("fake exec\n")
        os.chmod(exe, 0333)
        my_shell = self.execute_my_shell([exe])
        os.remove(exe)
        self.assertEqual("42sh: exec format error: %s\n" % exe, my_shell[1])

    def test_exec_fake_05(self):
        exe = "./fakeexec"
        if os.path.isfile(exe):
            os.remove(exe)
        with open(exe, "w") as f:
            f.write("fake exec\n")
        os.chmod(exe, 0222)
        my_shell = self.execute_my_shell([exe])
        os.remove(exe)
        self.assertEqual("42sh: permission denied: %s\n" % exe, my_shell[1])

    def test_exec_fake_06(self):
        exe = "./fakeexec"
        if os.path.isfile(exe):
            os.remove(exe)
        with open(exe, "w") as f:
            f.write("fake exec\n")
        os.chmod(exe, 0111)
        my_shell = self.execute_my_shell([exe])
        os.remove(exe)
        self.assertEqual("42sh: exec format error: %s\n" % exe, my_shell[1])


if __name__ == "__main__":
    unittest.main()
