/*
https://bit.ly/2YWClEi
*/

#include <iostream>

using namespace std;

int map[9][9];
int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

int main() {
	int testcase;

	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++)
	{
		bool flg = false;
		for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) scanf("%d", &map[i][j]);

		for (int i = 0; i < 9; i++) {
			if (flg) break;
			bool checkA[10] = {}, checkB[10] = {};
			for (int j = 0; j < 9; j++) {
				if (checkA[map[i][j]] || checkB[map[j][i]]) { flg = true; break; }
				checkA[map[i][j]] = true; checkB[map[j][i]] = true;
			}
		}

		for (int i = 0; i < 9; i++) {
			bool check[10] = {};
			if (flg) break;
			int a = (i / 3) * 3 + 1, b = (i % 3) * 3 + 1;
			check[map[a][b]] = true;
			for (int j = 0; j < 8; j++) {
				int left = a + dir[j][0], right = b + dir[j][1];
				if (check[map[left][right]]) { flg = true; break; }
				check[map[left][right]] = true;
			}
		}
		if (flg) printf("#%d 0\n", t);
		else printf("#%d 1\n", t);		
	}
	return 0;
}
