#pragma once

#include <iostream>

class BString
{
private:
	char* cp;
	unsigned int len;
	unsigned int maxlen= UINT_MAX - 1;


public:
	
	// Default Constructor
	BString();
	// Constructor 1
	BString(unsigned int iLen);
	// Constructor 2
	BString(const char* cStr);
	// Constructor 3
	BString(char initChar, unsigned int sSize =1);

	// copy constructor 
	BString(const BString &bString);

	// Destructor
	~BString();

	// Public functions
	void conOut() const;
	inline unsigned int length()const { return len; };
	inline unsigned int capacity() const { return len; };

	// overloading operators
	// Overload "=" operator to assign one object to another 
	BString& operator=(const BString& bString);
	// Overload "+=" operator to append one object to another 
	BString& operator+=(const BString& bString);

};

