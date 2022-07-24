//----- List.h -----
#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include"item.h"
using namespace std;
typedef item ElementType;
class List
{
private:
	class Node
	{
	public:
		ElementType data;
		Node* next;

		Node()
			: next(0)
		{ }

		Node(ElementType dataValue)
			: data(dataValue), next(0)
		{ }
	}; //--- end of Node class

	typedef Node* NodePointer;

public:
	//------ List OPERATIONS
	List();

	~List();

	List(const List& origList);

	const List& operator=(const List& rightSide);
	
	void insert(ElementType dataVal, int index);

	void erase(int index);

	void changeinfo();//used to change info for an item 

   void display(ostream& out) const;

	int nodeCount();

	bool empty();

	void reversePrint();//print list in reverse 

	void sort();//sort funciton 

	void printtoFile();//function to read to output file when the program ends 


private:
	//------ DATA MEMBERS
	NodePointer first;
	int mySize;
}; //--- end of List class
ostream& operator<<(ostream& out, const List& aList);
bool istreamFail(istream& in);//function that checks if the istream is in fail state
#endif