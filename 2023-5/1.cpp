#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
// n的规模小于等于100，所以准备数组大小为110
	int n;
	int count;
	string chess[110];
	
	cin >> n;
	for(int i = 1; i <= n; i++){
	// 每8行的字符串对应于一个局面，为了便于处理，使用string将其加和，获得一个64的字符串
		for(int j = 1; j <= 8; j++){
			string temp;
			cin >> temp;
			chess[i] = chess[i] + temp;
		}
	// 对于每一个获得的字符串，将该字符串与前面存储的字符串(局面)进行比较
		count = 1;
		for(int k = 1; k < i; k++){
			if(chess[k] == chess[i]) count++;
		}
	// 输出重复局面次数
		cout << count <<endl;
	}

	return 0;
}
