#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define GENERATIONS 5

int count_neighbors(int **grid, int i, int j) {
    int count = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) continue;
            int ni = i + x;
            int nj = j + y;
            if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE) {
                count += grid[ni][nj];
            }
        }
    }
    return count;
}

int main() {
    int **grid = (int **)malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        grid[i] = (int *)malloc(SIZE * sizeof(int));
    }

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
    	for (int j = 0; j < SIZE; j++) {
        	grid[i][j] = rand() % 2;
    	}
	}

    printf("Начальное состояние:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (int gen = 1; gen <= GENERATIONS; gen++) {
        int **next_grid = (int **)malloc(SIZE * sizeof(int *));
        for (int i = 0; i < SIZE; i++) {
            next_grid[i] = (int *)malloc(SIZE * sizeof(int));
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int neighbors = count_neighbors(grid, i, j);
                if (grid[i][j] == 1) {
                    next_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
                } else {
                    next_grid[i][j] = (neighbors == 3) ? 1 : 0;
                }
            }
        }

        printf("\nПоколение %d:\n", gen);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", next_grid[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < SIZE; i++) {
            free(grid[i]);
        }
        free(grid);

        grid = next_grid;
    }

    for (int i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
