// Dijkstra's Algorithm in C

#include <bits/stdc++.h>

using namespace std;


#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start) {

  int cost[MAX][MAX], distance[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY; //if no direct path exists
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    visited[i] = 0;
  }

  distance[start] = 0; //assigning distance of source vertex
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;

    for (i = 0; i < n; i++) //edge relaxation
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
}
int main() {
  int i, j, n, u;
  n = 7;

  int Graph[MAX][MAX] = { {0,0,1,2,0,0,0},
                          {0,0,2,0,0,3,0},
                          {1,2,0,1,3,0,0},
                          {2,0,1,0,0,0,1},
                          {0,0,3,0,0,2,0},
                          {0,3,0,0,2,0,1},
                          {0,0,0,1,0,1,0}
                        };

  u = 0;  //source
  Dijkstra(Graph, n, u);

  return 0;
}
