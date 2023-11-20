# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int compare(const void* a, const void* b) {
	if (strcmp(*(char**)a, *(char**)b) > 0)
		return 1;
	else
		return -1;
}

int bs(char** arr, char* element, int firstindex, int lastindex) {
	int mid = (firstindex + lastindex) / 2;
	int r = strcmp(*(arr + mid), element);

	if (firstindex > lastindex)
		return 0;



	if (r < 0) { // element가 사전 상 더 앞에 있는 경우
		return bs(arr, element, mid + 1, lastindex);
	}
	else if (r > 0) { // element가 사전 상 더 뒤에 있는 경우
		return bs(arr, element, firstindex, mid - 1);
	}
	else
		return 1;
}




int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	char** sarr = (char**)malloc(sizeof(char*) * n);
	char** input = (char**)malloc(sizeof(char*) * m);
	for (int i = 0; i < n; i++) {
		*(sarr + i) = (char*)malloc(sizeof(char) * 501);
		scanf("%s", *(sarr + i));
	}

	for (int j = 0; j < m; j++) {
		*(input + j) = (char*)malloc(sizeof(char) * 501);
		scanf("%s", *(input + j));
	}

	qsort(sarr, n, sizeof(char*), compare);

	int count = 0;
	for (int i = 0; i < m; i++)
		count += bs(sarr, input[i], 0, n - 1);

	printf("%d\n", count);


	return 0;
}