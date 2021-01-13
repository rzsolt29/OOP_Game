#include "Warrior.h"
#include <fstream>

int Warrior::alive = 0;

Warrior::Warrior(const std::string& team, const std::string& name, int health_point, int damage, int defense, Sword sword)
    : team(team), name(name), health_point(health_point), damage(damage), defense(defense), sword(sword) { ++alive; }

Warrior Warrior::parseFromFile(const std::string& team, const std::string& filename, Sword sword) {
    if (std::ifstream file(filename); file.is_open()) {
        std::string name;
        int health_point, damage, defense;
        file >> name >> health_point >> damage >> defense;
        if (file.fail()) throw BadFileFormatException{ filename };
        file.close();
        return Warrior(team, name, health_point, damage, defense, sword);

    }
    else throw FileNotFoundException{filename};
    
    
}


std::string Warrior::toString() const{
    return name + (isAlive()? "" : " DEAD ") + " (" + team + ") "
        + " ["
        +" HP: " + std::to_string(health_point)
        + " DMG: " + std::to_string(damage)
        + " DEF: " + std::to_string(defense)
        + "]";
}

void Warrior::die() {
    health_point = 0;
    damage = 0;
    defense = 0;   
    --alive;
}

void Warrior::attack(Warrior& defender) const {
    if (team != defender.team) {
        if (int actual_damage = damage + sword.use() - defender.defense; actual_damage > 0) {
            defender.health_point -= actual_damage;
            if (!defender.isAlive()) defender.die();
        }
    }
}

bool Warrior::isAlive() const {
    return health_point > 0;
}

std::string Warrior::getTeam() const { return team; }