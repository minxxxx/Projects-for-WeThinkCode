# Process and memory

This 42 school project is an introduction to linux kernel hacking.

The goal is to modify the kernel sources to add a new syscall.
This syscall will take a PID as an argument, and return some information about it:

```C
struct pid_info {
	pid_t		pid;
	long		state;           /* -1 unrunnable, 0 runnable, >0 stopped: */
	void		*stack;          /* pointer to its stack */
	uint64_t	age;             /* ns since start time */
	pid_t		*children;       /* NUL terminated array */
	pid_t		parent;
	char		*name;           /* executable name, excluding path */
	char		*root;           /* root path of the process */
	char		*pwd;            /* full path */
	size_t		mapped;          /* bytes the kernel has mapped */
};
```

The kernel will allocate memory for some of its non-statically sized outputs (children/name/root/pwd). 

When the caller now longer needs the returned information, it must `munmap()` this memory from its process, 
by passing `.mapped` as size argument to munmap.

#### Adding the syscall

The main goal of the project was to find out how to write a syscall handler, interact with the kernel api to do its work, 
and add it to the syscall_{32;64}.tbl to make it accessible from userspace.

#### Build

Just run `make`. The makefile will copy the required files to the linux source tree at `/user/src/linux-$(uname -r)`,
recompile it, copy the output image to `/boot/` and restart the machine. 

On the next startup you should be up and running your freshly patched kernel.

#### Testing the syscall

A proof-of-concept executable is included in the `/test` directory. It makes calls to our `get_pid_info` syscall,
and uses its output to display a ps-like tree of running processes on the machine.

##### Final grade

**106/100**
