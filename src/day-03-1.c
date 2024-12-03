/*
  Reporting data: 04-12-2024
  Dear furure Arka, before you read this code I want to acknowledge you
  about the whole solution situation. This problem is much more easier
  if we somehow can refactor and refine the input sample.

  With following, I've done some "REGEX" beforehand to refactor and
  refine the input sample.

  Regex: Get-Content .\day-03-1.txt | rg -o "mul\((\d+),(\d+)\)"
                                    | rg -o "(\d+),(\d+)"
                                    | Out-File day-03-1-refactored.txt
 */

#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "../include/vector.h"

int main(void) {
    size_t soln = 0;
    
    for (size_t i = 0; i < 654; i++) {
    	long a, b;
   		scanf("%ld%ld", &a, &b);

        soln += a * b;
    }

    printf("solution: %zu\n", soln);
    
    return EXIT_SUCCESS;
}
