class RingBuffer {
	public:
		RingBuffer();
		~RingBuffer();
		bool alloc(uint32_t numBuffers);
	
	protected:
		uint32_t mNumBuffers;
		uint32_t mLatestRead;
		uint32_t mLatestWrite;
		void** mBuffers;
		size_t mBufferSize;
		bool mReadOnce;
};
