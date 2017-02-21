
#include "stdafx.h"
#include "HashTable.h"
#include <iostream>
#include <string>

template<class T> void print(HashTable<T>);



int main()
{
	srand(time(0));
	double percentage = 30;
	float repetitions = 1000;
	double numberOfInserts = (MAXHASH * percentage) / 100;

	double totalCollisions = 0;

	cout << MAXHASH << endl;
	cout << numberOfInserts << endl;

	for (int i = 0; i < repetitions; i++){
		HashTable<string> t1;
		for (int j = 0; j < numberOfInserts; j++){
			int collisions = 0;
			while (!t1.insert(rand() % 1000000, "ashish", collisions)){
			}
		}
		int collisions = 0;
		t1.insert(rand() % 1000000, "ashish", collisions);
		totalCollisions += collisions + 1;
	}
	double avgCollisions = totalCollisions / repetitions;
	double optimal = 1 / (1 - (percentage / 100));
	cout << "avg: " << avgCollisions << endl;
	cout << "optimal: " << optimal << endl << endl; 

		cout << endl << endl;
		system("pause");
		return 0;
}





//#include "stdafx.h"
//#include "HashTable.h"
//
//
//using namespace std;
//
//template <class T> void visualize(HashTable<T> t) {
//	for (int i = 0; i < MAXHASH; i++)
//		cout << t.hashTable[i] << endl;
//	cout << endl;

//
//int main() {
//	cout << "Project 4" << endl;
//	HashTable<string> t1;
//	int collisions1 = 0;
//	t1.insert(98, "Jack Smiths", collisions1);
//	int collisions2 = 0;
//	t1.insert(55, "Jane Smiths", collisions2);
//	int collisions3 = 0;
//	t1.insert(666, "David", collisions3);
//	int collisions4 = 0;
//	t1.insert(676, "Joe", collisions4);
//	visualize(t1);
//
//
//	cout << endl << endl;
//	system("pause");
//	return 0;
//}
/*



//HashTable<string> t1;
//	int collisions = 0;
//	t1.insert(99,"ashish9",collisions);
//	t1.insert(90, "ashish0", collisions);
//	t1.insert(91, "ashish1", collisions);
//	t1.insert(92, "ashish2", collisions);
//	t1.insert(93, "ashish3", collisions);
//	t1.insert(94, "ashish4", collisions);
//	t1.insert(95, "ashish5", collisions);
//	t1.insert(96, "ashish6", collisions);
//	t1.insert(97, "ashish7", collisions);
//	t1.insert(98, "ashish8", collisions);
//	string str;
//	t1.remove(91);	
//	t1.insert(81, "ashishpatel",collisions);
//	t1.find(99, str);
//
//	t1.insert(18, "patel", collisions);
//	//t1.remove(18);
//
//	//t1.remove(8);
//	//float value = t1.alpha();
//
////	print(t1);
//	cout << &t1;
//	/*cout << value << endl;
//	cout << str << endl;
//	*/


//}
//
//template<class T> void print(HashTable<T> t){
//	for (int i = 0; i < MAXHASH; i++)
//		cout << t.hashTable[i] << endl;
//	cout << endl << endl;