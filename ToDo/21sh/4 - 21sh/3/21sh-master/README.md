# 21sh

The second in a sequence of three shells, this one handles advanced command lines, especially with pipes and redirections.

The following builtins are included : echo, cd, env, setenv, unsetenv, exit.

A Line-edition is provided, thanks to the termcaps library, using the shortcuts below :

left/right arrows : move through the command line.

up/down arrows : move through history.

shift + left/right : move by word.

shift + up/down : move by line.

home : move to the command line's start.

end : move to the command line's end.

alt + s/x : copy/cut from the cursor to the end of the command line.

alt + d/c : copy/cut the whole command line.

alt + v : paste the buffer.
