# include <stdio.h>
# include <stdlib.h>

typedef struct node {
	int element;
	struct node* pe; // 부모 node를 가리키는 엣지(포인터)
	struct node* ce1; struct node* ce2; // 자식 node를 가리키는 엣지(포인터)
	int check;
}Node;

void f(Node** tree_ptr, int* arr, int index, int size) {
	if (index >= size)
		return;
	if (arr[index] > (*tree_ptr)->element) {
		if ((*tree_ptr)->ce2 == NULL) {
			(*tree_ptr)->ce2 = (Node*)malloc(sizeof(Node));
			(*tree_ptr)->ce2->pe = (*tree_ptr);
			(*tree_ptr)->ce2->element = arr[index++];
			(*tree_ptr)->ce2->check = 0;
			(*tree_ptr)->ce2->ce1 = NULL;
			(*tree_ptr)->ce2->ce2 = NULL;
			while ((*tree_ptr)->element != arr[0]) {
				tree_ptr = &((*tree_ptr)->pe);
			}
			f(tree_ptr, arr, index, size);
		}
		else {
			f(&((*tree_ptr)->ce2), arr, index, size);
		}
	}
	else {
		if ((*tree_ptr)->ce1 == NULL) {
			(*tree_ptr)->ce1 = (Node*)malloc(sizeof(Node));
			(*tree_ptr)->ce1->pe = (*tree_ptr);
			(*tree_ptr)->ce1->element = arr[index++];
			(*tree_ptr)->ce1->check = 0;
			(*tree_ptr)->ce1->ce1 = NULL;
			(*tree_ptr)->ce1->ce2 = NULL;
			while ((*tree_ptr)->element != arr[0]) {
				tree_ptr = &((*tree_ptr)->pe);
			}
			f(tree_ptr, arr, index, size);
		}
		else {
			f(&((*tree_ptr)->ce1), arr, index, size);
		}
	}
}



int main(void) {
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	Node* tree = (Node*)malloc(sizeof(Node));

	tree->element = arr[0];
	Node** tree_ptr = &tree;

	(*tree_ptr)->pe = *tree_ptr;
	(*tree_ptr)->ce1 = NULL;
	(*tree_ptr)->ce2 = NULL;

	f(tree_ptr, arr, 1, n);

	// 9, [84, 9, -4, 2, -90, -27, 44, 1, 3]
	//printf("##########\n");
	//printf("%d\n", (*heap_ptr)->element); // 84
	//printf("%d\n", (*heap_ptr)->ce1->element); // 9
	//printf("%d\n", (*heap_ptr)->ce1->ce2->element); // 44
	//printf("%d\n", (*heap_ptr)->ce1->ce1->element); // -4
	//printf("%d\n", (*heap_ptr)->ce1->ce1->ce1->element); // -90
	//printf("%d\n", (*heap_ptr)->ce1->ce1->ce1->ce2->element); // -27
	//printf("%d\n", (*heap_ptr)->ce1->ce1->ce2->element); // 2
	//printf("%d\n", (*heap_ptr)->ce1->ce1->ce2->ce2->element); // 3
	//printf("%d\n", (*heap_ptr)->ce1->ce1->ce2->ce1->element); // 1


	int count = 0;
	while (count < n) {
		while (1) {
			if ((*tree_ptr)->ce1 == NULL) {
				if ((*tree_ptr)->check == 1) {
					tree_ptr = &((*tree_ptr)->pe);
					(*tree_ptr)->ce1 = NULL;
				}
				else {
					printf("%d\n", (*tree_ptr)->element);
					(*tree_ptr)->check = 1;
					count++;
					break;
				}
			}
			else {
				if ((*tree_ptr)->ce1->check == 1) {
					(*tree_ptr)->ce1 = NULL;
				}
				else
					tree_ptr = &((*tree_ptr)->ce1);

			}
		}
		if ((*tree_ptr)->ce2 != NULL) {
			if((*tree_ptr)->check == 1)
				tree_ptr = &((*tree_ptr)->ce2);
			else {
				printf("%d\n", (*tree_ptr)->element);
				(*tree_ptr)->check = 1;
				count++;
			}
			continue;
		}
		else {
			tree_ptr = &((*tree_ptr)->pe);

			if ((*tree_ptr)->check == 1) {
				tree_ptr = &((*tree_ptr)->pe);
				(*tree_ptr)->ce1 = NULL;
			}
			else {
				continue;
			}
		}
	}




	return 0;
}