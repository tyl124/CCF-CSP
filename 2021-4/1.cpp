#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 500 + 10;
int n, m, L;
int LL[MAXN];

int main(){
    scanf("%d%d%d", &n, &m, &L);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            int pix;
            cin >> pix;
            LL[pix]++;
        }
    for(int i = 0; i < L; i++)
        cout << LL[i] << ' ';
    return 0;
}
