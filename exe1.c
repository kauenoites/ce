#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contato
{
    char nome[50];
    char email[100];
    char telefone[20];
    char aniversario[10];
};

void cadastrarContato();
void alterarContato();
void excluirContato();
void exibirContato();
void exibirTodosContatos();

struct Contato agenda[100];
int totalContatos = 0;

int main()
{
    int opcao;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1 - Cadastrar novo contato\n");
        printf("2 - Alterar dados de um contato\n");
        printf("3 - Excluir os dados de um contato\n");
        printf("4 - Exibir os dados de um contato específico\n");
        printf("5 - Exibir os dados de todos os contatos\n");
        printf("6 - Sair da aplicação\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarContato();
            break;
        case 2:
            alterarContato();
            break;
        case 3:
            excluirContato();
            break;
        case 4:
            exibirContato();
            break;
        case 5:
            exibirTodosContatos();
            break;
        case 6:
            printf("Saindo da aplicação...\n");
            break;
        default:
            printf("Opção inválida! Digite novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}

void cadastrarContato()
{
    if (totalContatos == 100)
    {
        printf("Agenda cheia! Não é possível cadastrar mais contatos.\n");
        return;
    }

    struct Contato novoContato;

    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", novoContato.nome);

    printf("Digite o e-mail do contato: ");
    scanf(" %[^\n]", novoContato.email);

    printf("Digite o telefone do contato (código regional incluso): ");
    scanf(" %[^\n]", novoContato.telefone);

    printf("Digite a data de aniversário do contato (DD/MM/AAAA): ");
    scanf(" %[^\n]", novoContato.aniversario);

    agenda[totalContatos++] = novoContato;

    printf("Contato cadastrado com sucesso!\n");
}

void alterarContato()
{
    if (totalContatos == 0)
    {
        printf("Nenhum contato cadastrado ainda!\n");
        return;
    }

    char nomeBusca[50];
    int encontrado = 0;

    printf("Digite o nome do contato a ser alterado: ");
    scanf(" %[^\n]", nomeBusca);

    for (int i = 0; i < totalContatos; i++)
    {
        if (strcmp(nomeBusca, agenda[i].nome) == 0)
        {
            printf("Digite o novo nome do contato: ");
            scanf(" %[^\n]", agenda[i].nome);

            printf("Digite o novo e-mail do contato: ");
            scanf(" %[^\n]", agenda[i].email);

            printf("Digite o novo telefone do contato (código regional incluso): ");
            scanf(" %[^\n]", agenda[i].telefone);

            printf("Digite a nova data de aniversário do contato (DD/MM/AAAA): ");
            scanf(" %[^\n]", agenda[i].aniversario);

            printf("Contato alterado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Contato não encontrado!\n");
    }
}

void excluirContato()
{
    if (totalContatos == 0)
    {
        printf("Nenhum contato cadastrado ainda!\n");
        return;
    }

    char nomeBusca[50];
    int encontrado = 0;

    printf("Digite o nome do contato a ser excluído: ");
    scanf(" %[^\n]", nomeBusca);

    for (int i = 0; i < totalContatos; i++)
    {
        if (strcmp(nomeBusca, agenda[i].nome) == 0)
        {
            for (int j = i; j < totalContatos - 1; j++)
            {
                agenda[j] = agenda[j + 1];
            }
            totalContatos--;
            printf("Contato excluído com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Contato não encontrado!\n");
    }
}

void exibirContato()
{
    if (totalContatos == 0)
    {
        printf("Nenhum contato cadastrado ainda!\n");
        return;
    }

    char nomeBusca[50];
    int encontrado = 0;

    printf("Digite o nome do contato a ser exibido: ");
    scanf(" %[^\n]", nomeBusca);

    for (int i = 0; i < totalContatos; i++)
    {
        if (strcmp(nomeBusca, agenda[i].nome) == 0)
        {
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].email);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Aniversário: %s\n", agenda[i].aniversario);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Contato não encontrado!\n");
    }
}

void exibirTodosContatos()
{
    if (totalContatos == 0)
    {
        printf("Nenhum contato cadastrado ainda!\n");
        return;
    }

    printf("---- CONTATOS ----\n");
    for (int i = 0; i < totalContatos; i++)
    {
        printf("Nome: %s\n", agenda[i].nome);
        printf("E-mail: %s\n", agenda[i].email);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("Aniversário: %s\n", agenda[i].aniversario);
        printf("-----------------\n");
    }
}
