import os
import shutil
import subprocess
import unittest

from tests import tools

BINARY_NAME = "42sh"


class TestAdvanced(unittest.TestCase):
    tests_dir = os.path.split(__file__)[0]
    binary = "%s/../%s" % (tests_dir, BINARY_NAME)
    prompt = ""
    dev_null = None
    valgrind = False

    @classmethod
    def setUpClass(cls):
        os.write(1, "\nRunning %s\n" % __file__)
        if os.path.isfile(cls.binary) is False:
            raise IOError("Make the project: %s not here\n" % cls.binary)
        cls.prompt = cls.get_prompt(cls.binary)
        cls.dev_null = open("/dev/null", 'w')
        try:
            if os.getenv("VALGRIND") == "TRUE" and subprocess.call(["valgrind", "--version"]) == 0:
                cls.valgrind = True
        except OSError:
            os.write(2, "WARNING: No valgrind\n")

    @classmethod
    def tearDownClass(cls):
        cls.dev_null.close()
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

    def test_00_semi(self):
        folder = "%s.d" % self.test_00_semi.__name__
        cli = ["mkdir", "-p", "%s" % folder, ";", "cd", "%s" % folder, ";", "ls -a"]
        try:
            stdout, stderr = self.execute_my_shell(cli)
            self.assertEqual(stdout[:5], ".\n..\n")
            self.assertEqual(stderr, "")
        finally:
            shutil.rmtree(folder)

    def test_01_semi(self):
        folder = "%s.d" % self.test_01_semi.__name__

        cli = ["mkdir", "-p", "%s" % folder, ";", "cd", "%s" % folder, ";", "pwd",
               ";", "unsetenv", "OLDPWD", ";", "cd", "-"]
        try:
            stdout, stderr = self.execute_my_shell(cli)
            e_path = os.path.abspath(folder)
            self.assertEqual(stdout[:len(e_path)], e_path)
            self.assertEqual(stderr, "cd: OLDPWD not set\n")
        finally:
            shutil.rmtree(folder)

    def test_02_semi(self):
        folder = "%s.d" % self.test_02_semi.__name__

        cli = ["mkdir", "-p", "%s" % folder, ";", "ln", "-s", "%s" % folder, "%s.link" % folder, ";"
                                                                                                 "cd", "-L",
               "%s.link" % folder, ";", "pwd -L"]
        try:
            stdout, stderr = self.execute_my_shell(cli)
            e_path = os.path.abspath(folder)
            self.assertEqual(stderr, "")
            self.assertEqual(stdout[:len("%s.link" % e_path)], "%s.link" % e_path)
        finally:
            shutil.rmtree(folder)
            os.remove("%s.link" % folder)

    def test_03_semi(self):
        folder = "%s.d" % self.test_03_semi.__name__

        cli = ["mkdir", "-p", "%s" % folder, ";", "ln", "-s", "%s" % folder, "%s.link" % folder, ";"
                                                                                                 "cd", "-P",
               "%s.link" % folder, ";", "pwd -L"]
        try:
            stdout, stderr = self.execute_my_shell(cli)
            e_path = os.path.abspath(folder)
            self.assertEqual(stderr, "")
            self.assertEqual(stdout[:len("%s" % e_path)], "%s" % e_path)
        finally:
            shutil.rmtree(folder)
            os.remove("%s.link" % folder)

    def test_04_semi(self):
        folder = "%s.d" % self.test_04_semi.__name__

        cli = ["mkdir", "-p", "%s" % folder, ";", "ln", "-s", "%s" % folder,
               "%s.link" % folder, ";", "cd", "-P",
               "%s.link" % folder, ";", "pwd -L"]
        try:
            stdout, stderr = self.execute_my_shell(cli)
            e_path = os.path.abspath(folder)
            self.assertEqual(stderr, "")
            self.assertEqual(stdout[:len("%s" % e_path)], "%s" % e_path)
        finally:
            shutil.rmtree(folder)
            os.remove("%s.link" % folder)

    def test_ultra_pipe_00(self):
        base = ["ls"]

        tries = int("%d " % os.getenv("ULTRA_PIPES") if os.getenv("ULTRA_PIPES") else 10)

        # os.write(2, "\nStarting %s wait please\n" % self.test_ultra_pipe_00.__name__)

        for i in xrange(tries):
            base.append("|")
            base.append("cat -e")
            try:
                self.compare_shells(base)
            except AssertionError:
                os.write(2, "%s failed at %d pipes\n" % (self.test_ultra_pipe_00.__name__, i))
                if i < 20:
                    raise AssertionError
                break

    def test_and_or_00(self):
        self.compare_shells(["false", "||", "false", "||", "true", "&&", "ls"])

    def test_and_or_01(self):
        self.compare_shells(["false", "||", "false", "||", "true", "&&", "echo", "hello"])

    def test_and_or_02(self):
        self.compare_shells(["false", "||", "false", "||", "true", "&&", "echo", "hello", ";", "echo", "ok"])

    def test_and_or_pipe_00(self):
        self.compare_shells(["false", "||", "false", "||", "true", "&&",
                             "echo", "hello", "|", "cat -e" ";", "echo", "ok"])

    def test_and_or_pipe_01(self):
        self.compare_shells(["false", "||", "false", "||", "true", "&&",
                             "echo", "hello", "|", "cat -e" ";", "echo", "ok", "|", "cat", "-e"])

    def test_and_or_pipe_02(self):
        self.compare_shells(["false", "|", "cat -e", "&&", "echo", "ok"])

    def test_and_or_pipe_03(self):
        self.compare_shells(["false", "|", "cat -e", "&&", "echo", "ok", "|", "false", "||",
                             "echo", "ok2"])

    def test_and_or_pipe_04(self):
        out = self.execute_my_shell(["false", "|", "cat -e", "&&", "echo", "ok", "|", "false", "&&",
                                     "echo", "ok2"])
        self.assertEqual(("", ""), out)

    def test_and_or_pipe_05(self):
        out = self.execute_my_shell(["false", "|", "cat -e", "&&", "echo", "ok", "|", "false", "&&",
                                     "echo", "ok2", ";", "echo", "ok3"])
        self.assertEqual(("ok3\n", ""), out)

    def test_redirection_00(self):
        self.compare_shells(["ls notherethefile 2>&1 | cat -e"])

    def test_redirection_01(self):
        self.compare_shells(["ls notherethefile 2>&1 | cat -e 1>&2 | cat -e"])

    def test_redirection_02(self):
        self.compare_shells(["ls notherethefile 2>&1 | cat -e 1>&2 2>&1 | cat -e"])

    def test_redirection_03(self):
        self.compare_shells(["ls notherethefile 2>&1 1>&2 2>&1 | cat -e"])

    def test_redirection_04(self):
        self.compare_shells(["ls notherethefile 2>&1 1>&2 2>&1 | cat -e && echo 2>&1 ok"])

    def test_redirection_05(self):
        self.compare_shells(["ls notherethefile 2>&1 1>&2 2>&1 | cat -e || echo 2>&1 ok"])

    def test_redirection_06(self):
        self.compare_shells(["ls notherethefile 2>&1 1>&2 2>&1 | cat -e || echo 1>&1 ok"])

    def test_redirection_07(self):
        self.compare_shells(["ls notherethefile 2>&1 1>&2 2>&1 | cat -e || echo 1>&1 ok"])
