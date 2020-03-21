#include <stdio.h>

int len = 20;
int data[20] = {0,12,21,34,45,56,67,70,81,91,101,112,123,135,146,150,163,173,180,191};
/*
二分查找
*/

int binarySearch(int a){
	
	int begin = 0;
	int end = len-1;
	int mid = (end - begin)/2;
	while (begin <= end) {
		
		mid   =  (end + begin)/2;
		if (a > data[mid]) {
			begin = mid+1;
		}else {
			end  = mid-1;
		}
		
	}
	if (a == data[mid]) {
		return mid;
	}
	return -1;
}

int main(int argc, char *argv[]) {
	
	int index = binarySearch(46);
	if (index != -1) {
		printf("找到了:%d\n",index);
	}else{
		printf("没有找到!\n");
	}
	
}