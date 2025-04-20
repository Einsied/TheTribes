/**
 * @file fluids.hpp
 * @author Einsied
 * @brief These file contains the definition of the individual fluids
 */

#pragma once

#include <memory>
#include <vector>

#include "terrain_type.hpp"

/**
 * @brief Tracks the direction in which the water flows
 * @details This is partially governing how we view the flow of water.
 * Considering that our maps are three dimesional we are going to assume
 * the worst case of 26-connectivity (9 voxel bottom, 8 voxels self, 9 voxels top).
 * Hexagonal maps would have fewer connections so some parts of the integer
 * would simply go unused.
 */
enum class FlowDirection : uint_least8_t
{
    /** The water in this tile dows not flow */
    kNoFlow,
    /**
     * The releative cube coordinates are (x:-1, y:-1, z:+1).
     * This should not happen, fluids do no flow upwards, it is in here in case we add pressure.
     */
    kTopFrontLeft,
    /**
     * The releative cube coordinates are (x: 0, y:-1, z:+1).
     * This should not happen, fluids do no flow upwards, it is in here in case we add pressure.
     */
    kTopFrontCenter,
    /**
     * The releative cube coordinates are (x:+1, y:-1, z:+1).
     * This should not happen, fluids do no flow upwards, it is in here in case we add pressure.
     */
    kTopFrontRight,
    /**
     * The releative cube coordinates are (x:-1, y: 0, z:+1).
     * This should not happen, fluids do no flow upwards, it is in here in case we add pressure.
     */
    kTopMiddleLeft,
    /**
     * The releative cube coordinates are (x: 0, y: 0, z:+1).
     * This should not happen, fluids do no flow upwards, it is in here in case we add pressure.
     */
    kTopMiddleCenter,
    /**
     * The releative cube coordinates are (x:+1, y: 0, z:+1).
     * This should not happen, fluids do no flow upwards, it is in here in case we add pressure.
     */  
    kTopMiddleRight,
    /**
     * The releative cube coordinates are (x:-1, y:+1, z:+1).
     * This should not happen, fluids do no flow upwards, it is in here in case we add pressure.
     */
    kTopBackLeft,
    /**
     * The releative cube coordinates are (x: 0, y:+1, z:+1).
     * This should not happen, fluids do no flow upwards, it is in here in case we add pressure.
     */
    kTopBackCenter,
    /**
     * The releative cube coordinates are (x:+1, y:+1, z:+1).
     * This should not happen, fluids do no flow upwards, it is in here in case we add pressure.
     */
    kTopBackRight,
    /** The releative cube coordinates are (x:-1, y:-1, z:0). */
    kEvenFronLeft,
    /** The releative cube coordinates are (x:0, y:-1, z:0). */
    kEvenFrontCenter,
    /** The releative cube coordinates are (x:+1, y:-1, z:0). */
    kEvenFrontRight,
    /** The releative cube coordinates are (x:-1, y:0, z:0). */
    kEvenMiddleLeft,
    /** The releative cube coordinates are (x: 0, y:0, z:0). */
    kEvelMiddleCenter,
    /** The releative cube coordinates are (x:+1, y:-1, z:0). */
    kEvenMiddleRight,
    /** The releative cube coordinates are (x:-1, y:-1, z:0). */
    kEvenBackLeft,
    /** The releative cube coordinates are (x: 0, y:-1, z:0). */
    kEvenBackCenter,
    /** The releative cube coordinates are (x:+1, y:-1, z:0). */
    kEvenBackRight,
    /** The releative cube coordinates are (x:-1, y:-1, z:-1). */
    kBottomFrontLeft,
    /** The releative cube coordinates are (x: 0, y:-1, z:-1). */
    kBottomFrontCenter,
    /** The releative cube coordinates are (x:+1, y:-1, z:-1). */
    kBottomFrontRight,
    /** The releative cube coordinates are (x:-1, y: 0, z:-1). */
    kBottomMiddleLeft,
    /** The releative cube coordinates are (x: 0, y: 0, z:-1). */
    kBottomMiddleCenter,
    /** The releative cube coordinates are (x:+1, y: 0, z:-1). */
    kBottomMiddleRight,
    /** The releative cube coordinates are (x:-1, y:-1, z:-1). */
    kBottomBackleLeft,
    /** The releative cube coordinates are (x: 0, y:-1, z:-1). */
    kBottomBackCenter,
    /** The releative cube coordinates are (x:+1, y:-1, z:-1). */
    kBottomBackRight
};

class Fluid
{
public:
    /**
     * @brief Get a list of all existing fluids
     * @details Fluids are only created during the intial loading of a map.
     * There is no mechanik to dynamicaly create a new kind of water during the game.
     * So we can use raw pointers.
     * @return a list with pointers to all existing fluids
     */
    static std::vector<Fluid const *> GetFluids();

    bool MixFluid(Fluid const *invading_fluid, FlowDirection flow_direction, );
};