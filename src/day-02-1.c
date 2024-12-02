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

bool is_safe(vector_t *vec) {
    bool is_increasing = false;
    bool is_decreasing = false;

    for (size_t it = 0; it < vec->count - 1; it++) {
        if (vec->items[it] > vec->items[it + 1])
            is_decreasing = true;
        if (vec->items[it] < vec->items[it + 1])
            is_increasing = true;

        size_t diff = abs(vec->items[it] - vec->items[it + 1]);

        if (diff < 1 || diff > 3)
            return false;
    }

    return (is_increasing ^ is_decreasing) ? true : false;
}

int main(int argc, char *argv[]) {
    const size_t ts = 1000;
    const size_t max = 100;

    size_t soln = 0;
    
    for (size_t i = 0; i < ts; i++) {
        vector_t report = {0};      
        char cstr[max];
       	fgets(cstr, max, stdin);

        char *token = strtok(cstr, " ");
		while (token != NULL) {
            int item = atoi(token);
            vector_append(&report, item);
            
            token = strtok(NULL, " ");
        }

        if (is_safe(&report)) {
            soln++;
        }
        // this chunk of code is for part 2
        else {
            for (size_t j = 0; j < report.count; j++) {
                vector_t report_copy = {0};

                for (size_t z = 0; z < report.count; z++)
                    vector_append(&report_copy, report.items[z]);
                vector_remove(&report_copy, j);

                if (is_safe(&report_copy)) {
                    soln++;
                    vector_free(report_copy);
                    break;
                }
                vector_free(report_copy);
            }
        }
	 	vector_free(report);       
    }

    printf("solution: %zu\n", soln);
    
    return 0;
}
