#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct Node {
    char* key; 
    char* value; 
    struct Node* next; 
};

void setNode(struct Node* node, char* key, char* value) {
    node->key = key; 
    node->value = value; 
    node->next = NULL; 
}

struct HashMap {
    int numOfElements, capacity; 
    struct Node** array; 
};

void initializeHashMap(struct HashMap* map) {
    map->capacity = 100; 
    map->numOfElements = 0; 
    map->array = (struct Node**)malloc(sizeof(struct Node*) * map->capacity);
}

int hashFunction(struct HashMap* map, char* key) {
    int bucketIndex, sum = 0, factor = 31; 
    for (int i = 0; i < strlen(key); i++) {
        sum = ((sum % map->capacity) + (((int)key[i]) * factor) % map->capacity) % map->capacity; 
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__; 
    }
    bucketIndex = sum; 
    return bucketIndex; 
}

void insert(struct HashMap* map, char* key, char* value) {
    int bucketIndex = hashFunction(map, key); 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    setNode(newNode, key, value); 
    if (map->array[bucketIndex] == NULL) {
        map->array[bucketIndex] = newNode; 
    } else {
        newNode->next = map->array[bucketIndex]; 
        map->array[bucketIndex] = newNode; 
    }
}

void deleteNode(struct HashMap* map, char* key) {
    int bucketIndex = hashFunction(map, key); 
    struct Node* prevNode = NULL; 
    struct Node* currNode = map->array[bucketIndex]; 
    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (currNode == map->array[bucketIndex]) {
                map->array[bucketIndex] = currNode->next; 
            } else {
                prevNode->next = currNode->next; 
            }
            free(currNode); 
            break; 
        }
        prevNode = currNode; 
        currNode = currNode->next; 
    }
}

char* search(struct HashMap* map, char* key) {
    int bucketIndex = hashFunction(map, key);
    struct Node* bucketHead = map->array[bucketIndex]; 
    while (bucketHead != NULL) {
        if (bucketHead->key == key) {
            return bucketHead->value; 
        }
        bucketHead = bucketHead->next; 
    }
    char* errorMessage = (char*)malloc(sizeof(char) * 25); 
    errorMessage = "Oops! No data found.\n"; 
    return errorMessage;
}

int main() {
    struct HashMap* map = (struct HashMap*)malloc(sizeof(struct HashMap)); 
    initializeHashMap(map); 
    insert(map, "Yogaholic", "Anjali"); 
    insert(map, "pluto14", "Vartika"); 
    insert(map, "elite_Programmer", "Manish"); 
    insert(map, "GFG", "BITS"); 
    insert(map, "decentBoy", "Mayank");

    printf("%s\n", search(map, "elite_Programmer")); 
    printf("%s\n", search(map, "Yogaholic")); 
    printf("%s\n", search(map, "pluto14")); 
    printf("%s\n", search(map, "decentBoy")); 
    printf("%s\n", search(map, "GFG")); 
    printf("%s\n", search(map, "randomKey")); 
    printf("\nAfter deletion : \n"); 
    deleteNode(map, "decentBoy"); 
    printf("%s\n", search(map, "decentBoy")); 

    return 0; 
}
