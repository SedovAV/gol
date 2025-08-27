#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#define SUCCESS 0
#define FAIL -1

// Структура динамического стека
typedef struct Stack {
    int *data;
    size_t capacity;
    size_t top;
} Stack;

// Инициализация стека
int init(Stack *stack);

// Добавление элемента в стек
int push(Stack *stack, int value);

// Удаление элемента из стека
int pop(Stack *stack, int *value);

// Освобождение памяти стека
void destroy(Stack *stack);

#endif // STACK_H
