#include <stdio.h>

void insercao(int arr[], int n){
    int i,j, chave;
    for(i=1; i<n; i++){
        chave=arr[i];
        j=i-1;

//move os elementos maiores que a chave para a posicao a frente
    while (j >= 0 && arr[j] > chave){
        arr[j+1] = arr[j];
        j = j - 1;
    }
    arr[j+1] = chave;
    }
}

int main (){
    int n;
    printf("Quantos elementos deseja ordenar? \n");
    scanf("%d", &n);

    int arr[n];

    printf("Digite os numeros: \n");
    for(int i =0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    insercao(arr, n);

    printf("Array ordenado: ");
    for(int i = 0; i<n ; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}