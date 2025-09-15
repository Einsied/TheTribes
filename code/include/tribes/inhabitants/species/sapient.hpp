/**
 * @file
 * @brief This file declares the concrete species class for sapients
 * @details The species are the abstract categories for the inhabitants
 * every inhabitant belongs to exactly one species
 *
 * @author Sebastian Einsiedler
 * @date 2025-06-08
 * @copyright Copyright (c) 2025
 */

#pragma once

#include "tribes/types.hpp"
#include "tribes/inhabitants/species/base.hpp"

#include <vector>
#include <expected>
#include <memory>

namespace tribes::inhabitant::species
{
	/**
	 * @brief This class defines a specific species
	 * @details Since the inhabitants fall into multiple sub categories, this class is virtual,
	 * and the details are implemented by specific classes for each category.
	 */
	class Sapient: public Base
	{
	public:
		/**
		 * @brief This type is used to define the speed with which tools or weapons can be used
		 * @details This is mostly done to give elves or vampires a boost.
		 * In essence we can give a sapient a high handling speed and normal stamina recovery
		 * giving them a high potential for inital harm.
		 * We can also use time dependent stamina recovery to make some sapients more active during
		 * the night or day.
		 */
		using HandlingSpeed = float;

		/**
		 * @brief Get the species category
		 * @return the category this species belongs to
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		Category GetCategory() const override;

		/**
		 * @brief Get the base speed for this species
		 * @details The base speed is often the final
		 * @return the base speed
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		MovementSpeed GetSpeed() const override;

		/**
		 * @brief Gets the base resistance to a harm
		 * @details This is the raw resistance to harm of this species
		 * @param harm the that is resisted
		 * @return the harm resistance
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		combat::Harm::Resistance GetResistanceToHarm(combat::Harm::Identifier harm) const override;

		/**
		 * @brief Get the base reduction for a harm of this species
		 * @details This is the base value subtracted from any harm done to members of this species
		 * @param harm the harm that is reduced
		 * @return the harm reduction
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		combat::Harm::Reduction GetHarmReduction(combat::Harm::Identifier harm) const override;

		/**
		 * @brief Get the base recovery speed for a harm for this species
		 * @details This is the same or a modified value of the base recovery speed of the harm itself
		 * @param harm the harm that is recovered from
		 * @return the harm recovery speed
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		combat::Harm::RecoverySpeed GetHarmRecoverySpeed(combat::Harm::Identifier harm) const override;

		/**
		 * @brief Get the identifier for the base attacks
		 * @details This represents the attacks by fist, claws, tails fangs etc.
		 * Most inhabitants will have only one base attack.
		 * @return the base attacks of the species
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		std::vector<combat::Attack::Identifier> GetAttacks() const override;

		/**
		 * @brief Get the base sight range of the species
		 * @details This represent sight in "darkness" so it should be rather short.
		 * Think a moonless night for the level of dark.
		 * @return The base sight range
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		SightRange GetSightRange() const override;

		/**
		 * @brief Get the sight per brightness
		 * @details This is the range of sight increasing with brightness.
		 * So this value is multiplied by a brightness level and added to the base sight to
		 * get the total potential sight
		 * @return the sight per brightness
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		SightRange GetSightPerBrightness() const override;

		/**
		 * @brief Get the maximal sight range
		 * @details This is the maximal sight range even under full brightness.
		 * It serves as a cap.
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		SightRange MaximalSightRange() const override;

		/**
		 * @brief Get the base stamina of this species
		 * @details This is the amount of stamina a member of this species has
		 * @return the base stamina of this species
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		Stamina GetStamina() const override;

		/**
		 * @brief Get the stamina recovery of this species
		 * @details The stamina recovery depends on the time.
		 * In general species should recover more stamina during their active period.
		 * So nocturnal species recover more stamina during the night.
		 * @param time the time of the day
		 * @return the stamina recovery
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		StaminaRecovery GetStaminaRecovery(world::Time time) const override;

		/**
		 * @brief Get the times this species prefers to rest
		 * @details The nature of rest might be different between species,
		 * but most will most likely sleep
		 * @return the times this species prefers to rest
		 */
		[[nodiscard("Calling a getter without using the value seems to be a mistake.")]]
		std::vector<RestTime> GetRestTimes() const override;

		/**
		 * @brief Get the speed at which this species handles tools or weapons
		 * @return the speed at which this species handles tools or weapons
		 */
		HandlingSpeed GetHandlingSpeed();

		// TODO Get needs vector
		// TODO get equipment slots

		/**
		 * @brief The destructor
		 * @details Virtual classes need a destructor for pointers
		 */
		~Sapient();
	};
};
