//
//  he_stack.c
//  C
//
//  Created by heboyce on 2020/6/5.
//  Copyright © 2020 heboyce. All rights reserved.
//

#include "he_stack.h"
#include <stdlib.h>

HEStack *heCreateStack(unsigned int size){
    HEStack *stack = (HEStack *)malloc(sizeof(HEStack));
    stack->stack_size = size;
    stack->top = 0;
    stack->items = calloc(size, sizeof(void *));
    return stack;
}

int hePush(HEStack *stack,void *value){
    if (stack->stack_size == (stack->top + 1)) {
        return 0;
    }
    *(stack->items + stack->top) = value;
    stack->top++;
    return 1;
}

void *hePop(HEStack *stack){
    if (stack->top == 0) {
        return NULL;
    }
    stack->top--;
    return *(stack->items + stack->top);
    
}

void *heGetTop(HEStack *stack){
    if (stack->top == 0) {
        return NULL;
    }
    return *(stack->items + (stack->top - 1));
}

int heClearStack(HEStack *stack,heFreeNodeValueFunc func){
    void* value = hePop(stack);
    while (value != NULL) {
        if (func != NULL) {
            func(value);
        }
        value = hePop(stack);
        
    }
    return 1;
}

int heFreeStack(HEStack *stack,heFreeNodeValueFunc func){
    heClearStack(stack, func);
    free(stack->items);
    free(stack);
    return 1;
}
