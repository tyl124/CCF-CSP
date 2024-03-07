#include <iostream>
using namespace std;

const int N = 55;

char g[N][N];

// 上下左右四个方向
int xd[4] = {-1, 1, 0, 0};
int yd[4] = {0, 0, -1, 1};

// 用两个数组来进行标记
// 分别从源点出发和目点出发能够到达哪些点
bool fs[N][N];
bool ft[N][N];


bool check(int x, int y, int i){
    // 这三类点可以向任何方向行走
    if(g[x][y] == '+' || g[x][y] == 'S' || g[x][y] == 'T') return true;
    if(g[x][y] == '-' && (i == 2 || i == 3)) return true;   // 左右
    if(g[x][y] == '|' && (i == 0 || i == 1)) return true;   // 上下
    if(g[x][y] == '.' && i == 1) return true;   // 下
    return false;
}

// 从源点(x,y)出发查看能走到哪些点
void dfs1(int x, int y){
    // 首先(x, y)标记
    fs[x][y] = true;
    // 查看四个方向
    for(int i = 0; i < 4; i++){
        int nx = x + xd[i], ny = y + yd[i];
        // check(x, y, i): 检查在这个点，是否可以向i表示的方向走
        // !fs[nx][ny]: 下一个点没有被访问过
        // g[nx][ny] 不是#
        if(check(x, y, i) && !fs[nx][ny] && g[nx][ny] != '#'){
            dfs1(nx, ny);
        }
    }
    return;
}

void dfs2(int x, int y){
    ft[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + xd[i], ny = y + yd[i];
        // 由于我的上下左右数组的设置，此处可以通过与1按位异或来得到相反的方向
        int k = i ^ 1;
        // 此处稍微考虑一下，对于当前这个点(x, y)
        // 我们实际上考虑的是(x, y)相邻的4个点能否到达(x, y)
        // 所以当i = 0, 表示的是向上走可以走到(nx, ny)
        // 那么对于(nx, ny)来说就是向下走才可以走到(x, y)
        if(check(nx, ny, k) && !ft[nx][ny])
            dfs2(nx, ny);
    }
    return;
}



int main(){
    int R, C;
    int s_x, s_y, e_x, e_y;
    cin >> R >> C;
    // 初始化整张图都不可联通
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            g[i][j] = '#';
    // 输入数据
    for(int i = 1; i <= R; i++)
        for(int j = 1;  j <= C; j++){
            cin >> g[i][j];
            if(g[i][j] == 'S'){
                s_x = i;
                s_y = j;
            }
            if(g[i][j] == 'T'){
                e_x = i;
                e_y = j;
            }
        }

    dfs1(s_x, s_y);

    if(fs[e_x][e_y] == false){
        cout << "I'm stuck!" << endl;
        return 0;
    }

    // 从目点出发查看哪些点能够到达目点
    dfs2(e_x, e_y);

    int count = 0;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            // 在从源点出发的点里被标记为真 -- 能够从源点出发到达
            // 在从目点出发的点里标记为假 -- 从这些点不能走到目点
            if(fs[i][j] == true && ft[i][j] == false)
                count++;
        }
    }

    cout << count << endl;
    return 0;
}









