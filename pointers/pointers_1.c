#include <stdio.h>

int main() {
    long temperatures[] = {72, 81, 65, 94, 70};
    long *ptr = temperatures;
    for(int i = 0; i < 5; i++) {
        printf("Index: %d\nValue: %ld\nAddress: %p\n\n", i, temperatures[i], (void*)ptr);
        ptr++;
    }
    printf("%zu\n", sizeof(long));
    return 0;
}