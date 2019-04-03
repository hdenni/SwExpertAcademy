#include <iostream>

using namespace std;

int num_of_case = 0;
void queen(int* a, int k, int n);

int main() {
	int testcase;

	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++)
	{
		int q;
		num_of_case = 0;

		scanf("%d", &q);
		if (q == 1) num_of_case = 1;
		else if (q == 2) num_of_case = 0;
		else
		{
			int* chess = (int*)malloc(q * sizeof(int));
			for (int i = 0; i < q; i++)
				chess[i] = -1;
			queen(chess, 0, q);
			free(chess);
		}

		printf("#%d %d\n", t, num_of_case);

	}
	return 0;
}

void queen(int* a, int k, int n) 
{
	if (k == n)
	{
		num_of_case += 1;
		/*for (int i = 0; i < n; i++)
			printf("(%d,%d) ", i, a[i]);
		printf("\n");*/
		return;
	}
	// 위치찾기
	for (int j = 0; j < n; j++) {
		// j : k번째 행에서 j열에 체스를 놓을 경우
		if (k == 0)
		{
			a[k] = j;
			queen(a, k + 1, n);
		}
		int i;
		for (i = 0; i < k; i++) {
			// i번째 행에 a[i]열과 비교
			// -> 죽, 이전 줄의 queen과 비교

			// 해당 위치(j)에는 queen이 올 수 없음
			// 직선상에 위치한 경우 || /대각선 || \대각선
			if (a[i] == j || (i + a[i]) == (j + k) || (a[i] - i) == (j - k)) break;
		}
		// 이 위치는 ㅇㅋ
		//printf("(i, a[i]) : (%d, %d) || (k, j) : (%d, %d)\n", i, a[i], k, j);
		if (i == k && k!=0) {
			a[k] = j;
			queen(a, k + 1, n);
		}
	}

	// 못찾은 경우
	return;
}
