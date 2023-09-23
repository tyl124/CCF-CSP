#include <stdio.h>
#define N 20
using namespace std;
struct window{
	int x1, y1, x2, y2;
}w[N];
int rank[N]; // 表示窗口等级

bool check(int x, int l, int r){
	return (x>=l) && (x<=r);
}

void ask(int n, int tim, int x, int y){
	// 对于每一次点击，扫描所有窗口，记录最顶层的窗口下标
	int t = 0;
	for(int i = 1; i <= n; i++)
		if(check(x, w[i].x1, w[i].x2) &&
			check(y, w[i].y1, w[i].y2) && rank[i] > rank[t])
			t = i;
	if(!t)
		puts("IGNORED");
	else{
		//将每次点击的窗口的等级设置为最大
		rank[t] = tim;
		printf("%d\n", t);
	}
}

int main(){
	int n, m, x, y;
	scanf("%d %d", &n, &m);
	//读入窗口坐标，并给每个窗口设置等级，越靠上的等级越高
	for(int i = 1; i <= n; i++){
		scanf("%d %d %d %d", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2);
		rank[i] = i;
	}
	//模拟m次点击操作
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &x, &y);
		ask(n, n+i, x, y);
	}

	return 0;
}







[]
