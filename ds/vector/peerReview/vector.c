/*********************************/
/*    Data Structures            */
/*    Vector                     */       
/*    Author :Guy Cohen Zedek    */
/*    Reviewed By:               */
/*    Date:      /11/2019        */
/*                               */
/*********************************/

#include <stdlib.h> /* malloc */
#include <assert.h> /* assert */
#include <string.h> /* memmove */

#include "vector.h" /* API functions */

struct Vector
{
    void *start;
    size_t size;
    size_t capacity;
    size_t element_size;
};

vector_t* VectorCreate(size_t element_size, size_t capacity)
{
    vector_t* myvector = (vector_t*) malloc(sizeof(vector_t));
    if (NULL == myvector)
    {
        return NULL;
    }
    
    myvector -> start = (void*) malloc(element_size*capacity);
    if (NULL == myvector -> start)
    {
        return NULL;
    }
    
    myvector -> size = 0;
    myvector -> capacity = capacity;
    myvector -> element_size = element_size;
    
    return myvector;
}

/* This function destroy the vector */
void VectorDestroy(vector_t *myvector)
{
    assert(NULL != myvector);
    
    free(myvector -> start); myvector -> start = NULL;
    free(myvector); myvector = NULL;
}

/* This function push new item at the end of the vector */
int VectorPushBack(vector_t *myvector, const void* data)
{
    assert(NULL != myvector);
    
    if (myvector -> size == VectorCapacity(vector))
    {
        if (1 == VectorReserve(myvector, (myvector -> capacity)*2))
        {
            return 1;
        }
    }
    
    memmove(((char*)(myvector -> start) + (myvector -> size * myvector -> element_size))
                                                       , data, myvector -> element_size);
    ++(myvector -> size);
    
    return 0;
}

/* This function pops the last item in the vector */
void VectorPopBack(vector_t *myvector)
{
    assert(NULL != myvector);
    
    if (0 == myvector -> size)
    {
        return;
    }
    
    --(myvector -> size);
    
    if (myvector -> size == (size_t)((myvector -> capacity)/4))
    {
        VectorReserve(myvector, (size_t)((myvector -> capacity)/2));
    }
}

/* This function resizing the vector size as needed with extra space */
int VectorReserve(vector_t *myvector, size_t new_capacity)
{
    assert(NULL != myvector);
    
    if (0 >= new_capacity)
    {
        return 1;
    }
    myvector -> start = (void*) realloc(myvector -> start, (myvector -> element_size)*new_capacity);
    if (NULL == myvector -> start)
    {
        return 1;
    }
    
    myvector -> capacity = new_capacity;
    
    return 0; 
}

/* This function return the total size of the vetor */
size_t VectorCapacity(const vector_t *myvector)
{
    assert(NULL != myvector);

    return myvector -> capacity;
}

/* This function return the current number of elements in the vetor */
size_t VectorSize(const vector_t *myvector)
{
    assert(NULL != myvector);
    
    return myvector -> size;
}

/* This function return specific item address to the user */
void* VectorGetItemAddress(const vector_t *myvector, int position)
{
    assert(NULL != myvector);
    
    if (((size_t)position - 1) > myvector -> size)
    {
        return NULL;
    }
    
    return ((char*)(myvector -> start) + myvector -> element_size*(position - 1));
}
