///
/// @file    zuoP398.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-03-25 00:00:49
///

//以O(m^2)的复杂度遍历所有子矩阵可能的左右端点。对于每个遍历过程，将每一行的对应范围内的值相加得到一个数，
//所有行在左右范围内的值变为一个数组，求其最大连续子数组的和

#include <bits/stdc++.h>
using namespace std;

int main()
{
//技巧1，释放c++流的原始性能
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
//技巧2，减少corner case的处理负担
	vector<vector<int>> inp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> inp[i][j];
	}

//	预处理前缀和
		vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pre[i][j] = pre[i][j - 1] + inp[i][j];
		}
	}

	int res = INT_MIN;
	// 遍历所有可能的子矩阵左右端点，每次遍历根据预处理的前缀和求数组的最大连续子数组
	for (int l = 1; l <= m; l++) {
		for (int r = l; r <= m; r++) {
			// 求最大连续子数组
			int tmp = 0;
			for (int i = 1; i <= n; i++) {
				int now = pre[i][r] - pre[i][l - 1];
				if (tmp < 0) {
					tmp = now;
				} else {
					tmp += now;
				}
				res = max(res, tmp);
			}
		}
	}

	cout << res << endl;

	return 0;
}

