#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int arr[500][500];
int sum[500][500];
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> arr[i][j];
		}
	}
	sum[0][0] = 7;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) {
				sum[i][j] = sum[i - 1][j] + arr[i][j];
			}
			else if (j > 0 && j<i) {
				sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + arr[i][j];
			}
			else if (j == i) {
				sum[i][j] = sum[i-1][j - 1] + arr[i][j];
			}
		}
	}
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (sum[n - 1][i] > max) max = sum[n - 1][i];
	}
	cout << max;

}