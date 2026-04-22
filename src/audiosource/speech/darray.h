#ifndef SOLOUD_SRC_AUDIOSOURCE_SPEECH_DARRAY_H_
#define SOLOUD_SRC_AUDIOSOURCE_SPEECH_DARRAY_H_

class darray
{
protected:
	char *mData;
	int mUsed;
	int mAllocated;
	int mAllocChunk;
public:
	darray();
	~darray();
	void clear();
	char *getDataInPos(int aPosition);
	void put(int aData);
	int getSize() const { return mUsed; }
	char *getData() { return mData; } 
};

#endif  // SOLOUD_SRC_AUDIOSOURCE_SPEECH_DARRAY_H_