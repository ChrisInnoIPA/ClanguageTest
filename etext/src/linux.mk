Q           		:=@
CC			:=g++ -std=c++11
SRCS			:=$(wildcard *.cpp)
TARGETNAME		:=libcrypto
TARGET			:=$(TARGETNAME)_64.a
TARGETHADER		:=Crypto.hpp
OBJECTS			:=$(SRCS:.cpp=.o64)
OBJECTS_32  		:=$(SRCS:.cpp=.o32)
INCLUDE_PATH		:=include
MACROS			:=
CPPFLAGS		:=-Wall -I$(INCLUDE_PATH) $(MACROS)
CPPFLAGS		+=-I/usr/include
CPPFLAGS		+=-I$(INCLUDE_PATH)
LDFLAGS			:=
LIBS			:=
OUTPATH			:=../bin

.PHONY: all
all: clean $(TARGET) install

%.o64: %.cpp
	$(Q)echo "  Compiling '$<' ..."
	$(Q)$(CC) $(CPPFLAGS) -DNEWER_OPENSSLLIB -o $@ -c $<

$(TARGET): $(OBJECTS)
	$(Q)echo "  Building '$@' ..."
	$(Q)ar rcs -o $@ $(OBJECTS)

.PHONY: install
install:
	$(Q)mkdir -p $(OUTPATH)
	$(Q)mkdir -p $(OUTPATH)/$(INCLUDE_PATH)
	$(Q)cp $(TARGET) $(OUTPATH) 
	$(Q)cp $(INCLUDE_PATH)/$(TARGETHADER) $(OUTPATH)/$(INCLUDE_PATH)

.PHONY: clean
clean:
	$(Q)$(RM) $(TARGET) $(TARGET_32) $(OBJECTS)
	$(Q)$(RM) -r $(OUTPATH)