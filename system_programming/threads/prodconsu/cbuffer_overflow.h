#ifndef __CBUFFER_OVERFLOW_H__
#define __CBUFFER_OVERFLOW_H__

typedef struct CBufferOverFlow cbuffer_t;

cbuffer_t *CBufferCreate(size_t capacity);
void CBufferDestroy(cbuffer_t *cb);
int CBufferRead(cbuffer_t *cb);
void CBufferWrite(cbuffer_t *cb ,int num_to_insert);
size_t CBufferFreeSpace(const cbuffer_t *cb);

#endif