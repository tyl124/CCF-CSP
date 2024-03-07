#include <iostream>
#include <vector>
using namespace std;

int n, x, res = 1e9;
int a[35];
vector<int> ans, temp;

void dfs(int i, int currentSum){
    if(i == n) return;
    if(currentSum >= x){
        if(currentSum < res){
            res = currentSum;
            ans = temp;
        }
        return;
    }
    temp.push_back(i);
    dfs(i+1, currentSum + a[i]);
    temp.pop_back();
    dfs(i+1, currentSum);
}


int main(){
    cin >> n >> x;
    for(int i = 0 ; i < n; i++)
        cin >> a[i];

    dfs(0, 0);
    int resSum = 0;
    for(int i = 0; i < ans.size(); i++)
        resSum += a[ans[i]];
    cout << resSum << endl;

    return 0;
}

