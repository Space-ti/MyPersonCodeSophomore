#include<iostream>
#ifdef DISABLE_MAIN
using namespace std;
/*
״̬��
	dp[i]����i��λԪ�ؽ�β���ֶκ͵�ֵ
״̬ת�Ʒ��̣�
	dp[0] = val < 0 ? 0: val;
	dp[1] = ar[1] + dp[0] < 0 ? 0 : ar[1] + dp[0];
	......

*/
int main() {
	int ar[] = { -2, 11, -4, 13 ,-5,-2 };
	const int n = sizeof(ar)/sizeof(ar[0]);
	int dp[n] = { 0 };
	dp[0] = ar[0] < 0 ? 0 : ar[0];

	int ans = 0;

	for (int i = 0; i < n; i++) {
		dp[i] = ar[i] + dp[i - 1] < 0 ? 0 : ar[i] + dp[i - 1];
		if (dp[i] > ans)ans = dp[i];
	}

	cout << ans << endl;
}
#endif