//
//  he_stack.h
//  C
//
//  Created by heboyce on 2020/6/5.
//  Copyright © 2020 heboyce. All rights reserved.
//

#ifndef he_stack_h
#define he_stack_h

#include <stdio.h>
#include "he_base.h"


HEStack *heCreateStack(unsigned int size);
int hePush(HEStack *stack,void *value);
void *hePop(HEStack *stack);
void *heGetTop(HEStack *stack);
int heClearStack(HEStack *stack,heFreeNodeValueFunc func);
int heFreeStack(HEStack *stack,heFreeNodeValueFunc func);


#endif /* he_stack_h */
