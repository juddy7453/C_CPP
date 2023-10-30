# include <stdio.h>
# include <string.h>

int main(void) {
	int n;
	int m = 666;
	char str[10];

	scanf("%d", &n);

	int count = 1;
	while (count < n) {
		m++;
		sprintf(str, "%d", m);
		if (strstr(str, "666")) {
			count++;
		}
		// printf("%s\n", str);
	}

	printf("%d\n", m);

	return 0;
}