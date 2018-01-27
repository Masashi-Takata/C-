//整数a1,a2 ... anがある。そのなかからいくつか選び、その和をちょうどkにすることができるかを判定しなさい。
#include <stdio.h>

int dfs(int i, int sum);
void solve();

const int n = 4;
int a[n] = {1,2,4,7};
int k = 13;

int main(void) {
	solve();
	return 0;
}

int dfs(int i, int sum) {
	if(sum == k) return 1;
	if(sum < k) {
		if(i < n) {
			//いちどでも真なら１を返す。
                        //これはメモ再帰する必要はなさそうだ。
			if(dfs(i+1, sum+a[i])) return 1;
			if(dfs(i+1, sum)) return 1;
		}
	}

	return 0;
}

void solve() {
	if(dfs(0,0) == 1) {
		printf("SUCCESS\n");
	} else {
		printf("FAILURE\n");
	}
}
