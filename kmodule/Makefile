BINARY		:= njraa
KERNEL		:= /lib/modules/$(shell uname -r)/build
ARCH		:= x86
C_FLAGS		:= -Wall -Werror-implicit-function-declaration -Werror -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -m64 -mtune=generic -mno-red-zone
C_FLAGS		+= -O1
KMOD_DIR	:= $(shell pwd)
TARGET_PATH := /lib/modules/$(shell uname -r)/kernel/drivers/char

OBJECTS	:= njraa.o

ccflags-y += $(C_FLAGS)

obj-m += $(BINARY).o

$(BINARY).ko:
	make -C $(KERNEL) M=$(KMOD_DIR) modules

clean:
	make -C $(KERNEL) M=$(KMOD_DIR) clean
