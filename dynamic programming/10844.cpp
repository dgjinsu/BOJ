#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;


int main() {
	int n; 
	cin >> n;
	int dp[10][101];
	dp[0][0] = 0;
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[3][0] = 1;
	dp[4][0] = 1;
	dp[5][0] = 1;
	dp[6][0] = 1;
	dp[7][0] = 1;
	dp[8][0] = 1;
	dp[9][0] = 1;
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[j][i] = dp[j + 1][i - 1];
			}
			else if (j == 9) {
				dp[j][i] = dp[j - 1][i - 1];
			}
			else {
				dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1];
			}
			dp[j][i] %= 1000000000;
		}

	}
	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum+ dp[i][n-1]) % 1000000000;
	}
	cout << sum;
}