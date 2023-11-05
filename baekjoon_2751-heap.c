# include <stdio.h>
# include <stdlib.h>

void f(int** heap_ptr, int i, int n) {
	int j;
	int tmp;
	while (i < n) {
		i++;
		j = i;
		if ((*heap_ptr)[i] > (*heap_ptr)[i / 2]) {
			// 그대로 삽입
			continue;
		}
		else if ((*heap_ptr)[i] < (*heap_ptr)[i / 2]) {
			// 두 node를 서로 바꿈
			while ((*heap_ptr)[j] < (*heap_ptr)[j / 2]) {
				tmp = (*heap_ptr)[j / 2];
				(*heap_ptr)[j / 2] = (*heap_ptr)[j];
				(*heap_ptr)[j] = tmp;
				j /= 2;
			}

		}
	}
}

int main(void) {
	int n;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int* heap = (int*)malloc(sizeof(int) * (n+1));
	heap[1] = arr[0];
	
	int i = 1;
	int j;
	int tmp;
	while (i < n) {
		heap[i + 1] = arr[i];
		i++;
		j = i;
		if (heap[i] > heap[i / 2]) {
			// 그대로 삽입
			continue;
		}
		else if (heap[i] < heap[i / 2]) {
			// 두 node를 서로 바꿈
			while (heap[j] < heap[j / 2]) {
				tmp = heap[j / 2];
				heap[j / 2] = heap[j];
				heap[j] = tmp;
				j /= 2;
			}

		}
	}

	int count = n;
	int k = 1;
	while (count > 0) {
		printf("%d\n", heap[1]);
		heap[1] = heap[count--];
		f(&heap, k, count);
	}

	return 0;
}