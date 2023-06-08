#include <bits/stdc++.h>
using namespace std;

// This function prints the edges of the MST and returns the cost of the minimum spanning tree.
int MST(vector<vector<int>> &graph, int start)
{
  cout << "Edge : Weight" << endl;
  int n = graph.size();
  int vertex1, vertex2;
  int minCost = 0;
  int remainingVertices = n;
  int totalCost = 0;
  vector<bool> completed(n, false); // Create an array to record if a vertex is visited or unvisited.

  // Setting the visited vertex to true.
  completed[start] = true;
  remainingVertices -= 1;

  // Repeat this code until all the vertices are visited.
  while (remainingVertices > 0)
  {
    minCost = INT_MAX;
    // These two loops keeps repeating through the adjacency matrix to find the edge with a minimum cost.
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++) // j is always greater than i.
      {
        if ((graph[i][j] < minCost) && ((!completed[i] && completed[j]) || (!completed[j] && completed[i])) && (graph[i][j] != 0))
        {
          vertex1 = i;
          vertex2 = j;
          minCost = graph[i][j];
        }
      }
    }

    // Updates the current status on the remainingVertices variable and completed array.
    if (completed[vertex1] == false)
    {
      completed[vertex1] = true;
      remainingVertices -= 1;
    }
    if (completed[vertex2] == false)
    {
      completed[vertex2] = true;
      remainingVertices -= 1;
    }

    // Print the output.
    cout << vertex1 << " - " << vertex2 << " : " << graph[vertex1][vertex2] << endl;
    totalCost += minCost;
  }
  return totalCost;
}

int main()
{
  // Initialize the graph with the suitable values.
  vector<vector<int>> graph = {{INT_MAX, 3, INT_MAX, INT_MAX, INT_MAX, 1}, {3, INT_MAX, 2, 1, 10, INT_MAX}, {INT_MAX, 2, INT_MAX, 3, INT_MAX, 5}, {INT_MAX, 1, 3, INT_MAX, 5, INT_MAX}, {INT_MAX, 10, INT_MAX, 5, INT_MAX, 4}, {1, INT_MAX, 5, INT_MAX, 4, INT_MAX}};
  cout << "Total cost of the MST is : " << MST(graph, 0);
}