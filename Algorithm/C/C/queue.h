//
//  queue.h
//  C
//
//  Created by heboyce on 2020/5/31.
//  Copyright © 2020 heboyce. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>

/*
 数组队列
 **/
typedef struct ArrayQueue ArrayQueue;

struct ArrayQueue {
    int capacity;
    void **values;
    int rear;
    int front;
};

ArrayQueue* createArrayQueue(int capacity);
int isFullArrayQueue(ArrayQueue *queue);
int addArrayQueue(ArrayQueue *queue,void *value);
int isEmptyArrayQueue(ArrayQueue *queue);
void* deleteArrayQueue(ArrayQueue *queue);
void freeArrayQueue(ArrayQueue *queue);

/*
 链式队列
 **/

typedef struct LinkedQueue LinkedQueue;

struct LinkedQueue {
    
};

LinkedQueue* createLinkedQueue(int capacity);
int isFullLinkedQueue(LinkedQueue *queue);
void addLinkedQueue(void *value);
int isEmptyLinkedQueue(LinkedQueue *queue);
void* deleteLinkedQueue(LinkedQueue *queue);

#endif /* queue_h */
