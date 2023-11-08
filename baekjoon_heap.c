# include <stdio.h>
# include <stdlib.h>

//heapify, �� ���� ����� 
void heapify(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		int child = i;
		do {
			//�ڽ� ��尡 �θ� ��庸�� ũ�� ��ȯ
			int root = (child - 1) / 2;
			if (arr[root] < arr[child]) {
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			child = root;
		} while (child != 0);	//�ֻ�� ������ ����
	}
}

//�ֻ�� ���� ���ϴ� ��� ��ü
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
	
	//������
	for (int i = 0; i < n; i++) {
		heapify(arr, size);
		heap(arr, &size);
	}

	//��� 
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}


	return 0;
}