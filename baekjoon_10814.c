# include <stdio.h>
# include <stdlib.h>

typedef struct s {
	int age;
	char name[101];
	int order;
}Person;

int compare(const void* a, const void* b) {
	Person *ap = (Person*)a;
	Person* bp = (Person*)b;

	if (ap->age > bp->age)
		return 1;
	else if (ap->age < bp->age)
		return -1;
	else {
		if (ap->order > bp->order)
			return 1;
		else
			return -1;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	Person* arr = (Person*)malloc(sizeof(Person) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &arr[i].age, arr[i].name);
		arr[i].order = i;
	}

	qsort(arr, n, sizeof(Person), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", arr[i].age, arr[i].name);
	}

	return 0;
}