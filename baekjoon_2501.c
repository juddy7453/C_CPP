# include <stdio.h>

int main(void) {
	int n = 1;
	int k = 1;

	scanf("%d %d", &n, &k);

	int i = 0;	// n�� ���

	while (k > 0) {
		if (i == n) {
			printf("%d\n", 0);
			return 0;
		}

		if (n % (i + 1) == 0) {
			k--;	// i+1�� n�� n-k ��°�� ���� ���
		}
		i++;

	}

	
	printf("%d\n", i);

	return 0;
	
}