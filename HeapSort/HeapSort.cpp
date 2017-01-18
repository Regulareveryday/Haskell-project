#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
int left(int i){
    return 2*i+1;
}
int right(int i){

    return 2*i+2;
}
int parent(int i){
    return (i-1)/2;
}

//Naprawianie kopca
void Heapify(int A[],int n, int i){//i-indeks elementu, który zaburza w³asnoœæ kopca, n-liczba elementów,n- pomocniczo, ¿eby nie przekroczyæ rozmiaru tab
    int ind_max=i;
    if(left(i)<n and A[left(i)]>A[ind_max]) ind_max=left(i);
    if(right(i)<n and A[right(i)]>A[ind_max]) ind_max=right(i);
    if(ind_max!=i){
        swap(A[i],A[ind_max]);
        Heapify(A,n,ind_max);
    }
}

void BuildHeap(int A[],int n){
    for(int j=parent(n-1);j>=0;j--)
        Heapify(A,n,j);
}

//sortowanie przez kopcowanie
void heapSort(int A[],int n){
    BuildHeap(A,n);
    for(int j=n-1;j>0;j--){
        swap(A[j],A[0]);
        Heapify(A,j,0);
    }
}
