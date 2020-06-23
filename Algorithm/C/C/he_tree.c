#include <stdio.h>
#include <stdlib.h>
#include "he_tree.h"

/*
 学习各种遍历的方法关键是要知道特性有那些，他们所应用的场景有哪些。一定要举出应用场景，负责学算法就只是为了应试。
 后续遍历，要和逆波兰表达式联系在一起，他可以很方便的处理具有优先级关系的运算式样如 1+2*3，计算机在处理这个运算式时，前序遍历和中序遍历都会产生回溯
 **/

//前序遍历
void hePreOrderTraversal(HEBinTree *tree,heHandleValFunc func){
	
	if (tree==0) {
		return;
	}
	if (func != NULL){
	    func(tree->value);
	}
	hePreOrderTraversal(tree->leftTree);
	hePreOrderTraversal(tree->rightTree);
	
}

//中序遍历
void heMidOrderTraversal(HEBinTree *tree,heHandleValFunc func){
	if (tree==0) {
			return;
	}
	heMidOrderTraversal(tree->leftTree);
    if (func != NULL){
        func(tree->value);
    }
	heMidOrderTraversal(tree->rightTree);
	
}
//后序遍历
void hePostOrderTraversal(HEBinTree *tree,heHandleValFunc func){
	if (tree==0) {
		return;
	}
	hePostOrderTraversal(tree->leftTree);
	hePostOrderTraversal(tree->rightTree);
    if (func != NULL){
        func(tree->value);
    }
}

//求深度
int heDeptBinTree(HEBinTree *tree){
    return 0;
}
//求叶子节点
void heLeafBinTreeNode(HEBinTree *tree,heHandleValFunc func){
    return;
}
//转化为数组
void **heBinTreeToArray(HEBinTree *tree,int *size){
    return NULL;
}
//二叉搜索树 相关
void heAddValueToSearchBinTree(HEBinTree *tree,void *value,heCompareValueFunc compareValueFunc){

}
//二叉搜索树 相关
void heDelValueFromSearchBinTree(HEBinTree *tree,void *value,heCompareValueFunc compareValueFunc){

}
//查找最大的value
void *heFindMaxValueFromSearchBinTree(HEBinTree *tree,heCompareValueFunc compareValueFunc){

}
//查找最小的value
void *heFindMinValueFromSearchBinTree(HEBinTree *tree,heCompareValueFunc compareValueFunc){

}

