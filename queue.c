#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int front;
    int rear;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila *fila)
{
    fila->front = -1;
    fila->rear = -1;
}

// Função para verificar se a fila está vazia
int estaVazia(Fila *fila)
{
    return (fila->front == -1 && fila->rear == -1);
}

// Função para verificar se a fila está cheia
int estaCheia(Fila *fila)
{
    return ((fila->rear + 1) % MAX == fila->front);
}

// Função para enfileirar um elemento
void enfileirar(Fila *fila, int item)
{
    if (estaCheia(fila))
    {
        printf("Erro: a fila está cheia!\n");
        return;
    }
    if (estaVazia(fila))
    {
        fila->front = 0;
        fila->rear = 0;
    }
    else
    {
        fila->rear = (fila->rear + 1) % MAX;
    }
    fila->items[fila->rear] = item;
}

// Função para desenfileirar um elemento
int desenfileirar(Fila *fila)
{
    int item;
    if (estaVazia(fila))
    {
        printf("Erro: a fila está vazia!\n");
        return -1;
    }
    item = fila->items[fila->front];
    if (fila->front == fila->rear)
    {
        fila->front = -1;
        fila->rear = -1;
    }
    else
    {
        fila->front = (fila->front + 1) % MAX;
    }
    return item;
}

int main()
{
    Fila fila;
    inicializarFila(&fila);

    enfileirar(&fila, 1);
    enfileirar(&fila, 2);
    enfileirar(&fila, 3);

    printf("Frente da fila: %d\n", fila.items[fila.front]);
    printf("Desenfileirando: %d\n", desenfileirar(&fila));
    printf("Frente da fila após desenfileirar: %d\n", fila.items[fila.front]);

    return 0;
}
