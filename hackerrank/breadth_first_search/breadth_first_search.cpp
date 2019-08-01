#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <algorithm>

#define DUMP_VECTOR(__v, __inc) \
    printf("["); \
    for (int __vi = 0; __vi < __v.size(); __vi++) { \
        printf("%d%s", __v.at(__vi) + __inc, (__vi + 1 < __v.size() ? ", " : "")); \
    } \
    printf("]\n");

using namespace std;

class Graph {
int _size;
vector<vector<int>*> _adjacents;

public:
    Graph(int n) {
        this->_size = n;
        
        while (n-- > 0) {
            this->_adjacents.push_back(new vector<int>());
        }
    }

    ~Graph() {
        for (int index = 0; index < this->_adjacents.size(); index++) {
            vector<int>* current = this->_adjacents[index];

            if (nullptr != current) {
                delete current;
            }
        }
    }

    void add_edge(int u, int v) {
        vector<int>* first = this->_adjacents[u];
        vector<int>* second = this->_adjacents[v];
        
        printf("[add_edge] (%d) %d <=> %d (%d)\n", u, u + 1, v + 1, v);

        if (first != nullptr) {
            first->push_back(v);
        }

        if (second != nullptr) {
            second->push_back(u);
        }
    }

    vector<int> shortest_reach(int start) {
        // Let's see if this work

        printf("[shortest_reach] Dumping adjacents.\n");
        for (int __i = 0; __i < this->_adjacents.size(); __i++) {
            vector<int> *v = this->_adjacents.at(__i);
            if (v != nullptr) {
                DUMP_VECTOR((*v), 1);
            }
        }

        const int edge_length = 6;
        queue<int> vertices;
        vector<int> result;
        unordered_set<int> visited;

        result.reserve(this->_size);
        result.assign(this->_size, -1);

        // Initialize our queue and our list of distances
        vertices.push(start);
        result[start] = 0;
        visited.insert(start);

        printf("[shortest_reach] staring from %d\n", start + 1);

        while (!vertices.empty()) {
            int current = vertices.front();
            vertices.pop();

            printf("[shortest_reach] current: %d, vertices left: %d\n", current + 1, vertices.size());
            
            vector<int>* node = this->_adjacents[current];
            if (nullptr == node) {
                continue;
            }

            // Get adjacents nodes to 'current'
            for (vector<int>::const_iterator it = node->begin();
                it != node->end();
                it++)
            {
                int vertex = *it;
                printf("[shortest_reach] current: %d => %d vertex.\n", current + 1, vertex + 1);

                // Has current node been visited?
                if (visited.find(vertex) == visited.end()) {
                    printf("[shortest_reach] vertex %d not visited.\n", vertex + 1);
                    vertices.push(vertex);

                    visited.insert(vertex);

                    result[vertex] = result[current] + edge_length;
                } else {
                    printf("[shortest_reach] vertex %d has been visited.\n", vertex + 1);
                }
            }

            // Dump result
            printf("[shortest_reach] results so far:\n");
            DUMP_VECTOR(result, 0);
        }
        
        return result;
    }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

