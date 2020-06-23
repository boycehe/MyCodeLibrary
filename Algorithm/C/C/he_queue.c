//
//  queue.c
//  C
//
//  Created by heboyce on 2020/5/31.
//  Copyright © 2020 heboyce. All rights reserved.
//

#include "he_queue.h"
#include <stdlib.h>

HEArrayQueue* heCreateArrayQueue(int capacity){
    HEArrayQueue *queue = (HEArrayQueue *)malloc(sizeof(HEArrayQueue));
    queue->capacity = capacity+1;
    queue->values = (void **)malloc((capacity+1) * sizeof(void *));
    queue->front = 0;
    queue->rear  = 0;
    return queue;
}
int heIsFullArrayQueue(HEArrayQueue *queue){
    if((queue->rear + 1)%queue->capacity == queue->front) {
        return 1;
    }
    return 0;
}
int heAddValueArrayQueue(HEArrayQueue *queue,void *value){
    
   if ((queue->rear + 1)%queue->capacity == queue->front) {
        return 0;
    }
    *(queue->values+queue->rear)= value;
    queue->rear = (queue->rear+1)%queue->capacity;
    return 1;
}

int heIsEmptyArrayQueue(HEArrayQueue *queue){
    if (queue->rear == queue->front) {
        return 1;
    }
    return 0;
}

void* heDeleteValueArrayQueue(HEArrayQueue *queue){
    if (queue->rear == queue->front) {
        return NULL;
    }
    void *value = *(queue->values + queue->front);
    queue->front = (queue->front+1)%queue->capacity;
    return value;
}

void heFreeArrayQueue(HEArrayQueue *queue){
    if (queue == NULL) {
        return;
    }
    free(queue->values);
    free(queue);
}

HElinkedQueue* heCreateLinkedQueue(void){
    HElinkedQueue *queue = (HElinkedQueue *)malloc(sizeof(HElinkedQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int heIsEmptyLinkedQueue(HElinkedQueue *queue){
    if(queue->front == NULL) return 1;
    return 0;
}

void heAddValueLinkedQueue(HElinkedQueue *queue,void *value){
    HElinkedNode *node = (HElinkedNode *)malloc(sizeof(HElinkedNode));
    node->value = value;
    node->next = NULL;
    if (queue->rear == NULL) {
        queue->rear = node;
    }else{
        queue->rear->next = node;
        queue->rear = node;
    }
    if (queue->front == NULL) {
        queue->front = node;
    }
}

void* heDeleteValueLinkedQueue(HElinkedQueue *queue){
    HElinkedNode *frontNode = queue->front;
    queue->front = queue->front->next;
    void *value = frontNode->value;
    free(frontNode);
    return value;
}

void heFreeLinkedQueue(HElinkedQueue *queue,heFreeNodeValueFunc func){
    while (queue->front != NULL) {
        HElinkedNode *curNode = queue->front;
        queue->front = queue->front->next;
        if (func) {
            func(curNode->value);
        }
        free(curNode);
    }
    free(queue);
}
