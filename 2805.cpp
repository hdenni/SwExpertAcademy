/*
https://bit.ly/2YQ3itn
*/

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int testcase;

	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++)
	{
		int s;
		int** f;

		scanf("%d", &s);
		if (s == 1) {
			int r;
			scanf("%d", &r);
			printf("#%d %d\n", t, r);
			continue;
		}
		f = (int**)malloc(s * sizeof(int*));
		for (int i = 0; i < s; i++)
			f[i] = (int*)malloc(s * sizeof(int));
		
		for (int i = 0; i < s; i++)
			for (int j = 0; j < s; j++)
				scanf("%1d", &f[i][j]);

		
		/*이제입력끝남 미쳤나*/

		int now = 0;
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				int scale;
				int after = 0;
				
				scale = min(min(i, j), min(abs(s-1 - i), abs(s-1 - j)));
				after += f[i][j];

				if (scale==1) 
					after += f[i][j - 1] + f[i][j + 1] + f[i - 1][j] + f[i + 1][j];
				else if (scale > 1) 
				{
					for (int ii = 0; ii < s; ii++) {
						for (int jj = 0; jj < s; jj++) {
							if (i == ii && j == jj) continue;
							int check = abs(ii - i) + abs(jj - j);
							if (check <= scale) after += f[ii][jj];
						}
					}
				}

				// 큰 값으로 저장
				now = (after > now) ? after : now;
			}
		}
		printf("#%d %d\n", t, now);

		for (int i = 0; i < s; i++)
			free(f[i]);
		free(f);
	}
}
