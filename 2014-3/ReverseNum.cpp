#include <stdio.h>
#define N 510
#define M 1010
using namespace std;
int a[N], cnt[M];

//时间复杂度O(n), 空间复杂度O(m)
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	// 判断当前相反数是否在序列中出现过
	int ans = 0;
	for(int i = 0; i <= n; i++)
		if(a[i] >= 0) cnt[a[i]]++;
	for(int i = 0; i <= n; i++)
		if(a[i] < 0)
			ans += cnt[-a[i]];
	printf("%d", ans);

	return 0;
}
