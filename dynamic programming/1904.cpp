#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
#define mod 15746

int arr[1000001]{ 0, };


int main() {
	int n;
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] % mod;
	}
	cout << arr[n];



}