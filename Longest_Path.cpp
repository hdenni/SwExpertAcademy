/*
https://bit.ly/2UhV3HR
*/

#include <iostream>
#include <string.h>
using namespace std;

#define NSize 10

int node;
bool g[NSize][NSize];

void longest_path(bool*, int, int*, int);

int main() {
	int testcase;

	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++)
	{
		int edge;	
		scanf("%d %d", &node, &edge);

		// Set graph
		for (int i = 0; i < NSize; i++)
			memset(g[i], false, NSize * sizeof(bool));

		for (int i = 0; i < edge; i++){
			int a, b;
			scanf("%d %d", &a, &b);

			g[a-1][b-1] = true;
			g[b-1][a-1] = true;
		}		
		/* 입력 끝 */

		bool route[NSize];
		int now = 1;

		// 노드별로 각각 경로 탐색
		for (int i = 0; i < node; i++) {
			memset(route, false, NSize * sizeof(bool));
			if (now == node) break;
			longest_path(route, i, &now, 0);
		}
		printf("#%d %d\n", t, now);
		
	}
	return 0;
}

void longest_path(bool* route, int p, int* now, int ing) {
	if (*now == node)
		return;

	// 현위치정보 set
	route[p] = true;
	ing++;

	int i;
	// find next
	for (i = 0; i < node; i++) {
		// check edge
		if (!g[p][i]) continue;

		// already visit i
		if (route[i]) continue;

		// go to next
		longest_path(route, i, now, ing);
	}
	
	route[p] = false;
	*now = (*now > ing) ? *now : ing;
}
