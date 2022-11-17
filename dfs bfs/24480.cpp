#include <iostream>
#include <vector>
#include <deque>
#include <istream>
#include <algorithm>
#include <fstream>
#define endl '\n'
using namespace std;
vector<vector<int>> v(100002);
bool visit[100002];
int number = 0;
vector<int> result_dfs;
void dfs(int x) {
	visit[x] = true;
	result_dfs[x] = ++number;

	for (int i = 0; i < v[x].size(); i++) {
		if (visit[v[x][i]] == false) {
			dfs(v[x][i]);
		}
	}
}

int main() {
	int a, b, start, q, w;
	cin >> a >> b >> start;
	result_dfs.assign(a+1, 0);
	for (int i = 0; i < b; i++) {
		cin >> q >> w;
		v[q].push_back(w);
		v[w].push_back(q);
	}
	for (int i = 1; i <= a; i++) {
		sort(v[i].begin(), v[i].end(), greater<>());
	}

	dfs(start);
	
	for (int i = 1; i < result_dfs.size(); i++) {
		cout << result_dfs[i] << endl;
	}
}