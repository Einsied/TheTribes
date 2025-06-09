/**
 * @file
 * @brief This file declares an attack
 * @details An attack is a combination of harms applied to an area
 * @author Sebastian Einsiedler
 * @date 2025-06-09
 * @copyright Copyright (c) 2025
 */

#include "tribes/types.hpp"
#include "tribes/combat/harm.hpp"

#include <memory>

namespace tribes::combat
{
	/**
	 * @brief The general class for all attacks
	 * @details This class defines how harm is done
	 */
	class Attack
	{
	public:
		/**
		 * @brief This is a component of an attack and corresponds to one harm
		 */
		struct Component{
			/**
			 * @brief the area affected by the attack given as a radius
			 * @note An area of 0.0 corresponds to a single target
			 */
			float area{0.0};
			/**
			 * @brief If the har applies to everyone or only foes
			 */
			bool discriminates{true}
		};

		// Todo continue from here

		/**
		 * @brief The default constructor
		 * @note Deleted, because every attack should do some harm
		 */
		Harm() = delete;

		/**
		 * @brief Construct a new attack
		 * @param components the components of the attack
		 * @param delivery if it is direct like a spear or a projectile like an arrow
		 * @param range the range of the attack
		 * @todo finish from here
		 */
		Harm();

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
		Harm(Harm const &&to_move);

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
		Harm &operator=(Harm &&to_move);

		/**
		 * @brief The destructor
		 * @note Since harms are pseudo-globals these function should never be explicitly called.
		 */
		~Harm();

		/**
		 * @brief Get the Identifier of the current harm
		 * @return the identifier belonging to this harm
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		Identifier GetIdentifier() const;

		/**
		 * @brief Get the basic recovery speed for this harm.
		 * 	This can later be modified, by species, equipment etc,
		 *  and just serves as a starting value.
		 * 	Since its meaning is not clear yet it does not have a unit.
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		RecoverySpeed GetBaseRecoverySpeed() const;

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
