// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define arrays to store adjacency lists
    int *adj[5];
    int sizes[5] = {2, 2, 2, 2, 1}; // Sizes of each adjacency list

    // Allocate memory for each adjacency list
    for (int i = 0; i < 5; i++)
    {
        adj[i] = (int *)malloc(sizes[i] * sizeof(int));
    }

    // Add edges to the adjacency list
    adj[0][0] = 1;
    adj[0][1] = 2;
    adj[1][0] = 2;
    adj[1][1] = 3;
    adj[2][0] = 3;
    adj[2][1] = 4;
    adj[3][0] = 4;
    adj[3][1] = 5;
    adj[4][0] = 5;

    // Free allocated memory
    printf("Freeing allocated memory...\n");
    for (int i = 0; i < 5; i++)
    {
        free(adj[i]);
    }

    return 0;
}
