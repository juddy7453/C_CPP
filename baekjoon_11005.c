# include <stdio.h>

int main(void) {
	int n;
	int b;
	char total_sum[31];

	scanf("%d %d", &n, &b);

	int m = n;
	int r;
	int c;
	int j = 0;
	

	// 아스키 코드
	// 0 => 48
	// 9 => 57
	// A => 65
	// Z => 90

	while (m >= 1) {
		r = m % b;
		m /= b;
		if (r < 10) {
			total_sum[31 - j - 1] = r + 48;
			j++;
		}

		else {
			total_sum[31 - j - 1] = r + 55;
			j++;
		}
		
	}

	
	for (int i = 31 - j; i < 31; i++) {
		if (total_sum[i] == '\0') 
			return 0;
		
		else {
			c = total_sum[i];
			printf("%c", c);

		}
	}
	
	return 0;
}