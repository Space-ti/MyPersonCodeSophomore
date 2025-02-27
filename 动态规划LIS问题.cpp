#ifdef DISABLE_MAIN
#include<iostream>
using namespace std;

/*
遍历算法：O(n^2)
LIS问题：求序列的最长非降（升序）子序列长度
5 3 4 1 8 7 9
状态：dp[i] 以第i个元素结尾的非降子序列的长度
状态转移方程：
dp[0] = 1
dp[1] = max{1,1 + dp[0]} 条件 ar[0] <= ar[1] = 1

*/
int main() {
	int ar[] = { 5, 3 ,4, 1, 8, 7, 9 };
	const int n = sizeof(ar) / sizeof(ar[0]);
	int dp[n] = { 0 };
	
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (ar[i] >= ar[j] and 1 + dp[j] > dp[i]) {
				dp[i] = 1 + dp[j];
			}
		}

		if (dp[i] > ans) ans = dp[i];
	}
	cout << ans << endl;
	return 0;
}
#endif