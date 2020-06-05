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
#include "he_base.h"
/*
 数组队列
 **/
typedef struct HEArrayQueue HEArrayQueue;

struct HEArrayQueue {
    int capacity;
    void **values;
    int rear;
    int front;
};

HEArrayQueue* heCreateArrayQueue(int capacity);
int heIsFullArrayQueue(HEArrayQueue *queue);
int heAddArrayQueue(HEArrayQueue *queue,void *value);
int heIsEmptyArrayQueue(HEArrayQueue *queue);
void* heDeleteArrayQueue(HEArrayQueue *queue);
void heFreeArrayQueue(HEArrayQueue *queue);

/*
 链式队列
 **/


HElinkedQueue* heCreateLinkedQueue(void);
void heAddLinkedQueue(HElinkedQueue *queue,void *value);
int heIsEmptyLinkedQueue(HElinkedQueue *queue);
void* heDeleteLinkedQueue(HElinkedQueue *queue);
void heFreeLinkedQueue(HElinkedQueue *queue,heFreeNodeValueFunc func);

#endif /* queue_h */
