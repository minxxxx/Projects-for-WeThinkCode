import os
import subprocess
import unittest

from tests import tools

BINARY_NAME = "42sh"


class TestBasics(unittest.TestCase):
    tests_dir = os.path.split(__file__)[0]
    binary = "%s/../%s" % (tests_dir, BINARY_NAME)
    prompt = ""
    valgrind = False

    @classmethod
    def setUpClass(cls):
        os.write(1, "\nRunning %s\n" % __file__)
        if os.path.isfile(cls.binary) is False:
            raise IOError("Make the project: %s not here\n" % cls.binary)
        cls.prompt = cls.get_prompt(cls.binary)
        try:
            if os.getenv("VALGRIND") == "TRUE" and subprocess.call(["valgrind", "--version"]) == 0:
                cls.valgrind = True
        except OSError:
            os.write(2, "WARNING: No valgrind\n")

    @classmethod
    def tearDownClass(cls):
        os.write(1, "\n")

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

    def test_semi_00(self):
        self.compare_shells(["ls", ";", "ls"])

    def test_pipe_00(self):
        self.compare_shells(["ls", "|", "cat -e"])

    def test_pipe_01(self):
        self.compare_shells(["ls", "|", "cat -e", "|", "sort"])

    def test_pipe_02(self):
        self.compare_shells(["ls", "|", "cat -e", "|", "sort", "|", "rev", "|", "sort", "|", "cat -e"])

    def test_pipe_03(self):
        self.compare_shells(["ls", "|", "cat -e", "|", "sort", "|", "rev", "|", "sort", "|", "cat -e",
                             "|", "cat -e", "|", "sort", "|", "rev", "|", "sort", "|", "cat -e"])

    def test_pipe_04(self):
        self.compare_shells(["ls", "|", "cat -e", "|", "sort", "|", "rev", "|", "sort", "|", "cat -e",
                             "|", "cat -e", "|", "sort", "|", "rev", "|", "sort", "|", "cat -e",
                             "|", "cat -e", "|", "cat -e", "|", "cat -e"])

    def test_pipe_05(self):
        ret = self.execute_my_shell(["ls", "|", "cat -e", "|"])
        self.assertEqual(("", "42sh: parse error near '|' or '&'\n"), ret)

    def test_pipe_06(self):
        ret = self.execute_my_shell(["ls", "|", "cat -e", "|", "|"])
        self.assertEqual(("", "42sh: parse error near '|' or '&'\n"), ret)

    def test_pipe_07(self):
        ret = self.execute_my_shell(["|", "ls", "|", "cat -e"])
        self.assertEqual(("", "42sh: parse error near '|' or '&'\n"), ret)

    def test_pipe_08(self):
        ret = self.execute_my_shell(["|", "ls", "|", "cat -e", "|"])
        self.assertEqual(("", "42sh: parse error near '|' or '&'\n"), ret)

    def test_pipe_09(self):
        ret = self.execute_my_shell(["ls", "|", "cat | -e"])
        self.assertEqual(("", "42sh: command not found: -e\n"), ret)

    def test_pipe_100_pipe(self):
        base = ["ls"]

        for i in range(20):
            base.append("|")
            base.append("cat -e")

        self.compare_shells(base)

    def test_right_00(self):
        out = "out"
        self.compare_shells(["ls", ">", "%s" % out])
        os.remove(out)

    def test_and_00(self):
        self.compare_shells(["ls", "&&", "ls"])

    def test_and_01(self):
        ret = self.execute_my_shell(["nocommand", "&&", "ls"])
        self.assertEqual(("", "42sh: command not found: nocommand\n"), ret)

    def test_and_02(self):
        self.compare_shells(["ls", "&&", "ls", "&&", "ls", "&&", "ls", "&&", "ls", "&&", "ls", "&&", "ls"])

    def test_or_00(self):
        self.compare_shells(["false", "||", "ls"])

    def test_or_01(self):
        self.compare_shells(["false", "||", "ls", "||", "ls"])

    def test_right_01(self):
        my_out = "out.my"
        ref_out = "out.ref"
        for f in [my_out, ref_out]:
            with open(f, 'w') as fd:
                fd.write("")
        self.execute_my_shell(["ls", ">", "%s" % my_out])
        self.execute_real_shell(["ls", ">", "%s" % ref_out])
        with open(my_out, 'r') as my:
            with open(ref_out, 'r') as ref:
                self.assertEqual(ref.read(), my.read())
        for f in [my_out, ref_out]:
            os.remove(f)

    def test_right_02(self):
        my_out = "out.my"
        ref_out = "out.ref"
        for f in [my_out, ref_out]:
            with open(f, 'w') as fd:
                fd.write("")
        try:
            self.execute_my_shell(["ls", ">", "%s" % my_out])
            self.execute_my_shell(["ls", ">>", "%s" % my_out])
            self.execute_real_shell(["ls", ">", "%s" % ref_out])
            self.execute_real_shell(["ls", ">>", "%s" % ref_out])
            if self.valgrind:
                self.execute_real_shell(["ls", ">>", "%s" % ref_out])
            with open(my_out, 'r') as my:
                with open(ref_out, 'r') as ref:
                    self.assertEqual(ref.read(), my.read())
        finally:
            for f in [my_out, ref_out]:
                os.remove(f)

    def test_right_03(self):
        my_out = "out.my"
        ref_out = "out.ref"
        for f in [my_out, ref_out]:
            with open(f, 'w') as fd:
                fd.write("")
        try:
            self.execute_my_shell(["ls", ">", "%s" % my_out])
            self.execute_my_shell(["ls", ">>", "%s" % my_out])
            self.execute_my_shell(["ls", ">", "%s" % my_out])
            self.execute_real_shell(["ls", ">", "%s" % ref_out])
            self.execute_real_shell(["ls", ">>", "%s" % ref_out])
            self.execute_real_shell(["ls", ">", "%s" % ref_out])
            with open(my_out, 'r') as my:
                with open(ref_out, 'r') as ref:
                    self.assertEqual(ref.read(), my.read())
        finally:
            for f in [my_out, ref_out]:
                os.remove(f)

    def test_left_00(self):
        my_in = "in.my"
        with open(my_in, 'w') as fd:
            fd.write("data")
        self.compare_shells(["cat", "<", "%s" % my_in])
        os.remove(my_in)

    def test_left_pipe_00(self):
        my_in = "in.my"
        with open(my_in, 'w') as fd:
            fd.write("data")
        self.compare_shells(["cat", "<", "%s" % my_in, "|", "cat -e"])
        os.remove(my_in)

    def test_left_pipe_01(self):
        my_in = "in.my"
        with open(my_in, 'w') as fd:
            fd.write("3\n2\n1\n")
        self.compare_shells(["cat", "<", "%s" % my_in, "|", "cat -e", "|", "sort"])
        os.remove(my_in)

    def test_left_pipe_right_00(self):
        data_in = "in.data"
        my_out = "out.my"
        ref_out = "out.ref"
        try:
            for f in [my_out, ref_out]:
                with open(f, 'w') as fd:
                    fd.write("")
            with open(data_in, 'w') as fd:
                fd.write("3\n2\n1\n")

            def cli(output):
                return ["cat", "<", "%s" % data_in, "|", "cat -e", "|", "sort", ">", "%s" % output]

            self.execute_my_shell(cli(my_out))
            self.execute_real_shell(cli(ref_out))

            with open(my_out, 'r') as my:
                with open(ref_out, 'r') as ref:
                    self.assertEqual(ref.read(), my.read())
        finally:
            for f in [data_in, my_out, ref_out]:
                os.remove(f)


if __name__ == "__main__":
    unittest.main()
