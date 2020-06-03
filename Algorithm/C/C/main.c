//
//  main.c
//  C
//
//  Created by heboyce on 2020/3/29.
//  Copyright © 2020 heboyce. All rights reserved.
//

#include <stdio.h>
#include "he_queue.h"

void testArrayQueue(void);
void teatLinkedQueue(void);

int main(int argc, const char * argv[]) {
    testArrayQueue();
    teatLinkedQueue();
    return 0;
}

void teatLinkedQueue(void){
   HElinkedQueue *queue = heCreateLinkedQueue();
    int m1 = 11;
    heAddLinkedQueue(queue, &m1);
    int m2 = 12;
    heAddLinkedQueue(queue, &m2);
    int m3 = 13;
    heAddLinkedQueue(queue, &m3);
    int m4 = 14;
    heAddLinkedQueue(queue, &m4);
    int m5 = 15;
    heAddLinkedQueue(queue, &m5);
    int m6 = 16;
    heAddLinkedQueue(queue, &m6);
    int m7 = 17;
    heAddLinkedQueue(queue, &m7);
    int m8 = 18;
    heAddLinkedQueue(queue, &m8);
    int m9 = 19;
    heAddLinkedQueue(queue, &m9);
    int m10 = 20;
    heAddLinkedQueue(queue, &m10);
    
    int *a1 = (int *)heDeleteLinkedQueue(queue);
    printf("link->1:%d\n",(int)(*a1));
    int *a2 = (int *)heDeleteLinkedQueue(queue);
    printf("link->2:%d\n",(int)(*a2));
    int *a3 = (int *)heDeleteLinkedQueue(queue);
    printf("link->3:%d\n",(int)(*a3));
    int *a4 = (int *)heDeleteLinkedQueue(queue);
    printf("link->4:%d\n",(int)(*a4));
    int *a5 = (int *)heDeleteLinkedQueue(queue);
    printf("link->5:%d\n",(int)(*a5));
    int *a6 = (int *)heDeleteLinkedQueue(queue);
    printf("link->6:%d\n",(int)(*a6));
    int *a7 = (int *)heDeleteLinkedQueue(queue);
    printf("link->7:%d\n",(int)(*a7));
    int *a8 = (int *)heDeleteLinkedQueue(queue);
    printf("link->8:%d\n",(int)(*a8));
    int *a9 = (int *)heDeleteLinkedQueue(queue);
    printf("link->9:%d\n",(int)(*a9));
    int *a10 = (int *)heDeleteLinkedQueue(queue);
    if (a10 != NULL) {
        printf("link->10:%d\n",(int)(*a10));
    }
    if (heIsEmptyLinkedQueue(queue) == 1) {
        printf("linked 队列是空的\n");
    }
    heFreeLinkedQueue(queue);
    
}

void testArrayQueue(void){
   HEArrayQueue *queue = heCreateArrayQueue(10);
   int m1 = 11;
    heAddArrayQueue(queue, &m1);
    int m2 = 12;
    heAddArrayQueue(queue, &m2);
    int m3 = 13;
    heAddArrayQueue(queue, &m3);
    int m4 = 14;
    heAddArrayQueue(queue, &m4);
    int m5 = 15;
    heAddArrayQueue(queue, &m5);
    int m6 = 16;
    heAddArrayQueue(queue, &m6);
    int m7 = 17;
    heAddArrayQueue(queue, &m7);
    int m8 = 18;
    heAddArrayQueue(queue, &m8);
    int m9 = 19;
    heAddArrayQueue(queue, &m9);
    int m10 = 20;
    heAddArrayQueue(queue, &m10);
    
    if (heIsFullArrayQueue(queue) == 1) {
        printf("队列已满\n");
    }
    
    int *a1 = (int *)heDeleteArrayQueue(queue);
    printf("1:%d\n",(int)(*a1));
    int *a2 = (int *)heDeleteArrayQueue(queue);
    printf("2:%d\n",(int)(*a2));
    int *a3 = (int *)heDeleteArrayQueue(queue);
    printf("3:%d\n",(int)(*a3));
    int *a4 = (int *)heDeleteArrayQueue(queue);
    printf("4:%d\n",(int)(*a4));
    int *a5 = (int *)heDeleteArrayQueue(queue);
    printf("5:%d\n",(int)(*a5));
    int *a6 = (int *)heDeleteArrayQueue(queue);
    printf("6:%d\n",(int)(*a6));
    int *a7 = (int *)heDeleteArrayQueue(queue);
    printf("7:%d\n",(int)(*a7));
    int *a8 = (int *)heDeleteArrayQueue(queue);
    printf("8:%d\n",(int)(*a8));
    int *a9 = (int *)heDeleteArrayQueue(queue);
    printf("9:%d\n",(int)(*a9));
    int *a10 = (int *)heDeleteArrayQueue(queue);
    if (a10 != NULL) {
        printf("10:%d\n",(int)(*a10));
    }
    

    if (heIsEmptyArrayQueue(queue) == 1) {
        printf("队列是空的\n");
    }
    heFreeArrayQueue(queue);
}
