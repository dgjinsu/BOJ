#include <iostream>
#include <vector>
#include <deque>
#include <istream>
#include <algorithm>
#include <fstream>
#define endl '\n'
using namespace std;
vector<vector<int>> v(100000);
bool visit[100002];
vector<int> result;
int number = 0;

void bfs(int x) {
	deque<int> q;
	q.push_back(x);
	visit[x] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop_front();
		result[cur] = ++number;
		for (int i = 0; i < v[cur].size(); i++) {
			if (visit[v[cur][i]] == false) {
				visit[v[cur][i]] = true;
				q.push_back(v[cur][i]);
			}
		}
	}
}


int main() {

	int a, b, start, q, w;
	cin >> a >> b >> start;
	result.assign(a + 1, 0);
	for (int i = 0; i < b; i++) {
		cin >> q >> w;
		v[q].push_back(w);
		v[w].push_back(q);
	}

	for (int i = 1; i <= a; i++) {
		sort(v[i].begin(), v[i].end());
	}

	bfs(start);

	for (int i = 1; i < result.size(); i++) {
		cout << result[i] << endl;
	}


}