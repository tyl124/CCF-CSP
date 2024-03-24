#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int MAXN = 2e5 + 10;
int n, m, k;
int b[MAXN];

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int t, c;
        cin >> t >> c;
        int l = t - k - c + 1, r = t - k;
        if(r > 0)
            b[max(1, l)]++, b[r + 1]--;
    }
    for(int i = 1; i < MAXN; i++)
        b[i] += b[i-1];
    while(m--){
        int q;
        cin >> q;
        cout << b[q] << endl;
    }

    return 0;
}



/*
   70 分版本
vector<pair<int, int> > plan;
int n, m, k;

void question(int q){
    int count = 0;
    for(int i = 0; i < plan.size(); i++){
        pair<int, int> pp = plan[i];
        int start, end;
        start = q + k;
        end = q + k + pp.second;
        if(pp.first >= start && pp.first < end)
            count++;
    }
    cout << count << endl;
    return;
}


int main(){
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++){
        int t, c;
        cin >> t >> c;
        plan.push_back({t, c});
    }

    for(int i = 0; i < m; i++){
        int q;
        cin >> q;
        question(q);
    }
    return 0;
}
*/
