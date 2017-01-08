#include <stdio.h>
#include <stdlib.h>

int partition(int tablica[], int p, int r) {
    int x = tablica[p];
    int i = p, j = r, w; 
    while (1) {
        while (tablica[j] > x)
            j--;
        while (tablica[i] < x) 
            i++;
        if (i < j) {
            w = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = w;
            i++;
            j--;
        }
        else
            return j;
    }
}

void quicksort(int tablica[], int p, int r) {
    int q;
    if (p < r) {   
        q = partition(tablica,p,r); 
        quicksort(tablica, p, q); 
        quicksort(tablica, q+1, r); 
    }
}

int main(int argc, char **argv) {
        int *tablica = malloc(sizeof(int) * argc);

        if(tablica != NULL) {
            int i;
            for(i=1; i<argc; i++) {
                tablica[i-1] = atoi(argv[i]);
            }
				
			quicksort(tablica, 0, argc-2);

			printf("Sorted list:\n");
			for (int i = 0; i < argc-1; i++)
				printf("%d\n", tablica[i]);

			free(tablica);
        }

        return 0;
}