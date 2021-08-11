Q				:=@
TARGET_E		:= encrypt_example
TARGET_D		:= decrypt_example
OUTPUT			:=release
LIB_PATH		:=../bin
OPENSSL_LIB		:=../Build-OpenSSL-MinGW-64/bin

ifeq ($(OS),Windows_NT)
	MAKEFILE	:= windows.mk
else
	MAKEFILE	:= linux.mk
endif

.PHONY: all
all: 
	$(Q)make -f $(MAKEFILE)

.PHONY: clean
clean:
	$(Q)echo "  Cleaning '$(TARGET_E)' '$(TARGET_D)'..."
	$(Q)$(RM) $(TARGET_E) $(TARGET_D)
	$(Q)$(RM) *.o
	$(Q)$(RM) -r $(OUTPUT)

installwin32:
	mkdir -p $(OUTPUT)
	cp $(TARGET_E).exe $(TARGET_D).exe $(LIB_PATH)/libcrypto.dll $(OPENSSL_LIB)/libeay32.dll $(OPENSSL_LIB)/ssleay32.dll $(OUTPUT)