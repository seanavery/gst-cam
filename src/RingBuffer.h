#include <string>
using namespace std;
class RingBuffer {
	public:
		RingBuffer();
		~RingBuffer();
		bool alloc(uint32_t numBuffers, size_t size);
		void freeBuff();
		void* next(string command);
		void* peek(string command);
	protected:
		uint32_t mNumBuffers;
		uint32_t mLatestRead;
		uint32_t mLatestWrite;
		void** mBuffers;
		size_t mBufferSize;
		bool mReadOnce;
};
