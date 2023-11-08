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
		scanf("%s", &qlist[i].name); // 입력이 숫자이든 문자열이든 일단 문자열로 받음


	
	for (int i = 0; i < m; i++) {
		int pointer = qlist[i].name[0];
		if (pointer >= 49 && pointer <= 57) { // 입력이 숫자인 경우
			qlist[i].num = atoi(qlist[i].name);
		}
		else // 입력이 문자인 경우
			qlist[i].num = 0;
	}

	for (int i = 0; i < m; i++) {
		if (qlist[i].num == 0) { // 입력이 문자인 경우 : 도감 번호 출력
			for (int j = 0; j < n; j++) {
				if (strcmp(pokedex[j].name, qlist[i].name) == 0)
					printf("%d\n", pokedex[j].num);
			}
		}
		else { // 입력이 숫자인 경우 : 포켓몬 이름 출력
			printf("%s\n", pokedex[qlist[i].num - 1].name);
		}
		
	}


	return 0;
}