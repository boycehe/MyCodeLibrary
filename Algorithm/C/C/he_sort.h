//
// Created by heboyce on 2020/6/10.
//

#ifndef ALGORITHM_HE_SORT_H
#define ALGORITHM_HE_SORT_H
#include "he_base.h"
//归并排序递归实现
void heMergeSortByRecursive(void **values,unsigned int size,heCompareValueFunc func);
//归并排序非递归实现
void heMergeSortNoRecursive(void **values,unsigned int size,heCompareValueFunc func);
#endif //ALGORITHM_HE_SORT_H
