# Resource flows
This document houses the mermaid diagrams for the resource flows.

## Children of the Spirits

```mermaid
graph TD;
	subgraph Raw renewable
		Game(Game);
		Herb(Herb);
		Mushroom(Mushroom);
		FirTree(Fir tree);
		AppleTree(Apple tree);
		ChestnutTree(Chestnut tree);
		Grass(Grass);
		FishingGround(School of fish);
	end
	subgraph Raw limited
		Rock(Rock)
		VeinCopper(Copper Vein)
		VeinIron(Iron Vein)
		VeinGold(Gold Vein)
		CoalVein(Coal Vein)
	end
	subgraph Livestock
		Sheep(Sheep)
		Oxen(Oxen)
		Chicken(Chicken)
		Pig(Pig)
	end
	subgraph Produce
		Wheat(Wheat)
	end
	subgraph Food
		Meat(Meat)
		Fish(Fish)
		Bread(Bread)
		PieChestnut(Chestnut pie)
		PieApple(Apple pie)
		Mead(Mead)
		MeadFlavoured(Flavoured Mead)
		Ale(Ale)
		AleFlavoured(Mushroom Ale)
	end
	subgraph Material
		Lumber(Lumber)
		Boards(Boards)
		Stones(Stones)
	end
	subgraph Goods
		Medicine(Medicine)
		ClothesWool(Woolen clothes)
		Candles(Candles)
		Shoes(Shoes)
	end
	subgraph Luxury
		JewelryGold(Jewelry)
		DrinkingHorns(Drinking Horns)
		Pillow(Pillow)
	end
	subgraph Weapons
		BattleAxeCooper(Cooper battle axe)
		BattleAxeIron(Iron battle axe)
		SpearCopper(Cooper spear)
		SpearIron(Iron spear)
		SwordCopper(Copper Sword)
		SwordIron(Iron Sword)
		BowShort(Short Bow)
		MediumShieldWood(Medium wooden shield)
		MediumShieldCopper(Medium copper shield)
		MediumShieldIron(Medium iron shield)
		LightArmorLeather(Light leather armor)
		LightArmorCopper(Light copper armor)
		LightArmorIron(Light iron armor)
		LightHelmetLeather(Leather cap)
		MediumHelmetCopper(Copper helmet)
		MediumHelmetIron(Iron helmet)
		MediumHelmetCopperHorned(Horned copper helmet)
		MediumHelmetIronHorned(Horned iron helmet)
	end
	subgraph Tools
		AxeCopper(Copper Axe)
		AxeIron(IronAxe)
	end
```
