/**
 * @file
 * @brief This file declares harms that can be done to inhabitants
 * @details Harm is something that happens to inhabitants creating undesirable consequences.
 * 	Like physical harm having the consequence of death.
 * 	In most games this concept is called damage, but morale-damage seems way less clear than
 * 	morale harm.
 * 	Also most of the game conflicts will involve doing harm to inhabitants not objects,
 * 	so harm was the better term.
 *
 * @author Sebastian Einsiedler
 * @date 2025-05-23
 * @copyright Copyright (c) 2025
 */

#include "tribes/types.hpp"

#include <memory>
#include <expected>
#include <cstdint>

namespace tribes::inhabitant
{
	/**
	 * @brief The general class for all harm
	 * @details This class just defines a kind of harm
	 * So it is meant to distinguish between physical, stun or morale.
	 * In other games this would be called damage channels.
	 */
	class Harm
	{
	public:
		/**
		 * @brief This is a global identifier for all goods
		 */
		using Identifier = uint_fast64_t;

		/**
		 * @brief Get a pointer to a kind of harm by its identifier
		 * @details Harms are supposed to be static once instantiated,
		 * so you are not permitted to change them.
		 * @note The pointer is an observer and the observed object should exist during the entire runtime
		 * 	so ownership managemanent is not necessary
		 * @param identifier the identifier
		 * @return A pointer to the harm associated with the identifier, true if the harm could be found
		 */
		static std::expected<Good const *, bool> GetHarm(Identifier identifier);

		/**
		 * @brief The default constructor
		 * @note Deleted, because every good should have an unique identifier
		 */
		Harm() = delete;

		/**
		 * @brief Construct a new good
		 * @param identifier the unique identifier this harm will use
		 * @param base_recovery_speed is the basic recovery speed for this harm
		 * 	it can later be modified and just gives a general direction.
		 * 	Since its meaning is not clear hear it does not have a units.
		 * @todo the identifier should be given created by a static registry.
		 * 	This means the constructor should be private and we should use a factory method
		 */
		Harm(Identifier const &identifier, float base_recovery_speed);

		/**
		 * @brief The copy constructor
		 * @param to_copy the instance to copy
		 * @note Considering the instances are supposed to exist only once we need no copy
		 */
		Harm(Harm const &to_copy) = delete;

		/**
		 * @brief The move constructor
		 * @param to_move the instance to move
		 */
		Harm(Good const &&to_move);

		/**
		 * @brief The copy assignment operator
		 * @param to_copy the instance to copy
		 * @note Considering the instances are supposed to exist only once we need no copy
		 * @return reference to the new copy
		 */
		Harm &operator=(Harm const &to_copy) = delete;

		/**
		 * @brief The copy assignment operator
		 * @param to_move the instance to move
		 * @return reference to the new object
		 */
		Good &operator=(Harm &&to_move);

		/**
		 * @brief The destructor
		 */
		~Harm();

		/**
		 * @brief Get the Identifier of the current harm
		 * @return the identifier belonging to this harm
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
		std::unique_ptr<Implementation> implementation_{std::make_unique<Implementation>()};
	};
};
