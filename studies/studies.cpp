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

  printf("\n");
  printf("[algorithms] find LIS:\n");
  int lis = algorithms::LIS(numbers, numbers_size);
  printf("LIS of array is %d.\n", lis);

  algorithms::sorting::merge_sort(numbers, numbers_size);

  printf("\n");
  printf("[sorting] array after sorting:\n");
  printf("[");
  for (int index = 0; index < numbers_size; index++)
  {
    printf("%d%s", numbers[index], (index + 1 < numbers_size ? ", " : ""));
  }
  printf("]\n");

  printf("\n");
  printf("[shortest_path] Find 9 in a r x c Grid.\n");
  const size_t rows = 5;
  const size_t cols = 5;
  int grid[rows][cols] = 
  {
    0, 0, 0, 0, 1, // <-- begin at (0, 1)
    0, 1, 1, 0, 0, 
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
    1, 1, 0, 0, 9  // <-- ends at (4, 3)
  };
  // Path must be:
  // (0, 1) -> (0, 2) -> (0, 3) -> (1, 3) ...
  // (1, 4) -> (2, 4) -> (3, 4) -> (4, 4)

  int shortest = algorithms::find_shortest_path<rows, cols>(grid, 0, 1, 9);
  printf("[find_shortest_path] shortest path is %d.\n", shortest);

  printf("\n");
  const char* s1 = "abababddd";
  const char* s2 = "efefefddd";
  int lcs = algorithms::LCS(s1, s2, 9, 9);
  printf("[algorithm] lcs of strings '%s' and '%s' is %d.\n", s1, s2, lcs);

	return 0;
}