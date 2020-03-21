#include <stdio.h>

typedef struct BinTree BinTree;

struct BinTree{
	int value;
	BinTree *leftTree;
	BinTree *rightTree;
};

/*
																-78-
											
								-44-				   										 			-209-								
				    -30-	 					  -55-								   -189-						   -320-
			28				38				52				58		 			100				200				300				450
		12	   29 		35   	40		50		54		57		60			90		 120	190		202		 290	310		 440	460
*/

BinTree *addLeftTree(BinTree *tree,int value){
	
	if (tree == 0) {
		return 0;
	}
	
	BinTree *leftTree = (BinTree *)malloc(sizeof(BinTree));
	leftTree->value = value;
	tree->leftTree = leftTree;
	return leftTree;
	

}

BinTree *addRightTree(BinTree *tree,int value){
	if (tree == 0) {
		return 0;
	}
	BinTree *rightTree = (BinTree *)malloc(sizeof(BinTree));
	rightTree->value = value;
	tree->rightTree = rightTree;
	return rightTree;
}

BinTree *demoBinTree(){
	
	
	BinTree *rootTree = (BinTree *)malloc(sizeof(BinTree));
	rootTree->value = 78;
	BinTree *leftTree = addLeftTree(rootTree, 44);
	rootTree->leftTree = leftTree;
	BinTree *rightTree = addRightTree(rootTree, 209);
	rootTree->rightTree = rightTree;
	
	leftTree->leftTree = addLeftTree(rootTree->leftTree, 30);
	leftTree->rightTree = addRightTree(rootTree->leftTree, 55);
	
	leftTree->leftTree->leftTree = addLeftTree(leftTree->leftTree, 28);
	leftTree->leftTree->rightTree = addRightTree(leftTree->leftTree, 38);
		
	leftTree->rightTree->leftTree = addLeftTree(leftTree->rightTree, 52);
	leftTree->rightTree->rightTree = addRightTree(leftTree->rightTree, 58);
	
	leftTree->leftTree->leftTree->leftTree = addLeftTree(leftTree->leftTree->leftTree, 12);
	leftTree->leftTree->leftTree->rightTree = addRightTree(leftTree->leftTree->leftTree, 29);
	
	leftTree->leftTree->rightTree->leftTree = addLeftTree(leftTree->leftTree->rightTree, 35);
	leftTree->leftTree->rightTree->rightTree = addRightTree(leftTree->leftTree->rightTree, 40);
	
	leftTree->rightTree->leftTree->leftTree = addLeftTree(leftTree->rightTree->leftTree, 50);
	leftTree->rightTree->leftTree->rightTree = addRightTree(leftTree->rightTree->leftTree, 54);
	
	leftTree->rightTree->rightTree->leftTree = addLeftTree(leftTree->rightTree->rightTree, 57);
	leftTree->rightTree->rightTree->rightTree = addRightTree(leftTree->rightTree->rightTree, 60);
	
	
	
	
	
	
	rightTree->leftTree = addLeftTree(rootTree->rightTree, 189);
	rightTree->rightTree = addRightTree(rootTree->rightTree, 320);
	
	rightTree->leftTree->leftTree = addLeftTree(rightTree->leftTree, 100);
	rightTree->leftTree->rightTree = addRightTree(rightTree->leftTree, 200);
		
	rightTree->rightTree->leftTree = addLeftTree(rightTree->rightTree, 300);
	rightTree->rightTree->rightTree = addRightTree(rightTree->rightTree, 450);
	
	rightTree->leftTree->leftTree->leftTree = addLeftTree(rightTree->leftTree->leftTree, 90);
	rightTree->leftTree->leftTree->rightTree = addRightTree(rightTree->leftTree->leftTree, 120);
	
	rightTree->leftTree->rightTree->leftTree = addLeftTree(rightTree->leftTree->rightTree, 190);
	rightTree->leftTree->rightTree->rightTree = addRightTree(rightTree->leftTree->rightTree, 202);
		
	rightTree->rightTree->leftTree->leftTree = addLeftTree(rightTree->rightTree->leftTree, 290);
	rightTree->rightTree->leftTree->rightTree = addRightTree(rightTree->rightTree->leftTree, 310);
		
	rightTree->rightTree->rightTree->leftTree = addLeftTree(rightTree->rightTree->rightTree, 440);
	rightTree->rightTree->rightTree->rightTree = addRightTree(rightTree->rightTree->rightTree, 460);
			
	
		

	return rootTree;
	

}


void preOrderTraversal(BinTree *tree){
	
	if (tree==0) {
		return;
	}
	printf("%d\n",tree->value);
	preOrderTraversal(tree->leftTree);
	preOrderTraversal(tree->rightTree);
	
}

void midOrderTraversal(BinTree *tree){
	if (tree==0) {
			return;
	}
	midOrderTraversal(tree->leftTree);
	printf("%d\n",tree->value);
	midOrderTraversal(tree->rightTree);
	
}

void postOrderTraversal(BinTree *tree){
	if (tree==0) {
		return;
	}
	postOrderTraversal(tree->leftTree);
	postOrderTraversal(tree->rightTree);
	printf("%d\n",tree->value);
}



int main(int argc, char *argv[]) {
	
	BinTree *tree = demoBinTree();
	preOrderTraversal(tree);
}