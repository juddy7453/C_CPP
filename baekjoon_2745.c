# include <stdio.h>
# include <string.h>
# include <math.h>

int main(void) {
	char n[30]; // 10���� 2�������� ��Ÿ���� 2^29 + @ => �ִ� 30�ڸ�.
	int b;
	int sum = 0;
	int total_sum = 0;
	int c = 0;

	scanf("%s %d", n, &b);

	// �ƽ�Ű �ڵ�
	// 0 => 48
	// 9 => 57
	// A => 65
	// Z => 90

	int l = strlen(n);

	if (b <= 10) {
		for (int i = 0; i < l; i++) {
			c = n[l - 1 - i]; // c�� n[l - 1 - i]�� �ƽ�Ű �ڵ� ��ȯ�� ��.
			sum = pow(b, i) * (c - 48);
			total_sum += sum;
		}

		printf("%d\n", total_sum);
		return 0;
	}

	else { // 11 < b <= 36
		for (int i = 0; i < l; i++) {
			c = n[l - 1 - i]; // c�� n[l - 1 - i]�� �ƽ�Ű �ڵ� ��ȯ�� ��.

			if (c >= 48 && c <= 57) { // n[l - 1 - i]�� 0 ~ 9 �� ���
				sum = pow(b, i) * (c - 48);
				total_sum += sum;
			}
			else if (c >= 65 && c <= 90) { // n[l - 1 - i]�� A ~ Z �� ���
				sum = pow(b, i) * (c - 55);
				total_sum += sum;
			}
		}

		printf("%d\n", total_sum);
		return 0;
	}


	return 0;
}