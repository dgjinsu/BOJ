#include <iostream>
#include <vector>
#include <deque>
#include <istream>
#include <algorithm>
#include <fstream>
#define endl '\n'
using namespace std;
int n; int m;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };
char map[1001][1001];
int visit[1001][1001][2];
deque<pair<pair<int, int>, int>> q;

void bfs() {
	visit[0][0][0] = 1;
	q.push_back({ { 0,0 }, 0 }); //�̹� ������ 3��° ���ڿ� 1 / ���� �ʾ����� 0
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int isBreak = q.front().second;
		if (x == n - 1 && y == m - 1) {
			cout << visit[x][y][isBreak];
			return;
		}
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m) {
				if(map[next_x][next_y] == '1' && isBreak == 0) { //���� �����ְ� �� ���� ���ٸ�
					visit[next_x][next_y][isBreak + 1] = visit[x][y][isBreak] + 1;
					q.push_back({ {next_x, next_y}, isBreak + 1 });
				}
				else if (map[next_x][next_y] == '0' && visit[next_x][next_y][isBreak] == 0) { //���� �ƴѰ�����
					visit[next_x][next_y][isBreak] = visit[x][y][isBreak] + 1;
					q.push_back({ {next_x, next_y}, isBreak });
				}
			}
		}
	}
	cout << "-1";
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			map[i][j] = temp[j];
		}
	}
	bfs();
}