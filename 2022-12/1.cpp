#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

const int N = 50 + 10;

double a[N];

int main(){
    int n;
    double i;
    cin >> n >> i;

    for(int j = 0; j <= n; j++)
        cin >> a[j];

    double sum = a[0];
    for(int j = 1; j <=n; j++){
        a[j] = a[j] * pow(1+i, -j);
        sum += a[j];
    }
    cout << sum;
    return 0;
}
