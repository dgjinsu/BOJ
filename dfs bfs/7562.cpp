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

bool visit[301][301];
int result[301][301];
deque<pair<int, int>> q;
int dx[8] = { -2, -2, -1,-1,1,1,2,2 };
int dy[8] = { -1, 1, -2,2,2,-2,1,-1 };
int n;
int s_x, s_y;
int e_x, e_y;

void reset() {
	while (!q.empty()) q.pop_back();
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++)
		{
			visit[i][j] = false;
			result[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {
	q.push_back({ x,y });
	visit[x][y] = true;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		if (a == e_x && b == e_y) {
			break;
		}
		q.pop_front();
		for (int i = 0; i < 8; i++) {
			int next_a = a + dx[i];
			int next_b = b + dy[i];
			if (next_a >= 0 && next_b >= 0 && next_a < n && next_b < n) {
				if (visit[next_a][next_b] == false) {
					q.push_back({ next_a, next_b });
					visit[next_a][next_b] = true;
					result[next_a][next_b] = result[a][b] + 1;
				}
			}
		}
	}
}

int main() {
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> s_x >> s_y;
		cin >> e_x >> e_y;
		bfs(s_x, s_y);
		cout << result[e_x][e_y] << endl;
		reset();
	}

}