EXTRA_CFLAGS		= -I$(src)/include/
PWD			= $(shell pwd)
SRCS			= pid_info/
VERSION			= 4.16.0
KDIR			= /usr/src/linux-$(VERSION)/

cp:
	cp kernel.Makefile $(KDIR)kernel/Makefile
	cp syscalls.h $(KDIR)include/linux/syscalls.h
	cp syscall_64.tbl $(KDIR)arch/x86/entry/syscalls/syscall_64.tbl
	cp /boot/config-$(VERSION) $(KDIR).config; \

config:
	make olddefconfig -C $(KDIR)

default: cp config partial

partial:
	cp $(SRCS)/get_pid_info.c $(KDIR)kernel/
	$(MAKE) -j4 -C $(KDIR) 2>/tmp/err_log 1>/tmp/log
	cp $(KDIR)arch/x86/boot/bzImage /boot/vmlinuz-$(VERSION)
	reboot

clean:
	$(MAKE) clean -C $(KDIR)
	rm -f $(KDIR)kernel/get_pid_info.c

tbuild: tclean
	@gcc -o test test.c

tclean:
	@rm -f .log

test: tbuild
	@./test $(ARG)

t1: tbuild
	@./test 1 0 512 512 1>>.log
	@echo -e "\n#######" 1>>.log

t2: tbuild
	@./test 1 10 0 512 1>>.log
	@echo -e "\n#######" 1>>.log

t3: tbuild
	@./test 1 10 512 0 1>>.log
	@echo -e "\n#######" 1>>.log

t4: tbuild
	@./test 1 0 0 0 1>>.log
	@echo -e "\n#######" 1>>.log

all-test: tbuild t1 t2 t3 t4
	@less .log

re: clean default
