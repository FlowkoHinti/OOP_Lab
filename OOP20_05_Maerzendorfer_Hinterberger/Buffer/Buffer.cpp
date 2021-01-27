#include "Buffer.h"
#include <string>
#include <iostream>
#include <utility>

using namespace std;

Buffer::Buffer(size_t ID, size_t size_buf) : id{ ID }, size{ size_buf }
{
	this->data = new uint8_t[size_buf];
}

Buffer::Buffer(size_t ID, uint8_t* data_ptr, size_t size_data) : id{ ID }, data{ data_ptr }, size{ size_data }, p{ size_data-1 } {}

Buffer::~Buffer()
{
	cout << "Deleting Buffer with id: " << this -> id << endl;
	if (this->data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}

	
}

void Buffer::Fill(uint8_t fill_char) {
	for (size_t i = 0; i < this->size; ++i) {
		data[i] = fill_char;
	}
	p = size;
}
void Buffer::Fill(std::string fill_muster) {
	for (size_t i = 0; i < this->size; ++i) {
		data[i] = fill_muster[i % fill_muster.size()];
	}
	p = size;
}

int Buffer::InsertData(uint8_t* data, size_t data_size) {
	if (p + data_size > this->size)
		return -1;

	for (size_t i=0; i < data_size; ++i) {
		data[p + i] = data[i];
	}
	p += data_size;
	return 1;
}


Buffer::Buffer(Buffer& copy_buff) : id(copy_buff.id), size(copy_buff.size), p(copy_buff.p) {
	this->data = new uint8_t[copy_buff.size];
	//*(this->data) = *(copy_buff.data);
	//strcpy_s((char*)this->data, (char*)copy_buff.data);

	for(int i=0; i<copy_buff.p;i++){
		this->data[i] = copy_buff.data[i];
	}

}
//move-->move-->used for class-type members
//exchange(other.n,0)-->moves n and leaves 0 in other.n-->used for non-class-type members
Buffer::Buffer(Buffer&& move_buff) noexcept: id(exchange(move_buff.id,0)), size(exchange(move_buff.size, 0)),p(exchange(move_buff.p,0)) 
{
	this->data = new uint8_t[this->size];
	for(int i=0; i<this->p;i++){
		this->data[i] = move_buff.data[i];
	}
}

