#include <stdio.h>
#include <stdlib.h>

void write_file(void)
{
    FILE *ptr;
    unsigned char a[] = {
	0x00, 0xff, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00
    }; 
    ptr = fopen("test.bin","wb"); 
    fwrite(a, sizeof(unsigned char), sizeof(a)/sizeof(a[0]), ptr);
    fclose (ptr);
}

typedef struct {
    unsigned char colours[4];
    unsigned char *pixels;
} image;

void read_file(void)
{
    static const size_t BufferSize = 17;
    uint i;
    FILE *ptr;
    unsigned char buffer2[BufferSize];

    ptr = fopen("test.bin","rb");
    const size_t fileSize = fread(buffer2, sizeof(unsigned char), BufferSize, ptr);

    printf("File size = %d bytes\n", (int)fileSize);
    printf("Size of each item in bytes = %d\n",(int) sizeof(unsigned char));

    for(i = 0; i < (fileSize / sizeof(unsigned char)); i++){
        printf("%x ", buffer2[i]);
    }
    printf("\n");
    
    fclose(ptr);
}

int main(void)
{
    write_file();
    read_file();
    return 0;
}

// gcc -w test.c -o test && ./test && hexdump test.bin
