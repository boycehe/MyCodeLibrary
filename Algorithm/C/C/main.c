//
//  main.c
//  C
//
//  Created by heboyce on 2020/3/29.
//  Copyright © 2020 heboyce. All rights reserved.
//

#include <stdio.h>
#include "he_queue.h"
#include "he_linkedlist.h"
#include "he_stack.h"

void testArrayQueue(void);
void teatLinkedQueue(void);
void testLinkedList(void);
void testLinkedList2(void);
void testStack(void);

int equalInt(void *rVal,void *lVal){
    int *r = (int*)(rVal);
    int *l = (int*)(lVal);
    if (*r == *l) {
        return 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
//  testArrayQueue();
//  teatLinkedQueue();
//  testLinkedList();
//  testLinkedList2();
    testStack();
    return 0;
}

void testStack(void){
   HEStack *stack = heCreateStack(10);
   int m1 = 11;
   hePush(stack, &m1);
   int m2 = 12;
   hePush(stack, &m2);
   int m3 = 13;
   hePush(stack, &m3);
   int m4 = 14;
   hePush(stack, &m4);
   int m5 = 15;
   hePush(stack, &m5);
   int m6 = 16;
   hePush(stack, &m6);
   int m7 = 17;
   hePush(stack, &m7);
   int m8 = 18;
   hePush(stack, &m8);
   int m9 = 19;
   hePush(stack, &m9);
   int m10 = 20;
   hePush(stack, &m10);
    
   
   int *a1 = (int *)hePop(stack);
   printf("link->1:%d\n",(int)(*a1));
   
   int *a2 = (int *)hePop(stack);
   printf("link->2:%d\n",(int)(*a2));
   
   int *a3 = (int *)hePop(stack);
   printf("link->3:%d\n",(int)(*a3));
   
   int *a4 = (int *)hePop(stack);
   printf("link->4:%d\n",(int)(*a4));
   
   int *a5 = (int *)hePop(stack);
   printf("link->5:%d\n",(int)(*a5));
   
   int *a6 = (int *)hePop(stack);
   printf("link->6:%d\n",(int)(*a6));
   
   int *a7 = (int *)hePop(stack);
   printf("link->7:%d\n",(int)(*a7));
   
   int *a8 = (int *)hePop(stack);
   printf("link->8:%d\n",(int)(*a8));
   
   int *a9 = (int *)hePop(stack);
   printf("link->9:%d\n",(int)(*a9));
   
   int *a10 = (int *)hePop(stack);
   if (a10 != NULL) {
       printf("link->10:%d\n",(int)(*a10));
   }
    heFreeStack(stack, NULL);
}

void testLinkedList(void){
    
    HElinkedList *list = heCreateLinkedList();
    int m1 = 11;
    heAddLinkedList(list, &m1);
    int m2 = 12;
    heAddLinkedList(list, &m2);
    int m3 = 13;
    heAddLinkedList(list, &m3);
    int m4 = 14;
    heAddLinkedList(list, &m4);
    int m5 = 15;
    heAddLinkedList(list, &m5);
    int m6 = 16;
    heAddLinkedList(list, &m6);
    int m7 = 17;
    heAddLinkedList(list, &m7);
    int m8 = 18;
    heAddLinkedList(list, &m8);
    int m9 = 19;
    heAddLinkedList(list, &m9);
    int m10 = 20;
    heAddLinkedList(list, &m10);

    int b1 = 20;
    int *a1 = (int *)heDeleteLinkedList(list,&b1,&equalInt);
    printf("link->1:%d\n",(int)(*a1));
    int b2 = 19;
    int *a2 = (int *)heDeleteLinkedList(list,&b2,&equalInt);
    printf("link->2:%d\n",(int)(*a2));
    int b3 = 18;
    int *a3 = (int *)heDeleteLinkedList(list,&b3,&equalInt);
    printf("link->3:%d\n",(int)(*a3));
    int b4 = 17;
    int *a4 = (int *)heDeleteLinkedList(list,&b4,&equalInt);
    printf("link->4:%d\n",(int)(*a4));
    int b5 = 16;
    int *a5 = (int *)heDeleteLinkedList(list,&b5,&equalInt);
    printf("link->5:%d\n",(int)(*a5));
    int b6 = 15;
    int *a6 = (int *)heDeleteLinkedList(list,&b6,&equalInt);
    printf("link->6:%d\n",(int)(*a6));
    int b7 = 14;
    int *a7 = (int *)heDeleteLinkedList(list,&b7,&equalInt);
    printf("link->7:%d\n",(int)(*a7));
    int b8 = 13;
    int *a8 = (int *)heDeleteLinkedList(list,&b8,&equalInt);
    printf("link->8:%d\n",(int)(*a8));
    int b9 = 12;
    int *a9 = (int *)heDeleteLinkedList(list,&b9,&equalInt);
    printf("link->9:%d\n",(int)(*a9));
    int b10 = 11;
    int *a10 = (int *)heDeleteLinkedList(list,&b10,&equalInt);
    if (a10 != NULL) {
        printf("link->10:%d\n",(int)(*a10));
    }
    heFreeLinkedList(list, NULL);
    
    
}
void testLinkedList2(void){
    
    HEbothwayLinkedList *list = heCreateBothwayLinkedList();
    int m1 = 11;
    heAddBothwayLikedList(list, &m1);
    int m2 = 12;
    heAddBothwayLikedList(list, &m2);
    int m3 = 13;
    heAddBothwayLikedList(list, &m3);
    int m4 = 14;
    heAddBothwayLikedList(list, &m4);
    int m5 = 15;
    heAddBothwayLikedList(list, &m5);
    int m6 = 16;
    heAddBothwayLikedList(list, &m6);
    int m7 = 17;
    heAddBothwayLikedList(list, &m7);
    int m8 = 18;
    heAddBothwayLikedList(list, &m8);
    int m9 = 19;
    heAddBothwayLikedList(list, &m9);
    int m10 = 20;
    heAddBothwayLikedList(list, &m10);
    int b1 = 20;
    int *a1 = (int *)heDeleteBothwayLinkedList(list,&b1,&equalInt);
    printf("link->1:%d\n",(int)(*a1));
    int b2 = 19;
    int *a2 = (int *)heDeleteBothwayLinkedList(list,&b2,&equalInt);
    printf("link->2:%d\n",(int)(*a2));
    int b3 = 18;
    int *a3 = (int *)heDeleteBothwayLinkedList(list,&b3,&equalInt);
    printf("link->3:%d\n",(int)(*a3));
    int b4 = 17;
    int *a4 = (int *)heDeleteBothwayLinkedList(list,&b4,&equalInt);
    printf("link->4:%d\n",(int)(*a4));
    int b5 = 16;
    int *a5 = (int *)heDeleteBothwayLinkedList(list,&b5,&equalInt);
    printf("link->5:%d\n",(int)(*a5));
    int b6 = 15;
    int *a6 = (int *)heDeleteBothwayLinkedList(list,&b6,&equalInt);
    printf("link->6:%d\n",(int)(*a6));
    int b7 = 14;
    int *a7 = (int *)heDeleteBothwayLinkedList(list,&b7,&equalInt);
    printf("link->7:%d\n",(int)(*a7));
    int b8 = 13;
    int *a8 = (int *)heDeleteBothwayLinkedList(list,&b8,&equalInt);
    printf("link->8:%d\n",(int)(*a8));
    int b9 = 12;
    int *a9 = (int *)heDeleteBothwayLinkedList(list,&b9,&equalInt);
    printf("link->9:%d\n",(int)(*a9));
    int b10 = 11;
    int *a10 = (int *)heDeleteBothwayLinkedList(list,&b10,&equalInt);
    if (a10 != NULL) {
        printf("link->10:%d\n",(int)(*a10));
    }
    heFreeBothwayLinkedList(list, NULL);
    
    
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
    heFreeLinkedQueue(queue,NULL);
    
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
