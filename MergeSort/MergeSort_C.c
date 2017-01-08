#include <stdio.h>
#include <stdlib.h>

void merge(int tablica[], int start, int srodek, int koniec) {
    int *tab_pom = malloc(sizeof(int) * (koniec-start));
	
	if(tab_pom != NULL) {
		int i = start, j = srodek+1, k = 0;

		while (i <= srodek && j <= koniec) {
			if (tablica[j] < tablica[i]) {
				tab_pom[k] = tablica[j];
				j++;
			}
			else {
				tab_pom[k] = tablica[i];
				i++;
			}
			k++;
		}
 
		if (i <= srodek)
			while (i <= srodek) {
				tab_pom[k] = tablica[i];
				i++;
				k++;
			}
		else
			while (j <= koniec) {
				tab_pom[k] = tablica[j];
				j++;
				k++;
			}
		
 
		for (i = 0; i <= koniec-start; i++)
			tablica[start+i] = tab_pom[i];  
	
		free(tab_pom);
	}
}

void merge_sort(int tablica[], int start, int koniec)
{
    int srodek;

    if (start != koniec) {
        srodek = (start + koniec)/2;
		
		if(start != srodek)
			merge_sort(tablica, start, srodek);
		
		if(srodek+1 != koniec)
			merge_sort(tablica, srodek+1, koniec);
		
        merge(tablica, start, srodek, koniec);
    }
}

int main(int argc, char **argv) {
    int *tablica = malloc(sizeof(int) * argc);

    if(tablica != NULL) {
        for(int i=1; i<argc; i++) {
            tablica[i-1] = atoi(argv[i]);
        }

		merge_sort(tablica, 0, argc-2);

		printf("Sorted list:\n");
        
		for (int i = 0; i < argc-1; i++)
			printf("%d\n", tablica[i]);

		free(tablica);
	}

    return 0;
}