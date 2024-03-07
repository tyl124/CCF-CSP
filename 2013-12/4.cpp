#include <iostream>
using namespace std;

const int N = 1010, MOD = 1e9 + 7;

typedef long long LL;

int n;
int C[N][N];

int main(){
    cin >> n;
    // 组合数计算公式： C(i, j)
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(!j) C[i][j] = 1;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }

    // 经典计数问题求解思路
    int res = 0;
    for(int k = 2; k <= n-2; k++)
        res = (res + ((LL)C[n-1][k] * (k - 1)) % MOD * (n - k - 1)) % MOD; 
    cout << res << endl;

    return 0;
}

