//
//  he_linkedlist.h
//  C
//
//  Created by heboyce on 2020/6/3.
//  Copyright © 2020 heboyce. All rights reserved.
//

#ifndef he_linkedlist_h
#define he_linkedlist_h

#include <stdio.h>

//1代表相等，0代表不相等
typedef int (*heEqulNodeFunc)(void *rVal,void *lVal);
typedef void (*heFreeNodeValueFunc)(void *Val);

//单向链表
typedef struct HElinkedList HElinkedList;
struct HElinkedList {
    void *value;
    HElinkedList *next;
};
//双向链表
typedef struct HEbothwayLinkedNode HEbothwayLinkedNode;
typedef struct HEbothwayLinkedList HEbothwayLinkedList;
struct HEbothwayLinkedNode {
    void *value;
    HEbothwayLinkedNode *next;
    HEbothwayLinkedNode *prior;
};

struct HEbothwayLinkedList {
    HEbothwayLinkedNode *head;
    HEbothwayLinkedNode *rear;
};

HEbothwayLinkedList* heCreateBothwayLinkedList(void);
int heAddBothwayLikedList(HEbothwayLinkedList*linkedList,void *value);
int heDeleteBothwayLikedList(HEbothwayLinkedList*linkedList,void *value ,heEqulNodeFunc func);
int heIsValueInBothwayLikedList(HEbothwayLinkedList*linkedList,void *value,heEqulNodeFunc func);
void heFreeBothwayLinkedList(HEbothwayLinkedList *linkedList,heFreeNodeValueFunc func);
//循环链表

#endif /* he_linkedlist_h */
