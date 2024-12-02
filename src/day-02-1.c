#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "../include/vector.h"

typedef struct {
    int *items;
    size_t count;
    size_t capacity;
} vector_t;

int main(int argc, char *argv[]) {
    const size_t ts = 1000;
    const size_t max = 1000;

    size_t soln = 0;
    
    for (size_t i = 0; i < 1000; i++) {
        vector_t report = {0};
        bool is_increasing = false;
        bool is_decreasing = false;
        bool is_safe = true;
        
        char cstr[max];
       	fgets(cstr, max, stdin);

        size_t index = 0;
        char *token = strtok(cstr, " ");
		while (token != NULL) {
            int item = atoi(token);
            
            vector_append(&report, item);
            token = strtok(NULL, " ");
        }

        #if 1
        printf("%d -> ", i);
        for (size_t j = 0; j < report.count; j++)
            printf("%d ", report.items[j]);
        printf("\n");
        #endif

        for (size_t j = 0; j < report.count - 1; j++) {
            if (report.items[j] > report.items[j + 1])
                is_decreasing = true;
            else if (report.items[j] < report.items[j + 1])
                is_increasing = true;

            int diff = abs(report.items[j] - report.items[j + 1]);
            if (diff > 3 || diff < 1) {
                is_safe = false;
                break;
            }
        }

        if (is_safe && !(is_decreasing & is_increasing))
            soln++;

        vector_free(&report);
    }

    printf("solution: %zu\n", soln);
    
    return 0;
}
