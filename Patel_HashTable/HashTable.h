/*This header file declares what kind of and which functions 
are going to implement into a hashtable class in a HashTable.cpp file
This file reduces the dependencies so that this header file does not need 
to worry about the details of the implementations of the functions.
#define MAXHASH defines the size of the hash table */

#define MAXHASH 1000
#include "Record.h"

/*This class contains all declaration of all function which are being 
impplemented in the HashTable.cpp file*/
template <class T> class HashTable{
public:
    Record<T>* hashTable;
    int count;

	HashTable();
	~HashTable();
	bool insert(int, T, int&);
	bool find(int, T&);
	bool remove(int);
	float alpha();
	int hashFunction(int);
	int hashFunction2(int);
	int probingFunc(int, int);
    friend	ostream& operator << (ostream & , const HashTable <T>&);


};