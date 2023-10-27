# include <stdio.h>
# include <stdlib.h>

typedef struct s {
	int element;
	struct s* node_ptr;
}S;

int main(void) {
	int a, b, c;
	int count = 0;
	int result;

	S head;
	head.element = -1;
	head.node_ptr = NULL;

	S* ptr = &head;

	while (1) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0) {
			ptr = &head;
			ptr = (ptr->node_ptr);
			for (int j = 0; j < count; j++) {
				result = ptr->element;
				if (result == -1) {
					free(ptr);
					return 0;
				}
				if (result == 0)
					printf("Invalid\n");
				else if (result == 1)
					printf("Equilateral\n");
				else if (result == 2)
					printf("Isosceles\n");
				else
					printf("Scalene\n");

				ptr = (ptr->node_ptr);
			}
			free(ptr);
			return 0;
		}
		


		int max = a;
		int x = b;
		int y = c;

		if (max < b) {
			max = b;
			x = a; y = c;
		}
		if (max < c) {
			max = c;
			x = a; y = b;
		}

		S* new_node = (S*)malloc(sizeof(S));

		if (c >= (x + y)) { // Invalid
			new_node->element = 0;
			new_node->node_ptr = NULL;
			ptr->node_ptr = new_node;
			ptr = new_node;
		}
		else {
			if (a == b && a == c && b == c){ // Equilateral
				new_node->element = 1;
				new_node->node_ptr = NULL;
				ptr->node_ptr = new_node;
				ptr = new_node;
			}
			
			else if (x == y || x == max || y == max){ // Isosceles
				new_node->element = 2;
				new_node->node_ptr = NULL;
				ptr->node_ptr = new_node;
				ptr = new_node;
			}
			
			else { // Scalene
				new_node->element = 3;
				new_node->node_ptr = NULL;
				ptr->node_ptr = new_node;
				ptr = new_node;
			}
		}

		count++;
	}

	return 0;
}