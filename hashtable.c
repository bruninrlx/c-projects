#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct
{
    char *key;
    int value;
} HashNode;

typedef struct
{
    HashNode *nodes[TABLE_SIZE];
} HashTable;

unsigned int hash(const char *key)
{
    unsigned int hash_value = 0;
    for (; *key != '\0'; key++)
    {
        hash_value = *key + (hash_value << 5) - hash_value;
    }
    return hash_value % TABLE_SIZE;
}

HashTable *createHashTable()
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable->nodes[i] = NULL;
    }
    return hashTable;
}

void insert(HashTable *hashTable, const char *key, int value)
{
    unsigned int index = hash(key);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->value = value;

    if (hashTable->nodes[index] != NULL)
    {
        free(hashTable->nodes[index]->key);
        free(hashTable->nodes[index]);
    }
    hashTable->nodes[index] = newNode;
}

int get(HashTable *hashTable, const char *key)
{
    unsigned int index = hash(key);
    if (hashTable->nodes[index] != NULL && strcmp(hashTable->nodes[index]->key, key) == 0)
    {
        return hashTable->nodes[index]->value;
    }
    return -1; // Not found
}

void deleteHashTable(HashTable *hashTable)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable->nodes[i] != NULL)
        {
            free(hashTable->nodes[i]->key);
            free(hashTable->nodes[i]);
        }
    }
    free(hashTable);
}

int main()
{
    HashTable *hashTable = createHashTable();

    insert(hashTable, "key1", 10);
    insert(hashTable, "key2", 20);

    printf("Value for key1: %d\n", get(hashTable, "key1")); // Output should be 10
    printf("Value for key2: %d\n", get(hashTable, "key2")); // Output should be 20

    deleteHashTable(hashTable);

    return 0;
}
