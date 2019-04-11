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
	}
	return 0;
}