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

#include <vector>
#include <expected>
#include <memory>

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
		 * @brief This type is used to define how far an inhabitant can see
		 */
		using SightRange = MovementSpeed;

		/**
		 * @brief This type describes the stamina of the species
		 * @details Stamina is used to run, attack or work if the inhabitant is a sapient.
		 * It recovers at different rates during the day.
		 */
		using Stamina = uint_fast16_t;

		/**
		 * @brief The speed at which stamina is recovered
		 */
		using StaminaRecovery = Stamina;

		/**
		 * @brief The time when members of a species rest
		 * @details This means they will prefer to sleep during this time.
		 * @note Keep in mind that time is cyclic. So for humans we expect end < begin,
		 * since they sleep through midnight.
		 */
		struct RestTime
		{
			/**
			 * @details begin of the rest period
			 */
			world::Time begin{0};
			/**
			 * @brief The end of the rest period
			 */
			world::Time end{0};
		};

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
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		virtual MovementSpeed GetSpeed() const = 0;

		/**
		 * @brief Gets the base resistance to a harm
		 * @details This is the raw resistance to harm of this species
		 * @param harm the that is resisted
		 * @return the harm resistance
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		virtual combat::Harm::Resistance GetResistanceToHarm(combat::Harm::Identifier harm) const = 0;

		/**
		 * @brief Get the base reduction for a harm of this species
		 * @details This is the base value subtracted from any harm done to members of this species
		 * @param harm the harm that is reduced
		 * @return the harm reduction
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		virtual combat::Harm::Reduction GetHarmReduction(combat::Harm::Identifier harm) const = 0;

		/**
		 * @brief Get the base recovery speed for a harm for this species
		 * @details This is the same or a modified value of the base recovery speed of the harm itself
		 * @param harm the harm that is recovered from
		 * @return the harm recovery speed
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		virtual combat::Harm::RecoverySpeed GetHarmRecoverySpeed(combat::Harm::Identifier harm) const = 0;

		/**
		 * @brief Get the identifier for the base attacks
		 * @details This represents the attacks by fist, claws, tails fangs etc.
		 * Most inhabitants will have only one base attack.
		 * @return the base attacks of the species
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		virtual std::vector<combat::Attack::Identifier> GetAttacks() const = 0;

		/**
		 * @brief Get the base sight range of the species
		 * @details This represent sight in "darkness" so it should be rather short.
		 * Think a moonless night for the level of dark.
		 * @return The base sight range
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		SightRange GetSightRange() const = 0;

		/**
		 * @brief Get the sight per brightness
		 * @details This is the range of sight increasing with brightness.
		 * So this value is multiplied by a brightness level and added to the base sight to
		 * get the total potential sight
		 * @return the sight per brightness
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		SightRange GetSightPerBrightness() const = 0;

		/**
		 * @brief Get the maximal sight range
		 * @details This is the maximal sight range even under full brightness.
		 * It serves as a cap.
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		SightRange MaximalSightRange() const = 0;

		/**
		 * @brief Get the base stamina of this species
		 * @details This is the amount of stamina a member of this species has
		 * @return the base stamina of this species
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		Stamina GetStamina() const = 0;

		/**
		 * @brief Get the stamina recovery of this species
		 * @details The stamina recovery depends on the time.
		 * In general species should recover more stamina during their active period.
		 * So nocturnal species recover more stamina during the night.
		 * @param time the time of the day
		 * @return the stamina recovery
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		StaminaRecovery GetStaminaRecovery(world::Time time) const = 0;

		/**
		 * @brief Get the times this species prefers to rest
		 * @details The nature of rest might be different between species,
		 * but most will most likely sleep
		 * @return the times this species prefers to rest
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		std::vector<RestTime> GetRestTimes() const = 0;

		/**
		 * @brief The destructor
		 * @details Virtual classes need a destructor for pointers
		 */
		~Species();
	};
};
