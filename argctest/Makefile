CC = g++
CFLAGS := -fPIC -Wall -Wextra -O3 -g
#CFLAGS += -D_DEBUG_
LDFLAGS := -lcurl

OBJS = libdow.o
#LIB = libdow.a
LIB_NAME = libSample
SAMPLE_EXC = sample
SAMPLE_SRC = main.cpp
LIB_PATH = ./
INCLUDE_PATH = include/

all : $(SAMPLE_EXC)

%.o : %.cpp
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@ 

$(LIB) : $(OBJS)
	rm -f $@
	ar cr $@ $(OBJS)
	rm -f $(OBJS)

$(SAMPLE_EXC):
	$(CC) $(SAMPLE_SRC) $(LIB) -o $(SAMPLE_EXC) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(TARGET) $(LIB) $(SAMPLE_EXC)  
