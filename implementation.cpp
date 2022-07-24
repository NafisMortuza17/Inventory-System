#include<iostream>
#include"LinkedList.h"
#include<iomanip>
#include<fstream>
using namespace std;

//constructor
List::List()
{
	first = 0;
	mySize = 0;
}

//deocnstructor
List::~List()
{
	NodePointer prev = first;
	NodePointer nextnode;
	while (prev != 0) {
		nextnode = prev->next;
		delete prev;
		prev = nextnode;
		
	}

	
}
//copy constructor
List::List(const List& origList)
{
	mySize = origList.mySize;
	first = 0;
	if (mySize == 0) return;
	NodePointer origPtr, lastPtr;
	first = new Node(origList.first->data); // copy first node
	lastPtr = first;
	origPtr = origList.first->next;
	//keep copying till end of list
	while (origPtr != 0)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	}
}
const List& List::operator=(const List& rightSide)
{
	mySize = rightSide.mySize;
	first = 0;
	if (mySize == 0) return *this;
	if (this != &rightSide)
	{
		this->~List();
		NodePointer origPtr, lastPtr;
		first = new Node(rightSide.first->data); // copy first node
		lastPtr = first;
		origPtr = rightSide.first->next;
		while (origPtr != 0)
		{
			lastPtr->next = new Node(origPtr->data);
			origPtr = origPtr->next;
			lastPtr = lastPtr->next;
		}
	}
	return *this;
}

void List::insert(ElementType val, int pos) {

	if (pos<0 || pos>mySize) {
		cerr << "Invalid postion to enter node\n";
		return;
	}
	mySize++;
	NodePointer newNode = new Node(val),
		predptr = first;
	if (pos == 0) {
		newNode->next = first;
		first = newNode;
	}
	else
	{
		for (int i = 1; i < pos; i++) 
			predptr = predptr->next;
			newNode->next = predptr->next;
			predptr->next = newNode;
		
	}
	
	
}

void List::erase(int pos) {
	if (pos<0 || pos>mySize) {
		cerr << "Invalid pos to erase node\n";
		return;
	}
	
	NodePointer predptr = first;
	NodePointer ptr;

	
	if (pos == 0) {
	 ptr = first;
		first = ptr->next;
		delete ptr;
	}
	else {
		for (int i = 1; i < pos; i++) {
			predptr = predptr->next;
		}
		ptr = predptr->next;
		predptr->next = ptr->next;
		delete ptr;
	}
	//output item removed after removing
	cout << "Item removed\n";
}
void List::changeinfo() {
	string name;
	//ask for name of the item
	cout << "Please enter the name of the item \n";
	cin >> name;
	cout << endl;
	//iterate through the list to find item
	NodePointer thisNode = first;
	while (thisNode != 0) {
		//ask to make the required changes when item found
		if (thisNode->data.itemName == name) {
			cout << "Please make the changes you want to the item\n";
			cout << endl;

			cout << "Enter the new name of the item\n";
			cin >> thisNode->data.itemName;
			//checks for istream failure after each input
			while (istreamFail(cin)) {
				cout << "Enter a valid string for the item name\n";
				cin >> thisNode->data.itemName;
			}

			cout << endl;

			cout << "Update the price of the item\n";
			cin >> thisNode->data.price;
			while (istreamFail(cin)) {
				cout << "Enter a valid price for the item\n";
				cin >> thisNode->data.price;
			}
			cout << endl;

			cout << "Update the inventory amount of the item\n";
			cin >> thisNode->data.availablestock;
			while (istreamFail(cin)) {
				cout << "Enter a valid input for inventory level\n";
				cin >> thisNode->data.availablestock;
			}
			cout << endl;

			cout << "Update the minimum inventory level of the item\n";
			cin >> thisNode->data.minStock;
			while (istreamFail(cin)) {
				cout << "Enter a valid minimum inventory level\n";
				cin >> thisNode->data.minStock;
			}
			cout << "Item information updated\n";
			return;
		}
		thisNode = thisNode->next;
	}
	//output item not found in the list 
	cout << "Item was not found on the list\n";
	return;
}


bool List::empty()
{
	return mySize == 0;
}

ostream& operator<<(ostream& out, const List& aList)
{
	aList.display(out);
	return out;
}


void List::reversePrint()
{
	List tempList;
	
	//makes temp list and copies in all the contents from the main list to temp and then print it 
	NodePointer origPtr= first;
	
	while (origPtr != 0) {
		tempList.insert(origPtr->data, 0);
		origPtr = origPtr->next;
	}

	tempList.display(cout);
	
}
int List::nodeCount() {
	return mySize;
}


void List::display(ostream& out) const
{
	NodePointer ptr = first;
	
	while (ptr != 0){
		out << ptr->data.itemName << "  " << ptr->data.price << "  " << ptr->data.availablestock << "  "  << ptr->data.minStock << endl;
		cout << endl;
		ptr = ptr->next;
	}
}
void List::printtoFile()
{
	//function that prints the list to an output file when the program is done
	ofstream fout;
	fout.open("newlist.txt");

	NodePointer ptr = first;

	while (ptr != 0) {
		fout << ptr->data.itemName << "  " << ptr->data.price << "  " << ptr->data.availablestock << "  " << ptr->data.minStock << endl;
		ptr = ptr->next;
	}
	
}
//function that checks if istream is in fail state
 bool istreamFail(istream& in)
{
	 //if in fail state clear the buffer and return true
	if (!in) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return true;
   }

}


