#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
	int q;
	cin >> q;
	LL res, n;
	int k;
	for(int i = 0; i < q; i++){
		res = 1;
		n = 0;
		k = 0;
		cin >> n >> k;
		for(int j = 2; j <= n/j; j++){
			// 为什么此处可以直接 j++? 
			// 因为j在运行中，一定是质数
			// 假如j此时加到4，那么j一定是从2加过来，但是在2的时候，一定被除到不能再除
			// 所以此时j一定不等于4
			int coef = 0;
			while(n % j == 0){
				n /= j;
				coef++;
			}
			if(coef >= k) res *= pow(j, coef);
		}
		cout << res << endl;
	}
	return 0;
}
