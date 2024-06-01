#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Função para criar um novo nó
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no início da lista
void insertAtBeginning(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Função para imprimir a lista
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Função principal
int main()
{
    Node *head = NULL; // Inicializa a lista vazia

    // Inserindo elementos na lista
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 7);

    // Imprimindo a lista
    printf("Lista encadeada: ");
    printList(head);

    return 0;
}
