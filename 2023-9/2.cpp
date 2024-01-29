#include <iostream>
#include <cmath>
using namespace std;

struct OP{
	int type;
	double value;
};

struct OPsequence{
	int si;
	int sj;
	double x;
	double y;
};

int main(){
	int n, m;
	cin >> n >> m;
	// n 为操作个数，m为查询个数
	OP op[n+1];
	OPsequence opse[m];

	for(int i = 1; i <= n; i++){
		scanf("%d %lf", &op[i].type, &op[i].value);
	}

	for(int i = 0; i < m; i++){
		scanf("%d %d %lf %lf", &opse[i].si, &opse[i].sj, &opse[i].x, &opse[i].y);
		// 对这个输入的opse进行i -> j的操作

		int start = opse[i].si;
		int end = opse[i].sj;

		while(start <= end){
			int type = op[start].type;
			if(type == 1){
				opse[i].x *= op[start].value;
				opse[i].y *= op[start].value;
			}
			else if(type == 2){
				double new_x = opse[i].x * cos(op[start].value) - opse[i].y * sin(op[start].value);
                double new_y = opse[i].x * sin(op[start].value) + opse[i].y * cos(op[start].value);
                opse[i].x = new_x;
                opse[i].y = new_y;
			}
			start++;
		}
		printf("%f %f\n", opse[i].x, opse[i].y);
	}
	
	return 0;
}
