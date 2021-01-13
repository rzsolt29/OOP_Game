#include <iostream>
#include <string>
#include "Warrior.h"
#include "Battle.h"
#include "FileNotFoundException.h"
#include "Inventory.h"
using namespace std;


int main(){
    try {
        /*Warrior warrior1 = Warrior::parseFromFile("Blue", "units/Unicorn.txt", Sword(10, 3));
        Warrior warrior2 = Warrior::parseFromFile("Red", "units/Efreet.txt");
        fightTilDeath(warrior1, warrior2);
        cout << Warrior::getAliveWarriorCount() << " warrior(s) are still alive.\n ";
        */
        Inventory inv;
        inv.put(Sword(12, 3, 1.2));
        inv.put(Sword(12, 3, 3.4));
        inv.put(Sword(12, 3, 0.3));
        cout << inv.count() << endl;
        cout << inv.getTotalWeight() << endl;
        inv.put(Sword(12, 3, 1));
        inv.put(Sword(12, 3, 2));
        cout << inv.count() << endl;
        

        inv.get(3).use();

        for (int i = 0;i < inv.count(); i++) {
            cout<<i<<". item: "<< inv.get(i).toString()<<endl;
        }
        
        
        return 0;
    } catch (FileNotFoundException exception) {
        cout << "Bad filename: " << exception.filename << endl;
        return 1;
    } catch (Warrior::BadFileFormatException exception) {
        cout << "Bad file structure: " << exception.filename << endl;
        return 2;
    }
    
    //github test   
}
