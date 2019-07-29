/// ------------------------------
/// Template workaround
/// Original mempool.cpp
/// ------------------------------
#define OFFSET_PTR(__start, __end) (((unsigned char*)__end) - ((unsigned char*)__start))

template<typename _Ty>
memory_pool<_Ty>::memory_pool() :
    _pool_start(NULL), _pool_end(NULL), _pool_current(NULL), 
    _pool_size(0UL), _reset_request(false)
{
}

template<typename _Ty>
memory_pool<_Ty>::~memory_pool()
{
    destroy();
}

template<typename _Ty>
bool memory_pool<_Ty>::create(size_t size)
{
    const size_t actual_size = get_actual_size(size);

    // Pre-allocate memory for our structure
    this->_pool_size = size;
    this->_pool_start = malloc(actual_size);
    this->_pool_end = (reinterpret_cast<_Ty*>(this->_pool_start) + size);
    this->_pool_current = this->_pool_start;

    // Zero memory on start
    memset(this->_pool_start, 0x00, actual_size);

    return this->_pool_start;
}

template<class _Ty>
void memory_pool<_Ty>::destroy()
{
    printf("[memory_pool::destroy] Executing...\n");

    if (NULL != this->_pool_start)
    {
        free(this->_pool_start);
    }
    
    this->_pool_current = 
    this->_pool_start = 
    this->_pool_end = NULL;
}

template<typename _Ty>
_Ty* memory_pool<_Ty>::allocate(size_t bs, size_t* usable)
{
    _Ty* current = reinterpret_cast<_Ty*>(this->_pool_current);

    if (this->_reset_request)
    {
        printf("request_reset is true. O_O\n");
        return NULL;
    }

    if ( !is_available(bs, usable) )
    {
        return NULL;
    }

    _Ty *return_me = reinterpret_cast<_Ty*>(this->_pool_current);
    current += bs;

    this->_pool_current = current;

    return return_me;
}

template<typename _Ty>
_Ty* memory_pool<_Ty>::deallocate(const _Ty* ref, size_t size)
{
    /*
    size_t actual_size = get_actual_size(size);
    if ((ref + actual_size) >= this->_pool_end || ref < this->_pool_start)
    {
        // Some serious SISSEGV will be raised here
        // Just to scare the deallocator.
        raise(SIGSEGV);
    }

    // This is obviusly way too promiscuous, but this is the deal for current version
    // This routine sincerely hopes that the deallocator knows what he/she
    // is doing.
    memset(ref, 0x00, size);
    
    return ref;
    */

   return NULL;
}

template<typename _Ty>
bool memory_pool<_Ty>::is_available(size_t bs, size_t* usable)
{
    unsigned int available = 0;
    
    if (NULL == this->_pool_start)
    {
        return false;
    }
    
    available = OFFSET_PTR(this->_pool_current, this->_pool_end);
    if (NULL != usable)
    {
        *usable = available; 
    }

    return (bs <= available);
}

template<typename _Ty>
size_t memory_pool<_Ty>::get_available_memory() const
{
    return OFFSET_PTR(this->_pool_current, this->_pool_end);
}

template<typename _Ty>
size_t memory_pool<_Ty>::size() const
{
    return this->_pool_size;
}

// Private methods
template<typename _Ty>
const size_t memory_pool<_Ty>::get_actual_size(size_t base) const
{
    return (sizeof(_Ty) * base);
}

template<typename _Ty>
void memory_pool<_Ty>::request_reset()
{
    this->_reset_request = true;
}

template<typename _Ty>
bool memory_pool<_Ty>::reset()
{
    if (!this->_reset_request)
    {
        return false;
    }

    memset(this->_pool_start, 0x00, get_actual_size(this->_pool_size));

    this->_reset_request = false;

    return true;
}