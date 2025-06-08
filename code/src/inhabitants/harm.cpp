/**
 * @file
 * @brief This file declares good
 * @details A good is anything that participates in inactively in the economy.
 * This means things happen to it and it does nothing on its own besides maybe spoil.
 *
 * @author Sebastian Einsiedler
 * @date 2025-05-17
 * @copyright Copyright (c) 2025
 */

#include "tribes/inhabitants/harm.hpp"

#include <exception>
#include <vector>
#include <shared_mutex>

namespace tribes::inhabitant
{
	namespace
	{
		/**
		 * @brief This variable stores all the harms in the game.
		 * The position within the vector is the identifier of the harm.
		 */
		std::vector<Harm> global_harms;

		/**
		 * @brief The lock to control access to the harms list
		 */
		std::shared_mutex global_harms_lock;
	};

	/**
	 * @brief This is the implementation of the class
	 */
	class Harm::Implementation
	{
	};

	std::expected<Harm *, bool> Harm::GetHarm(Identifier identifier) {

	};

	Harm::Harm(Harm::RecoverySpeed base_recovery_speed)
	{
		// Get identifier from from the global list
		throw std::runtime_error("Not implemented yet");
	};

	Harm::Harm(Harm const &&to_move)
	{
		throw std::runtime_error("Not implemented yet");
	};

	Harm &Harm::operator=(Harm &&to_move)
	{
		throw std::runtime_error("Not implemented yet");
	};

	Harm::~Harm() = default;

	Harm::Identifier Harm::GetIdentifier() const
	{
		throw std::runtime_error("Not implemented yet");
	};

	Harm::RecoverySpeed Harm::GetBaseRecoverySpeed() const
	{
		throw std::runtime_error("Not implemented yet");
	};
};
