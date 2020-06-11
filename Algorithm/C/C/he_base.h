//
//  he_base.h
//  C
//
//  Created by heboyce on 2020/6/5.
//  Copyright © 2020 heboyce. All rights reserved.
//

#ifndef he_base_h
#define he_base_h

#define he_equal 0
#define he_greater_then 1
#define he_less_then -1

typedef enum HERelationalSymbols{
    HELessThen = -1,
    HEEqual = 0,
    HEGreaterThen = 1
}HERelationalSymbols;

//1代表相等，0代表不相等
typedef int (*heEqulNodeFunc)(void *rVal,void *lVal);
typedef void (*heFreeNodeValueFunc)(void *Val);
//HELessThen is rVal < lVal
typedef HERelationalSymbols (*heCompareValueFunc)(void *rVal,void *lVal);

typedef struct HElinkedQueue HElinkedQueue;
typedef struct HElinkedNode HElinkedNode;
typedef struct HElinkedList HElinkedList;
typedef struct HEStack  HEStack;

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

struct HEStack {
    unsigned int stack_size;
    unsigned int top;
    void    **items;
    
};

#endif /* he_base_h */
