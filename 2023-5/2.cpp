#include <stdio.h>
#include <iostream>
using namespace std;

int Q[10010][20], KT[20][10010], V[10010][20];
int W[10010];
long long int temp[10010][10010], temp2[10010][20];

int main(){
	int n, d;
	cin >> n >> d;

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

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			temp[i][j] = 0;
			for(int k = 1; k <= d; k++)
				temp[i][j] += Q[i][k] * KT[k][j];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			temp[i][j] = temp[i][j] * W[i];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= d; j++){
			temp2[i][j] = 0;
			for(int k = 1; k <= n; k++)
				temp2[i][j] += temp[i][k] * V[k][j];
		}
	}

	for(int i = 1; i <= n; i++){
		cout << temp2[i][1];
		for(int j = 2; j <= d; j++)
			cout <<" "<< temp2[i][j];
		cout << endl;
	}
	
	return 0;
}





