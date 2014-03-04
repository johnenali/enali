#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char text[1024];
    static int test_val = -72;
    int B=4;

    if (argc<2) {
        printf("Usage: %s <text to print>\n", argv[0]);
        exit(0);
    }

    strcpy(text, argv[1]);

    printf("The right way to print user-controlled input:\n");
    printf("%s", text);

    printf("\nThe wrong way to print user-controlled input:\n");
    printf(text);

    printf("\n");

    printf("[DEBUG] test_val @%p = %d 0x%08x\n", &test_val, test_val, test_val);
    printf("B @%p = %d", &B, B);
    return 1;
}
