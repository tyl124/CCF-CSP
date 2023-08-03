#include <stdio.h>
#include <iostream>
using namespace std;

int Q[10010][20], KT[20][10010], V[10010][20];
int W[10010];
long long int temp[10010][10010], temp2[10010][20];

// 70分版本
int main(){
	int n, d;
	cin >> n >> d;

// 读入一系列的数据(矩阵)进行存储
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= d; j++)
			cin>>Q[i][j];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= d; j++)
			cin>>KT[j][i];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= d; j++)
			cin>>V[i][j];
	
	for(int i = 1; i <= n; i++)
		cin>>W[i];

// 计算第一步：Q x KT
// 需要说明的是，这是矩阵计算相乘的板子，需要熟练应用
	for(int i = 1; i <= n; i++){          // 第一个矩阵的行
		for(int j = 1; j <= n; j++){      // 第二个矩阵的列
			temp[i][j] = 0;
			// 第一个矩阵的列(同时也是第二个矩阵的行)	
			for(int k = 1; k <= d; k++)   
				temp[i][j] += Q[i][k] * KT[k][j];
		}
	}

// 计算第二步：W * (QxKT)
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			temp[i][j] = temp[i][j] * W[i];
	}

// 计算第三步：(W*(QxKT)) x V
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= d; j++){
			temp2[i][j] = 0;
			for(int k = 1; k <= n; k++)
				temp2[i][j] += temp[i][k] * V[k][j];
		}
	}

// 格式化输出，注意空格与元素的格式
	for(int i = 1; i <= n; i++){
		cout << temp2[i][1];
		for(int j = 2; j <= d; j++)
			cout <<" "<< temp2[i][j];
		cout << endl;
	}
	
	return 0;
}





