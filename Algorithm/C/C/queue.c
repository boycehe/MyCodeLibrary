//
//  queue.c
//  C
//
//  Created by heboyce on 2020/5/31.
//  Copyright © 2020 heboyce. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>

ArrayQueue* createArrayQueue(int capacity){
    ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    queue->capacity = capacity+1;
    queue->values = (void **)malloc((capacity+1) * sizeof(void *));
    queue->front = 0;
    queue->rear  = 0;
    return queue;
}
int isFullArrayQueue(ArrayQueue *queue){
    if((queue->rear + 1)%queue->capacity == queue->front) {
        return 1;
    }
    return 0;
}
int addArrayQueue(ArrayQueue *queue,void *value){
    
   if ((queue->rear + 1)%queue->capacity == queue->front) {
        return 0;
    }
    *(queue->values+queue->rear)= value;
    queue->rear = (queue->rear+1)%queue->capacity;
    return 1;
}

int isEmptyArrayQueue(ArrayQueue *queue){
    if (queue->rear == queue->front) {
        return 1;
    }
    return 0;
}

void* deleteArrayQueue(ArrayQueue *queue){
    if (queue->rear == queue->front) {
        return NULL;
    }
    void *value = *(queue->values + queue->front);
    queue->front = (queue->front+1)%queue->capacity;
    return value;
}

void freeArrayQueue(ArrayQueue *queue){
    if (queue == NULL) {
        return;
    }
    free(queue->values);
    free(queue);
}
