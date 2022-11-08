#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int arr[1000001];


int main() {
	int n; 
	cin >> n;
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	int i = 4;
	while (i <= n) {
		arr[i] = arr[i - 1] + 1;
		
		if (i % 2 == 0) {
			arr[i] = min(arr[i / 2] + 1, arr[i]);
		}

		if (i % 3 == 0) {
			arr[i] = min(arr[i / 3] + 1, arr[i]);
		}
		
		i++;
	}

	cout << arr[n];

}