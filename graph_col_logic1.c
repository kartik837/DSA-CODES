#include <stdio.h>
#include <stdlib.h>
int n, num_colors;
int neighbors[100][100];
int best_solution[100];
void graph_coloring(int node, int colors[]) {
    if (node == n)
    {
        for (int i = 0; i < n; i++)
        {
            best_solution[i] = colors[i];
        }
        return;
    }
    if (is_feasible(node, colors))
    {
        for (int color = 1; color <= num_colors; color++)
        {
            colors[node] = color;
            graph_coloring(node+1, colors);
        }
    }
}

int is_feasible(int node, int colors[])
{
    for (int i = 0; i < n; i++)
    {
        if (neighbors[node][i] && i < node && colors[node] == colors[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &neighbors[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    int colors[100];
    graph_coloring(0, colors);

    printf("The best solution found assigns colors: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", best_solution[i]);
    }
    printf("\n");

    return 0;
}

/*
0 0 0 0 1
0 0 1 0 1
0 1 0 1 0
0 0 1 0 1
1 1 0 1 0
*/
