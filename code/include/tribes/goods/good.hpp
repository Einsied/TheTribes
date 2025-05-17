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

#include "tribes/types.hpp"

namespace tribes::good
{
	/**
	 * @brief The general class for all goods
	 * @details This class describes a type of good like meat.
	 * While there might be mutiple stacks of meat in the game
	 * they should all refer to one instance of this class representing meat.
	 */
	class Good
	{
		/**
		 * @brief This is a global identifier for all goods
		 */
		using Identifier = uint64_fast;

		/**
		 * @brief The default constructor
		 */
		Good() = delete;

		/**
		 * @brief The copy constructor
		 * @param to_copy the instance to copy
		 */
		Good(Good const &to_copy);

		/**
		 * @brief The move constructor
		 * @param to_move the instance to move
		 */
		Good(Good const &&to_move);

		/**
		 * @brief The copy assignment operator
		 * @param to_copy the instance to copy
		 * @return reference to the new copy
		 */
		Good &operator=(Good const &to_copy);

		/**
		 * @brief The copy assignment operator
		 * @param to_move the instance to move
		 * @return reference to the new object
		 */
		Good &operator=(Good &&to_move);

		/**
		 * @brief Get the I
		 * @return the identifier belonging to this good
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		Identifier GetIdentifier() const;
	};
};
