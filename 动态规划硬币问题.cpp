/*
�����״̬;di[i]�����ֵi����Ҫ������Ӳ������
״̬ת�Ʒ���:
dp[0] = 0
dp[1] = 1 + dp[1-1] = 1
dp[2] = 1 + dp[2-1] = 2
dp[3]:
		1 + dp[3-1] = 3
		1 + dp[3-3] = 1
dp[i] = min{1 + dp[i-Vj]} i��ʾ��ֵ,Vj��ʾ��j��Ӳ�ҵ���� ����i >= Vj

*/
#include<iostream>

#ifdef DISABLE_MAIN
int main() {

	int v[] = { 1,3,5 };
	int v_len = sizeof(v) / sizeof(v[0]);
	int c = 11;
	int* dp = new int[c + 1]();
	for (int i = 1; i <= c; ++i) {
		dp[i] = i; //��ʾ��ʼȫ����һ��Ӳ�����
		for (int j = 0; j < v_len; j++) {
			if (i >= v[j] && 1 + dp[i - v[j]] < dp[i]) {
				dp[i] = 1 + dp[i - v[j]];
			}
		}
	}
	std::cout << dp[c] << std::endl;
	delete[]dp;
}
#endif