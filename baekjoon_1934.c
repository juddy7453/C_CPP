# include <stdio.h>
# include <stdlib.h>

int main(void) {
	int t;
	scanf("%d", &t);
	int ** arr = (int**)malloc(sizeof(int*) * t);
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
	while (j < 6000) {
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

	long long max;
	int p = 0;
	for (int k = 0; k < t; k++) {
		if (arr[k][0] == 1 || arr[k][1] == 1) // 둘 중 하나가 1일 경우
			printf("%d\n", arr[k][0] * arr[k][1]);
		else if (arr[k][0] % arr[k][1] == 0) // 둘 중 하나가 다른 하나의 배수일 경우
			printf("%d\n", arr[k][0]);
		else if (arr[k][1] % arr[k][0] == 0)
			printf("%d\n", arr[k][1]);
		else {
			max = 1;
			p = 0;
			while (prime[p] <= arr[k][0] || prime[p] <= arr[k][1]) {
				if (arr[k][0] % prime[p] == 0 && arr[k][1] % prime[p] == 0) {
					max *= prime[p];
					arr[k][0] /= prime[p];
					arr[k][1] /= prime[p];
				}
				else {
					p++;
				}
			}
			max *= arr[k][0] * arr[k][1];
			printf("%lld\n", max);
		}
	}
	
	return 0;
}