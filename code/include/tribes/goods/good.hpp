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
		using Identifier = uint64_fast;

		/**
		 * @brief Get a pointer to a good by its identifier
		 * @details Goods are supposed to be static once instantiated,
		 * so you are not permitted to change them.
		 * @param identifier the identifier
		 * @return A reference to the good associated with the identifier, true if the good could be found
		 */
		static std::expected<Good const &, bool> GetGood(Identifier identifier);

		/**
		 * @brief The default constructor
		 * @note Deleted, because every good should have an unique identifier
		 */
		Good() = delete;

		/**
		 * @brief Construct a new good
		 * @param identifier the unique identifier this good will use
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
		Identifier GetIdentifier() const;

	private:
		/**
		 * @brief The forward declaration for pointer-to-implementation
		 */
		class Implementation;

		/**
		 * @brief The pointer to the implementation to hide the details
		 */
		std::unique_ptr<Implementation> implementation_ { std::make_unique<Implementation>() }
	};
};
