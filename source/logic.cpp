#include <string>
#include <array>
#include <vector>
#include <string_view>
#include <algorithm>
#include <3ds.h>
#include <cstdio>

#include "settings.hpp"
#include "logic.hpp"

using namespace Settings;

namespace Logic {

	bool noVariable = false;
	//item logic
	bool Ocarina = true;
	bool KokiriSword = false;
	bool HasBottle = false;
	bool Bombchus = false;
	bool DekuStick = false;
	bool MagicBean = false;
	bool MagicBeanPack = false;
	bool LensOfTruth = false;
	bool Bow = false;
	bool FireArrows = false;
	bool IceArrows = false;
	bool LightArrows = false;
	bool Hookshot = false;
	bool Pictobox = false;
	bool PowderKeg = false;
	bool Epona = false;
	//mask logic
	bool DekuMask = false;
	bool GoronMask = false;
	bool ZoraMask = false;
	bool KeatonMask = false;
	bool BunnyHood = false;
	bool PostmansHat = false;
	bool AllNightMask = false;
	bool BlastMask = false;
	bool StoneMask = false;
	bool GreatFairyMask = false;
	bool BremenMask = false;
	bool DonGerosMask = false;
	bool MaskOfScents = false;
	bool RomanisMask = false;
	bool CircusLeadersMask = false;
	bool KafeisMask = false;
	bool CouplesMask = false;
	bool KamarosMask = false;
	bool GibdosMask = false;
	bool GarosMask = false;
	bool CaptainsHat = false;
	bool GiantsMask = false;
	bool FierceDietyMask = false;
	bool MaskOfTruth = false;
	//trade items logic
	bool LandTitle = false;
	bool SwampTitle = false;
	bool MountainTitle = false;
	bool OceanTitle = false;
	bool RoomKey = false;
	bool LetterKafei = false;
	bool PendantOfMemories = false;
	bool LetterMama = false;
	bool MoonsTear = false;
	//trade quest events
	bool LandTitleAccess = false;
	bool SwampTitleAccess = false;
	bool MountainTitleAccess = false;
	bool OceanTitleAccess = false;
	bool RoomKeyAccess = false;
	bool LetterKafeiAccess = false;
	bool PendantAccess = false;
	bool LetterMamaAccess = false;
	bool MoonsTearAccess = false;
	//Songs
	bool SongOfStorms = false;
	bool SonataOfAwakening = false;
	bool GoronsLullaby = false;
	bool NewWaveBossaNova = false;
	bool ElegyOfEmptiness = false;
	bool OathToOrder = false;
	bool EponasSong = false;
	//Remains
	bool OdolwaRemains = false;
	bool GohtRemains = false;
	bool GyorgRemains = false;
	bool TwinmoldRemains = false;
	//Dungeon Clears
	bool WoodfallClear = false;
	bool SnowheadClear = false;
	bool GreatBayClear = false;
	bool StoneTowerClear = false;
	//Progressive Items
	u8 ProgressiveBow = 0;
	u8 ProgressiveMagic = 0;
	u8 ProgressiveWallet = 0;
	u8 ProgressiveBombBag = 0;
	//Keys
	u8 WoodfallTempleKeys = 0;
	u8 SnowheadTempleKeys = 0;
	u8 GreatBayTempleKeys = 0;
	u8 StoneTowerTempleKeys = 0;
	//Boss Keys
	bool BossKeyWoodfallTemple = false;
	bool BossKeySnowheadTemple = false;
	bool BossKeyGreatBayTemple = false;
	bool BossKeyStoneTowerTemple = false;
	//Skulltula Counts
	u8 SwampSkulltulaTokens = 0;
	u8 OceanSkulltulaTokens = 0;
	//Drops & Bottle Contents Access
	bool DekuNutDrop = false;
	bool NutPot = false;
	bool NutCrate = false;
	bool DekuBabaNuts = false;
	bool DekuStickDrop = false;
	bool StickPot = false;
	bool DekuBabaSticks = false;
	bool BugsAccess = false;
	bool BugShrub = false;
	bool WanderingBugs = false;
	bool BugRock = false;
	bool FishAccess = false;
	bool FishGroup = false;
	bool LoneFish = false;
	bool BombchuDrop = false;
	bool BuyBombchus5 = false;
	bool BuyBombchus10 = false;
	bool BuyBombchus20 = false;

	//Helpers, Events, Locations
	bool MagicMeter = false;
	bool BombBag = false;
	bool Scarecrow = false;
	bool ScarecrowSong = false;
	bool Bombs = false;
	bool Nuts = false;
	bool Sticks = false;
	bool Bugs = false;
	bool Fish = false;
	bool HasBombchus = false;
	bool FoundBombchus = false;
	bool HasExplosives = false;
	bool CanBlastOrSmash = false;
	bool CanCutShrubs = false;
	bool CanDive = false;
	bool CanPlantBugs = false;
	bool CanRideEpona = false;
	bool CanPlantBean = false;
	bool CanOpenBombGrotto = false;
	bool CanOpenStormGrotto = false;
	bool HasFireSource = false;
	bool HasFireSourceWithTorch = false;
	bool HasShield = false;
	bool CanShield = false;
	bool IsItem = false;
	bool CanShootBubble = false;
	bool CanUseProjectile = false;

	//placement tracking
	u8 AddedProgressiveBombBags = 0;
	u8 AddedProgressiveMagics = 0;
	u8 AddedProgressiveBows = 0;
	u8 AddedProgressiveWallets = 0;
	u8 SwampTokensInPool = 0;
	u8 OceanTokensInPool = 0;

	bool CanPlay(bool song) {
		return Ocarina && song;
	}

	static bool IsMagicItem(CanUseItem item) {
		return item == CanUseItem::Lens_of_Truth
		|| item == CanUseItem::ZoraMask;
	}

	static bool IsMagicArrow(CanUseItem item) {
		return item == CanUseItem::Fire_Arrows ||
			item == CanUseItem::Ice_Arrows ||
			item == CanUseItem::Light_Arrows;
	}
	static bool IsItemOrMask(CanUseItem item) {
		return (item == CanUseItem::Kokiri_Sword) ||
			(item == CanUseItem::DekuStick) ||
			(item == CanUseItem::Lens_of_Truth) ||
			(item == CanUseItem::Bow) ||
			(item == CanUseItem::Scarecrow) ||
			(item == CanUseItem::Fire_Arrows) ||
			(item == CanUseItem::Ice_Arrows) ||
			(item == CanUseItem::Light_Arrows) ||
			(item == CanUseItem::Sticks) ||
			(item == CanUseItem::Pictobox) ||
			(item == CanUseItem::PowderKeg) ||
			(item == CanUseItem::DekuMask) ||
			(item == CanUseItem::GoronMask) ||
			(item == CanUseItem::ZoraMask) ||
			(item == CanUseItem::BlastMask) ||
			(item == CanUseItem::GreatFairyMask) ||
			(item == CanUseItem::PostmansHat) ||
			(item == CanUseItem::AllNightMask) ||
			(item == CanUseItem::BremenMask) ||
			(item == CanUseItem::DonGerosMask) ||
			(item == CanUseItem::MaskOfScents) ||
			(item == CanUseItem::RomanisMask) ||
			(item == CanUseItem::CircusLeadersMask) ||
			(item == CanUseItem::KafeisMask) ||
			(item == CanUseItem::KamarosMask) ||
			(item == CanUseItem::CouplesMask) ||
			(item == CanUseItem::GibdosMask) ||
			(item == CanUseItem::GarosMask) ||
			(item == CanUseItem::CaptainsHat) ||
			(item == CanUseItem::GiantsMask) ||
			(item == CanUseItem::FierceDietyMask) ||
			(item == CanUseItem::MaskOfTruth);
	}
	static bool HasItem(CanUseItem itemName) {
		return (itemName == CanUseItem::Kokiri_Sword && KokiriSword) ||
			(itemName == CanUseItem::Lens_of_Truth && LensOfTruth) ||
			(itemName == CanUseItem::Bow && Bow) ||
			(itemName == CanUseItem::DekuStick && DekuStick)||
			(itemName == CanUseItem::Scarecrow && Scarecrow) ||
			(itemName == CanUseItem::Fire_Arrows && FireArrows) ||
			(itemName == CanUseItem::Ice_Arrows && IceArrows) ||
			(itemName == CanUseItem::Light_Arrows && LightArrows) ||
			(itemName == CanUseItem::Sticks && Sticks) ||
			(itemName == CanUseItem::Pictobox && Pictobox) ||
			(itemName == CanUseItem::PowderKeg && PowderKeg) ||
			(itemName == CanUseItem::DekuMask && DekuMask) ||
			(itemName == CanUseItem::GoronMask && GoronMask) ||
			(itemName == CanUseItem::ZoraMask && ZoraMask) ||
			(itemName == CanUseItem::BlastMask && BlastMask) ||
			(itemName == CanUseItem::GreatFairyMask && GreatFairyMask) ||
			(itemName == CanUseItem::PostmansHat && PostmansHat) ||
			(itemName == CanUseItem::AllNightMask && AllNightMask) ||
			(itemName == CanUseItem::BremenMask && BremenMask) ||
			(itemName == CanUseItem::DonGerosMask && DonGerosMask) ||
			(itemName == CanUseItem::MaskOfScents && MaskOfScents) ||
			(itemName == CanUseItem::RomanisMask && RomanisMask) ||
			(itemName == CanUseItem::CircusLeadersMask && CircusLeadersMask) ||
			(itemName == CanUseItem::KafeisMask && KafeisMask) ||
			(itemName == CanUseItem::KamarosMask && KamarosMask) ||
			(itemName == CanUseItem::CouplesMask && CouplesMask) ||
			(itemName == CanUseItem::GibdosMask && GibdosMask) ||
			(itemName == CanUseItem::GarosMask && GarosMask) ||
			(itemName == CanUseItem::CaptainsHat && CaptainsHat) ||
			(itemName == CanUseItem::GiantsMask && GiantsMask) ||
			(itemName == CanUseItem::FierceDietyMask && FierceDietyMask) ||
			(itemName == CanUseItem::MaskOfTruth && MaskOfTruth);
	}

	bool CanUse(CanUseItem itemName) {
		return (IsMagicItem(itemName) && HasItem(itemName) && MagicMeter) ||
			(IsMagicArrow(itemName) && HasItem(itemName) && MagicMeter && Bow) ||
			(IsItemOrMask(itemName) && HasItem(itemName) && IsItem);
	}

	bool HasProjectile(CanUseItem itemName) {
		return HasExplosives ||
			(IsItemOrMask(itemName) && HasItem(itemName) && Bow);
	}

	void UpdateHelpers() {
		MagicMeter = ProgressiveMagic >= 1;
		BombBag = ProgressiveBombBag >= 1;
		Bow = ProgressiveBow >= 1;
		Scarecrow = Hookshot && CanPlay(ScarecrowSong);

		//Drop Access
		DekuStickDrop = StickPot || DekuBabaSticks;
		DekuNutDrop = NutPot || NutCrate || DekuBabaNuts;
		BugsAccess = BugShrub || WanderingBugs || BugRock;
		FishAccess = LoneFish || FishGroup;

		//refills
		Bombs = BombBag;
		Nuts = DekuNutDrop || Nuts;
		Sticks = DekuStickDrop || Sticks;
		Bugs = HasBottle && BugsAccess;
		Fish = HasBottle && FishAccess;

		HasBombchus = (BuyBombchus5 || BuyBombchus10 || BuyBombchus20) && BombBag;
		FoundBombchus = Bombchus;
		HasExplosives = Bombs;

		CanBlastOrSmash = HasExplosives || CanUse(CanUseItem::GoronMask);
		CanDive = CanUse(CanUseItem::ZoraMask);
		CanPlantBugs = HasBottle && BugsAccess;
		CanRideEpona = Epona && CanPlay(EponasSong);
		CanPlantBean = MagicBean || MagicBeanPack;
		CanOpenStormGrotto = CanPlay(SongOfStorms);
		CanOpenBombGrotto = CanBlastOrSmash;

		HasFireSource = CanUse(CanUseItem::Fire_Arrows);
		HasFireSourceWithTorch = HasFireSource || CanUse(CanUseItem::DekuStick);

		CanUseProjectile = HasExplosives || CanUse(CanUseItem::Bow);

	}

	bool SmallKeys(u8 dungeonKeyCount, u8 requiredAmount) {
		return(dungeonKeyCount >= requiredAmount);
	}

	bool EventsUpdated() {
		return true;
	}
	//Resets all logic to false
	void logicReset() {
		noVariable = false;
		//item logic
		Ocarina = true;
		KokiriSword = false;
		HasBottle = false;
		Bombchus = false;
		DekuStick = false;
		MagicBean = false;
		MagicBeanPack = false;
		LensOfTruth = false;
		Bow = false;
		FireArrows = false;
		IceArrows = false;
		LightArrows = false;
		Hookshot = false;
		Pictobox = false;
		PowderKeg = false;
		Epona = false;
		//mask logic
		DekuMask = false;
		GoronMask = false;
		ZoraMask = false;
		KeatonMask = false;
		BunnyHood = false;
		PostmansHat = false;
		AllNightMask = false;
		BlastMask = false;
		StoneMask = false;
		GreatFairyMask = false;
		BremenMask = false;
		DonGerosMask = false;
		MaskOfScents = false;
		RomanisMask = false;
		CircusLeadersMask = false;
		KafeisMask = false;
		CouplesMask = false;
		KamarosMask = false;
		GibdosMask = false;
		GarosMask = false;
		CaptainsHat = false;
		GiantsMask = false;
		FierceDietyMask = false;
		MaskOfTruth = false;
		//trade items logic
		LandTitle = false;
		SwampTitle = false;
		MountainTitle = false;
		OceanTitle = false;
		RoomKey = false;
		LetterKafei = false;
		PendantOfMemories = false;
		LetterMama = false;
		MoonsTear = false;
		//trade quest events
		LandTitleAccess = false;
		SwampTitleAccess = false;
		MountainTitleAccess = false;
		OceanTitleAccess = false;
		RoomKeyAccess = false;
		LetterKafeiAccess = false;
		PendantAccess = false;
		LetterMamaAccess = false;
		MoonsTearAccess = false;
		//Songs
		SongOfStorms = false;
		SonataOfAwakening = false;
		GoronsLullaby = false;
		NewWaveBossaNova = false;
		ElegyOfEmptiness = false;
		OathToOrder = false;
		EponasSong = false;
		//Remains
		OdolwaRemains = false;
		GohtRemains = false;
		GyorgRemains = false;
		TwinmoldRemains = false;
		//Dungeon Clears
		WoodfallClear = false;
		SnowheadClear = false;
		GreatBayClear = false;
		StoneTowerClear = false;
		//Progressive Items
		ProgressiveBow = 0;
		ProgressiveMagic = 0;
		ProgressiveWallet = 0;
		ProgressiveBombBag = 0;
		//Keys
		WoodfallTempleKeys = 0;
		SnowheadTempleKeys = 0;
		GreatBayTempleKeys = 0;
		StoneTowerTempleKeys = 0;
		//Boss Keys
		BossKeyWoodfallTemple = false;
		BossKeySnowheadTemple = false;
		BossKeyGreatBayTemple = false;
		BossKeyStoneTowerTemple = false;
		//Skulltula Counts
		SwampSkulltulaTokens = 0;
		OceanSkulltulaTokens = 0;
		//Drops & Bottle Contents Access
		DekuNutDrop = false;
		NutPot = false;
		NutCrate = false;
		DekuBabaNuts = false;
		DekuStickDrop = false;
		StickPot = false;
		DekuBabaSticks = false;
		BugsAccess = false;
		BugShrub = false;
		WanderingBugs = false;
		BugRock = false;
		FishAccess = false;
		FishGroup = false;
		LoneFish = false;
		BombchuDrop = false;
		BuyBombchus5 = false;
		BuyBombchus10 = false;
		BuyBombchus20 = false;

		//Helpers, Events, Locations
		MagicMeter = false;
		BombBag = false;
		Scarecrow = false;
		ScarecrowSong = false;
		Bombs = false;
		Nuts = false;
		Sticks = false;
		Bugs = false;
		Fish = false;
		HasBombchus = false;
		FoundBombchus = false;
		HasExplosives = false;
		CanBlastOrSmash = false;
		CanCutShrubs = false;
		CanDive = false;
		CanPlantBugs = false;
		CanRideEpona = false;
		CanPlantBean = false;
		CanOpenBombGrotto = false;
		CanOpenStormGrotto = false;
		HasFireSource = false;
		HasFireSourceWithTorch = false;
		HasShield = false;
		CanShield = false;
		IsItem = false;
		CanShootBubble = false;
		CanUseProjectile = false;

		//placement tracking
		AddedProgressiveBombBags = 0;
		AddedProgressiveMagics = 0;
		AddedProgressiveBows = 0;
		AddedProgressiveWallets = 0;
		SwampTokensInPool = 0;
		OceanTokensInPool = 0;
	}
}

