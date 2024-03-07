#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int maxA[N], minA[N], B[N];


int main(){
    cin >> n;
    cin >> B[0];
    minA[0] = maxA[0] = B[0];
    for(int i = 1; i < n; i++){
        cin >> B[i];
        if(B[i] > B[i-1]){
            minA[i] = maxA[i] = B[i];
        }
        else if(B[i] = B[i-1]){
            maxA[i] = B[i];
            minA[i] = 0;
        }
    }
    
    int max_res = 0, min_res = 0;
    for(int i = 0; i < n; i++){
        max_res += maxA[i];
        min_res += minA[i];
    }
    cout << max_res << endl << min_res << endl;

    return 0;
}


