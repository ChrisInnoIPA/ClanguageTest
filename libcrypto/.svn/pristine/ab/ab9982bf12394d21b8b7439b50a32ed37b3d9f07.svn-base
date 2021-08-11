Q				:=@
OUTPATH			:=../bin
MACROS			:=

ifeq ($(OS),Windows_NT)
	TARGET		:= libcrypto.dll
	MAKEFILE	:= windows.mk
else
	TARGET		:= libcrypto_64.a
	MAKEFILE	:= linux.mk
endif

.PHONY: all
all: 
	$(Q)make -f $(MAKEFILE) MACROS=$(MACROS)