# include <stdio.h>
# include <math.h>

int main(void) {
	int a, b, v;
	int day = 0;

	scanf("%d %d %d", &a, &b, &v);
	day = ceil((double)(v - a) / (double)(a - b)) + 1;

	printf("%d\n", day);


	return 0;
}