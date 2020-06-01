//
//  linkedList.c
//  C
//
//  Created by heboyce on 2020/5/31.
//  Copyright © 2020 heboyce. All rights reserved.
//

#include "linkedList.h"
/*
 多项式的数据结构
 **/
typedef struct PolyNode *Ploynomial;
struct PolyNode {
    int coef;//系数
    int expon;//指数
    Ploynomial link;
};
