#include<iostream>
#include<string>
using namespace std;

/*
LCS:求两个序列的最长公共子序列长度 子串（连续的）
helloworld
hlweord

X: X1,X2...Xn
Y: Y1,Y2...Ym
如果Xn = Ym
LCS(X[1...n],Y[1...m]) = LCS(X[1...n-1],Y[1...m-1]) +1
如果Xn != Ym
LCS(X[1...n],Y[1...m]) = max{LCS(X[1...n],Y[1...m-1]),LCS(X[1...n-1],Y[1...m])}

 状态：给定两个序列的LCS的长度
 dp[n][m]:n表示第一个串的长度 m表示第二个串的长度，n行m列元素的值，记录的就是这两个串的LCS长度

*/

string str1 = "helloworld";
string str2 = "hlweord";
int** dp = nullptr;
int** path = nullptr;
int cnt1 = 0;
int cnt2 = 0;

//纯粹递归  分治算法：628次
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
		return dp[n][m]; //查表 ，查询子问题是否被求解过
	}
	cnt2++;
	if (X[n] == Y[m]) {
		dp[n][m] = LCS02(X,n-1,Y,m-1) + 1;
		path[n][m] = 1; //1表示向对角线缩减
		return dp[n][m];
	}
	else {
		int len1 = LCS02(X, n, Y, m - 1);
		int len2 = LCS02(X, n - 1, Y, m);
		if (len1 >= len2) {
			dp[n][m] = len1;
			path[n][m] = 2; //2表示向左缩减
		}
		else {
			dp[n][m] = len2;
			path[n][m] = 3; //3表示向上缩减
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
		cout << str1[n]; //回溯后打印
	}
	else if(path[n][m] == 2) {
		BackStrace(str1, n, m - 1);//向左
	}
	else {
		BackStrace(str1, n - 1, m);//向上
	}
		
}
int main() {
	// dp是一个n行m列的二维数组
	int n = str1.size();
	int m = str2.size();

	dp = new int* [n]; //n行
	for (int i = 0; i < n; ++i) {
		dp[i] = new int[m]; //m列
		
	}

	path = new int* [n]; // n行
	for (int i = 0; i < n; ++i) {
		path[i] = new int[m]; //m列
		for (int j = 0; j < m; ++j) {
			path[i][j] = 0;
		}
	}


	int size1 = LCS01(str1, n - 1, str2, m - 1);
	cout << "分治算法求解：" << size1 << " 递归次数：" << cnt1 << endl;
	int size2 = LCS02(str1, n - 1, str2, m - 1);
	cout << "分治算法求解：" << size2 << " 递归次数：" << cnt2 << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}

	BackStrace(str1,n-1,m-1);
}