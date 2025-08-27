#include "list.h"
#include <string.h>

// Инициализация структуры односвязного списка
node_t* init(door_t* door) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    if (!node) return NULL;

    node->door = door;
    node->next = NULL;

    return node;
}

// Вставка нового элемента в список после переданного узла
node_t* add_door(node_t* elem, door_t* door) {
    if (!elem) return NULL;

    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (!new_node) return NULL;

    new_node->door = door;
    new_node->next = elem->next;
    elem->next = new_node;

    return new_node;
}

// Поиск двери в списке по её id
node_t* find_door(int door_id, node_t* root) {
    node_t* current = root;

    while (current) {
        if (current->door && current->door->id == door_id)
            return current;
        current = current->next;
    }

    return NULL;
}

// Удаление элемента списка
node_t* remove_door(node_t* elem, node_t* root) {
    if (!elem || !root) return NULL;

    // Если удаляем корень
    if (elem == root) {
        node_t* next = elem->next;
        free(elem);
        return next; // Новый корень
    }

    // Ищем предыдущий элемент
    node_t* current = root;
    while (current && current->next != elem) {
        current = current->next;
    }

    if (!current) return root; // Элемент не найден

    current->next = elem->next;
    free(elem);
    return root;
}

// Освобождение памяти, занимаемой списком
void destroy(node_t* root) {
    node_t* current = root;
    while (current) {
        node_t* next = current->next;
        if (current->door && current->door->name)
            free(current->door->name);
        free(current->door);
        free(current);
        current = next;
    }
}
