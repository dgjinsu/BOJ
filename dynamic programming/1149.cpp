#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int main() {
	int arr[1000][3];
	int cost[1000][3];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	cost[0][0] = arr[0][0];
	cost[0][1] = arr[0][1];
	cost[0][2] = arr[0][2];

	for (int i = 1; i < n; i++) {
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + arr[i][0];
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + arr[i][1];
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + arr[i][2];
	}

	cout << min(cost[n - 1][2], min(cost[n - 1][0], cost[n - 1][1]));
	
	
}