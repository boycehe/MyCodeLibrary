//
//  he_linkedlist.c
//  C
//
//  Created by heboyce on 2020/6/3.
//  Copyright © 2020 heboyce. All rights reserved.
//

#include "he_linkedlist.h"
#include <stdlib.h>

//单向链表
HElinkedList* heCreateLinkedList(void){
    
    HElinkedList *list = (HElinkedList *)malloc(sizeof(HElinkedList));
    list->head = NULL;
    list->rear = NULL;
    return list;
    
}
int heAddLinkedList(HElinkedList*linkedList,void *value){
    HElinkedNode *node = (HElinkedNode *)malloc(sizeof(HElinkedNode));
    node->value = value;
    node->next  = NULL;
    if (linkedList->head == NULL) {
        linkedList->head = node;
        linkedList->rear = node;
    }else{
        linkedList->rear->next = node;
        linkedList->rear = node;
    }
    return 1;
}

HElinkedNode* heFindValueInLikedList(HElinkedList*linkedList,void *value,heEqulNodeFunc func){

    if (func == NULL || value == NULL || linkedList == NULL) {
        return NULL;
    }
    HElinkedNode *curNode = linkedList->head;
    while (curNode != NULL) {
        if (func(curNode->value,value) == 1) {
            return curNode;
        }
    }
    return NULL;
}
void* heDeleteLinkedList(HElinkedList*linkedList,void *value ,heEqulNodeFunc func){
    
    if (func == NULL || value == NULL || linkedList == NULL) {
        return 0;
    }
    HElinkedNode *preNode = NULL;
    HElinkedNode *curNode = linkedList->head;
    while (curNode != NULL) {
        if (func(curNode->value,value) != 1) {
            preNode = curNode;
            curNode = curNode->next;
            continue;
        }
        if (preNode != NULL) {
            preNode->next = curNode->next;
        }
        
        void *cValue = curNode->value;
        if (curNode == linkedList->head) {
            linkedList->head = curNode->next;
        }
        
        if (curNode == linkedList->rear) {
            linkedList->rear = preNode;
        }
        
        free(curNode);
        return cValue;
    }
    return NULL;

}
int heIsValueInLinkedList(HElinkedList*linkedList,void *value,heEqulNodeFunc func){
    HElinkedNode *curNode = heFindValueInLikedList(linkedList, value, func);
    if (curNode == NULL) {
        return 0;
    }
    return 1;
}
void heFreeLinkedList(HElinkedList *linkedList,heFreeNodeValueFunc func){
    HElinkedNode *curNode = linkedList->head;
    while (curNode != NULL) {
        if (func) {
            func(curNode->value);
        }
        free(curNode);
    }
    free(linkedList);
}

//双向链表
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
        linkedList->rear->next = node;
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
        curNode = curNode->next;
    }
    return NULL;
}

void* heDeleteBothwayLinkedList(HEbothwayLinkedList*linkedList,void *value ,heEqulNodeFunc func){

    HEbothwayLinkedNode *curNode = heFindValueInBothwayLikedList(linkedList,value,func);
    if (curNode == NULL) {
        return NULL;
    }
    
    //如果是头部节点
    if (curNode == linkedList->head) {
        linkedList->head = curNode->next;
    }
    
    if (curNode == linkedList->rear) {
        linkedList->rear = curNode->prior;
    }
    
    if (curNode->prior != NULL) {
        curNode->prior->next = curNode->next;
    }
    
    if (curNode->next != NULL) {
        curNode->next->prior = curNode->prior;
    }
    
    void *cValue = curNode->value;
    free(curNode);
    return cValue;
}

int heIsValueInBothwayLinkedList(HEbothwayLinkedList*linkedList,void *value,heEqulNodeFunc func){
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
    if (linkedList->rear == NULL && linkedList->head == NULL) {
        free(linkedList);
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
