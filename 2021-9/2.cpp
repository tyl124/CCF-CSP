/*
   实际是岛屿问题的变形: 海水逐渐下降，求露出最多的岛屿数量
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int N = 5e5 + 10, M = 1e4 + 10;
int a[N], b[N], cnt[N];
vector<int> v;
set<int> s;

int main(){
    int n;
    cin >> n;
    // 插入元素并去相邻的重复元素到vector<int> v 中
    v.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; ){
        int j = i;
        while(a[j] == a[i]) j++;
        v.push_back(a[i]);
        i = j;
    }
    v.push_back(0);     // 在第0个位置和第n+1个位置填入0
    
    // 记录高度为v[i]的山峰的贡献
    for(int i = 1; i <= v.size()-1; i++){
        int x = v[i-1], y = v[i], z = v[i+1];
        if(x < y && z < y) cnt[y]++;
        else if(x > y && z > y) cnt[y]--;
    }
    
    int res = 0, sum = 0;
    for(int i = M - 1; i > 0; i--){
        sum += cnt[i];
        res = max(res, sum);
    }
    cout << res << endl;
    return 0;
    
}
