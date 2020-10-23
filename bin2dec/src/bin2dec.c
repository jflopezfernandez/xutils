
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This is the entry point of the bin2dec conversion
 * utility.
 *
 * @todo Allow the user to request a signed or unsigned
 * representation via command-line arguments.
 *
 * @todo Allow the user to optionally build this utility
 * with GMP to allow for arbitrary-precision integer
 * conversions.
 *
 */
int main(int argc, char *argv[])
{
    if (argc == 1) {
        fprintf(stderr, "No input(s).\n");
        return EXIT_FAILURE;
    }

    while (*++argv) {
        long long int x = 0;

        for (size_t i = 0; i < strlen(*argv); ++i) {
            x <<= 1;
            x  |= (*argv)[i] - '0';
        }

        printf("%lld\n", x);
    }

    return EXIT_SUCCESS;
}

