#include <stdio.h>
#include <stdlib.h>

void write_file(void)
{
    FILE *fp;
    unsigned char a[] = {
	0x00, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x00,
	0x00, 0x01, 0x00,
	0x00, 0x00, 0x00,
	0x00, 0x01, 0x00,
	0x00, 0x00, 0x00,
	0x69
    };
    fp = fopen("test.bin","wb"); 
    fwrite(a, sizeof(unsigned char), sizeof(a)/sizeof(a[0]), fp);
    fclose (fp);
}

typedef struct {
    unsigned char colours[4];
    unsigned char *pixels;
    // ... 
} image;

void read_file(void)
{
    static const size_t buffer_size = 16;
    FILE *fp;
    unsigned char buffer[buffer_size];
    fp = fopen("test.bin","rb");
    while (1) {
	const size_t file_size = fread(buffer, sizeof(unsigned char), buffer_size, fp);
	printf("Reading buffer of size: %d bytes ", (int)file_size);
	for(uint i = 0; i < (file_size / sizeof(unsigned char)); i++) {
	    printf("%x ", buffer[i]);
	    if (buffer[i] == 0x69) {
		printf("\n");
		fclose(fp);
		return;
	    }
	}
	printf("\n");
    }
}

int main(void)
{
    write_file();
    read_file();
    return 0;
}

// gcc -w test.c -o test && ./test && hexdump test.bin
