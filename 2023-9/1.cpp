#include <iostream>
using namespace std;

struct OP{
	int dx;
	int dy;
};

int main(){
	int n, m;
	// n 个操作， m 个需要操作的坐标
	cin >> n >> m;
	OP op[n];
	for(int i = 0; i < n; i++)
		cin >> op[i].dx >> op[i].dy;
	int x, y;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		for(int j = 0; j < n; j++){
			x += op[j].dx;
			y += op[j].dy;
		}
		cout << x << ' ' << y << endl;
	}
	 return 0;
}
