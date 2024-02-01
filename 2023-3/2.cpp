#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int t[N], c[N];
int n, k;
long long m;

bool check(int mid){
    long long cost = 0;
    for(int i = 0; i < n; i++){
        if(t[i] > mid)
            cost += (long long)(t[i] - mid) * c[i];
    }
    return cost <= m;
}

int main(){
    
    scanf("%d%d%d", &n, &m ,&k);
    
    for(int i = 0; i < n; i++)
       scanf("%d %d", &t[i], &c[i]);
    
    int l = k, r = 1e5;
    while(l < r){
        int mid;
        mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else l = mid+1;
    }
    cout << l << endl;
    
    return 0;
}
