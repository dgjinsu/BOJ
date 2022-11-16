#include <iostream>
#include <vector>
#include <deque>
#include <istream>
#include <algorithm>
#include <fstream>
#define endl '\n'
using namespace std;
vector<vector<int>> v(10000);
bool visit[10002];
bool visit_[10002];
vector<int> result_dfs;
vector<int> result_bfs;


void dfs(int x) {
	visit[x] = true;
	result_dfs.push_back(x);
	for (int i = 0; i < v[x].size(); i++) {
		if (visit[v[x][i]] == false) {
			dfs(v[x][i]);
		}
	}

}

void bfs(int x) {
	deque<int> q;
	q.push_back(x);
	visit_[x] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop_front();
		result_bfs.push_back(cur);
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visit_[next] == false) {
				q.push_back(next);
				visit_[next] = true;
			}
		}
	}
}

int main() {
	
	int n, m, start;
	int a, b;

	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= m; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(start);
	bfs(start);

	for (int i = 0; i < result_dfs.size(); i++) {
		cout << result_dfs[i] << " ";
	}	
	cout << endl;
	for (int i = 0; i < result_bfs.size(); i++) {
		cout << result_bfs[i] << " ";
	}
	
}