//
//  main.c
//  C
//
//  Created by heboyce on 2020/3/29.
//  Copyright © 2020 heboyce. All rights reserved.
//

#include <stdio.h>
#include "queue.h"

void testArrayQueue(void);

int main(int argc, const char * argv[]) {
    testArrayQueue();
    
    return 0;
}

void testArrayQueue(void){
   ArrayQueue *queue = createArrayQueue(10);
   int m1 = 11;
   addArrayQueue(queue, &m1);
    int m2 = 12;
    addArrayQueue(queue, &m2);
    int m3 = 13;
    addArrayQueue(queue, &m3);
    int m4 = 14;
    addArrayQueue(queue, &m4);
    int m5 = 15;
    addArrayQueue(queue, &m5);
    int m6 = 16;
    addArrayQueue(queue, &m6);
    int m7 = 17;
    addArrayQueue(queue, &m7);
    int m8 = 18;
    addArrayQueue(queue, &m8);
    int m9 = 19;
    addArrayQueue(queue, &m9);
    int m10 = 20;
    addArrayQueue(queue, &m10);
    
    if (isFullArrayQueue(queue) == 1) {
        printf("队列已满\n");
    }
    
    int *a1 = (int *)deleteArrayQueue(queue);
    printf("1:%d\n",(int)(*a1));
    int *a2 = (int *)deleteArrayQueue(queue);
    printf("2:%d\n",(int)(*a2));
    int *a3 = (int *)deleteArrayQueue(queue);
    printf("3:%d\n",(int)(*a3));
    int *a4 = (int *)deleteArrayQueue(queue);
    printf("4:%d\n",(int)(*a4));
    int *a5 = (int *)deleteArrayQueue(queue);
    printf("5:%d\n",(int)(*a5));
    int *a6 = (int *)deleteArrayQueue(queue);
    printf("6:%d\n",(int)(*a6));
    int *a7 = (int *)deleteArrayQueue(queue);
    printf("7:%d\n",(int)(*a7));
    int *a8 = (int *)deleteArrayQueue(queue);
    printf("8:%d\n",(int)(*a8));
    int *a9 = (int *)deleteArrayQueue(queue);
    printf("9:%d\n",(int)(*a9));
    int *a10 = (int *)deleteArrayQueue(queue);
    if (a10 != NULL) {
        printf("10:%d\n",(int)(*a10));
    }
    

    if (isEmptyArrayQueue(queue) == 1) {
        printf("队列是空的\n");
    }
    freeArrayQueue(queue);
}
