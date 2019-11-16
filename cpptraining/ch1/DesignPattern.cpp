#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {
	printf("Hello : %d ", strlen("Hello"));
	printf("장애: %d ", strlen("장애"));
	//sprintf()
	return 0; 
}
//
//class LevelItem {
//public:
//	LevelItem(const char*);
//};
//
//class Level {
//public:
//	virtual ~Level();
//
//	const char* Name() {
//		return _name;
//	}
//	virtual float LifePoints();
//	virtual int NumEnemies();
//	virtual void Add(LevelItem*);
//protected:
//	LevelItem(const char*);
//private:
//	const char* _name;
//};
//
//class Potion : public LevelItem {
//public:
//	Potion();
//	Potion(const char*);
//	virtual ~Potion();
//
//	virtual float LifePoints();
//};
//
//class CompositeItem : public LevelItem {
//public:
//	virtual ~CompositeItem();
//
//	virtual float LifePoints();
//	virtual int NumEnemies();
//
//	virtual void Add(LevelItem *);
//	virtual void Remove(LevelItem *);
//	virtual Iterator<LevelItem*> *CreateIterator();
//	
//protected:
//	Composition(const char*);
//private:
//	list<LevelItem*> _item;
//};
//
//float CompositeItem::LifePoints() {
//	Iterator<LevelItem*> *i = CreateIterator();
//	float total = 0;
//
//	for (i->First(); !i->IsDone(); i->Next()) {
//		total += i->CurrentItem()->LifePoints();
//	}
//	delete i;
//	return total;
//}
//int CompositeItem::NumEnemies() {
//	Iterator<LevelItem*>* i = CreateIterator();
//	int total = 0;
//
//	for (i->First(); !i->IsDone(); i->Next()) {
//		total += i->CurrentItem()->NumEnemies();
//	}
//	delete i;
//	return total;
//}
//
//class Enemy : public CompositeItem {
//public:
//	Enemy(const char*);
//	virtual ~Enemy();
//
//	virtual float LifePoints();
//	virtual int NumEnemies();
//};
//
//class SubLevel : public CompositeItem {
//public:
//	SubLevel(const char*);
//	virtual ~SubLevel();
//	
//	virtual float LifePoints();
//	virtual int NumEnemies();
//};
//
//void LordOfTheRings() {
//	Level* MiddleEarth = new Level("Middle Earth");
//	SubLevel* TheShire = new SubLevel("TheShire");
//	SubLevel* Moria = new SubLevel("Mines of Moria");
//	MiddleEarth->Add(TheShire);
//	MiddleEarth->Add(Moria);
//
//	Enemy *Nazgul = new Enemy("Nazgul");
//	Enemy *NazgulRider = new Enemy("NazgulRider");
//	Enemy *NazgulSteed = new Enemy("NazgulSteed");
//	Nazgul->Add(NazgulRider);
//	Nazgul->Add(NazgulSteed);
//	TheShire->Add(Nazgul);
//	Enemy *Balrog = new Enemy("Balrog");
//	Moria->Add(Balrog);
//
//	Potion *Lembas = new Potion("Lembas");
//	TheShire->Add(Lembas);
//	cout << "The number of monsters in Middle Earth is " << MiddleEarth->NumEnemies() << endl;
//	cout << "The life points for the monsters are " << MiddleEarth->LifePoints() << endl;
//}
//
//
//Potion::Potion()
//{
//}
//
//Potion::Potion(const char *str)
//{
//	cout << str << endl;
//}
//
//Potion::~Potion()
//{
//}
//
//float Potion::LifePoints()
//{
//	return 0.0f;
//}
//
//LevelItem::LevelItem(const char *str)
//{
//	cout << str << endl;
//}
