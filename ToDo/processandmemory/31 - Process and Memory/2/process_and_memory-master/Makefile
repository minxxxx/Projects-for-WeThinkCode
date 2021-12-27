LINUX_FOLDER = /usr/src/linux-$(shell uname -r)/
LOCAL_LINUX_FOLDER = ./linux-root

all: apply compile install

fast: fast-apply compile install

fast-apply:
	cp -RT "$(LOCAL_LINUX_FOLDER)/kernel/process_and_memory" "$(LINUX_FOLDER)/kernel/process_and_memory"
	cp -RT "$(LOCAL_LINUX_FOLDER)/include/uapi/linux" "$(LINUX_FOLDER)/include/uapi/linux"

apply:
	# Copy all the files
	cp -RT "$(LOCAL_LINUX_FOLDER)" "$(LINUX_FOLDER)"

compile:
	# Recompile
	make -j4 -C $(LINUX_FOLDER)

install:
	# Export the header for our struct pid_info
	make -C $(LINUX_FOLDER) INSTALL_HDR_PATH=/usr headers_install

	# copy the resulting kernel to /boot and reboot
	cp $(LINUX_FOLDER)/arch/x86_64/boot/bzImage /boot/vmlinuz-4.13.0-process_and_memory
	cp $(LINUX_FOLDER)/System.map /boot/System.map-4.13.0-process_and_memory
	@echo 
	@echo "done !"
	@read -r -p "Reboot now ? [y/N]: " REBOOT; \
	case "$$REBOOT" in \
	[yY][eE][sS]|[yY]) \
		echo "Rebooting ..."; \
		reboot; \
		;; \
	esac
