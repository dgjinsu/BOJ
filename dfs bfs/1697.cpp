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
int dx[] = { -1,1,2 };
int result[100001];
bool visit[100001];
deque<int> q;
int n;
int k;

void bfs(int x) {
	visit[x] = true;
	q.push_back(x);
	while (!q.empty()) {
		int a = q.front();
		if (a == k) break;
		q.pop_front();
		for (int i = 0; i < 3; i++) {
			int next_a;
			if (i == 2) {
				next_a = a * dx[i];
			}
			else {
				next_a = a + dx[i];
			}
			if (next_a >= 0 && next_a < 100001 && visit[next_a] == false) {
				q.push_back(next_a);
				visit[next_a] = true;
				result[next_a] = result[a] + 1;
			}
		}
	}
	
}

int main() {

	cin >> n >> k;
	bfs(n);
	cout << result[k];


}