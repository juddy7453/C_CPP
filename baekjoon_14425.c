# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int hash_func(char *arr) {
	int h;
	int l = 0;
	while (1) {
		if (arr[l] == '\0') 
			break;
		
		l++;
	}
	int total = 0;
	int i = 0;
	while (i < l) {
		total += (i+1)*(int)arr[i];
		i++;
	}
	h = total;
//	printf("h=%d\n", h);
	return h;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	char (*sarr)[500];
	char(*inputarr)[500];
	sarr = (char(*)[500])malloc(sizeof(char) * 500 * n);
	inputarr = (char(*)[500])malloc(sizeof(char) * 500 * m);
	for (int i = 0; i < n; i++)
		scanf("%s", (sarr[i]));
	for (int i = 0; i < m; i++)
		scanf("%s", (inputarr[i]));

//	char(*r_sarr)[500];
//	r_sarr = (char(*)[500])malloc(sizeof(char) * 500 * n);

//	printf("sarr[0][10]=%c\n", sarr[0][10]);

	int* hash_s = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		hash_s[i] = hash_func(sarr[i]);
	int* hash_i = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
		hash_i[i] = hash_func(inputarr[i]);

	//for (int i = 0; i < n; i++)
	//	printf("i=%d, hash=%d\n", i, hash_s[i]);
	//printf("###########\n");
	//for (int i = 0; i < m; i++)
	//	printf("i=%d, hash=%d\n", i, hash_i[i]);

	int count = 0;
	int t = 0;

	int sp, ip;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (hash_i[i] == hash_s[j]) {
				count++;
				break;
			}
		}
	}

	printf("%d\n", count);

	return 0;
}