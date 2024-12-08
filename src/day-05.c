#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MAX_RULES 100
#define MAX_PAGES 50

int order[MAX_RULES][MAX_RULES];

int compare_pages(const void *a, const void *b) {
    const int *aa = (int*) a;
    const int *bb = (int*) b;

    return  order[*aa][*bb] == 1 ? -1 :
            order[*bb][*aa] == 1 ?  1 :
            0;
}

int maybe_fix_pages(int pages[MAX_PAGES], int page_count) {
    for (int i = 0; i < page_count; i++) {
        for (int j = 0; j < i; j++) {
            if (order[pages[i]][pages[j]] == 1) {
                qsort(pages, page_count, sizeof(int), compare_pages);
                return 1;
            }
        }
    }

    return 0;
}

int main(void) {
    char buf[BUFFER_SIZE];

    while (fgets(buf, BUFFER_SIZE, stdin) != NULL) {
        if (buf[0] == '\n') break;
        int before, after;
        sscanf(buf, "%d|%d", &before, &after);
        order[before][after] = 1;
    }

    int part1 = 0, part2 = 0;

    while (fgets(buf, BUFFER_SIZE, stdin) != NULL) {
        int page_count = 0;
        char *saveptr, *token;
        int pages[MAX_PAGES] = {0};

        while ((token = strtok_s(page_count ? NULL : buf, ",", &saveptr)) != NULL) {
            pages[page_count++] = atoi(token);
        }

        int fixed = maybe_fix_pages(pages, page_count);
        int middle = pages[page_count/2];

        if (fixed) {
            part2 += middle;
        }
        else {
            part1 += middle;
        }
    }

    printf("Part 1: %d\n", part1);
    printf("Part 2: %d\n", part2);

    return 0;
}
