/**
 * bin2dec - Binary to Decimal Conversion Utility
 * Copyright (C) 2020 Jose Fernando Lopez Fernandez
 * 
 * This program is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * 
 * You should have received a copy of the GNU General
 * Public License along with this program.  If not, see
 * <https://www.gnu.org/licenses/>.
 * 
 */

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

