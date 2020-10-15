#include "RingBuffer.h"
#include <iostream>

using namespace std;

inline RingBuffer::RingBuffer() 
{
	cout << "inside constructor" << endl;
	mBuffers = NULL;
	maxBuffers = 10;
	mSize = 0;
};

RingBuffer::~RingBuffer() 
{
	
};

bool RingBuffer::alloc(uint32_t numBuffers, size_t size) 
{

	if (mBuffers == NULL) 
	{
		const size_t bufferListSize = numBuffers * sizeof(void*);
		mBuffers = (void**)malloc(bufferListSize);
		memset(mBuffers, 0, bufferListSize);
	}
	return true;
};
 

void R

void* RingBuffer::peek(string cmd)
{
	return NULL;
};

void RingBuffer::pop() {
	mBuffers[0] = NULL;
};
