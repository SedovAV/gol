#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

// Структура двери
typedef struct door {
    int id;
    char* name;
} door_t;

// Структура узла списка
typedef struct node {
    door_t* door;
    struct node* next;
} node_t;

// Функции работы со списком
node_t* init(door_t* door);
node_t* add_door(node_t* elem, door_t* door);
node_t* find_door(int door_id, node_t* root);
node_t* remove_door(node_t* elem, node_t* root);
void destroy(node_t* root);

#endif // LIST_H
