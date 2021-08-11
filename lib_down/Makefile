Q		:= @
CC 		:= g++
SRCS    := $(wildcard *.cpp)
OBJS	:= $(SRCS:.cpp=.o)
TARGET	:= libdown.a
LIB		:=
CFLAGS	:= -Wall -fPIC -Wextra -O3 -g -I./include
LDFLAGS	:= $(LIBS)

.PHONY: all clean distclean

all: .depend $(TARGET)

%.o: %.cpp Makefile
	$(Q)echo "  Compiling '$<' ..."
	$(Q)$(CC) $(CFLAGS) -o $@ -c $<

$(TARGET): $(OBJS)
	$(Q)echo "  Building '$@', LIB name=$(TARGET) ..."
	$(Q)ar rcs $@ $(OBJS) $(LDFLAGS)

clean distclean: 
	$(Q)echo "  Cleaning '$(TARGET)' ..."
	$(Q)rm -f .depend *~ $(OBJS) $(TARGET)

.depend dep depend:
	$(Q)echo "  Generating '$@' ..."
	$(Q)$(CC) $(CFLAGS) -M *.cpp > $@

ifeq (.depend, $(wildcard .depend))
    include .depend
endif
