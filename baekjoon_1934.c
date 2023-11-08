# include <stdio.h>
# include <stdlib.h>

int main(void) {
	int t;
	scanf("%d", &t);
	int** arr = (int**)malloc(sizeof(int*) * t);
	for (int i = 0; i < t; i++)
		*(arr + i) = (int*)malloc(sizeof(int) * 2);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &(arr[i][0]), &(arr[i][1]));
	}

	// 소수 구하기
	int prime[6000] = { 0, };
	int num = 3;
	prime[0] = 2;
	int j = 1; int count = 1;
	while(j < 6000) {
		int ii = 0;
		while (ii <= j) {
			if (ii == j) {
				if (prime[ii] == 0) {
					prime[count++] = num;
					num++;
					j++;
					break;
				}
				if (num % prime[ii] != 0) {
					prime[count++] = num;
					num++;
					j++;
					break;
				}

			}
			else if (num % prime[ii] == 0) {
				num++;
				break;
			}
			else {
				ii++;
			}
		}
	}


	int r = 0; int q = 0; j = 0;
	for (int i = 0; i < t; i++) {
		if (arr[i][0] == 1 || arr[i][1] == 1) // 둘 중 하나가 1일 경우
			printf("%d\n", arr[i][0] * arr[i][1]);
		else if (arr[i][0] % arr[i][1] == 0) // 둘 중 하나가 다른 하나의 배수일 경우
			printf("%d\n", arr[i][0]);
		else if (arr[i][1] % arr[i][0] == 0)
			printf("%d\n", arr[i][1]);
		else {
			q = arr[i][0] * arr[i][1];
			while (prime[j] <= q) {
				if ((arr[i][0] % prime[j] == 0) && (arr[i][1] % prime[j] == 0)) {
					q /= prime[j];
					arr[i][0] /= prime[j];
					arr[i][1] /= prime[j];
					continue;
				}
				if (prime[j+1] < 45000)
					j++;
				else
					break;
				
			}
			printf("%d\n", q);
		}
		
	}

	return 0;
}