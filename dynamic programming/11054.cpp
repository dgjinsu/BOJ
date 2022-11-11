#include <iostream>
#include <vector>
#include <istream>
#include <algorithm>
#include <fstream>
using namespace std;

int arr[1001];
int dp[1001][2];

int main() {
	int n;
	cin >> n;

	for (int i = 1;  i<= n; i++) {
		cin >> arr[i];
	}
	
	dp[1][0] = dp[n][1] = 1; // 커질때 합, 작아질떄 합
	for (int i = 2; i < n; i++) {
		int max = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[i] > arr[j]) {
				if (dp[j][0] > max) {
					max = dp[j][0];
				}
			}
		}
		dp[i][0] = max + 1;
	}
	for (int i = n-1; i >= 1; i--) {
		int max = 0;
		for (int j = i + 1; j <= n; j++) {
			if (arr[i] > arr[j]) {
				if (dp[j][1] > max) {
					max = dp[j][1];
				}
			}
		}
		dp[i][1] = max + 1;
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i][0] + dp[i][1] > max) {
			max = dp[i][0] + dp[i][1];
		}
	}
	cout << max - 1;

}