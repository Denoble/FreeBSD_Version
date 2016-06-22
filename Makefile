CFLAGS=	-fPIC

all: intercept.so ldpreload

run: interceptOpen.so interceptAccess.so ldpreload
	LD_PRELOAD=./intercept.so ./ldpreload

intercept.so: interceptOpen.o interceptAccess.o
	$(CC) $(CFLAGS) -shared -o intercept.so interceptOpen.o interceptAccess.o

interceptOpen.so: interceptOpen.c
	$(CC) -shared -fPIC -o interceptOpen.so interceptOpen.c
interceptAccess.so: interceptAccess.c
	$(CC) -shared -fPIC -o interceptAccess.so interceptAccess.c
ldpreload: ldpreload.c
	$(CC) -o ldpreload ldpreload.c
clean:
	rm -f *.o *.so ldpreload