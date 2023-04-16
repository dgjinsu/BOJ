#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <deque>
#include <istream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <string>
#define endl '\n'
using namespace std;
ifstream fin;
ofstream fout;

int arr[102];
bool visit[102];
int result[102];
deque<int> q;

void bfs(int x) {
	q.push_back(x);
	visit[x] = true;
	while (!q.empty()) {
		int a = q.front();
		q.pop_front();
		for (int i = 0; i <= 6; i++) {
			int next_a = a + i;
			if (next_a > 100) continue;
			next_a = arr[next_a];
			if (visit[next_a] == false) {
				q.push_back(next_a);
				visit[next_a] = true;
				result[next_a] = result[a] + 1;
			}
		}
	}
}

int main() {
	for (int i = 1; i < 101; i++) {
		arr[i] = i;
	}
	int n; int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; int y;
		cin >> x >> y;
		arr[x] = y;
	}
	for (int i = 0; i < m; i++) {
		int x; int y;
		cin >> x >> y;
		arr[x] = y;
	}
	bfs(1);
	cout << result[100];

}