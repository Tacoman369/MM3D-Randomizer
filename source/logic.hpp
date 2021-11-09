#pragma once

#include <3ds.h>

namespace Logic {

	extern bool noVariable;
	//item logic
	extern bool Ocarina;
	extern bool KokiriSword;
	extern bool HasBottle;
	extern bool Bombchus;
	extern bool DekuStick;
	extern bool MagicBean;
	extern bool MagicBeanPack;
	extern bool LensOfTruth;
	extern bool Bow;
	extern bool FireArrows;
	extern bool IceArrows;
	extern bool LightArrows;
	extern bool Hookshot;
	extern bool Pictobox;
	extern bool PowderKeg;
	extern bool Epona;
	//mask logic
	extern bool DekuMask;
	extern bool GoronMask;
	extern bool ZoraMask;
	extern bool KeatonMask;
	extern bool BunnyHood;
	extern bool PostmansHat;
	extern bool AllNightMask;
	extern bool BlastMask;
	extern bool StoneMask;
	extern bool GreatFairyMask;
	extern bool BremenMask;
	extern bool DonGerosMask;
	extern bool MaskOfScents;
	extern bool RomanisMask;
	extern bool CircusLeadersMask;
	extern bool KafeisMask;
	extern bool CouplesMask;
	extern bool KamarosMask;
	extern bool GibdosMask;
	extern bool GarosMask;
	extern bool CaptainsHat;
	extern bool GiantsMask;
	extern bool FierceDietyMask;
	extern bool MaskOfTruth;
	//trade items logic
	extern bool LandTitle;
	extern bool SwampTitle;
	extern bool MountainTitle;
	extern bool OceanTitle;
	extern bool RoomKey;
	extern bool LetterKafei;
	extern bool PendantOfMemories;
	extern bool LetterMama;
	extern bool MoonsTear;
	//trade quest events
	extern bool LandTitleAccess;
	extern bool SwampTitleAccess;
	extern bool MountainTitleAccess;
	extern bool OceanTitleAccess;
	extern bool RoomKeyAccess;
	extern bool LetterKafeiAccess;
	extern bool PendantAccess;
	extern bool LetterMamaAccess;
	extern bool MoonsTearAccess;
	//Songs
	extern bool SongOfStorms;
	extern bool SonataOfAwakening;
	extern bool GoronsLullaby;
	extern bool NewWaveBossaNova;
	extern bool ElegyOfEmptiness;
	extern bool OathToOrder;
	extern bool EponasSong;
	//Remains
	extern bool OdolwaRemains;
	extern bool GohtRemains;
	extern bool GyorgRemains;
	extern bool TwinmoldRemains;
	//Dungeon Clears
	extern bool WoodfallClear;
	extern bool SnowheadClear;
	extern bool GreatBayClear;
	extern bool StoneTowerClear;
	//Progressive Items
	extern u8 ProgressiveBow;
	extern u8 ProgressiveMagic;
	extern u8 ProgressiveWallet;
	extern u8 ProgressiveBombBag;
	//Keys
	extern u8 WoodfallTempleKeys;
	extern u8 SnowheadTempleKeys;
	extern u8 GreatBayTempleKeys;
	extern u8 StoneTowerTempleKeys;
	//Boss Keys
	extern bool BossKeyWoodfallTemple;
	extern bool BossKeySnowheadTemple;
	extern bool BossKeyGreatBayTemple;
	extern bool BossKeyStoneTowerTemple;
	//Skulltula Counts
	extern u8 SwampSkulltulaTokens;
	extern u8 OceanSkulltulaTokens;
	//Drops & Bottle Contents Access
	extern bool DekuNutDrop;
	extern bool NutPot;
	extern bool NutCrate;
	extern bool DekuBabaNuts;
	extern bool DekuStickDrop;
	extern bool StickPot;
	extern bool DekuBabaSticks;
	extern bool BugsAccess;
	extern bool BugShrub;
	extern bool WanderingBugs;
	extern bool BugRock;
	extern bool FishAccess;
	extern bool FishGroup;
	extern bool LoneFish;
	extern bool BombchuDrop;
	extern bool BuyBombchus5;
	extern bool BuyBombchus10;
	extern bool BuyBombchus20;

	//Helpers, Events, Locations
	extern bool MagicMeter;
	extern bool BombBag;
	extern bool Scarecrow;
	extern bool ScarecrowSong;
	extern bool Bombs;
	extern bool Nuts;
	extern bool Sticks;
	extern bool Bugs;
	extern bool Fish;
	extern bool HasBombchus;
	extern bool FoundBombchus;
	extern bool HasExplosives;
	extern bool CanBlastOrSmash;
	extern bool CanCutShrubs;
	extern bool CanDive;
	extern bool CanPlantBugs;
	extern bool CanRideEpona;
	extern bool CanPlantBean;
	extern bool CanOpenBombGrotto;
	extern bool CanOpenStormGrotto;
	extern bool HasFireSource;
	extern bool HasFireSourceWithTorch;
	extern bool HasShield;
	extern bool CanShield;
	extern bool IsItem;
	extern bool CanShootBubble;
	extern bool CanUseProjectile;

	//placement tracking
	extern u8 AddedProgressiveBombBags;
	extern u8 AddedProgressiveMagics;
	extern u8 AddedProgressiveBows;
	extern u8 AddedProgressiveWallets;
	extern u8 SwampTokensInPool;
	extern u8 OceanTokensInPool;

	enum class CanUseItem {
		Kokiri_Sword,
		DekuStick,
		Lens_of_Truth,
		Bow,
		Scarecrow,
		Fire_Arrows,
		Ice_Arrows,
		Light_Arrows,
		Sticks,
		Pictobox,
		PowderKeg,
		DekuMask,
		GoronMask,
		ZoraMask,
		BlastMask,
		GreatFairyMask,
		PostmansHat,
		AllNightMask,
		BremenMask,
		DonGerosMask,
		MaskOfScents,
		RomanisMask,
		CircusLeadersMask,
		KafeisMask,
		KamarosMask,
		CouplesMask,
		GibdosMask,
		GarosMask,
		CaptainsHat,
		GiantsMask,
		FierceDietyMask,
		MaskOfTruth,
	};
	void UpdateHelpers();
	bool CanPlay(bool song);
	bool CanUse(CanUseItem itemName);
	bool HasProjectile(CanUseItem itemName);
	bool SmallKeys(u8 dungeonKeyCount, u8 requiredAmount);
	bool EventsUpdated();
	bool LogicReset();
}