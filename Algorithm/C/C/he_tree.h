//
// Created by heboyce on 2020/6/23.
//

#ifndef ALGORITHM_HE_TREE_H
#define ALGORITHM_HE_TREE_H
#include "he_base.h"
typedef struct HEBinTree HEBinTree;

struct HEBinTree{
    void *value;
    HEBinTree *leftTree;
    HEBinTree *rightTree;
};

/*
 * 二叉树 兄弟节点表示法
 * 左边节点指向子树 有节点指向兄弟节点
 *
 * /

//前序遍历
void hePreOrderTraversal(HEBinTree *tree,heHandleValFunc func);
//中序遍历
void heMidOrderTraversal(HEBinTree *tree,heHandleValFunc func);
//后序遍历
void hePostOrderTraversal(HEBinTree *tree,heHandleValFunc func);
//求深度
int heDeptBinTree(HEBinTree *tree);
//求叶子节点
void heLeafBinTreeNode(HEBinTree *tree,heHandleValFunc func);
//转化为数组
void **heBinTreeToArray(HEBinTree *tree,int *size);

//二叉搜索树 相关
void heAddValueToSearchBinTree(HEBinTree *tree,void *value,heCompareValueFunc compareValueFunc);
//二叉搜索树 相关
void heDelValueFromSearchBinTree(HEBinTree *tree,void *value,heCompareValueFunc compareValueFunc);
//查找最大的value
void *heFindMaxValueFromSearchBinTree(HEBinTree *tree,heCompareValueFunc compareValueFunc);
//查找最小的value
void *heFindMinValueFromSearchBinTree(HEBinTree *tree,heCompareValueFunc compareValueFunc);


#endif //ALGORITHM_HE_TREE_H
