#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {

	deque<int> router;
	int n;
	cin >> n;
	while (1) {
		int number;
		cin >> number;
		if (number == -1) break;

		if (number != 0 && n < 1) continue;

		if (number == 0) {
			router.pop_front();
			n++;
		}
		else if (number > 0) {
			router.push_back(number);
			n--;
		}
	}
	if (router.size() == 0) cout << "empty";
	for (int i = 0; i < router.size(); i++) {
		cout << router[i] << " ";
	}

}