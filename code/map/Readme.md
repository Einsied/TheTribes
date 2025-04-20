# Map
The map is the fundamental logic unit and bindes the game together.
It is artifically divided into *chunks* to make processing easier.
The chunks are integrated into a tree via *chunk containers*.

Eahc chunk contains a bunch of actors or game elements,
like *plants*, *structures*, *goods*, *animals*, *settlers* etc.
along with *layers*.

- [Map](#map)
  - [Layer](#layer)
    - [Fluid level](#fluid-level)
    - [Dirt level](#dirt-level)
    - [Rock level](#rock-level)
  - [Chunk](#chunk)
  - [Chunk Container](#chunk-container)


## Layer
A *layer* represents a certain height of the *chunk*.
Every *chunk* has at least one *layer*.
They are used to represent subterran parts of the *chunk*.
This can include resource mines or caves.
Therefore all *layers* have a height. 
Objects or materials within them might not exceed this height.

All *layers* contain the terrain information for the tiles.
This consist of multiple levels.
The levels are the always present but might be empty.
All levels have a height determining how much stuff is there.
The combined heights can not exceed the height of the *layer*.

Therea are three levels
* Fluid-level: Water, magma, tar.
* Dirt-level: The height of farm and shovelable dirt
* Rock-layer: The height of mineable rock

### Fluid level
The fluid level has a height, a material type and a flow direction.
Since there is only one material-type layer it follows that fluids can not mix.

This is acceptable because we currently only that there will be only
water, swamp-water, salt-water, lava and tar.
These substances do not mix.
Salt water turns swamp and pure water into salt water below a global water line.
Swamp water turns pure water into swamp water if there is no water-flow.
Tar does not mix with water.
Magma evaporates water and ignites and burns away tar.
Rivers of milk, honey or booze are not planned but have to be treated similarly.

To better track the flow of water the fluid layer tracks sinks and sources.
If fluid enteres the layer the entry point becomes a source.
A source fills up the fluid-layer up to a certain level.
If the heights are not changed in a turn and the source is full,
there has to be no hydrodynamic simulation.

Sinks exist on the map.
If there is no connected source they draw water.
Water is only removed if the sink stronger than the source.
To this end sources and sinks are connected in a water graph.
The graph contains indvidual *chunks* as nodes.
So only when one *chunk* becomes instable does it need to be recalculated.
To ease the process every *chunk*-node is safed with its interfaces.
The interfaces are coordinates for in and outflow to easily check if the
water-flow is still intact or not.

### Dirt level
The dirt level is only meant to dig in and to walk/grow/build upon.
So it is interesting for pathfinding and for building/farming.
Besides its height it contains the terrain type.
So we know it the tile is a desert, grass, road- or forest tile.
The updating of this tiles will be constant but slow.
It contains additional information in the sense of a walking map.
Essentially every animal, vehicle or settler that walks over a tile,
creates walking points.
Once the walking points become to much the grass dies.
(This might be nothing but eye-candy, but it could be relevant for pathfinding, since the most walked path is a good heuristic.)

### Rock level
Within these level can be dug to.
Opposite to the dirt-level a tunnel can be driven into rock,
thereby creating a new layer.

## Chunk
The *chunk* contains at least one or multiple layers.
It also stores the active game components like plants,
animals, resource nodes, structures, goods or settlers.
With only two exceptions they are all in precisley one *chunk*.

The first exceptions are strucutres, which by their nature can exits in mutiple chunks. 
While walls are created in segments that can stop at the *chunk* border,
larger strucutres like houses can not be arbitraily split.

The second rather suprising exceptions are plants.
While wheat, bushes and reeds are small, trees can be quite large.
So a huge ancient tree could walk over the *chunk*-border.
Instead of having weird lines in our forests we have to treat them similar to buildings.

## Chunk Container
The *chunk* containers are used to create a tree of *chunks* and thereby
ease tasks such as path-finding or inter-chunk transfer.
They only exist to gain efficency.
