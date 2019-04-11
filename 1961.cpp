/*
https://bit.ly/2Gacdgv
*/
#include <iostream>

using namespace std;

int main() {
	
	int testcase;
	int map[8][8];
	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);

		printf("#%d\n", t);
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) printf("%d", map[j][i]);
			printf(" ");
			for (int j = n - 1; j >= 0; j--) printf("%d", map[n - 1 - i][j]);
			printf(" ");
			for (int j = 0; j < n; j++) printf("%d", map[j][n - 1 - i]);
			printf("\n");
		}
	}
	return 0;
}
