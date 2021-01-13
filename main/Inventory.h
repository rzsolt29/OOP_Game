#pragma once

#include "Sword.h"

class Inventory {
    
    struct InventoryItem {
        Sword sword;
        InventoryItem* next;
    };

    InventoryItem* swords;
    
public:
    class  WrongIndexException{};
    Inventory();
    double getTotalWeight() const;
    int count() const;
    Sword& get(int index) const;
    void put(const Sword& sword);
    Sword drop(int index);
};