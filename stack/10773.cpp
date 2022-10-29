#include <iostream>
#include <algorithm>
#define endl '\n'
#include <vector>

using namespace std;

int main() {
	int k;
	cin >> k;
	vector<int> v;
	vector<int> result;
	v.assign(k, 0);
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		v[i] = n;
	}
	int count = 0;
	for (int i = 0; i < k; i++) {
		if (v[i] != 0) {
			result.push_back(v[i]);
			count++;
		}
		else {
			result.pop_back();
			count--;
		}
	}
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += result[i];
	}
	cout << sum;
}