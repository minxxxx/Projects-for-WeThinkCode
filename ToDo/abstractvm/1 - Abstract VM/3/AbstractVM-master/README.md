# AbstractVM
WeThinkCode project to code an abstract VM in c++.

## About the project

AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the machine as basic assembly programs.

## Install

To install abstract VM run the following

#### Input:
```
git clone https://github.com/Moondog360/AbstractVM.git 
cd AbstractVM
make
```

## Commands

Abstract VM accepts the following
The character # is replaced by a number value of your choice

```
push int8(#)
push int16(#)
push int32(#)
push float(#)
push double(#)
add
mul
sub
mod
div
pop
print
assert int8(#)
assert int16(#)
assert int32(#)
assert flaot(#)
assert double(#)
dump
exit
```

Structure of a file:
Needs to be a .avm extension
Can inlcude comments using ";"
Needs an exit commands

### Example:
```
push int8(1) ; Anything type after the ; is a comment
dump
exit ; needs this exit
```

## How to use

This program comes with 4 modes.

### Normal mode:
	Run abstract vm as follow and give inputs. 

#### Input:

```
./avm
push int8(1)
push int8(2)
dump
add
dump
exit
;;
```

#### Output:

```
2
1
3
```

### Interactive mode:
	This mode executes the commands as it's given. Use -i flag

#### Input/Output:
```
./avm -i
input : push int8(1)
input : dump
output: 1
input : exit
input : ;;
```
### Create File mode:
	Similar to normal mode but creates temp.avm file instead of executing commands

#### Input:
```
./avm -F
push int8(1)
push int8(2)
dump
add
dump
exit
;;
```
#### Output:
```
cat temp.avm
push int8(1)
push int8(2)
dump
add
dump
exit
```

### Run file mode:
	Give it files or a file and it will execute each valid file

#### Input:
```
./avm file1 file2 file3 ...
```

