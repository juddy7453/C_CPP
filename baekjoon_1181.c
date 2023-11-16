# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int compare(const char** s1, const char** s2) {
	int l1 = strlen(*s1);
	int l2 = strlen(*s2);

	if (l1 > l2)
		return 1;
	else if (l1 < l2)
		return -1;
	else {
		if (strcmp(*s1, *s2) > 0)
			return 1;
		else if (strcmp(*s1, *s2) < 0)
			return -1;
		else
			return 0;
	}
}


int main(void) {
	int n;
	scanf("%d", &n);

	char** arr = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		*(arr + i) = (char*)malloc(sizeof(char)*51);
		scanf("%s", arr[i]);
	}


	qsort(arr, n, sizeof(char*), compare);


	for (int i = 0; i < n-1; i++) {
		if (i < n - 2) {
			if (strcmp(arr[i], arr[i + 1]) == 0)
				continue;
			printf("%s\n", arr[i]);
		}

		else if (i == n - 2) {
			if (strcmp(arr[i], arr[i + 1]) != 0)
				printf("%s\n", arr[i]);
			printf("%s\n", arr[i + 1]);
		}
		
	}
	return 0;
}