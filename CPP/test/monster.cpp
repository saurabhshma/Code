#include <iostream>
#include <string>

using namespace std;

enum class monster
{
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME
};

struct my_monster
{
	monster type;
	string name;
	int health;
};

string getMonsterType(monster a)
{
	if(a == monster::OGRE)
		return("OGRE");
	else if(a == monster::DRAGON)
		return("DRAGON");	
	else if(a == monster::ORC)
		return("ORC");	
	else if(a == monster::GIANT_SPIDER)
		return("GIANT SPIDER");	
	else if(a == monster::SLIME)
		return("SLIME");
	else
		return("Incorrect Monster type");
}

void printMonster(my_monster x)
{
	cout << "This " << getMonsterType(x.type) << " is named " << x.name << " and has " << x.health << " health\n";
}

int main()
{
	my_monster a = {monster::OGRE, "Torg", 145};
	my_monster b = {monster::SLIME, "Blurp", 23};
	printMonster(a);
	printMonster(b);
	return 0;
}
