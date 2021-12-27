import os
import subprocess


def valgrind_wrapper(program, command):
    """
    Valgrind wrapper for unittesting in Python for minishell
    :param program: the binary to test
    :param command: the command to run into the minishell like ["ls", "-l"]
    :return: None
    """
    valgrind = ["valgrind", "--leak-check=full"]

    cmd_list = ["/bin/echo", "-n"] + command

    p_command = subprocess.Popen(cmd_list, stdout=subprocess.PIPE)
    p_minishell = subprocess.Popen(
        valgrind + [program], stdin=p_command.stdout, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    p_command.stdout.close()
    stdout, stderr = p_minishell.communicate()

    if cmd_list[0] == "/bin/echo" and cmd_list[1] == "-n":
        cmd_list.pop(0)
        cmd_list.pop(0)

    summary = [leak.split("==    ")[1] for leak in stderr.split("\n") if "lost:" in leak]
    if len(summary) > 0 and "definitely lost: 0 bytes in 0 blocks" not in summary:
        os.write(2, "%s\n%s" % (" ".join(cmd_list), stderr))
        os._exit(2)
        # raise AssertionError("%s\n%s" % (" ".join(cmd_list), stderr))

    summary = stderr.split("\n")[-2].split("== ")[1]
    if "ERROR SUMMARY: 0 errors from 0 contexts" not in summary:
        os.write(2, "%s\n%s" % (" ".join(cmd_list), stderr))
        os._exit(3)
        # raise AssertionError("%s\n%s" % (" ".join(cmd_list), stderr))
