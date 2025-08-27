#include "stack.h"
#include <stdio.h>

int test_push() {
    Stack s;
    if (init(&s) != SUCCESS) return FAIL;

    if (push(&s, 10) != SUCCESS) return FAIL;
    if (push(&s, 20) != SUCCESS) return FAIL;
    if (push(&s, 30) != SUCCESS) return FAIL;
    if (push(&s, 40) != SUCCESS) return FAIL;
    if (push(&s, 50) != SUCCESS) return FAIL; // Проверка расширения

    destroy(&s);
    return SUCCESS;
}

int test_pop() {
    Stack s;
    if (init(&s) != SUCCESS) return FAIL;

    if (push(&s, 10) != SUCCESS) return FAIL;
    if (push(&s, 20) != SUCCESS) return FAIL;

    int val;
    if (pop(&s, &val) != SUCCESS) return FAIL;
    if (val != 20) return FAIL;

    if (pop(&s, &val) != SUCCESS) return FAIL;
    if (val != 10) return FAIL;

    if (pop(&s, &val) != FAIL) return FAIL; // Попытка удалить из пустого стека

    destroy(&s);
    return SUCCESS;
}

int main() {
    int result = SUCCESS;

    printf("=== Тестирование функции push ===\n");
    if (test_push() != SUCCESS) {
        printf("Тест push провален\n");
        result = FAIL;
    } else {
        printf("Тест push пройден успешно\n");
    }

    printf("=== Тестирование функции pop ===\n");
    if (test_pop() != SUCCESS) {
        printf("Тест pop провален\n");
        result = FAIL;
    } else {
        printf("Тест pop пройден успешно\n");
    }

    return result;
}
