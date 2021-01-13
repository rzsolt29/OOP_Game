#pragma once
#include <string>
#include "FileNotFoundException.h"
#include "Sword.h"


class Warrior {
    static int alive;
    const std::string team;
    const std::string name;
    int health_point;
    int damage;
    int defense;

    mutable Sword sword;

    void die();
public:
    struct BadFileFormatException {
        std::string filename;
    };

    Warrior(const std::string& team, const std::string& name, int hp, int dmg = 0, int defense = 0, Sword sword = Sword{0, 0, 0});
    std::string toString() const;
    void attack(Warrior& defender) const;
    bool isAlive() const;
    std::string getTeam() const;
    std::string getName() const { return name; }
    static int getAliveWarriorCount() { return alive; };

    static Warrior parseFromFile(const std::string& team, const std::string& filename, Sword sword = Sword{0, 0, 0});

};
