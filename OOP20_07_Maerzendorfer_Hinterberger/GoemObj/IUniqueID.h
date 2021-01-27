#pragma once

class IUniqueID
{
public:
	virtual unsigned int getID() = 0;
};

class Counter : public IUniqueID {

private:
	static unsigned int seed;

public:
	unsigned int getID() override {
		return ++seed;
	}
};


