#include <stdio.h>

int main() {
    char mystr[] = "Hello\0";

    printf("%s World", mystr);

    return 0;
}