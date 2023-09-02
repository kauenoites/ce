#include <stdio.h>

#define TAM 100

// Estrutura da FILA
typedef struct {
    int data[TAM];
    int frente;
    int tras;
} Fila;

// Inicialização da FILA
void initFila(Fila *f) {
    f->frente = -1;
    f->tras = -1;
}

// Verificação se a FILA está vazia
int filaVazia(Fila *f) {
    return (f->frente == -1);
}

// Verificação se a FILA está cheia
int filaCheia(Fila *f) {
    return (f->tras == TAM - 1);
}

// Inserção na FILA
void insFila(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("A fila está cheia.\n");
        return;
    }
    
    if (filaVazia(f))
        f->frente = 0;
    
    f->tras++;
    f->data[f->tras] = valor;
}

// Remoção da FILA
int tiraFila(Fila *f) {
    if (filaVazia(f)) {
        printf("A fila está vazia.\n");
        return -1;
    }
    
    int valor = f->data[f->frente];
    if (f->frente == f->tras)
        initFila(f);
    else
        f->frente++;
    
    return valor;
}

// Exibição da FILA
void exibirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("A fila está vazia.\n");
        return;
    }
    
    printf("Elementos na fila: ");
    for (int i = f->frente; i <= f->tras; i++) {
        printf("%d ", f->data[i]);
    }
    printf("\n");
}

// Estrutura da PILHA
typedef struct {
    int data[TAM];
    int topo;
} Pilha;

// Inicialização da PILHA
void initPilha(Pilha *p) {
    p->topo = -1;
}

// Verificação se a PILHA está vazia
int pilhaVazia(Pilha *p) {
    return (p->topo == -1);
}

// Verificação se a PILHA está cheia
int pilhaCheia(Pilha *p) {
    return (p->topo == TAM - 1);
}

// Inserção na PILHA
void push(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        printf("A pilha está cheia.\n");
        return;
    }
    
    p->topo++;
    p->data[p->topo] = valor;
}

// Remoção da PILHA
int pop(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("A pilha está vazia.\n");
        return -1;
    }
    
    int valor = p->data[p->topo];
    p->topo--;
    return valor;
}

// Mostrar o topo da PILHA
int top(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("A pilha está vazia.\n");
        return -1;
    }
    
    return p->data[p->topo];
}

int main() {
    Fila fila;
    Pilha pilha;
    
    initFila(&fila);
    initPilha(&pilha);
    
    int escolha, valor, posicao;
    
    do {
        printf("\nEscolha a operação:\n");
        printf("1. Inserir na FILA\n");
        printf("2. Remover da FILA\n");
        printf("3. Exibir a FILA\n");
        printf("4. Inserir na PILHA\n");
        printf("5. Remover da PILHA\n");
        printf("6. Mostrar topo da PILHA\n");
        printf("0. Sair\n");
        scanf("%d", &escolha);
        
        //switch para escolher a opção desejada
        switch (escolha) {
            case 1:
                printf("Digite o valor para inserir na FILA: ");
                scanf("%d", &valor);
                insFila(&fila, valor);
                break;
            case 2:
                valor = tiraFila(&fila);
                if (valor != -1)
                    printf("Valor removido da FILA: %d\n", valor);
                break;
            case 3:
                exibirFila(&fila);
                break;
            case 4:
                printf("Digite o valor para inserir na PILHA: ");
                scanf("%d", &valor);
                push(&pilha, valor);
                break;
            case 5:
                valor = pop(&pilha);
                if (valor != -1)
                    printf("Valor removido da PILHA: %d\n", valor);
                break;
            case 6:
                valor = top(&pilha);
                if (valor != -1)
                    printf("Topo da PILHA: %d\n", valor);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (escolha != 0);
    
    return 0;
}
