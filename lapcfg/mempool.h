#pragma once

#include <stdio.h>

#include <stdlib.h>
#include <memory.h>
#include <signal.h>

namespace lap
{
namespace memory
{

template<class _Ty = void>
class memory_pool
{
private:
    /*
    typedef struct _memory_pool_data
    {
        _Ty *address;
        size_t size;
        _memory_pool_data* next;
    } memory_pool_data_t;
    */

    size_t _pool_size;

    void* _pool_start;
    void* _pool_end;
    void* _pool_current;

    volatile bool _reset_request;

    const size_t get_actual_size(size_t) const;

public:
    memory_pool();
    ~memory_pool();

    bool create(size_t);
    void request_reset();
    bool reset();

    void destroy();
    bool is_available(size_t, size_t* usable = NULL);
    size_t get_available_memory() const;
    _Ty* allocate(size_t, size_t* usable = NULL);
    _Ty* deallocate(const _Ty*, size_t);

    size_t size() const;
};

#include ".mempool.cpp"

}
}