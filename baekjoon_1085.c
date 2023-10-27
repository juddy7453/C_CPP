# include <stdio.h>

int main(void) {
	int x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	int arr[4];

	arr[0] = w - x;
	int min = arr[0];

	arr[1] = x;
	if (min > arr[1])
		min = arr[1];

	arr[2] = h - y;
	if (min > arr[2])
		min = arr[2];

	arr[3] = y;
	if (min > arr[3])
		min = arr[3];

	printf("%d\n", min);

	return 0;
}