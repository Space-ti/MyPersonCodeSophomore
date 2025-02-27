#ifdef DISABLE_MAIN
#include<iostream>
using namespace std;

/*
�����㷨��O(n^2)
LIS���⣺�����е���ǽ������������г���
5 3 4 1 8 7 9
״̬��dp[i] �Ե�i��Ԫ�ؽ�β�ķǽ������еĳ���
״̬ת�Ʒ��̣�
dp[0] = 1
dp[1] = max{1,1 + dp[0]} ���� ar[0] <= ar[1] = 1

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