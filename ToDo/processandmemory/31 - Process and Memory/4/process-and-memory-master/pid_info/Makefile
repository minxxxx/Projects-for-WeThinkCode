NAME    		= get_pid_info
PWD			= $(shell pwd)

ifneq ($(KERNELRELEASE),)

	obj-m		:= $(NAME).o
else
	
	KDIR		?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$(PWD)


clean:
	@rm -f Module.symvers $(NAME).mod.c $(NAME).mod.o $(NAME).o modules.order
	@rm -f built-in.o

fclean: clean
	@rm -f $(NAME).ko
	@rm -f $(SRCS)*.o

re: clean default

endif
