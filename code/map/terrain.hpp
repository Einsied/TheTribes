/**
 * @file terrain.hpp
 * @author Einsied 
 * @brief This file declares terrain types. 
 */

#pragma once

/** This class stores attributes of the terrain, like fertility, movement speed, permitted building, being a river etc.*/
// This will become a simple number
class TerrainType {
	/** How fast stuff grows there */
	// What can be planted is managed on the side of the plants
	// Natural occuring plants can be added in  a list too
	// The fertility it self should be managed completly by the plant, since it is a fixed value anyway.
	double fertility;
	/** How difficult it is to move in movement points */
	// This should be moved to creatures
	unsigned char movement_cost;
	/** How difficult it is to build in this terrain*/
	// This should be moved to buildings
	unsigned int building_cost;
};