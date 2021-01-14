#include "Inventory.h"

Inventory::Inventory() : swords(nullptr) {}

double Inventory::getTotalWeight() const {
	double totlaWeight = 0;
	for (InventoryItem* tmp = swords; tmp != nullptr; tmp = tmp->next)	totlaWeight+=tmp->sword.getWeight();
	return totlaWeight;
}

int Inventory::count() const {
	int count = 0;
	for (InventoryItem* tmp = swords; tmp != nullptr; tmp = tmp->next)	count++;
	return count;
}

Sword& Inventory::get(int index) const { 
	if (index < 0 || index >= count()) throw WrongIndexException();
	InventoryItem* tmp;
	for (tmp = swords; index != 0; --index) tmp = tmp->next;
	return tmp->sword;
}

void Inventory::put(const Sword& sword) {
	swords = new InventoryItem{ sword, swords };
}

Sword Inventory::drop(int index) {
	if (index < 0 || index >= count()) throw WrongIndexException();  //checkindexnel hagytam abba 17. vidi
	if (index == 0) {
		swords = swords->next;
		return Sword(0, 0, 0);
	}
	--index;
	InventoryItem* tmp;
	for (tmp = swords; index != 0; --index) tmp = tmp->next;
	tmp->next = tmp->next->next;
	return Sword(0, 0, 0);
}