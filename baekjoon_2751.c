# include <stdio.h>
# include <stdlib.h>

typedef struct node {
	int element;
	struct node* pe; // 부모 node를 가리키는 엣지(포인터)
	struct node* ce1; struct node* ce2; // 자식 node를 가리키는 엣지(포인터)
	int check;
}Node;

void f(Node** heap_ptr, int* arr, int index, int size) {
	if (index >= size)
		return;
	if (arr[index] > (*heap_ptr)->element) {
		if ((*heap_ptr)->ce2 == NULL) {
			(*heap_ptr)->ce2 = (Node*)malloc(sizeof(Node));
			(*heap_ptr)->ce2->pe = (*heap_ptr);
			(*heap_ptr)->ce2->element = arr[index++];
			(*heap_ptr)->ce2->check = 0;
			(*heap_ptr)->ce2->ce1 = NULL;
			(*heap_ptr)->ce2->ce2 = NULL;
			f(&((*heap_ptr)->pe), arr, index, size);
		}
		else {
			f(&((*heap_ptr)->ce2), arr, index, size);
		}
	}
	else {
		//		printf("caseB\n");
		if ((*heap_ptr)->ce1 == NULL) {
			(*heap_ptr)->ce1 = (Node*)malloc(sizeof(Node));
			(*heap_ptr)->ce1->pe = (*heap_ptr);
			(*heap_ptr)->ce1->element = arr[index++];
			(*heap_ptr)->ce1->check = 0;
			(*heap_ptr)->ce1->ce1 = NULL;
			(*heap_ptr)->ce1->ce2 = NULL;
			f(&((*heap_ptr)->pe), arr, index, size);
		}
		else {
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
	Node*** heap_address = &heap_ptr;

	(*heap_ptr)->pe = *heap_ptr;
	(*heap_ptr)->ce1 = NULL;
	(*heap_ptr)->ce2 = NULL;

	f(heap_ptr, arr, 1, n);


	//printf("##########\n");
	//printf("%d\n", (*heap_ptr)->element);
	//printf("%d\n", (*heap_ptr)->ce1->element);
	//printf("%d\n", (*heap_ptr)->ce1->ce2->element);


	int count = 0;
	while (count < n) {
		while (1) {
			if ((*heap_ptr)->ce1 == NULL) {
				if ((*heap_ptr)->check == 1) {
					heap_ptr = &((*heap_ptr)->pe);
					(*heap_ptr)->ce1 = NULL;
				}
				else {
					printf("%d\n", (*heap_ptr)->element);
					(*heap_ptr)->check = 1;
					count++;
					break;
				}
			}
			else {
				if ((*heap_ptr)->ce1->check == 1) {
					(*heap_ptr)->ce1 = NULL;
				}
				else
					heap_ptr = &((*heap_ptr)->ce1);

			}
		}
		if ((*heap_ptr)->ce2 != NULL) {
			heap_ptr = &((*heap_ptr)->ce2);
			continue;
		}
		else {
			heap_ptr = &((*heap_ptr)->pe);

			if ((*heap_ptr)->check == 1) {
				heap_ptr = &((*heap_ptr)->pe);
				(*heap_ptr)->ce1 = NULL;
			}
			else {
				continue;
			}
		}
	}




	return 0;
}