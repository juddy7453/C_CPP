# include <stdio.h>

int main(void) {
	int n = 0;

	while (1) {
		scanf("%d", &n);
		int sum = 0;
		int count = 0;

		if (n == -1)
			break;

		int m = 1;	// n의 약수
		// 완전수인지 아닌지 판단
		for (int i = 1; i <= n; i++) {
			if (n % i == 0) {
				if (n == i)
					break;
				else {
					sum += i;
					count ++;
				}
			}
		}
		if (sum == n) {	// n이 완전수인 경우
			printf("%d = ", n);

			for (int i = 1; i < n; i++) {
				if (n % i == 0) {
					printf("%d", i);
					count--;
					if (count == 0) {
						printf("\n");
						break;
					}
					else {
						printf(" + ");
					}
				}

			}
		}
		else {	// n이 완전수가 아닌 경우
			printf("%d is NOT perfect.\n", n);
		}

	}
	return 0;
}