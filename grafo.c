#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista de adjacências
typedef struct ListNode
{
    int dest;
    struct ListNode *next;
} ListNode;

// Estrutura para representar uma lista de adjacências
typedef struct List
{
    ListNode *head;
} List;

// Estrutura para representar um grafo
typedef struct Graph
{
    int V;       // Número de vértices
    List *array; // Lista de adjacências
} Graph;

// Função para criar um novo nó da lista de adjacências
ListNode *newListNode(int dest)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com V vértices
Graph *createGraph(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (List *)malloc(V * sizeof(List));

    // Inicializa todas as listas de adjacências como vazias
    for (int i = 0; i < V; ++i)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(Graph *graph, int src, int dest)
{
    // Adiciona uma aresta de src para dest
    ListNode *newNode = newListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Para um grafo não direcionado, também é necessário adicionar uma aresta de dest para src
    newNode = newListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Função para imprimir o grafo
void printGraph(Graph *graph)
{
    for (int v = 0; v < graph->V; ++v)
    {
        ListNode *temp = graph->array[v].head;
        printf("Lista de adjacências do vértice %d\n", v);
        while (temp)
        {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Função principal
int main()
{
    int V = 5; // Número de vértices
    Graph *graph = createGraph(V);

    // Adiciona arestas
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Imprime o grafo
    printGraph(graph);

    return 0;
}
