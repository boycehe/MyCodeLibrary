#include <stdio.h>

typedef struct HEBinTree HEBinTree;

struct HEBinTree{
	int value;
	HEBinTree *leftTree;
	HEBinTree *rightTree;
};

/*
																-78-
											
								-44-				   										 			-209-								
				    -30-	 					  -55-								   -189-						   -320-
			28				38				52				58		 			100				200				300				450
		12	   29 		35   	40		50		54		57		60			90		 120	190		202		 290	310		 440	460
*/

HEBinTree *heAddLeftTree(HEBinTree *tree,int value){
	
	if (tree == 0) {
		return 0;
	}
	
	HEBinTree *leftTree = (HEBinTree *)malloc(sizeof(HEBinTree));
	leftTree->value = value;
	tree->leftTree = leftTree;
	return leftTree;
	

}

HEBinTree *heAddRightTree(HEBinTree *tree,int value){
	if (tree == 0) {
		return 0;
	}
	HEBinTree *rightTree = (HEBinTree *)malloc(sizeof(HEBinTree));
	rightTree->value = value;
	tree->rightTree = rightTree;
	return rightTree;
}

HEBinTree *heDemoHEBinTree(){
	
	
	HEBinTree *rootTree = (HEBinTree *)malloc(sizeof(HEBinTree));
	rootTree->value = 78;
	HEBinTree *leftTree = heAddLeftTree(rootTree, 44);
	rootTree->leftTree = leftTree;
	HEBinTree *rightTree = heAddRightTree(rootTree, 209);
	rootTree->rightTree = rightTree;
	
	leftTree->leftTree = heAddLeftTree(rootTree->leftTree, 30);
	leftTree->rightTree = heAddRightTree(rootTree->leftTree, 55);
	
	leftTree->leftTree->leftTree = heAddLeftTree(leftTree->leftTree, 28);
	leftTree->leftTree->rightTree = heAddRightTree(leftTree->leftTree, 38);
		
	leftTree->rightTree->leftTree = heAddLeftTree(leftTree->rightTree, 52);
	leftTree->rightTree->rightTree = heAddRightTree(leftTree->rightTree, 58);
	
	leftTree->leftTree->leftTree->leftTree = heAddLeftTree(leftTree->leftTree->leftTree, 12);
	leftTree->leftTree->leftTree->rightTree = heAddRightTree(leftTree->leftTree->leftTree, 29);
	
	leftTree->leftTree->rightTree->leftTree = heAddLeftTree(leftTree->leftTree->rightTree, 35);
	leftTree->leftTree->rightTree->rightTree = heAddRightTree(leftTree->leftTree->rightTree, 40);
	
	leftTree->rightTree->leftTree->leftTree = heAddLeftTree(leftTree->rightTree->leftTree, 50);
	leftTree->rightTree->leftTree->rightTree = heAddRightTree(leftTree->rightTree->leftTree, 54);
	
	leftTree->rightTree->rightTree->leftTree = heAddLeftTree(leftTree->rightTree->rightTree, 57);
	leftTree->rightTree->rightTree->rightTree = heAddRightTree(leftTree->rightTree->rightTree, 60);
	
	
	rightTree->leftTree = heAddLeftTree(rootTree->rightTree, 189);
	rightTree->rightTree = heAddRightTree(rootTree->rightTree, 320);
	
	rightTree->leftTree->leftTree = heAddLeftTree(rightTree->leftTree, 100);
	rightTree->leftTree->rightTree = heAddRightTree(rightTree->leftTree, 200);
		
	rightTree->rightTree->leftTree = heAddLeftTree(rightTree->rightTree, 300);
	rightTree->rightTree->rightTree = heAddRightTree(rightTree->rightTree, 450);
	
	rightTree->leftTree->leftTree->leftTree = heAddLeftTree(rightTree->leftTree->leftTree, 90);
	rightTree->leftTree->leftTree->rightTree = heAddRightTree(rightTree->leftTree->leftTree, 120);
	
	rightTree->leftTree->rightTree->leftTree = heAddLeftTree(rightTree->leftTree->rightTree, 190);
	rightTree->leftTree->rightTree->rightTree = heAddRightTree(rightTree->leftTree->rightTree, 202);
		
	rightTree->rightTree->leftTree->leftTree = heAddLeftTree(rightTree->rightTree->leftTree, 290);
	rightTree->rightTree->leftTree->rightTree = heAddRightTree(rightTree->rightTree->leftTree, 310);
		
	rightTree->rightTree->rightTree->leftTree = heAddLeftTree(rightTree->rightTree->rightTree, 440);
	rightTree->rightTree->rightTree->rightTree = heAddRightTree(rightTree->rightTree->rightTree, 460);
			
	
		

	return rootTree;
	

}

/*
 学习各种遍历的方法关键是要知道特性有那些，他们所应用的场景有哪些。一定要举出应用场景，负责学算法就只是为了应试。
 
 后续遍历，要和逆波兰表达式联系在一起，他可以很方便的处理具有优先级关系的运算式样如 1+2*3，计算机在处理这个运算式时，前序遍历和中序遍历都会产生回溯
 **/


//前序遍历
void hePreOrderTraversal(HEBinTree *tree){
	
	if (tree==0) {
		return;
	}
	printf("%d\n",tree->value);
	hePreOrderTraversal(tree->leftTree);
	hePreOrderTraversal(tree->rightTree);
	
}

//中序遍历
void heMidOrderTraversal(HEBinTree *tree){
	if (tree==0) {
			return;
	}
	heMidOrderTraversal(tree->leftTree);
	printf("%d\n",tree->value);
	heMidOrderTraversal(tree->rightTree);
	
}
//后序遍历
void hePostOrderTraversal(HEBinTree *tree){
	if (tree==0) {
		return;
	}
	hePostOrderTraversal(tree->leftTree);
	hePostOrderTraversal(tree->rightTree);
	printf("%d\n",tree->value);
}

