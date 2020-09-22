#include "RingBuffer.h"
#include <iostream>

using namespace std;

inline RingBuffer::RingBuffer() {
	cout << "inside constructor" << endl;
	mBuffers = NULL;
	mBufferSize = 0;
	mNumBuffers = 0;
	mReadOnce = true;
	mLatestRead = 0;
	mLatestWrite = 0;
};

RingBuffer::~RingBuffer() {
	cout << "inside destructor" << endl;
};

bool RingBuffer::alloc(uint32_t numBuffers) {
	cout << "allocating memory" << endl;
	return true;
};
