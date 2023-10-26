# include <stdio.h>

int main(void) {
	int n = 1;
	int m = 1;
	int sum = 1;

	scanf("%d", &n);

	int i = 1;

	if (n == 1) {
		printf("1\n");
		return 0;
	}

	while (1) {
		m = i * 6;
		sum = sum + m;
		
		if (n <= sum) {
			printf("%d\n", i+1);
			break;
		}
		else
			i++;
	}

	return 0;
}