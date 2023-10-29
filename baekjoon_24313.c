# include <stdio.h>

int main(void) {
	double a0, a1;
	double c;
	double n0;

	scanf("%lf %lf", &a1, &a0);
	scanf("%lf", &c);
	scanf("%lf", &n0);

	// 두 직선의 교차점(x, y) = (x, c*x) = (x, a1*x + a0)
	// x = a0 / (c - a1)

	if (c == a1) {
		if (a0 == 0)  // 두 직선이 일치하는 경우 -> 항상 성립
			printf("1\n");

		else if (a0 < 0) // 두 직선이 평행한 경우 
			printf("1\n");
		else
			printf("0\n");
	}

	else if (c < a1) // f의 기울기가 더 큰 경우 -> 성립 불가
		printf("0\n");


	else {
		double x = a0 / (c - a1);
		if (n0 < x)
			printf("0\n");
		else
			printf("1\n");
	}

	return 0;
}