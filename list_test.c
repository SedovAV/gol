#include "list.h"
#include <stdio.h>
#include <assert.h>

#define SUCCESS 0
#define FAIL 1

int test_add_door() {
    // Создаем начальную дверь
    door_t* door1 = (door_t*)malloc(sizeof(door_t));
    door1->id = 1;
    door1->name = "Door 1";

    // Инициализируем список
    node_t* root = init(door1);

    // Добавляем новую дверь
    door_t* door2 = (door_t*)malloc(sizeof(door_t));
    door2->id = 2;
    door2->name = "Door 2";

    node_t* added = add_door(root, door2);

    // Проверяем, что добавление прошло успешно
    if (!added || added->door->id != 2) {
        destroy(root);
        return FAIL;
    }

    // Проверяем, что связь сохранена
    if (root->next != added) {
        destroy(root);
        return FAIL;
    }

    destroy(root);
    return SUCCESS;
}

int test_remove_door() {
    // Создаем начальные двери
    door_t* door1 = (door_t*)malloc(sizeof(door_t));
    door1->id = 1;
    door1->name = "Door 1";

    door_t* door2 = (door_t*)malloc(sizeof(door_t));
    door2->id = 2;
    door2->name = "Door 2";

    // Инициализируем список
    node_t* root = init(door1);
    add_door(root, door2);

    // Удаляем вторую дверь
    node_t* new_root = remove_door(root->next, root);

    // Проверяем, что удаление прошло успешно
    if (new_root == root->next || new_root->next != NULL) {
        destroy(new_root);
        return FAIL;
    }

    // Проверяем, что корень остался тем же
    if (new_root != root) {
        destroy(new_root);
        return FAIL;
    }

    destroy(new_root);
    return SUCCESS;
}

int main() {
    int result = SUCCESS;

    printf("=== Тестирование функции add_door ===\n");
    int add_result = test_add_door();
    if (add_result == SUCCESS)
        printf("Тест add_door пройден успешно\n");
    else
        printf("Ошибка в тесте add_door\n");
    result |= add_result;

    printf("\n=== Тестирование функции remove_door ===\n");
    int remove_result = test_remove_door();
    if (remove_result == SUCCESS)
        printf("Тест remove_door пройден успешно\n");
    else
        printf("Ошибка в тесте remove_door\n");
    result |= remove_result;

    return result;
}
