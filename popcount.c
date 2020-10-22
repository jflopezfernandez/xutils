
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        fprintf(stderr, "[Error] No input(s).\n");
        return EXIT_FAILURE;
    }

    while (*++argv) {
        int n = strtol(*argv, NULL, 10);

        size_t digits_in_current_group = 0;

        for (size_t i = 30; i != (size_t) -1; --i) {
            putchar((((1 << i) & n) ? '1' : '0'));
            ++digits_in_current_group;

            if (digits_in_current_group == 8) {
                putchar(' ');
                digits_in_current_group = 0;
            }
        }

        putchar('\n');
    }

    return EXIT_SUCCESS;
}
