#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int compare_callback(const void *a, const void *b)
{
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

	return (arg1 > arg2) - (arg1 < arg2);
}

int main(void)
{
	int list1[MAX];
    int list2[MAX];

    for (size_t i = 0; i < MAX; i++) {
        scanf("%d%d", &list1[i], &list2[i]);
    }

    qsort(list1, MAX, sizeof(int), compare_callback);
    qsort(list2, MAX, sizeof(int), compare_callback);
    
    size_t soln = 0;
	for (size_t i = 0; i < MAX; i++) {
        int counter = 0;
        for (size_t j = 0; j < MAX; j++) {
            if (list1[i] == list2[j])
                counter++;
        }

        soln += (size_t) (list1[i] * counter);
    }   

    printf("Solution: %zu\n", soln);
    
    return EXIT_SUCCESS;
}
