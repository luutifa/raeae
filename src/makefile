# A makefile.

#SRCS=$(wildcard *.c) $(wildcard */*.c)
SRCS=main.c
TARGET=raeae
OBJS=$(SRCS:.c=.o)
CC=gcc
CFLAGS=-Wl,--build-id=none -march=armv6j -mfpu=vfp -mfloat-abi=hard -ffast-math -fno-inline -fpeephole2 -fexpensive-optimizations -nostdlib -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables
INCLUDES=-I./
LFLAGS=-L/opt/vc/lib -L/usr/lib
LIBS=-lGLESv2 -lEGL -lbcm_host -lSDL

all: $(TARGET)
	sstrip $(TARGET)
	@echo "Finished."
	
$(TARGET):
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(SRCS) $(LFLAGS) $(LIBS)

#.c.o:
#	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	find ./ -type f -name "*.o" -delete
	find ./ -type f -name "*.d" -delete
	rm -f $(TARGET)*

-include *.d