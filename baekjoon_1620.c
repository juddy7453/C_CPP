# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s {
	int num;
	char name[20];
}Pokemon;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	Pokemon* pokedex = (Pokemon*)malloc(sizeof(Pokemon) * n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &pokedex[i].name);
		pokedex[i].num = i + 1;
	}

	Pokemon* qlist = (Pokemon*)malloc(sizeof(Pokemon) * m);
	for (int i = 0; i < m; i++)
		scanf("%s", &qlist[i].name); // �Է��� �����̵� ���ڿ��̵� �ϴ� ���ڿ��� ����


	
	for (int i = 0; i < m; i++) {
		int pointer = qlist[i].name[0];
		if (pointer >= 49 && pointer <= 57) { // �Է��� ������ ���
			qlist[i].num = atoi(qlist[i].name);
		}
		else // �Է��� ������ ���
			qlist[i].num = 0;
	}

	for (int i = 0; i < m; i++) {
		if (qlist[i].num == 0) { // �Է��� ������ ��� : ���� ��ȣ ���
			for (int j = 0; j < n; j++) {
				if (strcmp(pokedex[j].name, qlist[i].name) == 0)
					printf("%d\n", pokedex[j].num);
			}
		}
		else { // �Է��� ������ ��� : ���ϸ� �̸� ���
			printf("%s\n", pokedex[qlist[i].num - 1].name);
		}
		
	}


	return 0;
}