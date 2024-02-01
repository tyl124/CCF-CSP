#include <iostream>
#include <cstdio>

using namespace std;

int get_area(int x1, int y1, int x2, int y2, int a, int b){
    int area = 0;

    /*
       思路是将不重叠的部分直接砍掉, 即当有需要改变(x1, y1), (x2, y2)
       时, 直接简化坐标
    */
    if(x1 >= a || x2 <= 0 || y1 >= b || y2 <= 0)
        return 0;
    if(x1 <= 0)
        x1 = 0;
    if(y2 >= b)
        y2 = b;
    if(x2 >= a)
        x2 = a;
    if(y1 <= 0)
        y1 = 0;
    area = (x2 - x1) * (y2 - y1);
    return area;
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    int sum = 0;
    int x1, y1, x2, y2;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int area= get_area(x1, y1, x2, y2, a, b);
        sum += area;
    }
    cout << sum << endl;

    return 0;
}
