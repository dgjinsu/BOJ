#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> m;
	vector<int> result;
	vector<string> out;

	vector<int> example;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		example.push_back(temp);
	}
	int index = 0;
	int push_number = 1;
	while (1) {
		while (push_number <= example[index]) {
			m.push_back(push_number);
			push_number++;
			out.push_back("+");
		}
		result.push_back(m.back());
		m.pop_back();
		out.push_back("-");

		index++;
		if (result.size() == n) break;
	}
	if (example == result) {
		for (int i = 0; i < out.size(); i++) {
			cout << out[i] << endl;
		}
	}
	else {
		cout << "NO";
	}
}
