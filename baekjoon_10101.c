# include <stdio.h>

int main(void) {
	int a, b, c;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	if (a == 60 && b == 60 && c == 60) {
		printf("Equilateral\n");
		return 0;
	}

	else if (a + b + c == 180) {
		if (a == b || a == c || b == c) {
			printf("Isosceles\n");
			return 0;
		}
		else {
			printf("Scalene\n");
			return 0;
		}
	}

	else {
		printf("Error\n");
		return 0;
	}

}