# include <stdio.h>
# include <stdlib.h>

int f(char arr[8][8])
{
	int count_w = 0;
	int count_b = 0;

	for (int j = 0; j < 8; j += 2) { // ¸Ç ¿ÞÂÊ À§ Ä­ÀÌ Èò»ö
		for (int k = 0; k < 7; k += 2) { // WBWBWB...
			if (arr[j][k] == 'B') {
				count_w++;
			}
			if (arr[j][k + 1] == 'W') {
				count_w++;
			}
		}
	}
	for (int j = 1; j < 8; j += 2) { // ¸Ç ¿ÞÂÊ À§ Ä­ÀÌ Èò»ö
		for (int k = 0; k < 7; k += 2) { // BWBWBW...
			if (arr[j][k] == 'W') {
				count_w++;
			}
			if (arr[j][k + 1] == 'B') {
				count_w++;
			}
		}
	}

	for (int j = 0; j < 8; j += 2) { // ¸Ç ¿ÞÂÊ À§ Ä­ÀÌ °ËÀº»ö
		for (int k = 0; k < 7; k += 2) { // BWBWBW...
			if (arr[j][k] == 'W') {
				count_b++;
			}
			if (arr[j][k + 1] == 'B') {
				count_b++;
			}
		}
	}

	for (int j = 1; j < 8; j += 2) { // ¸Ç ¿ÞÂÊ À§ Ä­ÀÌ °ËÀº»ö
		for (int k = 0; k < 7; k += 2) { // WBWBWB...
			if (arr[j][k] == 'B') {
				count_b++;
			}
			if (arr[j][k + 1] == 'W') {
				count_b++;
			}
		}
	}

	if (count_w > count_b)
		return count_b;
	else
		return count_w;
}


int main(void) {
	int n, m;
	int min = 2500;
	int result;

	scanf("%d %d", &n, &m);

	char** arr = (char**)malloc(sizeof(char*) * n);


	for (int i = 0; i < n; i++) {
		char* line = (char*)malloc(sizeof(char) * m);
		scanf("%s", line);
		arr[i] = line;
	}
	
	char square[8][8];

	int x = 0;
	int y = 0;

	while(y + 8 <= n)
	{
		while (x + 8 <= m) {
			for (int i = 0; i <  8; i++) {
				for (int j = 0; j <  8; j++) {
					square[i][j] = arr[i+y][j+x];
				}
			} // °ª º¹»ç ¿Ï·á
			result = f(square);

			if (result < min) {
				min = result;
			}
			x++;
		}
		x = 0;
		y++;
	}

	printf("%d\n", min);
	return 0;
}