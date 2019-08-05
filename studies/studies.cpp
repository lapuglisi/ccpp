#include <iostream>

#include "algorithms/algorithms.h"
#include "linked_lists/linked_lists.h"
#include "hash_table/hash_table.h"
#include "trees/trees.h"
#include "graph/graph.h"

int main(int argc, char *argv[])
{
	size_t index;
	const int keys_size = 11;
	const char *keys[keys_size] = {
		"jo", "guto", "ique", "nando", "botelho",
		"brigite", "bianca", "beatriz", "basilio",
		"papai noel", "testando"
	};

	hash_table::HashTable table = hash_table::HashTable();
	for (index = 0; index < keys_size; index++) 
	{
		table.put(keys[index], rand() / 1000);
	}

	for (index = 0; index < keys_size; index++)
	{
		printf("[main] Get value for key: '%s': %d\n", 
			keys[index], table.get(keys[index]));
	}

  printf("\n\n");
  printf("[trees::test_binary_tree]\n");
  trees::test_binary_tree();

  printf("\n");
  printf("[graph::basic_graph_test]\n");
  graph::basic_graph_test();

	return 0;
}