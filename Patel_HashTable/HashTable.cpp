/*This cpp file contains all functions which are initialized in a HashTable class in a .h file. 
This file contains constructor for hash table to initialze with required specification, It also contains insert, find, remove, and alpha
which is used to insert, remove and find record. Besides this, it also contains hashfunction which find index of the hashtable according to the key.*/
#include "stdafx.h"
#include "HashTable.h"
#include <string>
#include <iostream>

using namespace std;

/*This is a simple HashTable constructor which simply creates a hash table with specific size with key, record and recordType field.*/
template <class T> HashTable<T>::HashTable(){

	hashTable = new Record<T>[MAXHASH];			
}


/*This is a destructor which is we don't need in this data structure,
because we are not using dynamic memory allocation.*/
template <class T> HashTable<T>:: ~HashTable(){

}

/*Insert function has three parameters key,value and collisions,
which will be used to insert at right place in the hash table.
Insert function calls probingFunc method to find the index where record would be inserted.
Then finds an empty spot for being inserted record.*/
template <class T> bool HashTable<T>::insert(int key, T value, int& collisions){

	//invoking probingFunc to find an index to insert record.
	int index = probingFunc(key, collisions);

	//return false if hash table is full so, no more insertion will happen.
	if (count == MAXHASH)
		return false;

	//check the index is empty if it is then insert new record with key and value and return true
	if (hashTable[index].isEmpty() || hashTable[index].isTombstone())	{
		hashTable[index] = Record<T>(key, value);
		count++;
		return true;
	}

	//return false if record already exists in a hash table.
	if (hashTable[index].getKey() == key)
		return false;

	//recursively calls itself until finds an empty spot.
	return insert(key, value, ++collisions);


}

/*Remove function has one parameter key,
which will be used to remove record from right place in the hash table.
Remove function calls hashFunction method to find the index where record would be removed.
Then set that index as a empty record.*/
template <class T> bool HashTable<T>::remove(int key){

	//Hash function to find right index 
	int index = hashFunction(key);

	//condition to check if record exist or not.
	if (hashTable[index].isEmpty())
		return false;

	//loop to check indexs if collisions occur and 
	//if right index found with right key then loop will be broken 
	while (!hashTable[index].isEmpty() && hashTable[index].getKey() != key)
	{
		index = (index + 1) % MAXHASH;
	}

	//condition if record exist or not and if exist 
	//then record will be removed from that index and 
	//for that kill method will be called and it returns true.
	if (!hashTable[index].isEmpty())
	{
		//delete record by calling kill method 
		//and size will be decreased 
		hashTable[index].kill();
		count--;
		return true;
	}

	return false;
	
}

/*Find function has two parameter key and value,
which will be used to find record from right place in the hash table.
find function calls hashFunction method to find the index where record would be found.
Returns true if record successfully found from the hash table and record will be stored in a value parameter.*/
template <class T> bool HashTable<T>::find(int key, T& value){

	//Hash function to find right index 
	int index = hashFunction(key);

	//loop to check indexs if collisions occur and 
	//if right index found with right key then loop will be broken 
	while (!hashTable[index].isEmpty() && hashTable[index].getKey() != key)
	{
		index = (index + 1) % MAXHASH;
	}

	//condition if record exist or not and if exist 
	//then record will be stored in value it returns true.
	if (!hashTable[index].isEmpty())
	{
		value = hashTable[index].getValue();
		return true;
	}

	return false;
}

/*This function calcuates the load factor of hash table by dividing
the number of existed record with the size of the hash table.*/
template <class T> float HashTable<T>::alpha(){
	
	return (float)count / MAXHASH;
}

/*Hash function simply returns the modulo of passed key and
size of the hash table.*/
template <class T> int HashTable<T>::hashFunction(int key){
	
	return key % MAXHASH;
	
}
/*Hash function simply returns the modulo of passed key's sqaure and
size of the hash table.*/
template <class T> int HashTable<T>::hashFunction2(int key){

	return  (key * key) % MAXHASH;
}

/*probing function calls the hash function method to find the index and
adds number of collisions to find an empty index in the hash table.*/
template <class T> int HashTable<T>::probingFunc(int key, int collisions){

	return (hashFunction(key) + (collisions*collisions*collisions)) % MAXHASH;
}

template <class T> ostream  & operator << (ostream & os, const HashTable <T> &ht) {

	for (int i = 0; i < MAXHASH; i++){

		int key = ht[i].getKey();
		T value = ht[i].getValue();

		os << key << " "<< value << endl;

	}
	os << endl;
	return os;
}
template HashTable<string>;
template HashTable<int>;

