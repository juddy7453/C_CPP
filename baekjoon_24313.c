# include <stdio.h>

int main(void) {
	double a0, a1;
	double c;
	double n0;

	scanf("%lf %lf", &a1, &a0);
	scanf("%lf", &c);
	scanf("%lf", &n0);

	// �� ������ ������(x, y) = (x, c*x) = (x, a1*x + a0)
	// x = a0 / (c - a1)

	if (c == a1) {
		if (a0 == 0)  // �� ������ ��ġ�ϴ� ��� -> �׻� ����
			printf("1\n");

		else if (a0 < 0) // �� ������ ������ ��� 
			printf("1\n");
		else
			printf("0\n");
	}

	else if (c < a1) // f�� ���Ⱑ �� ū ��� -> ���� �Ұ�
		printf("0\n");


	else {
		double x = a0 / (c - a1);
		if (n0 < x)
			printf("0\n");
		else
			printf("1\n");
	}

	return 0;
}