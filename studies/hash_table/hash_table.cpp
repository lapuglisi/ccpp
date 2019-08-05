#include "hash_table.h"

namespace hash_table
{
    // A simple hashing algorithm
    unsigned int HashTable::hash(const char *key)
    {
        unsigned int hash_value = hash_initial_value_;
        for (const char* p = key; *p != 0x00; p++)
        {
            hash_value = (hash_value * hash_modifier_) + (*p); 
        }

        return (hash_value % this->size_);
    }

    void HashTable::put(const char* key, int value)
    {
        unsigned int slot = hash(key);

        if (this->bucket_[slot] == nullptr)
        {
            this->bucket_[slot] = new LinkedList(key, value);
        }
        else
        {
            LinkedList* node;
            for (node = this->bucket_[slot]; node->next != nullptr; node = node->next);
            node->next = new LinkedList(key, value);
        }
    }

    int HashTable::get(const char* key)
    {
        unsigned int slot = hash(key);
        
        // Iterate through the items in slot to find our corresponding item
        LinkedList* node;
        for (node = this->bucket_[slot]; 
            node != nullptr && strcmp(node->key, key); node = node->next);

        return (node == nullptr ? -1 : node->data);
    }

    void HashTable::remove(const char* key)
    {
        printf("[HashTable::remove]\n");
    }
}
