/**
 * @file
 * @brief This file defines an attack
 *
 * @author Sebastian Einsiedler
 * @date 2025-06-09
 * @copyright Copyright (c) 2025
 */

#include "tribes/combat/attack.hpp"

#include <exception>
#include <vector>
#include <shared_mutex>

namespace tribes::combat
{
	namespace
	{
		/**
		 * @brief This variable stores all the harms in the game.
		 * The position within the vector is the identifier of the harm.
		 */
		std::vector<Attack> global_attacks;

		/**
		 * @brief The lock to control access to the harms list
		 */
		std::shared_mutex global_attacks_lock;
	};

	/**
	 * @brief This is the implementation of the class
	 */
	class Attack::Implementation
	{
	};

	std::expected<Attack *, bool> Attack::GetAttack(Identifier identifier) {

	};

	Attack::Attack(std::vector<Component> components, Delivery delivery, Range range)
	{
		// Get identifier from from the global list
		throw std::runtime_error("Not implemented yet");
	};

	Attack::Attack(Attack const &&to_move)
	{
		throw std::runtime_error("Not implemented yet");
	};

	Attack &Attack::operator=(Attack &&to_move)
	{
		throw std::runtime_error("Not implemented yet");
	};

	Attack::~Attack() = default;

	Attack::Identifier Attack::GetIdentifier() const
	{
		throw std::runtime_error("Not implemented yet");
	};

	std::vector<Attack::Component const *> Attack::GetComponents() const
	{
		throw std::runtime_error("Not implemented yet");
	};

	Attack::Delivery Attack::GetDelivery() const
	{
		throw std::runtime_error("Not implemented yet");
	};

	Attack::Range Attack::GetRange() const
	{
		throw std::runtime_error("Not implemented yet");
	};
};
