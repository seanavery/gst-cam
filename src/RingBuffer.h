#include <string>
using namespace std;
class RingBuffer {
	public:
		RingBuffer();
		~RingBuffer();
		bool alloc(uint32_t numBuffers, size_t size);
		void pop();
		void* peek(string command);
	protected:
		// queue structure
		void** mBuffers;
		uint32_t maxBuffers;
		uint32_t mNumBuffers;
		size_t mSize;
};
