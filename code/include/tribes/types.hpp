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
	 */
	namespace good
	{
		class Good;
		class Stack;
		class Food;
		class Merchandise;
		class Beverage;
		class Medicine;
		class Equipment;
		class Tool;
		class Weapon;
		class Armor;
	};

	/**
	 * @brief The namespace for all inhabitants and related classes
	 */
	namespace inhabitant
	{
		class Inhabitant;
		class Harm;
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
