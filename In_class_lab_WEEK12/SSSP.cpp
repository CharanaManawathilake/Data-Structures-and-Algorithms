#include <bits/stdc++.h>
using namespace std;

// Finds the index that has a min distance from the starting node.
int minDist(vector<int> dist, vector<bool> visited)
{
  int minDist = INT_MAX;
  int minIndex = -1;
  int n = dist.size();
  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && dist[i] < minDist)
    {
      minDist = dist[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void dijkstra(int start, vector<vector<int>> &mat, vector<int> &dist)
{
  int n = mat.size();
  vector<bool> visited(n, false); // Maintain a single boolean list to denote what nodes are visited and what are not.
  dist[start] = 0;                // Initialize the starting node to zero.

  for (int i = 0; i < n - 1; i++)
  {
    int u = minDist(dist, visited); // Find the unvisited node that has a min distance from the current node
    visited[u] = true;              // Mark that node as visited.
    for (int v = 0; v < n; v++)
    {
      if ((!visited[v]) && (mat[u][v] != 0) && (dist[u] != INT_MAX) && (dist[u] + mat[u][v] < dist[v]))
      {
        dist[v] = dist[u] + mat[u][v]; // Finds the minimum distance to that node from the starting node.
      }
    }
  }
}

// This function calculates the average time taken.
int AvgTime(int start, vector<vector<int>> &mat)
{
  int n = mat.size();
  vector<int> dist(n, INT_MAX);
  dijkstra(start, mat, dist); // Calls the dijkstras algorithm.
  int totalTime = 0;
  for (int i = 0; i < dist.size(); i++) // Calculates the total time taken to traverl to all the nodes in the graph.
  {
    totalTime += dist[i];
  }
  return totalTime / (n - 1);
}

int main()
{
  vector<vector<int>> mat = {{0, 10, 0, 0, 15, 5},
                             {10, 0, 10, 30, 0, 0},
                             {0, 10, 0, 12, 5, 0},
                             {0, 30, 12, 0, 0, 20},
                             {15, 0, 5, 0, 0, 0},
                             {5, 0, 0, 20, 0, 0}};
  for (int i = 0; i < mat.size(); i++) // Returns the average time for all the starting nodes.
    cout << "Average Time from City" << i << ' ' << AvgTime(i, mat) << endl;
  return 0;
}
