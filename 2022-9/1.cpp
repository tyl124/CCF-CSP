#include <iostream>
#include <vector>
using namespace std;

int a[25], b[25], c[25];
int ans[25];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    c[0] = 1;
    for(int i = 1; i <= n; i++)
        c[i] = c[i-1] * a[i];

    // 题目这么友好。。直接把答案都告诉你了
    int tmp_m = 0;
    for(int i = 1, j = 0; i <= n; i++, j++){
        b[i] = (m % c[i]) / c[j];
        m = m - c[j] * b[i];
    }
    for(int i = 1; i <= n; i++)
        cout << b[i] << ' ';

    return 0;
}




