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
#include "he_base.h"
//单向链表

HElinkedList* heCreateLinkedList(void);
int heAddLinkedList(HElinkedList*linkedList,void *value);
void* heDeleteLinkedList(HElinkedList*linkedList,void *value ,heEqulNodeFunc func);
int heIsValueInLinkedList(HElinkedList*linkedList,void *value,heEqulNodeFunc func);
void heFreeLinkedList(HElinkedList *linkedList,heFreeNodeValueFunc func);

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
void* heDeleteBothwayLinkedList(HEbothwayLinkedList*linkedList,void *value ,heEqulNodeFunc func);
int heIsValueInBothwayLinkedList(HEbothwayLinkedList*linkedList,void *value,heEqulNodeFunc func);
void heFreeBothwayLinkedList(HEbothwayLinkedList *linkedList,heFreeNodeValueFunc func);
//循环链表

#endif /* he_linkedlist_h */
