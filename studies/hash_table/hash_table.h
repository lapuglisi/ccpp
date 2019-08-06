#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <memory.h>

namespace hash_table
{
    ///
    /// Separate chaining Linked List
    ///
    struct LinkedList
    {
        int data;
        const char* key;
        struct LinkedList* next;

        LinkedList(const char *hash_key, int data) : data(data), 
            key(strdup(hash_key))
        {
        }

        ~LinkedList()
        {
            if (this->key != nullptr)
            {
                free((void*)this->key);
            }
        }

    };
    
    // Consider using template
    struct HashTable
    {
    private:
        static const size_t default_bucket_size_ = 19;
        static const unsigned int hash_initial_value_ = 1977;
        static const unsigned int hash_modifier_ = 39;

        size_t size_;
        LinkedList** bucket_;

        unsigned int hash(const char *key);

    public:
        HashTable(int size = default_bucket_size_)
        {
            this->size_ = (size <= 0 ? default_bucket_size_ : size);
            this->bucket_ = new LinkedList*[this->size_];
            memset(this->bucket_, 0x00, this->size_);
        }

        ~HashTable()
        {
            if (this->bucket_ != nullptr)
            {
                // WARNING! Change this
                for (size_t slot = 0; slot < this->size_; slot++)
                {
                    LinkedList* node = this->bucket_[slot];
                    while (node != nullptr)
                    {
                        LinkedList* next = node->next;
                        delete node;
                        node = node->next;
                    }
                }
                delete [] this->bucket_;
            }
            this->bucket_ = nullptr;
        }

        void put(const char* /* key */, int /* value */);
        int get(const char* /* key */); 
        void remove(const char* /* key */);
        void clear();

    };
}

#endif // HASH_TABLE_H