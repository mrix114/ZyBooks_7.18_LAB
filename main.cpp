#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


#include "ShoppingCart.h"

void PrintMenu() {
	cout << "MENU" << endl;
	cout << "a - Add item to cart" << endl;
	cout << "d - Remove item from cart" << endl;
	cout << "c - Change item quantity" << endl;
	cout << "i - Output items' descriptions" << endl;
	cout << "o - Output shopping cart" << endl;
	cout << "q - Quit" << endl;
	cout << "Choose an option:" << endl;
	
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
	string menuInput;
	string newitemName;
	string description;
	int quantity;
	int price;
	ItemToPurchase newItem;

	if (option == 'a'){
		cout << "ADD ITEM TO CART" << endl;
		cout << "Enter the item name : " << endl;
		cin.ignore();
		getline(cin, menuInput);
		newitemName = menuInput;
		newItem.SetItemName(newitemName);

		cout << "Enter the item description : " << endl;
		cin.ignore();
		getline(cin, menuInput);
		description = menuInput;
		newItem.SetDescription(description);

		cout << "Enter the item price : " << endl;
		cin >> price;
		newItem.SetItemPrice(price);

		cout << "Enter the item quantity : " << endl;
		cin >> quantity;
		newItem.SetItemQuantity(quantity);

		theCart.AddItem(newItem);
	}
	if (option == 'd') {
		cout << "REMOVE ITEM FROM CART" << endl;
		cout <<"Enter name of item to remove : " << endl;
		cin.ignore();
		getline(cin, menuInput);
		newitemName = menuInput;
		theCart.RemoveItem(newitemName);
	}
	if (option == 'c') {
		cout << "CHANGE ITEM QUANTITY" << endl;
		cout << "Enter the item name:" << endl;
		cin.ignore();
		getline(cin, menuInput);
		newitemName = menuInput;
		theCart.ModifyItem(newitemName);
	}
	if (option == 'i') {
		cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
		theCart.PrintDescriptions();
	}
	if (option == 'o') {
		cout << "OUTPUT SHOPPING CART" << endl;
		cout << endl;
		theCart.PrintTotal();
	}
}

int main() {
	string input;
	string customerName;
	string currentDate;
	char menuChoice = 'o';
	ShoppingCart mycart;

	cout << "Enter customer's name:" << endl;
	getline(cin, input);
	customerName = input;
	mycart.SetCustomerName(customerName);
	cout << "Enter today's date:" << endl;
	getline(cin, input);
	currentDate = input;
	mycart.SetDate(currentDate);
	cout << endl;

	cout << "Customer name: " << mycart.GetCustomerName() << endl;
	cout << "Today's date: " << mycart.GetDate() << endl;
	cout << endl;

	PrintMenu();
	cin >> menuChoice;
	while (menuChoice != 'q')
	{
		while (menuChoice != 'a' &&
			menuChoice != 'd' &&
			menuChoice != 'c' &&
			menuChoice != 'i' &&
			menuChoice != 'o' &&
			menuChoice != 'q')
		{
			cout << "Choose an option:" << endl;
			cin >> menuChoice;
		}
		ExecuteMenu(menuChoice, mycart);
		cout << "Choose an option:" << endl;
		cin >> menuChoice;

	}

	return 0;
}
