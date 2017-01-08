#include <stdio.h>
#include <stdlib.h>

void InsertSort(int a[], int length) {

    int i, j, value;

    for(i = 1 ; i < length ; i++) {
        value = a[i];
        for (j = i - 1; j >= 0 && a[j] > value; j--)
            a[j + 1] = a[j];
        a[j + 1] = value;
    }

    printf("Sorted list:\n");
    for (i = 0; i < length; i++) {
        printf("%d\n", a[i]);
    }

}

int main(int argc, char **argv) {
        int *tab = malloc(sizeof(int) * argc);

        if(tab != NULL) {
                int i;
                for(i=1; i<argc; i++) {
                        tab[i-1] = atoi(argv[i]);
                }
        }
        InsertSort(tab, argc-1);
        free(tab);
        return 0;
}