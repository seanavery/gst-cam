#include "RingBuffer.h"
#include <iostream>

using namespace std;

inline RingBuffer::RingBuffer() 
{
	cout << "inside constructor" << endl;
	mBuffers = NULL;
	mBufferSize = 0;
	mNumBuffers = 0;
	mReadOnce = true;
	mLatestRead = 0;
	mLatestWrite = 0;
};

RingBuffer::~RingBuffer() 
{
	cout << "inside destructor" << endl;
	freeBuff();
	if (mBuffers != NULL)
	{
		free(mBuffers);
		mBuffers = NULL;
	}
};

bool RingBuffer::alloc(uint32_t numBuffers, size_t size) 
{
	freeBuff();
	if (mBuffers != NULL && mNumBuffers != numBuffers)
	{
		free(mBuffers);
		mBuffers = NULL;
	}
	if (mBuffers == NULL)
	{
		cout << "allocating for real" << endl;
		size_t bufferListSize = numBuffers * sizeof(void*);
		cout << "bufferListSize " << bufferListSize << endl;
		mBuffers = (void**)malloc(bufferListSize);
		memset(mBuffers, 0, bufferListSize);
	}
	for (uint32_t n=0; n < numBuffers; n++)
	{
		mBuffers[n] = malloc(size);
	}
	mNumBuffers = numBuffers;
	mBufferSize = size;
	return true;
};

void RingBuffer::freeBuff() 
{
	if (!mBuffers || mNumBuffers == 0) 
	{
		return;
	}
	for (uint32_t n=0; n < mNumBuffers; n++) 
	{
		mBuffers[n] = NULL;
	}
};

void* RingBuffer::peek(string cmd)
{
	if (!mBuffers || mNumBuffers == 0)
	{
		return NULL;
	}
	int bufferIndex = -1;
	return NULL;
};

void* RingBuffer::next(string cmd) 
{
	
	return NULL;
};
