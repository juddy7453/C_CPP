# include <stdio.h>
# include <stdlib.h>

typedef struct node {
	int element;
	struct node* pe; // 부모 node를 가리키는 엣지(포인터)
	struct node* ce1; struct node* ce2; // 자식 node를 가리키는 엣지(포인터)
}Node;

void f(Node** heap_ptr, int* arr, int index, int size) {
//	printf("*****f*****\n");
	if (index >= size)
		return;
	if (arr[index] > (*heap_ptr)->element) {
//		printf("caseA\n");
		if ((*heap_ptr)->ce2 == NULL){
//			printf("caseA-1\n");
			(*heap_ptr)->ce2 = (Node*)malloc(sizeof(Node));
			(*heap_ptr)->ce2->pe = (*heap_ptr);
			(*heap_ptr)->ce2->element = arr[index++];
			(*heap_ptr)->ce2->ce1 = NULL;
			(*heap_ptr)->ce2->ce2 = NULL;
			f(heap_ptr, arr, index, size);
		}
		else {
//			printf("caseA-2\n");
			f(&((*heap_ptr)->ce2), arr, index, size);
		}
	}
	else {
//		printf("caseB\n");
		if ((*heap_ptr)->ce1 == NULL) {
//			printf("caseB-1\n");
			(*heap_ptr)->ce1 = (Node*)malloc(sizeof(Node));
			(*heap_ptr)->ce1->pe = (*heap_ptr);
			(*heap_ptr)->ce1->element = arr[index++];
			(*heap_ptr)->ce1->ce1 = NULL;
			(*heap_ptr)->ce1->ce2 = NULL;
			f(heap_ptr, arr, index, size);
		}
		else {
//			printf("caseB-2\n");
			f(&((*heap_ptr)->ce1), arr, index, size);
		}
	}
}

int main(void) {
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	Node* heap = (Node*)malloc(sizeof(Node));

	heap->element = arr[0];
	Node** heap_ptr = &heap;
	Node** heap_address = &heap;

	(*heap_ptr)->pe = NULL;
	(*heap_ptr)->ce1 = NULL;
	(*heap_ptr)->ce2 = NULL;

	f(heap_ptr, arr, 1, n);

	int* result_arr = (int*)malloc(sizeof(int) * n);
	int j = 0;
	int complete = 0;
	while(j < n) { // 중위 순회
		if (complete==0 && (*heap_address)->ce1 != NULL) {
			heap_address = &((*heap_address)->ce1);
		}
		else {
			if (complete == 0 && (*heap_address)->ce1 == NULL) {
				result_arr[j] = (*heap_address)->element;
				heap_address = &((*heap_address)->pe);
				j++;
				complete = 1;
			}
			else if (complete == 1) {
				result_arr[j] = (*heap_address)->element;
				j++;
				complete = -1; // ce2 탐색할 차례
			}
			else if (complete == -1 && (*heap_address)->ce2 != NULL) {
				heap_address = &((*heap_address)->ce2);
				complete = 0;
			}
			else if (complete == -1 && (*heap_address)->ce2 == NULL){
				heap_address = &((*heap_address)->pe);
				complete = 1;
			}
		}
	}

	for (int k = 0; k < n; k++)
		printf("%d\n", result_arr[k]);

	return 0;
}