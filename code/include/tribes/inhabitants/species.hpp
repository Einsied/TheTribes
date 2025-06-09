/**
 * @file
 * @brief This file declares the species class
 * @details The species are the abstract categories for the inhabitants
 * every inhabitant belongs to exactly one species
 *
 * @author Sebastian Einsiedler
 * @date 2025-06-08
 * @copyright Copyright (c) 2025
 */

#include "tribes/types.hpp"
#include "tribes/combat/harm.hpp"

namespace tribes::inhabitant
{
	/**
	 * @brief This class defines a specific species
	 * @details Since the inhabitants fall into multiple sub categories, this class is virtual,
	 * and the details are implemented by specific classes for each category.
	 */
	class Species
	{
	public:
		/**
		 * @brief This type is used to define the movement speed of an inhabitant
		 */
		using MovementSpeed = float;

		/**
		 * @brief This is used to categorize the species
		 * @details Depending on the category a different concrete class with different potential values
		 * is used.
		 * @note These are exclusive, so a wild animal species can never be livestock or sapient.
		 * An individual inhabitant however could transfer from wild animal to livestock by changing its species.
		 * So if we ever wish to create a group of sapient boar-people that reproduce by indoctrinating wild boars at an altar,
		 * we would have to give them a spell that transfers the (wild animal) boars into tame boars(livestock)
		 * and an altar that transfers all close tame (livestock) or (wild animal) boars into sapient boar people.
		 * Headaches about other sapient stealing the tame boars, since thy are livestock might follow.
		 */
		enum class Category
		{
			/**
			 * @brief Wild animals the roam the world
			 */
			Animal,
			/**
			 * @brief Animals integrated and partially controlled by sapients
			 */
			Livestock,
			/**
			 * @brief Intelligent beings using tools and controlled by or allied to a faction
			 */
			Sapient
		};

		/**
		 * @brief This is a global identifier for all species
		 */
		using Identifier = uint_fast64_t;

		/**
		 * @brief Get a pointer to a species by its identifier
		 * @note The pointer is an observer and the observed object should exist during the entire runtime
		 * 	so ownership managemanent is not necessary
		 * @param identifier the identifier
		 * @return A pointer to the harm associated with the identifier, true if the harm could be found
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		static std::expected<Species *, bool> GetSpecies(Identifier identifier);

		/**
		 * @brief Get the species category
		 * @return the category this species belongs to
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		virtual Category GetCategory() const = 0;

		/**
		 * @brief Get the base speed for this species
		 * @details The base speed is often the final 
		 * @return the base speed
		 */
		virtual MovementSpeed GetBaseSpeed() const = 0;

		virtual combat:Harm::Resistance GetBaseResistanceToHarm(combat::Harm::Identifier harm) const = 0;

		// ToDo add the base attack that represents fist or claws
		virtual combat::Attack GetBaseAttack()const  = 0
	};
};
