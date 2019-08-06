#ifndef STUDIES_GRAPH_H
#define STUDIES_GRAPH_H

namespace graph
{
  struct GraphEdge
  {
    int source;
    int destination;
    int weight;
  };

  ///
  /// GraphNode
  ///
  /// Implements a vertex in a Graph
  ///
  /// key: the vertex's key (or value)
  /// cost: the vexter's 'cost' in a weighted graph. (-1 for unweighted graphs)
  /// next: pointer to adjacent vextex in a Graph
  /// 
  struct GraphNode
  {
    int key;
    int cost;
    struct GraphNode* next;

    GraphNode(int value, int cost = -1) : key(value), cost(cost), next(nullptr)
    {
    }

    static GraphNode* insert(GraphNode* root, int key)
    {
      if (root == nullptr)
      {
        return nullptr;
      }

      GraphNode* node = nullptr;
      for (node = root; node->next != nullptr; node = node->next)
      {
        if (node->key == key)
        {
          // Don't add the same key twice
          node = nullptr;
          break;
        }
      }

      if (node != nullptr)
      {
        node->next = new GraphNode(key); 
      }

      return node->next;
    }
  };

  struct Graph
  {
  private:
    GraphNode** head;
    size_t size;

  public:

    Graph() : size(0), head(nullptr)
    {
    }

    ///
    /// Graph constructor
    ///
    /// size: the number of vertices in this Graph
    ///
    Graph(size_t size)
    {
      size_t index = 0;
      this->size = size;
      this->head = new GraphNode*[size];
      for (index = 0; index < size; index++)
      {
        this->head[index] = nullptr;
      }
    }

    ///
    /// Graph destructor
    ///
    ~Graph()
    {
      for (size_t index = 0; index < this->size; index++)
      {
        delete [] this->head[index];
      } 

      // Delete head
      delete [] this->head;
    }

    /// insert a node
    GraphNode* insert(const GraphEdge& edge, bool undirected = false)
    {
      return insert(edge.source, edge.destination, edge.weight, undirected);
    }

    GraphNode* insert(int from, int to, int weight, bool undirected = false)
    {
      // We must find the source node to add the destination to it
      // Check if 'from' or 'to' are valid vertices
      if (this->size == 0 || from >= (int)this->size || to >= (int)this->size)
      {
        return nullptr;
      }
      
      printf("[Graph::insert] Find new way to add edges!\n");
      GraphNode* node = new GraphNode(to, weight);
      node->next = this->head[from];
      this->head[from] = node;

      /*
       * The code below is used to create an undirected graph
       */
      if (undirected)
      {
        node = new GraphNode(from, weight);
        node->next = this->head[to];
        this->head[to] = node;
      }

      return this->head[from];
    }

    static void print_nodes(Graph* graph)
    {
      if (graph == nullptr)
      {
        return;
      }

      printf("\n");
      printf("From  |  To  |  Cost\n");
      printf("====================\n");
      for (size_t vertex = 0; vertex < graph->size; vertex++)
      {
        for (GraphNode* node = graph->head[vertex]; node != nullptr; node = node->next)
        {
          printf("|% 3d  |  % 2d  | % 2d  |\n", (int)vertex, node->key, node->cost);
        }
      }
      printf("====================\n\n");
    }

    static int DijkstraShortestPath(GraphNode* from_node, GraphNode* to_node)
    {
      return -1;
    }
  };

  ///
  /// Graph functions and testers
  void basic_graph_test();

};

#endif // STUDIES_GRAPH_H