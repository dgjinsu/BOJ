#include <iostream>
#include <vector>
#include <deque>
#include <istream>
#include <algorithm>
#include <fstream>
#define endl '\n'
using namespace std;

int arr[51][51];
bool visit[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
deque<pair<int, int>> q;
int row;
int col;
int c;


void bfs(int x, int y) {
	q.push_back({ x,y });
	visit[x][y] = true;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int next_a = a + dx[i];
			int next_b = b + dy[i];
			if (next_a >= 0 && next_b >= 0 && next_a < row && next_b < col) {
				if (visit[next_a][next_b] == false && arr[next_a][next_b] == 1) {
					visit[next_a][next_b] = true;
					q.push_back({ next_a,next_b });
				}
			}
		}
	}
}

int main() {
	int t;
	cin >> t;

	for (int k = 0; k < t; k++) {
		cin >> col >> row >> c;
		int cnt = 0;
		for (int i = 0; i < c; i++) {
			int x;
			int y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arr[i][j] == 1 && visit[i][j] == false) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				arr[i][j] = 0;
				visit[i][j] = false;
			}
		}
	}

}