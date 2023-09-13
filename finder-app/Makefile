# Author: Lucas Cunha (@Lucasgb7)
#------------------------------------------------------------------------------
# Use: make [TARGET] [PLATFORM-OVERRIDES]
# Build Targets:
#      			all : Compiles all source files
#	   			clean: Removes all generated files.
# Platform Overrides:
# 					aarch64-none-linux-gnu-: Uses Linux GCC Compiler
#					default: Uses GCC compiler
#------------------------------------------------------------------------------
CC=$(CROSS_COMPILE)gcc
CFLAGS=-Wall -Werror

TARGET=writer
SRC:=writer.c
OBJS:=$(SRC:.c=.o)

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	-rm -f *.o $(TARGET)