#include<iostream>
#include<string>
using namespace std;

/*
LCS:���������е�����������г��� �Ӵ��������ģ�
helloworld
hlweord

X: X1,X2...Xn
Y: Y1,Y2...Ym
���Xn = Ym
LCS(X[1...n],Y[1...m]) = LCS(X[1...n-1],Y[1...m-1]) +1
���Xn != Ym
LCS(X[1...n],Y[1...m]) = max{LCS(X[1...n],Y[1...m-1]),LCS(X[1...n-1],Y[1...m])}

 ״̬�������������е�LCS�ĳ���
 dp[n][m]:n��ʾ��һ�����ĳ��� m��ʾ�ڶ������ĳ��ȣ�n��m��Ԫ�ص�ֵ����¼�ľ�������������LCS����

*/

string str1 = "helloworld";
string str2 = "hlweord";
int** dp = nullptr;
int** path = nullptr;
int cnt1 = 0;
int cnt2 = 0;

//����ݹ�  �����㷨��628��
int LCS01(string X, int n, string Y, int m) {
	if (n < 0 || m < 0) {
		return 0;
	}
	cnt1++;
	if (X[n] == Y[m]) {
		return LCS01(X, n - 1, Y, m - 1) + 1;
	}
	else {
		int len1 = LCS01(X, n, Y, m - 1);
		int len2 = LCS01(X, n - 1, Y, m);
		return std::max(len1, len2);
	}
}

int LCS02(string X, int n, string Y, int m) {
	if (n < 0 || m < 0) {
		return 0;
	}
	if (dp[n][m] >= 0) {
		return dp[n][m]; //��� ����ѯ�������Ƿ�����
	}
	cnt2++;
	if (X[n] == Y[m]) {
		dp[n][m] = LCS02(X,n-1,Y,m-1) + 1;
		path[n][m] = 1; //1��ʾ��Խ�������
		return dp[n][m];
	}
	else {
		int len1 = LCS02(X, n, Y, m - 1);
		int len2 = LCS02(X, n - 1, Y, m);
		if (len1 >= len2) {
			dp[n][m] = len1;
			path[n][m] = 2; //2��ʾ��������
		}
		else {
			dp[n][m] = len2;
			path[n][m] = 3; //3��ʾ��������
		}
		return dp[n][m];
	}
}

void BackStrace(string str1,int n,int m) {
	if (n < 0 || m < 0) {
		return;
	}
	if (path[n][m] == 1) {
		BackStrace(str1, n - 1, m - 1);
		cout << str1[n]; //���ݺ��ӡ
	}
	else if(path[n][m] == 2) {
		BackStrace(str1, n, m - 1);//����
	}
	else {
		BackStrace(str1, n - 1, m);//����
	}
		
}
int main() {
	// dp��һ��n��m�еĶ�ά����
	int n = str1.size();
	int m = str2.size();

	dp = new int* [n]; //n��
	for (int i = 0; i < n; ++i) {
		dp[i] = new int[m]; //m��
		
	}

	path = new int* [n]; // n��
	for (int i = 0; i < n; ++i) {
		path[i] = new int[m]; //m��
		for (int j = 0; j < m; ++j) {
			path[i][j] = 0;
		}
	}


	int size1 = LCS01(str1, n - 1, str2, m - 1);
	cout << "�����㷨��⣺" << size1 << " �ݹ������" << cnt1 << endl;
	int size2 = LCS02(str1, n - 1, str2, m - 1);
	cout << "�����㷨��⣺" << size2 << " �ݹ������" << cnt2 << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}

	BackStrace(str1,n-1,m-1);
}