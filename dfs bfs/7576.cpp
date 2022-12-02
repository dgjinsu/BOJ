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
int row, col, x, y;


int arr[1001][1001];
deque<pair<int, int>> q;
bool visit[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int day = 0;
int result[1001][1001];

void bfs() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 1) q.push_back({ i,j });
		}
	}
	q.push_back({ x,y });
	visit[x][y] = true;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int n_a = a + dx[i];
			int n_b = b + dy[i];
			if (n_a >= 0 && n_b >= 0 && n_a < row && n_b < col) {
				if (arr[n_a][n_b] == 0 && visit[n_a][n_b] == false) {
					visit[n_a][n_b] = true;
					q.push_back({ n_a,n_b });
					result[n_a][n_b] = result[a][b] + 1;
				}
			}
		}
		
	}
}

int main() {
	cin >> col >> row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				x = i;
				y = j;
			}
		}
	}
	bfs();
	int max_day = 0;
	bool check = false;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (max_day < result[i][j]) max_day = result[i][j];
			if (arr[i][j] == 0 && result[i][j] == 0) check = true;
		}
	}
	if (check) cout << "-1";
	else cout << max_day;


}