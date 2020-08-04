/*
    1953. [모의 SW 역량테스트] 탈주범 검거
*/

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_N 50

using namespace std;
int maze[MAX_N][MAX_N];
int visit[MAX_N][MAX_N];
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
// 상 하 좌 우

int check_lim(int x, int y, int n, int m) { return (x < 0 || y < 0 || x == n || y == m) ? 1 : 0; }
void reset(int (*ary)[MAX_N][MAX_N]) { for (int i = 0; i < MAX_N; i++) for (int j = 0; j < MAX_N; j++) (*ary)[i][j] = 0; }

// 1일 경우 갈 수 있음
int check_route(int after, int d) {
	if (d == 0) {
		if (after == 2 || after == 5 || after == 6) return 1;
	}
	else if (d == 1) {
		if (after == 2 || after == 4 || after == 7) return 1;
	}
	else if (d == 2) {
		if (after == 3 || after == 4 || after == 5) return 1;
	}
	else if (d == 3) {
		if (after == 3 || after == 6 || after == 7) return 1;
	}
	return 0;
		
}
/* 
터널 구조물
1: 상 하 좌 우 0 1 2 3

2: 상 하	   0 1

3: 좌 우		   2 3

4: 상 우       0     3

5: 하 우         1   3

6: 하 좌         1 2

7: 상 좌       0   2
*/
int solve(int n, int m, int x, int y, int time) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	if (time == 1) return 1;
	if (time == 0) return 0;
	for (int t = 0; t < time; t++) { // time 횟수만큼 움직일 수 있음
		int stack = q.size();

		for (int s = 0; s < stack; s++) {
			x = q.front().first;
			y = q.front().second;
			q.pop();

			if (visit[x][y]) continue; // 이미 방문했던 곳임
			visit[x][y] = 1; // 도착했음

			// 0  1  2  3
			// 상 하 좌 우
			for (int d = 0; d < 4; d++) { // 각 방향에 대해 
				if		(maze[x][y] == 2) { if (d == 2 || d == 3) continue; }
				else if (maze[x][y] == 3) { if (d == 0 || d == 1) continue; }
				else if (maze[x][y] == 4) { if (d == 1 || d == 2) continue;	}
				else if (maze[x][y] == 5) { if (d == 0 || d == 2) continue; }
				else if (maze[x][y] == 6) {	if (d == 0 || d == 3) continue;	}
				else if (maze[x][y] == 7) { if (d == 1 || d == 3) continue;	}
				// 1일 경우에는 무조건 pass

				int i = x + dir[d][0];
				int j = y + dir[d][1];

				if (check_lim(i, j, n, m)==1 || maze[i][j]==0 || visit[i][j]==1) continue;
				// 어차피 못가는곳임

				// 파이프 경로 열려있는지 확인
				if (maze[i][j] != 1 && !check_route(maze[i][j], d)) continue;
				q.push(make_pair(i, j));
			}
		}
	}
	
	int score = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (visit[i][j]) score++;
	
	return score;
}
int main() {
	int T;

	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++) {
		// 지하 터널의 세로크기 N
		// 가로크기 M
		// 맨홀 뚜껑이 위치한 장소의 세로위치 R, 가로위치 C
		// 탈출 후 소요된 시간 L
		int n, m, start_x, start_y, time;

		cin >> n >> m >> start_x >> start_y >> time;
		reset(&visit);
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				cin >> maze[i][j];

		cout << "#" << testcase << " " << solve(n, m, start_x, start_y, time) << endl;
	}
	return 0;

}
