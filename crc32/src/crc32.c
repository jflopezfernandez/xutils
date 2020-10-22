
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 *
 * @cite Warren, H. S. (2013). Hacker’s Delight (2nd ed.). Addison-Wesley.
 *
 */
unsigned int reverse(unsigned int byte) {
    byte = (byte & 0x55555555) <<  1 | (byte & 0xAAAAAAAA) >>  1;
    byte = (byte & 0x33333333) <<  2 | (byte & 0xCCCCCCCC) >>  2;
    byte = (byte & 0x0F0F0F0F) <<  4 | (byte & 0xF0F0F0F0) >>  4;
    byte = (byte & 0x00FF00FF) <<  8 | (byte & 0xFF00FF00) >>  8;
    byte = (byte & 0x0000FFFF) << 16 | (byte & 0xFFFF0000) >> 16;

    return byte;
}

unsigned int crc32(const char* string) {
    int i;
    unsigned int byte, crc;

    i = 0;
    crc = 0xFFFFFFFF;

    while (string[i] != '\0') {
        byte = string[i];
        byte = reverse(byte);

        for (int j = 0; j <= 7; j++) {
            if ((int) (crc ^ byte) < 0) {
                crc = (crc << 1) ^ 0x04C11DB7;
            } else {
                crc = crc << 1;
            }

            byte = byte << 1;
        }

        i = i + 1;
    }

    return reverse(~crc);
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        fprintf(stderr, "[Error] No input(s).\n");
        return EXIT_FAILURE;
    }

    while (*++argv) {
        printf("%u\n", crc32(*argv));
    }

    return EXIT_SUCCESS;
}
