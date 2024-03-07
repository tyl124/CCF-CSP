#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 1e4 + 10;

int T, n;

struct instruction{
    int sig; // 0代表R，1代表S
    int id;  // 这条指令要去处理的进程id
};

// 每一个Process[i]是一个vector，其中存储i这个进程所要执行的指令序列
vector<instruction> Process[MAXN];

void init(){
    for(int k  = 0; k < n; k++){
        string s;
        getline(cin, s);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'R' || s[i] == 'S'){
                instruction ins;
                if(s[i] == 'R') ins.sig = 0;
                else ins.sig = 1;
                i++;
                string pid = "";
                while(s[i] != ' ' && i < s.length()){
                    pid += s[i];
                    i++;
                } 
                // 执行完这个循环时,s[i] = ' '
                ins.id = stoi(pid);
                // 此时就应该是处理完了一条指令，那就把这条指令压入对应的进程里
                Process[k].push_back(ins);
            }
        }
    }

    return;
}

// 满分
bool isDead(){
    bool flag = true;
    while(flag){
        flag = false;
        for(int k = 0; k < n; k++){
            if(Process[k].empty()) continue;
            instruction ins = *Process[k].begin();
            int next_p = ins.id;
            if(Process[next_p].empty()){
                flag = false;
                break;
            }
            instruction next_ins = *Process[next_p].begin();
            if((ins.sig + next_ins.sig == 1) && (next_ins.id) == k){ 
                Process[k].erase(Process[k].begin());
                Process[next_p].erase(Process[next_p].begin());
                k--;
                flag = true;
            }
        }
    }
            
/*  40分
    for(int k = 0; k < n; k++){
        // 当前访问的这个进程的指令序列非空
        while(!Process[k].empty()){
            instruction ins = *Process[k].begin();
            // 查看这个指令序列的第一条指令要访问的进程指令序列是不是空
            int next_p = ins.id;
            if(Process[next_p].empty()) return false;       // 如果已空一定死锁
            instruction next_ins = *Process[next_p].begin();

            // S与R一定对称出现且相应的id应该相等
            if((ins.sig + next_ins.sig == 1) && (next_ins.id) == k){ 
                Process[k].erase(Process[k].begin());
                Process[next_p].erase(Process[next_p].begin());
                k = next_p
            }
            // 如果S/R没对称出现或者相应的id不等一定死锁
            else return false;
        }
    }
*/
    // 如果没有死锁，那么所有的进程的指令序列应该都为空
    for(int k = 0; k < n; k++)
        if(!Process[k].empty()) return false;
    return true;
}

int main(){
    cin >> T >> n;
    cin.ignore();
    bool res;
    
    while(T--){
        init();
        res = isDead();
        if(res == false) cout << 1 << endl;
        else cout << 0 << endl;
        for(int i = 0; i < n; i++)
            Process[i].clear();
    }

    return 0;
}



