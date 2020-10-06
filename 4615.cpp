/* 
  https://bit.ly/3nokXon
*/

#include <iostream>

using namespace std;

int dir[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1},{0,1}, {1,-1}, {1,0}, {1,1} };
// y좌표 x좌표
int over(int x, int y, int n) {
	if (x < 0 || y < 0 || x >= n || y >= n) return 1;
	else return 0;
}

int main() {
	int tc;

	cin >> tc;
	
	for (int t = 1; t <= tc; t++) {
		int maze[8][8];
		int n, m;

		cin >> n >> m;
		// n: 보드의 길이, m: 돌 놓는 횟수

		// 보드판 세팅
		/* 0 0 0 0
		   0 2 1 0
		   0 1 2 0 
		   0 0 0 0 */
		for (int i = 0; i < n/2 - 1; i++) {
			for (int j = 0; j < n; j++) {
				maze[i][j] = 0;
				maze[n - i - 1][j] = 0;
			}
		}
		for (int i = n / 2 - 1; i < n / 2 + 1; i++) {
			for (int j = 0; j < n / 2 - 1; j++) {
				maze[i][j] = 0;
				maze[i][n - 1 - j] = 0;
			}
			maze[n / 2 - 1][n / 2 - 1] = 2;
			maze[n / 2][n / 2] = 2;
			maze[n / 2 - 1][n / 2] = 1;
			maze[n / 2][n / 2 - 1] = 1;
			
		}

		/*
		// 출력 테스트
		for (int a = 0; a < n; a++) {
			for (int bb = 0; bb < n; bb++) {
				cout << maze[a][bb];
			}
			cout << endl;
		}*/

		for (int i = 0; i < m; i++) {
			int x, y, c;
			cin >> x >> y >> c;

			maze[--y][--x] = c; // 배열 index에 맞춰서 하나씩 뺌

			int flag = 0;
			// 뒤집기
			for (int d = 0; d < 8; d++) {
				// 초기화 주의
				int nx = x, ny = y;
				flag = 0;
				while (1) {
					ny += dir[d][0];
					nx += dir[d][1];
					if (nx == 1 && ny == 3) {
						int asdfge;
					}
					if (over(nx, ny, n)) break; // 범위 넘어감
					if (maze[ny][nx] == 0) break; // 뒤집을게 없어요
					if (maze[ny][nx] == c) {
						// 이제 걸어온만큼 뒤집어줘야함
						for (int f = 1; f <= flag; f++) {
							maze[ny + f * (-1 * dir[d][0])][nx + f * (-1 * dir[d][1])] = c;
						}
						flag = 0;
						break; // 다뒤집었으니 돌아와라
					}
					else {
						flag++;
						// 뒤집을게 몇개나 있는지
						// 여기는 진짜 방금 놓은 돌이랑 색 반전됐을 때만 들어옴(당연하지만..)
					}
				// 방향따라 쭉 가보다 나랑 같은 색이 나와야 함
				// 그럼 그 걸어온 길만큼을 다 뒤집어주면됨
				}
			}

		}
		int b = 0, w = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// maze에 0이 포함되었을 수도 있으니 주의
				if (maze[i][j] == 1) b++;
				else if (maze[i][j] == 2) w++;
			}
		}

		cout << "#" << t << " " << b << " " << w << endl;
	}

	
}
