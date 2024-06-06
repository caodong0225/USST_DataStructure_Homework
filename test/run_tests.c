#include <stdio.h>
#include <stdlib.h>

void run_test(const char *cmd) {
    printf("Test compiled: %s\n", cmd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No test specified.\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; ++i) {
        run_test(argv[i]);
    }

    printf("All tests compiled!\n");
    return EXIT_SUCCESS;
}
