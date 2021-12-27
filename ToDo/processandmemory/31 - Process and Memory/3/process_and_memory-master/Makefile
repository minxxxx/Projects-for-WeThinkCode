src-test = test.c
obj-test = $(src-test:.c=.o)
src-m += main.c
obj-m += $(src-m:.c=.o)
module-obj = $(obj-m:.o=.ko)
KERNELRELEASE=$(shell uname -r)
KDIR=/lib/modules/$(shell uname -r)/build
EXTRAFLAGS= -Wall -Wextra -Wextra -Werror -v -g -DDEBUG
FLAGS= $(EXTRAFLAGS) -g3 -fsanitize=address
ccflags-y= $(EXTRAFLAGS)
TEST_DIR= "testing"
TEST_BIN= "test_bin"
CP_BACKUP_FLAG=simple
CC= gcc

all: install
	make -C $(KDIR) -j4 M=$(PWD)
	cp -v --backup=$(CP_BACKUP_FLAG) $(KDIR)/arch/x86_64/boot/bzImage /boot/vmlinuz-$(KERNELRELEASE)
	cp -v --backup=$(CP_BACKUP_FLAG) $(KDIR)/System.map /boot/System.map-$(KERNELRELEASE)
	# reboot

install: all
	mkdir -pv $(KDIR)/$(TEST_DIR)
	cp -v sys_Makefile $(KDIR)/$(TEST_DIR)/Makefile
	cp -v --backup=$(CP_BACKUP_FLAG) get_pid_info.h $(KDIR)/include/linux/get_pid_info.h
	cp -v --backup=$(CP_BACKUP_FLAG) sys_get_pid_info.c $(KDIR)/$(TEST_DIR)/sys_get_pid_info.c
	# cp -v --backup=$(CP_BACKUP_FLAG) unistd.h $(KDIR)/include/uapi/asm-generic/unistd.h
	# cp -v --backup=$(CP_BACKUP_FLAG) syscalls.h $(KDIR)/include/linux/syscalls.h
	# cp -v --backup=$(CP_BACKUP_FLAG) sys_ni.c $(KDIR)/kernel/sys_ni.c
	# cp -v --backup=$(CP_BACKUP_FLAG) syscall_64.tbl $(KDIR)/arch/x86/entry/syscalls/syscall_64.tbl

clean:
#	make -C $(KDIR) M=$(PWD) clean
	rm -f $(obj-test)

fclean:
	rm -f $(TEST_BIN)

$(TEST_BIN): $(obj-test)
	$(CC) $^ $(FLAGS) -o $@

%.o: %.c
	$(CC) $< $(FLAGS) -c
test: $(TEST_BIN)
	-./$(TEST_BIN)
