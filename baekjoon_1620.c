# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s {
	int num;
	char name[21];
}Pokemon;

int compare(const void* a, const void* b) {
	if (strcmp(((Pokemon*)a)->name, ((Pokemon*)b)->name) >= 0)
		return 1;
	else 
		return -1;
}

void injection(Pokemon* x, Pokemon* y) {
	Pokemon tmp;

	strcpy(tmp.name, y->name);
	tmp.num = y->num;

	strcpy(x->name, tmp.name);
	x->num = tmp.num;

}


Pokemon bs(Pokemon*pdex, Pokemon* element, int minindex, int maxindex) {
	int pivot = (maxindex + minindex) / 2;
	int r = strcmp(element->name, pdex[pivot].name);
	if (r == 0)
		return pdex[pivot];
	if (minindex < maxindex) {
		if (r < 0) { // element.name이 더 위에 있는(작은) 경우
			return bs(pdex, element, minindex, pivot-1);
		}
		else if (r > 0) { // element.name이 더 아래에 있는(큰) 경우
			return bs(pdex, element, pivot + 1, maxindex);
		}
	}
}


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

	Pokemon* namearr = (Pokemon*)malloc(sizeof(Pokemon) * n);
	for (int i = 0; i < n; i++) {
		injection(&(namearr[i]), &(pokedex[i]));
	}

	qsort(pokedex, n, sizeof(Pokemon), compare);


	Pokemon p;


	for (int i = 0; i < m; i++) {
		if (qlist[i].num == 0) { // 입력이 문자인 경우 : 도감 번호 출력
			p = bs(pokedex, &qlist[i], 0, n-1);
			printf("%d\n", p.num);
		}
		else { // 입력이 숫자인 경우 : 포켓몬 이름 출력
			printf("%s\n", namearr[qlist[i].num - 1].name);
			/*for (int j = 0; j < n; j++) {
				if (qlist[i].num == pokedex[j].num)
					printf("%s\n", pokedex[j].name);*/
			
			
		}
		
	}


	return 0;
}