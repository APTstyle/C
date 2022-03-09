#include <stdio.h>
#define INFIN 2147483647
void input(int cities[9][9], int waynum) {
    int i, city1, city2, way;
    for (i = 0; i < waynum; i++) {
        scanf("%d,%d,%d", &city1, &city2, &way);
        cities[city1 - 1][city2 - 1] = way;
        cities[city2 - 1][city1 - 1] = way;
    }
}

void way(int result[40320][9], int *times, int passed[9], int inside, int citynum) {
    int i;
    for (i = 1; i < citynum; i++) {
        if (passed[i] == 1) {
            continue;
        }
        passed[i] = 1;
        result[*times][inside - 1] = i;
        if (inside == citynum - 1) {
            *times += 1;
        }
        else {
            way(result, times, passed, inside + 1, citynum);
        }
        passed[i] = 0;
    }
}

void treat(int result[40320][9], int times, int citynum) {
    int i, j;
    for (i = 0; i < times; i++) {
        for (j = 0; j < citynum - 1; j++) {
            if (result[i][j] == 0) {
                result[i][j] = result[i - 1][j];
            }
        }
    }
}

void compute(int cities[9][9], int citynum) {
    int result[40320][9] = {0}, times = 0, passed[9] = {0};
    way(result, &times, passed, 1, citynum);
    treat(result, times, citynum);
    int min = INFIN, i;
    for (i = 0; i < times; i++) {
        int answer = cities[0][result[i][0]], j;
        for (j = 0; j < citynum - 2; j++) {
            int waylength = cities[result[i][j]][result[i][j + 1]];
            answer += waylength;
            if (waylength == 0) {
                answer = INFIN;
                break;
            }
        }
        if (answer < min) {
            min = answer;
        }
    }
    printf("%d\n", min);
}

int main() {
    int cities[9][9] = {0};
    int citynum, waynum;
    scanf("%d,%d", &citynum, &waynum);
    input(cities, waynum);
    compute(cities, citynum);
    return 0;
}