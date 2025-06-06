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

#include "tribes/goods/good.hpp"

#include <exception>

namespace tribes::good
{
	/**
	 * @brief This is the implementation of the class
	 */
	class Good::Implementation
	{
	};

	std::expected<Good const *, bool> Good::GetGood(Identifier identifier) {

	};

	Good::Good(Identifier const &identifier)
	{
		throw std::runtime_error("Not implemented yet");
	};

	Good::Good(Good const &&to_move)
	{
		throw std::runtime_error("Not implemented yet");
	};

	Good &Good::operator=(Good &&to_move)
	{
		throw std::runtime_error("Not implemented yet");
	};

	Good::~Good() = default;

	Good::Identifier Good::GetIdentifier() const
	{
		throw std::runtime_error("Not implemented yet");
	};
};
