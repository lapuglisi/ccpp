#include <iostream>
#include "graph.h"

namespace graph
{

void basic_graph_test()
{
  /// Create a Graph here
  /// Let us use weigths from 1 to 7

  const int num_edges = 9;
  GraphEdge edges[num_edges] = {
    {0, 1, 1}, {0, 3, 2}, // 0 [1]-> 1, 0 [3]-> 4
    {1, 2, 4}, {1, 3, 5}, // 1 [4]-> 2, 1 [1]-> 3
    {2, 4, 3},            // 2 [3]-> 4
    {3, 5, 4},            // 3 [4]-> 5
    {4, 7, 7},            // 4 [7]-> 7
    {5, 6, 2},            // 5 [2]-> 6
    {6, 7, 3}             // 6 [3]-> 7
    // Notice that for path 0 -> 1 -> 2 -> 4 -> 7, weight is 15;
    // for path 0 -> 3 -> 5 -> 6 -> 7, weight is 11
    // Therefore, when calculating the shortest path,
    // the second path must be chosen.
  };

  const int vertices = 8; // 0 to 7
  Graph root(vertices);
  for (int edge = 0; edge < num_edges; edge++)
  {
    root.insert(edges[edge] /*, undirected = false */);
  }

  // Dump graph data
  Graph::print_nodes(&root);
}


}