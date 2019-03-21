#include <iostream>
using namespace std;

/*
input :
number of test
number(array 크기, number*number)

output:
ex) number=3
1 2 3
8 9 4
7 6 5
*/

int main()
{
	int testcase;

	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++)
	{
		int** ary;
		int num, i, j;

		scanf("%d", &num);
		printf("#%d\n", t);
		ary = (int**)malloc(num * sizeof(int*));
		for (int m = 0; m < num; m++) {
			*(ary + m) = (int*)malloc(num * sizeof(int));
		}

		int cnt = 1;
    if (num == 1){
      printf("1\n");
      continue;
    }
		else if (num == 2) {
			for (int k = 0;; k++) {
				for (i = k, j = k; j < num - k; j++)
					ary[i][j] = cnt++;
				for (++i, --j; i < num - k; i++)
					ary[i][j] = cnt++;
				for (--i, --j; j >= k; j--)
					ary[i][j] = cnt++;
				for (--i, ++j; i >= k + 1; i--)
					ary[i][j] = cnt++;

				if (k == num - 2) break;
			}
		}
    // num > 2
		else {
			for (int k = 0; k < num - 2; k++) {
				for (i = k, j = k; j < num - k; j++)
					ary[i][j] = cnt++;
				for (++i, --j; i < num - k; i++)
					ary[i][j] = cnt++;
				for (--i, --j; j >= k; j--)
					ary[i][j] = cnt++;
				for (--i, ++j; i >= k + 1; i--)
					ary[i][j] = cnt++;

			}
			if (num == 3) ary[i + 1][j + 1] = cnt;
		}

	
		for (int m = 0; m < num; m++)
		{
			for (int n = 0; n < num; n++)
				printf("%d ", ary[m][n]);
			printf("\n");
		}
		
	}

	return 0;

}
