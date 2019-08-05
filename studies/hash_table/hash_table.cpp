#include "hash_table.hpp"

namespace hash_table
{
    // A simple hashing algorithm
    unsigned int sc_hash_table::hash(const char *key)
    {
        unsigned int hash_value = hash_initial_value;
        for (const char* p = key; *p != 0x00; p++)
        {
            hash_value = (hash_value * hash_modifier) + (*p); 
        }

        return (hash_value % this->_size);
    }

    void sc_hash_table::put(const char* key, int value)
    {
        unsigned int slot = hash(key);

        if (this->_bucket[slot] == nullptr)
        {
            this->_bucket[slot] = new sc_linked_list_t(key, value);
        }
        else
        {
            sc_linked_list_t* node;
            for (node = this->_bucket[slot]; node->next != nullptr; node = node->next);
            node->next = new sc_linked_list_t(key, value);
        }
    }

    int sc_hash_table::get(const char* key)
    {
        unsigned int slot = hash(key);
        
        // Iterate through the items in slot to find our corresponding item
        sc_linked_list_t* node;
        for (node = this->_bucket[slot]; 
            node != nullptr && strcmp(node->key, key); node = node->next);

        return (node == nullptr ? -1 : node->data);
    }

    void sc_hash_table::remove(const char* key)
    {
        printf("[sc_hash_table::remove]\n");
    }
}
