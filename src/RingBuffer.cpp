#include "RingBuffer.h"
#include <iostream>

using namespace std;

inline RingBuffer::RingBuffer() {
	cout << "inside constructor" << endl;
};

RingBuffer::~RingBuffer() {
	cout << "inside destructor" << endl;
};

bool RingBuffer::alloc(uint32_t numBuffers) {
	cout << "allocating memory" << endl;
	return true;
};
