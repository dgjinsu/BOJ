#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
#define mod 15746

long long arr[1000001]{ 0, };



int main() {
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	int t;
	cin >> t;
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		for (int i = 6; i <= n; i++) {
			arr[i] = (arr[i - 5] + arr[i - 1]);
		}
		cout << arr[n] << endl;
	}

}