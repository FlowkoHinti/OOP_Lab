#include "Buffer.h"
#include <iostream>
#include <vector>


using namespace std;

class BuffCount {
private:
	static unsigned int count;
public:
	static unsigned int getCount() {
		return ++count;
	}
};

unsigned int BuffCount::count = 0;


void useBuffer(Buffer& v) {
	cout << "Using Buffer with id: " << v.getID() << endl;
}//v out of scope, destruktor called

Buffer createBuffer() {
	Buffer x(BuffCount::getCount(), 20);
	x.Fill("Yes, I am!");
	return x; //calls move const here also calls destruktor on x after the move
}

int main()
{
	uint8_t* testcreate = new uint8_t[]{ "abcdef" };
	Buffer RoliBuf(BuffCount::getCount(), 20);
	Buffer DaveBuf(BuffCount::getCount(), testcreate, strlen((const char*)testcreate));
	//Buffer DaveBuf(2, testcreate, sizeof(testcreate)/sizeof(char));

	useBuffer(RoliBuf);

	//Buffer FloBuf = (Buffer&) createBuffer(); //move const
	Buffer test1 = createBuffer(); //move const
	Buffer test2 = move(RoliBuf);
	Buffer test3 = RoliBuf;
	Buffer test4 = (Buffer&&)RoliBuf;

	//array<Buffer, 6> BufferVec{  };
	vector<Buffer> BufferVec;
	for (int i = 0; i < 6; ++i)
	{

		BufferVec.push_back(createBuffer());
		//BufferVec.push_back(b);
	}

	for(auto b : BufferVec)
	{
		useBuffer(b);
	}


	delete[] testcreate;
}
