#include <iostream>
#include <vector>

struct Item;
typedef std::vector<Item> LootBox;



struct Coin
{
	uint16_t count;

	Coin(uint16_t count) : count(count) 
	{
	}
};

enum class Element { FIRE, WATER, EARTH, AIR };

struct Rune 
{
	uint16_t level;
	Element element;
	
	Rune(uint16_t level, Element element) :
		level(level),
		element(element)
	{
	}
};

struct Weapon
{
	uint16_t damage;
	uint16_t critical;
	uint16_t durability;

	Weapon(uint16_t damage, uint16_t critical, uint16_t durability) : 
		damage(damage), 
		critical(critical), 
		durability(durability)
	{
	}
};

struct Armor
{
	uint16_t guard;
	uint16_t durability;

	Armor() :
		guard(guard),
		durability(durability)
	{
	}
};

enum class ItemType {
	СOIN,
	RUNE,
	WEAPON,
	ARMOR
};

union itemType {
	Coin coin;
	Rune rune;
	Weapon weapon;
	Armor armor;
};

struct Item 
{
	ItemType itemTypeEnum;
	itemType itemTypeUnion;
};

Item generateLoot() 
{
	std::vector<std::pair<int, Item >> gen(16);

	// 1
	gen[0].first = 50 * 100;
	
	gen[0].second.itemTypeEnum = ItemType::СOIN;
	gen[0].second.itemTypeUnion.coin = Coin(1000);

	// 2
	gen[1].first = 6 * 100;
	gen[1].second.itemTypeUnion.rune = Rune(1, Element::FIRE);

}

LootBox generateLootBox() {
	const int countLootBox = 3;
	
	LootBox box(countLootBox);
	for (int i = 0; i < countLootBox; i++)
	{
		box[i] = generateLoot();
	}
	
	return box;
}

int main() 
{

}