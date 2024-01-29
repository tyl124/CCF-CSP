#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


struct REPO{
	int number;
	long long *vector;
};

int main(){
	int n, m;
	cin >> n >> m;
	int *UpNum;		/* 记录上级仓库的编号 */
	UpNum = (int*)malloc(sizeof(int) * (n+1));
	for(int i = 1; i <=n ; i++){
		*(UpNum+i) = n+1; /* 初始化为n+1, 
							 这样保证最开始找到的任意一个上级仓库编号一定都小于n+1 */
	}
	struct REPO repos[1010];

	for(int i = 1; i <= n; i++){
		repos[i].number = i;
		repos[i].vector = (long long*)malloc(sizeof(long long) * m );
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++)
			cin >> *(repos[i].vector+j);
	}

	for(int i = 1; i <= n; i++){
		int TempUp = n+1;
		for(int j = 1; j <= n; j++){
		/* 遍历仓库i,j的每一个向量分量，如果发现有一个分量j大于i, 则终止这次比较i */
			if(i != j){
				int k = 0;
				while(k < m){
					if(*(repos[i].vector + k) >= *(repos[j].vector + k))
						break;	
					k++;
				}
				/* 比较完所有分量均满足i比j小, 并且此时的j比上一次获得的tempup还要小, 取更小者 */ 
				if(k == m && j < TempUp)
					TempUp = j;
			}
		}
	*(UpNum+i) = TempUp;
	}
	
	for(int i = 1; i <= n; i++){
		if(*(UpNum+i) == (n+1))
			*(UpNum+i) = 0;
		printf("%d\n", *(UpNum+i));
	}
	return 0;
}
