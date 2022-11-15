#include <iostream>
#include <vector>
#include <istream>
#include <algorithm>
#include <fstream>
#define endl '\n'
using namespace std;
int main() {

	int k, n;
	cin >> k >> n;
	int arr[10000];


	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	long long right = *max_element(arr, arr + k);
	long long left = 1;

	int number = 1;
	long long result = 0;

	while (left<=right) {
		//if (left >= right) break;
		long long value = (left + right) / 2;
		int answer = 0;
		int index = 0;
		while (index < k) {
			answer += arr[index] / value;
			index++;
		}
		if (answer >= n) {
			left = value + 1;
			result = max(result, value);
		}
		else {
			right = value -1;
		}
	}
	cout << result;
	

}