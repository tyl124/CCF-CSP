#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> a;
    for(int i = 0; i < n; i++){
        double tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    double avg = 0, da = 0;
    for(int i = 0; i < n; i++)
        avg += a[i];
    avg /= n;
    for(int i = 0; i < n; i++){
        da += (a[i] - avg) * (a[i] - avg);
    }
    da /= n;
    
    for(int i = 0; i < n; i++){
        double fa = 0;
        fa = (a[i] - avg) / sqrt(da);
        cout << fa << endl;
    }
    return 0;
}
    
