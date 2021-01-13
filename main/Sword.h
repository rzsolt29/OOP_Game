#pragma once

#include <string>

class Sword {
	const int damage;
	const int max_durability;
	int current_durability;
	const double weight;
public:
	Sword(int damage, int durability, double weight);
	int use();
	void repair();
	double getWeight() const;
	std::string toString() const;
};