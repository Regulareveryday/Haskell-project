#include <stdio.h>
#include <stdlib.h>

void BubbleSort (int a[], int length) {
    
    int temp;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (a[j + 1] < a[j]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Sorted list:\n");
    for (int i = 0; i < length; i++) {
        printf("%d\n", a[i]);
    }
}

int main(int argc, char **argv) {
        int *tab = malloc(sizeof(int) * argc);

        if(tab != NULL) {
                for(int i=1; i<argc; i++) {
                        tab[i-1] = atoi(argv[i]);
                }
        }

        BubbleSort(tab, argc-1);
        free(tab);
        return 0;
}