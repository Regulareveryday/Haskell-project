#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int *array, int length)
{
    int max, i, temp;
    int length_copy = length;
    while (length > 0)
    {
        max = 0;
        for (i = 1; i < length; i++)
            if (array[i] > array[max])
                max = i;

        temp = array[length-1];
        array[length-1] = array[max];
        array[max] = temp;
        length--;
    }

    printf("Sorted list:\n");
    for (int j = 0; j < length_copy; j++)
        printf("%d\n", array[j]);
}

int main(int argc, char **argv) {
        int *array = malloc(sizeof(int) * argc);

        if(array != NULL) {
                int i;
                for(i=1; i<argc; i++) {
                        array[i-1] = atoi(argv[i]);
                }
        }
        SelectionSort(array, argc-1);
        free(array);
        return 0;
}