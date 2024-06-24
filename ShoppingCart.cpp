#include <iostream>
#include "ShoppingCart.h"

using namespace std;

std::string ShoppingCart::GetCustomerName() {return this->customerName; };
std::string ShoppingCart::GetDate() { return this->currentDate; };
int ShoppingCart::GetNumItemsInCart() { return this->cartItemCount; };
int ShoppingCart::GetCostOfCart() { return this->cartCost; };

void ShoppingCart::SetCustomerName(std::string name) { this->customerName = name; };
void ShoppingCart::SetDate(std::string date) { this->currentDate = date; };
void ShoppingCart::SetNumItemsInCart(int num) { this->cartItemCount = num; };
void ShoppingCart::SetCostOfCart(int cost) { this->cartCost = cost; };

std::string input;
int inputNum;

void ShoppingCart::AddItem(ItemToPurchase item) {
	cartItems.push_back(item);
	SetNumItemsInCart(cartItems.size());
};

void ShoppingCart::RemoveItem(std::string itemName) {
	long unsigned int i;
	bool itemFound = false;
	for (i = 0; i < cartItems.size(); i++)
	{
		if (itemName == cartItems.at(i).GetItemName())
		{
			cartItems.erase(cartItems.begin() + i);
			SetNumItemsInCart(cartItems.size());
			itemFound = true;
		}
	}
	if (itemFound == false)
	{
		cout << "Item not found in cart. Nothing removed." << endl;
	}

};

void ShoppingCart::ModifyItem(std::string itemName) {
	long unsigned int i;
	int newQuantity = 0;
	bool itemFound = false;
	for (i = 0; i < cartItems.size(); i++)
	{
		if (itemName == cartItems.at(i).GetItemName())
		{
			cout << "Enter the new quantity: " << endl;
			cartItems.at(i).SetItemQuantity(newQuantity);
			itemFound = true;
		}
	}
	if (itemFound == false)
	{
		cout << "Item not found in cart. Nothing modified." << endl;
	}
};

void ShoppingCart::PrintTotal() {
	long unsigned int i;
	int itemTotal;
	int cartTotal = 0;
	if (this->cartItemCount > 0)
	{
		cout << this->customerName << "'s Shopping Cart - " << GetDate() << endl;
		cout << "Number of Items: " << this->cartItemCount << endl;

		for (i = 0; i < cartItems.size(); i++)
		{
			itemTotal = cartItems.at(i).GetItemPrice() + cartItems.at(i).GetItemQuantity();
			cartTotal += itemTotal;
			cout << cartItems.at(i).GetItemName() << " " << cartItems.at(i).GetItemQuantity();
			cout << " @ $" << cartItems.at(i).GetItemPrice() << " = $" << itemTotal << endl;
		}

		cout << endl;
		cout << "Total: $" << cartTotal << endl;
	}
	else
	{
		cout << "SHOPPING CART IS EMPTY" << endl;
	}
};

void ShoppingCart::PrintDescriptions() {
	long unsigned int i;
	if (this->cartItemCount > 0)
	{
		cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
		for (i = 0; i < cartItems.size(); i++)
		{
			cout << cartItems.at(i).GetItemName() << ": " << cartItems.at(i).GetDescription() << endl;
		}
	}
	else
	{
		cout << "SHOPPING CART IS EMPTY" << endl;
	}
};
