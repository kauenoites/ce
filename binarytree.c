#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *esq;
    struct Node *dir;
};


struct Node* novo(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->esq = NULL;
    node->dir = NULL;
    return node;
}

// Função para inserir um novo nó na árvore
struct Node* inserir(struct Node* node, int data) {
    if (node == NULL)
        return novo(data);

    if (data < node->data)
        node->esq = inserir(node->esq, data);
    else if (data > node->data)
        node->dir = inserir(node->dir, data);

    return node;
}


struct Node* procura(struct Node* raiz, int pesq) {
    if (raiz == NULL || raiz->data == pesq)
        return raiz;

    if (raiz->data < pesq)
        return procura(raiz->dir, pesq);

    return procura(raiz->esq, pesq);
}

void emOrdem(struct Node* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->data);
        emOrdem(raiz->dir);
    }
}
void Mostrar(struct Node* node) {
    if (node == NULL)
        return;

    printf("%d ", node->data);
    Mostrar(node->esq);
    Mostrar(node->dir);
}

int main() {
    struct Node* raiz = NULL;
    int nodes, num, pesq;
    
    printf("Quantos números deseja inserir na árvore? ");
    scanf("%d", &nodes);

    printf("Insira os números:\n");
    for (int i = 0; i < nodes; i++) {
        scanf("%d", &num);
        raiz = inserir(raiz, num);
    }

    printf("Árvore sem ordenação : ");
    Mostrar(raiz);
    printf("\n");

    printf("Árvore em ordem: ");
    emOrdem(raiz);
    printf("\n");

    printf("Insira o número que deseja pesquisar na árvore: ");
    scanf("%d", &pesq);

    if (procura(raiz, pesq) != NULL)
        printf("Numero %d encontrado na árvore.\n", pesq);
    else
        printf("Numero %d não encontrado na árvore.\n", pesq);

    return 0;
}
