# Welcome Message for Tic Tac Toe

## Overview

We're going to build a simple program that implements only the very first thing a complete Tic Tac Toe program would require, which is to greet the player with a welcome message.

## Objectives

1. Read the output from running `learn`.
2. Use `puts` to print "Welcome to Tic Tac Toe!"
3. Have tests pass locally by running `learn`.
4. Submit solution.

## Instructions

1. Run `learn`
2. Read output.
3. Code solution in `lib/welcome.rb`
4. Run `learn`
5. Read output.
6. If still broken, repeat 3-5
7. If passing, submit with `learn submit`

## Troubleshooting

Here are some things you can try to get more clues to solve the lab.

### 1. Try running `ruby lib/welcome.rb`

When you run `ruby lib/welcome.rb` from your terminal you are asking the Ruby interpreter to run your program. If you see no output, like below, that means there is no code in `lib/welcome.rb` to print "Welcome to Tic Tac Toe!".

![No Puts](http://learn-co-videos.s3.amazonaws.com/ruby/no.puts.in.code.gif)

The solution to this is to make sure you have `puts "Welcome to Tic Tac Toe!"` in `lib/welcome.rb`. A working program should look like:

![Working program](http://learn-co-videos.s3.amazonaws.com/ruby/working.tic.tac.toe.rb.gif)

**Hint: Make sure you've saved `lib/welcome.rb`.**

### 2. Make sure you're printing "Welcome to Tic Tac Toe!" exactly.

When you run `learn` you might see failing tests even though your program seemingly works. The failures might read something like:

```
1) lib/welcome.rb prints "Welcome to Tic Tac Toe!"
   Failure/Error: load './lib/welcome.rb'
     #<IO:0x007fa2b28325a0> received :puts with unexpected arguments
       expected: ("Welcome to Tic Tac Toe!")
            got: ("Welcome to Tic Tac Toe")
   # ./lib/welcome.rb:4:in `puts'
```

An error like this is telling you that the test expects you to print `"Welcome to Tic Tac Toe!"`, but you printed something else. Programming is absolutely precise, make sure your tests are printing exactly "Welcome to Tic Tac Toe!".

<p data-visibility='hidden'>View <a href='https://learn.co/lessons/ttt-1-welcome-rb' title='Welcome Message for Tic Tac Toe'>Welcome Message for Tic Tac Toe</a> on Learn.co and start learning to code for free.</p>
