# include <stdio.h>

int main(void) {
	int n = 0;

	while (1) {
		scanf("%d", &n);
		int sum = 0;
		int count = 0;

		if (n == -1)
			break;

		int m = 1;	// n�� ���
		// ���������� �ƴ��� �Ǵ�
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
		if (sum == n) {	// n�� �������� ���
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
		else {	// n�� �������� �ƴ� ���
			printf("%d is NOT perfect.\n", n);
		}

	}
	return 0;
}