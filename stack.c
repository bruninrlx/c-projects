#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Definição da estrutura da pilha
typedef struct Stack
{
    Node *top;
} Stack;

// Função para criar um novo nó
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Função para criar uma pilha vazia
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *stack)
{
    return (stack->top == NULL);
}

// Função para empilhar um elemento
void push(Stack *stack, int data)
{
    Node *node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

// Função para desempilhar um elemento
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("A pilha está vazia\n");
        exit(1);
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Função para retornar o elemento no topo da pilha
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("A pilha está vazia\n");
        exit(1);
    }
    return stack->top->data;
}

int main()
{
    Stack *stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Elemento no topo: %d\n", peek(stack));

    printf("Desempilhando: %d\n", pop(stack));
    printf("Desempilhando: %d\n", pop(stack));

    printf("Elemento no topo: %d\n", peek(stack));

    return 0;
}
