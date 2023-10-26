# include <stdio.h>

int main(void) {
	int x;

	scanf("%d", &x);

	int n = 0;
	int m = 0;
	int i = 0;
	int count = 1;

	if (x == 1) {
		printf("1/1\n");
		return 0;
	}

	while (count < x) {

		if ((i % 2 == 0) && (n == 0)) { // 오른쪽으로 한칸 이동
			m++;
			count++;
			i++;
		}

		else if ((i % 2 != 0) && (m == 0)) { //아래로 한칸 이동
			n++;
			count++;
			i++;
		}

		else if (i % 2 != 0) { //아래로 한칸, 왼쪽으로 한칸 이동
			n++;
			m--;
			count++;
		}

		else if (i % 2 == 0) { //오른쪽으로 한칸, 위쪽으로 한칸 이동
			m++;
			n--;
			count++;
		}
			
		
	}


	printf("%d", n + 1);
	printf("/");
	printf("%d\n", m + 1);
	

	return 0;
}
