#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = 1;

	for (int i = 2; i <= n; i++) {

		dp[i] = 1;

		int max = 0;
		int max_index = 0;

		for (int j = i - 1; j >= 1; j--) {
			if (arr[i] > arr[j]) {
				if (dp[j] > max) {
					max = dp[j];
					max_index = j;
				}
			}
		}
		if (arr[i] > arr[max_index]) {
			dp[i] = dp[max_index] + 1;
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > answer) answer = dp[i];
	}
	cout << answer;
}