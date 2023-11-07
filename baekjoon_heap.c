# include <stdio.h>
# include <stdlib.h>

//heapify, 힙 상태 만들기 
void heapify(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		int child = i;
		do {
			//자식 노드가 부모 노드보다 크면 교환
			int root = (child - 1) / 2;
			if (arr[root] < arr[child]) {
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			child = root;
		} while (child != 0);	//최상단 노드까지 점검
	}
}

//최상단 노드와 최하단 노드 교체
void heap(int* arr, int* size) {
	int temp = arr[0];
	arr[0] = arr[*size - 1];
	arr[*size - 1] = temp;
	--(*size);
}

int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int size = n;
	
	//힙정렬
	for (int i = 0; i < n; i++) {
		heapify(arr, size);
		heap(arr, &size);
	}

	//출력 
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}


	return 0;
}