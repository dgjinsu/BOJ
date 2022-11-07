#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int arr[300];
int sum[300];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sum[0] = arr[0];
	sum[1] = arr[0] + arr[1];
	sum[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < n; i++) {
		sum[i] = max(sum[i - 2] + arr[i], sum[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << sum[n - 1];

}