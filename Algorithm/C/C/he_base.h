//
//  he_base.h
//  C
//
//  Created by heboyce on 2020/6/5.
//  Copyright © 2020 heboyce. All rights reserved.
//

#ifndef he_base_h
#define he_base_h

//1代表相等，0代表不相等
typedef int (*heEqulNodeFunc)(void *rVal,void *lVal);
typedef void (*heFreeNodeValueFunc)(void *Val);

typedef struct HElinkedQueue HElinkedQueue;
typedef struct HElinkedNode HElinkedNode;
typedef struct HElinkedList HElinkedList;

struct HElinkedNode {
    void *value;
    HElinkedNode *next;
};

struct HElinkedQueue {
    HElinkedNode *front;
    HElinkedNode *rear;
};

struct HElinkedList {
    HElinkedNode *rear;
    HElinkedNode *head;
};

#endif /* he_base_h */
