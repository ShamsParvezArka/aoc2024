#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <assert.h>

#define VECTOR_INIT_CAP 256
#define VECTOR_GROWTH_FACTOR 2

#define vector_extend_capacity(vec)                                                    \
    do {                                                                               \
        (vec)->capacity = (vec)->capacity == 0 ?                                       \
                          (vec)->capacity = VECTOR_INIT_CAP :                          \
                          (vec)->capacity + (vec)->capacity * VECTOR_GROWTH_FACTOR;    \
        (vec)->items = realloc((vec)->items, sizeof(*(vec)->items) * (vec)->capacity); \
                                                                                       \
        assert((vec)->items != NULL);                                                  \
    } while (0)

#define vector_append(vec, item)             \
    do {                                     \
    	if ((vec)->count >= (vec)->capacity) \
            vector_extend_capacity((vec));   \
        (vec)->items[(vec)->count] = (item); \
        (vec)->count++;                      \
	} while (0)

#define vector_remove(vec, pos)                         \
    do {                                                \
        for (size_t i = pos; i < (vec)->count - 1; i++) \
            (vec)->items[i] = (vec)->items[i + 1];      \
        (vec)->items[(vec)->count] = 0;                 \
        (vec)->count--;                                 \
    } while (0)

#define vector_free(vec)     \
    do {                     \
        free((vec)->items);  \
        (vec)->count = 0;    \
        (vec)->capacity = 0; \
    } while (0)

#endif //VECTOR_H_
