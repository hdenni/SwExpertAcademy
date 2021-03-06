/*
https://bit.ly/2I0MNWh
*/

#include <iostream>
#include <string.h>
using namespace std;

#define MAX 300

int map[MAX][MAX];
bool visit[MAX][MAX];

int dir[8][2] = { {-1,-1}, {0,-1}, {1,-1}, {-1,0}, {1,0}, {-1,1}, {0,1}, {1,1} };


void popping(int i, int j, int size) {
	visit[i][j] = true;
	for (int k = 0; k < 8; k++) {
		int left = i + dir[k][0], right = j + dir[k][1];
		if (left < size && left >= 0 && right < size && right >= 0 && map[left][right] != -1)
		{
			if (map[left][right] == 0 && !visit[left][right]) popping(left, right, size);
			visit[left][right] = true;
		}
	}
}

int main() {
	int testcase;

	scanf("%d", &testcase);
	getchar();

	for (int t = 1; t <= testcase; t++)
	{
		int pop = 0, nomine = 0;
		int size;

		scanf("%d", &size);
		
		getchar();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				char c;
				c = getchar();
				if (c == '.') {
					map[i][j] = 0; nomine++;
				}
				else if (c == '*') map[i][j] = -1;
			}
			getchar();
		}
		
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++) {
				// Reset array visit
				visit[i][j] = false;

				// If it is mine, skip
				if (map[i][j] == -1) {
					// If is mine, set visit true
					visit[i][j] = true;
					continue;
				}

				// set the map
				for (int k = 0; k < 8; k++) {
					int left = i + dir[k][0], right = j + dir[k][1];
					if (left < size && left >= 0 && right < size && right >= 0 && map[left][right] == -1)
						map[i][j]++;
				}
				/*
				if (i - 1 >= 0 && j - 1 >= 0 && map[i - 1][j - 1] == -1) map[i][j]++;
				if (i - 1 >= 0 && map[i - 1][j] == -1) map[i][j]++;
				if (i - 1 >= 0 && j + 1 < size && map[i - 1][j + 1] == -1) map[i][j]++;
				
				if (j - 1 >= 0 && map[i][j - 1] == -1) map[i][j]++;
				if (j + 1 < size && map[i][j + 1] == -1) map[i][j]++;
				
				if (i + 1 < size && j - 1 >= 0 && map[i + 1][j - 1] == -1) map[i][j]++;
				if (i + 1 < size && map[i + 1][j] == -1) map[i][j]++;
				if (i + 1 < size && j + 1 < size && map[i + 1][j + 1] == -1) map[i][j]++;
				*/
			}
		}
		
		/*
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		*/
		
		pop = 0;
		// find zero
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (map[i][j] == 0 && !visit[i][j]) {
					pop++;
					popping(i, j, size);
				}
			}
		}
		// find else
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (!visit[i][j]) pop++;
			}
		}
	
		printf("#%d %d\n", t, pop);

	}
	return 0;
}
