#include <iostream>
#include <set>
using namespace std;

const int MAXN = 1e5 + 10;

int main(){
    int n, k;
    int count = 0;
    cin >> n >> k;
    set<int> s;

    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        if(y == 0 || s.count(y)){
            s.insert(x);
            continue;
        }
        s.insert(x);
        count++;
    }
    
    cout << count << endl;
    return 0;
}
