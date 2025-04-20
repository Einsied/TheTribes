#pragma once

#include <memory>
#include <array>

#include <chunk.hpp>

/** Infinite hierarchy to group chunks*/
class ChunkContainer{

	/** Number of chunks or containers in a container per side */
	static const kChunkContainerSize = 4;

	/** The parent container, nullptr for root */
	std::weak_ptr<ChunkContainer> parent;

};

class ChunkContainerLeaf: public ChunkContainer{
	std::array<std::unique_ptr<Chunk>, kChunkContainerSize * kChunkContainerSize> children;
};

class ChunkContainerLeaf: public ChunkContainer{
	/** Empty for leaves */
	std::array<std::unique_ptr<Chunk>, kChunkContainerSize * kChunkContainerSize> children;
};
