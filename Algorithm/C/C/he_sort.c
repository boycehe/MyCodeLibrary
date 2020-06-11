//
// Created by heboyce on 2020/6/10.
//

/*
 * 归并排序
 * logn的层次
 * O(n) = nlogn
 * */
#include "he_sort.h"
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>

void heMergeSortRecurise(void **value,unsigned int left,unsigned int right,heCompareValueFunc func){

    if (left >= right) return;

    unsigned int mid = floor((right-left)/2);
    heMergeSortRecurise(value,left,left+mid,func);
    heMergeSortRecurise(value,left+mid+1,right,func);

    unsigned int leftLen    = mid + 1;
    unsigned int rightLen   = right - mid - left;
    unsigned int leftIndex  = 0;
    unsigned int rightIndex = 0;
    unsigned int index      = 0;
    void **leftValues = (void **)malloc(leftLen*sizeof(void *));
    void **rightValues = (void **)malloc(rightLen*sizeof(void *));
    memcpy(leftValues,value + left,sizeof(void *)*(leftLen));
    memcpy(rightValues,value + left + mid + 1,sizeof(void *)*(rightLen));
    while (leftIndex < leftLen && rightIndex < rightLen){
        void* leftTmpValue = *(leftValues + leftIndex);
        void* rightTmpValue = *(rightValues + rightIndex);
        HERelationalSymbols result = func(leftTmpValue,rightTmpValue);
        if (result == HELessThen){
            *(value + left + index) = leftTmpValue;
            leftIndex++;
        } else if(result == HEGreaterThen){
            *(value + left + index) = rightTmpValue;
            rightIndex++;
        }else{
            *(value + left + index) = leftTmpValue;
            index++;
            *(value + left + index) = rightTmpValue;
            leftIndex++;
            rightIndex++;
        }
            index++;
    }
    while (leftIndex < leftLen){
        *(value + left + index) = *(leftValues + leftIndex);
        leftIndex++;
        index++;
    }
    while (rightIndex < rightLen){
        *(value + left + index) = *(rightValues + rightIndex);
        rightIndex++;
        index++;
    }
    free(leftValues);
    free(rightValues);

}
void heMergeSortByRecursive(void **values,unsigned int size,heCompareValueFunc func){
    heMergeSortRecurise(values,0,size-1,func);
}

void heMergeSortNoRecursive(void **values,unsigned int size,heCompareValueFunc func){
    unsigned int step = 1;
    unsigned int numOfGroup = 0;
    unsigned int index = 0;
    while (1){
        if (index + step >= size) {
            if (index == 0) break;
            index = 0;
            step = step *2;
            continue;
        };
        void **leftValues = (void **)malloc(step*sizeof(void *));
        unsigned int rightStep = step;
        if (size - index - step < step){
            rightStep = size - index - step;
        }
        void **rightValues = (void **)malloc(rightStep*sizeof(void *));
        memcpy(leftValues,values+index,step*sizeof(void *));
        memcpy(rightValues,values+index+step,rightStep*sizeof(void *));
        unsigned int leftIndex  = 0;
        unsigned int rightIndex = 0;
        unsigned int innerindex = 0;
        while (leftIndex < step && rightIndex < rightStep){
            void* leftTmpValue = *(leftValues + leftIndex);
            void* rightTmpValue = *(rightValues + rightIndex);
            HERelationalSymbols result = func(leftTmpValue,rightTmpValue);
            if (result == HELessThen){
                *(values + index + innerindex) = leftTmpValue;
                leftIndex++;
            } else if(result == HEGreaterThen){
                *(values + index + innerindex) = rightTmpValue;
                rightIndex++;
            }else{
                *(values + index + innerindex) = leftTmpValue;
                innerindex++;
                *(values + index + innerindex) = rightTmpValue;
                leftIndex++;
                rightIndex++;
            }
            innerindex++;
        }
        while (leftIndex < step){
            *(values + innerindex + index) = *(leftValues + leftIndex);
            leftIndex++;
            innerindex++;
        }
        while (rightIndex < rightStep){
            *(values + innerindex + index) = *(rightValues + rightIndex);
            rightIndex++;
            innerindex++;
        }
        numOfGroup++;
        index = index + step + rightStep;
        free(leftValues);
        free(rightValues);

    }

}