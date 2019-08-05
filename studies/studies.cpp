#include <iostream>

#include "algorithms/algorithms.hpp"
#include "linked_lists/linked_lists.hpp"
#include "hash_table/hash_table.hpp"

int main(int argc, char *argv[])
{
	size_t index;
	const int keys_size = 11;
	const char *keys[keys_size] = {
		"jo", "guto", "ique", "nando", "botelho",
		"brigite", "bianca", "beatriz", "basilio",
		"papai noel", "testando"
	};

	hash_table::sc_hash_table_t table = hash_table::sc_hash_table_t();
	for (index = 0; index < keys_size; index++) 
	{
		table.put(keys[index], rand() / 1000);
	}

	for (index = 0; index < keys_size; index++)
	{
		printf("[main] Get value for key: '%s': %d\n", 
			keys[index], table.get(keys[index]));
	}

	return 0;
}