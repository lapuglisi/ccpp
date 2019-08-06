#include <iostream>

#include "algorithms/algorithms.h"
#include "linked_list/linked_list.h"
#include "hash_table/hash_table.h"
#include "tree/tree.h"
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

  // Try to sort an array with merge_sort
  int numbers[] = {5, 4, 1, 10, 12, 7, 9, 3, 2, 8, 11};
  int numbers_size = sizeof(numbers)/sizeof(numbers[0]);

  algorithms::sorting::merge_sort(numbers, numbers_size);

  printf("\n");
  printf("[sorting] array after sorting:\n");
  printf("[");
  for (int index = 0; index < numbers_size; index++)
  {
    printf("%d%s", numbers[index], (index + 1 < numbers_size ? ", " : ""));
  }
  printf("]\n");

	return 0;
}