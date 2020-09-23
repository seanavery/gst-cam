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
	flush();
};

bool RingBuffer::alloc(uint32_t numBuffers, size_t size) 
{
	
	return true;
};

void* RingBuffer::peek(string cmd)
{
	return NULL;
};

void RingBuffer::flush() {
	
};
