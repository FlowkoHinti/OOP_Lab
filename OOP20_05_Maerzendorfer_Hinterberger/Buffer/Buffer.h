#pragma once

#include <string>

class Buffer
{
public:
	Buffer(size_t ID, size_t size_buf);
	Buffer(size_t ID, uint8_t* data_ptr, size_t size_data); //--> zur umwandlung von einem normalen char* mit der länge in unseren Buffer
	~Buffer();
	Buffer(Buffer& copy_buff);	
	Buffer(Buffer&& move_buff) noexcept; 


	size_t getID() const { return this->id; }
	size_t getSize() const { return this->size; }
	uint8_t* getPtr() const { return this->data; }
	void setID(size_t ID) { this->id = ID; }
	void setSize(size_t size) { this->size = size; }
	void setPtr(uint8_t* data_ptr) { this->data = data_ptr; } //is doch kontrolliert xD
	void Fill(uint8_t fill_char);
	void Fill(std::string fill_muster);
	int InsertData(uint8_t* data, size_t data_size);

	

private:
	size_t id;
	size_t size=255;
	//sollte vl char8_t sein für wirkliche 8bit; char an sich sind 16bit also 2 byte-->wir allokieren also auch die doppelte size
	uint8_t* data;
	size_t p = 0;


};