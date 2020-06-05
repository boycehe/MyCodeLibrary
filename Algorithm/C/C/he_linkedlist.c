//
//  he_linkedlist.c
//  C
//
//  Created by heboyce on 2020/6/3.
//  Copyright © 2020 heboyce. All rights reserved.
//

#include "he_linkedlist.h"
#include <stdlib.h>
HEbothwayLinkedList* heCreateBothwayLinkedList(void){
    HEbothwayLinkedList *linkedList = (HEbothwayLinkedList *)malloc(sizeof(HEbothwayLinkedList));
    linkedList->head = NULL;
    linkedList->rear = NULL;
    return linkedList;
}
int heAddBothwayLikedList(HEbothwayLinkedList*linkedList,void *value){
    if (linkedList == NULL) {
        return 0;
    }
    HEbothwayLinkedNode *node = (HEbothwayLinkedNode *)calloc(1, sizeof(HEbothwayLinkedNode));
    node->value = value;
    node->next = NULL;
    if (linkedList->head == NULL) {
        linkedList->head = node;
        linkedList->rear = node;
    }else{
        node->prior = linkedList->rear;
        linkedList->rear = node;
    }
    return 1;
}


HEbothwayLinkedNode* heFindValueInBothwayLikedList(HEbothwayLinkedList*linkedList,void *value,heEqulNodeFunc func){

    if (func == NULL || value == NULL || linkedList == NULL) {
        return NULL;
    }
    HEbothwayLinkedNode *curNode = linkedList->head;
    while (curNode != NULL) {
        if (func(curNode->value,value) == 1) {
            return curNode;
        }
    }
    return NULL;
}

int heDeleteBothwayLikedList(HEbothwayLinkedList*linkedList,void *value ,heEqulNodeFunc func){

    HEbothwayLinkedNode *curNode = heFindValueInBothwayLikedList(linkedList,value,func);
    if (curNode == NULL) {
        return 0;
    }
    curNode->prior->next = curNode->next;
    curNode->next->prior = curNode->prior;
    return 1;
}

int heIsValueInBothwayLikedList(HEbothwayLinkedList*linkedList,void *value,heEqulNodeFunc func){
    HEbothwayLinkedNode *curNode = heFindValueInBothwayLikedList(linkedList,value,func);
    if (curNode == NULL) {
        return 0;
    }
    return 1;
}

void heFreeBothwayLinkedList(HEbothwayLinkedList *linkedList,heFreeNodeValueFunc func){
    if (linkedList == NULL) {
        return;
    }
    HEbothwayLinkedNode *curNode = linkedList->rear->prior;
    while (curNode != NULL) {
        if (func != NULL) {
            func(curNode->value);
        }
        free(curNode);
        curNode = curNode->prior;
    }
    free(linkedList);
}
