CC = arm-linux-gnueabihf-gcc

CFLAGS = -g -O2 -static
OBJECTS = memhog.o

memhog : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o memhog

memhog.o : memhog.c
	$(CC) $(CFLAGS) -c memhog.c
