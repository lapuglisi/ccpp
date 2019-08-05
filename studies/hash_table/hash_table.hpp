#pragma once

#include <iostream>
#include <memory.h>
#include "../linked_lists/linked_lists.hpp"

namespace hash_table
{
    typedef struct sc_linked_list
    {
        int data;
        const char* key;
        struct sc_linked_list* next;

        sc_linked_list(const char *hash_key, int data)
        {
            this->data = data;
            this->key = strdup(hash_key);
        }

        ~sc_linked_list()
        {
            if (this->key != nullptr)
            {
                free((void*)this->key);
            }
        }

    } sc_linked_list_t;
    // Consider using template
    typedef struct sc_hash_table
    {
    private:
        static const size_t default_bucket_size = 19;
        static const unsigned int hash_initial_value = 1977;
        static const unsigned int hash_modifier = 39;

        int _size;
        sc_linked_list_t** _bucket;

        unsigned int hash(const char *key);

    public:
        sc_hash_table(int size = default_bucket_size)
        {
            this->_size = (size <= 0 ? default_bucket_size : size);
            this->_bucket = new sc_linked_list_t*[this->_size];
            memset(this->_bucket, 0x00, this->_size);
        }

        ~sc_hash_table()
        {
            if (this->_bucket != nullptr)
            {
                // WARNING! Change this
                for (size_t slot = 0; slot < this->_size; slot++)
                {
                    sc_linked_list_t* node = this->_bucket[slot];
                    while (node != nullptr)
                    {
                        sc_linked_list_t* next = node->next;
                        delete node;
                        node = node->next;
                    }
                }
                delete [] this->_bucket;
            }
            this->_bucket = nullptr;
        }

        void put(const char* /* key */, int /* value */);
        int get(const char* /* key */); 
        void remove(const char* /* key */);
        void clear();

    } sc_hash_table_t;
}