# include <stdio.h>

int main(void) {
	int x;

	scanf("%d", &x);

	int n = 0;
	int m = 0;
	int i = 0;
	int count = 1;

	if (x == 1) {
		printf("1/1\n");
		return 0;
	}

	while (x > 1) {
		if (i % 2 == 0) { // ������ �̵�
			m++;
			count++;
			if (count == x) {
				printf("%d", n+1);
				printf("/");
				printf("%d\n", m+1);
				break;
			}
			if (n == 0) {
				i++;
				for (int j = 0; j < i; j++) {
					n++;
					m--;
					count++;
					if (count == x) {
						printf("%d", n+1);
						printf("/");
						printf("%d\n", m+1);
						break;
					}
				}
			}
		}
		else { // �Ʒ��� �̵�
			n++;
			count++;
			if (count == x) {
				printf("%d", n+1);
				printf("/");
				printf("%d\n", m+1);
				break;
			}
			if (m == 0) {
				i++;
				for (int j = 0; j < i; j++) {
					m++;
					n--;
					count++;
					if (count == x) {
						printf("%d", n+1);
						printf("/");
						printf("%d\n", m+1);
						break;
					}
				}
				
			}
		}
	}

	return 0;
}