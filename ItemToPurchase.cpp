#include <iostream>
using namespace std;
#include "ItemToPurchase.h"

std::string ItemToPurchase::GetDescription() {
	return this->itemDescription;
}

std::string ItemToPurchase::GetItemName() {
	return this->itemName;
}

int  ItemToPurchase::GetItemPrice() {
	return this->itemPrice;
}

int  ItemToPurchase::GetItemQuantity() {
	return this->itemQuantity;
}

void ItemToPurchase::SetDescription(std::string description) {
	this->itemDescription = description;
}

void ItemToPurchase::SetItemName(std::string name) {
	this->itemName = name;
}

void ItemToPurchase::SetItemPrice(int price) {
	this->itemPrice = price;
}

void ItemToPurchase::SetItemQuantity(int amount) {
	this->itemQuantity = amount;
}

void ItemToPurchase::PrintItemDescription() {
	cout << this->itemName << ": " << this->itemDescription;
}

void ItemToPurchase::PrintItemCost() {
	int total = this->itemPrice + this->itemQuantity;
	cout << this->itemName << " " << this->itemQuantity << " @" << this->itemPrice; 
	cout << " = $" << total << endl;
}