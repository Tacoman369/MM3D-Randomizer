#pragma once

enum class ItemCategory {

	Fake = -1,
	None,
	MainInventory,
	Songs,
	SongOfSoaring,
	HeartContainers,
	PiecesOfHeart,
	Masks,
	TradeItems,
	Navigation,
	MagicPowers,
	SkulltulaTokens,
	StrayFairies,
	DungeonKeys,
	Seahorse,
	Shields,
	DekuSticks,
	ScoopedItems,
	Remains,
	BlueRupees,
	RedRupees,
	PurpleRupees,
	SilverRupees,
	Bombchu,
	GoldRupees,
	HeartContainer,
	Arrows,
	DekuNuts,


};

enum class LocationCategory {
	Fake = -1,
	None,

	Chests,
	NpcRewards, //Given by NPC but not from minigame
	Freestanding,
	Purchases, //Shops, Scrubs, Tingle, Bean Daddy, Milk Bar & Gorman Bros
	StartingItems,
	Minigames,
	BossFights, //bosses/minibosses
	MoonItems,
	EnemySpawn, //items spawned by enemies (Gold Skulltulas, enemies that spawn stray fairies, etc.)
	Beehives,
	Events, //items from events (Moons Tear, Sword School Gong, Song Wall, Telescope Guay & Field Guay)
	Jars,
	Crates,
	Barrels,
	Scoops,
	GlitchesRequired,
	SoftSoil,
};