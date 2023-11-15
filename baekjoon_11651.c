# include <stdio.h>
# include <stdlib.h>

typedef struct s {
	int x;
	int y;
}Pair;

int compare(const void* n1, const void* n2) {
	if ((*(Pair*)n1).y > (*(Pair*)n2).y)
		return 1;
	else if ((*(Pair*)n1).y < (*(Pair*)n2).y)
		return -1;
	else {
		if ((*(Pair*)n1).x > (*(Pair*)n2).x)
			return 1;
		else
			return -1;
	}
}


int main(void) {
	int n;
	scanf("%d", &n);

	Pair* arr = (Pair*)malloc(sizeof(Pair) * n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &(arr[i].x), &(arr[i].y));

	if (n == 1) {
		printf("%d %d\n", arr[0].x, arr[0].y);
		return 0;
	}

	qsort(arr, n, sizeof(Pair), compare);

	for (int i = 0; i < n; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);

	return 0;
}