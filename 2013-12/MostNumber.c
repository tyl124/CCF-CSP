#include <stdio.h>
int nums[10010] = {0}; 

int main(){
	int n, i, max_pos;

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		nums[temp]++;
	}
	int Max = nums[0];
	for(i = 1; i < 10010; i++){
		if(nums[i] > Max){
			Max = nums[i];
			max_pos = i;
		}
	}

	printf("%d", max_pos);

	return 0;
}
