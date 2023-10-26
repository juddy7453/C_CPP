# include <stdio.h>

int main(void) {
	int n;;
	int m = 2;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) 
		m = m + (m - 1);
	
	printf("%d", m*m);

	return 0;
}