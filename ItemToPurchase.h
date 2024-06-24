#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

class ItemToPurchase {
	public:
		void SetDescription(std::string description);
		std::string GetDescription();
		void SetItemName(std::string name);
		std::string GetItemName();
		void SetItemQuantity(int amount);
		int GetItemQuantity();
		void SetItemPrice(int price);
		int GetItemPrice();

		void PrintItemCost();
		void PrintItemDescription();

	private:
		std::string itemDescription;
		std::string itemName;
		int itemQuantity;
		int itemPrice;
};

#endif
