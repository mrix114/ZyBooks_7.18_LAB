#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart {
	public:
		std::string GetCustomerName();
		std::string GetDate();
		int GetNumItemsInCart();
		int GetCostOfCart();
		void SetCustomerName(std::string name);
		void SetDate(std::string date);
		void SetNumItemsInCart(int num);
		void SetCostOfCart(int cost);
		void AddItem(ItemToPurchase item);
		void RemoveItem(std::string itemName);
		void ModifyItem(std::string itemName);
		void PrintTotal();
		void PrintDescriptions();
	private:
		std::string customerName;
		std::string currentDate;
		int cartCost;
		int cartItemCount;
		std::vector <ItemToPurchase> cartItems;
};

#endif
