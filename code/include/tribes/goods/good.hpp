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

#include <memory>
#include <expected>
#include <cstdint>

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
	public:
		/**
		 * @brief This is a global identifier for all goods
		 */
		using Identifier = uint_fast64_t;

		/**
		 * @brief Get a pointer to a good by its identifier
		 * @details Goods are supposed to be static once instantiated,
		 * so you are not permitted to change them.
		 * @note The pointer is an observer and the observed object should exist during the entire runtime
		 * 	so ownership managemanent is not necessary
		 * @param identifier the identifier
		 * @return A pointer to the good associated with the identifier, true if the good could be found
		 */
		static std::expected<Good const *, bool> GetGood(Identifier identifier);

		/**
		 * @brief The default constructor
		 * @note Deleted, because every good should have an unique identifier
		 */
		Good() = delete;

		/**
		 * @brief Construct a new good
		 * @param identifier the unique identifier this good will use
		 * @todo the identifier should be given created by a static registry.
		 * 	This means the constructor should be private and we should use a factory method
		 */
		Good(Identifier const &identifier);

		/**
		 * @brief The copy constructor
		 * @param to_copy the instance to copy
		 * @note Considering the instances are supposed to exist only once we need no copy
		 */
		Good(Good const &to_copy) = delete;

		/**
		 * @brief The move constructor
		 * @param to_move the instance to move
		 */
		Good(Good const &&to_move);

		/**
		 * @brief The copy assignment operator
		 * @param to_copy the instance to copy
		 * @note Considering the instances are supposed to exist only once we need no copy
		 * @return reference to the new copy
		 */
		Good &operator=(Good const &to_copy) = delete;

		/**
		 * @brief The copy assignment operator
		 * @param to_move the instance to move
		 * @return reference to the new object
		 */
		Good &operator=(Good &&to_move);

		/**
		 * @brief The destructor
		 */
		~Good();

		/**
		 * @brief Get the Identifier of the current good
		 * @return the identifier belonging to this good
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		virtual Identifier GetIdentifier() const;

		// TODO use std:optional to gain possible properties of weapons, beverages, food etc.
		// The idea is to return std::nullopt if the good is not a weapon, beverage, food etc.

	private:
		/**
		 * @brief The forward declaration for pointer-to-implementation
		 */
		class Implementation;

		/**
		 * @brief The pointer to the implementation to hide the details
		 */
		std::unique_ptr<Implementation> implementation_{std::make_unique<Implementation>()};
	};
};
