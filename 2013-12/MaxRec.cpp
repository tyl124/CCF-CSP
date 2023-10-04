#include <iostream>
using namespace std;

int rec_height[1010];

int main(){
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> rec_height[i];

	int max_area = 0, temp_area = 0;
	for(int i = 1; i <= n; i++){
		int min_height = rec_height[i];
		for(int j = i+1; j <= n; j++){
			if(rec_height[j] < min_height)
				min_height = rec_height[j];
			temp_area = (j - i + 1) * min_height;
			if(temp_area > max_area)
				max_area = temp_area;
		}
	}

	cout << max_area << endl;

	return 0;
}
