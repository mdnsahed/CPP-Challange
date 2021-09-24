#include "BString.h"

// default constructor
BString::BString()
{
	len = 1;
	maxlen = UINT_MAX - 1;
}

//constructor 1 
BString::BString(unsigned int iLen)
{
	len = iLen;
	// assign new memory
	cp = new char[len]();
	// assigning char array as symbolic constant
	char symConst[] = {'i','n','i', 't', 'i', 'a', 'l', 'i', 'z', 'i', 'n','g', ' ', 'c','h','a','r', ' ', 'a','r','r','a','y'};
	int symConst_size = sizeof(symConst) / sizeof(symConst[0]);
	// Checking of memory allocation
	if (cp == NULL) {
		std::cout<< "ERROR : Memory allocation failed!" <<std::endl;
		exit(-1);
	}
	else
	{
		if (len < symConst_size)
		{
			for (int i = 0; i < len; i++) {

				cp[i] = symConst[i];
			}
		} 
		else
		{
		for (int i = 0; i < symConst_size; i++) {

			cp[i] = symConst[i];
		}
		for (int i = 0; i < len- symConst_size; i++) {

			cp[i+ symConst_size] ='.';
		}
		}
	}
}
// Constructor 2
BString::BString(const char * cStr)
{
	int Size = 0;
	// Increment of "Size" according to string size
	while ((cStr != NULL) && (cStr[Size] != '\0') ) Size++;

	if(Size >0 && Size < maxlen){
	// assigning new memory
	cp = new char[Size]();
	// Checking of memory allocation
	if (cp == nullptr) {
		std::cout<< "ERROR : Memory allocation failed!" <<std::endl;
		exit(-1);
	}
	else
	{
		for (int i = 0; i < Size; i++) {

			cp[i] = cStr[i];
		}
	}
	len = Size;	
	}
	else
	{
		len = Size;
		if (cStr == nullptr)
		{
			std::cout << "INFO : No Memory allocated for nullptr with size :" << len << std::endl;
		} 
		else
		{
		std::cout << "INFO : No Memory allocated for empty String : "<<cStr << "with size :" << len << std::endl;
		}
	}
}
// Constructor 3
BString::BString(char initChar, unsigned int sSize)
{
	// assigning new memory
	cp = new char[sizeof(initChar)]();
	// Checking of memory allocation
	if (cp == nullptr) {
		std::cout << "ERROR : Memory allocation failed!" << std::endl;
		exit(-1);
	}
	else
	{
		for (int i = 0; i < int(sSize); i++) {
			cp[i] = initChar;
		}
	}
	len = sizeof(initChar);	

}
// Copy Constructor
BString::BString(const BString & bString)
{
	// Assigning "len" and "maxlen"
	len = bString.len;
	maxlen = bString.maxlen;
	// assigning new memory
	cp = new char[len]();
	// Checking of memory allocation
	if (cp == nullptr) {
		std::cout << "ERROR : Memory allocation failed!" << std::endl;
		exit(-1);
	}
	// copying the data from "cp" to "len"
	std::memcpy(cp, bString.cp, len);
}

//Destructor
BString::~BString()
{
	len = 0;
	maxlen = 0;
	std::cout << "destructed :  " << &cp << std::endl;
	// deleting the allocated memory
	if (cp != NULL)
		delete[] cp;
	//std::cout << "Destructed!" << std::endl;
	
}

// Public function for output devices
void BString::conOut() const
{
	//std::cout << "len :  "<< len << std::endl;

	// Iterating over cp
	for (int i = 0; i < len; i++) {

		std::cout << cp[i];
	}
	std::cout << " " << std::endl;
}

BString & BString::operator=(const BString & bString)
{
	if(this== &bString)
		return *this; //self assignment
	if (cp != NULL)
		delete[] cp;//clean up already allocated memory
	// assigning "len" and "maxlen" variable
	len= bString.len;
	maxlen = bString.maxlen;
	// assigning new memory
	cp = new char[len]();
	// Checking of memory allocation
	if (cp == nullptr) {
		std::cout << "ERROR : Memory allocation failed!" << std::endl;
		exit(-1);
	}
	// copying the data from "cp" to "len"
	std::memcpy(cp, bString.cp, len);
	return *this;
	
}

BString & BString::operator+=(const BString & bString)
{
	// allocating memory for new object
	char* tmp = new char[len + bString.len ];   
	// Checking of memory allocation  
	if (tmp == nullptr) {
		std::cout << "ERROR : Memory allocation failed for '+=' operator overload!" << std::endl;
		exit(-1);
	}
	// read self string to temp array
	for (int i = 0; i < len; i++)
	{
		tmp[i] = cp[i];
	}
	// read string from other object to temp array
	for (int i = 0; i < bString.len ; i++) 
	{
		tmp[i + len] = bString.cp[i];
	}
	// delete already allocated memory
	if (cp != NULL)
		delete[] cp;
	//point to new string array
	cp = tmp;
	//assign new length to combined length
	len += bString.len;
	//return this object
	return *this;
	
}