#include <iostream>
#include <vector>
#include <deque>
#include <istream>
#include <algorithm>
#include <fstream>
#define endl '\n'
using namespace std;

int n; int m;
int cnt = 0;
int arr[101][101];
bool visit[101][101];
int result[101][101];
deque<pair<int, int>> q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int x, int y) {
	visit[x][y] = true;
	q.push_back({ x,y });
	result[x][y]++;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {

			int next_a = a + dx[i];
			int next_b = b + dy[i];

			if (next_a >= 0 && next_b >= 0 && next_a < n && next_b < m) {
				if (arr[next_a][next_b] == '1' && visit[next_a][next_b] == false) {
					visit[next_a][next_b] = true;
					q.push_back({ next_a, next_b });
					result[next_a][next_b] = result[a][b] + 1;
				}
			}
		}
	}

}

int main() {
	string temp;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j];
		}
	}

	bfs(0, 0);
	cout << result[n-1][m-1];



}