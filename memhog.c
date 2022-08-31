#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned sleep(unsigned seconds);
int main(int argc, const char* argv[]) {
	char* lastchar;
	long bytes_to_hog;
	void* mem;
	int ret;
	if (argc !=2)  {
		printf("memhog size, unit is M\n");
		return 1;
	}

	bytes_to_hog = strtol(argv[1], &lastchar, 16);
	if (*lastchar != '\0') {
		printf("Failed: Invalid argument %s\n", argv[1]);
		return 1;
	}
	printf("sleep 5 seconds to start.\n");
	sleep(5);
	printf("Attempting to hog %li MB of RAM.\n", bytes_to_hog);
	bytes_to_hog *= (1024*1024);
 	mem = malloc(bytes_to_hog);
	if (!mem) {
		printf("Failied! Couldn't malloc.\n");
		return 1;
	}
	if (ret = mlock(mem, bytes_to_hog)) {
		printf("Failed! Couldn't mlock. %s\n", strerror(-ret));
		return 1;
	}
	printf("Success! Press any key to kill me and get back the RAM.\n");
	while(1)
		sleep(5);
	return 0;

}
