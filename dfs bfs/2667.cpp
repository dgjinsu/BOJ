#include <iostream>
#include <vector>
#include <deque>
#include <istream>
#include <algorithm>
#include <fstream>
#define endl '\n'
using namespace std;

string arr[26];
bool visit[26][26];
deque<pair<int, int>> q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n;
int cnt = 0;
vector<int> result;

void bfs(int x, int y) {
	visit[x][y] = true;
	q.push_back({ x,y });
	cnt++;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int next_x = a + dx[i];
			int next_y = b + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n) {
				if (visit[next_x][next_y] == false && arr[next_x][next_y] == '1') {
					q.push_back({ next_x, next_y });
					visit[next_x][next_y] = true;
					cnt++;
				}
			}
		}
		

	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false && arr[i][j] == '1') {
				cnt = 0;
				bfs(i, j);
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}