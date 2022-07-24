#pragma once
#include<iostream>

using namespace std;

//definiton of a struct that holds all the information of an item
struct item {
	string itemName;
	double price;
	int availablestock;
	int minStock;
};

//overloaded insertion operator for item data type
inline istream& operator>>(istream& in, item& obj) {
	in >> obj.itemName;
	in >> obj.price;
	in >> obj.availablestock;
	in >> obj.minStock;

	return in;
}