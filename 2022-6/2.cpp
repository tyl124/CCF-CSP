#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

const int MAXN = 50 + 10;
int B[MAXN][MAXN];
int C[MAXN][MAXN];

int main(){
    bool flag = true;
    int n, l, s;
    cin >> n >> l >> s;
    vector<pair<int, int> > trees;
    set<pair<int, int> > uni_trees;
    
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        trees.push_back({x, y});
        uni_trees.insert({x, y});
    }
    for(int i = s; i >= 0; i--)
        for(int j = 0; j <= s; j++)
            cin >> B[i][j];
    /*
    cout << "B:" << endl;
    for(int i = 0; i <= s; i++){
        for(int j = 0; j <= s; j++)
            cout << B[i][j];
        cout << endl;
    }
    */
    int count = 0;
    for(int i = 0; i < n; i++){
        // 每次获取一棵树
        int x = trees[i].first;
        int y = trees[i].second;
        flag = true;

        // 要先判断一下这颗树 +s 后会不会越界，如果越界直接跳过此次循环
        if((x + s) > l || (y + s) > l)
            continue;

        // 以这颗树为起点构造 s+1 * s+1 的矩阵
        for(int j = 0; j <= s; j++){
            for(int k = 0; k <= s; k++){
                int cur_x = j + x;
                int cur_y = k + y;
                pair<int, int> target = {cur_x, cur_y};
                // 构造矩阵时考虑其他树的存在情况
                if(uni_trees.count(target))
                    C[j][k] = 1;
                else C[j][k] = 0;
            }
        }
        
        // 将B 与C比对
        for(int j = 0; j <= s; j++)
            for(int k = 0; k <= s; k++)
                if(C[j][k] != B[j][k]){
                    flag = false;
                    break;
                }

        if(flag == true)
            count++;
    }

    cout << count << endl;
    return 0;
}




            



            




