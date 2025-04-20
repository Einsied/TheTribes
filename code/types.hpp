class Good; // Goods should be flammable and magma-meltable to govern their destruction
// Goods should also know in what gods they are dissasembled upon destruction (This might be done via a reatcion)

class Equipment: public Good;

class Armor: public Equipment;

class Weapon: public Equipment:

class Creature;

class Animal: public Creature;

class Sophont: public Creature;

class Pet: public Animal;
