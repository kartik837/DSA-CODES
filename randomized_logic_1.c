#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_CITIES 10
#define MAX_DISTANCE 100

typedef struct {
    int x, y;
} city;

int get_distance(city c1, city c2) {
    int dx = c1.x - c2.x;
    int dy = c1.y - c2.y;
    return (int) sqrt(dx*dx + dy*dy);
}

int main() {
    srand(time(NULL));

    int n_cities = 5;
    city cities[MAX_CITIES];

       for (int i = 0; i < n_cities; i++) {
        cities[i].x = rand() % MAX_DISTANCE;
        cities[i].y = rand() % MAX_DISTANCE;
    }


    printf("Generated cities:\n");
    for (int i = 0; i < n_cities; i++) {
        printf("City %d: (%d, %d)\n", i+1, cities[i].x, cities[i].y);
    }


    int iterations = 10000;
    int best_distance = MAX_DISTANCE * MAX_CITIES;
    int route[MAX_CITIES];

    for (int i = 0; i < iterations; i++) {

        int route[MAX_CITIES];
        for (int j = 0; j < n_cities; j++) {
            route[j] = j;
        }
        for (int j = 0; j < n_cities; j++) {
            int k = rand() % n_cities;
            int temp = route[j];
            route[j] = route[k];
            route[k] = temp;
        }


        int distance = 0;
        for (int j = 0; j < n_cities-1; j++) {
            distance += get_distance(cities[route[j]], cities[route[j+1]]);
        }
        distance += get_distance(cities[route[n_cities-1]], cities[route[0]]);


        if (distance < best_distance) {
            best_distance = distance;
            for (int j = 0; j < n_cities; j++) {
                route[j] = route[j];
            }
        }
    }


    printf("Best route found:\n");
    for (int i = 0; i < n_cities; i++) {
        printf("%d ", route[i]+1);
    }
    printf("\nBest distance: %d\n", best_distance);

    return 0;
}

