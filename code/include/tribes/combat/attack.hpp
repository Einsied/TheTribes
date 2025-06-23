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
#include <expected>
#include <vector>

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
		 * @brief This is a global identifier for all harm
		 */
		using Identifier = size_t;

		/**
		 * @brief This is a component of an attack and corresponds to one harm
		 */
		struct Component
		{
			/**
			 * @brief the area affected by the attack given as a radius
			 * @note An area of 0.0 corresponds to a single target
			 */
			float area{0.0};
			/**
			 * @brief If the harm applies to everyone or only foes
			 */
			bool discriminates{true};
			/**
			 * @brief The harm this component does
			 */
			Harm::Identifier harm_identifier;
			/**
			 * @brief The amount of harm this component does
			 */
			Harm::Amount amount;
		};

		/**
		 * @brief This enumerator describes how the attack is delivered
		 */
		enum Delivery
		{
			/**
			 * @brief The attack is delivered directly, from the attacker.
			 * @details This is the mode that should be chosen for swords, spears, claws, fangs
			 * and other melee attacks.
			 */
			Direct,
			/**
			 * @brief The attack is delivered as a projectile
			 * @details This means the attack is expressed as a projectile and sent
			 * to the target. This is the appropiate delivery for bows, javelins
			 * and similar ranged weapons.
			 */
			Projectile
		};

		/**
		 * @brief The range of an attack
		 */
		using Range = float;

		/**
		 * @brief Get a pointer to an attack by its identifier
		 * @note The pointer is an observer and the observed object should exist during the entire runtime
		 * 	so ownership managemanent is not necessary
		 * @param identifier the identifier
		 * @return A pointer to the attack associated with the identifier, true if the attack could be found
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		static std::expected<Attack *, bool> GetAttack(Identifier identifier);

		/**
		 * @brief The default constructor
		 * @note Deleted, because every attack should do some harm
		 */
		Attack() = delete;

		/**
		 * @brief Construct a new attack
		 * @param components the components of the attack
		 * @param delivery if it is direct like a spear or a projectile like an arrow
		 * @param range the range of the attack
		 * @note The attack will automatically obtain the next free identifier.
		 */
		Attack(std::vector<Component> components, Delivery delivery, Range range);

		/**
		 * @brief The copy constructor
		 * @param to_copy the instance to copy
		 * @note Considering the instances are supposed to exist only once we need no copy
		 */
		Attack(Attack const &to_copy) = delete;

		/**
		 * @brief The move constructor
		 * @param to_move the instance to move
		 */
		Attack(Attack const &&to_move);

		/**
		 * @brief The copy assignment operator
		 * @param to_copy the instance to copy
		 * @note Considering the instances are supposed to exist only once we need no copy
		 * @return reference to the new copy
		 */
		Attack &operator=(Attack const &to_copy) = delete;

		/**
		 * @brief The copy assignment operator
		 * @param to_move the instance to move
		 * @return reference to the new object
		 */
		Attack &operator=(Attack &&to_move);

		/**
		 * @brief The destructor
		 * @note Since attacks are pseudo-globals these function should never be explicitly called.
		 */
		~Attack();

		/**
		 * @brief Get the Identifier of the current attack
		 * @return the identifier belonging to this attack
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		Identifier GetIdentifier() const;

		/**
		 * @brief Get the components of the attack
		 * @details Considering that the components of the attack never need to change they are transferred as pointers.
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		std::vector<Component const *> GetComponents() const;

		/**
		 * @brief Get the delivery of the attack
		 * @return the delivery of the attack
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		Delivery GetDelivery() const;

		/**
		 * @brief Get the range of the attack
		 * @return the range of the attack
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		Range GetRange() const;

	private:
		/**
		 * @brief The forward declaration for pointer-to-implementation
		 */
		class Implementation;

		/**
		 * @brief The pointer to the implementation to hide the details
		 */
		std::unique_ptr<Implementation> implementation_;
	};
};
