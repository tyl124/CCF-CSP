#include <stdio.h>
#include <iostream>
using namespace std;

int Q[10010][22], KT[22][10010], V[10010][22];
int W[10010];
long long int temp[10010];

// 100分版本，优化主要在空间复杂度上
int main(){
	int n, d;
	cin >> n >> d;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= d; j++)
			cin >> Q[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= d; j++)
			cin >> KT[j][i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= d; j++)
			cin >> V[i][j];
	for(int i = 1; i <= n; i++)
		cin >> W[i];
	
// 优化思想：
// 1.将暂存的 temp 二维数组改写成一维数组
// 2.取消大量的暂存结果，从某一行(列)入手，获得结果时后直接输出
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			temp[j] = 0;
			for(int k = 1; k <= d; k++)
			// 计算第一步：Q x KT
				temp[j] += Q[i][k] * KT[k][j];
			// 计算第二步：对该行，直接用W对应行的数字相乘
			temp[j] = W[i] * temp[j];
		}

		for(int j = 1; j <= d; j++){
			long long int temp2 = 0;
			// 计算第三步：计算最后的(W*(QxKT)) x V
			for(int k = 1; k <= n; k++)
				temp2 += temp[k] * V[k][j];
			if(j == 1)
				cout << temp2;
			else
				cout << " " << temp2;
		}
		cout << endl;
	}
	return 0;
}
