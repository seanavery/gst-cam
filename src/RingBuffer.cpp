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
	// free all memory allocation
};

bool RingBuffer::alloc(uint32_t numBuffers, size_t size) 
{
	if (mBuffers == NULL) 
	{
		cout << "creating mBuffers" << endl; 
		const size_t bufferListSize = numBuffers * sizeof(void*);
		cout << "bufferListSize" << bufferListSize << endl;
		mBuffers = (void**)malloc(bufferListSize);
		memset(mBuffers, 0, bufferListSize);
	}
	for (uint32_t n=0; n < numBuffers; n++)
	{
		mBuffers[n] = malloc(size);
	}
	return true;
};
 
void* RingBuffer::peek(string cmd)
{
	return NULL;
};

void RingBuffer::pop() {
	mBuffers[0] = NULL;
};
