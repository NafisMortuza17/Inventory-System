#include<iostream>
#include<fstream>
#include"LinkedList.h"
#include "item.h"
#include<string>
#include<stack>
using namespace std;
	
	int main(){
	List itemList;
	ifstream fin;
	item temp;//temp item to use for the insert function
	bool Exit = false;//bool value for the do while loop
	int choice;// user decision for the menu
	fin.open("Inventory.Txt");
	if (!fin) {
		cout << "Error opening file\n";
		exit(-1);
	}
	int pos = 0;
	//read into temp directly via overloaded insertion operator
	while (fin >> temp) {
		itemList.insert(temp, pos);//insert all items from file into linked list
		pos++;
	}

	itemList.sort();//sort the list in alphabetical order  after reading all items in
	
	
	
	do {
		//menu for the user to chose from
		cout << "***********************************" << endl;
		cout << "Please chose from the options below\n";
		cout << "Option 1: Add item to the list\n";
		cout << "Option 2: Remove item from the list\n";
		cout << "Option 3: Change the data for an item\n";
		cout << "Opiton 4:Print the item list\n";
		cout << "Option 5:Print the item list in reverse\n";
		cout << "Option 6:Exit\n";
		cout << "****************************************" << endl;
		cout << "Your choice>>";
		cin >> choice;
		cout << endl;
		//function that checks for istream failure and asks for input again
		while (istreamFail(cin)) {
			cout << "Enter a valid integer between 1-6 please\n";
			cin >> choice;
		}

	     //**********************************************************************************************//
		//Istream fail function is called after each single input to check if the stream is in fail state//
		//***********************************************************************************************//

		switch (choice)
		{
		case 1:

			int pos;
			cout << "Enter the position you would like to insert the item\n";
			cin >> pos; 
			 
			cout << endl;
			
			while (istreamFail(cin)) {
				cout << "Enter a valid position to insert your item\n";
				cin >> pos;
			}
          
			cout << "Enter the name of the item\n";
			cin >> temp.itemName;
			cout << endl;
			while (istreamFail(cin)) {
				cout << "Enter a item name in form of string\n";
				cin >> temp.itemName;
			}
			
			cout << "Enter the price of the item\n";
			cin >> temp.price;
			cout << endl;
			while (istreamFail(cin)) {
				cout << "Enter a valid price for the item\n";
				cin >> temp.price;
			}
			cout << "Enter the amount available in hand\n";
			cin >> temp.availablestock;
			cout << endl;

			while (istreamFail(cin)) {
				cout << "Enter a valid amount in stock\n";
				cin >> temp.availablestock;
			}


		
			cout << "Enter the minimum inventory level\n";
			cin >> temp.minStock;

			while (istreamFail(cin)) {
				cout << "Enter a valid minimum inventory level\n";
				cin >> temp.minStock;
			}
		
			itemList.insert(temp, pos);

			//outputs message if itemi is inserted in valid pos
			if (pos < itemList.nodeCount()) {
				cout << "Item added\n";
			}
			itemList.sort();//sort the list again after inserting new item 
		
			break;

		case 2:
			cout << "Enter the position you would like to remove\n";
			cin >> pos;
			while (istreamFail(cin)) {
				cout << "Enter a valid integer\n";
				cin >> pos;
			}
			itemList.erase(pos);
			
			
			break;
		case 3:
			itemList.changeinfo();//call member function that asks for the item info and make required changes
			itemList.sort();//sort the list as changing item name might potentially  make the list unsorted 
			break;
		case 4:
			itemList.display(cout);//call member function display
			break;
		case 5:
			itemList.reversePrint();//call member function to reverse display
			break;
		
		case 6:
			Exit = true;//make exit true 
			itemList.printtoFile();//print to output file after done
			break;
		default:
			//default if invalid option chose 
			cout << "Invalid answer! Please chose from options 1-5!\n";
		}//end of switch statement
	} while (!Exit);
	return 0;
}