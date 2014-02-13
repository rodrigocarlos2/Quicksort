#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){

    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

int part(int *vetor, int leaf, int right){
    int pivo =  vetor[leaf];
    int j, i = leaf;

    for(j=leaf+1; j<right; j++){
        if(vetor[j]< pivo){
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }
    swap(&vetor[leaf], &vetor[i]);

    return i;


}

void quicksort(int *vetor, int inicio, int fim){

    int partition;

    if(inicio< fim){
        partition = part(vetor, inicio, fim);
        quicksort(vetor,inicio, partition-1);
        quicksort(vetor,partition+1,fim);
    }

}

int main(){

    int vetor[]={100, 23, 32, 65, 7, 8, 98, 123, 34, 92, 54, 33, 45, 4, 3, 2, 1};
    int tam = sizeof(vetor)/sizeof(int);
    int i;

    for(i=0; i<tam; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");

    quicksort(vetor,0, tam);

    printf("\n");


    for(i=0; i<tam; i++){
        printf("%d ", vetor[i]);
    }


}
