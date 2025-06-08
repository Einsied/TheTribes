/**
 * @file
 * @brief This file declares the namespaces and types.
 * @details To give an overview over the different namespaces and
 * classes they are all collected in this file as forward declarations
 * @author Sebastian Einsiedler
 * @date 2025-05-17
 * @copyright Copyright (c) 2025
 */

/**
 * @brief The main namespace for the game
 */
namespace tribes
{

	/**
	 * @brief The namespace for all goods and related classes
	 * @details a fundamental challenge for the goods is multiple-use.
	 * An axe could be a tool or a weapon. A mushroom tea a beverage or medicine.
	 * With multiple inheritance this may introduces the diamond problem.
	 * To avoid it all goods have to contain the necessary values as properties.
	 */
	namespace good
	{
		class Good;
		class Food;
		class Merchandise;
		class Beverage;
		class Medicine;
		class Equipment;
		class Tool;
		class Weapon;
		class Armor;
		/*
		 * Goods are either carried, stored in buildings ore are on the map.
		 * In the former cases the inventory management just references the above classes,
		 * in the last case they exist as a stack, so this is the only "on-map"-representation of goods.
		 */
		class Stack;
	};

	/**
	 * @brief The namespace for all combat related classes
	 */
	namespace combat
	{
		class Harm;
	}

	/**
	 * @brief The namespace for all inhabitants and related classes
	 */
	namespace inhabitant
	{
		class Inhabitant;
		class Animal;
		class Livestock;
		class Sapient;
		class Need;
	};

	/**
	 * @brief The namespace for all objects of interest
	 * @details Objects of interest are interactive objects in
	 * the game world. Like plants or resource nodes.
	 */
	namespace interest
	{
		class ObjectOfInterest;
		class ResourceNode;
		class Plant;
	};
};
