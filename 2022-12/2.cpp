#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 500;

int main(){
    int n, m;
    cin >> n >> m;
    int depend[N], takes[N];
    int early[N] = {0};
    int late[N] = {0};
    bool flag = true;

    // depend[i] = 0 表示没有前置依赖
    for(int i = 1; i <= m; i++)
        cin >> depend[i];
    for(int i = 1; i <= m; i++)
        cin >> takes[i];

    // 计算最早开始时间
    for(int i = 1; i <= m; i++){
        if(depend[i] == 0)
            early[i] = 1;
        else{
            int day = depend[i];
            while(day != 0){
                early[i] += takes[day];
                day = depend[day];
            }
            early[i]++;
        }
    }

    // 计算最晚开始时间
    for(int i = 1; i <= m; i++)
        late[i] = n - takes[i] + 1;

    // 判断是否需要输出最晚开始时间
    for(int i = 1; i <= m; i++)
        if((early[i] + takes[i] - 1) > n){
            flag = false;
            break;
        }

    for(int i = 1; i <= m; i++){
        cout << early[i] << ' ';
    }

    if(flag == true){
        cout << endl;
        for(int i = 1; i <= m; i++)
             cout << late[i] << ' ';
    }

    return 0;
}



    
