#include <iostream>
#include <list>
using namespace std;

struct Node
{
  // A node will 2 entities
  // 1. data type int called label
  int label;
  // 2. a int type list called neighbours
  int neighbours[10] = {0};
};

struct Graph
{
  // graph will have an array of type "node" with length specified by n
  int n = 9;
  Node *nodes = new Node[n];

  void intializenodes()
  {
    // iterate through the nodes and assign labels
    for (int i = 0; i < n; i++)
    {
      nodes[i].label = i;
    }
  }

  void addedge(int u, int v) // For undirected graphs
  {
    // select node u and push v into u's neighbour
    for (int i = 0; i < 10; i++)
    {
      if (nodes[u].neighbours[i] == 0 || nodes[u].neighbours[i] == v)
      {
        nodes[u].neighbours[i] = v;
        break;
      }
    }

    // select node v and push u into v's neighbour
    for (int i = 0; i < 10; i++)
    {
      if (nodes[v].neighbours[i] == 0 || nodes[v].neighbours[i] == u)
      {
        nodes[v].neighbours[i] = u;
        break;
      }
    }
  }

  // void addedge(int u, int v)  // For directed graphs
  // {
  //   // select node u and push v into u's neighbour
  //   for (int i = 0; i < 10; i++)
  //   {
  //     if (nodes[u].neighbours[i] == 0 || nodes[u].neighbours[i] == v)
  //     {
  //       nodes[u].neighbours[i] = v;
  //       break;
  //     }
  //   }
  // }

  void print()
  {
    // lets iterate through each node and print its neighbours
    for (int i = 1; i < n; i++)
    {
      cout << nodes[i].label << "-->";
      for (int j = 0; j < 10; j++)
      {
        if (nodes[i].neighbours[j] != 0)
          cout << nodes[i].neighbours[j] << ",";
        else
          break;
      }
      cout << "\b " << endl;
    }
  }
};

int main()
{
  Graph *g = new Graph;
  g->intializenodes();
  // add edges for the graphs here.
  g->addedge(1, 2);
  g->addedge(1, 3);
  g->addedge(1, 4);
  g->addedge(1, 5);
  g->addedge(2, 3);
  g->addedge(2, 6);
  g->addedge(4, 6);
  g->addedge(4, 7);
  g->addedge(4, 8);
  g->addedge(5, 6);
  g->addedge(5, 7);
  g->addedge(5, 8);
  // print the graph adjaceny list
  g->print();
  delete g;
}