#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define MAPPED_SIZE  0x1000 //place the size here
#define DDR_RAM_PHYS  0x703B00000 //0x5ad00000//place the physical address here

int main() {
	int _fdmem, i;
	int *map = NULL;
	char str[MAPPED_SIZE] = "HI FROM ASH";
	const char memDevice[] = "/dev/mem";

/* open /dev/mem and error checking */
	_fdmem = open( memDevice, O_RDWR | O_SYNC );

	if (_fdmem < 0){
		printf("Failed to open the /dev/mem !\n");
		return 0;
	}
	else{
		printf("open /dev/mem successfully !\n");
	}	

/* mmap() the opened /dev/mem */
map= (int *)(mmap(0,MAPPED_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,_fdmem,DDR_RAM_PHYS));

                memcpy((char*)map,str,MAPPED_SIZE);
/* unmap the area & error checking */
	if (munmap(map,MAPPED_SIZE)==-1){
		perror("Error un-mmapping the file");
	}

/* close the character device */
	close(_fdmem);
}
