#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int x;
    int y;
} vec2_t;

typedef enum
{
    UP,
    DOWN,
    RIGHT,
    LEFT
} direction_t;

#define ROWS 130
#define COLS 130

char **parse_samples(void)
{
    char **sample = (char **) calloc(ROWS, sizeof(char *));
    for (size_t i = 0; i < COLS; i++)
    {
        sample[i] = (char *) calloc(COLS + 2, sizeof(char));
        fgets(sample[i], COLS + 2, stdin);
        sample[i][strcspn(sample[i], "\n")] = 0;
        sample[i] = realloc(sample[i], COLS + 1);
    }
    
    return sample;
}

vec2_t get_starting_position(char **input)
{
    for (size_t row = 0; row < ROWS; row++)
    {
        for (size_t col = 0; col < COLS; col++)
        {
            if (input[row][col] == '^')
                return (vec2_t) {.x = (int) row, .y = (int) col};
        }
    }

    return (vec2_t) {0, 0};
}

void guard_action(char **input, bool **is_visited, vec2_t position, direction_t direction, size_t *answer)
{
    if (!is_visited[position.x][position.y])
    {
        is_visited[position.y][position.y] = true;
        //printf("%zu\n", *answer);
        (*answer)++;
    }

    vec2_t new_position;
    direction_t new_direction;

    switch (direction)
    {
    case UP:
        new_direction = RIGHT;
        new_position.x = position.x - 1;
        new_position.y = position.y;
        break;
    case DOWN:
        new_direction = LEFT;
        new_position.x = position.x + 1;
        new_position.y = position.y;
        break;
    case LEFT:
        new_direction = UP;
        new_position.x = position.x;
        new_position.y = position.y - 1;
        break;
    case RIGHT:
        new_direction = DOWN;
        new_position.x = position.x;
        new_position.y = position.y + 1;
        break;
    default:
        break;
    }

    if (new_position.x < 0 || new_position.x >= COLS) return;
    if (new_position.y < 0 || new_position.y >= ROWS) return;

    if (input[new_position.x][new_position.y] == '.' ||
        input[new_position.x][new_position.y] == '^')
    {
		guard_action(input, is_visited, new_position, direction, answer);
    }
    else if (input[new_position.x][new_position.y] == '#')
    {
     	guard_action(input, is_visited, position, new_direction, answer);
    }
    
    return;
}

int main(int argc, char *argv[])
{
    size_t answer = 0;
	char **input = parse_samples();
	vec2_t starting_position = get_starting_position(input);

    bool **is_visited = (bool **) calloc(ROWS, sizeof(bool *));
    for (size_t i = 0; i < ROWS; i++)
        is_visited[i] = (bool *) calloc(COLS, sizeof(bool));

	guard_action(input, is_visited, starting_position, UP, &answer);

    printf("debug: %zu: soln: %zu\n", tmp, answer);
    
    return 0;
}
