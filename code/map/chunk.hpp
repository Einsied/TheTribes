#pragma once

#include <memory>
#include <array>
#include <vector>

// A lot of shared pointer here reference to stuff that is created when the game starts and never deleted.
// This means it stays in memory forever.
// So instead of shared pointers raw pointers should be used via using.
// Not safe for refactor but the only way I think

/** A large rock that can be mined or a tree */
class ResourceNode;

/** Flowers, trees growing wheat, everything that grows and requires no interaction*/
class Plant{
	PlantType * plant_type; // Am I a tree, a flower, mushroom or wheat.
	unsigend int growth_points; // How much the plant has grown
};

/** Huntable deer, aggresive bears, fish, dolphins etc. */
class Animal;

/** This class stores buildings */
class Building;

/** A stack of goods like timber */
class StackOfGoods; 

/** Workers, soldiers, idlers etc.*/
class Sapient;

/**
 * @brief A chunk represent a part of the map
 * @details The map is separated into chunks to speed up processing and make it easier accesible for our algorithms.
 * Every chunk contains pointers to all elements within it.
 * So it is the central place were most stuff mets.
 * 
 * A chunk comes in multiple levels giving it some depth.
 * The levels represent the final terrain.
 */
class Chunk{
	/** The size of the side of one chunk */
	static const int kChunkSize = 64;

	/** The list defining all terrain tiles*/
	std::array<TerrainType *, kChunkSize * kChunkSize> terrain_tiles; 

	/** The list of all resources in the chunk */
	std::vector<std::unique_ptr<ResourceNode>> resources;

	/** The list of all goods in the chunk. That is all goods laying on the ground */
	std::vector<std::unique_ptr<StackOfGoods>> goods;

	/** The list of all plants in the chunk, this is a shared pointer, becuase a large plant like a tree can be part of another chunk.*/
	std::vector<std::shared_ptr<Plant>> plants;

	/** The list of all animals in the chunk.*/
	std::vector<std::unique_ptr<Animal>> plants;

	/** The list of all the settlers in the chunk.*/
	std::vector<std::unique_ptr<Settler>> settlers;

	/** The list of all plants in the buildings in the chunk, this is shared becaue a building can ectend over chunk borders.*/
	std::vector<std::shared_ptr<Building>> buildings;
};
