/*
  https://bit.ly/34zTS8O
*/
#include <iostream>

using namespace std;
int map[50][3];

int draw(int i, int j, int k) {
	int n = i + j + k;
	int result = 0;
	int a;

	for (a = 0; a < i; a++)
		result += map[a][1] + map[a][2];
	for (a = i; a < i + j; a++)
		result += map[a][0] + map[a][2];
	for (a = i + j; a < i + j + k; a++)
		result += map[a][0] + map[a][1];

	return result;
}

int main() {
	int tc;

	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int result = 0;
		int x, y;

		cin >> y >> x;

		char temp[50];

		// 첫줄은 전부다 W, 마지막 줄은 전부다 R이어야 함
		cin >> temp;
		for (int j = 0; j < x; j++)
			if (temp[j] != 'W') result++;

		// 가운데는..그때그때 다르겠지 뭐..
		for (int i = 0; i < y - 2; i++) {
			cin >> temp;
			map[i][0] = 0;
			map[i][1] = 0;
			map[i][2] = 0;
			for (int j = 0; j < x; j++) {
				if (temp[j] == 'W') map[i][0]++;
				else if (temp[j] == 'B') map[i][1]++;
				else if (temp[j] == 'R') map[i][2]++;
			}
		}
		cin >> temp;
		for (int j = 0; j < x; j++)
			if (temp[j] != 'R') result++;


		// 여기서부터 고치시오 - 10.06
		int n = y - 2; // 채워야 하는 면적 줄 수
		int min = 2500;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (n - i - j < 1) break; // 한줄은 무조건 중간 색으로 채워져야 하니까

				int x;
				x = draw(i, n - i - j, j);
				//printf("x: %d\n", x);
				if (x < min) {
					//printf("%d %d %d %d %d\n", i, n - i - j, j, min, x);
					min = x;
				}
			}
		}

		cout << "#" << t << " " << min + result << endl;
	}
}
