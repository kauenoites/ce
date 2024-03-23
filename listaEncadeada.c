#include <stdio.h>
#include <stdlib.h>

// Nó da lista
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no início
void inserirNoInicio(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Função para imprimir a lista
void imprimeLista(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    char res;

    do {
        int numero;
        printf("Digite o número que deseja inserir: ");
        scanf("%d", &numero);
        inserirNoInicio(&head, numero);

        printf("Deseja inserir outro número? (S/s para sim, qualquer outra tecla para não): ");
        scanf(" %c", &res);  // Note o espaço antes de %c para evitar quebra de linha anterior

        printf("Lista: ");
        imprimeLista(head);
    } while (res == 'S' || res == 's');

    return 0;
}
