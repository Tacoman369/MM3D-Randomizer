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
	bool KokiriSword = true;
	bool HasBottle = true;
	bool Bombchus = false;
	bool DekuStick = true;
	bool MagicBean = false;
	bool MagicBeanPack = true;
	bool LensOfTruth = false;
	bool Bow = false;
	bool HerosBow = false;
	bool FireArrows = false;
	bool IceArrows = false;
	bool LightArrows = false;
	bool Hookshot = false;
	bool Pictobox = true;
	bool PowderKeg = true;
	bool Seahorse = true;
	bool DekuPrincess = false;
	bool BigPoe = true;
	bool ZoraEgg = true;
	bool Mushroom = true;
	bool SpringWater = true;
	bool HotSpringWater = true;
	bool SpinAttack = true;
	bool Epona = true;
	bool WitchBottle = true;
	bool AlienBottle = true;
	bool GoronRaceBottle = true;
	bool BeaverRaceBottle = true;
	bool DampeBottle = true;
	bool ChateauBottle = true;
	bool BombersNotebook = true;
	bool MirrorShield = false;
	bool HerosShield = true;
	bool RazorSword = true;
	bool GildedSword = true;
	//bool GretFairysMask = false;
	bool BombBag20 = true;
	bool TownBombBag = true;
	bool MountainBombBag = true;
	bool TownArcheryQuiver = true;
	bool SwampArcheryQuiver = true;
	bool Townwallet200 = true;
	bool OceanWallet500 = true;
	bool MagicPower = true;
	bool ExtendedMagicPower = true;
	bool GreatFairySword = true;
	bool StoneTowerMagicBean = false;
	bool SwampScrubMagicBean = false;

	//mask logic
	bool DekuMask = true;
	bool GoronMask = true;
	bool ZoraMask = true;
	bool KeatonMask = true;
	bool BunnyHood = true;
	bool PostmansHat = true;
	bool AllNightMask = true;
	bool BlastMask = true;
	bool StoneMask = true;
	bool GreatFairyMask = true;
	bool BremenMask = true;
	bool DonGerosMask = true;
	bool MaskOfScents = true;
	bool RomanisMask = true;
	bool CircusLeadersMask = true;
	bool KafeisMask = true;
	bool CouplesMask = true;
	bool KamarosMask = true;
	bool GibdosMask = true;
	bool GarosMask = true;
	bool CaptainsHat = true;
	bool GiantsMask = true;
	bool FierceDietyMask = true;
	bool MaskOfTruth = true;
	bool OneMask = true;
	bool TwoMasks = true;
	bool ThreeMasks = true;
	bool FourMasks = true;
	bool AllMasks = true;
	//trade items logic
	bool LandTitle = true;
	bool SwampTitle = true;
	bool MountainTitle = true;
	bool OceanTitle = true;
	bool RoomKey = true;
	bool LetterKafei = true;
	bool PendantOfMemories = true;
	bool LetterMama = true;
	bool MoonsTear = true;
	//trade quest events
	bool LandTitleAccess = true;
	bool SwampTitleAccess = true;
	bool MountainTitleAccess = true;
	bool OceanTitleAccess = true;
	bool RoomKeyAccess = true;
	bool LetterKafeiAccess = true;
	bool PendantAccess = true;
	bool LetterMamaAccess = true;
	bool MoonsTearAccess = true;
	//Songs
	bool ScarecrowSong = true;
	bool SongOfStorms = true;
	bool SonataOfAwakening = true;
	bool SongOfHealing = true;
	bool GoronsLullaby = true;
	bool NewWaveBossaNova = true;
	bool ElegyOfEmptiness = true;
	bool OathToOrder = true;
	bool EponasSong = true;
	bool SongOfSoaring = true;
	//Remains
	bool OdolwaRemains = false;
	bool GohtRemains = false;
	bool GyorgRemains = false;
	bool TwinmoldRemains = false;
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
	//Stray Fairies
	u8 WoodfallStrayFairies = 0;
	u8 SnowheadStrayFairies = 0;
	u8 GBTStrayFairies = 0;
	u8 StoneTowerStrayFairies = 0;
	//Drops & Bottle Contents Access
	bool DekuNutDrop = true;
	bool NutPot = true;
	bool NutCrate = true;
	bool DekuBabaNuts = true;
	bool DekuStickDrop = true;
	bool StickPot = true;
	bool DekuBabaSticks = true;
	bool BugsAccess = true;
	bool BugShrub = true;
	bool WanderingBugs = true;
	bool BugRock = true;
	bool FishAccess = true;
	bool FishGroup = true;
	bool LoneFish = true;
	bool BombchuDrop = true;
	bool BuyBombchus5 = true;
	bool BuyBombchus10 = true;
	bool BuyBombchus20 = true;

	//Helpers, Events, Locations
	bool MagicMeter = true;
	bool BombBag = true;
	bool Explosives = true;
	bool Scarecrow = true;
	bool Bombs = true;
	bool Nuts = true;
	bool Sticks = true;
	bool Bugs = true;
	bool Fish = true;
	bool HasBombchus = false;
	bool FoundBombchus = false;
	bool HasExplosives = true;
	bool CanBlastOrSmash = true;
	bool CanCutShrubs = true;
	bool CanDive = true;
	bool CanPlantBugs = true;
	bool CanRideEpona = true;
	bool CanPlantBean = true;
	bool CanOpenBombGrotto = true;
	bool CanOpenStormGrotto = true;
	bool HasFireSource = true;
	bool HasFireSourceWithTorch = true;
	bool HasShield = true;
	bool CanShield = true;
	bool IsItem = true;
	bool CanShootBubble = true;
	bool CanUseProjectile = true;
	bool Arrows = false;
	bool AnyBottle = true;
	bool AnySword = true;
	bool AnyBombBag = true;
	bool AnyMagicBean = false;
	bool WaterForBeans = true;
	bool TwoBottles = true;
	bool AnyWallet = true;
	bool LimitlessBeans = true;
	bool AnyShield = true;
	bool AnyHealingPotion = true;
	bool AnyRedPotion = true;
	bool AnyBluePotion = true;
	bool UseFireArrow = false;
	bool UseIceArrow = false;
	bool UseLightArrow = false;
	bool AnyBSword = true;
	//dungeon clears
	bool WoodfallClear = false;
	bool SnowheadClear = false;
	bool GreatBayClear = false;
	bool StoneTowerClear = false;
	//Locational Helpers
	bool PoisonSwampAccess = true;
	bool WoodfallTempleAccess = true;
	bool NorthAccess = false;
	bool SnowheadTempleAccess = false;
	bool EponaAccess = false;
	bool WestAccess = false;
	bool PiratesFortressAccess = false;
	bool GreatBayTempleAccess = false;
	bool EastAccess = false;
	bool IkanaCanyonAccess = false;
	bool StoneTowerTempleAcccess = false;
	bool InvertedStoneTowerTempleAccess = false;
	bool MoonAccess = false;
	bool OneWoodfallKey = false;
	bool OneSnowheadKey = false;
	bool TwoSnowheadKeys = false;
	bool OneGreatBayKey = false;
	bool OneStoneTowerKey = false;
	bool TwoStoneTowerKeys = false;
	bool ThreeStoneTowerKeys = false;
	bool SwampSpiderhouseTreeRoom = false;
	bool OceanSkulltulas = false;
	bool IkanaGraveyardAccess = false;
	bool FightTwinmold = false;
	bool PinnacleRockAccess = false;
	bool ExitOceanSpiderHouse = false;
	bool NightInnAccess = false;
	bool EnterSnowheadTemple = false;
	bool GBTReverseWaterDirection = false;
	bool Fighting = true;
	bool CrossPoisonWater = false;
	bool AccessToAllOceanSpiders = false;
	bool AccessToAllSwampSpiders = false;
	bool ClockTownStrayFairy = true;
	bool AllWoodfallStrays = true;
	bool AllSnowheadStrays = true;
	bool AllGreatBayStrays = true;
	bool AllStoneTowerStrays = true;
	bool AnyPaper = true;
	//Tricks
	bool DekuStickFighting = true;
	bool PoisonWaterAsZora = true;
	bool WFT2ndFloorSkip = true;
	bool TakeDamage = true;

	//placement tracking
	u8 AddedProgressiveBombBags = 0;
	u8 AddedProgressiveMagics = 0;
	u8 AddedProgressiveBows = 0;
	u8 AddedProgressiveWallets = 0;
	u8 SwampTokensInPool = 0;
	u8 OceanTokensInPool = 0;
	u8 WFStraysInPool = 0;
	u8 SHStraysInPool = 0;
	u8 STStraysInPool = 0;
	u8 PlacedMasks = 0;

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
		MagicMeter = (ProgressiveMagic >= 1) || MagicPower || ExtendedMagicPower;
		AnyBombBag = (ProgressiveBombBag >= 1) || BombBag20 || TownBombBag || MountainBombBag;
		Bow = ProgressiveBow >= 1 || HerosBow;
		Scarecrow = Hookshot && CanPlay(ScarecrowSong);
		HasBottle = AnyBottle;
		//Drop Access
		DekuStickDrop = StickPot || DekuBabaSticks;
		DekuNutDrop = NutPot || NutCrate || DekuBabaNuts;
		BugsAccess = BugShrub || WanderingBugs || BugRock;
		FishAccess = LoneFish || FishGroup;

		//refills
		Bombs = AnyBombBag;
		Nuts = DekuNutDrop || Nuts;
		Sticks = DekuStickDrop || Sticks;
		Bugs = HasBottle && BugsAccess;
		Fish = HasBottle && FishAccess;

		HasBombchus = (BuyBombchus5 || BuyBombchus10 || BuyBombchus20) && AnyBombBag;
		FoundBombchus = Bombchus;
		HasExplosives = Bombs;

		CanBlastOrSmash = HasExplosives || CanUse(CanUseItem::GoronMask);
		CanDive = CanUse(CanUseItem::ZoraMask);
		CanPlantBugs = HasBottle && BugsAccess;
		CanRideEpona = Epona && CanPlay(EponasSong);
		CanPlantBean = MagicBean || MagicBeanPack;
		CanOpenStormGrotto = CanPlay(SongOfStorms);
		CanOpenBombGrotto = CanBlastOrSmash;
		DekuStickFighting = DekuStick;
		HasFireSource = CanUse(CanUseItem::Fire_Arrows);
		HasFireSourceWithTorch = HasFireSource || CanUse(CanUseItem::DekuStick);

		CanUseProjectile = HasExplosives || CanUse(CanUseItem::Bow);

		Explosives = BlastMask || AnyBombBag;
		Arrows = Bow || TownArcheryQuiver || SwampArcheryQuiver;
		UseFireArrow = Arrows && FireArrows && MagicMeter;
		UseIceArrow = Arrows && IceArrows && MagicMeter;
		UseLightArrow = Arrows && LightArrows && MagicMeter;
		AnyBSword = KokiriSword || GildedSword || RazorSword;

		DekuPrincess = WoodfallClear && AnyBottle;
		BigPoe = IkanaCanyonAccess && GibdosMask && AnyBottle && AnyBombBag;
		HotSpringWater = NorthAccess && AnyBottle && (SnowheadClear || UseFireArrow);
		SpringWater = AnyBottle;
		ZoraEgg = PiratesFortressAccess && Hookshot && AnyBottle && PinnacleRockAccess && ((DekuMask && MagicMeter) || Arrows);
		Mushroom = MaskOfScents && AnyBottle;
		Seahorse = Pictobox && WestAccess && PiratesFortressAccess;



		PoisonSwampAccess = CrossPoisonWater;
		WoodfallTempleAccess = DekuMask && SonataOfAwakening && PoisonSwampAccess && Fighting;
		WoodfallClear = WoodfallTempleAccess && Arrows && BossKeyWoodfallTemple;
		NorthAccess = HasExplosives || Arrows;
		SnowheadTempleAccess = NorthAccess && GoronMask && MagicMeter && GoronsLullaby;
		SnowheadClear = SnowheadTempleAccess && BossKeySnowheadTemple && GoronMask && UseFireArrow;
		EponaAccess = GoronMask && PowderKeg;
		WestAccess = EponasSong;
		PiratesFortressAccess = WestAccess && ZoraMask;
		GreatBayTempleAccess = PiratesFortressAccess && NewWaveBossaNova && Hookshot;
		GreatBayClear = GreatBayTempleAccess && BossKeyGreatBayTemple && ZoraMask && Hookshot && UseIceArrow;
		EastAccess = Hookshot && IkanaGraveyardAccess && (GibdosMask || GarosMask);
		IkanaCanyonAccess = EastAccess && UseIceArrow;
		StoneTowerTempleAcccess = IkanaCanyonAccess && Hookshot && ElegyOfEmptiness && ZoraMask && GoronMask && DekuMask;
		InvertedStoneTowerTempleAccess = StoneTowerTempleAcccess && UseLightArrow;
		StoneTowerClear = InvertedStoneTowerTempleAccess && Hookshot && BossKeyStoneTowerTemple && GiantsMask && UseLightArrow;
		MoonAccess = StoneTowerClear && GreatBayClear && SnowheadClear && WoodfallClear;
		OneSnowheadKey = SnowheadTempleKeys == 1;
		TwoSnowheadKeys = SnowheadTempleKeys == 2;
		OneStoneTowerKey = StoneTowerTempleKeys == 1;
		TwoStoneTowerKeys = StoneTowerTempleKeys == 2;
		ThreeStoneTowerKeys = StoneTowerTempleKeys == 3;
		OneWoodfallKey = WoodfallTempleKeys == 1;
		OneGreatBayKey = GreatBayTempleKeys == 1;
		AnyBottle = WitchBottle || AlienBottle || BeaverRaceBottle || DampeBottle || GoronRaceBottle || ChateauBottle;
		AnySword = GreatFairySword || AnyBSword;
		AnyBombBag = BombBag20 || TownBombBag || MountainBombBag || BombBag;
		SwampSpiderhouseTreeRoom = PoisonSwampAccess;
		OceanSkulltulas = Explosives && WestAccess && ExitOceanSpiderHouse && Hookshot;
		AnyMagicBean = MagicBean || StoneTowerMagicBean || SwampScrubMagicBean || (DekuMask && PoisonSwampAccess);
		WaterForBeans = (AnyBottle && (SpringWater || HotSpringWater)) || SongOfStorms;
		TwoBottles = { (WitchBottle && AlienBottle) || (WitchBottle && BeaverRaceBottle) || (WitchBottle && DampeBottle) ||
			(WitchBottle && GoronRaceBottle) || (WitchBottle && ChateauBottle) || (AlienBottle && GoronRaceBottle) ||
			(AlienBottle && BeaverRaceBottle) || (AlienBottle && DampeBottle) || (AlienBottle && ChateauBottle) ||
			(GoronRaceBottle && BeaverRaceBottle) || (GoronRaceBottle && DampeBottle) || (GoronRaceBottle && ChateauBottle) ||
			(BeaverRaceBottle && DampeBottle) || (BeaverRaceBottle && ChateauBottle) || (DampeBottle && ChateauBottle) };
		AnyWallet = Townwallet200 || OceanWallet500;
		LimitlessBeans = PoisonSwampAccess && DekuMask;
		IkanaGraveyardAccess = EponasSong;
		FightTwinmold = GiantsMask && AnySword && UseLightArrow;
		PinnacleRockAccess = ZoraMask && (Seahorse && AnyBottle);
		ExitOceanSpiderHouse = GoronMask;
		NightInnAccess = DekuMask || RoomKey;
		EnterSnowheadTemple = GoronMask && MagicMeter;
		GBTReverseWaterDirection = UseIceArrow;
		Fighting = GoronMask || ZoraMask || AnySword || DekuStickFighting;
		AnyShield = HerosShield || MirrorShield;
		AnyHealingPotion = AnyRedPotion || AnyBluePotion;
		AnyRedPotion = AnyBottle;
		AnyBluePotion = AnyBottle;
		CrossPoisonWater = DekuMask || (GoronMask && TakeDamage) || (ZoraMask && TakeDamage);
		AccessToAllSwampSpiders = PoisonSwampAccess && Bugs && DekuMask && MagicMeter && Fighting && (Hookshot || ZoraMask);
		AccessToAllOceanSpiders = OceanSkulltulas && UseFireArrow;
		AllWoodfallStrays = WoodfallClear;
		AllSnowheadStrays = SnowheadClear;
		AllGreatBayStrays = GreatBayClear;
		AllStoneTowerStrays = StoneTowerClear;
		AnyPaper = (LandTitle || SwampTitle || OceanTitle || MountainTitle || LetterKafei || LetterMama);

		PoisonWaterAsZora = ZoraMask && TakeDamage;
		WFT2ndFloorSkip = Hookshot;

		OneMask = (PostmansHat || AllNightMask || BlastMask || StoneMask || GreatFairyMask || KeatonMask || BremenMask || BunnyHood ||
			DonGerosMask || MaskOfScents || RomanisMask || CircusLeadersMask || KafeisMask || CouplesMask || MaskOfTruth || KamarosMask ||
			GibdosMask || GarosMask || CaptainsHat || GiantsMask);
		TwoMasks = ( (PostmansHat && AllNightMask) || (PostmansHat && BlastMask) || (PostmansHat && StoneMask) || (PostmansHat && GreatFairyMask) ||
			(PostmansHat && KeatonMask) || (PostmansHat && BremenMask) || (PostmansHat && BunnyHood) || (PostmansHat && DonGerosMask) ||
			(PostmansHat && MaskOfScents) || (PostmansHat && RomanisMask) || (PostmansHat && CircusLeadersMask) || (PostmansHat && KafeisMask) ||
			(PostmansHat && CouplesMask) || (PostmansHat && MaskOfTruth) || (PostmansHat && GibdosMask) || (PostmansHat && GarosMask) ||
			(PostmansHat && CaptainsHat) || (PostmansHat && GiantsMask) || (AllNightMask && BlastMask) || (AllNightMask && StoneMask) ||
			(AllNightMask && GreatFairyMask) || (AllNightMask && KeatonMask) || (AllNightMask && BremenMask) || (AllNightMask && BunnyHood) ||
			(AllNightMask && DonGerosMask) || (AllNightMask && MaskOfScents) || (AllNightMask && RomanisMask) || (AllNightMask && CircusLeadersMask) ||
			(AllNightMask && KafeisMask) || (AllNightMask && CouplesMask) || (AllNightMask && MaskOfTruth) || (AllNightMask && KamarosMask) ||
			(AllNightMask && GibdosMask) || (AllNightMask && GarosMask) || (AllNightMask && CaptainsHat) || (AllNightMask && GiantsMask) || (BlastMask && StoneMask) ||
			(BlastMask && GreatFairyMask) || (BlastMask && KeatonMask) || (BlastMask && BremenMask) || (BlastMask && BunnyHood) || (BlastMask && DonGerosMask) ||
			(BlastMask && MaskOfScents) || (BlastMask && RomanisMask) || (BlastMask && CircusLeadersMask) || (BlastMask && KafeisMask) || (BlastMask && CouplesMask) ||
			(BlastMask && MaskOfTruth) || (BlastMask && KamarosMask) || (BlastMask && GibdosMask) || (BlastMask && GarosMask) || (BlastMask && CaptainsHat) ||
			(BlastMask && GiantsMask) || (StoneMask && GreatFairyMask) || (StoneMask && KeatonMask) || (StoneMask && BremenMask) || (StoneMask && BunnyHood) ||
			(StoneMask && DonGerosMask) || (StoneMask && MaskOfScents) || (StoneMask && RomanisMask) || (StoneMask && CircusLeadersMask) || (StoneMask && KafeisMask) ||
			(StoneMask && CouplesMask) || (StoneMask && MaskOfTruth) || (StoneMask && KamarosMask) || (StoneMask && GibdosMask) || (StoneMask && GarosMask) ||
			(StoneMask && CaptainsHat) || (StoneMask && GiantsMask) || (GreatFairyMask && KeatonMask) || (GreatFairyMask && BremenMask) || (GreatFairyMask && BunnyHood) ||
			(GreatFairyMask && DonGerosMask) || (GreatFairyMask && MaskOfScents) || (GreatFairyMask && RomanisMask) || (GreatFairyMask && CircusLeadersMask) ||
			(GreatFairyMask && KafeisMask) || (GreatFairyMask && CouplesMask) || (GreatFairyMask && MaskOfTruth) || (GreatFairyMask && KamarosMask) ||
			(GreatFairyMask && GibdosMask) || (GreatFairyMask && GarosMask) || (GreatFairyMask && CaptainsHat) || (GreatFairyMask && GiantsMask) ||
			(KeatonMask && BremenMask) || (KeatonMask && BunnyHood) || (KeatonMask && DonGerosMask) || (KeatonMask && MaskOfScents) || (KeatonMask && RomanisMask) ||
			(KeatonMask && CircusLeadersMask) || (KeatonMask && KafeisMask) || (KeatonMask && CouplesMask) || (KeatonMask && MaskOfTruth) || (KeatonMask && KamarosMask) ||
			(KeatonMask && GibdosMask) || (KeatonMask && GarosMask) || (KeatonMask && CaptainsHat) || (KeatonMask && GiantsMask) || (BremenMask && BunnyHood) ||
			(BremenMask && DonGerosMask) || (BremenMask && MaskOfScents) || (BremenMask && RomanisMask) || (BremenMask && CircusLeadersMask) || (BremenMask && KafeisMask) ||
			(BremenMask && CouplesMask) || (BremenMask && MaskOfTruth) || (BremenMask && KamarosMask) || (BremenMask && GibdosMask) || (BremenMask && GarosMask) ||
			(BremenMask && CaptainsHat) || (BremenMask && GiantsMask) || (BunnyHood && DonGerosMask) || (BunnyHood && MaskOfScents) || (BunnyHood && RomanisMask) ||
			(BunnyHood && CircusLeadersMask) || (BunnyHood && KafeisMask) || (BunnyHood && CouplesMask) || (BunnyHood && MaskOfTruth) || (BunnyHood && KamarosMask) ||
			(BunnyHood && GibdosMask) || (BunnyHood && GarosMask) || (BunnyHood && CaptainsHat) || (BunnyHood && GiantsMask) || (DonGerosMask && MaskOfScents) ||
			(DonGerosMask && RomanisMask) || (DonGerosMask && CircusLeadersMask) || (DonGerosMask && KafeisMask) || (DonGerosMask && CouplesMask) ||
			(DonGerosMask && MaskOfTruth) || (DonGerosMask && KamarosMask) || (DonGerosMask && GibdosMask) || (DonGerosMask && GarosMask) || (DonGerosMask && CaptainsHat) ||
			(DonGerosMask && GiantsMask) || (MaskOfScents && RomanisMask) || (MaskOfScents && CircusLeadersMask) || (MaskOfScents && KafeisMask) || (MaskOfScents && CouplesMask) ||
			(MaskOfScents && MaskOfTruth) || (MaskOfScents && KamarosMask) || (MaskOfScents && GibdosMask) || (MaskOfScents && GarosMask) || (MaskOfScents && CaptainsHat) ||
			(MaskOfScents && GiantsMask) || (RomanisMask && CircusLeadersMask) || (RomanisMask && KafeisMask) || (RomanisMask && CouplesMask) || (RomanisMask && MaskOfTruth) ||
			(RomanisMask && KamarosMask) || (RomanisMask && GibdosMask) || (RomanisMask && GarosMask) || (RomanisMask && CaptainsHat) || (RomanisMask && GiantsMask) ||
			(CircusLeadersMask && KafeisMask) || (CircusLeadersMask && CouplesMask) || (CircusLeadersMask && MaskOfTruth) || (CircusLeadersMask && KamarosMask) ||
			(CircusLeadersMask && GibdosMask) || (CircusLeadersMask && GarosMask) || (CircusLeadersMask && CaptainsHat) || (CircusLeadersMask && GiantsMask) ||
			(KafeisMask && CouplesMask) || (KafeisMask && MaskOfTruth) || (KafeisMask && KamarosMask) || (KafeisMask && GibdosMask) || (KafeisMask && GarosMask) ||
			(KafeisMask && CaptainsHat) || (KafeisMask && GiantsMask) || (CouplesMask && MaskOfTruth) || (CouplesMask && KamarosMask) || (CouplesMask && GibdosMask) ||
			(CouplesMask && GarosMask) || (CouplesMask && CaptainsHat) || (CouplesMask && GiantsMask) || (MaskOfTruth && KamarosMask) || (MaskOfTruth && GibdosMask) ||
			(MaskOfTruth && GarosMask) || (MaskOfTruth && CaptainsHat) || (MaskOfTruth && GiantsMask) || (KamarosMask && GibdosMask) || (KamarosMask && GarosMask) ||
			(KamarosMask && CaptainsHat) || (KamarosMask && GiantsMask) || (GibdosMask && GarosMask) || (GibdosMask && CaptainsHat) || (GibdosMask && GiantsMask) ||
			(GarosMask && CaptainsHat) || (GarosMask && GiantsMask) || (CaptainsHat && GiantsMask) );

		ThreeMasks = ( (PostmansHat && AllNightMask && BlastMask) || (PostmansHat && AllNightMask && StoneMask) || (PostmansHat && AllNightMask && GreatFairyMask) ||
			(PostmansHat && AllNightMask && KeatonMask) || (PostmansHat && AllNightMask && BremenMask) || (PostmansHat && AllNightMask && BunnyHood) ||
			(PostmansHat && AllNightMask && DonGerosMask) || (PostmansHat && AllNightMask && MaskOfScents) || (PostmansHat && AllNightMask && RomanisMask) ||
			(PostmansHat && AllNightMask && CircusLeadersMask) || (PostmansHat && AllNightMask && KafeisMask) || (PostmansHat && AllNightMask && CouplesMask) ||
			(PostmansHat && AllNightMask && MaskOfTruth) || (PostmansHat && AllNightMask && GibdosMask) || (PostmansHat && AllNightMask && GarosMask) ||
			(PostmansHat && AllNightMask && CaptainsHat) || (PostmansHat && AllNightMask && GiantsMask) || (PostmansHat && BlastMask && StoneMask) ||
			(PostmansHat && BlastMask && GreatFairyMask) || (PostmansHat && BlastMask && KeatonMask) || (PostmansHat && BlastMask && BremenMask) ||
			(PostmansHat && BlastMask && BunnyHood) || (PostmansHat && BlastMask && DonGerosMask) || (PostmansHat && BlastMask && MaskOfScents) ||
			(PostmansHat && BlastMask && RomanisMask) || (PostmansHat && BlastMask && CircusLeadersMask) || (PostmansHat && BlastMask && KafeisMask) ||
			(PostmansHat && BlastMask && CouplesMask) || (PostmansHat && BlastMask && MaskOfTruth) || (PostmansHat && BlastMask && GibdosMask) ||
			(PostmansHat && BlastMask && GarosMask) || (PostmansHat && BlastMask && CaptainsHat) || (PostmansHat && BlastMask && GiantsMask) ||
			(PostmansHat && StoneMask && GreatFairyMask) || (PostmansHat && StoneMask && KeatonMask) || (PostmansHat && StoneMask && BremenMask) ||
			(PostmansHat && StoneMask && BunnyHood) || (PostmansHat && StoneMask && DonGerosMask) || (PostmansHat && StoneMask && MaskOfScents) ||
			(PostmansHat && StoneMask && RomanisMask) || (PostmansHat && StoneMask && CircusLeadersMask) || (PostmansHat && StoneMask && KafeisMask) ||
			(PostmansHat && StoneMask && CouplesMask) || (PostmansHat && StoneMask && MaskOfTruth) || (PostmansHat && StoneMask && GibdosMask) ||
			(PostmansHat && StoneMask && GarosMask) || (PostmansHat && StoneMask && CaptainsHat) || (PostmansHat && StoneMask && GiantsMask) ||
			(PostmansHat && GreatFairyMask && KeatonMask) || (PostmansHat && GreatFairyMask && BremenMask) || (PostmansHat && GreatFairyMask && BunnyHood) ||
			(PostmansHat && GreatFairyMask && DonGerosMask) || (PostmansHat && GreatFairyMask && MaskOfScents) || (PostmansHat && GreatFairyMask && RomanisMask) ||
			(PostmansHat && GreatFairyMask && CircusLeadersMask) || (PostmansHat && GreatFairyMask && KafeisMask) || (PostmansHat && GreatFairyMask && CouplesMask) ||
			(PostmansHat && GreatFairyMask && MaskOfTruth) || (PostmansHat && GreatFairyMask && GibdosMask) || (PostmansHat && GreatFairyMask && GarosMask) ||
			(PostmansHat && GreatFairyMask && CaptainsHat) || (PostmansHat && GreatFairyMask && GiantsMask) || (PostmansHat && KeatonMask && BremenMask) ||
			(PostmansHat && KeatonMask && BunnyHood) || (PostmansHat && KeatonMask && DonGerosMask) || (PostmansHat && KeatonMask && MaskOfScents) ||
			(PostmansHat && KeatonMask && RomanisMask) || (PostmansHat && KeatonMask && CircusLeadersMask) || (PostmansHat && KeatonMask && KafeisMask) ||
			(PostmansHat && KeatonMask && CouplesMask) || (PostmansHat && KeatonMask && MaskOfTruth) || (PostmansHat && KeatonMask && GibdosMask) ||
			(PostmansHat && KeatonMask && GarosMask) || (PostmansHat && KeatonMask && CaptainsHat) || (PostmansHat && KeatonMask && GiantsMask) ||
			(PostmansHat && BremenMask && BunnyHood) || (PostmansHat && BremenMask && DonGerosMask) || (PostmansHat && BremenMask && MaskOfScents) ||
			(PostmansHat && BremenMask && RomanisMask) || (PostmansHat && BremenMask && CircusLeadersMask) || (PostmansHat && BremenMask && KafeisMask) ||
			(PostmansHat && BremenMask && CouplesMask) || (PostmansHat && BremenMask && MaskOfTruth) || (PostmansHat && BremenMask && GibdosMask) ||
			(PostmansHat && BremenMask && GarosMask) || (PostmansHat && BremenMask && CaptainsHat) || (PostmansHat && BremenMask && GiantsMask) ||
			(PostmansHat && BunnyHood && DonGerosMask) || (PostmansHat && BunnyHood && MaskOfScents) || (PostmansHat && BunnyHood && RomanisMask) ||
			(PostmansHat && BunnyHood && CircusLeadersMask) || (PostmansHat && BunnyHood && KafeisMask) || (PostmansHat && BunnyHood && CouplesMask) ||
			(PostmansHat && BunnyHood && MaskOfTruth) || (PostmansHat && BunnyHood && GibdosMask) || (PostmansHat && BunnyHood && GarosMask) ||
			(PostmansHat && BunnyHood && CaptainsHat) || (PostmansHat && BunnyHood && GiantsMask) || (PostmansHat && DonGerosMask && MaskOfScents) ||
			(PostmansHat && DonGerosMask && RomanisMask) || (PostmansHat && DonGerosMask && CircusLeadersMask) || (PostmansHat && DonGerosMask && KafeisMask) ||
			(PostmansHat && DonGerosMask && CouplesMask) || (PostmansHat && DonGerosMask && MaskOfTruth) || (PostmansHat && DonGerosMask && GibdosMask) ||
			(PostmansHat && DonGerosMask && GarosMask) || (PostmansHat && DonGerosMask && CaptainsHat) || (PostmansHat && DonGerosMask && GiantsMask) ||
			(PostmansHat && MaskOfScents && RomanisMask) || (PostmansHat && MaskOfScents && CircusLeadersMask) || (PostmansHat && MaskOfScents && KafeisMask) ||
			(PostmansHat && MaskOfScents && CouplesMask) || (PostmansHat && MaskOfScents && MaskOfTruth) || (PostmansHat && MaskOfScents && GibdosMask) ||
			(PostmansHat && MaskOfScents && GarosMask) || (PostmansHat && MaskOfScents && CaptainsHat) || (PostmansHat && MaskOfScents && GiantsMask) ||
			(PostmansHat && RomanisMask && CircusLeadersMask) || (PostmansHat && RomanisMask && KafeisMask) || (PostmansHat && RomanisMask && CouplesMask) ||
			(PostmansHat && RomanisMask && MaskOfTruth) || (PostmansHat && RomanisMask && GibdosMask) || (PostmansHat && RomanisMask && GarosMask) ||
			(PostmansHat && RomanisMask && CaptainsHat) || (PostmansHat && RomanisMask && GiantsMask) || (PostmansHat && CircusLeadersMask && KafeisMask) ||
			(PostmansHat && CircusLeadersMask && CouplesMask) || (PostmansHat && CircusLeadersMask && MaskOfTruth) || (PostmansHat && CircusLeadersMask && GibdosMask) ||
			(PostmansHat && CircusLeadersMask && GarosMask) || (PostmansHat && CircusLeadersMask && CaptainsHat) || (PostmansHat && CircusLeadersMask && GiantsMask) ||
			(PostmansHat && KafeisMask && CouplesMask) || (PostmansHat && KafeisMask && MaskOfTruth) || (PostmansHat && KafeisMask && GibdosMask) ||
			(PostmansHat && KafeisMask && GarosMask) || (PostmansHat && KafeisMask && CaptainsHat) || (PostmansHat && KafeisMask && GiantsMask) ||
			(PostmansHat && CouplesMask && MaskOfTruth) || (PostmansHat && CouplesMask && GibdosMask) || (PostmansHat && CouplesMask && GarosMask) ||
			(PostmansHat && CouplesMask && CaptainsHat) || (PostmansHat && CouplesMask && GiantsMask) || (PostmansHat && MaskOfTruth && GibdosMask) ||
			(PostmansHat && MaskOfTruth && GarosMask) || (PostmansHat && MaskOfTruth && CaptainsHat) || (PostmansHat && MaskOfTruth && GiantsMask) ||
			(PostmansHat && GibdosMask && GarosMask) || (PostmansHat && GibdosMask && CaptainsHat) || (PostmansHat && GibdosMask && GiantsMask) ||
			(PostmansHat && GarosMask && CaptainsHat) || (PostmansHat && GarosMask && GiantsMask) || (PostmansHat && CaptainsHat && GiantsMask) ||
			(AllNightMask && BlastMask && StoneMask) || (AllNightMask && BlastMask && GreatFairyMask) || (AllNightMask && BlastMask && KeatonMask) ||
			(AllNightMask && BlastMask && BremenMask) || (AllNightMask && BlastMask && BunnyHood) || (AllNightMask && BlastMask && DonGerosMask) ||
			(AllNightMask && BlastMask && MaskOfScents) || (AllNightMask && BlastMask && RomanisMask) || (AllNightMask && BlastMask && CircusLeadersMask) ||
			(AllNightMask && BlastMask && KafeisMask) || (AllNightMask && BlastMask && CouplesMask) || (AllNightMask && BlastMask && MaskOfTruth) ||
			(AllNightMask && BlastMask && GibdosMask) || (AllNightMask && BlastMask && GarosMask) || (AllNightMask && BlastMask && CaptainsHat) ||
			(AllNightMask && BlastMask && GiantsMask) || (AllNightMask && StoneMask && GreatFairyMask) || (AllNightMask && StoneMask && KeatonMask) ||
			(AllNightMask && StoneMask && BremenMask) || (AllNightMask && StoneMask && BunnyHood) || (AllNightMask && StoneMask && DonGerosMask) ||
			(AllNightMask && StoneMask && MaskOfScents) || (AllNightMask && StoneMask && RomanisMask) || (AllNightMask && StoneMask && CircusLeadersMask) ||
			(AllNightMask && StoneMask && KafeisMask) || (AllNightMask && StoneMask && CouplesMask) || (AllNightMask && StoneMask && MaskOfTruth) ||
			(AllNightMask && StoneMask && GibdosMask) || (AllNightMask && StoneMask && GarosMask) || (AllNightMask && StoneMask && CaptainsHat) ||
			(AllNightMask && StoneMask && GiantsMask) || (AllNightMask && GreatFairyMask && KeatonMask) || (AllNightMask && GreatFairyMask && BremenMask) ||
			(AllNightMask && GreatFairyMask && BunnyHood) || (AllNightMask && GreatFairyMask && DonGerosMask) || (AllNightMask && GreatFairyMask && MaskOfScents) ||
			(AllNightMask && GreatFairyMask && RomanisMask) || (AllNightMask && GreatFairyMask && CircusLeadersMask) || (AllNightMask && GreatFairyMask && KafeisMask) ||
			(AllNightMask && GreatFairyMask && CouplesMask) || (AllNightMask && GreatFairyMask && MaskOfTruth) || (AllNightMask && GreatFairyMask && GibdosMask) ||
			(AllNightMask && GreatFairyMask && GarosMask) || (AllNightMask && GreatFairyMask && CaptainsHat) || (AllNightMask && GreatFairyMask && GiantsMask) ||
			(AllNightMask && KeatonMask && BremenMask) || (AllNightMask && KeatonMask && BunnyHood) || (AllNightMask && KeatonMask && DonGerosMask) ||
			(AllNightMask && KeatonMask && MaskOfScents) || (AllNightMask && KeatonMask && RomanisMask) || (AllNightMask && KeatonMask && CircusLeadersMask) ||
			(AllNightMask && KeatonMask && KafeisMask) || (AllNightMask && KeatonMask && CouplesMask) || (AllNightMask && KeatonMask && MaskOfTruth) ||
			(AllNightMask && KeatonMask && GibdosMask) || (AllNightMask && KeatonMask && GarosMask) || (AllNightMask && KeatonMask && CaptainsHat) ||
			(AllNightMask && KeatonMask && GiantsMask) || (AllNightMask && BremenMask && BunnyHood) || (AllNightMask && BremenMask && DonGerosMask) ||
			(AllNightMask && BremenMask && MaskOfScents) || (AllNightMask && BremenMask && RomanisMask) || (AllNightMask && BremenMask && CircusLeadersMask) ||
			(AllNightMask && BremenMask && KafeisMask) || (AllNightMask && BremenMask && CouplesMask) || (AllNightMask && BremenMask && MaskOfTruth) ||
			(AllNightMask && BremenMask && GibdosMask) || (AllNightMask && BremenMask && GarosMask) || (AllNightMask && BremenMask && CaptainsHat) ||
			(AllNightMask && BremenMask && GiantsMask) || (AllNightMask && BunnyHood && DonGerosMask) || (AllNightMask && BunnyHood && MaskOfScents) ||
			(AllNightMask && BunnyHood && RomanisMask) || (AllNightMask && BunnyHood && CircusLeadersMask) || (AllNightMask && BunnyHood && KafeisMask) ||
			(AllNightMask && BunnyHood && CouplesMask) || (AllNightMask && BunnyHood && MaskOfTruth) || (AllNightMask && BunnyHood && GibdosMask) ||
			(AllNightMask && BunnyHood && GarosMask) || (AllNightMask && BunnyHood && CaptainsHat) || (AllNightMask && BunnyHood && GiantsMask) ||
			(AllNightMask && DonGerosMask && MaskOfScents) || (AllNightMask && DonGerosMask && RomanisMask) || (AllNightMask && DonGerosMask && CircusLeadersMask) ||
			(AllNightMask && DonGerosMask && KafeisMask) || (AllNightMask && DonGerosMask && CouplesMask) || (AllNightMask && DonGerosMask && MaskOfTruth) ||
			(AllNightMask && DonGerosMask && GibdosMask) || (AllNightMask && DonGerosMask && GarosMask) || (AllNightMask && DonGerosMask && CaptainsHat) ||
			(AllNightMask && DonGerosMask && GiantsMask) || (AllNightMask && MaskOfScents && RomanisMask) || (AllNightMask && MaskOfScents && CircusLeadersMask) ||
			(AllNightMask && MaskOfScents && KafeisMask) || (AllNightMask && MaskOfScents && CouplesMask) || (AllNightMask && MaskOfScents && MaskOfTruth) ||
			(AllNightMask && MaskOfScents && GibdosMask) || (AllNightMask && MaskOfScents && GarosMask) || (AllNightMask && MaskOfScents && CaptainsHat) ||
			(AllNightMask && MaskOfScents && GiantsMask) || (AllNightMask && RomanisMask && CircusLeadersMask) || (AllNightMask && RomanisMask && KafeisMask) ||
			(AllNightMask && RomanisMask && CouplesMask) || (AllNightMask && RomanisMask && MaskOfTruth) || (AllNightMask && RomanisMask && GibdosMask) ||
			(AllNightMask && RomanisMask && GarosMask) || (AllNightMask && RomanisMask && CaptainsHat) || (AllNightMask && RomanisMask && GiantsMask) ||
			(AllNightMask && CircusLeadersMask && KafeisMask) || (AllNightMask && CircusLeadersMask && CouplesMask) || (AllNightMask && CircusLeadersMask && MaskOfTruth) ||
			(AllNightMask && CircusLeadersMask && GibdosMask) || (AllNightMask && CircusLeadersMask && GarosMask) || (AllNightMask && CircusLeadersMask && CaptainsHat) ||
			(AllNightMask && CircusLeadersMask && GiantsMask) || (AllNightMask && KafeisMask && CouplesMask) || (AllNightMask && KafeisMask && MaskOfTruth) ||
			(AllNightMask && KafeisMask && GibdosMask) || (AllNightMask && KafeisMask && GarosMask) || (AllNightMask && KafeisMask && CaptainsHat) ||
			(AllNightMask && KafeisMask && GiantsMask) || (AllNightMask && CouplesMask && MaskOfTruth) || (AllNightMask && CouplesMask && GibdosMask) ||
			(AllNightMask && CouplesMask && GarosMask) || (AllNightMask && CouplesMask && CaptainsHat) || (AllNightMask && CouplesMask && GiantsMask) ||
			(AllNightMask && MaskOfTruth && GibdosMask) || (AllNightMask && MaskOfTruth && GarosMask) || (AllNightMask && MaskOfTruth && CaptainsHat) ||
			(AllNightMask && MaskOfTruth && GiantsMask) || (AllNightMask && GibdosMask && GarosMask) || (AllNightMask && GibdosMask && CaptainsHat) ||
			(AllNightMask && GibdosMask && GiantsMask) || (AllNightMask && GarosMask && CaptainsHat) || (AllNightMask && GarosMask && GiantsMask) ||
			(AllNightMask && CaptainsHat && GiantsMask) || (BlastMask && StoneMask && GreatFairyMask) || (BlastMask && StoneMask && KeatonMask) || (BlastMask && StoneMask && BremenMask) ||
			(BlastMask && StoneMask && BunnyHood) || (BlastMask && StoneMask && DonGerosMask) || (BlastMask && StoneMask && MaskOfScents) || (BlastMask && StoneMask && RomanisMask) ||
			(BlastMask && StoneMask && CircusLeadersMask) || (BlastMask && StoneMask && KafeisMask) || (BlastMask && StoneMask && CouplesMask) || (BlastMask && StoneMask && MaskOfTruth) ||
			(BlastMask && StoneMask && GibdosMask) || (BlastMask && StoneMask && GarosMask) || (BlastMask && StoneMask && CaptainsHat) || (BlastMask && StoneMask && GiantsMask) ||
			(BlastMask && GreatFairyMask && KeatonMask) || (BlastMask && GreatFairyMask && BremenMask) || (BlastMask && GreatFairyMask && BunnyHood) || (BlastMask && GreatFairyMask && DonGerosMask) ||
			(BlastMask && GreatFairyMask && MaskOfScents) || (BlastMask && GreatFairyMask && RomanisMask) || (BlastMask && GreatFairyMask && CircusLeadersMask) ||
			(BlastMask && GreatFairyMask && KafeisMask) || (BlastMask && GreatFairyMask && CouplesMask) || (BlastMask && GreatFairyMask && MaskOfTruth) ||
			(BlastMask && GreatFairyMask && GibdosMask) || (BlastMask && GreatFairyMask && GarosMask) || (BlastMask && GreatFairyMask && CaptainsHat) ||
			(BlastMask && GreatFairyMask && GiantsMask) || (BlastMask && KeatonMask && BremenMask) || (BlastMask && KeatonMask && BunnyHood) || (BlastMask && KeatonMask && DonGerosMask) ||
			(BlastMask && KeatonMask && MaskOfScents) || (BlastMask && KeatonMask && RomanisMask) || (BlastMask && KeatonMask && CircusLeadersMask) || (BlastMask && KeatonMask && KafeisMask) ||
			(BlastMask && KeatonMask && CouplesMask) || (BlastMask && KeatonMask && MaskOfTruth) || (BlastMask && KeatonMask && GibdosMask) || (BlastMask && KeatonMask && GarosMask) ||
			(BlastMask && KeatonMask && CaptainsHat) || (BlastMask && KeatonMask && GiantsMask) || (BlastMask && BremenMask && BunnyHood) || (BlastMask && BremenMask && DonGerosMask) ||
			(BlastMask && BremenMask && MaskOfScents) || (BlastMask && BremenMask && RomanisMask) || (BlastMask && BremenMask && CircusLeadersMask) || (BlastMask && BremenMask && KafeisMask) ||
			(BlastMask && BremenMask && CouplesMask) || (BlastMask && BremenMask && MaskOfTruth) || (BlastMask && BremenMask && GibdosMask) || (BlastMask && BremenMask && GarosMask) ||
			(BlastMask && BremenMask && CaptainsHat) || (BlastMask && BremenMask && GiantsMask) || (BlastMask && BunnyHood && DonGerosMask) || (BlastMask && BunnyHood && MaskOfScents) ||
			(BlastMask && BunnyHood && RomanisMask) || (BlastMask && BunnyHood && CircusLeadersMask) || (BlastMask && BunnyHood && KafeisMask) || (BlastMask && BunnyHood && CouplesMask) ||
			(BlastMask && BunnyHood && MaskOfTruth) || (BlastMask && BunnyHood && GibdosMask) || (BlastMask && BunnyHood && GarosMask) || (BlastMask && BunnyHood && CaptainsHat) ||
			(BlastMask && BunnyHood && GiantsMask) || (BlastMask && DonGerosMask && MaskOfScents) || (BlastMask && DonGerosMask && RomanisMask) || (BlastMask && DonGerosMask && CircusLeadersMask) ||
			(BlastMask && DonGerosMask && KafeisMask) || (BlastMask && DonGerosMask && CouplesMask) || (BlastMask && DonGerosMask && MaskOfTruth) || (BlastMask && DonGerosMask && GibdosMask) ||
			(BlastMask && DonGerosMask && GarosMask) || (BlastMask && DonGerosMask && CaptainsHat) || (BlastMask && DonGerosMask && GiantsMask) || (BlastMask && MaskOfScents && RomanisMask) ||
			(BlastMask && MaskOfScents && CircusLeadersMask) || (BlastMask && MaskOfScents && KafeisMask) || (BlastMask && MaskOfScents && CouplesMask) || (BlastMask && MaskOfScents && MaskOfTruth) ||
			(BlastMask && MaskOfScents && GibdosMask) || (BlastMask && MaskOfScents && GarosMask) || (BlastMask && MaskOfScents && CaptainsHat) || (BlastMask && MaskOfScents && GiantsMask) ||
			(BlastMask && RomanisMask && CircusLeadersMask) || (BlastMask && RomanisMask && KafeisMask) || (BlastMask && RomanisMask && CouplesMask) || (BlastMask && RomanisMask && MaskOfTruth) ||
			(BlastMask && RomanisMask && GibdosMask) || (BlastMask && RomanisMask && GarosMask) || (BlastMask && RomanisMask && CaptainsHat) || (BlastMask && RomanisMask && GiantsMask) ||
			(BlastMask && CircusLeadersMask && KafeisMask) || (BlastMask && CircusLeadersMask && CouplesMask) || (BlastMask && CircusLeadersMask && MaskOfTruth) || (BlastMask && CircusLeadersMask && GibdosMask) ||
			(BlastMask && CircusLeadersMask && GarosMask) || (BlastMask && CircusLeadersMask && CaptainsHat) || (BlastMask && CircusLeadersMask && GiantsMask) || (BlastMask && KafeisMask && CouplesMask) ||
			(BlastMask && KafeisMask && MaskOfTruth) || (BlastMask && KafeisMask && GibdosMask) || (BlastMask && KafeisMask && GarosMask) || (BlastMask && KafeisMask && CaptainsHat) ||
			(BlastMask && KafeisMask && GiantsMask) || (BlastMask && CouplesMask && MaskOfTruth) || (BlastMask && CouplesMask && GibdosMask) || (BlastMask && CouplesMask && GarosMask) ||
			(BlastMask && CouplesMask && CaptainsHat) || (BlastMask && CouplesMask && GiantsMask) || (BlastMask && MaskOfTruth && GibdosMask) || (BlastMask && MaskOfTruth && GarosMask) ||
			(BlastMask && MaskOfTruth && CaptainsHat) || (BlastMask && MaskOfTruth && GiantsMask) || (BlastMask && GibdosMask && GarosMask) || (BlastMask && GibdosMask && CaptainsHat) ||
			(BlastMask && GibdosMask && GiantsMask) || (BlastMask && GarosMask && CaptainsHat) || (BlastMask && GarosMask && GiantsMask) || (BlastMask && CaptainsHat && GiantsMask) ||
			(StoneMask && GreatFairyMask && KeatonMask) || (StoneMask && GreatFairyMask && BremenMask) || (StoneMask && GreatFairyMask && BunnyHood) || (StoneMask && GreatFairyMask && DonGerosMask) ||
			(StoneMask && GreatFairyMask && MaskOfScents) || (StoneMask && GreatFairyMask && RomanisMask) || (StoneMask && GreatFairyMask && CircusLeadersMask) || (StoneMask && GreatFairyMask && KafeisMask) ||
			(StoneMask && GreatFairyMask && CouplesMask) || (StoneMask && GreatFairyMask && MaskOfTruth) || (StoneMask && GreatFairyMask && GibdosMask) || (StoneMask && GreatFairyMask && GarosMask) ||
			(StoneMask && GreatFairyMask && CaptainsHat) || (StoneMask && GreatFairyMask && GiantsMask) || (StoneMask && KeatonMask && BremenMask) || (StoneMask && KeatonMask && BunnyHood) ||
			(StoneMask && KeatonMask && DonGerosMask) || (StoneMask && KeatonMask && MaskOfScents) || (StoneMask && KeatonMask && RomanisMask) || (StoneMask && KeatonMask && CircusLeadersMask) ||
			(StoneMask && KeatonMask && KafeisMask) || (StoneMask && KeatonMask && CouplesMask) || (StoneMask && KeatonMask && MaskOfTruth) || (StoneMask && KeatonMask && GibdosMask) ||
			(StoneMask && KeatonMask && GarosMask) || (StoneMask && KeatonMask && CaptainsHat) || (StoneMask && KeatonMask && GiantsMask) || (StoneMask && BremenMask && BunnyHood) ||
			(StoneMask && BremenMask && DonGerosMask) || (StoneMask && BremenMask && MaskOfScents) || (StoneMask && BremenMask && RomanisMask) || (StoneMask && BremenMask && CircusLeadersMask) ||
			(StoneMask && BremenMask && KafeisMask) || (StoneMask && BremenMask && CouplesMask) || (StoneMask && BremenMask && MaskOfTruth) || (StoneMask && BremenMask && GibdosMask) ||
			(StoneMask && BremenMask && GarosMask) || (StoneMask && BremenMask && CaptainsHat) || (StoneMask && BremenMask && GiantsMask) || (StoneMask && BunnyHood && DonGerosMask) ||
			(StoneMask && BunnyHood && MaskOfScents) || (StoneMask && BunnyHood && RomanisMask) || (StoneMask && BunnyHood && CircusLeadersMask) || (StoneMask && BunnyHood && KafeisMask) ||
			(StoneMask && BunnyHood && CouplesMask) || (StoneMask && BunnyHood && MaskOfTruth) || (StoneMask && BunnyHood && GibdosMask) || (StoneMask && BunnyHood && GarosMask) ||
			(StoneMask && BunnyHood && CaptainsHat) || (StoneMask && BunnyHood && GiantsMask) || (StoneMask && DonGerosMask && MaskOfScents) || (StoneMask && DonGerosMask && RomanisMask) ||
			(StoneMask && DonGerosMask && CircusLeadersMask) || (StoneMask && DonGerosMask && KafeisMask) || (StoneMask && DonGerosMask && CouplesMask) || (StoneMask && DonGerosMask && MaskOfTruth) ||
			(StoneMask && DonGerosMask && GibdosMask) || (StoneMask && DonGerosMask && GarosMask) || (StoneMask && DonGerosMask && CaptainsHat) || (StoneMask && DonGerosMask && GiantsMask) ||
			(StoneMask && MaskOfScents && RomanisMask) || (StoneMask && MaskOfScents && CircusLeadersMask) || (StoneMask && MaskOfScents && KafeisMask) || (StoneMask && MaskOfScents && CouplesMask) ||
			(StoneMask && MaskOfScents && MaskOfTruth) || (StoneMask && MaskOfScents && GibdosMask) || (StoneMask && MaskOfScents && GarosMask) || (StoneMask && MaskOfScents && CaptainsHat) ||
			(StoneMask && MaskOfScents && GiantsMask) || (StoneMask && RomanisMask && CircusLeadersMask) || (StoneMask && RomanisMask && KafeisMask) || (StoneMask && RomanisMask && CouplesMask) ||
			(StoneMask && RomanisMask && MaskOfTruth) || (StoneMask && RomanisMask && GibdosMask) || (StoneMask && RomanisMask && GarosMask) || (StoneMask && RomanisMask && CaptainsHat) ||
			(StoneMask && RomanisMask && GiantsMask) || (StoneMask && CircusLeadersMask && KafeisMask) || (StoneMask && CircusLeadersMask && CouplesMask) || (StoneMask && CircusLeadersMask && MaskOfTruth) ||
			(StoneMask && CircusLeadersMask && GibdosMask) || (StoneMask && CircusLeadersMask && GarosMask) || (StoneMask && CircusLeadersMask && CaptainsHat) || (StoneMask && CircusLeadersMask && GiantsMask) ||
			(StoneMask && KafeisMask && CouplesMask) || (StoneMask && KafeisMask && MaskOfTruth) || (StoneMask && KafeisMask && GibdosMask) || (StoneMask && KafeisMask && GarosMask) ||
			(StoneMask && KafeisMask && CaptainsHat) || (StoneMask && KafeisMask && GiantsMask) || (StoneMask && CouplesMask && MaskOfTruth) || (StoneMask && CouplesMask && GibdosMask) ||
			(StoneMask && CouplesMask && GarosMask) || (StoneMask && CouplesMask && CaptainsHat) || (StoneMask && CouplesMask && GiantsMask) || (StoneMask && MaskOfTruth && GibdosMask) ||
			(StoneMask && MaskOfTruth && GarosMask) || (StoneMask && MaskOfTruth && CaptainsHat) || (StoneMask && MaskOfTruth && GiantsMask) || (StoneMask && GibdosMask && GarosMask) ||
			(StoneMask && GibdosMask && CaptainsHat) || (StoneMask && GibdosMask && GiantsMask) || (StoneMask && GarosMask && CaptainsHat) || (StoneMask && GarosMask && GiantsMask) ||
			(StoneMask && CaptainsHat && GiantsMask) || (GreatFairyMask && KeatonMask && BremenMask) || (GreatFairyMask && KeatonMask && BunnyHood) || (GreatFairyMask && KeatonMask && DonGerosMask) ||
			(GreatFairyMask && KeatonMask && MaskOfScents) || (GreatFairyMask && KeatonMask && RomanisMask) || (GreatFairyMask && KeatonMask && CircusLeadersMask) || (GreatFairyMask && KeatonMask && KafeisMask) ||
			(GreatFairyMask && KeatonMask && CouplesMask) || (GreatFairyMask && KeatonMask && MaskOfTruth) || (GreatFairyMask && KeatonMask && GibdosMask) || (GreatFairyMask && KeatonMask && GarosMask) ||
			(GreatFairyMask && KeatonMask && CaptainsHat) || (GreatFairyMask && KeatonMask && GiantsMask) || (GreatFairyMask && BremenMask && BunnyHood) || (GreatFairyMask && BremenMask && DonGerosMask) ||
			(GreatFairyMask && BremenMask && MaskOfScents) || (GreatFairyMask && BremenMask && RomanisMask) || (GreatFairyMask && BremenMask && CircusLeadersMask) || (GreatFairyMask && BremenMask && KafeisMask) ||
			(GreatFairyMask && BremenMask && CouplesMask) || (GreatFairyMask && BremenMask && MaskOfTruth) || (GreatFairyMask && BremenMask && GibdosMask) || (GreatFairyMask && BremenMask && GarosMask) ||
			(GreatFairyMask && BremenMask && CaptainsHat) || (GreatFairyMask && BremenMask && GiantsMask) || (GreatFairyMask && BunnyHood && DonGerosMask) || (GreatFairyMask && BunnyHood && MaskOfScents) ||
			(GreatFairyMask && BunnyHood && RomanisMask) || (GreatFairyMask && BunnyHood && CircusLeadersMask) || (GreatFairyMask && BunnyHood && KafeisMask) || (GreatFairyMask && BunnyHood && CouplesMask) ||
			(GreatFairyMask && BunnyHood && MaskOfTruth) || (GreatFairyMask && BunnyHood && GibdosMask) || (GreatFairyMask && BunnyHood && GarosMask) || (GreatFairyMask && BunnyHood && CaptainsHat) ||
			(GreatFairyMask && BunnyHood && GiantsMask) || (GreatFairyMask && DonGerosMask && MaskOfScents) || (GreatFairyMask && DonGerosMask && RomanisMask) ||
			(GreatFairyMask && DonGerosMask && CircusLeadersMask) || (GreatFairyMask && DonGerosMask && KafeisMask) || (GreatFairyMask && DonGerosMask && CouplesMask) ||
			(GreatFairyMask && DonGerosMask && MaskOfTruth) || (GreatFairyMask && DonGerosMask && GibdosMask) || (GreatFairyMask && DonGerosMask && GarosMask) || (GreatFairyMask && DonGerosMask && CaptainsHat) ||
			(GreatFairyMask && DonGerosMask && GiantsMask) || (GreatFairyMask && MaskOfScents && RomanisMask) || (GreatFairyMask && MaskOfScents && CircusLeadersMask) ||
			(GreatFairyMask && MaskOfScents && KafeisMask) || (GreatFairyMask && MaskOfScents && CouplesMask) || (GreatFairyMask && MaskOfScents && MaskOfTruth) || (GreatFairyMask && MaskOfScents && GibdosMask) ||
			(GreatFairyMask && MaskOfScents && GarosMask) || (GreatFairyMask && MaskOfScents && CaptainsHat) || (GreatFairyMask && MaskOfScents && GiantsMask) ||
			(GreatFairyMask && RomanisMask && CircusLeadersMask) || (GreatFairyMask && RomanisMask && KafeisMask) || (GreatFairyMask && RomanisMask && CouplesMask) ||
			(GreatFairyMask && RomanisMask && MaskOfTruth) || (GreatFairyMask && RomanisMask && GibdosMask) || (GreatFairyMask && RomanisMask && GarosMask) || (GreatFairyMask && RomanisMask && CaptainsHat) ||
			(GreatFairyMask && RomanisMask && GiantsMask) || (GreatFairyMask && CircusLeadersMask && KafeisMask) || (GreatFairyMask && CircusLeadersMask && CouplesMask) ||
			(GreatFairyMask && CircusLeadersMask && MaskOfTruth) || (GreatFairyMask && CircusLeadersMask && GibdosMask) || (GreatFairyMask && CircusLeadersMask && GarosMask) ||
			(GreatFairyMask && CircusLeadersMask && CaptainsHat) || (GreatFairyMask && CircusLeadersMask && GiantsMask) || (GreatFairyMask && KafeisMask && CouplesMask) ||
			(GreatFairyMask && KafeisMask && MaskOfTruth) || (GreatFairyMask && KafeisMask && GibdosMask) || (GreatFairyMask && KafeisMask && GarosMask) || (GreatFairyMask && KafeisMask && CaptainsHat) ||
			(GreatFairyMask && KafeisMask && GiantsMask) || (GreatFairyMask && CouplesMask && MaskOfTruth) || (GreatFairyMask && CouplesMask && GibdosMask) || (GreatFairyMask && CouplesMask && GarosMask) ||
			(GreatFairyMask && CouplesMask && CaptainsHat) || (GreatFairyMask && CouplesMask && GiantsMask) || (GreatFairyMask && MaskOfTruth && GibdosMask) || (GreatFairyMask && MaskOfTruth && GarosMask) ||
			(GreatFairyMask && MaskOfTruth && CaptainsHat) || (GreatFairyMask && MaskOfTruth && GiantsMask) || (GreatFairyMask && GibdosMask && GarosMask) || (GreatFairyMask && GibdosMask && CaptainsHat) ||
			(GreatFairyMask && GibdosMask && GiantsMask) || (GreatFairyMask && GarosMask && CaptainsHat) || (GreatFairyMask && GarosMask && GiantsMask) || (GreatFairyMask && CaptainsHat && GiantsMask) ||
			(KeatonMask && BremenMask && BunnyHood) || (KeatonMask && BremenMask && DonGerosMask) || (KeatonMask && BremenMask && MaskOfScents) || (KeatonMask && BremenMask && RomanisMask) ||
			(KeatonMask && BremenMask && CircusLeadersMask) || (KeatonMask && BremenMask && KafeisMask) || (KeatonMask && BremenMask && CouplesMask) || (KeatonMask && BremenMask && MaskOfTruth) ||
			(KeatonMask && BremenMask && GibdosMask) || (KeatonMask && BremenMask && GarosMask) || (KeatonMask && BremenMask && CaptainsHat) || (KeatonMask && BremenMask && GiantsMask) ||
			(KeatonMask && BunnyHood && DonGerosMask) || (KeatonMask && BunnyHood && MaskOfScents) || (KeatonMask && BunnyHood && RomanisMask) || (KeatonMask && BunnyHood && CircusLeadersMask) ||
			(KeatonMask && BunnyHood && KafeisMask) || (KeatonMask && BunnyHood && CouplesMask) || (KeatonMask && BunnyHood && MaskOfTruth) || (KeatonMask && BunnyHood && GibdosMask) ||
			(KeatonMask && BunnyHood && GarosMask) || (KeatonMask && BunnyHood && CaptainsHat) || (KeatonMask && BunnyHood && GiantsMask) || (KeatonMask && DonGerosMask && MaskOfScents) ||
			(KeatonMask && DonGerosMask && RomanisMask) || (KeatonMask && DonGerosMask && CircusLeadersMask) || (KeatonMask && DonGerosMask && KafeisMask) || (KeatonMask && DonGerosMask && CouplesMask) ||
			(KeatonMask && DonGerosMask && MaskOfTruth) || (KeatonMask && DonGerosMask && GibdosMask) || (KeatonMask && DonGerosMask && GarosMask) || (KeatonMask && DonGerosMask && CaptainsHat) ||
			(KeatonMask && DonGerosMask && GiantsMask) || (KeatonMask && MaskOfScents && RomanisMask) || (KeatonMask && MaskOfScents && CircusLeadersMask) || (KeatonMask && MaskOfScents && KafeisMask) ||
			(KeatonMask && MaskOfScents && CouplesMask) || (KeatonMask && MaskOfScents && MaskOfTruth) || (KeatonMask && MaskOfScents && GibdosMask) || (KeatonMask && MaskOfScents && GarosMask) ||
			(KeatonMask && MaskOfScents && CaptainsHat) || (KeatonMask && MaskOfScents && GiantsMask) || (KeatonMask && RomanisMask && CircusLeadersMask) || (KeatonMask && RomanisMask && KafeisMask) ||
			(KeatonMask && RomanisMask && CouplesMask) || (KeatonMask && RomanisMask && MaskOfTruth) || (KeatonMask && RomanisMask && GibdosMask) || (KeatonMask && RomanisMask && GarosMask) ||
			(KeatonMask && RomanisMask && CaptainsHat) || (KeatonMask && RomanisMask && GiantsMask) || (KeatonMask && CircusLeadersMask && KafeisMask) || (KeatonMask && CircusLeadersMask && CouplesMask) ||
			(KeatonMask && CircusLeadersMask && MaskOfTruth) || (KeatonMask && CircusLeadersMask && GibdosMask) || (KeatonMask && CircusLeadersMask && GarosMask) ||
			(KeatonMask && CircusLeadersMask && CaptainsHat) || (KeatonMask && CircusLeadersMask && GiantsMask) || (KeatonMask && KafeisMask && CouplesMask) || (KeatonMask && KafeisMask && MaskOfTruth) ||
			(KeatonMask && KafeisMask && GibdosMask) || (KeatonMask && KafeisMask && GarosMask) || (KeatonMask && KafeisMask && CaptainsHat) || (KeatonMask && KafeisMask && GiantsMask) ||
			(KeatonMask && CouplesMask && MaskOfTruth) || (KeatonMask && CouplesMask && GibdosMask) || (KeatonMask && CouplesMask && GarosMask) || (KeatonMask && CouplesMask && CaptainsHat) ||
			(KeatonMask && CouplesMask && GiantsMask) || (KeatonMask && MaskOfTruth && GibdosMask) || (KeatonMask && MaskOfTruth && GarosMask) || (KeatonMask && MaskOfTruth && CaptainsHat) ||
			(KeatonMask && MaskOfTruth && GiantsMask) || (KeatonMask && GibdosMask && GarosMask) || (KeatonMask && GibdosMask && CaptainsHat) || (KeatonMask && GibdosMask && GiantsMask) ||
			(KeatonMask && GarosMask && CaptainsHat) || (KeatonMask && GarosMask && GiantsMask) || (KeatonMask && CaptainsHat && GiantsMask) || (BremenMask && BunnyHood && DonGerosMask) ||
			(BremenMask && BunnyHood && MaskOfScents) || (BremenMask && BunnyHood && RomanisMask) || (BremenMask && BunnyHood && CircusLeadersMask) || (BremenMask && BunnyHood && KafeisMask) ||
			(BremenMask && BunnyHood && CouplesMask) || (BremenMask && BunnyHood && MaskOfTruth) || (BremenMask && BunnyHood && GibdosMask) || (BremenMask && BunnyHood && GarosMask) ||
			(BremenMask && BunnyHood && CaptainsHat) || (BremenMask && BunnyHood && GiantsMask) || (BremenMask && DonGerosMask && MaskOfScents) || (BremenMask && DonGerosMask && RomanisMask) ||
			(BremenMask && DonGerosMask && CircusLeadersMask) || (BremenMask && DonGerosMask && KafeisMask) || (BremenMask && DonGerosMask && CouplesMask) || (BremenMask && DonGerosMask && MaskOfTruth) ||
			(BremenMask && DonGerosMask && GibdosMask) || (BremenMask && DonGerosMask && GarosMask) || (BremenMask && DonGerosMask && CaptainsHat) || (BremenMask && DonGerosMask && GiantsMask) ||
			(BremenMask && MaskOfScents && RomanisMask) || (BremenMask && MaskOfScents && CircusLeadersMask) || (BremenMask && MaskOfScents && KafeisMask) || (BremenMask && MaskOfScents && CouplesMask) ||
			(BremenMask && MaskOfScents && MaskOfTruth) || (BremenMask && MaskOfScents && GibdosMask) || (BremenMask && MaskOfScents && GarosMask) || (BremenMask && MaskOfScents && CaptainsHat) ||
			(BremenMask && MaskOfScents && GiantsMask) || (BremenMask && RomanisMask && CircusLeadersMask) || (BremenMask && RomanisMask && KafeisMask) || (BremenMask && RomanisMask && CouplesMask) ||
			(BremenMask && RomanisMask && MaskOfTruth) || (BremenMask && RomanisMask && GibdosMask) || (BremenMask && RomanisMask && GarosMask) || (BremenMask && RomanisMask && CaptainsHat) ||
			(BremenMask && RomanisMask && GiantsMask) || (BremenMask && CircusLeadersMask && KafeisMask) || (BremenMask && CircusLeadersMask && CouplesMask) || (BremenMask && CircusLeadersMask && MaskOfTruth) ||
			(BremenMask && CircusLeadersMask && GibdosMask) || (BremenMask && CircusLeadersMask && GarosMask) || (BremenMask && CircusLeadersMask && CaptainsHat) ||
			(BremenMask && CircusLeadersMask && GiantsMask) || (BremenMask && KafeisMask && CouplesMask) || (BremenMask && KafeisMask && MaskOfTruth) || (BremenMask && KafeisMask && GibdosMask) ||
			(BremenMask && KafeisMask && GarosMask) || (BremenMask && KafeisMask && CaptainsHat) || (BremenMask && KafeisMask && GiantsMask) || (BremenMask && CouplesMask && MaskOfTruth) ||
			(BremenMask && CouplesMask && GibdosMask) || (BremenMask && CouplesMask && GarosMask) || (BremenMask && CouplesMask && CaptainsHat) || (BremenMask && CouplesMask && GiantsMask) ||
			(BremenMask && MaskOfTruth && GibdosMask) || (BremenMask && MaskOfTruth && GarosMask) || (BremenMask && MaskOfTruth && CaptainsHat) || (BremenMask && MaskOfTruth && GiantsMask) ||
			(BremenMask && GibdosMask && GarosMask) || (BremenMask && GibdosMask && CaptainsHat) || (BremenMask && GibdosMask && GiantsMask) || (BremenMask && GarosMask && CaptainsHat) ||
			(BremenMask && GarosMask && GiantsMask) || (BremenMask && CaptainsHat && GiantsMask) || (BunnyHood && DonGerosMask && MaskOfScents) || (BunnyHood && DonGerosMask && RomanisMask) ||
			(BunnyHood && DonGerosMask && CircusLeadersMask) || (BunnyHood && DonGerosMask && KafeisMask) || (BunnyHood && DonGerosMask && CouplesMask) || (BunnyHood && DonGerosMask && MaskOfTruth) ||
			(BunnyHood && DonGerosMask && GibdosMask) || (BunnyHood && DonGerosMask && GarosMask) || (BunnyHood && DonGerosMask && CaptainsHat) || (BunnyHood && DonGerosMask && GiantsMask) ||
			(BunnyHood && MaskOfScents && RomanisMask) || (BunnyHood && MaskOfScents && CircusLeadersMask) || (BunnyHood && MaskOfScents && KafeisMask) || (BunnyHood && MaskOfScents && CouplesMask) ||
			(BunnyHood && MaskOfScents && MaskOfTruth) || (BunnyHood && MaskOfScents && GibdosMask) || (BunnyHood && MaskOfScents && GarosMask) || (BunnyHood && MaskOfScents && CaptainsHat) ||
			(BunnyHood && MaskOfScents && GiantsMask) || (BunnyHood && RomanisMask && CircusLeadersMask) || (BunnyHood && RomanisMask && KafeisMask) || (BunnyHood && RomanisMask && CouplesMask) ||
			(BunnyHood && RomanisMask && MaskOfTruth) || (BunnyHood && RomanisMask && GibdosMask) || (BunnyHood && RomanisMask && GarosMask) || (BunnyHood && RomanisMask && CaptainsHat) ||
			(BunnyHood && RomanisMask && GiantsMask) || (BunnyHood && CircusLeadersMask && KafeisMask) || (BunnyHood && CircusLeadersMask && CouplesMask) || (BunnyHood && CircusLeadersMask && MaskOfTruth) ||
			(BunnyHood && CircusLeadersMask && GibdosMask) || (BunnyHood && CircusLeadersMask && GarosMask) || (BunnyHood && CircusLeadersMask && CaptainsHat) || (BunnyHood && CircusLeadersMask && GiantsMask) ||
			(BunnyHood && KafeisMask && CouplesMask) || (BunnyHood && KafeisMask && MaskOfTruth) || (BunnyHood && KafeisMask && GibdosMask) || (BunnyHood && KafeisMask && GarosMask) || 
			(BunnyHood && KafeisMask && CaptainsHat) || (BunnyHood && KafeisMask && GiantsMask) || (BunnyHood && CouplesMask && MaskOfTruth) || (BunnyHood && CouplesMask && GibdosMask) ||
			(BunnyHood && CouplesMask && GarosMask) || (BunnyHood && CouplesMask && CaptainsHat) || (BunnyHood && CouplesMask && GiantsMask) || (BunnyHood && MaskOfTruth && GibdosMask) || 
			(BunnyHood && MaskOfTruth && GarosMask) || (BunnyHood && MaskOfTruth && CaptainsHat) || (BunnyHood && MaskOfTruth && GiantsMask) || (BunnyHood && GibdosMask && GarosMask) || 
			(BunnyHood && GibdosMask && CaptainsHat) || (BunnyHood && GibdosMask && GiantsMask) || (BunnyHood && GarosMask && CaptainsHat) || (BunnyHood && GarosMask && GiantsMask) || 
			(BunnyHood && CaptainsHat && GiantsMask) || (DonGerosMask && MaskOfScents && RomanisMask) || (DonGerosMask && MaskOfScents && CircusLeadersMask) || (DonGerosMask && MaskOfScents && KafeisMask) || 
			(DonGerosMask && MaskOfScents && CouplesMask) || (DonGerosMask && MaskOfScents && MaskOfTruth) || (DonGerosMask && MaskOfScents && GibdosMask) || (DonGerosMask && MaskOfScents && GarosMask) || 
			(DonGerosMask && MaskOfScents && CaptainsHat) || (DonGerosMask && MaskOfScents && GiantsMask) || (DonGerosMask && RomanisMask && CircusLeadersMask) || (DonGerosMask && RomanisMask && KafeisMask) ||
			(DonGerosMask && RomanisMask && CouplesMask) || (DonGerosMask && RomanisMask && MaskOfTruth) || (DonGerosMask && RomanisMask && GibdosMask) || (DonGerosMask && RomanisMask && GarosMask) || 
			(DonGerosMask && RomanisMask && CaptainsHat) || (DonGerosMask && RomanisMask && GiantsMask) || (DonGerosMask && CircusLeadersMask && KafeisMask) || (DonGerosMask && CircusLeadersMask && CouplesMask) ||
			(DonGerosMask && CircusLeadersMask && MaskOfTruth) || (DonGerosMask && CircusLeadersMask && GibdosMask) || (DonGerosMask && CircusLeadersMask && GarosMask) || 
			(DonGerosMask && CircusLeadersMask && CaptainsHat) || (DonGerosMask && CircusLeadersMask && GiantsMask) || (DonGerosMask && KafeisMask && CouplesMask) || (DonGerosMask && KafeisMask && MaskOfTruth) ||
			(DonGerosMask && KafeisMask && GibdosMask) || (DonGerosMask && KafeisMask && GarosMask) || (DonGerosMask && KafeisMask && CaptainsHat) || (DonGerosMask && KafeisMask && GiantsMask) || 
			(DonGerosMask && CouplesMask && MaskOfTruth) || (DonGerosMask && CouplesMask && GibdosMask) || (DonGerosMask && CouplesMask && GarosMask) || (DonGerosMask && CouplesMask && CaptainsHat) || 
			(DonGerosMask && CouplesMask && GiantsMask) || (DonGerosMask && MaskOfTruth && GibdosMask) || (DonGerosMask && MaskOfTruth && GarosMask) || (DonGerosMask && MaskOfTruth && CaptainsHat) || 
			(DonGerosMask && MaskOfTruth && GiantsMask) || (DonGerosMask && GibdosMask && GarosMask) || (DonGerosMask && GibdosMask && CaptainsHat) || (DonGerosMask && GibdosMask && GiantsMask) || 
			(DonGerosMask && GarosMask && CaptainsHat) || (DonGerosMask && GarosMask && GiantsMask) || (DonGerosMask && CaptainsHat && GiantsMask) || (MaskOfScents && RomanisMask && CircusLeadersMask) || 
			(MaskOfScents && RomanisMask && KafeisMask) || (MaskOfScents && RomanisMask && CouplesMask) || (MaskOfScents && RomanisMask && MaskOfTruth) || (MaskOfScents && RomanisMask && GibdosMask) ||
			(MaskOfScents && RomanisMask && GarosMask) || (MaskOfScents && RomanisMask && CaptainsHat) || (MaskOfScents && RomanisMask && GiantsMask) || (MaskOfScents && CircusLeadersMask && KafeisMask) || 
			(MaskOfScents && CircusLeadersMask && CouplesMask) || (MaskOfScents && CircusLeadersMask && MaskOfTruth) || (MaskOfScents && CircusLeadersMask && GibdosMask) || 
			(MaskOfScents && CircusLeadersMask && GarosMask) || (MaskOfScents && CircusLeadersMask && CaptainsHat) || (MaskOfScents && CircusLeadersMask && GiantsMask) || (MaskOfScents && KafeisMask && CouplesMask) || 
			(MaskOfScents && KafeisMask && MaskOfTruth) || (MaskOfScents && KafeisMask && GibdosMask) || (MaskOfScents && KafeisMask && GarosMask) || (MaskOfScents && KafeisMask && CaptainsHat) || 
			(MaskOfScents && KafeisMask && GiantsMask) || (MaskOfScents && CouplesMask && MaskOfTruth) || (MaskOfScents && CouplesMask && GibdosMask) || (MaskOfScents && CouplesMask && GarosMask) || 
			(MaskOfScents && CouplesMask && CaptainsHat) || (MaskOfScents && CouplesMask && GiantsMask) || (MaskOfScents && MaskOfTruth && GibdosMask) || (MaskOfScents && MaskOfTruth && GarosMask) || 
			(MaskOfScents && MaskOfTruth && CaptainsHat) || (MaskOfScents && MaskOfTruth && GiantsMask) || (MaskOfScents && GibdosMask && GarosMask) || (MaskOfScents && GibdosMask && CaptainsHat) || 
			(MaskOfScents && GibdosMask && GiantsMask) || (MaskOfScents && GarosMask && CaptainsHat) || (MaskOfScents && GarosMask && GiantsMask) || (MaskOfScents && CaptainsHat && GiantsMask) || 
			(RomanisMask && CircusLeadersMask && KafeisMask) || (RomanisMask && CircusLeadersMask && CouplesMask) || (RomanisMask && CircusLeadersMask && MaskOfTruth) || 
			(RomanisMask && CircusLeadersMask && GibdosMask) || (RomanisMask && CircusLeadersMask && GarosMask) || (RomanisMask && CircusLeadersMask && CaptainsHat) || 
			(RomanisMask && CircusLeadersMask && GiantsMask) || (RomanisMask && KafeisMask && CouplesMask) || (RomanisMask && KafeisMask && MaskOfTruth) || (RomanisMask && KafeisMask && GibdosMask) || 
			(RomanisMask && KafeisMask && GarosMask) || (RomanisMask && KafeisMask && CaptainsHat) || (RomanisMask && KafeisMask && GiantsMask) || (RomanisMask && CouplesMask && MaskOfTruth) || 
			(RomanisMask && CouplesMask && GibdosMask) || (RomanisMask && CouplesMask && GarosMask) || (RomanisMask && CouplesMask && CaptainsHat) || (RomanisMask && CouplesMask && GiantsMask) || 
			(RomanisMask && MaskOfTruth && GibdosMask) || (RomanisMask && MaskOfTruth && GarosMask) || (RomanisMask && MaskOfTruth && CaptainsHat) || (RomanisMask && MaskOfTruth && GiantsMask) || 
			(RomanisMask && GibdosMask && GarosMask) || (RomanisMask && GibdosMask && CaptainsHat) || (RomanisMask && GibdosMask && GiantsMask) || (RomanisMask && GarosMask && CaptainsHat) || 
			(RomanisMask && GarosMask && GiantsMask) || (RomanisMask && CaptainsHat && GiantsMask) || (CircusLeadersMask && KafeisMask && CouplesMask) || (CircusLeadersMask && KafeisMask && MaskOfTruth) ||
			(CircusLeadersMask && KafeisMask && GibdosMask) || (CircusLeadersMask && KafeisMask && GarosMask) || (CircusLeadersMask && KafeisMask && CaptainsHat) || (CircusLeadersMask && KafeisMask && GiantsMask) ||
			(CircusLeadersMask && CouplesMask && MaskOfTruth) || (CircusLeadersMask && CouplesMask && GibdosMask) || (CircusLeadersMask && CouplesMask && GarosMask) ||
			(CircusLeadersMask && CouplesMask && CaptainsHat) || (CircusLeadersMask && CouplesMask && GiantsMask) || (CircusLeadersMask && MaskOfTruth && GibdosMask) ||
			(CircusLeadersMask && MaskOfTruth && GarosMask) || (CircusLeadersMask && MaskOfTruth && CaptainsHat) || (CircusLeadersMask && MaskOfTruth && GiantsMask) || 
			(CircusLeadersMask && GibdosMask && GarosMask) || (CircusLeadersMask && GibdosMask && CaptainsHat) || (CircusLeadersMask && GibdosMask && GiantsMask) || 
			(CircusLeadersMask && GarosMask && CaptainsHat) || (CircusLeadersMask && GarosMask && GiantsMask) || (CircusLeadersMask && CaptainsHat && GiantsMask) || 
			(KafeisMask && CouplesMask && MaskOfTruth) || (KafeisMask && CouplesMask && GibdosMask) || (KafeisMask && CouplesMask && GarosMask) || (KafeisMask && CouplesMask && CaptainsHat) ||
			(KafeisMask && CouplesMask && GiantsMask) || (KafeisMask && MaskOfTruth && GibdosMask) || (KafeisMask && MaskOfTruth && GarosMask) || (KafeisMask && MaskOfTruth && CaptainsHat) || 
			(KafeisMask && MaskOfTruth && GiantsMask) || (KafeisMask && GibdosMask && GarosMask) || (KafeisMask && GibdosMask && CaptainsHat) || (KafeisMask && GibdosMask && GiantsMask) ||
			(KafeisMask && GarosMask && CaptainsHat) || (KafeisMask && GarosMask && GiantsMask) || (KafeisMask && CaptainsHat && GiantsMask) || (CouplesMask && MaskOfTruth && GibdosMask) || 
			(CouplesMask && MaskOfTruth && GarosMask) || (CouplesMask && MaskOfTruth && CaptainsHat) || (CouplesMask && MaskOfTruth && GiantsMask) || (CouplesMask && GibdosMask && GarosMask) || 
			(CouplesMask && GibdosMask && CaptainsHat) || (CouplesMask && GibdosMask && GiantsMask) || (CouplesMask && GarosMask && CaptainsHat) || (CouplesMask && GarosMask && GiantsMask) || 
			(CouplesMask && CaptainsHat && GiantsMask) || (MaskOfTruth && GibdosMask && GarosMask) || (MaskOfTruth && GibdosMask && CaptainsHat) || (MaskOfTruth && GibdosMask && GiantsMask) ||
			(MaskOfTruth && GarosMask && CaptainsHat) || (MaskOfTruth && GarosMask && GiantsMask) || (MaskOfTruth && CaptainsHat && GiantsMask) || (GibdosMask && GarosMask && CaptainsHat) ||
			(GibdosMask && GarosMask && GiantsMask) || (GibdosMask && CaptainsHat && GiantsMask) || (GarosMask && CaptainsHat && GiantsMask) );

		FourMasks = ( (PostmansHat && AllNightMask && BlastMask && StoneMask) || (PostmansHat && AllNightMask && BlastMask && GreatFairyMask) || (PostmansHat && AllNightMask && BlastMask && KeatonMask) || 
			(PostmansHat && AllNightMask && BlastMask && BremenMask) || (PostmansHat && AllNightMask && BlastMask && BunnyHood) || (PostmansHat && AllNightMask && BlastMask && DonGerosMask) || 
			(PostmansHat && AllNightMask && BlastMask && MaskOfScents) || (PostmansHat && AllNightMask && BlastMask && RomanisMask) || (PostmansHat && AllNightMask && BlastMask && CircusLeadersMask) || 
			(PostmansHat && AllNightMask && BlastMask && KafeisMask) || (PostmansHat && AllNightMask && BlastMask && CouplesMask) || (PostmansHat && AllNightMask && BlastMask && MaskOfTruth) ||
			(PostmansHat && AllNightMask && BlastMask && GibdosMask) || (PostmansHat && AllNightMask && BlastMask && GarosMask) || (PostmansHat && AllNightMask && BlastMask && CaptainsHat) || 
			(PostmansHat && AllNightMask && BlastMask && GiantsMask) || (PostmansHat && AllNightMask && StoneMask && GreatFairyMask) || (PostmansHat && AllNightMask && StoneMask && KeatonMask) || 
			(PostmansHat && AllNightMask && StoneMask && BremenMask) || (PostmansHat && AllNightMask && StoneMask && BunnyHood) || (PostmansHat && AllNightMask && StoneMask && DonGerosMask) || 
			(PostmansHat && AllNightMask && StoneMask && MaskOfScents) || (PostmansHat && AllNightMask && StoneMask && RomanisMask) || (PostmansHat && AllNightMask && StoneMask && CircusLeadersMask) || 
			(PostmansHat && AllNightMask && StoneMask && KafeisMask) || (PostmansHat && AllNightMask && StoneMask && CouplesMask) || (PostmansHat && AllNightMask && StoneMask && MaskOfTruth) || 
			(PostmansHat && AllNightMask && StoneMask && GibdosMask) || (PostmansHat && AllNightMask && StoneMask && GarosMask) || (PostmansHat && AllNightMask && StoneMask && CaptainsHat) || 
			(PostmansHat && AllNightMask && StoneMask && GiantsMask) || (PostmansHat && AllNightMask && GreatFairyMask && KeatonMask) || (PostmansHat && AllNightMask && GreatFairyMask && BremenMask) || 
			(PostmansHat && AllNightMask && GreatFairyMask && BunnyHood) || (PostmansHat && AllNightMask && GreatFairyMask && DonGerosMask) || (PostmansHat && AllNightMask && GreatFairyMask && MaskOfScents) || 
			(PostmansHat && AllNightMask && GreatFairyMask && RomanisMask) || (PostmansHat && AllNightMask && GreatFairyMask && CircusLeadersMask) || (PostmansHat && AllNightMask && GreatFairyMask && KafeisMask) || 
			(PostmansHat && AllNightMask && GreatFairyMask && CouplesMask) || (PostmansHat && AllNightMask && GreatFairyMask && MaskOfTruth) || (PostmansHat && AllNightMask && GreatFairyMask && GibdosMask) ||
			(PostmansHat && AllNightMask && GreatFairyMask && GarosMask) || (PostmansHat && AllNightMask && GreatFairyMask && CaptainsHat) || (PostmansHat && AllNightMask && GreatFairyMask && GiantsMask) || 
			(PostmansHat && AllNightMask && KeatonMask && BremenMask) || (PostmansHat && AllNightMask && KeatonMask && BunnyHood) || (PostmansHat && AllNightMask && KeatonMask && DonGerosMask) || 
			(PostmansHat && AllNightMask && KeatonMask && MaskOfScents) || (PostmansHat && AllNightMask && KeatonMask && RomanisMask) || (PostmansHat && AllNightMask && KeatonMask && CircusLeadersMask) || 
			(PostmansHat && AllNightMask && KeatonMask && KafeisMask) || (PostmansHat && AllNightMask && KeatonMask && CouplesMask) || (PostmansHat && AllNightMask && KeatonMask && MaskOfTruth) || 
			(PostmansHat && AllNightMask && KeatonMask && GibdosMask) || (PostmansHat && AllNightMask && KeatonMask && GarosMask) || (PostmansHat && AllNightMask && KeatonMask && CaptainsHat) || 
			(PostmansHat && AllNightMask && KeatonMask && GiantsMask) || (PostmansHat && AllNightMask && BremenMask && BunnyHood) || (PostmansHat && AllNightMask && BremenMask && DonGerosMask) || 
			(PostmansHat && AllNightMask && BremenMask && MaskOfScents) || (PostmansHat && AllNightMask && BremenMask && RomanisMask) || (PostmansHat && AllNightMask && BremenMask && CircusLeadersMask) || 
			(PostmansHat && AllNightMask && BremenMask && KafeisMask) || (PostmansHat && AllNightMask && BremenMask && CouplesMask) || (PostmansHat && AllNightMask && BremenMask && MaskOfTruth) || 
			(PostmansHat && AllNightMask && BremenMask && GibdosMask) || (PostmansHat && AllNightMask && BremenMask && GarosMask) || (PostmansHat && AllNightMask && BremenMask && CaptainsHat) || 
			(PostmansHat && AllNightMask && BremenMask && GiantsMask) || (PostmansHat && AllNightMask && BunnyHood && DonGerosMask) || (PostmansHat && AllNightMask && BunnyHood && MaskOfScents) || 
			(PostmansHat && AllNightMask && BunnyHood && RomanisMask) || (PostmansHat && AllNightMask && BunnyHood && CircusLeadersMask) || (PostmansHat && AllNightMask && BunnyHood && KafeisMask) || 
			(PostmansHat && AllNightMask && BunnyHood && CouplesMask) || (PostmansHat && AllNightMask && BunnyHood && MaskOfTruth) || (PostmansHat && AllNightMask && BunnyHood && GibdosMask) || 
			(PostmansHat && AllNightMask && BunnyHood && GarosMask) || (PostmansHat && AllNightMask && BunnyHood && CaptainsHat) || (PostmansHat && AllNightMask && BunnyHood && GiantsMask) || 
			(PostmansHat && AllNightMask && DonGerosMask && MaskOfScents) || (PostmansHat && AllNightMask && DonGerosMask && RomanisMask) || (PostmansHat && AllNightMask && DonGerosMask && CircusLeadersMask) ||
			(PostmansHat && AllNightMask && DonGerosMask && KafeisMask) || (PostmansHat && AllNightMask && DonGerosMask && CouplesMask) || (PostmansHat && AllNightMask && DonGerosMask && MaskOfTruth) || 
			(PostmansHat && AllNightMask && DonGerosMask && GibdosMask) || (PostmansHat && AllNightMask && DonGerosMask && GarosMask) || (PostmansHat && AllNightMask && DonGerosMask && CaptainsHat) ||
			(PostmansHat && AllNightMask && DonGerosMask && GiantsMask) || (PostmansHat && AllNightMask && MaskOfScents && RomanisMask) || (PostmansHat && AllNightMask && MaskOfScents && CircusLeadersMask) || 
			(PostmansHat && AllNightMask && MaskOfScents && KafeisMask) || (PostmansHat && AllNightMask && MaskOfScents && CouplesMask) || (PostmansHat && AllNightMask && MaskOfScents && MaskOfTruth) || 
			(PostmansHat && AllNightMask && MaskOfScents && GibdosMask) || (PostmansHat && AllNightMask && MaskOfScents && GarosMask) || (PostmansHat && AllNightMask && MaskOfScents && CaptainsHat) || 
			(PostmansHat && AllNightMask && MaskOfScents && GiantsMask) || (PostmansHat && AllNightMask && RomanisMask && CircusLeadersMask) || (PostmansHat && AllNightMask && RomanisMask && KafeisMask) ||
			(PostmansHat && AllNightMask && RomanisMask && CouplesMask) || (PostmansHat && AllNightMask && RomanisMask && MaskOfTruth) || (PostmansHat && AllNightMask && RomanisMask && GibdosMask) ||
			(PostmansHat && AllNightMask && RomanisMask && GarosMask) || (PostmansHat && AllNightMask && RomanisMask && CaptainsHat) || (PostmansHat && AllNightMask && RomanisMask && GiantsMask) || 
			(PostmansHat && AllNightMask && CircusLeadersMask && KafeisMask) || (PostmansHat && AllNightMask && CircusLeadersMask && CouplesMask) || (PostmansHat && AllNightMask && CircusLeadersMask && MaskOfTruth) ||
			(PostmansHat && AllNightMask && CircusLeadersMask && GibdosMask) || (PostmansHat && AllNightMask && CircusLeadersMask && GarosMask) || (PostmansHat && AllNightMask && CircusLeadersMask && CaptainsHat) ||
			(PostmansHat && AllNightMask && CircusLeadersMask && GiantsMask) || (PostmansHat && AllNightMask && KafeisMask && CouplesMask) || (PostmansHat && AllNightMask && KafeisMask && MaskOfTruth) || 
			(PostmansHat && AllNightMask && KafeisMask && GibdosMask) || (PostmansHat && AllNightMask && KafeisMask && GarosMask) || (PostmansHat && AllNightMask && KafeisMask && CaptainsHat) ||
			(PostmansHat && AllNightMask && KafeisMask && GiantsMask) || (PostmansHat && AllNightMask && CouplesMask && MaskOfTruth) || (PostmansHat && AllNightMask && CouplesMask && GibdosMask) || 
			(PostmansHat && AllNightMask && CouplesMask && GarosMask) || (PostmansHat && AllNightMask && CouplesMask && CaptainsHat) || (PostmansHat && AllNightMask && CouplesMask && GiantsMask) || 
			(PostmansHat && AllNightMask && MaskOfTruth && GibdosMask) || (PostmansHat && AllNightMask && MaskOfTruth && GarosMask) || (PostmansHat && AllNightMask && MaskOfTruth && CaptainsHat) || 
			(PostmansHat && AllNightMask && MaskOfTruth && GiantsMask) || (PostmansHat && AllNightMask && GibdosMask && GarosMask) || (PostmansHat && AllNightMask && GibdosMask && CaptainsHat) || 
			(PostmansHat && AllNightMask && GibdosMask && GiantsMask) || (PostmansHat && AllNightMask && GarosMask && CaptainsHat) || (PostmansHat && AllNightMask && GarosMask && GiantsMask) || 
			(PostmansHat && AllNightMask && CaptainsHat && GiantsMask) || (PostmansHat && BlastMask && StoneMask && GreatFairyMask) || (PostmansHat && BlastMask && StoneMask && KeatonMask) || 
			(PostmansHat && BlastMask && StoneMask && BremenMask) || (PostmansHat && BlastMask && StoneMask && BunnyHood) || (PostmansHat && BlastMask && StoneMask && DonGerosMask) || 
			(PostmansHat && BlastMask && StoneMask && MaskOfScents) || (PostmansHat && BlastMask && StoneMask && RomanisMask) || (PostmansHat && BlastMask && StoneMask && CircusLeadersMask) ||
			(PostmansHat && BlastMask && StoneMask && KafeisMask) || (PostmansHat && BlastMask && StoneMask && CouplesMask) || (PostmansHat && BlastMask && StoneMask && MaskOfTruth) || 
			(PostmansHat && BlastMask && StoneMask && GibdosMask) || (PostmansHat && BlastMask && StoneMask && GarosMask) || (PostmansHat && BlastMask && StoneMask && CaptainsHat) || 
			(PostmansHat && BlastMask && StoneMask && GiantsMask) || (PostmansHat && BlastMask && GreatFairyMask && KeatonMask) || (PostmansHat && BlastMask && GreatFairyMask && BremenMask) || 
			(PostmansHat && BlastMask && GreatFairyMask && BunnyHood) || (PostmansHat && BlastMask && GreatFairyMask && DonGerosMask) || (PostmansHat && BlastMask && GreatFairyMask && MaskOfScents) || 
			(PostmansHat && BlastMask && GreatFairyMask && RomanisMask) || (PostmansHat && BlastMask && GreatFairyMask && CircusLeadersMask) || (PostmansHat && BlastMask && GreatFairyMask && KafeisMask) ||
			(PostmansHat && BlastMask && GreatFairyMask && CouplesMask) || (PostmansHat && BlastMask && GreatFairyMask && MaskOfTruth) || (PostmansHat && BlastMask && GreatFairyMask && GibdosMask) || 
			(PostmansHat && BlastMask && GreatFairyMask && GarosMask) || (PostmansHat && BlastMask && GreatFairyMask && CaptainsHat) || (PostmansHat && BlastMask && GreatFairyMask && GiantsMask) || 
			(PostmansHat && BlastMask && KeatonMask && BremenMask) || (PostmansHat && BlastMask && KeatonMask && BunnyHood) || (PostmansHat && BlastMask && KeatonMask && DonGerosMask) || 
			(PostmansHat && BlastMask && KeatonMask && MaskOfScents) || (PostmansHat && BlastMask && KeatonMask && RomanisMask) || (PostmansHat && BlastMask && KeatonMask && CircusLeadersMask) || 
			(PostmansHat && BlastMask && KeatonMask && KafeisMask) || (PostmansHat && BlastMask && KeatonMask && CouplesMask) || (PostmansHat && BlastMask && KeatonMask && MaskOfTruth) || 
			(PostmansHat && BlastMask && KeatonMask && GibdosMask) || (PostmansHat && BlastMask && KeatonMask && GarosMask) || (PostmansHat && BlastMask && KeatonMask && CaptainsHat) || 
			(PostmansHat && BlastMask && KeatonMask && GiantsMask) || (PostmansHat && BlastMask && BremenMask && BunnyHood) || (PostmansHat && BlastMask && BremenMask && DonGerosMask) || 
			(PostmansHat && BlastMask && BremenMask && MaskOfScents) || (PostmansHat && BlastMask && BremenMask && RomanisMask) || (PostmansHat && BlastMask && BremenMask && CircusLeadersMask) || 
			(PostmansHat && BlastMask && BremenMask && KafeisMask) || (PostmansHat && BlastMask && BremenMask && CouplesMask) || (PostmansHat && BlastMask && BremenMask && MaskOfTruth) ||
			(PostmansHat && BlastMask && BremenMask && GibdosMask) || (PostmansHat && BlastMask && BremenMask && GarosMask) || (PostmansHat && BlastMask && BremenMask && CaptainsHat) || 
			(PostmansHat && BlastMask && BremenMask && GiantsMask) || (PostmansHat && BlastMask && BunnyHood && DonGerosMask) || (PostmansHat && BlastMask && BunnyHood && MaskOfScents) || 
			(PostmansHat && BlastMask && BunnyHood && RomanisMask) || (PostmansHat && BlastMask && BunnyHood && CircusLeadersMask) || (PostmansHat && BlastMask && BunnyHood && KafeisMask) || 
			(PostmansHat && BlastMask && BunnyHood && CouplesMask) || (PostmansHat && BlastMask && BunnyHood && MaskOfTruth) || (PostmansHat && BlastMask && BunnyHood && GibdosMask) || 
			(PostmansHat && BlastMask && BunnyHood && GarosMask) || (PostmansHat && BlastMask && BunnyHood && CaptainsHat) || (PostmansHat && BlastMask && BunnyHood && GiantsMask) || 
			(PostmansHat && BlastMask && DonGerosMask && MaskOfScents) || (PostmansHat && BlastMask && DonGerosMask && RomanisMask) || (PostmansHat && BlastMask && DonGerosMask && CircusLeadersMask) || 
			(PostmansHat && BlastMask && DonGerosMask && KafeisMask) || (PostmansHat && BlastMask && DonGerosMask && CouplesMask) || (PostmansHat && BlastMask && DonGerosMask && MaskOfTruth) || 
			(PostmansHat && BlastMask && DonGerosMask && GibdosMask) || (PostmansHat && BlastMask && DonGerosMask && GarosMask) || (PostmansHat && BlastMask && DonGerosMask && CaptainsHat) ||
			(PostmansHat && BlastMask && DonGerosMask && GiantsMask) || (PostmansHat && BlastMask && MaskOfScents && RomanisMask) || (PostmansHat && BlastMask && MaskOfScents && CircusLeadersMask) ||
			(PostmansHat && BlastMask && MaskOfScents && KafeisMask) || (PostmansHat && BlastMask && MaskOfScents && CouplesMask) || (PostmansHat && BlastMask && MaskOfScents && MaskOfTruth) || 
			(PostmansHat && BlastMask && MaskOfScents && GibdosMask) || (PostmansHat && BlastMask && MaskOfScents && GarosMask) || (PostmansHat && BlastMask && MaskOfScents && CaptainsHat) || 
			(PostmansHat && BlastMask && MaskOfScents && GiantsMask) || (PostmansHat && BlastMask && RomanisMask && CircusLeadersMask) || (PostmansHat && BlastMask && RomanisMask && KafeisMask) || 
			(PostmansHat && BlastMask && RomanisMask && CouplesMask) || (PostmansHat && BlastMask && RomanisMask && MaskOfTruth) || (PostmansHat && BlastMask && RomanisMask && GibdosMask) || 
			(PostmansHat && BlastMask && RomanisMask && GarosMask) || (PostmansHat && BlastMask && RomanisMask && CaptainsHat) || (PostmansHat && BlastMask && RomanisMask && GiantsMask) || 
			(PostmansHat && BlastMask && CircusLeadersMask && KafeisMask) || (PostmansHat && BlastMask && CircusLeadersMask && CouplesMask) || (PostmansHat && BlastMask && CircusLeadersMask && MaskOfTruth) || 
			(PostmansHat && BlastMask && CircusLeadersMask && GibdosMask) || (PostmansHat && BlastMask && CircusLeadersMask && GarosMask) || (PostmansHat && BlastMask && CircusLeadersMask && CaptainsHat) || 
			(PostmansHat && BlastMask && CircusLeadersMask && GiantsMask) || (PostmansHat && BlastMask && KafeisMask && CouplesMask) || (PostmansHat && BlastMask && KafeisMask && MaskOfTruth) ||
			(PostmansHat && BlastMask && KafeisMask && GibdosMask) || (PostmansHat && BlastMask && KafeisMask && GarosMask) || (PostmansHat && BlastMask && KafeisMask && CaptainsHat) || 
			(PostmansHat && BlastMask && KafeisMask && GiantsMask) || (PostmansHat && BlastMask && CouplesMask && MaskOfTruth) || (PostmansHat && BlastMask && CouplesMask && GibdosMask) || 
			(PostmansHat && BlastMask && CouplesMask && GarosMask) || (PostmansHat && BlastMask && CouplesMask && CaptainsHat) || (PostmansHat && BlastMask && CouplesMask && GiantsMask) || 
			(PostmansHat && BlastMask && MaskOfTruth && GibdosMask) || (PostmansHat && BlastMask && MaskOfTruth && GarosMask) || (PostmansHat && BlastMask && MaskOfTruth && CaptainsHat) || 
			(PostmansHat && BlastMask && MaskOfTruth && GiantsMask) || (PostmansHat && BlastMask && GibdosMask && GarosMask) || (PostmansHat && BlastMask && GibdosMask && CaptainsHat) || 
			(PostmansHat && BlastMask && GibdosMask && GiantsMask) || (PostmansHat && BlastMask && GarosMask && CaptainsHat) || (PostmansHat && BlastMask && GarosMask && GiantsMask) ||
			(PostmansHat && BlastMask && CaptainsHat && GiantsMask) || (PostmansHat && StoneMask && GreatFairyMask && KeatonMask) || (PostmansHat && StoneMask && GreatFairyMask && BremenMask) || 
			(PostmansHat && StoneMask && GreatFairyMask && BunnyHood) || (PostmansHat && StoneMask && GreatFairyMask && DonGerosMask) || (PostmansHat && StoneMask && GreatFairyMask && MaskOfScents) ||
			(PostmansHat && StoneMask && GreatFairyMask && RomanisMask) || (PostmansHat && StoneMask && GreatFairyMask && CircusLeadersMask) || (PostmansHat && StoneMask && GreatFairyMask && KafeisMask) || 
			(PostmansHat && StoneMask && GreatFairyMask && CouplesMask) || (PostmansHat && StoneMask && GreatFairyMask && MaskOfTruth) || (PostmansHat && StoneMask && GreatFairyMask && GibdosMask) ||
			(PostmansHat && StoneMask && GreatFairyMask && GarosMask) || (PostmansHat && StoneMask && GreatFairyMask && CaptainsHat) || (PostmansHat && StoneMask && GreatFairyMask && GiantsMask) || 
			(PostmansHat && StoneMask && KeatonMask && BremenMask) || (PostmansHat && StoneMask && KeatonMask && BunnyHood) || (PostmansHat && StoneMask && KeatonMask && DonGerosMask) || 
			(PostmansHat && StoneMask && KeatonMask && MaskOfScents) || (PostmansHat && StoneMask && KeatonMask && RomanisMask) || (PostmansHat && StoneMask && KeatonMask && CircusLeadersMask) || 
			(PostmansHat && StoneMask && KeatonMask && KafeisMask) || (PostmansHat && StoneMask && KeatonMask && CouplesMask) || (PostmansHat && StoneMask && KeatonMask && MaskOfTruth) || 
			(PostmansHat && StoneMask && KeatonMask && GibdosMask) || (PostmansHat && StoneMask && KeatonMask && GarosMask) || (PostmansHat && StoneMask && KeatonMask && CaptainsHat) || 
			(PostmansHat && StoneMask && KeatonMask && GiantsMask) || (PostmansHat && StoneMask && BremenMask && BunnyHood) || (PostmansHat && StoneMask && BremenMask && DonGerosMask) || 
			(PostmansHat && StoneMask && BremenMask && MaskOfScents) || (PostmansHat && StoneMask && BremenMask && RomanisMask) || (PostmansHat && StoneMask && BremenMask && CircusLeadersMask) || 
			(PostmansHat && StoneMask && BremenMask && KafeisMask) || (PostmansHat && StoneMask && BremenMask && CouplesMask) || (PostmansHat && StoneMask && BremenMask && MaskOfTruth) || 
			(PostmansHat && StoneMask && BremenMask && GibdosMask) || (PostmansHat && StoneMask && BremenMask && GarosMask) || (PostmansHat && StoneMask && BremenMask && CaptainsHat) || 
			(PostmansHat && StoneMask && BremenMask && GiantsMask) || (PostmansHat && StoneMask && BunnyHood && DonGerosMask) || (PostmansHat && StoneMask && BunnyHood && MaskOfScents) || 
			(PostmansHat && StoneMask && BunnyHood && RomanisMask) || (PostmansHat && StoneMask && BunnyHood && CircusLeadersMask) || (PostmansHat && StoneMask && BunnyHood && KafeisMask) ||
			(PostmansHat && StoneMask && BunnyHood && CouplesMask) || (PostmansHat && StoneMask && BunnyHood && MaskOfTruth) || (PostmansHat && StoneMask && BunnyHood && GibdosMask) || 
			(PostmansHat && StoneMask && BunnyHood && GarosMask) || (PostmansHat && StoneMask && BunnyHood && CaptainsHat) || (PostmansHat && StoneMask && BunnyHood && GiantsMask) ||
			(PostmansHat && StoneMask && DonGerosMask && MaskOfScents) || (PostmansHat && StoneMask && DonGerosMask && RomanisMask) || (PostmansHat && StoneMask && DonGerosMask && CircusLeadersMask) ||
			(PostmansHat && StoneMask && DonGerosMask && KafeisMask) || (PostmansHat && StoneMask && DonGerosMask && CouplesMask) || (PostmansHat && StoneMask && DonGerosMask && MaskOfTruth) ||
			(PostmansHat && StoneMask && DonGerosMask && GibdosMask) || (PostmansHat && StoneMask && DonGerosMask && GarosMask) || (PostmansHat && StoneMask && DonGerosMask && CaptainsHat) ||
			(PostmansHat && StoneMask && DonGerosMask && GiantsMask) || (PostmansHat && StoneMask && MaskOfScents && RomanisMask) || (PostmansHat && StoneMask && MaskOfScents && CircusLeadersMask) || 
			(PostmansHat && StoneMask && MaskOfScents && KafeisMask) || (PostmansHat && StoneMask && MaskOfScents && CouplesMask) || (PostmansHat && StoneMask && MaskOfScents && MaskOfTruth) || 
			(PostmansHat && StoneMask && MaskOfScents && GibdosMask) || (PostmansHat && StoneMask && MaskOfScents && GarosMask) || (PostmansHat && StoneMask && MaskOfScents && CaptainsHat) || 
			(PostmansHat && StoneMask && MaskOfScents && GiantsMask) || (PostmansHat && StoneMask && RomanisMask && CircusLeadersMask) || (PostmansHat && StoneMask && RomanisMask && KafeisMask) || 
			(PostmansHat && StoneMask && RomanisMask && CouplesMask) || (PostmansHat && StoneMask && RomanisMask && MaskOfTruth) || (PostmansHat && StoneMask && RomanisMask && GibdosMask) || 
			(PostmansHat && StoneMask && RomanisMask && GarosMask) || (PostmansHat && StoneMask && RomanisMask && CaptainsHat) || (PostmansHat && StoneMask && RomanisMask && GiantsMask) ||
			(PostmansHat && StoneMask && CircusLeadersMask && KafeisMask) || (PostmansHat && StoneMask && CircusLeadersMask && CouplesMask) || (PostmansHat && StoneMask && CircusLeadersMask && MaskOfTruth) || 
			(PostmansHat && StoneMask && CircusLeadersMask && GibdosMask) || (PostmansHat && StoneMask && CircusLeadersMask && GarosMask) || (PostmansHat && StoneMask && CircusLeadersMask && CaptainsHat) ||
			(PostmansHat && StoneMask && CircusLeadersMask && GiantsMask) || (PostmansHat && StoneMask && KafeisMask && CouplesMask) || (PostmansHat && StoneMask && KafeisMask && MaskOfTruth) || 
			(PostmansHat && StoneMask && KafeisMask && GibdosMask) || (PostmansHat && StoneMask && KafeisMask && GarosMask) || (PostmansHat && StoneMask && KafeisMask && CaptainsHat) || 
			(PostmansHat && StoneMask && KafeisMask && GiantsMask) || (PostmansHat && StoneMask && CouplesMask && MaskOfTruth) || (PostmansHat && StoneMask && CouplesMask && GibdosMask) || 
			(PostmansHat && StoneMask && CouplesMask && GarosMask) || (PostmansHat && StoneMask && CouplesMask && CaptainsHat) || (PostmansHat && StoneMask && CouplesMask && GiantsMask) || 
			(PostmansHat && StoneMask && MaskOfTruth && GibdosMask) || (PostmansHat && StoneMask && MaskOfTruth && GarosMask) || (PostmansHat && StoneMask && MaskOfTruth && CaptainsHat) || 
			(PostmansHat && StoneMask && MaskOfTruth && GiantsMask) || (PostmansHat && StoneMask && GibdosMask && GarosMask) || (PostmansHat && StoneMask && GibdosMask && CaptainsHat) || 
			(PostmansHat && StoneMask && GibdosMask && GiantsMask) || (PostmansHat && StoneMask && GarosMask && CaptainsHat) || (PostmansHat && StoneMask && GarosMask && GiantsMask) || 
			(PostmansHat && StoneMask && CaptainsHat && GiantsMask) || (PostmansHat && GreatFairyMask && KeatonMask && BremenMask) || (PostmansHat && GreatFairyMask && KeatonMask && BunnyHood) || 
			(PostmansHat && GreatFairyMask && KeatonMask && DonGerosMask) || (PostmansHat && GreatFairyMask && KeatonMask && MaskOfScents) || (PostmansHat && GreatFairyMask && KeatonMask && RomanisMask) || 
			(PostmansHat && GreatFairyMask && KeatonMask && CircusLeadersMask) || (PostmansHat && GreatFairyMask && KeatonMask && KafeisMask) || (PostmansHat && GreatFairyMask && KeatonMask && CouplesMask) || 
			(PostmansHat && GreatFairyMask && KeatonMask && MaskOfTruth) || (PostmansHat && GreatFairyMask && KeatonMask && GibdosMask) || (PostmansHat && GreatFairyMask && KeatonMask && GarosMask) ||
			(PostmansHat && GreatFairyMask && KeatonMask && CaptainsHat) || (PostmansHat && GreatFairyMask && KeatonMask && GiantsMask) || (PostmansHat && GreatFairyMask && BremenMask && BunnyHood) ||
			(PostmansHat && GreatFairyMask && BremenMask && DonGerosMask) || (PostmansHat && GreatFairyMask && BremenMask && MaskOfScents) || (PostmansHat && GreatFairyMask && BremenMask && RomanisMask) || 
			(PostmansHat && GreatFairyMask && BremenMask && CircusLeadersMask) || (PostmansHat && GreatFairyMask && BremenMask && KafeisMask) || (PostmansHat && GreatFairyMask && BremenMask && CouplesMask) ||
			(PostmansHat && GreatFairyMask && BremenMask && MaskOfTruth) || (PostmansHat && GreatFairyMask && BremenMask && GibdosMask) || (PostmansHat && GreatFairyMask && BremenMask && GarosMask) || 
			(PostmansHat && GreatFairyMask && BremenMask && CaptainsHat) || (PostmansHat && GreatFairyMask && BremenMask && GiantsMask) || (PostmansHat && GreatFairyMask && BunnyHood && DonGerosMask) || 
			(PostmansHat && GreatFairyMask && BunnyHood && MaskOfScents) || (PostmansHat && GreatFairyMask && BunnyHood && RomanisMask) || (PostmansHat && GreatFairyMask && BunnyHood && CircusLeadersMask) || 
			(PostmansHat && GreatFairyMask && BunnyHood && KafeisMask) || (PostmansHat && GreatFairyMask && BunnyHood && CouplesMask) || (PostmansHat && GreatFairyMask && BunnyHood && MaskOfTruth) || 
			(PostmansHat && GreatFairyMask && BunnyHood && GibdosMask) || (PostmansHat && GreatFairyMask && BunnyHood && GarosMask) || (PostmansHat && GreatFairyMask && BunnyHood && CaptainsHat) || 
			(PostmansHat && GreatFairyMask && BunnyHood && GiantsMask) || (PostmansHat && GreatFairyMask && DonGerosMask && MaskOfScents) || (PostmansHat && GreatFairyMask && DonGerosMask && RomanisMask) || 
			(PostmansHat && GreatFairyMask && DonGerosMask && CircusLeadersMask) || (PostmansHat && GreatFairyMask && DonGerosMask && KafeisMask) || (PostmansHat && GreatFairyMask && DonGerosMask && CouplesMask) ||
			(PostmansHat && GreatFairyMask && DonGerosMask && MaskOfTruth) || (PostmansHat && GreatFairyMask && DonGerosMask && GibdosMask) || (PostmansHat && GreatFairyMask && DonGerosMask && GarosMask) ||
			(PostmansHat && GreatFairyMask && DonGerosMask && CaptainsHat) || (PostmansHat && GreatFairyMask && DonGerosMask && GiantsMask) || (PostmansHat && GreatFairyMask && MaskOfScents && RomanisMask) || 
			(PostmansHat && GreatFairyMask && MaskOfScents && CircusLeadersMask) || (PostmansHat && GreatFairyMask && MaskOfScents && KafeisMask) || (PostmansHat && GreatFairyMask && MaskOfScents && CouplesMask) || 
			(PostmansHat && GreatFairyMask && MaskOfScents && MaskOfTruth) || (PostmansHat && GreatFairyMask && MaskOfScents && GibdosMask) || (PostmansHat && GreatFairyMask && MaskOfScents && GarosMask) || 
			(PostmansHat && GreatFairyMask && MaskOfScents && CaptainsHat) || (PostmansHat && GreatFairyMask && MaskOfScents && GiantsMask) || (PostmansHat && GreatFairyMask && RomanisMask && CircusLeadersMask) || 
			(PostmansHat && GreatFairyMask && RomanisMask && KafeisMask) || (PostmansHat && GreatFairyMask && RomanisMask && CouplesMask) || (PostmansHat && GreatFairyMask && RomanisMask && MaskOfTruth) || 
			(PostmansHat && GreatFairyMask && RomanisMask && GibdosMask) || (PostmansHat && GreatFairyMask && RomanisMask && GarosMask) || (PostmansHat && GreatFairyMask && RomanisMask && CaptainsHat) || 
			(PostmansHat && GreatFairyMask && RomanisMask && GiantsMask) || (PostmansHat && GreatFairyMask && CircusLeadersMask && KafeisMask) || (PostmansHat && GreatFairyMask && CircusLeadersMask && CouplesMask) || 
			(PostmansHat && GreatFairyMask && CircusLeadersMask && MaskOfTruth) || (PostmansHat && GreatFairyMask && CircusLeadersMask && GibdosMask) || (PostmansHat && GreatFairyMask && CircusLeadersMask && GarosMask) ||
			(PostmansHat && GreatFairyMask && CircusLeadersMask && CaptainsHat) || (PostmansHat && GreatFairyMask && CircusLeadersMask && GiantsMask) || (PostmansHat && GreatFairyMask && KafeisMask && CouplesMask) || 
			(PostmansHat && GreatFairyMask && KafeisMask && MaskOfTruth) || (PostmansHat && GreatFairyMask && KafeisMask && GibdosMask) || (PostmansHat && GreatFairyMask && KafeisMask && GarosMask) || 
			(PostmansHat && GreatFairyMask && KafeisMask && CaptainsHat) || (PostmansHat && GreatFairyMask && KafeisMask && GiantsMask) || (PostmansHat && GreatFairyMask && CouplesMask && MaskOfTruth) || 
			(PostmansHat && GreatFairyMask && CouplesMask && GibdosMask) || (PostmansHat && GreatFairyMask && CouplesMask && GarosMask) || (PostmansHat && GreatFairyMask && CouplesMask && CaptainsHat) || 
			(PostmansHat && GreatFairyMask && CouplesMask && GiantsMask) || (PostmansHat && GreatFairyMask && MaskOfTruth && GibdosMask) || (PostmansHat && GreatFairyMask && MaskOfTruth && GarosMask) || 
			(PostmansHat && GreatFairyMask && MaskOfTruth && CaptainsHat) || (PostmansHat && GreatFairyMask && MaskOfTruth && GiantsMask) || (PostmansHat && GreatFairyMask && GibdosMask && GarosMask) || 
			(PostmansHat && GreatFairyMask && GibdosMask && CaptainsHat) || (PostmansHat && GreatFairyMask && GibdosMask && GiantsMask) || (PostmansHat && GreatFairyMask && GarosMask && CaptainsHat) || 
			(PostmansHat && GreatFairyMask && GarosMask && GiantsMask) || (PostmansHat && GreatFairyMask && CaptainsHat && GiantsMask) || (PostmansHat && KeatonMask && BremenMask && BunnyHood) || 
			(PostmansHat && KeatonMask && BremenMask && DonGerosMask) || (PostmansHat && KeatonMask && BremenMask && MaskOfScents) || (PostmansHat && KeatonMask && BremenMask && RomanisMask) || 
			(PostmansHat && KeatonMask && BremenMask && CircusLeadersMask) || (PostmansHat && KeatonMask && BremenMask && KafeisMask) || (PostmansHat && KeatonMask && BremenMask && CouplesMask) || 
			(PostmansHat && KeatonMask && BremenMask && MaskOfTruth) || (PostmansHat && KeatonMask && BremenMask && GibdosMask) || (PostmansHat && KeatonMask && BremenMask && GarosMask) || 
			(PostmansHat && KeatonMask && BremenMask && CaptainsHat) || (PostmansHat && KeatonMask && BremenMask && GiantsMask) || (PostmansHat && KeatonMask && BunnyHood && DonGerosMask) || 
			(PostmansHat && KeatonMask && BunnyHood && MaskOfScents) || (PostmansHat && KeatonMask && BunnyHood && RomanisMask) || (PostmansHat && KeatonMask && BunnyHood && CircusLeadersMask) || 
			(PostmansHat && KeatonMask && BunnyHood && KafeisMask) || (PostmansHat && KeatonMask && BunnyHood && CouplesMask) || (PostmansHat && KeatonMask && BunnyHood && MaskOfTruth) || 
			(PostmansHat && KeatonMask && BunnyHood && GibdosMask) || (PostmansHat && KeatonMask && BunnyHood && GarosMask) || (PostmansHat && KeatonMask && BunnyHood && CaptainsHat) || 
			(PostmansHat && KeatonMask && BunnyHood && GiantsMask) || (PostmansHat && KeatonMask && DonGerosMask && MaskOfScents) || (PostmansHat && KeatonMask && DonGerosMask && RomanisMask) || 
			(PostmansHat && KeatonMask && DonGerosMask && CircusLeadersMask) || (PostmansHat && KeatonMask && DonGerosMask && KafeisMask) || (PostmansHat && KeatonMask && DonGerosMask && CouplesMask) ||
			(PostmansHat && KeatonMask && DonGerosMask && MaskOfTruth) || (PostmansHat && KeatonMask && DonGerosMask && GibdosMask) || (PostmansHat && KeatonMask && DonGerosMask && GarosMask) || 
			(PostmansHat && KeatonMask && DonGerosMask && CaptainsHat) || (PostmansHat && KeatonMask && DonGerosMask && GiantsMask) || (PostmansHat && KeatonMask && MaskOfScents && RomanisMask) || 
			(PostmansHat && KeatonMask && MaskOfScents && CircusLeadersMask) || (PostmansHat && KeatonMask && MaskOfScents && KafeisMask) || (PostmansHat && KeatonMask && MaskOfScents && CouplesMask) || 
			(PostmansHat && KeatonMask && MaskOfScents && MaskOfTruth) || (PostmansHat && KeatonMask && MaskOfScents && GibdosMask) || (PostmansHat && KeatonMask && MaskOfScents && GarosMask) || 
			(PostmansHat && KeatonMask && MaskOfScents && CaptainsHat) || (PostmansHat && KeatonMask && MaskOfScents && GiantsMask) || (PostmansHat && KeatonMask && RomanisMask && CircusLeadersMask) || 
			(PostmansHat && KeatonMask && RomanisMask && KafeisMask) || (PostmansHat && KeatonMask && RomanisMask && CouplesMask) || (PostmansHat && KeatonMask && RomanisMask && MaskOfTruth) || 
			(PostmansHat && KeatonMask && RomanisMask && GibdosMask) || (PostmansHat && KeatonMask && RomanisMask && GarosMask) || (PostmansHat && KeatonMask && RomanisMask && CaptainsHat) ||
			(PostmansHat && KeatonMask && RomanisMask && GiantsMask) || (PostmansHat && KeatonMask && CircusLeadersMask && KafeisMask) || (PostmansHat && KeatonMask && CircusLeadersMask && CouplesMask) || 
			(PostmansHat && KeatonMask && CircusLeadersMask && MaskOfTruth) || (PostmansHat && KeatonMask && CircusLeadersMask && GibdosMask) || (PostmansHat && KeatonMask && CircusLeadersMask && GarosMask) ||
			(PostmansHat && KeatonMask && CircusLeadersMask && CaptainsHat) || (PostmansHat && KeatonMask && CircusLeadersMask && GiantsMask) || (PostmansHat && KeatonMask && KafeisMask && CouplesMask) || 
			(PostmansHat && KeatonMask && KafeisMask && MaskOfTruth) || (PostmansHat && KeatonMask && KafeisMask && GibdosMask) || (PostmansHat && KeatonMask && KafeisMask && GarosMask) || 
			(PostmansHat && KeatonMask && KafeisMask && CaptainsHat) || (PostmansHat && KeatonMask && KafeisMask && GiantsMask) || (PostmansHat && KeatonMask && CouplesMask && MaskOfTruth) ||
			(PostmansHat && KeatonMask && CouplesMask && GibdosMask) || (PostmansHat && KeatonMask && CouplesMask && GarosMask) || (PostmansHat && KeatonMask && CouplesMask && CaptainsHat) || 
			(PostmansHat && KeatonMask && CouplesMask && GiantsMask) || (PostmansHat && KeatonMask && MaskOfTruth && GibdosMask) || (PostmansHat && KeatonMask && MaskOfTruth && GarosMask) || 
			(PostmansHat && KeatonMask && MaskOfTruth && CaptainsHat) || (PostmansHat && KeatonMask && MaskOfTruth && GiantsMask) || (PostmansHat && KeatonMask && GibdosMask && GarosMask) ||
			(PostmansHat && KeatonMask && GibdosMask && CaptainsHat) || (PostmansHat && KeatonMask && GibdosMask && GiantsMask) || (PostmansHat && KeatonMask && GarosMask && CaptainsHat) || 
			(PostmansHat && KeatonMask && GarosMask && GiantsMask) || (PostmansHat && KeatonMask && CaptainsHat && GiantsMask) || (PostmansHat && BremenMask && BunnyHood && DonGerosMask) || 
			(PostmansHat && BremenMask && BunnyHood && MaskOfScents) || (PostmansHat && BremenMask && BunnyHood && RomanisMask) || (PostmansHat && BremenMask && BunnyHood && CircusLeadersMask) || 
			(PostmansHat && BremenMask && BunnyHood && KafeisMask) || (PostmansHat && BremenMask && BunnyHood && CouplesMask) || (PostmansHat && BremenMask && BunnyHood && MaskOfTruth) || 
			(PostmansHat && BremenMask && BunnyHood && GibdosMask) || (PostmansHat && BremenMask && BunnyHood && GarosMask) || (PostmansHat && BremenMask && BunnyHood && CaptainsHat) || 
			(PostmansHat && BremenMask && BunnyHood && GiantsMask) || (PostmansHat && BremenMask && DonGerosMask && MaskOfScents) || (PostmansHat && BremenMask && DonGerosMask && RomanisMask) || 
			(PostmansHat && BremenMask && DonGerosMask && CircusLeadersMask) || (PostmansHat && BremenMask && DonGerosMask && KafeisMask) || (PostmansHat && BremenMask && DonGerosMask && CouplesMask) || 
			(PostmansHat && BremenMask && DonGerosMask && MaskOfTruth) || (PostmansHat && BremenMask && DonGerosMask && GibdosMask) || (PostmansHat && BremenMask && DonGerosMask && GarosMask) || 
			(PostmansHat && BremenMask && DonGerosMask && CaptainsHat) || (PostmansHat && BremenMask && DonGerosMask && GiantsMask) || (PostmansHat && BremenMask && MaskOfScents && RomanisMask) || 
			(PostmansHat && BremenMask && MaskOfScents && CircusLeadersMask) || (PostmansHat && BremenMask && MaskOfScents && KafeisMask) || (PostmansHat && BremenMask && MaskOfScents && CouplesMask) ||
			(PostmansHat && BremenMask && MaskOfScents && MaskOfTruth) || (PostmansHat && BremenMask && MaskOfScents && GibdosMask) || (PostmansHat && BremenMask && MaskOfScents && GarosMask) || 
			(PostmansHat && BremenMask && MaskOfScents && CaptainsHat) || (PostmansHat && BremenMask && MaskOfScents && GiantsMask) || (PostmansHat && BremenMask && RomanisMask && CircusLeadersMask) || 
			(PostmansHat && BremenMask && RomanisMask && KafeisMask) || (PostmansHat && BremenMask && RomanisMask && CouplesMask) || (PostmansHat && BremenMask && RomanisMask && MaskOfTruth) ||
			(PostmansHat && BremenMask && RomanisMask && GibdosMask) || (PostmansHat && BremenMask && RomanisMask && GarosMask) || (PostmansHat && BremenMask && RomanisMask && CaptainsHat) || 
			(PostmansHat && BremenMask && RomanisMask && GiantsMask) || (PostmansHat && BremenMask && CircusLeadersMask && KafeisMask) || (PostmansHat && BremenMask && CircusLeadersMask && CouplesMask) || 
			(PostmansHat && BremenMask && CircusLeadersMask && MaskOfTruth) || (PostmansHat && BremenMask && CircusLeadersMask && GibdosMask) || (PostmansHat && BremenMask && CircusLeadersMask && GarosMask) || 
			(PostmansHat && BremenMask && CircusLeadersMask && CaptainsHat) || (PostmansHat && BremenMask && CircusLeadersMask && GiantsMask) || (PostmansHat && BremenMask && KafeisMask && CouplesMask) ||
			(PostmansHat && BremenMask && KafeisMask && MaskOfTruth) || (PostmansHat && BremenMask && KafeisMask && GibdosMask) || (PostmansHat && BremenMask && KafeisMask && GarosMask) ||
			(PostmansHat && BremenMask && KafeisMask && CaptainsHat) || (PostmansHat && BremenMask && KafeisMask && GiantsMask) || (PostmansHat && BremenMask && CouplesMask && MaskOfTruth) || 
			(PostmansHat && BremenMask && CouplesMask && GibdosMask) || (PostmansHat && BremenMask && CouplesMask && GarosMask) || (PostmansHat && BremenMask && CouplesMask && CaptainsHat) || 
			(PostmansHat && BremenMask && CouplesMask && GiantsMask) || (PostmansHat && BremenMask && MaskOfTruth && GibdosMask) || (PostmansHat && BremenMask && MaskOfTruth && GarosMask) ||
			(PostmansHat && BremenMask && MaskOfTruth && CaptainsHat) || (PostmansHat && BremenMask && MaskOfTruth && GiantsMask) || (PostmansHat && BremenMask && GibdosMask && GarosMask) ||
			(PostmansHat && BremenMask && GibdosMask && CaptainsHat) || (PostmansHat && BremenMask && GibdosMask && GiantsMask) || (PostmansHat && BremenMask && GarosMask && CaptainsHat) || 
			(PostmansHat && BremenMask && GarosMask && GiantsMask) || (PostmansHat && BremenMask && CaptainsHat && GiantsMask) || (PostmansHat && BunnyHood && DonGerosMask && MaskOfScents) || 
			(PostmansHat && BunnyHood && DonGerosMask && RomanisMask) || (PostmansHat && BunnyHood && DonGerosMask && CircusLeadersMask) || (PostmansHat && BunnyHood && DonGerosMask && KafeisMask) ||
			(PostmansHat && BunnyHood && DonGerosMask && CouplesMask) || (PostmansHat && BunnyHood && DonGerosMask && MaskOfTruth) || (PostmansHat && BunnyHood && DonGerosMask && GibdosMask) ||
			(PostmansHat && BunnyHood && DonGerosMask && GarosMask) || (PostmansHat && BunnyHood && DonGerosMask && CaptainsHat) || (PostmansHat && BunnyHood && DonGerosMask && GiantsMask) || 
			(PostmansHat && BunnyHood && MaskOfScents && RomanisMask) || (PostmansHat && BunnyHood && MaskOfScents && CircusLeadersMask) || (PostmansHat && BunnyHood && MaskOfScents && KafeisMask) || 
			(PostmansHat && BunnyHood && MaskOfScents && CouplesMask) || (PostmansHat && BunnyHood && MaskOfScents && MaskOfTruth) || (PostmansHat && BunnyHood && MaskOfScents && GibdosMask) || 
			(PostmansHat && BunnyHood && MaskOfScents && GarosMask) || (PostmansHat && BunnyHood && MaskOfScents && CaptainsHat) || (PostmansHat && BunnyHood && MaskOfScents && GiantsMask) || 
			(PostmansHat && BunnyHood && RomanisMask && CircusLeadersMask) || (PostmansHat && BunnyHood && RomanisMask && KafeisMask) || (PostmansHat && BunnyHood && RomanisMask && CouplesMask) || 
			(PostmansHat && BunnyHood && RomanisMask && MaskOfTruth) || (PostmansHat && BunnyHood && RomanisMask && GibdosMask) || (PostmansHat && BunnyHood && RomanisMask && GarosMask) || 
			(PostmansHat && BunnyHood && RomanisMask && CaptainsHat) || (PostmansHat && BunnyHood && RomanisMask && GiantsMask) || (PostmansHat && BunnyHood && CircusLeadersMask && KafeisMask) || 
			(PostmansHat && BunnyHood && CircusLeadersMask && CouplesMask) || (PostmansHat && BunnyHood && CircusLeadersMask && MaskOfTruth) || (PostmansHat && BunnyHood && CircusLeadersMask && GibdosMask) ||
			(PostmansHat && BunnyHood && CircusLeadersMask && GarosMask) || (PostmansHat && BunnyHood && CircusLeadersMask && CaptainsHat) || (PostmansHat && BunnyHood && CircusLeadersMask && GiantsMask) || 
			(PostmansHat && BunnyHood && KafeisMask && CouplesMask) || (PostmansHat && BunnyHood && KafeisMask && MaskOfTruth) || (PostmansHat && BunnyHood && KafeisMask && GibdosMask) || 
			(PostmansHat && BunnyHood && KafeisMask && GarosMask) || (PostmansHat && BunnyHood && KafeisMask && CaptainsHat) || (PostmansHat && BunnyHood && KafeisMask && GiantsMask) || 
			(PostmansHat && BunnyHood && CouplesMask && MaskOfTruth) || (PostmansHat && BunnyHood && CouplesMask && GibdosMask) || (PostmansHat && BunnyHood && CouplesMask && GarosMask) || 
			(PostmansHat && BunnyHood && CouplesMask && CaptainsHat) || (PostmansHat && BunnyHood && CouplesMask && GiantsMask) || (PostmansHat && BunnyHood && MaskOfTruth && GibdosMask) || 
			(PostmansHat && BunnyHood && MaskOfTruth && GarosMask) || (PostmansHat && BunnyHood && MaskOfTruth && CaptainsHat) || (PostmansHat && BunnyHood && MaskOfTruth && GiantsMask) || 
			(PostmansHat && BunnyHood && GibdosMask && GarosMask) || (PostmansHat && BunnyHood && GibdosMask && CaptainsHat) || (PostmansHat && BunnyHood && GibdosMask && GiantsMask) || 
			(PostmansHat && BunnyHood && GarosMask && CaptainsHat) || (PostmansHat && BunnyHood && GarosMask && GiantsMask) || (PostmansHat && BunnyHood && CaptainsHat && GiantsMask) ||
			(PostmansHat && DonGerosMask && MaskOfScents && RomanisMask) || (PostmansHat && DonGerosMask && MaskOfScents && CircusLeadersMask) || (PostmansHat && DonGerosMask && MaskOfScents && KafeisMask) ||
			(PostmansHat && DonGerosMask && MaskOfScents && CouplesMask) || (PostmansHat && DonGerosMask && MaskOfScents && MaskOfTruth) || (PostmansHat && DonGerosMask && MaskOfScents && GibdosMask) || 
			(PostmansHat && DonGerosMask && MaskOfScents && GarosMask) || (PostmansHat && DonGerosMask && MaskOfScents && CaptainsHat) || (PostmansHat && DonGerosMask && MaskOfScents && GiantsMask) || 
			(PostmansHat && DonGerosMask && RomanisMask && CircusLeadersMask) || (PostmansHat && DonGerosMask && RomanisMask && KafeisMask) || (PostmansHat && DonGerosMask && RomanisMask && CouplesMask) || 
			(PostmansHat && DonGerosMask && RomanisMask && MaskOfTruth) || (PostmansHat && DonGerosMask && RomanisMask && GibdosMask) || (PostmansHat && DonGerosMask && RomanisMask && GarosMask) ||
			(PostmansHat && DonGerosMask && RomanisMask && CaptainsHat) || (PostmansHat && DonGerosMask && RomanisMask && GiantsMask) || (PostmansHat && DonGerosMask && CircusLeadersMask && KafeisMask) || 
			(PostmansHat && DonGerosMask && CircusLeadersMask && CouplesMask) || (PostmansHat && DonGerosMask && CircusLeadersMask && MaskOfTruth) || (PostmansHat && DonGerosMask && CircusLeadersMask && GibdosMask) || 
			(PostmansHat && DonGerosMask && CircusLeadersMask && GarosMask) || (PostmansHat && DonGerosMask && CircusLeadersMask && CaptainsHat) || (PostmansHat && DonGerosMask && CircusLeadersMask && GiantsMask) ||
			(PostmansHat && DonGerosMask && KafeisMask && CouplesMask) || (PostmansHat && DonGerosMask && KafeisMask && MaskOfTruth) || (PostmansHat && DonGerosMask && KafeisMask && GibdosMask) ||
			(PostmansHat && DonGerosMask && KafeisMask && GarosMask) || (PostmansHat && DonGerosMask && KafeisMask && CaptainsHat) || (PostmansHat && DonGerosMask && KafeisMask && GiantsMask) || 
			(PostmansHat && DonGerosMask && CouplesMask && MaskOfTruth) || (PostmansHat && DonGerosMask && CouplesMask && GibdosMask) || (PostmansHat && DonGerosMask && CouplesMask && GarosMask) || 
			(PostmansHat && DonGerosMask && CouplesMask && CaptainsHat) || (PostmansHat && DonGerosMask && CouplesMask && GiantsMask) || (PostmansHat && DonGerosMask && MaskOfTruth && GibdosMask) ||
			(PostmansHat && DonGerosMask && MaskOfTruth && GarosMask) || (PostmansHat && DonGerosMask && MaskOfTruth && CaptainsHat) || (PostmansHat && DonGerosMask && MaskOfTruth && GiantsMask) || 
			(PostmansHat && DonGerosMask && GibdosMask && GarosMask) || (PostmansHat && DonGerosMask && GibdosMask && CaptainsHat) || (PostmansHat && DonGerosMask && GibdosMask && GiantsMask) || 
			(PostmansHat && DonGerosMask && GarosMask && CaptainsHat) || (PostmansHat && DonGerosMask && GarosMask && GiantsMask) || (PostmansHat && DonGerosMask && CaptainsHat && GiantsMask) || 
			(PostmansHat && MaskOfScents && RomanisMask && CircusLeadersMask) || (PostmansHat && MaskOfScents && RomanisMask && KafeisMask) || (PostmansHat && MaskOfScents && RomanisMask && CouplesMask) || 
			(PostmansHat && MaskOfScents && RomanisMask && MaskOfTruth) || (PostmansHat && MaskOfScents && RomanisMask && GibdosMask) || (PostmansHat && MaskOfScents && RomanisMask && GarosMask) || 
			(PostmansHat && MaskOfScents && RomanisMask && CaptainsHat) || (PostmansHat && MaskOfScents && RomanisMask && GiantsMask) || (PostmansHat && MaskOfScents && CircusLeadersMask && KafeisMask) || 
			(PostmansHat && MaskOfScents && CircusLeadersMask && CouplesMask) || (PostmansHat && MaskOfScents && CircusLeadersMask && MaskOfTruth) || (PostmansHat && MaskOfScents && CircusLeadersMask && GibdosMask) || 
			(PostmansHat && MaskOfScents && CircusLeadersMask && GarosMask) || (PostmansHat && MaskOfScents && CircusLeadersMask && CaptainsHat) || (PostmansHat && MaskOfScents && CircusLeadersMask && GiantsMask) ||
			(PostmansHat && MaskOfScents && KafeisMask && CouplesMask) || (PostmansHat && MaskOfScents && KafeisMask && MaskOfTruth) || (PostmansHat && MaskOfScents && KafeisMask && GibdosMask) || 
			(PostmansHat && MaskOfScents && KafeisMask && GarosMask) || (PostmansHat && MaskOfScents && KafeisMask && CaptainsHat) || (PostmansHat && MaskOfScents && KafeisMask && GiantsMask) || 
			(PostmansHat && MaskOfScents && CouplesMask && MaskOfTruth) || (PostmansHat && MaskOfScents && CouplesMask && GibdosMask) || (PostmansHat && MaskOfScents && CouplesMask && GarosMask) || 
			(PostmansHat && MaskOfScents && CouplesMask && CaptainsHat) || (PostmansHat && MaskOfScents && CouplesMask && GiantsMask) || (PostmansHat && MaskOfScents && MaskOfTruth && GibdosMask) || 
			(PostmansHat && MaskOfScents && MaskOfTruth && GarosMask) || (PostmansHat && MaskOfScents && MaskOfTruth && CaptainsHat) || (PostmansHat && MaskOfScents && MaskOfTruth && GiantsMask) ||
			(PostmansHat && MaskOfScents && GibdosMask && GarosMask) || (PostmansHat && MaskOfScents && GibdosMask && CaptainsHat) || (PostmansHat && MaskOfScents && GibdosMask && GiantsMask) || 
			(PostmansHat && MaskOfScents && GarosMask && CaptainsHat) || (PostmansHat && MaskOfScents && GarosMask && GiantsMask) || (PostmansHat && MaskOfScents && CaptainsHat && GiantsMask) || 
			(PostmansHat && RomanisMask && CircusLeadersMask && KafeisMask) || (PostmansHat && RomanisMask && CircusLeadersMask && CouplesMask) || (PostmansHat && RomanisMask && CircusLeadersMask && MaskOfTruth) || 
			(PostmansHat && RomanisMask && CircusLeadersMask && GibdosMask) || (PostmansHat && RomanisMask && CircusLeadersMask && GarosMask) || (PostmansHat && RomanisMask && CircusLeadersMask && CaptainsHat) || 
			(PostmansHat && RomanisMask && CircusLeadersMask && GiantsMask) || (PostmansHat && RomanisMask && KafeisMask && CouplesMask) || (PostmansHat && RomanisMask && KafeisMask && MaskOfTruth) ||
			(PostmansHat && RomanisMask && KafeisMask && GibdosMask) || (PostmansHat && RomanisMask && KafeisMask && GarosMask) || (PostmansHat && RomanisMask && KafeisMask && CaptainsHat) ||
			(PostmansHat && RomanisMask && KafeisMask && GiantsMask) || (PostmansHat && RomanisMask && CouplesMask && MaskOfTruth) || (PostmansHat && RomanisMask && CouplesMask && GibdosMask) || 
			(PostmansHat && RomanisMask && CouplesMask && GarosMask) || (PostmansHat && RomanisMask && CouplesMask && CaptainsHat) || (PostmansHat && RomanisMask && CouplesMask && GiantsMask) || 
			(PostmansHat && RomanisMask && MaskOfTruth && GibdosMask) || (PostmansHat && RomanisMask && MaskOfTruth && GarosMask) || (PostmansHat && RomanisMask && MaskOfTruth && CaptainsHat) ||
			(PostmansHat && RomanisMask && MaskOfTruth && GiantsMask) || (PostmansHat && RomanisMask && GibdosMask && GarosMask) || (PostmansHat && RomanisMask && GibdosMask && CaptainsHat) || 
			(PostmansHat && RomanisMask && GibdosMask && GiantsMask) || (PostmansHat && RomanisMask && GarosMask && CaptainsHat) || (PostmansHat && RomanisMask && GarosMask && GiantsMask) || 
			(PostmansHat && RomanisMask && CaptainsHat && GiantsMask) || (PostmansHat && CircusLeadersMask && KafeisMask && CouplesMask) || (PostmansHat && CircusLeadersMask && KafeisMask && MaskOfTruth) ||
			(PostmansHat && CircusLeadersMask && KafeisMask && GibdosMask) || (PostmansHat && CircusLeadersMask && KafeisMask && GarosMask) || (PostmansHat && CircusLeadersMask && KafeisMask && CaptainsHat) || 
			(PostmansHat && CircusLeadersMask && KafeisMask && GiantsMask) || (PostmansHat && CircusLeadersMask && CouplesMask && MaskOfTruth) || (PostmansHat && CircusLeadersMask && CouplesMask && GibdosMask) || 
			(PostmansHat && CircusLeadersMask && CouplesMask && GarosMask) || (PostmansHat && CircusLeadersMask && CouplesMask && CaptainsHat) || (PostmansHat && CircusLeadersMask && CouplesMask && GiantsMask) ||
			(PostmansHat && CircusLeadersMask && MaskOfTruth && GibdosMask) || (PostmansHat && CircusLeadersMask && MaskOfTruth && GarosMask) || (PostmansHat && CircusLeadersMask && MaskOfTruth && CaptainsHat) || 
			(PostmansHat && CircusLeadersMask && MaskOfTruth && GiantsMask) || (PostmansHat && CircusLeadersMask && GibdosMask && GarosMask) || (PostmansHat && CircusLeadersMask && GibdosMask && CaptainsHat) || 
			(PostmansHat && CircusLeadersMask && GibdosMask && GiantsMask) || (PostmansHat && CircusLeadersMask && GarosMask && CaptainsHat) || (PostmansHat && CircusLeadersMask && GarosMask && GiantsMask) ||
			(PostmansHat && CircusLeadersMask && CaptainsHat && GiantsMask) || (PostmansHat && KafeisMask && CouplesMask && MaskOfTruth) || (PostmansHat && KafeisMask && CouplesMask && GibdosMask) ||
			(PostmansHat && KafeisMask && CouplesMask && GarosMask) || (PostmansHat && KafeisMask && CouplesMask && CaptainsHat) || (PostmansHat && KafeisMask && CouplesMask && GiantsMask) || 
			(PostmansHat && KafeisMask && MaskOfTruth && GibdosMask) || (PostmansHat && KafeisMask && MaskOfTruth && GarosMask) || (PostmansHat && KafeisMask && MaskOfTruth && CaptainsHat) || 
			(PostmansHat && KafeisMask && MaskOfTruth && GiantsMask) || (PostmansHat && KafeisMask && GibdosMask && GarosMask) || (PostmansHat && KafeisMask && GibdosMask && CaptainsHat) || 
			(PostmansHat && KafeisMask && GibdosMask && GiantsMask) || (PostmansHat && KafeisMask && GarosMask && CaptainsHat) || (PostmansHat && KafeisMask && GarosMask && GiantsMask) || 
			(PostmansHat && KafeisMask && CaptainsHat && GiantsMask) || (PostmansHat && CouplesMask && MaskOfTruth && GibdosMask) || (PostmansHat && CouplesMask && MaskOfTruth && GarosMask) || 
			(PostmansHat && CouplesMask && MaskOfTruth && CaptainsHat) || (PostmansHat && CouplesMask && MaskOfTruth && GiantsMask) || (PostmansHat && CouplesMask && GibdosMask && GarosMask) || 
			(PostmansHat && CouplesMask && GibdosMask && CaptainsHat) || (PostmansHat && CouplesMask && GibdosMask && GiantsMask) || (PostmansHat && CouplesMask && GarosMask && CaptainsHat) || 
			(PostmansHat && CouplesMask && GarosMask && GiantsMask) || (PostmansHat && CouplesMask && CaptainsHat && GiantsMask) || (PostmansHat && MaskOfTruth && GibdosMask && GarosMask) || 
			(PostmansHat && MaskOfTruth && GibdosMask && CaptainsHat) || (PostmansHat && MaskOfTruth && GibdosMask && GiantsMask) || (PostmansHat && MaskOfTruth && GarosMask && CaptainsHat) ||
			(PostmansHat && MaskOfTruth && GarosMask && GiantsMask) || (PostmansHat && MaskOfTruth && CaptainsHat && GiantsMask) || (PostmansHat && GibdosMask && GarosMask && CaptainsHat) || 
			(PostmansHat && GibdosMask && GarosMask && GiantsMask) || (PostmansHat && GibdosMask && CaptainsHat && GiantsMask) || (PostmansHat && GarosMask && CaptainsHat && GiantsMask) ||
			(AllNightMask && BlastMask && StoneMask && GreatFairyMask) || (AllNightMask && BlastMask && StoneMask && KeatonMask) || (AllNightMask && BlastMask && StoneMask && BremenMask) || 
			(AllNightMask && BlastMask && StoneMask && BunnyHood) || (AllNightMask && BlastMask && StoneMask && DonGerosMask) || (AllNightMask && BlastMask && StoneMask && MaskOfScents) || 
			(AllNightMask && BlastMask && StoneMask && RomanisMask) || (AllNightMask && BlastMask && StoneMask && CircusLeadersMask) || (AllNightMask && BlastMask && StoneMask && KafeisMask) || 
			(AllNightMask && BlastMask && StoneMask && CouplesMask) || (AllNightMask && BlastMask && StoneMask && MaskOfTruth) || (AllNightMask && BlastMask && StoneMask && GibdosMask) || 
			(AllNightMask && BlastMask && StoneMask && GarosMask) || (AllNightMask && BlastMask && StoneMask && CaptainsHat) || (AllNightMask && BlastMask && StoneMask && GiantsMask) || 
			(AllNightMask && BlastMask && GreatFairyMask && KeatonMask) || (AllNightMask && BlastMask && GreatFairyMask && BremenMask) || (AllNightMask && BlastMask && GreatFairyMask && BunnyHood) || 
			(AllNightMask && BlastMask && GreatFairyMask && DonGerosMask) || (AllNightMask && BlastMask && GreatFairyMask && MaskOfScents) || (AllNightMask && BlastMask && GreatFairyMask && RomanisMask) ||
			(AllNightMask && BlastMask && GreatFairyMask && CircusLeadersMask) || (AllNightMask && BlastMask && GreatFairyMask && KafeisMask) || (AllNightMask && BlastMask && GreatFairyMask && CouplesMask) ||
			(AllNightMask && BlastMask && GreatFairyMask && MaskOfTruth) || (AllNightMask && BlastMask && GreatFairyMask && GibdosMask) || (AllNightMask && BlastMask && GreatFairyMask && GarosMask) || 
			(AllNightMask && BlastMask && GreatFairyMask && CaptainsHat) || (AllNightMask && BlastMask && GreatFairyMask && GiantsMask) || (AllNightMask && BlastMask && KeatonMask && BremenMask) ||
			(AllNightMask && BlastMask && KeatonMask && BunnyHood) || (AllNightMask && BlastMask && KeatonMask && DonGerosMask) || (AllNightMask && BlastMask && KeatonMask && MaskOfScents) || 
			(AllNightMask && BlastMask && KeatonMask && RomanisMask) || (AllNightMask && BlastMask && KeatonMask && CircusLeadersMask) || (AllNightMask && BlastMask && KeatonMask && KafeisMask) ||
			(AllNightMask && BlastMask && KeatonMask && CouplesMask) || (AllNightMask && BlastMask && KeatonMask && MaskOfTruth) || (AllNightMask && BlastMask && KeatonMask && GibdosMask) || 
			(AllNightMask && BlastMask && KeatonMask && GarosMask) || (AllNightMask && BlastMask && KeatonMask && CaptainsHat) || (AllNightMask && BlastMask && KeatonMask && GiantsMask) || 
			(AllNightMask && BlastMask && BremenMask && BunnyHood) || (AllNightMask && BlastMask && BremenMask && DonGerosMask) || (AllNightMask && BlastMask && BremenMask && MaskOfScents) || 
			(AllNightMask && BlastMask && BremenMask && RomanisMask) || (AllNightMask && BlastMask && BremenMask && CircusLeadersMask) || (AllNightMask && BlastMask && BremenMask && KafeisMask) ||
			(AllNightMask && BlastMask && BremenMask && CouplesMask) || (AllNightMask && BlastMask && BremenMask && MaskOfTruth) || (AllNightMask && BlastMask && BremenMask && GibdosMask) || 
			(AllNightMask && BlastMask && BremenMask && GarosMask) || (AllNightMask && BlastMask && BremenMask && CaptainsHat) || (AllNightMask && BlastMask && BremenMask && GiantsMask) || 
			(AllNightMask && BlastMask && BunnyHood && DonGerosMask) || (AllNightMask && BlastMask && BunnyHood && MaskOfScents) || (AllNightMask && BlastMask && BunnyHood && RomanisMask) || 
			(AllNightMask && BlastMask && BunnyHood && CircusLeadersMask) || (AllNightMask && BlastMask && BunnyHood && KafeisMask) || (AllNightMask && BlastMask && BunnyHood && CouplesMask) || 
			(AllNightMask && BlastMask && BunnyHood && MaskOfTruth) || (AllNightMask && BlastMask && BunnyHood && GibdosMask) || (AllNightMask && BlastMask && BunnyHood && GarosMask) || 
			(AllNightMask && BlastMask && BunnyHood && CaptainsHat) || (AllNightMask && BlastMask && BunnyHood && GiantsMask) || (AllNightMask && BlastMask && DonGerosMask && MaskOfScents) ||
			(AllNightMask && BlastMask && DonGerosMask && RomanisMask) || (AllNightMask && BlastMask && DonGerosMask && CircusLeadersMask) || (AllNightMask && BlastMask && DonGerosMask && KafeisMask) || 
			(AllNightMask && BlastMask && DonGerosMask && CouplesMask) || (AllNightMask && BlastMask && DonGerosMask && MaskOfTruth) || (AllNightMask && BlastMask && DonGerosMask && GibdosMask) || 
			(AllNightMask && BlastMask && DonGerosMask && GarosMask) || (AllNightMask && BlastMask && DonGerosMask && CaptainsHat) || (AllNightMask && BlastMask && DonGerosMask && GiantsMask) ||
			(AllNightMask && BlastMask && MaskOfScents && RomanisMask) || (AllNightMask && BlastMask && MaskOfScents && CircusLeadersMask) || (AllNightMask && BlastMask && MaskOfScents && KafeisMask) || 
			(AllNightMask && BlastMask && MaskOfScents && CouplesMask) || (AllNightMask && BlastMask && MaskOfScents && MaskOfTruth) || (AllNightMask && BlastMask && MaskOfScents && GibdosMask) || 
			(AllNightMask && BlastMask && MaskOfScents && GarosMask) || (AllNightMask && BlastMask && MaskOfScents && CaptainsHat) || (AllNightMask && BlastMask && MaskOfScents && GiantsMask) ||
			(AllNightMask && BlastMask && RomanisMask && CircusLeadersMask) || (AllNightMask && BlastMask && RomanisMask && KafeisMask) || (AllNightMask && BlastMask && RomanisMask && CouplesMask) || 
			(AllNightMask && BlastMask && RomanisMask && MaskOfTruth) || (AllNightMask && BlastMask && RomanisMask && GibdosMask) || (AllNightMask && BlastMask && RomanisMask && GarosMask) || 
			(AllNightMask && BlastMask && RomanisMask && CaptainsHat) || (AllNightMask && BlastMask && RomanisMask && GiantsMask) || (AllNightMask && BlastMask && CircusLeadersMask && KafeisMask) ||
			(AllNightMask && BlastMask && CircusLeadersMask && CouplesMask) || (AllNightMask && BlastMask && CircusLeadersMask && MaskOfTruth) || (AllNightMask && BlastMask && CircusLeadersMask && GibdosMask) || 
			(AllNightMask && BlastMask && CircusLeadersMask && GarosMask) || (AllNightMask && BlastMask && CircusLeadersMask && CaptainsHat) || (AllNightMask && BlastMask && CircusLeadersMask && GiantsMask) || 
			(AllNightMask && BlastMask && KafeisMask && CouplesMask) || (AllNightMask && BlastMask && KafeisMask && MaskOfTruth) || (AllNightMask && BlastMask && KafeisMask && GibdosMask) ||
			(AllNightMask && BlastMask && KafeisMask && GarosMask) || (AllNightMask && BlastMask && KafeisMask && CaptainsHat) || (AllNightMask && BlastMask && KafeisMask && GiantsMask) ||
			(AllNightMask && BlastMask && CouplesMask && MaskOfTruth) || (AllNightMask && BlastMask && CouplesMask && GibdosMask) || (AllNightMask && BlastMask && CouplesMask && GarosMask) || 
			(AllNightMask && BlastMask && CouplesMask && CaptainsHat) || (AllNightMask && BlastMask && CouplesMask && GiantsMask) || (AllNightMask && BlastMask && MaskOfTruth && GibdosMask) || 
			(AllNightMask && BlastMask && MaskOfTruth && GarosMask) || (AllNightMask && BlastMask && MaskOfTruth && CaptainsHat) || (AllNightMask && BlastMask && MaskOfTruth && GiantsMask) || 
			(AllNightMask && BlastMask && GibdosMask && GarosMask) || (AllNightMask && BlastMask && GibdosMask && CaptainsHat) || (AllNightMask && BlastMask && GibdosMask && GiantsMask) ||
			(AllNightMask && BlastMask && GarosMask && CaptainsHat) || (AllNightMask && BlastMask && GarosMask && GiantsMask) || (AllNightMask && BlastMask && CaptainsHat && GiantsMask) || 
			(AllNightMask && StoneMask && GreatFairyMask && KeatonMask) || (AllNightMask && StoneMask && GreatFairyMask && BremenMask) || (AllNightMask && StoneMask && GreatFairyMask && BunnyHood) || 
			(AllNightMask && StoneMask && GreatFairyMask && DonGerosMask) || (AllNightMask && StoneMask && GreatFairyMask && MaskOfScents) || (AllNightMask && StoneMask && GreatFairyMask && RomanisMask) || 
			(AllNightMask && StoneMask && GreatFairyMask && CircusLeadersMask) || (AllNightMask && StoneMask && GreatFairyMask && KafeisMask) || (AllNightMask && StoneMask && GreatFairyMask && CouplesMask) || 
			(AllNightMask && StoneMask && GreatFairyMask && MaskOfTruth) || (AllNightMask && StoneMask && GreatFairyMask && GibdosMask) || (AllNightMask && StoneMask && GreatFairyMask && GarosMask) ||
			(AllNightMask && StoneMask && GreatFairyMask && CaptainsHat) || (AllNightMask && StoneMask && GreatFairyMask && GiantsMask) || (AllNightMask && StoneMask && KeatonMask && BremenMask) || 
			(AllNightMask && StoneMask && KeatonMask && BunnyHood) || (AllNightMask && StoneMask && KeatonMask && DonGerosMask) || (AllNightMask && StoneMask && KeatonMask && MaskOfScents) || 
			(AllNightMask && StoneMask && KeatonMask && RomanisMask) || (AllNightMask && StoneMask && KeatonMask && CircusLeadersMask) || (AllNightMask && StoneMask && KeatonMask && KafeisMask) ||
			(AllNightMask && StoneMask && KeatonMask && CouplesMask) || (AllNightMask && StoneMask && KeatonMask && MaskOfTruth) || (AllNightMask && StoneMask && KeatonMask && GibdosMask) ||
			(AllNightMask && StoneMask && KeatonMask && GarosMask) || (AllNightMask && StoneMask && KeatonMask && CaptainsHat) || (AllNightMask && StoneMask && KeatonMask && GiantsMask) ||
			(AllNightMask && StoneMask && BremenMask && BunnyHood) || (AllNightMask && StoneMask && BremenMask && DonGerosMask) || (AllNightMask && StoneMask && BremenMask && MaskOfScents) ||
			(AllNightMask && StoneMask && BremenMask && RomanisMask) || (AllNightMask && StoneMask && BremenMask && CircusLeadersMask) || (AllNightMask && StoneMask && BremenMask && KafeisMask) ||
			(AllNightMask && StoneMask && BremenMask && CouplesMask) || (AllNightMask && StoneMask && BremenMask && MaskOfTruth) || (AllNightMask && StoneMask && BremenMask && GibdosMask) || 
			(AllNightMask && StoneMask && BremenMask && GarosMask) || (AllNightMask && StoneMask && BremenMask && CaptainsHat) || (AllNightMask && StoneMask && BremenMask && GiantsMask) ||
			(AllNightMask && StoneMask && BunnyHood && DonGerosMask) || (AllNightMask && StoneMask && BunnyHood && MaskOfScents) || (AllNightMask && StoneMask && BunnyHood && RomanisMask) || 
			(AllNightMask && StoneMask && BunnyHood && CircusLeadersMask) || (AllNightMask && StoneMask && BunnyHood && KafeisMask) || (AllNightMask && StoneMask && BunnyHood && CouplesMask) ||
			(AllNightMask && StoneMask && BunnyHood && MaskOfTruth) || (AllNightMask && StoneMask && BunnyHood && GibdosMask) || (AllNightMask && StoneMask && BunnyHood && GarosMask) || 
			(AllNightMask && StoneMask && BunnyHood && CaptainsHat) || (AllNightMask && StoneMask && BunnyHood && GiantsMask) || (AllNightMask && StoneMask && DonGerosMask && MaskOfScents) || 
			(AllNightMask && StoneMask && DonGerosMask && RomanisMask) || (AllNightMask && StoneMask && DonGerosMask && CircusLeadersMask) || (AllNightMask && StoneMask && DonGerosMask && KafeisMask) || 
			(AllNightMask && StoneMask && DonGerosMask && CouplesMask) || (AllNightMask && StoneMask && DonGerosMask && MaskOfTruth) || (AllNightMask && StoneMask && DonGerosMask && GibdosMask) || 
			(AllNightMask && StoneMask && DonGerosMask && GarosMask) || (AllNightMask && StoneMask && DonGerosMask && CaptainsHat) || (AllNightMask && StoneMask && DonGerosMask && GiantsMask) || 
			(AllNightMask && StoneMask && MaskOfScents && RomanisMask) || (AllNightMask && StoneMask && MaskOfScents && CircusLeadersMask) || (AllNightMask && StoneMask && MaskOfScents && KafeisMask) || 
			(AllNightMask && StoneMask && MaskOfScents && CouplesMask) || (AllNightMask && StoneMask && MaskOfScents && MaskOfTruth) || (AllNightMask && StoneMask && MaskOfScents && GibdosMask) ||
			(AllNightMask && StoneMask && MaskOfScents && GarosMask) || (AllNightMask && StoneMask && MaskOfScents && CaptainsHat) || (AllNightMask && StoneMask && MaskOfScents && GiantsMask) ||
			(AllNightMask && StoneMask && RomanisMask && CircusLeadersMask) || (AllNightMask && StoneMask && RomanisMask && KafeisMask) || (AllNightMask && StoneMask && RomanisMask && CouplesMask) || 
			(AllNightMask && StoneMask && RomanisMask && MaskOfTruth) || (AllNightMask && StoneMask && RomanisMask && GibdosMask) || (AllNightMask && StoneMask && RomanisMask && GarosMask) || 
			(AllNightMask && StoneMask && RomanisMask && CaptainsHat) || (AllNightMask && StoneMask && RomanisMask && GiantsMask) || (AllNightMask && StoneMask && CircusLeadersMask && KafeisMask) || 
			(AllNightMask && StoneMask && CircusLeadersMask && CouplesMask) || (AllNightMask && StoneMask && CircusLeadersMask && MaskOfTruth) || (AllNightMask && StoneMask && CircusLeadersMask && GibdosMask) || 
			(AllNightMask && StoneMask && CircusLeadersMask && GarosMask) || (AllNightMask && StoneMask && CircusLeadersMask && CaptainsHat) || (AllNightMask && StoneMask && CircusLeadersMask && GiantsMask) ||
			(AllNightMask && StoneMask && KafeisMask && CouplesMask) || (AllNightMask && StoneMask && KafeisMask && MaskOfTruth) || (AllNightMask && StoneMask && KafeisMask && GibdosMask) || 
			(AllNightMask && StoneMask && KafeisMask && GarosMask) || (AllNightMask && StoneMask && KafeisMask && CaptainsHat) || (AllNightMask && StoneMask && KafeisMask && GiantsMask) ||
			(AllNightMask && StoneMask && CouplesMask && MaskOfTruth) || (AllNightMask && StoneMask && CouplesMask && GibdosMask) || (AllNightMask && StoneMask && CouplesMask && GarosMask) || 
			(AllNightMask && StoneMask && CouplesMask && CaptainsHat) || (AllNightMask && StoneMask && CouplesMask && GiantsMask) || (AllNightMask && StoneMask && MaskOfTruth && GibdosMask) ||
			(AllNightMask && StoneMask && MaskOfTruth && GarosMask) || (AllNightMask && StoneMask && MaskOfTruth && CaptainsHat) || (AllNightMask && StoneMask && MaskOfTruth && GiantsMask) || 
			(AllNightMask && StoneMask && GibdosMask && GarosMask) || (AllNightMask && StoneMask && GibdosMask && CaptainsHat) || (AllNightMask && StoneMask && GibdosMask && GiantsMask) ||
			(AllNightMask && StoneMask && GarosMask && CaptainsHat) || (AllNightMask && StoneMask && GarosMask && GiantsMask) || (AllNightMask && StoneMask && CaptainsHat && GiantsMask) ||
			(AllNightMask && GreatFairyMask && KeatonMask && BremenMask) || (AllNightMask && GreatFairyMask && KeatonMask && BunnyHood) || (AllNightMask && GreatFairyMask && KeatonMask && DonGerosMask) ||
			(AllNightMask && GreatFairyMask && KeatonMask && MaskOfScents) || (AllNightMask && GreatFairyMask && KeatonMask && RomanisMask) || (AllNightMask && GreatFairyMask && KeatonMask && CircusLeadersMask) ||
			(AllNightMask && GreatFairyMask && KeatonMask && KafeisMask) || (AllNightMask && GreatFairyMask && KeatonMask && CouplesMask) || (AllNightMask && GreatFairyMask && KeatonMask && MaskOfTruth) || 
			(AllNightMask && GreatFairyMask && KeatonMask && GibdosMask) || (AllNightMask && GreatFairyMask && KeatonMask && GarosMask) || (AllNightMask && GreatFairyMask && KeatonMask && CaptainsHat) || 
			(AllNightMask && GreatFairyMask && KeatonMask && GiantsMask) || (AllNightMask && GreatFairyMask && BremenMask && BunnyHood) || (AllNightMask && GreatFairyMask && BremenMask && DonGerosMask) || 
			(AllNightMask && GreatFairyMask && BremenMask && MaskOfScents) || (AllNightMask && GreatFairyMask && BremenMask && RomanisMask) || (AllNightMask && GreatFairyMask && BremenMask && CircusLeadersMask) || 
			(AllNightMask && GreatFairyMask && BremenMask && KafeisMask) || (AllNightMask && GreatFairyMask && BremenMask && CouplesMask) || (AllNightMask && GreatFairyMask && BremenMask && MaskOfTruth) || 
			(AllNightMask && GreatFairyMask && BremenMask && GibdosMask) || (AllNightMask && GreatFairyMask && BremenMask && GarosMask) || (AllNightMask && GreatFairyMask && BremenMask && CaptainsHat) || 
			(AllNightMask && GreatFairyMask && BremenMask && GiantsMask) || (AllNightMask && GreatFairyMask && BunnyHood && DonGerosMask) || (AllNightMask && GreatFairyMask && BunnyHood && MaskOfScents) ||
			(AllNightMask && GreatFairyMask && BunnyHood && RomanisMask) || (AllNightMask && GreatFairyMask && BunnyHood && CircusLeadersMask) || (AllNightMask && GreatFairyMask && BunnyHood && KafeisMask) || 
			(AllNightMask && GreatFairyMask && BunnyHood && CouplesMask) || (AllNightMask && GreatFairyMask && BunnyHood && MaskOfTruth) || (AllNightMask && GreatFairyMask && BunnyHood && GibdosMask) || 
			(AllNightMask && GreatFairyMask && BunnyHood && GarosMask) || (AllNightMask && GreatFairyMask && BunnyHood && CaptainsHat) || (AllNightMask && GreatFairyMask && BunnyHood && GiantsMask) || 
			(AllNightMask && GreatFairyMask && DonGerosMask && MaskOfScents) || (AllNightMask && GreatFairyMask && DonGerosMask && RomanisMask) || (AllNightMask && GreatFairyMask && DonGerosMask && CircusLeadersMask) ||
			(AllNightMask && GreatFairyMask && DonGerosMask && KafeisMask) || (AllNightMask && GreatFairyMask && DonGerosMask && CouplesMask) || (AllNightMask && GreatFairyMask && DonGerosMask && MaskOfTruth) || 
			(AllNightMask && GreatFairyMask && DonGerosMask && GibdosMask) || (AllNightMask && GreatFairyMask && DonGerosMask && GarosMask) || (AllNightMask && GreatFairyMask && DonGerosMask && CaptainsHat) ||
			(AllNightMask && GreatFairyMask && DonGerosMask && GiantsMask) || (AllNightMask && GreatFairyMask && MaskOfScents && RomanisMask) || (AllNightMask && GreatFairyMask && MaskOfScents && CircusLeadersMask) || 
			(AllNightMask && GreatFairyMask && MaskOfScents && KafeisMask) || (AllNightMask && GreatFairyMask && MaskOfScents && CouplesMask) || (AllNightMask && GreatFairyMask && MaskOfScents && MaskOfTruth) ||
			(AllNightMask && GreatFairyMask && MaskOfScents && GibdosMask) || (AllNightMask && GreatFairyMask && MaskOfScents && GarosMask) || (AllNightMask && GreatFairyMask && MaskOfScents && CaptainsHat) ||
			(AllNightMask && GreatFairyMask && MaskOfScents && GiantsMask) || (AllNightMask && GreatFairyMask && RomanisMask && CircusLeadersMask) || (AllNightMask && GreatFairyMask && RomanisMask && KafeisMask) || 
			(AllNightMask && GreatFairyMask && RomanisMask && CouplesMask) || (AllNightMask && GreatFairyMask && RomanisMask && MaskOfTruth) || (AllNightMask && GreatFairyMask && RomanisMask && GibdosMask) || 
			(AllNightMask && GreatFairyMask && RomanisMask && GarosMask) || (AllNightMask && GreatFairyMask && RomanisMask && CaptainsHat) || (AllNightMask && GreatFairyMask && RomanisMask && GiantsMask) || 
			(AllNightMask && GreatFairyMask && CircusLeadersMask && KafeisMask) || (AllNightMask && GreatFairyMask && CircusLeadersMask && CouplesMask) || (AllNightMask && GreatFairyMask && CircusLeadersMask && MaskOfTruth) || 
			(AllNightMask && GreatFairyMask && CircusLeadersMask && GibdosMask) || (AllNightMask && GreatFairyMask && CircusLeadersMask && GarosMask) || (AllNightMask && GreatFairyMask && CircusLeadersMask && CaptainsHat) || 
			(AllNightMask && GreatFairyMask && CircusLeadersMask && GiantsMask) || (AllNightMask && GreatFairyMask && KafeisMask && CouplesMask) || (AllNightMask && GreatFairyMask && KafeisMask && MaskOfTruth) ||
			(AllNightMask && GreatFairyMask && KafeisMask && GibdosMask) || (AllNightMask && GreatFairyMask && KafeisMask && GarosMask) || (AllNightMask && GreatFairyMask && KafeisMask && CaptainsHat) ||
			(AllNightMask && GreatFairyMask && KafeisMask && GiantsMask) || (AllNightMask && GreatFairyMask && CouplesMask && MaskOfTruth) || (AllNightMask && GreatFairyMask && CouplesMask && GibdosMask) || 
			(AllNightMask && GreatFairyMask && CouplesMask && GarosMask) || (AllNightMask && GreatFairyMask && CouplesMask && CaptainsHat) || (AllNightMask && GreatFairyMask && CouplesMask && GiantsMask) || 
			(AllNightMask && GreatFairyMask && MaskOfTruth && GibdosMask) || (AllNightMask && GreatFairyMask && MaskOfTruth && GarosMask) || (AllNightMask && GreatFairyMask && MaskOfTruth && CaptainsHat) || 
			(AllNightMask && GreatFairyMask && MaskOfTruth && GiantsMask) || (AllNightMask && GreatFairyMask && GibdosMask && GarosMask) || (AllNightMask && GreatFairyMask && GibdosMask && CaptainsHat) ||
			(AllNightMask && GreatFairyMask && GibdosMask && GiantsMask) || (AllNightMask && GreatFairyMask && GarosMask && CaptainsHat) || (AllNightMask && GreatFairyMask && GarosMask && GiantsMask) || 
			(AllNightMask && GreatFairyMask && CaptainsHat && GiantsMask) || (AllNightMask && KeatonMask && BremenMask && BunnyHood) || (AllNightMask && KeatonMask && BremenMask && DonGerosMask) || 
			(AllNightMask && KeatonMask && BremenMask && MaskOfScents) || (AllNightMask && KeatonMask && BremenMask && RomanisMask) || (AllNightMask && KeatonMask && BremenMask && CircusLeadersMask) || 
			(AllNightMask && KeatonMask && BremenMask && KafeisMask) || (AllNightMask && KeatonMask && BremenMask && CouplesMask) || (AllNightMask && KeatonMask && BremenMask && MaskOfTruth) || 
			(AllNightMask && KeatonMask && BremenMask && GibdosMask) || (AllNightMask && KeatonMask && BremenMask && GarosMask) || (AllNightMask && KeatonMask && BremenMask && CaptainsHat) || 
			(AllNightMask && KeatonMask && BremenMask && GiantsMask) || (AllNightMask && KeatonMask && BunnyHood && DonGerosMask) || (AllNightMask && KeatonMask && BunnyHood && MaskOfScents) || 
			(AllNightMask && KeatonMask && BunnyHood && RomanisMask) || (AllNightMask && KeatonMask && BunnyHood && CircusLeadersMask) || (AllNightMask && KeatonMask && BunnyHood && KafeisMask) || 
			(AllNightMask && KeatonMask && BunnyHood && CouplesMask) || (AllNightMask && KeatonMask && BunnyHood && MaskOfTruth) || (AllNightMask && KeatonMask && BunnyHood && GibdosMask) || 
			(AllNightMask && KeatonMask && BunnyHood && GarosMask) || (AllNightMask && KeatonMask && BunnyHood && CaptainsHat) || (AllNightMask && KeatonMask && BunnyHood && GiantsMask) || 
			(AllNightMask && KeatonMask && DonGerosMask && MaskOfScents) || (AllNightMask && KeatonMask && DonGerosMask && RomanisMask) || (AllNightMask && KeatonMask && DonGerosMask && CircusLeadersMask) || 
			(AllNightMask && KeatonMask && DonGerosMask && KafeisMask) || (AllNightMask && KeatonMask && DonGerosMask && CouplesMask) || (AllNightMask && KeatonMask && DonGerosMask && MaskOfTruth) ||
			(AllNightMask && KeatonMask && DonGerosMask && GibdosMask) || (AllNightMask && KeatonMask && DonGerosMask && GarosMask) || (AllNightMask && KeatonMask && DonGerosMask && CaptainsHat) ||
			(AllNightMask && KeatonMask && DonGerosMask && GiantsMask) || (AllNightMask && KeatonMask && MaskOfScents && RomanisMask) || (AllNightMask && KeatonMask && MaskOfScents && CircusLeadersMask) || 
			(AllNightMask && KeatonMask && MaskOfScents && KafeisMask) || (AllNightMask && KeatonMask && MaskOfScents && CouplesMask) || (AllNightMask && KeatonMask && MaskOfScents && MaskOfTruth) || 
			(AllNightMask && KeatonMask && MaskOfScents && GibdosMask) || (AllNightMask && KeatonMask && MaskOfScents && GarosMask) || (AllNightMask && KeatonMask && MaskOfScents && CaptainsHat) ||
			(AllNightMask && KeatonMask && MaskOfScents && GiantsMask) || (AllNightMask && KeatonMask && RomanisMask && CircusLeadersMask) || (AllNightMask && KeatonMask && RomanisMask && KafeisMask) ||
			(AllNightMask && KeatonMask && RomanisMask && CouplesMask) || (AllNightMask && KeatonMask && RomanisMask && MaskOfTruth) || (AllNightMask && KeatonMask && RomanisMask && GibdosMask) || 
			(AllNightMask && KeatonMask && RomanisMask && GarosMask) || (AllNightMask && KeatonMask && RomanisMask && CaptainsHat) || (AllNightMask && KeatonMask && RomanisMask && GiantsMask) || 
			(AllNightMask && KeatonMask && CircusLeadersMask && KafeisMask) || (AllNightMask && KeatonMask && CircusLeadersMask && CouplesMask) || (AllNightMask && KeatonMask && CircusLeadersMask && MaskOfTruth) ||
			(AllNightMask && KeatonMask && CircusLeadersMask && GibdosMask) || (AllNightMask && KeatonMask && CircusLeadersMask && GarosMask) || (AllNightMask && KeatonMask && CircusLeadersMask && CaptainsHat) || 
			(AllNightMask && KeatonMask && CircusLeadersMask && GiantsMask) || (AllNightMask && KeatonMask && KafeisMask && CouplesMask) || (AllNightMask && KeatonMask && KafeisMask && MaskOfTruth) || 
			(AllNightMask && KeatonMask && KafeisMask && GibdosMask) || (AllNightMask && KeatonMask && KafeisMask && GarosMask) || (AllNightMask && KeatonMask && KafeisMask && CaptainsHat) ||
			(AllNightMask && KeatonMask && KafeisMask && GiantsMask) || (AllNightMask && KeatonMask && CouplesMask && MaskOfTruth) || (AllNightMask && KeatonMask && CouplesMask && GibdosMask) ||
			(AllNightMask && KeatonMask && CouplesMask && GarosMask) || (AllNightMask && KeatonMask && CouplesMask && CaptainsHat) || (AllNightMask && KeatonMask && CouplesMask && GiantsMask) || 
			(AllNightMask && KeatonMask && MaskOfTruth && GibdosMask) || (AllNightMask && KeatonMask && MaskOfTruth && GarosMask) || (AllNightMask && KeatonMask && MaskOfTruth && CaptainsHat) || 
			(AllNightMask && KeatonMask && MaskOfTruth && GiantsMask) || (AllNightMask && KeatonMask && GibdosMask && GarosMask) || (AllNightMask && KeatonMask && GibdosMask && CaptainsHat) || 
			(AllNightMask && KeatonMask && GibdosMask && GiantsMask) || (AllNightMask && KeatonMask && GarosMask && CaptainsHat) || (AllNightMask && KeatonMask && GarosMask && GiantsMask) ||
			(AllNightMask && KeatonMask && CaptainsHat && GiantsMask) || (AllNightMask && BremenMask && BunnyHood && DonGerosMask) || (AllNightMask && BremenMask && BunnyHood && MaskOfScents) || 
			(AllNightMask && BremenMask && BunnyHood && RomanisMask) || (AllNightMask && BremenMask && BunnyHood && CircusLeadersMask) || (AllNightMask && BremenMask && BunnyHood && KafeisMask) || 
			(AllNightMask && BremenMask && BunnyHood && CouplesMask) || (AllNightMask && BremenMask && BunnyHood && MaskOfTruth) || (AllNightMask && BremenMask && BunnyHood && GibdosMask) || 
			(AllNightMask && BremenMask && BunnyHood && GarosMask) || (AllNightMask && BremenMask && BunnyHood && CaptainsHat) || (AllNightMask && BremenMask && BunnyHood && GiantsMask) || 
			(AllNightMask && BremenMask && DonGerosMask && MaskOfScents) || (AllNightMask && BremenMask && DonGerosMask && RomanisMask) || (AllNightMask && BremenMask && DonGerosMask && CircusLeadersMask) ||
			(AllNightMask && BremenMask && DonGerosMask && KafeisMask) || (AllNightMask && BremenMask && DonGerosMask && CouplesMask) || (AllNightMask && BremenMask && DonGerosMask && MaskOfTruth) || 
			(AllNightMask && BremenMask && DonGerosMask && GibdosMask) || (AllNightMask && BremenMask && DonGerosMask && GarosMask) || (AllNightMask && BremenMask && DonGerosMask && CaptainsHat) || 
			(AllNightMask && BremenMask && DonGerosMask && GiantsMask) || (AllNightMask && BremenMask && MaskOfScents && RomanisMask) || (AllNightMask && BremenMask && MaskOfScents && CircusLeadersMask) || 
			(AllNightMask && BremenMask && MaskOfScents && KafeisMask) || (AllNightMask && BremenMask && MaskOfScents && CouplesMask) || (AllNightMask && BremenMask && MaskOfScents && MaskOfTruth) || 
			(AllNightMask && BremenMask && MaskOfScents && GibdosMask) || (AllNightMask && BremenMask && MaskOfScents && GarosMask) || (AllNightMask && BremenMask && MaskOfScents && CaptainsHat) || 
			(AllNightMask && BremenMask && MaskOfScents && GiantsMask) || (AllNightMask && BremenMask && RomanisMask && CircusLeadersMask) || (AllNightMask && BremenMask && RomanisMask && KafeisMask) || 
			(AllNightMask && BremenMask && RomanisMask && CouplesMask) || (AllNightMask && BremenMask && RomanisMask && MaskOfTruth) || (AllNightMask && BremenMask && RomanisMask && GibdosMask) || 
			(AllNightMask && BremenMask && RomanisMask && GarosMask) || (AllNightMask && BremenMask && RomanisMask && CaptainsHat) || (AllNightMask && BremenMask && RomanisMask && GiantsMask) || 
			(AllNightMask && BremenMask && CircusLeadersMask && KafeisMask) || (AllNightMask && BremenMask && CircusLeadersMask && CouplesMask) || (AllNightMask && BremenMask && CircusLeadersMask && MaskOfTruth) || 
			(AllNightMask && BremenMask && CircusLeadersMask && GibdosMask) || (AllNightMask && BremenMask && CircusLeadersMask && GarosMask) || (AllNightMask && BremenMask && CircusLeadersMask && CaptainsHat) || 
			(AllNightMask && BremenMask && CircusLeadersMask && GiantsMask) || (AllNightMask && BremenMask && KafeisMask && CouplesMask) || (AllNightMask && BremenMask && KafeisMask && MaskOfTruth) || 
			(AllNightMask && BremenMask && KafeisMask && GibdosMask) || (AllNightMask && BremenMask && KafeisMask && GarosMask) || (AllNightMask && BremenMask && KafeisMask && CaptainsHat) ||
			(AllNightMask && BremenMask && KafeisMask && GiantsMask) || (AllNightMask && BremenMask && CouplesMask && MaskOfTruth) || (AllNightMask && BremenMask && CouplesMask && GibdosMask) || 
			(AllNightMask && BremenMask && CouplesMask && GarosMask) || (AllNightMask && BremenMask && CouplesMask && CaptainsHat) || (AllNightMask && BremenMask && CouplesMask && GiantsMask) ||
			(AllNightMask && BremenMask && MaskOfTruth && GibdosMask) || (AllNightMask && BremenMask && MaskOfTruth && GarosMask) || (AllNightMask && BremenMask && MaskOfTruth && CaptainsHat) || 
			(AllNightMask && BremenMask && MaskOfTruth && GiantsMask) || (AllNightMask && BremenMask && GibdosMask && GarosMask) || (AllNightMask && BremenMask && GibdosMask && CaptainsHat) || 
			(AllNightMask && BremenMask && GibdosMask && GiantsMask) || (AllNightMask && BremenMask && GarosMask && CaptainsHat) || (AllNightMask && BremenMask && GarosMask && GiantsMask) ||
			(AllNightMask && BremenMask && CaptainsHat && GiantsMask) || (AllNightMask && BunnyHood && DonGerosMask && MaskOfScents) || (AllNightMask && BunnyHood && DonGerosMask && RomanisMask) ||
			(AllNightMask && BunnyHood && DonGerosMask && CircusLeadersMask) || (AllNightMask && BunnyHood && DonGerosMask && KafeisMask) || (AllNightMask && BunnyHood && DonGerosMask && CouplesMask) ||
			(AllNightMask && BunnyHood && DonGerosMask && MaskOfTruth) || (AllNightMask && BunnyHood && DonGerosMask && GibdosMask) || (AllNightMask && BunnyHood && DonGerosMask && GarosMask) || 
			(AllNightMask && BunnyHood && DonGerosMask && CaptainsHat) || (AllNightMask && BunnyHood && DonGerosMask && GiantsMask) || (AllNightMask && BunnyHood && MaskOfScents && RomanisMask) || 
			(AllNightMask && BunnyHood && MaskOfScents && CircusLeadersMask) || (AllNightMask && BunnyHood && MaskOfScents && KafeisMask) || (AllNightMask && BunnyHood && MaskOfScents && CouplesMask) ||
			(AllNightMask && BunnyHood && MaskOfScents && MaskOfTruth) || (AllNightMask && BunnyHood && MaskOfScents && GibdosMask) || (AllNightMask && BunnyHood && MaskOfScents && GarosMask) || 
			(AllNightMask && BunnyHood && MaskOfScents && CaptainsHat) || (AllNightMask && BunnyHood && MaskOfScents && GiantsMask) || (AllNightMask && BunnyHood && RomanisMask && CircusLeadersMask) ||
			(AllNightMask && BunnyHood && RomanisMask && KafeisMask) || (AllNightMask && BunnyHood && RomanisMask && CouplesMask) || (AllNightMask && BunnyHood && RomanisMask && MaskOfTruth) || 
			(AllNightMask && BunnyHood && RomanisMask && GibdosMask) || (AllNightMask && BunnyHood && RomanisMask && GarosMask) || (AllNightMask && BunnyHood && RomanisMask && CaptainsHat) || 
			(AllNightMask && BunnyHood && RomanisMask && GiantsMask) || (AllNightMask && BunnyHood && CircusLeadersMask && KafeisMask) || (AllNightMask && BunnyHood && CircusLeadersMask && CouplesMask) ||
			(AllNightMask && BunnyHood && CircusLeadersMask && MaskOfTruth) || (AllNightMask && BunnyHood && CircusLeadersMask && GibdosMask) || (AllNightMask && BunnyHood && CircusLeadersMask && GarosMask) || 
			(AllNightMask && BunnyHood && CircusLeadersMask && CaptainsHat) || (AllNightMask && BunnyHood && CircusLeadersMask && GiantsMask) || (AllNightMask && BunnyHood && KafeisMask && CouplesMask) ||
			(AllNightMask && BunnyHood && KafeisMask && MaskOfTruth) || (AllNightMask && BunnyHood && KafeisMask && GibdosMask) || (AllNightMask && BunnyHood && KafeisMask && GarosMask) || 
			(AllNightMask && BunnyHood && KafeisMask && CaptainsHat) || (AllNightMask && BunnyHood && KafeisMask && GiantsMask) || (AllNightMask && BunnyHood && CouplesMask && MaskOfTruth) ||
			(AllNightMask && BunnyHood && CouplesMask && GibdosMask) || (AllNightMask && BunnyHood && CouplesMask && GarosMask) || (AllNightMask && BunnyHood && CouplesMask && CaptainsHat) ||
			(AllNightMask && BunnyHood && CouplesMask && GiantsMask) || (AllNightMask && BunnyHood && MaskOfTruth && GibdosMask) || (AllNightMask && BunnyHood && MaskOfTruth && GarosMask) || 
			(AllNightMask && BunnyHood && MaskOfTruth && CaptainsHat) || (AllNightMask && BunnyHood && MaskOfTruth && GiantsMask) || (AllNightMask && BunnyHood && GibdosMask && GarosMask) || 
			(AllNightMask && BunnyHood && GibdosMask && CaptainsHat) || (AllNightMask && BunnyHood && GibdosMask && GiantsMask) || (AllNightMask && BunnyHood && GarosMask && CaptainsHat) || 
			(AllNightMask && BunnyHood && GarosMask && GiantsMask) || (AllNightMask && BunnyHood && CaptainsHat && GiantsMask) || (AllNightMask && DonGerosMask && MaskOfScents && RomanisMask) || 
			(AllNightMask && DonGerosMask && MaskOfScents && CircusLeadersMask) || (AllNightMask && DonGerosMask && MaskOfScents && KafeisMask) || (AllNightMask && DonGerosMask && MaskOfScents && CouplesMask) ||
			(AllNightMask && DonGerosMask && MaskOfScents && MaskOfTruth) || (AllNightMask && DonGerosMask && MaskOfScents && GibdosMask) || (AllNightMask && DonGerosMask && MaskOfScents && GarosMask) || 
			(AllNightMask && DonGerosMask && MaskOfScents && CaptainsHat) || (AllNightMask && DonGerosMask && MaskOfScents && GiantsMask) || (AllNightMask && DonGerosMask && RomanisMask && CircusLeadersMask) || 
			(AllNightMask && DonGerosMask && RomanisMask && KafeisMask) || (AllNightMask && DonGerosMask && RomanisMask && CouplesMask) || (AllNightMask && DonGerosMask && RomanisMask && MaskOfTruth) ||
			(AllNightMask && DonGerosMask && RomanisMask && GibdosMask) || (AllNightMask && DonGerosMask && RomanisMask && GarosMask) || (AllNightMask && DonGerosMask && RomanisMask && CaptainsHat) || 
			(AllNightMask && DonGerosMask && RomanisMask && GiantsMask) || (AllNightMask && DonGerosMask && CircusLeadersMask && KafeisMask) || (AllNightMask && DonGerosMask && CircusLeadersMask && CouplesMask) || 
			(AllNightMask && DonGerosMask && CircusLeadersMask && MaskOfTruth) || (AllNightMask && DonGerosMask && CircusLeadersMask && GibdosMask) || (AllNightMask && DonGerosMask && CircusLeadersMask && GarosMask) ||
			(AllNightMask && DonGerosMask && CircusLeadersMask && CaptainsHat) || (AllNightMask && DonGerosMask && CircusLeadersMask && GiantsMask) || (AllNightMask && DonGerosMask && KafeisMask && CouplesMask) || 
			(AllNightMask && DonGerosMask && KafeisMask && MaskOfTruth) || (AllNightMask && DonGerosMask && KafeisMask && GibdosMask) || (AllNightMask && DonGerosMask && KafeisMask && GarosMask) || 
			(AllNightMask && DonGerosMask && KafeisMask && CaptainsHat) || (AllNightMask && DonGerosMask && KafeisMask && GiantsMask) || (AllNightMask && DonGerosMask && CouplesMask && MaskOfTruth) || 
			(AllNightMask && DonGerosMask && CouplesMask && GibdosMask) || (AllNightMask && DonGerosMask && CouplesMask && GarosMask) || (AllNightMask && DonGerosMask && CouplesMask && CaptainsHat) || 
			(AllNightMask && DonGerosMask && CouplesMask && GiantsMask) || (AllNightMask && DonGerosMask && MaskOfTruth && GibdosMask) || (AllNightMask && DonGerosMask && MaskOfTruth && GarosMask) ||
			(AllNightMask && DonGerosMask && MaskOfTruth && CaptainsHat) || (AllNightMask && DonGerosMask && MaskOfTruth && GiantsMask) || (AllNightMask && DonGerosMask && GibdosMask && GarosMask) || 
			(AllNightMask && DonGerosMask && GibdosMask && CaptainsHat) || (AllNightMask && DonGerosMask && GibdosMask && GiantsMask) || (AllNightMask && DonGerosMask && GarosMask && CaptainsHat) || 
			(AllNightMask && DonGerosMask && GarosMask && GiantsMask) || (AllNightMask && DonGerosMask && CaptainsHat && GiantsMask) || (AllNightMask && MaskOfScents && RomanisMask && CircusLeadersMask) || 
			(AllNightMask && MaskOfScents && RomanisMask && KafeisMask) || (AllNightMask && MaskOfScents && RomanisMask && CouplesMask) || (AllNightMask && MaskOfScents && RomanisMask && MaskOfTruth) ||
			(AllNightMask && MaskOfScents && RomanisMask && GibdosMask) || (AllNightMask && MaskOfScents && RomanisMask && GarosMask) || (AllNightMask && MaskOfScents && RomanisMask && CaptainsHat) || 
			(AllNightMask && MaskOfScents && RomanisMask && GiantsMask) || (AllNightMask && MaskOfScents && CircusLeadersMask && KafeisMask) || (AllNightMask && MaskOfScents && CircusLeadersMask && CouplesMask) ||
			(AllNightMask && MaskOfScents && CircusLeadersMask && MaskOfTruth) || (AllNightMask && MaskOfScents && CircusLeadersMask && GibdosMask) || (AllNightMask && MaskOfScents && CircusLeadersMask && GarosMask) ||
			(AllNightMask && MaskOfScents && CircusLeadersMask && CaptainsHat) || (AllNightMask && MaskOfScents && CircusLeadersMask && GiantsMask) || (AllNightMask && MaskOfScents && KafeisMask && CouplesMask) ||
			(AllNightMask && MaskOfScents && KafeisMask && MaskOfTruth) || (AllNightMask && MaskOfScents && KafeisMask && GibdosMask) || (AllNightMask && MaskOfScents && KafeisMask && GarosMask) ||
			(AllNightMask && MaskOfScents && KafeisMask && CaptainsHat) || (AllNightMask && MaskOfScents && KafeisMask && GiantsMask) || (AllNightMask && MaskOfScents && CouplesMask && MaskOfTruth) || 
			(AllNightMask && MaskOfScents && CouplesMask && GibdosMask) || (AllNightMask && MaskOfScents && CouplesMask && GarosMask) || (AllNightMask && MaskOfScents && CouplesMask && CaptainsHat) ||
			(AllNightMask && MaskOfScents && CouplesMask && GiantsMask) || (AllNightMask && MaskOfScents && MaskOfTruth && GibdosMask) || (AllNightMask && MaskOfScents && MaskOfTruth && GarosMask) || 
			(AllNightMask && MaskOfScents && MaskOfTruth && CaptainsHat) || (AllNightMask && MaskOfScents && MaskOfTruth && GiantsMask) || (AllNightMask && MaskOfScents && GibdosMask && GarosMask) || 
			(AllNightMask && MaskOfScents && GibdosMask && CaptainsHat) || (AllNightMask && MaskOfScents && GibdosMask && GiantsMask) || (AllNightMask && MaskOfScents && GarosMask && CaptainsHat) || 
			(AllNightMask && MaskOfScents && GarosMask && GiantsMask) || (AllNightMask && MaskOfScents && CaptainsHat && GiantsMask) || (AllNightMask && RomanisMask && CircusLeadersMask && KafeisMask) ||
			(AllNightMask && RomanisMask && CircusLeadersMask && CouplesMask) || (AllNightMask && RomanisMask && CircusLeadersMask && MaskOfTruth) || (AllNightMask && RomanisMask && CircusLeadersMask && GibdosMask) ||
			(AllNightMask && RomanisMask && CircusLeadersMask && GarosMask) || (AllNightMask && RomanisMask && CircusLeadersMask && CaptainsHat) || (AllNightMask && RomanisMask && CircusLeadersMask && GiantsMask) ||
			(AllNightMask && RomanisMask && KafeisMask && CouplesMask) || (AllNightMask && RomanisMask && KafeisMask && MaskOfTruth) || (AllNightMask && RomanisMask && KafeisMask && GibdosMask) ||
			(AllNightMask && RomanisMask && KafeisMask && GarosMask) || (AllNightMask && RomanisMask && KafeisMask && CaptainsHat) || (AllNightMask && RomanisMask && KafeisMask && GiantsMask) || 
			(AllNightMask && RomanisMask && CouplesMask && MaskOfTruth) || (AllNightMask && RomanisMask && CouplesMask && GibdosMask) || (AllNightMask && RomanisMask && CouplesMask && GarosMask) || 
			(AllNightMask && RomanisMask && CouplesMask && CaptainsHat) || (AllNightMask && RomanisMask && CouplesMask && GiantsMask) || (AllNightMask && RomanisMask && MaskOfTruth && GibdosMask) ||
			(AllNightMask && RomanisMask && MaskOfTruth && GarosMask) || (AllNightMask && RomanisMask && MaskOfTruth && CaptainsHat) || (AllNightMask && RomanisMask && MaskOfTruth && GiantsMask) || 
			(AllNightMask && RomanisMask && GibdosMask && GarosMask) || (AllNightMask && RomanisMask && GibdosMask && CaptainsHat) || (AllNightMask && RomanisMask && GibdosMask && GiantsMask) || 
			(AllNightMask && RomanisMask && GarosMask && CaptainsHat) || (AllNightMask && RomanisMask && GarosMask && GiantsMask) || (AllNightMask && RomanisMask && CaptainsHat && GiantsMask) || 
			(AllNightMask && CircusLeadersMask && KafeisMask && CouplesMask) || (AllNightMask && CircusLeadersMask && KafeisMask && MaskOfTruth) || (AllNightMask && CircusLeadersMask && KafeisMask && GibdosMask) || 
			(AllNightMask && CircusLeadersMask && KafeisMask && GarosMask) || (AllNightMask && CircusLeadersMask && KafeisMask && CaptainsHat) || (AllNightMask && CircusLeadersMask && KafeisMask && GiantsMask) ||
			(AllNightMask && CircusLeadersMask && CouplesMask && MaskOfTruth) || (AllNightMask && CircusLeadersMask && CouplesMask && GibdosMask) || (AllNightMask && CircusLeadersMask && CouplesMask && GarosMask) ||
			(AllNightMask && CircusLeadersMask && CouplesMask && CaptainsHat) || (AllNightMask && CircusLeadersMask && CouplesMask && GiantsMask) || (AllNightMask && CircusLeadersMask && MaskOfTruth && GibdosMask) || 
			(AllNightMask && CircusLeadersMask && MaskOfTruth && GarosMask) || (AllNightMask && CircusLeadersMask && MaskOfTruth && CaptainsHat) || (AllNightMask && CircusLeadersMask && MaskOfTruth && GiantsMask) || 
			(AllNightMask && CircusLeadersMask && GibdosMask && GarosMask) || (AllNightMask && CircusLeadersMask && GibdosMask && CaptainsHat) || (AllNightMask && CircusLeadersMask && GibdosMask && GiantsMask) || 
			(AllNightMask && CircusLeadersMask && GarosMask && CaptainsHat) || (AllNightMask && CircusLeadersMask && GarosMask && GiantsMask) || (AllNightMask && CircusLeadersMask && CaptainsHat && GiantsMask) || 
			(AllNightMask && KafeisMask && CouplesMask && MaskOfTruth) || (AllNightMask && KafeisMask && CouplesMask && GibdosMask) || (AllNightMask && KafeisMask && CouplesMask && GarosMask) ||
			(AllNightMask && KafeisMask && CouplesMask && CaptainsHat) || (AllNightMask && KafeisMask && CouplesMask && GiantsMask) || (AllNightMask && KafeisMask && MaskOfTruth && GibdosMask) ||
			(AllNightMask && KafeisMask && MaskOfTruth && GarosMask) || (AllNightMask && KafeisMask && MaskOfTruth && CaptainsHat) || (AllNightMask && KafeisMask && MaskOfTruth && GiantsMask) || 
			(AllNightMask && KafeisMask && GibdosMask && GarosMask) || (AllNightMask && KafeisMask && GibdosMask && CaptainsHat) || (AllNightMask && KafeisMask && GibdosMask && GiantsMask) || 
			(AllNightMask && KafeisMask && GarosMask && CaptainsHat) || (AllNightMask && KafeisMask && GarosMask && GiantsMask) || (AllNightMask && KafeisMask && CaptainsHat && GiantsMask) ||
			(AllNightMask && CouplesMask && MaskOfTruth && GibdosMask) || (AllNightMask && CouplesMask && MaskOfTruth && GarosMask) || (AllNightMask && CouplesMask && MaskOfTruth && CaptainsHat) || 
			(AllNightMask && CouplesMask && MaskOfTruth && GiantsMask) || (AllNightMask && CouplesMask && GibdosMask && GarosMask) || (AllNightMask && CouplesMask && GibdosMask && CaptainsHat) ||
			(AllNightMask && CouplesMask && GibdosMask && GiantsMask) || (AllNightMask && CouplesMask && GarosMask && CaptainsHat) || (AllNightMask && CouplesMask && GarosMask && GiantsMask) || 
			(AllNightMask && CouplesMask && CaptainsHat && GiantsMask) || (AllNightMask && MaskOfTruth && GibdosMask && GarosMask) || (AllNightMask && MaskOfTruth && GibdosMask && CaptainsHat) || 
			(AllNightMask && MaskOfTruth && GibdosMask && GiantsMask) || (AllNightMask && MaskOfTruth && GarosMask && CaptainsHat) || (AllNightMask && MaskOfTruth && GarosMask && GiantsMask) || 
			(AllNightMask && MaskOfTruth && CaptainsHat && GiantsMask) || (AllNightMask && GibdosMask && GarosMask && CaptainsHat) || (AllNightMask && GibdosMask && GarosMask && GiantsMask) || 
			(AllNightMask && GibdosMask && CaptainsHat && GiantsMask) || (AllNightMask && GarosMask && CaptainsHat && GiantsMask) || (BlastMask && StoneMask && GreatFairyMask && KeatonMask) || 
			(BlastMask && StoneMask && GreatFairyMask && BremenMask) || (BlastMask && StoneMask && GreatFairyMask && BunnyHood) || (BlastMask && StoneMask && GreatFairyMask && DonGerosMask) || 
			(BlastMask && StoneMask && GreatFairyMask && MaskOfScents) || (BlastMask && StoneMask && GreatFairyMask && RomanisMask) || (BlastMask && StoneMask && GreatFairyMask && CircusLeadersMask) || 
			(BlastMask && StoneMask && GreatFairyMask && KafeisMask) || (BlastMask && StoneMask && GreatFairyMask && CouplesMask) || (BlastMask && StoneMask && GreatFairyMask && MaskOfTruth) || 
			(BlastMask && StoneMask && GreatFairyMask && GibdosMask) || (BlastMask && StoneMask && GreatFairyMask && GarosMask) || (BlastMask && StoneMask && GreatFairyMask && CaptainsHat) || 
			(BlastMask && StoneMask && GreatFairyMask && GiantsMask) || (BlastMask && StoneMask && KeatonMask && BremenMask) || (BlastMask && StoneMask && KeatonMask && BunnyHood) || 
			(BlastMask && StoneMask && KeatonMask && DonGerosMask) || (BlastMask && StoneMask && KeatonMask && MaskOfScents) || (BlastMask && StoneMask && KeatonMask && RomanisMask) || 
			(BlastMask && StoneMask && KeatonMask && CircusLeadersMask) || (BlastMask && StoneMask && KeatonMask && KafeisMask) || (BlastMask && StoneMask && KeatonMask && CouplesMask) || 
			(BlastMask && StoneMask && KeatonMask && MaskOfTruth) || (BlastMask && StoneMask && KeatonMask && GibdosMask) || (BlastMask && StoneMask && KeatonMask && GarosMask) || 
			(BlastMask && StoneMask && KeatonMask && CaptainsHat) || (BlastMask && StoneMask && KeatonMask && GiantsMask) || (BlastMask && StoneMask && BremenMask && BunnyHood) || 
			(BlastMask && StoneMask && BremenMask && DonGerosMask) || (BlastMask && StoneMask && BremenMask && MaskOfScents) || (BlastMask && StoneMask && BremenMask && RomanisMask) || 
			(BlastMask && StoneMask && BremenMask && CircusLeadersMask) || (BlastMask && StoneMask && BremenMask && KafeisMask) || (BlastMask && StoneMask && BremenMask && CouplesMask) ||
			(BlastMask && StoneMask && BremenMask && MaskOfTruth) || (BlastMask && StoneMask && BremenMask && GibdosMask) || (BlastMask && StoneMask && BremenMask && GarosMask) || 
			(BlastMask && StoneMask && BremenMask && CaptainsHat) || (BlastMask && StoneMask && BremenMask && GiantsMask) || (BlastMask && StoneMask && BunnyHood && DonGerosMask) || 
			(BlastMask && StoneMask && BunnyHood && MaskOfScents) || (BlastMask && StoneMask && BunnyHood && RomanisMask) || (BlastMask && StoneMask && BunnyHood && CircusLeadersMask) ||
			(BlastMask && StoneMask && BunnyHood && KafeisMask) || (BlastMask && StoneMask && BunnyHood && CouplesMask) || (BlastMask && StoneMask && BunnyHood && MaskOfTruth) || 
			(BlastMask && StoneMask && BunnyHood && GibdosMask) || (BlastMask && StoneMask && BunnyHood && GarosMask) || (BlastMask && StoneMask && BunnyHood && CaptainsHat) ||
			(BlastMask && StoneMask && BunnyHood && GiantsMask) || (BlastMask && StoneMask && DonGerosMask && MaskOfScents) || (BlastMask && StoneMask && DonGerosMask && RomanisMask) || 
			(BlastMask && StoneMask && DonGerosMask && CircusLeadersMask) || (BlastMask && StoneMask && DonGerosMask && KafeisMask) || (BlastMask && StoneMask && DonGerosMask && CouplesMask) ||
			(BlastMask && StoneMask && DonGerosMask && MaskOfTruth) || (BlastMask && StoneMask && DonGerosMask && GibdosMask) || (BlastMask && StoneMask && DonGerosMask && GarosMask) || 
			(BlastMask && StoneMask && DonGerosMask && CaptainsHat) || (BlastMask && StoneMask && DonGerosMask && GiantsMask) || (BlastMask && StoneMask && MaskOfScents && RomanisMask) || 
			(BlastMask && StoneMask && MaskOfScents && CircusLeadersMask) || (BlastMask && StoneMask && MaskOfScents && KafeisMask) || (BlastMask && StoneMask && MaskOfScents && CouplesMask) ||
			(BlastMask && StoneMask && MaskOfScents && MaskOfTruth) || (BlastMask && StoneMask && MaskOfScents && GibdosMask) || (BlastMask && StoneMask && MaskOfScents && GarosMask) || 
			(BlastMask && StoneMask && MaskOfScents && CaptainsHat) || (BlastMask && StoneMask && MaskOfScents && GiantsMask) || (BlastMask && StoneMask && RomanisMask && CircusLeadersMask) ||
			(BlastMask && StoneMask && RomanisMask && KafeisMask) || (BlastMask && StoneMask && RomanisMask && CouplesMask) || (BlastMask && StoneMask && RomanisMask && MaskOfTruth) || 
			(BlastMask && StoneMask && RomanisMask && GibdosMask) || (BlastMask && StoneMask && RomanisMask && GarosMask) || (BlastMask && StoneMask && RomanisMask && CaptainsHat) || 
			(BlastMask && StoneMask && RomanisMask && GiantsMask) || (BlastMask && StoneMask && CircusLeadersMask && KafeisMask) || (BlastMask && StoneMask && CircusLeadersMask && CouplesMask) ||
			(BlastMask && StoneMask && CircusLeadersMask && MaskOfTruth) || (BlastMask && StoneMask && CircusLeadersMask && GibdosMask) || (BlastMask && StoneMask && CircusLeadersMask && GarosMask) ||
			(BlastMask && StoneMask && CircusLeadersMask && CaptainsHat) || (BlastMask && StoneMask && CircusLeadersMask && GiantsMask) || (BlastMask && StoneMask && KafeisMask && CouplesMask) || 
			(BlastMask && StoneMask && KafeisMask && MaskOfTruth) || (BlastMask && StoneMask && KafeisMask && GibdosMask) || (BlastMask && StoneMask && KafeisMask && GarosMask) || 
			(BlastMask && StoneMask && KafeisMask && CaptainsHat) || (BlastMask && StoneMask && KafeisMask && GiantsMask) || (BlastMask && StoneMask && CouplesMask && MaskOfTruth) || 
			(BlastMask && StoneMask && CouplesMask && GibdosMask) || (BlastMask && StoneMask && CouplesMask && GarosMask) || (BlastMask && StoneMask && CouplesMask && CaptainsHat) || 
			(BlastMask && StoneMask && CouplesMask && GiantsMask) || (BlastMask && StoneMask && MaskOfTruth && GibdosMask) || (BlastMask && StoneMask && MaskOfTruth && GarosMask) || 
			(BlastMask && StoneMask && MaskOfTruth && CaptainsHat) || (BlastMask && StoneMask && MaskOfTruth && GiantsMask) || (BlastMask && StoneMask && GibdosMask && GarosMask) || 
			(BlastMask && StoneMask && GibdosMask && CaptainsHat) || (BlastMask && StoneMask && GibdosMask && GiantsMask) || (BlastMask && StoneMask && GarosMask && CaptainsHat) || 
			(BlastMask && StoneMask && GarosMask && GiantsMask) || (BlastMask && StoneMask && CaptainsHat && GiantsMask) || (BlastMask && GreatFairyMask && KeatonMask && BremenMask) || 
			(BlastMask && GreatFairyMask && KeatonMask && BunnyHood) || (BlastMask && GreatFairyMask && KeatonMask && DonGerosMask) || (BlastMask && GreatFairyMask && KeatonMask && MaskOfScents) || 
			(BlastMask && GreatFairyMask && KeatonMask && RomanisMask) || (BlastMask && GreatFairyMask && KeatonMask && CircusLeadersMask) || (BlastMask && GreatFairyMask && KeatonMask && KafeisMask) ||
			(BlastMask && GreatFairyMask && KeatonMask && CouplesMask) || (BlastMask && GreatFairyMask && KeatonMask && MaskOfTruth) || (BlastMask && GreatFairyMask && KeatonMask && GibdosMask) ||
			(BlastMask && GreatFairyMask && KeatonMask && GarosMask) || (BlastMask && GreatFairyMask && KeatonMask && CaptainsHat) || (BlastMask && GreatFairyMask && KeatonMask && GiantsMask) || 
			(BlastMask && GreatFairyMask && BremenMask && BunnyHood) || (BlastMask && GreatFairyMask && BremenMask && DonGerosMask) || (BlastMask && GreatFairyMask && BremenMask && MaskOfScents) || 
			(BlastMask && GreatFairyMask && BremenMask && RomanisMask) || (BlastMask && GreatFairyMask && BremenMask && CircusLeadersMask) || (BlastMask && GreatFairyMask && BremenMask && KafeisMask) || 
			(BlastMask && GreatFairyMask && BremenMask && CouplesMask) || (BlastMask && GreatFairyMask && BremenMask && MaskOfTruth) || (BlastMask && GreatFairyMask && BremenMask && GibdosMask) || 
			(BlastMask && GreatFairyMask && BremenMask && GarosMask) || (BlastMask && GreatFairyMask && BremenMask && CaptainsHat) || (BlastMask && GreatFairyMask && BremenMask && GiantsMask) || 
			(BlastMask && GreatFairyMask && BunnyHood && DonGerosMask) || (BlastMask && GreatFairyMask && BunnyHood && MaskOfScents) || (BlastMask && GreatFairyMask && BunnyHood && RomanisMask) || 
			(BlastMask && GreatFairyMask && BunnyHood && CircusLeadersMask) || (BlastMask && GreatFairyMask && BunnyHood && KafeisMask) || (BlastMask && GreatFairyMask && BunnyHood && CouplesMask) ||
			(BlastMask && GreatFairyMask && BunnyHood && MaskOfTruth) || (BlastMask && GreatFairyMask && BunnyHood && GibdosMask) || (BlastMask && GreatFairyMask && BunnyHood && GarosMask) || 
			(BlastMask && GreatFairyMask && BunnyHood && CaptainsHat) || (BlastMask && GreatFairyMask && BunnyHood && GiantsMask) || (BlastMask && GreatFairyMask && DonGerosMask && MaskOfScents) || 
			(BlastMask && GreatFairyMask && DonGerosMask && GarosMask) || (BlastMask && GreatFairyMask && DonGerosMask && CaptainsHat) || (BlastMask && GreatFairyMask && DonGerosMask && GiantsMask) ||
			(BlastMask && GreatFairyMask && MaskOfScents && RomanisMask) || (BlastMask && GreatFairyMask && MaskOfScents && CircusLeadersMask) || (BlastMask && GreatFairyMask && MaskOfScents && KafeisMask) || 
			(BlastMask && GreatFairyMask && MaskOfScents && CouplesMask) || (BlastMask && GreatFairyMask && MaskOfScents && MaskOfTruth) || (BlastMask && GreatFairyMask && MaskOfScents && GibdosMask) || 
			(BlastMask && GreatFairyMask && MaskOfScents && GarosMask) || (BlastMask && GreatFairyMask && MaskOfScents && CaptainsHat) || (BlastMask && GreatFairyMask && MaskOfScents && GiantsMask) || 
			(BlastMask && GreatFairyMask && RomanisMask && CircusLeadersMask) || (BlastMask && GreatFairyMask && RomanisMask && KafeisMask) || (BlastMask && GreatFairyMask && RomanisMask && CouplesMask) ||
			(BlastMask && GreatFairyMask && RomanisMask && MaskOfTruth) || (BlastMask && GreatFairyMask && RomanisMask && GibdosMask) || (BlastMask && GreatFairyMask && RomanisMask && GarosMask) || 
			(BlastMask && GreatFairyMask && RomanisMask && CaptainsHat) || (BlastMask && GreatFairyMask && RomanisMask && GiantsMask) || (BlastMask && GreatFairyMask && CircusLeadersMask && KafeisMask) ||
			(BlastMask && GreatFairyMask && CircusLeadersMask && CouplesMask) || (BlastMask && GreatFairyMask && CircusLeadersMask && MaskOfTruth) || (BlastMask && GreatFairyMask && CircusLeadersMask && GibdosMask) ||
			(BlastMask && GreatFairyMask && CircusLeadersMask && GarosMask) || (BlastMask && GreatFairyMask && CircusLeadersMask && CaptainsHat) || (BlastMask && GreatFairyMask && CircusLeadersMask && GiantsMask) ||
			(BlastMask && GreatFairyMask && KafeisMask && CouplesMask) || (BlastMask && GreatFairyMask && KafeisMask && MaskOfTruth) || (BlastMask && GreatFairyMask && KafeisMask && GibdosMask) || 
			(BlastMask && GreatFairyMask && KafeisMask && GarosMask) || (BlastMask && GreatFairyMask && KafeisMask && CaptainsHat) || (BlastMask && GreatFairyMask && KafeisMask && GiantsMask) ||
			(BlastMask && GreatFairyMask && CouplesMask && MaskOfTruth) || (BlastMask && GreatFairyMask && CouplesMask && GibdosMask) || (BlastMask && GreatFairyMask && CouplesMask && GarosMask) || 
			(BlastMask && GreatFairyMask && CouplesMask && CaptainsHat) || (BlastMask && GreatFairyMask && CouplesMask && GiantsMask) || (BlastMask && GreatFairyMask && MaskOfTruth && GibdosMask) || 
			(BlastMask && GreatFairyMask && MaskOfTruth && GarosMask) || (BlastMask && GreatFairyMask && MaskOfTruth && CaptainsHat) || (BlastMask && GreatFairyMask && MaskOfTruth && GiantsMask) || 
			(BlastMask && GreatFairyMask && GibdosMask && GarosMask) || (BlastMask && GreatFairyMask && GibdosMask && CaptainsHat) || (BlastMask && GreatFairyMask && GibdosMask && GiantsMask) || 
			(BlastMask && GreatFairyMask && GarosMask && CaptainsHat) || (BlastMask && GreatFairyMask && GarosMask && GiantsMask) || (BlastMask && GreatFairyMask && CaptainsHat && GiantsMask) || 
			(BlastMask && KeatonMask && BremenMask && BunnyHood) || (BlastMask && KeatonMask && BremenMask && DonGerosMask) || (BlastMask && KeatonMask && BremenMask && MaskOfScents) || 
			(BlastMask && KeatonMask && BremenMask && RomanisMask) || (BlastMask && KeatonMask && BremenMask && CircusLeadersMask) || (BlastMask && KeatonMask && BremenMask && KafeisMask) || 
			(BlastMask && KeatonMask && BremenMask && CouplesMask) || (BlastMask && KeatonMask && BremenMask && MaskOfTruth) || (BlastMask && KeatonMask && BremenMask && GibdosMask) || 
			(BlastMask && KeatonMask && BremenMask && GarosMask) || (BlastMask && KeatonMask && BremenMask && CaptainsHat) || (BlastMask && KeatonMask && BremenMask && GiantsMask) ||
			(BlastMask && KeatonMask && BunnyHood && DonGerosMask) || (BlastMask && KeatonMask && BunnyHood && MaskOfScents) || (BlastMask && KeatonMask && BunnyHood && RomanisMask) || 
			(BlastMask && KeatonMask && BunnyHood && CircusLeadersMask) || (BlastMask && KeatonMask && BunnyHood && KafeisMask) || (BlastMask && KeatonMask && BunnyHood && CouplesMask) ||
			(BlastMask && KeatonMask && BunnyHood && MaskOfTruth) || (BlastMask && KeatonMask && BunnyHood && GibdosMask) || (BlastMask && KeatonMask && BunnyHood && GarosMask) || 
			(BlastMask && KeatonMask && BunnyHood && CaptainsHat) || (BlastMask && KeatonMask && BunnyHood && GiantsMask) || (BlastMask && KeatonMask && DonGerosMask && MaskOfScents) || 
			(BlastMask && KeatonMask && DonGerosMask && RomanisMask) || (BlastMask && KeatonMask && DonGerosMask && CircusLeadersMask) || (BlastMask && KeatonMask && DonGerosMask && KafeisMask) ||
			(BlastMask && KeatonMask && DonGerosMask && CouplesMask) || (BlastMask && KeatonMask && DonGerosMask && MaskOfTruth) || (BlastMask && KeatonMask && DonGerosMask && GibdosMask) ||
			(BlastMask && KeatonMask && DonGerosMask && GarosMask) || (BlastMask && KeatonMask && DonGerosMask && CaptainsHat) || (BlastMask && KeatonMask && DonGerosMask && GiantsMask) ||
			(BlastMask && KeatonMask && MaskOfScents && RomanisMask) || (BlastMask && KeatonMask && MaskOfScents && CircusLeadersMask) || (BlastMask && KeatonMask && MaskOfScents && KafeisMask) || 
			(BlastMask && KeatonMask && MaskOfScents && CouplesMask) || (BlastMask && KeatonMask && MaskOfScents && MaskOfTruth) || (BlastMask && KeatonMask && MaskOfScents && GibdosMask) ||
			(BlastMask && KeatonMask && MaskOfScents && GarosMask) || (BlastMask && KeatonMask && MaskOfScents && CaptainsHat) || (BlastMask && KeatonMask && MaskOfScents && GiantsMask) || 
			(BlastMask && KeatonMask && RomanisMask && CircusLeadersMask) || (BlastMask && KeatonMask && RomanisMask && KafeisMask) || (BlastMask && KeatonMask && RomanisMask && CouplesMask) || 
			(BlastMask && KeatonMask && RomanisMask && MaskOfTruth) || (BlastMask && KeatonMask && RomanisMask && GibdosMask) || (BlastMask && KeatonMask && RomanisMask && GarosMask) || 
			(BlastMask && KeatonMask && RomanisMask && CaptainsHat) || (BlastMask && KeatonMask && RomanisMask && GiantsMask) || (BlastMask && KeatonMask && CircusLeadersMask && KafeisMask) ||
			(BlastMask && KeatonMask && CircusLeadersMask && CouplesMask) || (BlastMask && KeatonMask && CircusLeadersMask && MaskOfTruth) || (BlastMask && KeatonMask && CircusLeadersMask && GibdosMask) ||
			(BlastMask && KeatonMask && CircusLeadersMask && GarosMask) || (BlastMask && KeatonMask && CircusLeadersMask && CaptainsHat) || (BlastMask && KeatonMask && CircusLeadersMask && GiantsMask) ||
			(BlastMask && KeatonMask && KafeisMask && CouplesMask) || (BlastMask && KeatonMask && KafeisMask && MaskOfTruth) || (BlastMask && KeatonMask && KafeisMask && GibdosMask) || 
			(BlastMask && KeatonMask && KafeisMask && GarosMask) || (BlastMask && KeatonMask && KafeisMask && CaptainsHat) || (BlastMask && KeatonMask && KafeisMask && GiantsMask) || 
			(BlastMask && KeatonMask && CouplesMask && MaskOfTruth) || (BlastMask && KeatonMask && CouplesMask && GibdosMask) || (BlastMask && KeatonMask && CouplesMask && GarosMask) || 
			(BlastMask && KeatonMask && CouplesMask && CaptainsHat) || (BlastMask && KeatonMask && CouplesMask && GiantsMask) || (BlastMask && KeatonMask && MaskOfTruth && GibdosMask) || 
			(BlastMask && KeatonMask && MaskOfTruth && GarosMask) || (BlastMask && KeatonMask && MaskOfTruth && CaptainsHat) || (BlastMask && KeatonMask && MaskOfTruth && GiantsMask) ||
			(BlastMask && KeatonMask && GibdosMask && GarosMask) || (BlastMask && KeatonMask && GibdosMask && CaptainsHat) || (BlastMask && KeatonMask && GibdosMask && GiantsMask) ||
			(BlastMask && KeatonMask && GarosMask && CaptainsHat) || (BlastMask && KeatonMask && GarosMask && GiantsMask) || (BlastMask && KeatonMask && CaptainsHat && GiantsMask) || 
			(BlastMask && BremenMask && BunnyHood && DonGerosMask) || (BlastMask && BremenMask && BunnyHood && MaskOfScents) || (BlastMask && BremenMask && BunnyHood && RomanisMask) || 
			(BlastMask && BremenMask && BunnyHood && CircusLeadersMask) || (BlastMask && BremenMask && BunnyHood && KafeisMask) || (BlastMask && BremenMask && BunnyHood && CouplesMask) || 
			(BlastMask && BremenMask && BunnyHood && MaskOfTruth) || (BlastMask && BremenMask && BunnyHood && GibdosMask) || (BlastMask && BremenMask && BunnyHood && GarosMask) ||
			(BlastMask && BremenMask && BunnyHood && CaptainsHat) || (BlastMask && BremenMask && BunnyHood && GiantsMask) || (BlastMask && BremenMask && DonGerosMask && MaskOfScents) ||
			(BlastMask && BremenMask && DonGerosMask && RomanisMask) || (BlastMask && BremenMask && DonGerosMask && CircusLeadersMask) || (BlastMask && BremenMask && DonGerosMask && KafeisMask) || 
			(BlastMask && BremenMask && DonGerosMask && CouplesMask) || (BlastMask && BremenMask && DonGerosMask && MaskOfTruth) || (BlastMask && BremenMask && DonGerosMask && GibdosMask) ||
			(BlastMask && BremenMask && DonGerosMask && GarosMask) || (BlastMask && BremenMask && DonGerosMask && CaptainsHat) || (BlastMask && BremenMask && DonGerosMask && GiantsMask) ||
			(BlastMask && BremenMask && MaskOfScents && RomanisMask) || (BlastMask && BremenMask && MaskOfScents && CircusLeadersMask) || (BlastMask && BremenMask && MaskOfScents && KafeisMask) ||
			(BlastMask && BremenMask && MaskOfScents && CouplesMask) || (BlastMask && BremenMask && MaskOfScents && MaskOfTruth) || (BlastMask && BremenMask && MaskOfScents && GibdosMask) || 
			(BlastMask && BremenMask && MaskOfScents && GarosMask) || (BlastMask && BremenMask && MaskOfScents && CaptainsHat) || (BlastMask && BremenMask && MaskOfScents && GiantsMask) || 
			(BlastMask && BremenMask && RomanisMask && CircusLeadersMask) || (BlastMask && BremenMask && RomanisMask && KafeisMask) || (BlastMask && BremenMask && RomanisMask && CouplesMask) || 
			(BlastMask && BremenMask && RomanisMask && MaskOfTruth) || (BlastMask && BremenMask && RomanisMask && GibdosMask) || (BlastMask && BremenMask && RomanisMask && GarosMask) || 
			(BlastMask && BremenMask && RomanisMask && CaptainsHat) || (BlastMask && BremenMask && RomanisMask && GiantsMask) || (BlastMask && BremenMask && CircusLeadersMask && KafeisMask) ||
			(BlastMask && BremenMask && CircusLeadersMask && CouplesMask) || (BlastMask && BremenMask && CircusLeadersMask && MaskOfTruth) || (BlastMask && BremenMask && CircusLeadersMask && GibdosMask) ||
			(BlastMask && BremenMask && CircusLeadersMask && GarosMask) || (BlastMask && BremenMask && CircusLeadersMask && CaptainsHat) || (BlastMask && BremenMask && CircusLeadersMask && GiantsMask) || 
			(BlastMask && BremenMask && KafeisMask && CouplesMask) || (BlastMask && BremenMask && KafeisMask && MaskOfTruth) || (BlastMask && BremenMask && KafeisMask && GibdosMask) ||
			(BlastMask && BremenMask && KafeisMask && GarosMask) || (BlastMask && BremenMask && KafeisMask && CaptainsHat) || (BlastMask && BremenMask && KafeisMask && GiantsMask) ||
			(BlastMask && BremenMask && CouplesMask && MaskOfTruth) || (BlastMask && BremenMask && CouplesMask && GibdosMask) || (BlastMask && BremenMask && CouplesMask && GarosMask) || 
			(BlastMask && BremenMask && CouplesMask && CaptainsHat) || (BlastMask && BremenMask && CouplesMask && GiantsMask) || (BlastMask && BremenMask && MaskOfTruth && GibdosMask) || 
			(BlastMask && BremenMask && MaskOfTruth && GarosMask) || (BlastMask && BremenMask && MaskOfTruth && CaptainsHat) || (BlastMask && BremenMask && MaskOfTruth && GiantsMask) || 
			(BlastMask && BremenMask && GibdosMask && GarosMask) || (BlastMask && BremenMask && GibdosMask && CaptainsHat) || (BlastMask && BremenMask && GibdosMask && GiantsMask) ||
			(BlastMask && BremenMask && GarosMask && CaptainsHat) || (BlastMask && BremenMask && GarosMask && GiantsMask) || (BlastMask && BremenMask && CaptainsHat && GiantsMask) || 
			(BlastMask && BunnyHood && DonGerosMask && MaskOfScents) || (BlastMask && BunnyHood && DonGerosMask && RomanisMask) || (BlastMask && BunnyHood && DonGerosMask && CircusLeadersMask) || 
			(BlastMask && BunnyHood && DonGerosMask && KafeisMask) || (BlastMask && BunnyHood && DonGerosMask && CouplesMask) || (BlastMask && BunnyHood && DonGerosMask && MaskOfTruth) || 
			(BlastMask && BunnyHood && DonGerosMask && GibdosMask) || (BlastMask && BunnyHood && DonGerosMask && GarosMask) || (BlastMask && BunnyHood && DonGerosMask && CaptainsHat) ||
			(BlastMask && BunnyHood && DonGerosMask && GiantsMask) || (BlastMask && BunnyHood && MaskOfScents && RomanisMask) || (BlastMask && BunnyHood && MaskOfScents && CircusLeadersMask) || 
			(BlastMask && BunnyHood && MaskOfScents && KafeisMask) || (BlastMask && BunnyHood && MaskOfScents && CouplesMask) || (BlastMask && BunnyHood && MaskOfScents && MaskOfTruth) || 
			(BlastMask && BunnyHood && MaskOfScents && GibdosMask) || (BlastMask && BunnyHood && MaskOfScents && GarosMask) || (BlastMask && BunnyHood && MaskOfScents && CaptainsHat) || 
			(BlastMask && BunnyHood && MaskOfScents && GiantsMask) || (BlastMask && BunnyHood && RomanisMask && CircusLeadersMask) || (BlastMask && BunnyHood && RomanisMask && KafeisMask) || 
			(BlastMask && BunnyHood && RomanisMask && CouplesMask) || (BlastMask && BunnyHood && RomanisMask && MaskOfTruth) || (BlastMask && BunnyHood && RomanisMask && GibdosMask) ||
			(BlastMask && BunnyHood && RomanisMask && GarosMask) || (BlastMask && BunnyHood && RomanisMask && CaptainsHat) || (BlastMask && BunnyHood && RomanisMask && GiantsMask) ||
			(BlastMask && BunnyHood && CircusLeadersMask && KafeisMask) || (BlastMask && BunnyHood && CircusLeadersMask && CouplesMask) || (BlastMask && BunnyHood && CircusLeadersMask && MaskOfTruth) || 
			(BlastMask && BunnyHood && CircusLeadersMask && GibdosMask) || (BlastMask && BunnyHood && CircusLeadersMask && GarosMask) || (BlastMask && BunnyHood && CircusLeadersMask && CaptainsHat) || 
			(BlastMask && BunnyHood && CircusLeadersMask && GiantsMask) || (BlastMask && BunnyHood && KafeisMask && CouplesMask) || (BlastMask && BunnyHood && KafeisMask && MaskOfTruth) || 
			(BlastMask && BunnyHood && KafeisMask && GibdosMask) || (BlastMask && BunnyHood && KafeisMask && GarosMask) || (BlastMask && BunnyHood && KafeisMask && CaptainsHat) || 
			(BlastMask && BunnyHood && KafeisMask && GiantsMask) || (BlastMask && BunnyHood && CouplesMask && MaskOfTruth) || (BlastMask && BunnyHood && CouplesMask && GibdosMask) || 
			(BlastMask && BunnyHood && CouplesMask && GarosMask) || (BlastMask && BunnyHood && CouplesMask && CaptainsHat) || (BlastMask && BunnyHood && CouplesMask && GiantsMask) || 
			(BlastMask && BunnyHood && MaskOfTruth && GibdosMask) || (BlastMask && BunnyHood && MaskOfTruth && GarosMask) || (BlastMask && BunnyHood && MaskOfTruth && CaptainsHat) || 
			(BlastMask && BunnyHood && MaskOfTruth && GiantsMask) || (BlastMask && BunnyHood && GibdosMask && GarosMask) || (BlastMask && BunnyHood && GibdosMask && CaptainsHat) || 
			(BlastMask && BunnyHood && GibdosMask && GiantsMask) || (BlastMask && BunnyHood && GarosMask && CaptainsHat) || (BlastMask && BunnyHood && GarosMask && GiantsMask) || 
			(BlastMask && BunnyHood && CaptainsHat && GiantsMask) || (BlastMask && DonGerosMask && MaskOfScents && RomanisMask) || (BlastMask && DonGerosMask && MaskOfScents && CircusLeadersMask) ||
			(BlastMask && DonGerosMask && MaskOfScents && KafeisMask) || (BlastMask && DonGerosMask && MaskOfScents && CouplesMask) || (BlastMask && DonGerosMask && MaskOfScents && MaskOfTruth) ||
			(BlastMask && DonGerosMask && MaskOfScents && GibdosMask) || (BlastMask && DonGerosMask && MaskOfScents && GarosMask) || (BlastMask && DonGerosMask && MaskOfScents && CaptainsHat) ||
			(BlastMask && DonGerosMask && MaskOfScents && GiantsMask) || (BlastMask && DonGerosMask && RomanisMask && CircusLeadersMask) || (BlastMask && DonGerosMask && RomanisMask && KafeisMask) ||
			(BlastMask && DonGerosMask && RomanisMask && CouplesMask) || (BlastMask && DonGerosMask && RomanisMask && MaskOfTruth) || (BlastMask && DonGerosMask && RomanisMask && GibdosMask) || 
			(BlastMask && DonGerosMask && RomanisMask && GarosMask) || (BlastMask && DonGerosMask && RomanisMask && CaptainsHat) || (BlastMask && DonGerosMask && RomanisMask && GiantsMask) || 
			(BlastMask && DonGerosMask && CircusLeadersMask && KafeisMask) || (BlastMask && DonGerosMask && CircusLeadersMask && CouplesMask) || (BlastMask && DonGerosMask && CircusLeadersMask && MaskOfTruth) ||
			(BlastMask && DonGerosMask && CircusLeadersMask && GibdosMask) || (BlastMask && DonGerosMask && CircusLeadersMask && GarosMask) || (BlastMask && DonGerosMask && CircusLeadersMask && CaptainsHat) || 
			(BlastMask && DonGerosMask && CircusLeadersMask && GiantsMask) || (BlastMask && DonGerosMask && KafeisMask && CouplesMask) || (BlastMask && DonGerosMask && KafeisMask && MaskOfTruth) || 
			(BlastMask && DonGerosMask && KafeisMask && GibdosMask) || (BlastMask && DonGerosMask && KafeisMask && GarosMask) || (BlastMask && DonGerosMask && KafeisMask && CaptainsHat) || 
			(BlastMask && DonGerosMask && KafeisMask && GiantsMask) || (BlastMask && DonGerosMask && CouplesMask && MaskOfTruth) || (BlastMask && DonGerosMask && CouplesMask && GibdosMask) ||
			(BlastMask && DonGerosMask && CouplesMask && GarosMask) || (BlastMask && DonGerosMask && CouplesMask && CaptainsHat) || (BlastMask && DonGerosMask && CouplesMask && GiantsMask) || 
			(BlastMask && DonGerosMask && MaskOfTruth && GibdosMask) || (BlastMask && DonGerosMask && MaskOfTruth && GarosMask) || (BlastMask && DonGerosMask && MaskOfTruth && CaptainsHat) || 
			(BlastMask && DonGerosMask && MaskOfTruth && GiantsMask) || (BlastMask && DonGerosMask && GibdosMask && GarosMask) || (BlastMask && DonGerosMask && GibdosMask && CaptainsHat) ||
			(BlastMask && DonGerosMask && GibdosMask && GiantsMask) || (BlastMask && DonGerosMask && GarosMask && CaptainsHat) || (BlastMask && DonGerosMask && GarosMask && GiantsMask) || 
			(BlastMask && DonGerosMask && CaptainsHat && GiantsMask) || (BlastMask && MaskOfScents && RomanisMask && CircusLeadersMask) || (BlastMask && MaskOfScents && RomanisMask && KafeisMask) ||
			(BlastMask && MaskOfScents && RomanisMask && CouplesMask) || (BlastMask && MaskOfScents && RomanisMask && MaskOfTruth) || (BlastMask && MaskOfScents && RomanisMask && GibdosMask) || 
			(BlastMask && MaskOfScents && RomanisMask && GarosMask) || (BlastMask && MaskOfScents && RomanisMask && CaptainsHat) || (BlastMask && MaskOfScents && RomanisMask && GiantsMask) ||
			(BlastMask && MaskOfScents && CircusLeadersMask && KafeisMask) || (BlastMask && MaskOfScents && CircusLeadersMask && CouplesMask) || (BlastMask && MaskOfScents && CircusLeadersMask && MaskOfTruth) ||
			(BlastMask && MaskOfScents && CircusLeadersMask && GibdosMask) || (BlastMask && MaskOfScents && CircusLeadersMask && GarosMask) || (BlastMask && MaskOfScents && CircusLeadersMask && CaptainsHat) ||
			(BlastMask && MaskOfScents && CircusLeadersMask && GiantsMask) || (BlastMask && MaskOfScents && KafeisMask && CouplesMask) || (BlastMask && MaskOfScents && KafeisMask && MaskOfTruth) || 
			(BlastMask && MaskOfScents && KafeisMask && GibdosMask) || (BlastMask && MaskOfScents && KafeisMask && GarosMask) || (BlastMask && MaskOfScents && KafeisMask && CaptainsHat) ||
			(BlastMask && MaskOfScents && KafeisMask && GiantsMask) || (BlastMask && MaskOfScents && CouplesMask && MaskOfTruth) || (BlastMask && MaskOfScents && CouplesMask && GibdosMask) ||
			(BlastMask && MaskOfScents && CouplesMask && GarosMask) || (BlastMask && MaskOfScents && CouplesMask && CaptainsHat) || (BlastMask && MaskOfScents && CouplesMask && GiantsMask) ||
			(BlastMask && MaskOfScents && MaskOfTruth && GibdosMask) || (BlastMask && MaskOfScents && MaskOfTruth && GarosMask) || (BlastMask && MaskOfScents && MaskOfTruth && CaptainsHat) || 
			(BlastMask && MaskOfScents && MaskOfTruth && GiantsMask) || (BlastMask && MaskOfScents && GibdosMask && GarosMask) || (BlastMask && MaskOfScents && GibdosMask && CaptainsHat) ||
			(BlastMask && MaskOfScents && GibdosMask && GiantsMask) || (BlastMask && MaskOfScents && GarosMask && CaptainsHat) || (BlastMask && MaskOfScents && GarosMask && GiantsMask) || 
			(BlastMask && MaskOfScents && CaptainsHat && GiantsMask) || (BlastMask && RomanisMask && CircusLeadersMask && KafeisMask) || (BlastMask && RomanisMask && CircusLeadersMask && CouplesMask) ||
			(BlastMask && RomanisMask && CircusLeadersMask && MaskOfTruth) || (BlastMask && RomanisMask && CircusLeadersMask && GibdosMask) || (BlastMask && RomanisMask && CircusLeadersMask && GarosMask) || 
			(BlastMask && RomanisMask && CircusLeadersMask && CaptainsHat) || (BlastMask && RomanisMask && CircusLeadersMask && GiantsMask) || (BlastMask && RomanisMask && KafeisMask && CouplesMask) || 
			(BlastMask && RomanisMask && KafeisMask && MaskOfTruth) || (BlastMask && RomanisMask && KafeisMask && GibdosMask) || (BlastMask && RomanisMask && KafeisMask && GarosMask) ||
			(BlastMask && RomanisMask && KafeisMask && CaptainsHat) || (BlastMask && RomanisMask && KafeisMask && GiantsMask) || (BlastMask && RomanisMask && CouplesMask && MaskOfTruth) || 
			(BlastMask && RomanisMask && CouplesMask && GibdosMask) || (BlastMask && RomanisMask && CouplesMask && GarosMask) || (BlastMask && RomanisMask && CouplesMask && CaptainsHat) || 
			(BlastMask && RomanisMask && CouplesMask && GiantsMask) || (BlastMask && RomanisMask && MaskOfTruth && GibdosMask) || (BlastMask && RomanisMask && MaskOfTruth && GarosMask) || 
			(BlastMask && RomanisMask && MaskOfTruth && CaptainsHat) || (BlastMask && RomanisMask && MaskOfTruth && GiantsMask) || (BlastMask && RomanisMask && GibdosMask && GarosMask) || 
			(BlastMask && RomanisMask && GibdosMask && CaptainsHat) || (BlastMask && RomanisMask && GibdosMask && GiantsMask) || (BlastMask && RomanisMask && GarosMask && CaptainsHat) || 
			(BlastMask && RomanisMask && GarosMask && GiantsMask) || (BlastMask && RomanisMask && CaptainsHat && GiantsMask) || (BlastMask && CircusLeadersMask && KafeisMask && CouplesMask) ||
			(BlastMask && CircusLeadersMask && KafeisMask && MaskOfTruth) || (BlastMask && CircusLeadersMask && KafeisMask && GibdosMask) || (BlastMask && CircusLeadersMask && KafeisMask && GarosMask) || 
			(BlastMask && CircusLeadersMask && KafeisMask && CaptainsHat) || (BlastMask && CircusLeadersMask && KafeisMask && GiantsMask) || (BlastMask && CircusLeadersMask && CouplesMask && MaskOfTruth) || 
			(BlastMask && CircusLeadersMask && CouplesMask && GibdosMask) || (BlastMask && CircusLeadersMask && CouplesMask && GarosMask) || (BlastMask && CircusLeadersMask && CouplesMask && CaptainsHat) || 
			(BlastMask && CircusLeadersMask && CouplesMask && GiantsMask) || (BlastMask && CircusLeadersMask && MaskOfTruth && GibdosMask) || (BlastMask && CircusLeadersMask && MaskOfTruth && GarosMask) || 
			(BlastMask && CircusLeadersMask && MaskOfTruth && CaptainsHat) || (BlastMask && CircusLeadersMask && MaskOfTruth && GiantsMask) || (BlastMask && CircusLeadersMask && GibdosMask && GarosMask) || 
			(BlastMask && CircusLeadersMask && GibdosMask && CaptainsHat) || (BlastMask && CircusLeadersMask && GibdosMask && GiantsMask) || (BlastMask && CircusLeadersMask && GarosMask && CaptainsHat) ||
			(BlastMask && CircusLeadersMask && GarosMask && GiantsMask) || (BlastMask && CircusLeadersMask && CaptainsHat && GiantsMask) || (BlastMask && KafeisMask && CouplesMask && MaskOfTruth) ||
			(BlastMask && KafeisMask && CouplesMask && GibdosMask) || (BlastMask && KafeisMask && CouplesMask && GarosMask) || (BlastMask && KafeisMask && CouplesMask && CaptainsHat) ||
			(BlastMask && KafeisMask && CouplesMask && GiantsMask) || (BlastMask && KafeisMask && MaskOfTruth && GibdosMask) || (BlastMask && KafeisMask && MaskOfTruth && GarosMask) || 
			(BlastMask && KafeisMask && MaskOfTruth && CaptainsHat) || (BlastMask && KafeisMask && MaskOfTruth && GiantsMask) || (BlastMask && KafeisMask && GibdosMask && GarosMask) || 
			(BlastMask && KafeisMask && GibdosMask && CaptainsHat) || (BlastMask && KafeisMask && GibdosMask && GiantsMask) || (BlastMask && KafeisMask && GarosMask && CaptainsHat) ||
			(BlastMask && KafeisMask && GarosMask && GiantsMask) || (BlastMask && KafeisMask && CaptainsHat && GiantsMask) || (BlastMask && CouplesMask && MaskOfTruth && GibdosMask) || 
			(BlastMask && CouplesMask && MaskOfTruth && GarosMask) || (BlastMask && CouplesMask && MaskOfTruth && CaptainsHat) || (BlastMask && CouplesMask && MaskOfTruth && GiantsMask) ||
			(BlastMask && CouplesMask && GibdosMask && GarosMask) || (BlastMask && CouplesMask && GibdosMask && CaptainsHat) || (BlastMask && CouplesMask && GibdosMask && GiantsMask) ||
			(BlastMask && CouplesMask && GarosMask && CaptainsHat) || (BlastMask && CouplesMask && GarosMask && GiantsMask) || (BlastMask && CouplesMask && CaptainsHat && GiantsMask) ||
			(BlastMask && MaskOfTruth && GibdosMask && GarosMask) || (BlastMask && MaskOfTruth && GibdosMask && CaptainsHat) || (BlastMask && MaskOfTruth && GibdosMask && GiantsMask) || 
			(BlastMask && MaskOfTruth && GarosMask && CaptainsHat) || (BlastMask && MaskOfTruth && GarosMask && GiantsMask) || (BlastMask && MaskOfTruth && CaptainsHat && GiantsMask) || 
			(BlastMask && GibdosMask && GarosMask && CaptainsHat) || (BlastMask && GibdosMask && GarosMask && GiantsMask) || (BlastMask && GibdosMask && CaptainsHat && GiantsMask) ||
			(BlastMask && GarosMask && CaptainsHat && GiantsMask) || (StoneMask && GreatFairyMask && KeatonMask && BremenMask) || (StoneMask && GreatFairyMask && KeatonMask && BunnyHood) || 
			(StoneMask && GreatFairyMask && KeatonMask && DonGerosMask) || (StoneMask && GreatFairyMask && KeatonMask && MaskOfScents) || (StoneMask && GreatFairyMask && KeatonMask && RomanisMask) || 
			(StoneMask && GreatFairyMask && KeatonMask && CircusLeadersMask) || (StoneMask && GreatFairyMask && KeatonMask && KafeisMask) || (StoneMask && GreatFairyMask && KeatonMask && CouplesMask) || 
			(StoneMask && GreatFairyMask && KeatonMask && MaskOfTruth) || (StoneMask && GreatFairyMask && KeatonMask && GibdosMask) || (StoneMask && GreatFairyMask && KeatonMask && GarosMask) || 
			(StoneMask && GreatFairyMask && KeatonMask && CaptainsHat) || (StoneMask && GreatFairyMask && KeatonMask && GiantsMask) || (StoneMask && GreatFairyMask && BremenMask && BunnyHood) ||
			(StoneMask && GreatFairyMask && BremenMask && DonGerosMask) || (StoneMask && GreatFairyMask && BremenMask && MaskOfScents) || (StoneMask && GreatFairyMask && BremenMask && RomanisMask) ||
			(StoneMask && GreatFairyMask && BremenMask && CircusLeadersMask) || (StoneMask && GreatFairyMask && BremenMask && KafeisMask) || (StoneMask && GreatFairyMask && BremenMask && CouplesMask) ||
			(StoneMask && GreatFairyMask && BremenMask && MaskOfTruth) || (StoneMask && GreatFairyMask && BremenMask && GibdosMask) || (StoneMask && GreatFairyMask && BremenMask && GarosMask) || 
			(StoneMask && GreatFairyMask && BremenMask && CaptainsHat) || (StoneMask && GreatFairyMask && BremenMask && GiantsMask) || (StoneMask && GreatFairyMask && BunnyHood && DonGerosMask) ||
			(StoneMask && GreatFairyMask && BunnyHood && MaskOfScents) || (StoneMask && GreatFairyMask && BunnyHood && RomanisMask) || (StoneMask && GreatFairyMask && BunnyHood && CircusLeadersMask) ||
			(StoneMask && GreatFairyMask && BunnyHood && KafeisMask) || (StoneMask && GreatFairyMask && BunnyHood && CouplesMask) || (StoneMask && GreatFairyMask && BunnyHood && MaskOfTruth) || 
			(StoneMask && GreatFairyMask && BunnyHood && GibdosMask) || (StoneMask && GreatFairyMask && BunnyHood && GarosMask) || (StoneMask && GreatFairyMask && BunnyHood && CaptainsHat) ||
			(StoneMask && GreatFairyMask && BunnyHood && GiantsMask) || (StoneMask && GreatFairyMask && DonGerosMask && MaskOfScents) || (StoneMask && GreatFairyMask && DonGerosMask && RomanisMask) || 
			(StoneMask && GreatFairyMask && DonGerosMask && CircusLeadersMask) || (StoneMask && GreatFairyMask && DonGerosMask && KafeisMask) || (StoneMask && GreatFairyMask && DonGerosMask && CouplesMask) ||
			(StoneMask && GreatFairyMask && DonGerosMask && MaskOfTruth) || (StoneMask && GreatFairyMask && DonGerosMask && GibdosMask) || (StoneMask && GreatFairyMask && DonGerosMask && GarosMask) || 
			(StoneMask && GreatFairyMask && DonGerosMask && CaptainsHat) || (StoneMask && GreatFairyMask && DonGerosMask && GiantsMask) || (StoneMask && GreatFairyMask && MaskOfScents && RomanisMask) ||
			(StoneMask && GreatFairyMask && MaskOfScents && CircusLeadersMask) || (StoneMask && GreatFairyMask && MaskOfScents && KafeisMask) || (StoneMask && GreatFairyMask && MaskOfScents && CouplesMask) ||
			(StoneMask && GreatFairyMask && MaskOfScents && MaskOfTruth) || (StoneMask && GreatFairyMask && MaskOfScents && GibdosMask) || (StoneMask && GreatFairyMask && MaskOfScents && GarosMask) || 
			(StoneMask && GreatFairyMask && MaskOfScents && CaptainsHat) || (StoneMask && GreatFairyMask && MaskOfScents && GiantsMask) || (StoneMask && GreatFairyMask && RomanisMask && CircusLeadersMask) ||
			(StoneMask && GreatFairyMask && RomanisMask && KafeisMask) || (StoneMask && GreatFairyMask && RomanisMask && CouplesMask) || (StoneMask && GreatFairyMask && RomanisMask && MaskOfTruth) || 
			(StoneMask && GreatFairyMask && RomanisMask && GibdosMask) || (StoneMask && GreatFairyMask && RomanisMask && GarosMask) || (StoneMask && GreatFairyMask && RomanisMask && CaptainsHat) || 
			(StoneMask && GreatFairyMask && RomanisMask && GiantsMask) || (StoneMask && GreatFairyMask && CircusLeadersMask && KafeisMask) || (StoneMask && GreatFairyMask && CircusLeadersMask && CouplesMask) ||
			(StoneMask && GreatFairyMask && CircusLeadersMask && MaskOfTruth) || (StoneMask && GreatFairyMask && CircusLeadersMask && GibdosMask) || (StoneMask && GreatFairyMask && CircusLeadersMask && GarosMask) ||
			(StoneMask && GreatFairyMask && CircusLeadersMask && CaptainsHat) || (StoneMask && GreatFairyMask && CircusLeadersMask && GiantsMask) || (StoneMask && GreatFairyMask && KafeisMask && CouplesMask) || 
			(StoneMask && GreatFairyMask && KafeisMask && MaskOfTruth) || (StoneMask && GreatFairyMask && KafeisMask && GibdosMask) || (StoneMask && GreatFairyMask && KafeisMask && GarosMask) ||
			(StoneMask && GreatFairyMask && KafeisMask && CaptainsHat) || (StoneMask && GreatFairyMask && KafeisMask && GiantsMask) || (StoneMask && GreatFairyMask && CouplesMask && MaskOfTruth) ||
			(StoneMask && GreatFairyMask && CouplesMask && GibdosMask) || (StoneMask && GreatFairyMask && CouplesMask && GarosMask) || (StoneMask && GreatFairyMask && CouplesMask && CaptainsHat) || 
			(StoneMask && GreatFairyMask && CouplesMask && GiantsMask) || (StoneMask && GreatFairyMask && MaskOfTruth && GibdosMask) || (StoneMask && GreatFairyMask && MaskOfTruth && GarosMask) || 
			(StoneMask && GreatFairyMask && MaskOfTruth && CaptainsHat) || (StoneMask && GreatFairyMask && MaskOfTruth && GiantsMask) || (StoneMask && GreatFairyMask && GibdosMask && GarosMask) || 
			(StoneMask && GreatFairyMask && GibdosMask && CaptainsHat) || (StoneMask && GreatFairyMask && GibdosMask && GiantsMask) || (StoneMask && GreatFairyMask && GarosMask && CaptainsHat) || 
			(StoneMask && GreatFairyMask && GarosMask && GiantsMask) || (StoneMask && GreatFairyMask && CaptainsHat && GiantsMask) || (StoneMask && KeatonMask && BremenMask && BunnyHood) || 
			(StoneMask && KeatonMask && BremenMask && DonGerosMask) || (StoneMask && KeatonMask && BremenMask && MaskOfScents) || (StoneMask && KeatonMask && BremenMask && RomanisMask) ||
			(StoneMask && KeatonMask && BremenMask && CircusLeadersMask) || (StoneMask && KeatonMask && BremenMask && KafeisMask) || (StoneMask && KeatonMask && BremenMask && CouplesMask) ||
			(StoneMask && KeatonMask && BremenMask && MaskOfTruth) || (StoneMask && KeatonMask && BremenMask && GibdosMask) || (StoneMask && KeatonMask && BremenMask && GarosMask) ||
			(StoneMask && KeatonMask && BremenMask && CaptainsHat) || (StoneMask && KeatonMask && BremenMask && GiantsMask) || (StoneMask && KeatonMask && BunnyHood && DonGerosMask) ||
			(StoneMask && KeatonMask && BunnyHood && MaskOfScents) || (StoneMask && KeatonMask && BunnyHood && RomanisMask) || (StoneMask && KeatonMask && BunnyHood && CircusLeadersMask) ||
			(StoneMask && KeatonMask && BunnyHood && KafeisMask) || (StoneMask && KeatonMask && BunnyHood && CouplesMask) || (StoneMask && KeatonMask && BunnyHood && MaskOfTruth) || 
			(StoneMask && KeatonMask && BunnyHood && GibdosMask) || (StoneMask && KeatonMask && BunnyHood && GarosMask) || (StoneMask && KeatonMask && BunnyHood && CaptainsHat) || 
			(StoneMask && KeatonMask && BunnyHood && GiantsMask) || (StoneMask && KeatonMask && DonGerosMask && MaskOfScents) || (StoneMask && KeatonMask && DonGerosMask && RomanisMask) || 
			(StoneMask && KeatonMask && DonGerosMask && CircusLeadersMask) || (StoneMask && KeatonMask && DonGerosMask && KafeisMask) || (StoneMask && KeatonMask && DonGerosMask && CouplesMask) || 
			(StoneMask && KeatonMask && DonGerosMask && MaskOfTruth) || (StoneMask && KeatonMask && DonGerosMask && GibdosMask) || (StoneMask && KeatonMask && DonGerosMask && GarosMask) ||
			(StoneMask && KeatonMask && DonGerosMask && CaptainsHat) || (StoneMask && KeatonMask && DonGerosMask && GiantsMask) || (StoneMask && KeatonMask && MaskOfScents && RomanisMask) || 
			(StoneMask && KeatonMask && MaskOfScents && CircusLeadersMask) || (StoneMask && KeatonMask && MaskOfScents && KafeisMask) || (StoneMask && KeatonMask && MaskOfScents && CouplesMask) ||
			(StoneMask && KeatonMask && MaskOfScents && MaskOfTruth) || (StoneMask && KeatonMask && MaskOfScents && GibdosMask) || (StoneMask && KeatonMask && MaskOfScents && GarosMask) ||
			(StoneMask && KeatonMask && MaskOfScents && CaptainsHat) || (StoneMask && KeatonMask && MaskOfScents && GiantsMask) || (StoneMask && KeatonMask && RomanisMask && CircusLeadersMask) || 
			(StoneMask && KeatonMask && RomanisMask && KafeisMask) || (StoneMask && KeatonMask && RomanisMask && CouplesMask) || (StoneMask && KeatonMask && RomanisMask && MaskOfTruth) || 
			(StoneMask && KeatonMask && RomanisMask && GibdosMask) || (StoneMask && KeatonMask && RomanisMask && GarosMask) || (StoneMask && KeatonMask && RomanisMask && CaptainsHat) || 
			(StoneMask && KeatonMask && RomanisMask && GiantsMask) || (StoneMask && KeatonMask && CircusLeadersMask && KafeisMask) || (StoneMask && KeatonMask && CircusLeadersMask && CouplesMask) ||
			(StoneMask && KeatonMask && CircusLeadersMask && MaskOfTruth) || (StoneMask && KeatonMask && CircusLeadersMask && GibdosMask) || (StoneMask && KeatonMask && CircusLeadersMask && GarosMask) ||
			(StoneMask && KeatonMask && CircusLeadersMask && CaptainsHat) || (StoneMask && KeatonMask && CircusLeadersMask && GiantsMask) || (StoneMask && KeatonMask && KafeisMask && CouplesMask) || 
			(StoneMask && KeatonMask && KafeisMask && MaskOfTruth) || (StoneMask && KeatonMask && KafeisMask && GibdosMask) || (StoneMask && KeatonMask && KafeisMask && GarosMask) || 
			(StoneMask && KeatonMask && KafeisMask && CaptainsHat) || (StoneMask && KeatonMask && KafeisMask && GiantsMask) || (StoneMask && KeatonMask && CouplesMask && MaskOfTruth) ||
			(StoneMask && KeatonMask && CouplesMask && GibdosMask) || (StoneMask && KeatonMask && CouplesMask && GarosMask) || (StoneMask && KeatonMask && CouplesMask && CaptainsHat) || 
			(StoneMask && KeatonMask && CouplesMask && GiantsMask) || (StoneMask && KeatonMask && MaskOfTruth && GibdosMask) || (StoneMask && KeatonMask && MaskOfTruth && GarosMask) || 
			(StoneMask && KeatonMask && MaskOfTruth && CaptainsHat) || (StoneMask && KeatonMask && MaskOfTruth && GiantsMask) || (StoneMask && KeatonMask && GibdosMask && GarosMask) || 
			(StoneMask && KeatonMask && GibdosMask && CaptainsHat) || (StoneMask && KeatonMask && GibdosMask && GiantsMask) || (StoneMask && KeatonMask && GarosMask && CaptainsHat) || 
			(StoneMask && KeatonMask && GarosMask && GiantsMask) || (StoneMask && KeatonMask && CaptainsHat && GiantsMask) || (StoneMask && BremenMask && BunnyHood && DonGerosMask) || 
			(StoneMask && BremenMask && BunnyHood && MaskOfScents) || (StoneMask && BremenMask && BunnyHood && RomanisMask) || (StoneMask && BremenMask && BunnyHood && CircusLeadersMask) ||
			(StoneMask && BremenMask && BunnyHood && KafeisMask) || (StoneMask && BremenMask && BunnyHood && CouplesMask) || (StoneMask && BremenMask && BunnyHood && MaskOfTruth) ||
			(StoneMask && BremenMask && BunnyHood && GibdosMask) || (StoneMask && BremenMask && BunnyHood && GarosMask) || (StoneMask && BremenMask && BunnyHood && CaptainsHat) || 
			(StoneMask && BremenMask && BunnyHood && GiantsMask) || (StoneMask && BremenMask && DonGerosMask && MaskOfScents) || (StoneMask && BremenMask && DonGerosMask && RomanisMask) || 
			(StoneMask && BremenMask && DonGerosMask && CircusLeadersMask) || (StoneMask && BremenMask && DonGerosMask && KafeisMask) || (StoneMask && BremenMask && DonGerosMask && CouplesMask) || 
			(StoneMask && BremenMask && DonGerosMask && MaskOfTruth) || (StoneMask && BremenMask && DonGerosMask && GibdosMask) || (StoneMask && BremenMask && DonGerosMask && GarosMask) || 
			(StoneMask && BremenMask && DonGerosMask && CaptainsHat) || (StoneMask && BremenMask && DonGerosMask && GiantsMask) || (StoneMask && BremenMask && MaskOfScents && RomanisMask) ||
			(StoneMask && BremenMask && MaskOfScents && CircusLeadersMask) || (StoneMask && BremenMask && MaskOfScents && KafeisMask) || (StoneMask && BremenMask && MaskOfScents && CouplesMask) ||
			(StoneMask && BremenMask && MaskOfScents && MaskOfTruth) || (StoneMask && BremenMask && MaskOfScents && GibdosMask) || (StoneMask && BremenMask && MaskOfScents && GarosMask) || 
			(StoneMask && BremenMask && MaskOfScents && CaptainsHat) || (StoneMask && BremenMask && MaskOfScents && GiantsMask) || (StoneMask && BremenMask && RomanisMask && CircusLeadersMask) ||
			(StoneMask && BremenMask && RomanisMask && KafeisMask) || (StoneMask && BremenMask && RomanisMask && CouplesMask) || (StoneMask && BremenMask && RomanisMask && MaskOfTruth) ||
			(StoneMask && BremenMask && RomanisMask && GibdosMask) || (StoneMask && BremenMask && RomanisMask && GarosMask) || (StoneMask && BremenMask && RomanisMask && CaptainsHat) ||
			(StoneMask && BremenMask && RomanisMask && GiantsMask) || (StoneMask && BremenMask && CircusLeadersMask && KafeisMask) || (StoneMask && BremenMask && CircusLeadersMask && CouplesMask) ||
			(StoneMask && BremenMask && CircusLeadersMask && MaskOfTruth) || (StoneMask && BremenMask && CircusLeadersMask && GibdosMask) || (StoneMask && BremenMask && CircusLeadersMask && GarosMask) ||
			(StoneMask && BremenMask && CircusLeadersMask && CaptainsHat) || (StoneMask && BremenMask && CircusLeadersMask && GiantsMask) || (StoneMask && BremenMask && KafeisMask && CouplesMask) ||
			(StoneMask && BremenMask && KafeisMask && MaskOfTruth) || (StoneMask && BremenMask && KafeisMask && GibdosMask) || (StoneMask && BremenMask && KafeisMask && GarosMask) || 
			(StoneMask && BremenMask && KafeisMask && CaptainsHat) || (StoneMask && BremenMask && KafeisMask && GiantsMask) || (StoneMask && BremenMask && CouplesMask && MaskOfTruth) || 
			(StoneMask && BremenMask && CouplesMask && GibdosMask) || (StoneMask && BremenMask && CouplesMask && GarosMask) || (StoneMask && BremenMask && CouplesMask && CaptainsHat) ||
			(StoneMask && BremenMask && CouplesMask && GiantsMask) || (StoneMask && BremenMask && MaskOfTruth && GibdosMask) || (StoneMask && BremenMask && MaskOfTruth && GarosMask) || 
			(StoneMask && BremenMask && MaskOfTruth && CaptainsHat) || (StoneMask && BremenMask && MaskOfTruth && GiantsMask) || (StoneMask && BremenMask && GibdosMask && GarosMask) ||
			(StoneMask && BremenMask && GibdosMask && CaptainsHat) || (StoneMask && BremenMask && GibdosMask && GiantsMask) || (StoneMask && BremenMask && GarosMask && CaptainsHat) || 
			(StoneMask && BremenMask && GarosMask && GiantsMask) || (StoneMask && BremenMask && CaptainsHat && GiantsMask) || (StoneMask && BunnyHood && DonGerosMask && MaskOfScents) ||
			(StoneMask && BunnyHood && DonGerosMask && RomanisMask) || (StoneMask && BunnyHood && DonGerosMask && CircusLeadersMask) || (StoneMask && BunnyHood && DonGerosMask && KafeisMask) ||
			(StoneMask && BunnyHood && DonGerosMask && CouplesMask) || (StoneMask && BunnyHood && DonGerosMask && MaskOfTruth) || (StoneMask && BunnyHood && DonGerosMask && GibdosMask) || 
			(StoneMask && BunnyHood && DonGerosMask && GarosMask) || (StoneMask && BunnyHood && DonGerosMask && CaptainsHat) || (StoneMask && BunnyHood && DonGerosMask && GiantsMask) ||
			(StoneMask && BunnyHood && MaskOfScents && RomanisMask) || (StoneMask && BunnyHood && MaskOfScents && CircusLeadersMask) || (StoneMask && BunnyHood && MaskOfScents && KafeisMask) || 
			(StoneMask && BunnyHood && MaskOfScents && CouplesMask) || (StoneMask && BunnyHood && MaskOfScents && MaskOfTruth) || (StoneMask && BunnyHood && MaskOfScents && GibdosMask) || 
			(StoneMask && BunnyHood && MaskOfScents && GarosMask) || (StoneMask && BunnyHood && MaskOfScents && CaptainsHat) || (StoneMask && BunnyHood && MaskOfScents && GiantsMask) || 
			(StoneMask && BunnyHood && RomanisMask && CircusLeadersMask) || (StoneMask && BunnyHood && RomanisMask && KafeisMask) || (StoneMask && BunnyHood && RomanisMask && CouplesMask) ||
			(StoneMask && BunnyHood && RomanisMask && MaskOfTruth) || (StoneMask && BunnyHood && RomanisMask && GibdosMask) || (StoneMask && BunnyHood && RomanisMask && GarosMask) || 
			(StoneMask && BunnyHood && RomanisMask && CaptainsHat) || (StoneMask && BunnyHood && RomanisMask && GiantsMask) || (StoneMask && BunnyHood && CircusLeadersMask && KafeisMask) || 
			(StoneMask && BunnyHood && CircusLeadersMask && CouplesMask) || (StoneMask && BunnyHood && CircusLeadersMask && MaskOfTruth) || (StoneMask && BunnyHood && CircusLeadersMask && GibdosMask) ||
			(StoneMask && BunnyHood && CircusLeadersMask && GarosMask) || (StoneMask && BunnyHood && CircusLeadersMask && CaptainsHat) || (StoneMask && BunnyHood && CircusLeadersMask && GiantsMask) ||
			(StoneMask && BunnyHood && KafeisMask && CouplesMask) || (StoneMask && BunnyHood && KafeisMask && MaskOfTruth) || (StoneMask && BunnyHood && KafeisMask && GibdosMask) ||
			(StoneMask && BunnyHood && KafeisMask && GarosMask) || (StoneMask && BunnyHood && KafeisMask && CaptainsHat) || (StoneMask && BunnyHood && KafeisMask && GiantsMask) || 
			(StoneMask && BunnyHood && CouplesMask && MaskOfTruth) || (StoneMask && BunnyHood && CouplesMask && GibdosMask) || (StoneMask && BunnyHood && CouplesMask && GarosMask) ||
			(StoneMask && BunnyHood && CouplesMask && CaptainsHat) || (StoneMask && BunnyHood && CouplesMask && GiantsMask) || (StoneMask && BunnyHood && MaskOfTruth && GibdosMask) ||
			(StoneMask && BunnyHood && MaskOfTruth && GarosMask) || (StoneMask && BunnyHood && MaskOfTruth && CaptainsHat) || (StoneMask && BunnyHood && MaskOfTruth && GiantsMask) ||
			(StoneMask && BunnyHood && GibdosMask && GarosMask) || (StoneMask && BunnyHood && GibdosMask && CaptainsHat) || (StoneMask && BunnyHood && GibdosMask && GiantsMask) ||
			(StoneMask && BunnyHood && GarosMask && CaptainsHat) || (StoneMask && BunnyHood && GarosMask && GiantsMask) || (StoneMask && BunnyHood && CaptainsHat && GiantsMask) ||
			(StoneMask && DonGerosMask && MaskOfScents && RomanisMask) || (StoneMask && DonGerosMask && MaskOfScents && CircusLeadersMask) || (StoneMask && DonGerosMask && MaskOfScents && KafeisMask) ||
			(StoneMask && DonGerosMask && MaskOfScents && CouplesMask) || (StoneMask && DonGerosMask && MaskOfScents && MaskOfTruth) || (StoneMask && DonGerosMask && MaskOfScents && GibdosMask) ||
			(StoneMask && DonGerosMask && MaskOfScents && GarosMask) || (StoneMask && DonGerosMask && MaskOfScents && CaptainsHat) || (StoneMask && DonGerosMask && MaskOfScents && GiantsMask) || 
			(StoneMask && DonGerosMask && RomanisMask && CircusLeadersMask) || (StoneMask && DonGerosMask && RomanisMask && KafeisMask) || (StoneMask && DonGerosMask && RomanisMask && CouplesMask) || 
			(StoneMask && DonGerosMask && RomanisMask && MaskOfTruth) || (StoneMask && DonGerosMask && RomanisMask && GibdosMask) || (StoneMask && DonGerosMask && RomanisMask && GarosMask) || 
			(StoneMask && DonGerosMask && RomanisMask && CaptainsHat) || (StoneMask && DonGerosMask && RomanisMask && GiantsMask) || (StoneMask && DonGerosMask && CircusLeadersMask && KafeisMask) ||
			(StoneMask && DonGerosMask && CircusLeadersMask && CouplesMask) || (StoneMask && DonGerosMask && CircusLeadersMask && MaskOfTruth) || (StoneMask && DonGerosMask && CircusLeadersMask && GibdosMask) ||
			(StoneMask && DonGerosMask && CircusLeadersMask && GarosMask) || (StoneMask && DonGerosMask && CircusLeadersMask && CaptainsHat) || (StoneMask && DonGerosMask && CircusLeadersMask && GiantsMask) ||
			(StoneMask && DonGerosMask && KafeisMask && CouplesMask) || (StoneMask && DonGerosMask && KafeisMask && MaskOfTruth) || (StoneMask && DonGerosMask && KafeisMask && GibdosMask) || 
			(StoneMask && DonGerosMask && KafeisMask && GarosMask) || (StoneMask && DonGerosMask && KafeisMask && CaptainsHat) || (StoneMask && DonGerosMask && KafeisMask && GiantsMask) ||
			(StoneMask && DonGerosMask && CouplesMask && MaskOfTruth) || (StoneMask && DonGerosMask && CouplesMask && GibdosMask) || (StoneMask && DonGerosMask && CouplesMask && GarosMask) ||
			(StoneMask && DonGerosMask && CouplesMask && CaptainsHat) || (StoneMask && DonGerosMask && CouplesMask && GiantsMask) || (StoneMask && DonGerosMask && MaskOfTruth && GibdosMask) || 
			(StoneMask && DonGerosMask && MaskOfTruth && GarosMask) || (StoneMask && DonGerosMask && MaskOfTruth && CaptainsHat) || (StoneMask && DonGerosMask && MaskOfTruth && GiantsMask) || 
			(StoneMask && DonGerosMask && GibdosMask && GarosMask) || (StoneMask && DonGerosMask && GibdosMask && CaptainsHat) || (StoneMask && DonGerosMask && GibdosMask && GiantsMask) ||
			(StoneMask && DonGerosMask && GarosMask && CaptainsHat) || (StoneMask && DonGerosMask && GarosMask && GiantsMask) || (StoneMask && DonGerosMask && CaptainsHat && GiantsMask) ||
			(StoneMask && MaskOfScents && RomanisMask && CircusLeadersMask) || (StoneMask && MaskOfScents && RomanisMask && KafeisMask) || (StoneMask && MaskOfScents && RomanisMask && CouplesMask) || 
			(StoneMask && MaskOfScents && RomanisMask && MaskOfTruth) || (StoneMask && MaskOfScents && RomanisMask && GibdosMask) || (StoneMask && MaskOfScents && RomanisMask && GarosMask) ||
			(StoneMask && MaskOfScents && RomanisMask && CaptainsHat) || (StoneMask && MaskOfScents && RomanisMask && GiantsMask) || (StoneMask && MaskOfScents && CircusLeadersMask && KafeisMask) || 
			(StoneMask && MaskOfScents && CircusLeadersMask && CouplesMask) || (StoneMask && MaskOfScents && CircusLeadersMask && MaskOfTruth) || (StoneMask && MaskOfScents && CircusLeadersMask && GibdosMask) ||
			(StoneMask && MaskOfScents && CircusLeadersMask && GarosMask) || (StoneMask && MaskOfScents && CircusLeadersMask && CaptainsHat) || (StoneMask && MaskOfScents && CircusLeadersMask && GiantsMask) || 
			(StoneMask && MaskOfScents && KafeisMask && CouplesMask) || (StoneMask && MaskOfScents && KafeisMask && MaskOfTruth) || (StoneMask && MaskOfScents && KafeisMask && GibdosMask) || 
			(StoneMask && MaskOfScents && KafeisMask && GarosMask) || (StoneMask && MaskOfScents && KafeisMask && CaptainsHat) || (StoneMask && MaskOfScents && KafeisMask && GiantsMask) ||
			(StoneMask && MaskOfScents && CouplesMask && MaskOfTruth) || (StoneMask && MaskOfScents && CouplesMask && GibdosMask) || (StoneMask && MaskOfScents && CouplesMask && GarosMask) || 
			(StoneMask && MaskOfScents && CouplesMask && CaptainsHat) || (StoneMask && MaskOfScents && CouplesMask && GiantsMask) || (StoneMask && MaskOfScents && MaskOfTruth && GibdosMask) ||
			(StoneMask && MaskOfScents && MaskOfTruth && GarosMask) || (StoneMask && MaskOfScents && MaskOfTruth && CaptainsHat) || (StoneMask && MaskOfScents && MaskOfTruth && GiantsMask) ||
			(StoneMask && MaskOfScents && GibdosMask && GarosMask) || (StoneMask && MaskOfScents && GibdosMask && CaptainsHat) || (StoneMask && MaskOfScents && GibdosMask && GiantsMask) ||
			(StoneMask && MaskOfScents && GarosMask && CaptainsHat) || (StoneMask && MaskOfScents && GarosMask && GiantsMask) || (StoneMask && MaskOfScents && CaptainsHat && GiantsMask) ||
			(StoneMask && RomanisMask && CircusLeadersMask && KafeisMask) || (StoneMask && RomanisMask && CircusLeadersMask && CouplesMask) || (StoneMask && RomanisMask && CircusLeadersMask && MaskOfTruth) || 
			(StoneMask && RomanisMask && CircusLeadersMask && GibdosMask) || (StoneMask && RomanisMask && CircusLeadersMask && GarosMask) || (StoneMask && RomanisMask && CircusLeadersMask && CaptainsHat) || 
			(StoneMask && RomanisMask && CircusLeadersMask && GiantsMask) || (StoneMask && RomanisMask && KafeisMask && CouplesMask) || (StoneMask && RomanisMask && KafeisMask && MaskOfTruth) || 
			(StoneMask && RomanisMask && KafeisMask && GibdosMask) || (StoneMask && RomanisMask && KafeisMask && GarosMask) || (StoneMask && RomanisMask && KafeisMask && CaptainsHat) ||
			(StoneMask && RomanisMask && KafeisMask && GiantsMask) || (StoneMask && RomanisMask && CouplesMask && MaskOfTruth) || (StoneMask && RomanisMask && CouplesMask && GibdosMask) || 
			(StoneMask && RomanisMask && CouplesMask && GarosMask) || (StoneMask && RomanisMask && CouplesMask && CaptainsHat) || (StoneMask && RomanisMask && CouplesMask && GiantsMask) ||
			(StoneMask && RomanisMask && MaskOfTruth && GibdosMask) || (StoneMask && RomanisMask && MaskOfTruth && GarosMask) || (StoneMask && RomanisMask && MaskOfTruth && CaptainsHat) ||
			(StoneMask && RomanisMask && MaskOfTruth && GiantsMask) || (StoneMask && RomanisMask && GibdosMask && GarosMask) || (StoneMask && RomanisMask && GibdosMask && CaptainsHat) || 
			(StoneMask && RomanisMask && GibdosMask && GiantsMask) || (StoneMask && RomanisMask && GarosMask && CaptainsHat) || (StoneMask && RomanisMask && GarosMask && GiantsMask) ||
			(StoneMask && RomanisMask && CaptainsHat && GiantsMask) || (StoneMask && CircusLeadersMask && KafeisMask && CouplesMask) || (StoneMask && CircusLeadersMask && KafeisMask && MaskOfTruth) ||
			(StoneMask && CircusLeadersMask && KafeisMask && GibdosMask) || (StoneMask && CircusLeadersMask && KafeisMask && GarosMask) || (StoneMask && CircusLeadersMask && KafeisMask && CaptainsHat) || 
			(StoneMask && CircusLeadersMask && KafeisMask && GiantsMask) || (StoneMask && CircusLeadersMask && CouplesMask && MaskOfTruth) || (StoneMask && CircusLeadersMask && CouplesMask && GibdosMask) || 
			(StoneMask && CircusLeadersMask && CouplesMask && GarosMask) || (StoneMask && CircusLeadersMask && CouplesMask && CaptainsHat) || (StoneMask && CircusLeadersMask && CouplesMask && GiantsMask) || 
			(StoneMask && CircusLeadersMask && MaskOfTruth && GibdosMask) || (StoneMask && CircusLeadersMask && MaskOfTruth && GarosMask) || (StoneMask && CircusLeadersMask && MaskOfTruth && CaptainsHat) ||
			(StoneMask && CircusLeadersMask && MaskOfTruth && GiantsMask) || (StoneMask && CircusLeadersMask && GibdosMask && GarosMask) || (StoneMask && CircusLeadersMask && GibdosMask && CaptainsHat) || 
			(StoneMask && CircusLeadersMask && GibdosMask && GiantsMask) || (StoneMask && CircusLeadersMask && GarosMask && CaptainsHat) || (StoneMask && CircusLeadersMask && GarosMask && GiantsMask) ||
			(StoneMask && CircusLeadersMask && CaptainsHat && GiantsMask) || (StoneMask && KafeisMask && CouplesMask && MaskOfTruth) || (StoneMask && KafeisMask && CouplesMask && GibdosMask) ||
			(StoneMask && KafeisMask && CouplesMask && GarosMask) || (StoneMask && KafeisMask && CouplesMask && CaptainsHat) || (StoneMask && KafeisMask && CouplesMask && GiantsMask) ||
			(StoneMask && KafeisMask && MaskOfTruth && GibdosMask) || (StoneMask && KafeisMask && MaskOfTruth && GarosMask) || (StoneMask && KafeisMask && MaskOfTruth && CaptainsHat) ||
			(StoneMask && KafeisMask && MaskOfTruth && GiantsMask) || (StoneMask && KafeisMask && GibdosMask && GarosMask) || (StoneMask && KafeisMask && GibdosMask && CaptainsHat) || 
			(StoneMask && KafeisMask && GibdosMask && GiantsMask) || (StoneMask && KafeisMask && GarosMask && CaptainsHat) || (StoneMask && KafeisMask && GarosMask && GiantsMask) || 
			(StoneMask && KafeisMask && CaptainsHat && GiantsMask) || (StoneMask && CouplesMask && MaskOfTruth && GibdosMask) || (StoneMask && CouplesMask && MaskOfTruth && GarosMask) || 
			(StoneMask && CouplesMask && MaskOfTruth && CaptainsHat) || (StoneMask && CouplesMask && MaskOfTruth && GiantsMask) || (StoneMask && CouplesMask && GibdosMask && GarosMask) ||
			(StoneMask && CouplesMask && GibdosMask && CaptainsHat) || (StoneMask && CouplesMask && GibdosMask && GiantsMask) || (StoneMask && CouplesMask && GarosMask && CaptainsHat) || 
			(StoneMask && CouplesMask && GarosMask && GiantsMask) || (StoneMask && CouplesMask && CaptainsHat && GiantsMask) || (StoneMask && MaskOfTruth && GibdosMask && GarosMask) || 
			(StoneMask && MaskOfTruth && GibdosMask && CaptainsHat) || (StoneMask && MaskOfTruth && GibdosMask && GiantsMask) || (StoneMask && MaskOfTruth && GarosMask && CaptainsHat) || 
			(StoneMask && MaskOfTruth && GarosMask && GiantsMask) || (StoneMask && MaskOfTruth && CaptainsHat && GiantsMask) || (StoneMask && GibdosMask && GarosMask && CaptainsHat) ||
			(StoneMask && GibdosMask && GarosMask && GiantsMask) || (StoneMask && GibdosMask && CaptainsHat && GiantsMask) || (StoneMask && GarosMask && CaptainsHat && GiantsMask) || 
			(GreatFairyMask && KeatonMask && BremenMask && BunnyHood) || (GreatFairyMask && KeatonMask && BremenMask && DonGerosMask) || (GreatFairyMask && KeatonMask && BremenMask && MaskOfScents) ||
			(GreatFairyMask && KeatonMask && BremenMask && RomanisMask) || (GreatFairyMask && KeatonMask && BremenMask && CircusLeadersMask) || (GreatFairyMask && KeatonMask && BremenMask && KafeisMask) ||
			(GreatFairyMask && KeatonMask && BremenMask && CouplesMask) || (GreatFairyMask && KeatonMask && BremenMask && MaskOfTruth) || (GreatFairyMask && KeatonMask && BremenMask && GibdosMask) ||
			(GreatFairyMask && KeatonMask && BremenMask && GarosMask) || (GreatFairyMask && KeatonMask && BremenMask && CaptainsHat) || (GreatFairyMask && KeatonMask && BremenMask && GiantsMask) ||
			(GreatFairyMask && KeatonMask && BunnyHood && DonGerosMask) || (GreatFairyMask && KeatonMask && BunnyHood && MaskOfScents) || (GreatFairyMask && KeatonMask && BunnyHood && RomanisMask) ||
			(GreatFairyMask && KeatonMask && BunnyHood && CircusLeadersMask) || (GreatFairyMask && KeatonMask && BunnyHood && KafeisMask) || (GreatFairyMask && KeatonMask && BunnyHood && CouplesMask) ||
			(GreatFairyMask && KeatonMask && BunnyHood && MaskOfTruth) || (GreatFairyMask && KeatonMask && BunnyHood && GibdosMask) || (GreatFairyMask && KeatonMask && BunnyHood && GarosMask) ||
			(GreatFairyMask && KeatonMask && BunnyHood && CaptainsHat) || (GreatFairyMask && KeatonMask && BunnyHood && GiantsMask) || (GreatFairyMask && KeatonMask && DonGerosMask && MaskOfScents) || 
			(GreatFairyMask && KeatonMask && DonGerosMask && RomanisMask) || (GreatFairyMask && KeatonMask && DonGerosMask && CircusLeadersMask) || (GreatFairyMask && KeatonMask && DonGerosMask && KafeisMask) ||
			(GreatFairyMask && KeatonMask && DonGerosMask && CouplesMask) || (GreatFairyMask && KeatonMask && DonGerosMask && MaskOfTruth) || (GreatFairyMask && KeatonMask && DonGerosMask && GibdosMask) ||
			(GreatFairyMask && KeatonMask && DonGerosMask && GarosMask) || (GreatFairyMask && KeatonMask && DonGerosMask && CaptainsHat) || (GreatFairyMask && KeatonMask && DonGerosMask && GiantsMask) ||
			(GreatFairyMask && KeatonMask && MaskOfScents && RomanisMask) || (GreatFairyMask && KeatonMask && MaskOfScents && CircusLeadersMask) || (GreatFairyMask && KeatonMask && MaskOfScents && KafeisMask) ||
			(GreatFairyMask && KeatonMask && MaskOfScents && CouplesMask) || (GreatFairyMask && KeatonMask && MaskOfScents && MaskOfTruth) || (GreatFairyMask && KeatonMask && MaskOfScents && GibdosMask) ||
			(GreatFairyMask && KeatonMask && MaskOfScents && GarosMask) || (GreatFairyMask && KeatonMask && MaskOfScents && CaptainsHat) || (GreatFairyMask && KeatonMask && MaskOfScents && GiantsMask) || 
			(GreatFairyMask && KeatonMask && RomanisMask && CircusLeadersMask) || (GreatFairyMask && KeatonMask && RomanisMask && KafeisMask) || (GreatFairyMask && KeatonMask && RomanisMask && CouplesMask) ||
			(GreatFairyMask && KeatonMask && RomanisMask && MaskOfTruth) || (GreatFairyMask && KeatonMask && RomanisMask && GibdosMask) || (GreatFairyMask && KeatonMask && RomanisMask && GarosMask) || 
			(GreatFairyMask && KeatonMask && RomanisMask && CaptainsHat) || (GreatFairyMask && KeatonMask && RomanisMask && GiantsMask) || (GreatFairyMask && KeatonMask && CircusLeadersMask && KafeisMask) || 
			(GreatFairyMask && KeatonMask && CircusLeadersMask && CouplesMask) || (GreatFairyMask && KeatonMask && CircusLeadersMask && MaskOfTruth) || (GreatFairyMask && KeatonMask && CircusLeadersMask && GibdosMask) ||
			(GreatFairyMask && KeatonMask && CircusLeadersMask && GarosMask) || (GreatFairyMask && KeatonMask && CircusLeadersMask && CaptainsHat) || (GreatFairyMask && KeatonMask && CircusLeadersMask && GiantsMask) || 
			(GreatFairyMask && KeatonMask && KafeisMask && CouplesMask) || (GreatFairyMask && KeatonMask && KafeisMask && MaskOfTruth) || (GreatFairyMask && KeatonMask && KafeisMask && GibdosMask) || 
			(GreatFairyMask && KeatonMask && KafeisMask && GarosMask) || (GreatFairyMask && KeatonMask && KafeisMask && CaptainsHat) || (GreatFairyMask && KeatonMask && KafeisMask && GiantsMask) ||
			(GreatFairyMask && KeatonMask && CouplesMask && MaskOfTruth) || (GreatFairyMask && KeatonMask && CouplesMask && GibdosMask) || (GreatFairyMask && KeatonMask && CouplesMask && GarosMask) ||
			(GreatFairyMask && KeatonMask && CouplesMask && CaptainsHat) || (GreatFairyMask && KeatonMask && CouplesMask && GiantsMask) || (GreatFairyMask && KeatonMask && MaskOfTruth && GibdosMask) || 
			(GreatFairyMask && KeatonMask && MaskOfTruth && GarosMask) || (GreatFairyMask && KeatonMask && MaskOfTruth && CaptainsHat) || (GreatFairyMask && KeatonMask && MaskOfTruth && GiantsMask) || 
			(GreatFairyMask && KeatonMask && GibdosMask && GarosMask) || (GreatFairyMask && KeatonMask && GibdosMask && CaptainsHat) || (GreatFairyMask && KeatonMask && GibdosMask && GiantsMask) ||
			(GreatFairyMask && KeatonMask && GarosMask && CaptainsHat) || (GreatFairyMask && KeatonMask && GarosMask && GiantsMask) || (GreatFairyMask && KeatonMask && CaptainsHat && GiantsMask) ||
			(GreatFairyMask && BremenMask && BunnyHood && DonGerosMask) || (GreatFairyMask && BremenMask && BunnyHood && MaskOfScents) || (GreatFairyMask && BremenMask && BunnyHood && RomanisMask) ||
			(GreatFairyMask && BremenMask && BunnyHood && CircusLeadersMask) || (GreatFairyMask && BremenMask && BunnyHood && KafeisMask) || (GreatFairyMask && BremenMask && BunnyHood && CouplesMask) ||
			(GreatFairyMask && BremenMask && BunnyHood && MaskOfTruth) || (GreatFairyMask && BremenMask && BunnyHood && GibdosMask) || (GreatFairyMask && BremenMask && BunnyHood && GarosMask) || 
			(GreatFairyMask && BremenMask && BunnyHood && CaptainsHat) || (GreatFairyMask && BremenMask && BunnyHood && GiantsMask) || (GreatFairyMask && BremenMask && DonGerosMask && MaskOfScents) ||
			(GreatFairyMask && BremenMask && DonGerosMask && RomanisMask) || (GreatFairyMask && BremenMask && DonGerosMask && CircusLeadersMask) || (GreatFairyMask && BremenMask && DonGerosMask && KafeisMask) ||
			(GreatFairyMask && BremenMask && DonGerosMask && CouplesMask) || (GreatFairyMask && BremenMask && DonGerosMask && MaskOfTruth) || (GreatFairyMask && BremenMask && DonGerosMask && GibdosMask) || 
			(GreatFairyMask && BremenMask && DonGerosMask && GarosMask) || (GreatFairyMask && BremenMask && DonGerosMask && CaptainsHat) || (GreatFairyMask && BremenMask && DonGerosMask && GiantsMask) ||
			(GreatFairyMask && BremenMask && MaskOfScents && RomanisMask) || (GreatFairyMask && BremenMask && MaskOfScents && CircusLeadersMask) || (GreatFairyMask && BremenMask && MaskOfScents && KafeisMask) || 
			(GreatFairyMask && BremenMask && MaskOfScents && CouplesMask) || (GreatFairyMask && BremenMask && MaskOfScents && MaskOfTruth) || (GreatFairyMask && BremenMask && MaskOfScents && GibdosMask) ||
			(GreatFairyMask && BremenMask && MaskOfScents && GarosMask) || (GreatFairyMask && BremenMask && MaskOfScents && CaptainsHat) || (GreatFairyMask && BremenMask && MaskOfScents && GiantsMask) || 
			(GreatFairyMask && BremenMask && RomanisMask && CircusLeadersMask) || (GreatFairyMask && BremenMask && RomanisMask && KafeisMask) || (GreatFairyMask && BremenMask && RomanisMask && CouplesMask) ||
			(GreatFairyMask && BremenMask && RomanisMask && MaskOfTruth) || (GreatFairyMask && BremenMask && RomanisMask && GibdosMask) || (GreatFairyMask && BremenMask && RomanisMask && GarosMask) || 
			(GreatFairyMask && BremenMask && RomanisMask && CaptainsHat) || (GreatFairyMask && BremenMask && RomanisMask && GiantsMask) || (GreatFairyMask && BremenMask && CircusLeadersMask && KafeisMask) || 
			(GreatFairyMask && BremenMask && CircusLeadersMask && CouplesMask) || (GreatFairyMask && BremenMask && CircusLeadersMask && MaskOfTruth) || (GreatFairyMask && BremenMask && CircusLeadersMask && GibdosMask) ||
			(GreatFairyMask && BremenMask && CircusLeadersMask && GarosMask) || (GreatFairyMask && BremenMask && CircusLeadersMask && CaptainsHat) || (GreatFairyMask && BremenMask && CircusLeadersMask && GiantsMask) || 
			(GreatFairyMask && BremenMask && KafeisMask && CouplesMask) || (GreatFairyMask && BremenMask && KafeisMask && MaskOfTruth) || (GreatFairyMask && BremenMask && KafeisMask && GibdosMask) || 
			(GreatFairyMask && BremenMask && KafeisMask && GarosMask) || (GreatFairyMask && BremenMask && KafeisMask && CaptainsHat) || (GreatFairyMask && BremenMask && KafeisMask && GiantsMask) ||
			(GreatFairyMask && BremenMask && CouplesMask && MaskOfTruth) || (GreatFairyMask && BremenMask && CouplesMask && GibdosMask) || (GreatFairyMask && BremenMask && CouplesMask && GarosMask) || 
			(GreatFairyMask && BremenMask && CouplesMask && CaptainsHat) || (GreatFairyMask && BremenMask && CouplesMask && GiantsMask) || (GreatFairyMask && BremenMask && MaskOfTruth && GibdosMask) ||
			(GreatFairyMask && BremenMask && MaskOfTruth && GarosMask) || (GreatFairyMask && BremenMask && MaskOfTruth && CaptainsHat) || (GreatFairyMask && BremenMask && MaskOfTruth && GiantsMask) || 
			(GreatFairyMask && BremenMask && GibdosMask && GarosMask) || (GreatFairyMask && BremenMask && GibdosMask && CaptainsHat) || (GreatFairyMask && BremenMask && GibdosMask && GiantsMask) || 
			(GreatFairyMask && BremenMask && GarosMask && CaptainsHat) || (GreatFairyMask && BremenMask && GarosMask && GiantsMask) || (GreatFairyMask && BremenMask && CaptainsHat && GiantsMask) || 
			(GreatFairyMask && BunnyHood && DonGerosMask && MaskOfScents) || (GreatFairyMask && BunnyHood && DonGerosMask && RomanisMask) || (GreatFairyMask && BunnyHood && DonGerosMask && CircusLeadersMask) || 
			(GreatFairyMask && BunnyHood && DonGerosMask && KafeisMask) || (GreatFairyMask && BunnyHood && DonGerosMask && CouplesMask) || (GreatFairyMask && BunnyHood && DonGerosMask && MaskOfTruth) ||
			(GreatFairyMask && BunnyHood && DonGerosMask && GibdosMask) || (GreatFairyMask && BunnyHood && DonGerosMask && GarosMask) || (GreatFairyMask && BunnyHood && DonGerosMask && CaptainsHat) || 
			(GreatFairyMask && BunnyHood && DonGerosMask && GiantsMask) || (GreatFairyMask && BunnyHood && MaskOfScents && RomanisMask) || (GreatFairyMask && BunnyHood && MaskOfScents && CircusLeadersMask) || 
			(GreatFairyMask && BunnyHood && MaskOfScents && KafeisMask) || (GreatFairyMask && BunnyHood && MaskOfScents && CouplesMask) || (GreatFairyMask && BunnyHood && MaskOfScents && MaskOfTruth) || 
			(GreatFairyMask && BunnyHood && MaskOfScents && GibdosMask) || (GreatFairyMask && BunnyHood && MaskOfScents && GarosMask) || (GreatFairyMask && BunnyHood && MaskOfScents && CaptainsHat) ||
			(GreatFairyMask && BunnyHood && MaskOfScents && GiantsMask) || (GreatFairyMask && BunnyHood && RomanisMask && CircusLeadersMask) || (GreatFairyMask && BunnyHood && RomanisMask && KafeisMask) || 
			(GreatFairyMask && BunnyHood && RomanisMask && CouplesMask) || (GreatFairyMask && BunnyHood && RomanisMask && MaskOfTruth) || (GreatFairyMask && BunnyHood && RomanisMask && GibdosMask) ||
			(GreatFairyMask && BunnyHood && RomanisMask && GarosMask) || (GreatFairyMask && BunnyHood && RomanisMask && CaptainsHat) || (GreatFairyMask && BunnyHood && RomanisMask && GiantsMask) || 
			(GreatFairyMask && BunnyHood && CircusLeadersMask && KafeisMask) || (GreatFairyMask && BunnyHood && CircusLeadersMask && CouplesMask) || (GreatFairyMask && BunnyHood && CircusLeadersMask && MaskOfTruth) ||
			(GreatFairyMask && BunnyHood && CircusLeadersMask && GibdosMask) || (GreatFairyMask && BunnyHood && CircusLeadersMask && GarosMask) || (GreatFairyMask && BunnyHood && CircusLeadersMask && CaptainsHat) ||
			(GreatFairyMask && BunnyHood && CircusLeadersMask && GiantsMask) || (GreatFairyMask && BunnyHood && KafeisMask && CouplesMask) || (GreatFairyMask && BunnyHood && KafeisMask && MaskOfTruth) || 
			(GreatFairyMask && BunnyHood && KafeisMask && GibdosMask) || (GreatFairyMask && BunnyHood && KafeisMask && GarosMask) || (GreatFairyMask && BunnyHood && KafeisMask && CaptainsHat) || 
			(GreatFairyMask && BunnyHood && KafeisMask && GiantsMask) || (GreatFairyMask && BunnyHood && CouplesMask && MaskOfTruth) || (GreatFairyMask && BunnyHood && CouplesMask && GibdosMask) ||
			(GreatFairyMask && BunnyHood && CouplesMask && GarosMask) || (GreatFairyMask && BunnyHood && CouplesMask && CaptainsHat) || (GreatFairyMask && BunnyHood && CouplesMask && GiantsMask) ||
			(GreatFairyMask && BunnyHood && MaskOfTruth && GibdosMask) || (GreatFairyMask && BunnyHood && MaskOfTruth && GarosMask) || (GreatFairyMask && BunnyHood && MaskOfTruth && CaptainsHat) ||
			(GreatFairyMask && BunnyHood && MaskOfTruth && GiantsMask) || (GreatFairyMask && BunnyHood && GibdosMask && GarosMask) || (GreatFairyMask && BunnyHood && GibdosMask && CaptainsHat) || 
			(GreatFairyMask && BunnyHood && GibdosMask && GiantsMask) || (GreatFairyMask && BunnyHood && GarosMask && CaptainsHat) || (GreatFairyMask && BunnyHood && GarosMask && GiantsMask) || 
			(GreatFairyMask && BunnyHood && CaptainsHat && GiantsMask) || (GreatFairyMask && DonGerosMask && MaskOfScents && RomanisMask) || (GreatFairyMask && DonGerosMask && MaskOfScents && CircusLeadersMask) ||
			(GreatFairyMask && DonGerosMask && MaskOfScents && KafeisMask) || (GreatFairyMask && DonGerosMask && MaskOfScents && CouplesMask) || (GreatFairyMask && DonGerosMask && MaskOfScents && MaskOfTruth) || 
			(GreatFairyMask && DonGerosMask && MaskOfScents && GibdosMask) || (GreatFairyMask && DonGerosMask && MaskOfScents && GarosMask) || (GreatFairyMask && DonGerosMask && MaskOfScents && CaptainsHat) || 
			(GreatFairyMask && DonGerosMask && MaskOfScents && GiantsMask) || (GreatFairyMask && DonGerosMask && RomanisMask && CircusLeadersMask) || (GreatFairyMask && DonGerosMask && RomanisMask && KafeisMask) || 
			(GreatFairyMask && DonGerosMask && RomanisMask && CouplesMask) || (GreatFairyMask && DonGerosMask && RomanisMask && MaskOfTruth) || (GreatFairyMask && DonGerosMask && RomanisMask && GibdosMask) || 
			(GreatFairyMask && DonGerosMask && RomanisMask && GarosMask) || (GreatFairyMask && DonGerosMask && RomanisMask && CaptainsHat) || (GreatFairyMask && DonGerosMask && RomanisMask && CircusLeadersMask && MaskOfTruth) ||
			(GreatFairyMask && DonGerosMask && CircusLeadersMask && GibdosMask) || (GreatFairyMask && DonGerosMask && CircusLeadersMask && GarosMask) || (GreatFairyMask && DonGerosMask && CircusLeadersMask && CaptainsHat) ||
			(GreatFairyMask && DonGerosMask && CircusLeadersMask && GiantsMask) || (GreatFairyMask && DonGerosMask && KafeisMask && CouplesMask) || (GreatFairyMask && DonGerosMask && KafeisMask && MaskOfTruth) || 
			(GreatFairyMask && DonGerosMask && KafeisMask && GibdosMask) || (GreatFairyMask && DonGerosMask && KafeisMask && GarosMask) || (GreatFairyMask && DonGerosMask && KafeisMask && CaptainsHat) ||
			(GreatFairyMask && DonGerosMask && KafeisMask && GiantsMask) || (GreatFairyMask && DonGerosMask && CouplesMask && MaskOfTruth) || (GreatFairyMask && DonGerosMask && CouplesMask && GibdosMask) || 
			(GreatFairyMask && DonGerosMask && CouplesMask && GarosMask) || (GreatFairyMask && DonGerosMask && CouplesMask && CaptainsHat) || (GreatFairyMask && DonGerosMask && CouplesMask && GiantsMask) || 
			(GreatFairyMask && DonGerosMask && MaskOfTruth && GibdosMask) || (GreatFairyMask && DonGerosMask && MaskOfTruth && GarosMask) || (GreatFairyMask && DonGerosMask && MaskOfTruth && CaptainsHat) || 
			(GreatFairyMask && DonGerosMask && MaskOfTruth && GiantsMask) || (GreatFairyMask && DonGerosMask && GibdosMask && GarosMask) || (GreatFairyMask && DonGerosMask && GibdosMask && CaptainsHat) ||
			(GreatFairyMask && DonGerosMask && GibdosMask && GiantsMask) || (GreatFairyMask && DonGerosMask && GarosMask && CaptainsHat) || (GreatFairyMask && DonGerosMask && GarosMask && GiantsMask) || 
			(GreatFairyMask && DonGerosMask && CaptainsHat && GiantsMask) || (GreatFairyMask && MaskOfScents && RomanisMask && CircusLeadersMask) || (GreatFairyMask && MaskOfScents && RomanisMask && KafeisMask) ||
			(GreatFairyMask && MaskOfScents && RomanisMask && CouplesMask) || (GreatFairyMask && MaskOfScents && RomanisMask && MaskOfTruth) || (GreatFairyMask && MaskOfScents && RomanisMask && GibdosMask) || 
			(GreatFairyMask && MaskOfScents && RomanisMask && GarosMask) || (GreatFairyMask && MaskOfScents && RomanisMask && CaptainsHat) || (GreatFairyMask && MaskOfScents && RomanisMask && GiantsMask) ||
			(GreatFairyMask && MaskOfScents && CircusLeadersMask && KafeisMask) || (GreatFairyMask && MaskOfScents && CircusLeadersMask && CouplesMask) || (GreatFairyMask && MaskOfScents && CircusLeadersMask && MaskOfTruth) || 
			(GreatFairyMask && MaskOfScents && CircusLeadersMask && GibdosMask) || (GreatFairyMask && MaskOfScents && CircusLeadersMask && GarosMask) || (GreatFairyMask && MaskOfScents && CircusLeadersMask && CaptainsHat) || 
			(GreatFairyMask && MaskOfScents && CircusLeadersMask && GiantsMask) || (GreatFairyMask && MaskOfScents && KafeisMask && CouplesMask) || (GreatFairyMask && MaskOfScents && KafeisMask && MaskOfTruth) || 
			(GreatFairyMask && MaskOfScents && KafeisMask && GibdosMask) || (GreatFairyMask && MaskOfScents && KafeisMask && GarosMask) || (GreatFairyMask && MaskOfScents && KafeisMask && CaptainsHat) ||
			(GreatFairyMask && MaskOfScents && KafeisMask && GiantsMask) || (GreatFairyMask && MaskOfScents && CouplesMask && MaskOfTruth) || (GreatFairyMask && MaskOfScents && CouplesMask && GibdosMask) || 
			(GreatFairyMask && MaskOfScents && CouplesMask && GarosMask) || (GreatFairyMask && MaskOfScents && CouplesMask && CaptainsHat) || (GreatFairyMask && MaskOfScents && CouplesMask && GiantsMask) ||
			(GreatFairyMask && MaskOfScents && MaskOfTruth && GibdosMask) || (GreatFairyMask && MaskOfScents && MaskOfTruth && GarosMask) || (GreatFairyMask && MaskOfScents && MaskOfTruth && CaptainsHat) ||
			(GreatFairyMask && MaskOfScents && MaskOfTruth && GiantsMask) || (GreatFairyMask && MaskOfScents && GibdosMask && GarosMask) || (GreatFairyMask && MaskOfScents && GibdosMask && CaptainsHat) || 
			(GreatFairyMask && MaskOfScents && GibdosMask && GiantsMask) || (GreatFairyMask && MaskOfScents && GarosMask && CaptainsHat) || (GreatFairyMask && MaskOfScents && GarosMask && GiantsMask) || 
			(GreatFairyMask && MaskOfScents && CaptainsHat && GiantsMask) || (GreatFairyMask && RomanisMask && CircusLeadersMask && KafeisMask) || (GreatFairyMask && RomanisMask && CircusLeadersMask && CouplesMask) ||
			(GreatFairyMask && RomanisMask && CircusLeadersMask && MaskOfTruth) || (GreatFairyMask && RomanisMask && CircusLeadersMask && GibdosMask) || (GreatFairyMask && RomanisMask && CircusLeadersMask && GarosMask) || 
			(GreatFairyMask && RomanisMask && CircusLeadersMask && CaptainsHat) || (GreatFairyMask && RomanisMask && CircusLeadersMask && GiantsMask) || (GreatFairyMask && RomanisMask && KafeisMask && CouplesMask) ||
			(GreatFairyMask && RomanisMask && KafeisMask && MaskOfTruth) || (GreatFairyMask && RomanisMask && KafeisMask && GibdosMask) || (GreatFairyMask && RomanisMask && KafeisMask && GarosMask) ||
			(GreatFairyMask && RomanisMask && KafeisMask && CaptainsHat) || (GreatFairyMask && RomanisMask && KafeisMask && GiantsMask) || (GreatFairyMask && RomanisMask && CouplesMask && MaskOfTruth) ||
			(GreatFairyMask && RomanisMask && CouplesMask && GibdosMask) || (GreatFairyMask && RomanisMask && CouplesMask && GarosMask) || (GreatFairyMask && RomanisMask && CouplesMask && CaptainsHat) ||
			(GreatFairyMask && RomanisMask && CouplesMask && GiantsMask) || (GreatFairyMask && RomanisMask && MaskOfTruth && GibdosMask) || (GreatFairyMask && RomanisMask && MaskOfTruth && GarosMask) || 
			(GreatFairyMask && RomanisMask && MaskOfTruth && CaptainsHat) || (GreatFairyMask && RomanisMask && MaskOfTruth && GiantsMask) || (GreatFairyMask && RomanisMask && GibdosMask && GarosMask) || 
			(GreatFairyMask && RomanisMask && GibdosMask && CaptainsHat) || (GreatFairyMask && RomanisMask && GibdosMask && GiantsMask) || (GreatFairyMask && RomanisMask && GarosMask && CaptainsHat) || 
			(GreatFairyMask && RomanisMask && GarosMask && GiantsMask) || (GreatFairyMask && RomanisMask && CaptainsHat && GiantsMask) || (GreatFairyMask && CircusLeadersMask && KafeisMask && CouplesMask) || 
			(GreatFairyMask && CircusLeadersMask && KafeisMask && MaskOfTruth) || (GreatFairyMask && CircusLeadersMask && KafeisMask && GibdosMask) || (GreatFairyMask && CircusLeadersMask && KafeisMask && GarosMask) ||
			(GreatFairyMask && CircusLeadersMask && KafeisMask && CaptainsHat) || (GreatFairyMask && CircusLeadersMask && KafeisMask && GiantsMask) || (GreatFairyMask && CircusLeadersMask && CouplesMask && MaskOfTruth) ||
			(GreatFairyMask && CircusLeadersMask && CouplesMask && GibdosMask) || (GreatFairyMask && CircusLeadersMask && CouplesMask && GarosMask) || (GreatFairyMask && CircusLeadersMask && CouplesMask && CaptainsHat) ||
			(GreatFairyMask && CircusLeadersMask && CouplesMask && GiantsMask) || (GreatFairyMask && CircusLeadersMask && MaskOfTruth && GibdosMask) || (GreatFairyMask && CircusLeadersMask && MaskOfTruth && GarosMask) || 
			(GreatFairyMask && CircusLeadersMask && MaskOfTruth && CaptainsHat) || (GreatFairyMask && CircusLeadersMask && MaskOfTruth && GiantsMask) || (GreatFairyMask && CircusLeadersMask && GibdosMask && GarosMask) ||
			(GreatFairyMask && CircusLeadersMask && GibdosMask && CaptainsHat) || (GreatFairyMask && CircusLeadersMask && GibdosMask && GiantsMask) || (GreatFairyMask && CircusLeadersMask && GarosMask && CaptainsHat) || 
			(GreatFairyMask && CircusLeadersMask && GarosMask && GiantsMask) || (GreatFairyMask && CircusLeadersMask && CaptainsHat && GiantsMask) || (GreatFairyMask && KafeisMask && CouplesMask && MaskOfTruth) ||
			(GreatFairyMask && KafeisMask && CouplesMask && GibdosMask) || (GreatFairyMask && KafeisMask && CouplesMask && GarosMask) || (GreatFairyMask && KafeisMask && CouplesMask && CaptainsHat) ||
			(GreatFairyMask && KafeisMask && CouplesMask && GiantsMask) || (GreatFairyMask && KafeisMask && MaskOfTruth && GibdosMask) || (GreatFairyMask && KafeisMask && MaskOfTruth && GarosMask) ||
			(GreatFairyMask && KafeisMask && MaskOfTruth && CaptainsHat) || (GreatFairyMask && KafeisMask && MaskOfTruth && GiantsMask) || (GreatFairyMask && KafeisMask && GibdosMask && GarosMask) ||
			(GreatFairyMask && KafeisMask && GibdosMask && CaptainsHat) || (GreatFairyMask && KafeisMask && GibdosMask && GiantsMask) || (GreatFairyMask && KafeisMask && GarosMask && CaptainsHat) || 
			(GreatFairyMask && KafeisMask && GarosMask && GiantsMask) || (GreatFairyMask && KafeisMask && CaptainsHat && GiantsMask) || (GreatFairyMask && CouplesMask && MaskOfTruth && GibdosMask) ||
			(GreatFairyMask && CouplesMask && MaskOfTruth && GarosMask) || (GreatFairyMask && CouplesMask && MaskOfTruth && CaptainsHat) || (GreatFairyMask && CouplesMask && MaskOfTruth && GiantsMask) ||
			(GreatFairyMask && CouplesMask && GibdosMask && GarosMask) || (GreatFairyMask && CouplesMask && GibdosMask && CaptainsHat) || (GreatFairyMask && CouplesMask && GibdosMask && GiantsMask) ||
			(GreatFairyMask && CouplesMask && GarosMask && CaptainsHat) || (GreatFairyMask && CouplesMask && GarosMask && GiantsMask) || (GreatFairyMask && CouplesMask && CaptainsHat && GiantsMask) ||
			(GreatFairyMask && MaskOfTruth && GibdosMask && GarosMask) || (GreatFairyMask && MaskOfTruth && GibdosMask && CaptainsHat) || (GreatFairyMask && MaskOfTruth && GibdosMask && GiantsMask) ||
			(GreatFairyMask && MaskOfTruth && GarosMask && CaptainsHat) || (GreatFairyMask && MaskOfTruth && GarosMask && GiantsMask) || (GreatFairyMask && MaskOfTruth && CaptainsHat && GiantsMask) ||
			(GreatFairyMask && GibdosMask && GarosMask && CaptainsHat) || (GreatFairyMask && GibdosMask && GarosMask && GiantsMask) || (GreatFairyMask && GibdosMask && CaptainsHat && GiantsMask) ||
			(GreatFairyMask && GarosMask && CaptainsHat && GiantsMask) || (KeatonMask && BremenMask && BunnyHood && DonGerosMask) || (KeatonMask && BremenMask && BunnyHood && MaskOfScents) || 
			(KeatonMask && BremenMask && BunnyHood && RomanisMask) || (KeatonMask && BremenMask && BunnyHood && CircusLeadersMask) || (KeatonMask && BremenMask && BunnyHood && KafeisMask) ||
			(KeatonMask && BremenMask && BunnyHood && CouplesMask) || (KeatonMask && BremenMask && BunnyHood && MaskOfTruth) || (KeatonMask && BremenMask && BunnyHood && GibdosMask) || 
			(KeatonMask && BremenMask && BunnyHood && GarosMask) || (KeatonMask && BremenMask && BunnyHood && CaptainsHat) || (KeatonMask && BremenMask && BunnyHood && GiantsMask) ||
			(KeatonMask && BremenMask && DonGerosMask && MaskOfScents) || (KeatonMask && BremenMask && DonGerosMask && RomanisMask) || (KeatonMask && BremenMask && DonGerosMask && CircusLeadersMask) || 
			(KeatonMask && BremenMask && DonGerosMask && KafeisMask) || (KeatonMask && BremenMask && DonGerosMask && CouplesMask) || (KeatonMask && BremenMask && DonGerosMask && MaskOfTruth) || 
			(KeatonMask && BremenMask && DonGerosMask && GibdosMask) || (KeatonMask && BremenMask && DonGerosMask && GarosMask) || (KeatonMask && BremenMask && DonGerosMask && CaptainsHat) || 
			(KeatonMask && BremenMask && DonGerosMask && GiantsMask) || (KeatonMask && BremenMask && MaskOfScents && RomanisMask) || (KeatonMask && BremenMask && MaskOfScents && CircusLeadersMask) ||
			(KeatonMask && BremenMask && MaskOfScents && KafeisMask) || (KeatonMask && BremenMask && MaskOfScents && CouplesMask) || (KeatonMask && BremenMask && MaskOfScents && MaskOfTruth) ||
			(KeatonMask && BremenMask && MaskOfScents && GibdosMask) || (KeatonMask && BremenMask && MaskOfScents && GarosMask) || (KeatonMask && BremenMask && MaskOfScents && CaptainsHat) || 
			(KeatonMask && BremenMask && MaskOfScents && GiantsMask) || (KeatonMask && BremenMask && RomanisMask && CircusLeadersMask) || (KeatonMask && BremenMask && RomanisMask && KafeisMask) || 
			(KeatonMask && BremenMask && RomanisMask && CouplesMask) || (KeatonMask && BremenMask && RomanisMask && MaskOfTruth) || (KeatonMask && BremenMask && RomanisMask && GibdosMask) ||
			(KeatonMask && BremenMask && RomanisMask && GarosMask) || (KeatonMask && BremenMask && RomanisMask && CaptainsHat) || (KeatonMask && BremenMask && RomanisMask && GiantsMask) || 
			(KeatonMask && BremenMask && CircusLeadersMask && KafeisMask) || (KeatonMask && BremenMask && CircusLeadersMask && CouplesMask) || (KeatonMask && BremenMask && CircusLeadersMask && MaskOfTruth) ||
			(KeatonMask && BremenMask && CircusLeadersMask && GibdosMask) || (KeatonMask && BremenMask && CircusLeadersMask && GarosMask) || (KeatonMask && BremenMask && CircusLeadersMask && CaptainsHat) || 
			(KeatonMask && BremenMask && CircusLeadersMask && GiantsMask) || (KeatonMask && BremenMask && KafeisMask && CouplesMask) || (KeatonMask && BremenMask && KafeisMask && MaskOfTruth) || 
			(KeatonMask && BremenMask && KafeisMask && GibdosMask) || (KeatonMask && BremenMask && KafeisMask && GarosMask) || (KeatonMask && BremenMask && KafeisMask && CaptainsHat) || 
			(KeatonMask && BremenMask && KafeisMask && GiantsMask) || (KeatonMask && BremenMask && CouplesMask && MaskOfTruth) || (KeatonMask && BremenMask && CouplesMask && GibdosMask) ||
			(KeatonMask && BremenMask && CouplesMask && GarosMask) || (KeatonMask && BremenMask && CouplesMask && CaptainsHat) || (KeatonMask && BremenMask && CouplesMask && GiantsMask) ||
			(KeatonMask && BremenMask && MaskOfTruth && GibdosMask) || (KeatonMask && BremenMask && MaskOfTruth && GarosMask) || (KeatonMask && BremenMask && MaskOfTruth && CaptainsHat) || 
			(KeatonMask && BremenMask && MaskOfTruth && GiantsMask) || (KeatonMask && BremenMask && GibdosMask && GarosMask) || (KeatonMask && BremenMask && GibdosMask && CaptainsHat) || 
			(KeatonMask && BremenMask && GibdosMask && GiantsMask) || (KeatonMask && BremenMask && GarosMask && CaptainsHat) || (KeatonMask && BremenMask && GarosMask && GiantsMask) || 
			(KeatonMask && BremenMask && CaptainsHat && GiantsMask) || (KeatonMask && BunnyHood && DonGerosMask && MaskOfScents) || (KeatonMask && BunnyHood && DonGerosMask && RomanisMask) || 
			(KeatonMask && BunnyHood && DonGerosMask && CircusLeadersMask) || (KeatonMask && BunnyHood && DonGerosMask && KafeisMask) || (KeatonMask && BunnyHood && DonGerosMask && CouplesMask) ||
			(KeatonMask && BunnyHood && DonGerosMask && MaskOfTruth) || (KeatonMask && BunnyHood && DonGerosMask && GibdosMask) || (KeatonMask && BunnyHood && DonGerosMask && GarosMask) || 
			(KeatonMask && BunnyHood && DonGerosMask && CaptainsHat) || (KeatonMask && BunnyHood && DonGerosMask && GiantsMask) || (KeatonMask && BunnyHood && MaskOfScents && RomanisMask) ||
			(KeatonMask && BunnyHood && MaskOfScents && CircusLeadersMask) || (KeatonMask && BunnyHood && MaskOfScents && KafeisMask) || (KeatonMask && BunnyHood && MaskOfScents && CouplesMask) ||
			(KeatonMask && BunnyHood && MaskOfScents && MaskOfTruth) || (KeatonMask && BunnyHood && MaskOfScents && GibdosMask) || (KeatonMask && BunnyHood && MaskOfScents && GarosMask) || 
			(KeatonMask && BunnyHood && MaskOfScents && CaptainsHat) || (KeatonMask && BunnyHood && MaskOfScents && GiantsMask) || (KeatonMask && BunnyHood && RomanisMask && CircusLeadersMask) || 
			(KeatonMask && BunnyHood && RomanisMask && KafeisMask) || (KeatonMask && BunnyHood && RomanisMask && CouplesMask) || (KeatonMask && BunnyHood && RomanisMask && MaskOfTruth) || 
			(KeatonMask && BunnyHood && RomanisMask && GibdosMask) || (KeatonMask && BunnyHood && RomanisMask && GarosMask) || (KeatonMask && BunnyHood && RomanisMask && CaptainsHat) ||
			(KeatonMask && BunnyHood && RomanisMask && GiantsMask) || (KeatonMask && BunnyHood && CircusLeadersMask && KafeisMask) || (KeatonMask && BunnyHood && CircusLeadersMask && CouplesMask) || 
			(KeatonMask && BunnyHood && CircusLeadersMask && MaskOfTruth) || (KeatonMask && BunnyHood && CircusLeadersMask && GibdosMask) || (KeatonMask && BunnyHood && CircusLeadersMask && GarosMask) || 
			(KeatonMask && BunnyHood && CircusLeadersMask && CaptainsHat) || (KeatonMask && BunnyHood && CircusLeadersMask && GiantsMask) || (KeatonMask && BunnyHood && KafeisMask && CouplesMask) || 
			(KeatonMask && BunnyHood && KafeisMask && MaskOfTruth) || (KeatonMask && BunnyHood && KafeisMask && GibdosMask) || (KeatonMask && BunnyHood && KafeisMask && GarosMask) || 
			(KeatonMask && BunnyHood && KafeisMask && CaptainsHat) || (KeatonMask && BunnyHood && KafeisMask && GiantsMask) || (KeatonMask && BunnyHood && CouplesMask && MaskOfTruth) || 
			(KeatonMask && BunnyHood && CouplesMask && GibdosMask) || (KeatonMask && BunnyHood && CouplesMask && GarosMask) || (KeatonMask && BunnyHood && CouplesMask && CaptainsHat) || 
			(KeatonMask && BunnyHood && CouplesMask && GiantsMask) || (KeatonMask && BunnyHood && MaskOfTruth && GibdosMask) || (KeatonMask && BunnyHood && MaskOfTruth && GarosMask) ||
			(KeatonMask && BunnyHood && MaskOfTruth && CaptainsHat) || (KeatonMask && BunnyHood && MaskOfTruth && GiantsMask) || (KeatonMask && BunnyHood && GibdosMask && GarosMask) || 
			(KeatonMask && BunnyHood && GibdosMask && CaptainsHat) || (KeatonMask && BunnyHood && GibdosMask && GiantsMask) || (KeatonMask && BunnyHood && GarosMask && CaptainsHat) || 
			(KeatonMask && BunnyHood && GarosMask && GiantsMask) || (KeatonMask && BunnyHood && CaptainsHat && GiantsMask) || (KeatonMask && DonGerosMask && MaskOfScents && RomanisMask) ||
			(KeatonMask && DonGerosMask && MaskOfScents && CircusLeadersMask) || (KeatonMask && DonGerosMask && MaskOfScents && KafeisMask) || (KeatonMask && DonGerosMask && MaskOfScents && CouplesMask) || 
			(KeatonMask && DonGerosMask && MaskOfScents && MaskOfTruth) || (KeatonMask && DonGerosMask && MaskOfScents && GibdosMask) || (KeatonMask && DonGerosMask && MaskOfScents && GarosMask) || 
			(KeatonMask && DonGerosMask && MaskOfScents && CaptainsHat) || (KeatonMask && DonGerosMask && MaskOfScents && GiantsMask) || (KeatonMask && DonGerosMask && RomanisMask && CircusLeadersMask) || 
			(KeatonMask && DonGerosMask && RomanisMask && KafeisMask) || (KeatonMask && DonGerosMask && RomanisMask && CouplesMask) || (KeatonMask && DonGerosMask && RomanisMask && MaskOfTruth) ||
			(KeatonMask && DonGerosMask && RomanisMask && GibdosMask) || (KeatonMask && DonGerosMask && RomanisMask && GarosMask) || (KeatonMask && DonGerosMask && RomanisMask && CaptainsHat) ||
			(KeatonMask && DonGerosMask && RomanisMask && GiantsMask) || (KeatonMask && DonGerosMask && CircusLeadersMask && KafeisMask) || (KeatonMask && DonGerosMask && CircusLeadersMask && CouplesMask) || 
			(KeatonMask && DonGerosMask && CircusLeadersMask && MaskOfTruth) || (KeatonMask && DonGerosMask && CircusLeadersMask && GibdosMask) || (KeatonMask && DonGerosMask && CircusLeadersMask && GarosMask) ||
			(KeatonMask && DonGerosMask && CircusLeadersMask && CaptainsHat) || (KeatonMask && DonGerosMask && CircusLeadersMask && GiantsMask) || (KeatonMask && DonGerosMask && KafeisMask && CouplesMask) || 
			(KeatonMask && DonGerosMask && KafeisMask && MaskOfTruth) || (KeatonMask && DonGerosMask && KafeisMask && GibdosMask) || (KeatonMask && DonGerosMask && KafeisMask && GarosMask) || 
			(KeatonMask && DonGerosMask && KafeisMask && CaptainsHat) || (KeatonMask && DonGerosMask && KafeisMask && GiantsMask) || (KeatonMask && DonGerosMask && CouplesMask && MaskOfTruth) || 
			(KeatonMask && DonGerosMask && CouplesMask && GibdosMask) || (KeatonMask && DonGerosMask && CouplesMask && GarosMask) || (KeatonMask && DonGerosMask && CouplesMask && CaptainsHat) || 
			(KeatonMask && DonGerosMask && CouplesMask && GiantsMask) || (KeatonMask && DonGerosMask && MaskOfTruth && GibdosMask) || (KeatonMask && DonGerosMask && MaskOfTruth && GarosMask) || 
			(KeatonMask && DonGerosMask && MaskOfTruth && CaptainsHat) || (KeatonMask && DonGerosMask && MaskOfTruth && GiantsMask) || (KeatonMask && DonGerosMask && GibdosMask && GarosMask) ||
			(KeatonMask && DonGerosMask && GibdosMask && CaptainsHat) || (KeatonMask && DonGerosMask && GibdosMask && GiantsMask) || (KeatonMask && DonGerosMask && GarosMask && CaptainsHat) || 
			(KeatonMask && DonGerosMask && GarosMask && GiantsMask) || (KeatonMask && DonGerosMask && CaptainsHat && GiantsMask) || (KeatonMask && MaskOfScents && RomanisMask && CircusLeadersMask) || 
			(KeatonMask && MaskOfScents && RomanisMask && KafeisMask) || (KeatonMask && MaskOfScents && RomanisMask && CouplesMask) || (KeatonMask && MaskOfScents && RomanisMask && MaskOfTruth) ||
			(KeatonMask && MaskOfScents && RomanisMask && GibdosMask) || (KeatonMask && MaskOfScents && RomanisMask && GarosMask) || (KeatonMask && MaskOfScents && RomanisMask && CaptainsHat) || 
			(KeatonMask && MaskOfScents && RomanisMask && GiantsMask) || (KeatonMask && MaskOfScents && CircusLeadersMask && KafeisMask) || (KeatonMask && MaskOfScents && CircusLeadersMask && CouplesMask) ||
			(KeatonMask && MaskOfScents && CircusLeadersMask && MaskOfTruth) || (KeatonMask && MaskOfScents && CircusLeadersMask && GibdosMask) || (KeatonMask && MaskOfScents && CircusLeadersMask && GarosMask) ||
			(KeatonMask && MaskOfScents && CircusLeadersMask && CaptainsHat) || (KeatonMask && MaskOfScents && CircusLeadersMask && GiantsMask) || (KeatonMask && MaskOfScents && KafeisMask && CouplesMask) || 
			(KeatonMask && MaskOfScents && KafeisMask && MaskOfTruth) || (KeatonMask && MaskOfScents && KafeisMask && GibdosMask) || (KeatonMask && MaskOfScents && KafeisMask && GarosMask) ||
			(KeatonMask && MaskOfScents && KafeisMask && CaptainsHat) || (KeatonMask && MaskOfScents && KafeisMask && GiantsMask) || (KeatonMask && MaskOfScents && CouplesMask && MaskOfTruth) ||
			(KeatonMask && MaskOfScents && CouplesMask && GibdosMask) || (KeatonMask && MaskOfScents && CouplesMask && GarosMask) || (KeatonMask && MaskOfScents && CouplesMask && CaptainsHat) ||
			(KeatonMask && MaskOfScents && CouplesMask && GiantsMask) || (KeatonMask && MaskOfScents && MaskOfTruth && GibdosMask) || (KeatonMask && MaskOfScents && MaskOfTruth && GarosMask) ||
			(KeatonMask && MaskOfScents && MaskOfTruth && CaptainsHat) || (KeatonMask && MaskOfScents && MaskOfTruth && GiantsMask) || (KeatonMask && MaskOfScents && GibdosMask && GarosMask) || 
			(KeatonMask && MaskOfScents && GibdosMask && CaptainsHat) || (KeatonMask && MaskOfScents && GibdosMask && GiantsMask) || (KeatonMask && MaskOfScents && GarosMask && CaptainsHat) || 
			(KeatonMask && MaskOfScents && GarosMask && GiantsMask) || (KeatonMask && MaskOfScents && CaptainsHat && GiantsMask) || (KeatonMask && RomanisMask && CircusLeadersMask && KafeisMask) || 
			(KeatonMask && RomanisMask && CircusLeadersMask && CouplesMask) || (KeatonMask && RomanisMask && CircusLeadersMask && MaskOfTruth) || (KeatonMask && RomanisMask && CircusLeadersMask && GibdosMask) || 
			(KeatonMask && RomanisMask && CircusLeadersMask && GarosMask) || (KeatonMask && RomanisMask && CircusLeadersMask && CaptainsHat) || (KeatonMask && RomanisMask && CircusLeadersMask && GiantsMask) || 
			(KeatonMask && RomanisMask && KafeisMask && CouplesMask) || (KeatonMask && RomanisMask && KafeisMask && MaskOfTruth) || (KeatonMask && RomanisMask && KafeisMask && GibdosMask) ||
			(KeatonMask && RomanisMask && KafeisMask && GarosMask) || (KeatonMask && RomanisMask && KafeisMask && CaptainsHat) || (KeatonMask && RomanisMask && KafeisMask && GiantsMask) || 
			(KeatonMask && RomanisMask && CouplesMask && MaskOfTruth) || (KeatonMask && RomanisMask && CouplesMask && GibdosMask) || (KeatonMask && RomanisMask && CouplesMask && GarosMask) ||
			(KeatonMask && RomanisMask && CouplesMask && CaptainsHat) || (KeatonMask && RomanisMask && CouplesMask && GiantsMask) || (KeatonMask && RomanisMask && MaskOfTruth && GibdosMask) ||
			(KeatonMask && RomanisMask && MaskOfTruth && GarosMask) || (KeatonMask && RomanisMask && MaskOfTruth && CaptainsHat) || (KeatonMask && RomanisMask && MaskOfTruth && GiantsMask) || 
			(KeatonMask && RomanisMask && GibdosMask && GarosMask) || (KeatonMask && RomanisMask && GibdosMask && CaptainsHat) || (KeatonMask && RomanisMask && GibdosMask && GiantsMask) ||
			(KeatonMask && RomanisMask && GarosMask && CaptainsHat) || (KeatonMask && RomanisMask && GarosMask && GiantsMask) || (KeatonMask && RomanisMask && CaptainsHat && GiantsMask) || 
			(KeatonMask && CircusLeadersMask && KafeisMask && CouplesMask) || (KeatonMask && CircusLeadersMask && KafeisMask && MaskOfTruth) || (KeatonMask && CircusLeadersMask && KafeisMask && GibdosMask) ||
			(KeatonMask && CircusLeadersMask && KafeisMask && GarosMask) || (KeatonMask && CircusLeadersMask && KafeisMask && CaptainsHat) || (KeatonMask && CircusLeadersMask && KafeisMask && GiantsMask) ||
			(KeatonMask && CircusLeadersMask && CouplesMask && MaskOfTruth) || (KeatonMask && CircusLeadersMask && CouplesMask && GibdosMask) || (KeatonMask && CircusLeadersMask && CouplesMask && GarosMask) || 
			(KeatonMask && CircusLeadersMask && CouplesMask && CaptainsHat) || (KeatonMask && CircusLeadersMask && CouplesMask && GiantsMask) || (KeatonMask && CircusLeadersMask && MaskOfTruth && GibdosMask) ||
			(KeatonMask && CircusLeadersMask && MaskOfTruth && GarosMask) || (KeatonMask && CircusLeadersMask && MaskOfTruth && CaptainsHat) || (KeatonMask && CircusLeadersMask && MaskOfTruth && GiantsMask) ||
			(KeatonMask && CircusLeadersMask && GibdosMask && GarosMask) || (KeatonMask && CircusLeadersMask && GibdosMask && CaptainsHat) || (KeatonMask && CircusLeadersMask && GibdosMask && GiantsMask) ||
			(KeatonMask && CircusLeadersMask && GarosMask && CaptainsHat) || (KeatonMask && CircusLeadersMask && GarosMask && GiantsMask) || (KeatonMask && CircusLeadersMask && CaptainsHat && GiantsMask) || 
			(KeatonMask && KafeisMask && CouplesMask && MaskOfTruth) || (KeatonMask && KafeisMask && CouplesMask && GibdosMask) || (KeatonMask && KafeisMask && CouplesMask && GarosMask) || 
			(KeatonMask && KafeisMask && CouplesMask && CaptainsHat) || (KeatonMask && KafeisMask && CouplesMask && GiantsMask) || (KeatonMask && KafeisMask && MaskOfTruth && GibdosMask) ||
			(KeatonMask && KafeisMask && MaskOfTruth && GarosMask) || (KeatonMask && KafeisMask && MaskOfTruth && CaptainsHat) || (KeatonMask && KafeisMask && MaskOfTruth && GiantsMask) || 
			(KeatonMask && KafeisMask && GibdosMask && GarosMask) || (KeatonMask && KafeisMask && GibdosMask && CaptainsHat) || (KeatonMask && KafeisMask && GibdosMask && GiantsMask) || 
			(KeatonMask && KafeisMask && GarosMask && CaptainsHat) || (KeatonMask && KafeisMask && GarosMask && GiantsMask) || (KeatonMask && KafeisMask && CaptainsHat && GiantsMask) || 
			(KeatonMask && CouplesMask && MaskOfTruth && GibdosMask) || (KeatonMask && CouplesMask && MaskOfTruth && GarosMask) || (KeatonMask && CouplesMask && MaskOfTruth && CaptainsHat) || 
			(KeatonMask && CouplesMask && MaskOfTruth && GiantsMask) || (KeatonMask && CouplesMask && GibdosMask && GarosMask) || (KeatonMask && CouplesMask && GibdosMask && CaptainsHat) ||
			(KeatonMask && CouplesMask && GibdosMask && GiantsMask) || (KeatonMask && CouplesMask && GarosMask && CaptainsHat) || (KeatonMask && CouplesMask && GarosMask && GiantsMask) || 
			(KeatonMask && CouplesMask && CaptainsHat && GiantsMask) || (KeatonMask && MaskOfTruth && GibdosMask && GarosMask) || (KeatonMask && MaskOfTruth && GibdosMask && CaptainsHat) ||
			(KeatonMask && MaskOfTruth && GibdosMask && GiantsMask) || (KeatonMask && MaskOfTruth && GarosMask && CaptainsHat) || (KeatonMask && MaskOfTruth && GarosMask && GiantsMask) ||
			(KeatonMask && MaskOfTruth && CaptainsHat && GiantsMask) || (KeatonMask && GibdosMask && GarosMask && CaptainsHat) || (KeatonMask && GibdosMask && GarosMask && GiantsMask) || 
			(KeatonMask && GibdosMask && CaptainsHat && GiantsMask) || (KeatonMask && GarosMask && CaptainsHat && GiantsMask) || (BremenMask && BunnyHood && DonGerosMask && MaskOfScents) || 
			(BremenMask && BunnyHood && DonGerosMask && RomanisMask) || (BremenMask && BunnyHood && DonGerosMask && CircusLeadersMask) || (BremenMask && BunnyHood && DonGerosMask && KafeisMask) ||
			(BremenMask && BunnyHood && DonGerosMask && CouplesMask) || (BremenMask && BunnyHood && DonGerosMask && MaskOfTruth) || (BremenMask && BunnyHood && DonGerosMask && GibdosMask) || 
			(BremenMask && BunnyHood && DonGerosMask && GarosMask) || (BremenMask && BunnyHood && DonGerosMask && CaptainsHat) || (BremenMask && BunnyHood && DonGerosMask && GiantsMask) ||
			(BremenMask && BunnyHood && MaskOfScents && RomanisMask) || (BremenMask && BunnyHood && MaskOfScents && CircusLeadersMask) || (BremenMask && BunnyHood && MaskOfScents && KafeisMask) || 
			(BremenMask && BunnyHood && MaskOfScents && CouplesMask) || (BremenMask && BunnyHood && MaskOfScents && MaskOfTruth) || (BremenMask && BunnyHood && MaskOfScents && GibdosMask) ||
			(BremenMask && BunnyHood && MaskOfScents && GarosMask) || (BremenMask && BunnyHood && MaskOfScents && CaptainsHat) || (BremenMask && BunnyHood && MaskOfScents && GiantsMask) || 
			(BremenMask && BunnyHood && RomanisMask && CircusLeadersMask) || (BremenMask && BunnyHood && RomanisMask && KafeisMask) || (BremenMask && BunnyHood && RomanisMask && CouplesMask) || 
			(BremenMask && BunnyHood && RomanisMask && MaskOfTruth) || (BremenMask && BunnyHood && RomanisMask && GibdosMask) || (BremenMask && BunnyHood && RomanisMask && GarosMask) || 
			(BremenMask && BunnyHood && RomanisMask && CaptainsHat) || (BremenMask && BunnyHood && RomanisMask && GiantsMask) || (BremenMask && BunnyHood && CircusLeadersMask && KafeisMask) || 
			(BremenMask && BunnyHood && CircusLeadersMask && CouplesMask) || (BremenMask && BunnyHood && CircusLeadersMask && MaskOfTruth) || (BremenMask && BunnyHood && CircusLeadersMask && GibdosMask) ||
			(BremenMask && BunnyHood && CircusLeadersMask && GarosMask) || (BremenMask && BunnyHood && CircusLeadersMask && CaptainsHat) || (BremenMask && BunnyHood && CircusLeadersMask && GiantsMask) || 
			(BremenMask && BunnyHood && KafeisMask && CouplesMask) || (BremenMask && BunnyHood && KafeisMask && MaskOfTruth) || (BremenMask && BunnyHood && KafeisMask && GibdosMask) || 
			(BremenMask && BunnyHood && KafeisMask && GarosMask) || (BremenMask && BunnyHood && KafeisMask && CaptainsHat) || (BremenMask && BunnyHood && KafeisMask && GiantsMask) ||
			(BremenMask && BunnyHood && CouplesMask && MaskOfTruth) || (BremenMask && BunnyHood && CouplesMask && GibdosMask) || (BremenMask && BunnyHood && CouplesMask && GarosMask) || 
			(BremenMask && BunnyHood && CouplesMask && CaptainsHat) || (BremenMask && BunnyHood && CouplesMask && GiantsMask) || (BremenMask && BunnyHood && MaskOfTruth && GibdosMask) ||
			(BremenMask && BunnyHood && MaskOfTruth && GarosMask) || (BremenMask && BunnyHood && MaskOfTruth && CaptainsHat) || (BremenMask && BunnyHood && MaskOfTruth && GiantsMask) || 
			(BremenMask && BunnyHood && GibdosMask && GarosMask) || (BremenMask && BunnyHood && GibdosMask && CaptainsHat) || (BremenMask && BunnyHood && GibdosMask && GiantsMask) ||
			(BremenMask && BunnyHood && GarosMask && CaptainsHat) || (BremenMask && BunnyHood && GarosMask && GiantsMask) || (BremenMask && BunnyHood && CaptainsHat && GiantsMask) ||
			(BremenMask && DonGerosMask && MaskOfScents && RomanisMask) || (BremenMask && DonGerosMask && MaskOfScents && CircusLeadersMask) || (BremenMask && DonGerosMask && MaskOfScents && KafeisMask) ||
			(BremenMask && DonGerosMask && MaskOfScents && CouplesMask) || (BremenMask && DonGerosMask && MaskOfScents && MaskOfTruth) || (BremenMask && DonGerosMask && MaskOfScents && GibdosMask) ||
			(BremenMask && DonGerosMask && MaskOfScents && GarosMask) || (BremenMask && DonGerosMask && MaskOfScents && CaptainsHat) || (BremenMask && DonGerosMask && MaskOfScents && GiantsMask) || 
			(BremenMask && DonGerosMask && RomanisMask && CircusLeadersMask) || (BremenMask && DonGerosMask && RomanisMask && KafeisMask) || (BremenMask && DonGerosMask && RomanisMask && CouplesMask) || 
			(BremenMask && DonGerosMask && RomanisMask && MaskOfTruth) || (BremenMask && DonGerosMask && RomanisMask && GibdosMask) || (BremenMask && DonGerosMask && RomanisMask && GarosMask) ||
			(BremenMask && DonGerosMask && RomanisMask && CaptainsHat) || (BremenMask && DonGerosMask && RomanisMask && GiantsMask) || (BremenMask && DonGerosMask && CircusLeadersMask && KafeisMask) ||
			(BremenMask && DonGerosMask && CircusLeadersMask && CouplesMask) || (BremenMask && DonGerosMask && CircusLeadersMask && MaskOfTruth) || (BremenMask && DonGerosMask && CircusLeadersMask && GibdosMask) ||
			(BremenMask && DonGerosMask && CircusLeadersMask && GarosMask) || (BremenMask && DonGerosMask && CircusLeadersMask && CaptainsHat) || (BremenMask && DonGerosMask && CircusLeadersMask && GiantsMask) ||
			(BremenMask && DonGerosMask && KafeisMask && CouplesMask) || (BremenMask && DonGerosMask && KafeisMask && MaskOfTruth) || (BremenMask && DonGerosMask && KafeisMask && GibdosMask) ||
			(BremenMask && DonGerosMask && KafeisMask && GarosMask) || (BremenMask && DonGerosMask && KafeisMask && CaptainsHat) || (BremenMask && DonGerosMask && KafeisMask && GiantsMask) || 
			(BremenMask && DonGerosMask && CouplesMask && MaskOfTruth) || (BremenMask && DonGerosMask && CouplesMask && GibdosMask) || (BremenMask && DonGerosMask && CouplesMask && GarosMask) ||
			(BremenMask && DonGerosMask && CouplesMask && CaptainsHat) || (BremenMask && DonGerosMask && CouplesMask && GiantsMask) || (BremenMask && DonGerosMask && MaskOfTruth && GibdosMask) ||
			(BremenMask && DonGerosMask && MaskOfTruth && GarosMask) || (BremenMask && DonGerosMask && MaskOfTruth && CaptainsHat) || (BremenMask && DonGerosMask && MaskOfTruth && GiantsMask) || 
			(BremenMask && DonGerosMask && GibdosMask && GarosMask) || (BremenMask && DonGerosMask && GibdosMask && CaptainsHat) || (BremenMask && DonGerosMask && GibdosMask && GiantsMask) || 
			(BremenMask && DonGerosMask && GarosMask && CaptainsHat) || (BremenMask && DonGerosMask && GarosMask && GiantsMask) || (BremenMask && DonGerosMask && CaptainsHat && GiantsMask) || 
			(BremenMask && MaskOfScents && RomanisMask && CircusLeadersMask) || (BremenMask && MaskOfScents && RomanisMask && KafeisMask) || (BremenMask && MaskOfScents && RomanisMask && CouplesMask) ||
			(BremenMask && MaskOfScents && RomanisMask && MaskOfTruth) || (BremenMask && MaskOfScents && RomanisMask && GibdosMask) || (BremenMask && MaskOfScents && RomanisMask && GarosMask) || 
			(BremenMask && MaskOfScents && RomanisMask && CaptainsHat) || (BremenMask && MaskOfScents && RomanisMask && GiantsMask) || (BremenMask && MaskOfScents && CircusLeadersMask && KafeisMask) || 
			(BremenMask && MaskOfScents && CircusLeadersMask && CouplesMask) || (BremenMask && MaskOfScents && CircusLeadersMask && MaskOfTruth) || (BremenMask && MaskOfScents && CircusLeadersMask && GibdosMask) ||
			(BremenMask && MaskOfScents && CircusLeadersMask && GarosMask) || (BremenMask && MaskOfScents && CircusLeadersMask && CaptainsHat) || (BremenMask && MaskOfScents && CircusLeadersMask && GiantsMask) ||
			(BremenMask && MaskOfScents && KafeisMask && CouplesMask) || (BremenMask && MaskOfScents && KafeisMask && MaskOfTruth) || (BremenMask && MaskOfScents && KafeisMask && GibdosMask) || 
			(BremenMask && MaskOfScents && KafeisMask && GarosMask) || (BremenMask && MaskOfScents && KafeisMask && CaptainsHat) || (BremenMask && MaskOfScents && KafeisMask && GiantsMask) || 
			(BremenMask && MaskOfScents && CouplesMask && MaskOfTruth) || (BremenMask && MaskOfScents && CouplesMask && GibdosMask) || (BremenMask && MaskOfScents && CouplesMask && GarosMask) || 
			(BremenMask && MaskOfScents && CouplesMask && CaptainsHat) || (BremenMask && MaskOfScents && CouplesMask && GiantsMask) || (BremenMask && MaskOfScents && MaskOfTruth && GibdosMask) ||
			(BremenMask && MaskOfScents && MaskOfTruth && GarosMask) || (BremenMask && MaskOfScents && MaskOfTruth && CaptainsHat) || (BremenMask && MaskOfScents && MaskOfTruth && GiantsMask) || 
			(BremenMask && MaskOfScents && GibdosMask && GarosMask) || (BremenMask && MaskOfScents && GibdosMask && CaptainsHat) || (BremenMask && MaskOfScents && GibdosMask && GiantsMask) || 
			(BremenMask && MaskOfScents && GarosMask && CaptainsHat) || (BremenMask && MaskOfScents && GarosMask && GiantsMask) || (BremenMask && MaskOfScents && CaptainsHat && GiantsMask) || 
			(BremenMask && RomanisMask && CircusLeadersMask && KafeisMask) || (BremenMask && RomanisMask && CircusLeadersMask && CouplesMask) || (BremenMask && RomanisMask && CircusLeadersMask && MaskOfTruth) ||
			(BremenMask && RomanisMask && CircusLeadersMask && GibdosMask) || (BremenMask && RomanisMask && CircusLeadersMask && GarosMask) || (BremenMask && RomanisMask && CircusLeadersMask && CaptainsHat) ||
			(BremenMask && RomanisMask && CircusLeadersMask && GiantsMask) || (BremenMask && RomanisMask && KafeisMask && CouplesMask) || (BremenMask && RomanisMask && KafeisMask && MaskOfTruth) ||
			(BremenMask && RomanisMask && KafeisMask && GibdosMask) || (BremenMask && RomanisMask && KafeisMask && GarosMask) || (BremenMask && RomanisMask && KafeisMask && CaptainsHat) || 
			(BremenMask && RomanisMask && KafeisMask && GiantsMask) || (BremenMask && RomanisMask && CouplesMask && MaskOfTruth) || (BremenMask && RomanisMask && CouplesMask && GibdosMask) || 
			(BremenMask && RomanisMask && CouplesMask && GarosMask) || (BremenMask && RomanisMask && CouplesMask && CaptainsHat) || (BremenMask && RomanisMask && CouplesMask && GiantsMask) || 
			(BremenMask && RomanisMask && MaskOfTruth && GibdosMask) || (BremenMask && RomanisMask && MaskOfTruth && GarosMask) || (BremenMask && RomanisMask && MaskOfTruth && CaptainsHat) || 
			(BremenMask && RomanisMask && MaskOfTruth && GiantsMask) || (BremenMask && RomanisMask && GibdosMask && GarosMask) || (BremenMask && RomanisMask && GibdosMask && CaptainsHat) || 
			(BremenMask && RomanisMask && GibdosMask && GiantsMask) || (BremenMask && RomanisMask && GarosMask && CaptainsHat) || (BremenMask && RomanisMask && GarosMask && GiantsMask) ||
			(BremenMask && RomanisMask && CaptainsHat && GiantsMask) || (BremenMask && CircusLeadersMask && KafeisMask && CouplesMask) || (BremenMask && CircusLeadersMask && KafeisMask && MaskOfTruth) ||
			(BremenMask && CircusLeadersMask && KafeisMask && GibdosMask) || (BremenMask && CircusLeadersMask && KafeisMask && GarosMask) || (BremenMask && CircusLeadersMask && KafeisMask && CaptainsHat) ||
			(BremenMask && CircusLeadersMask && KafeisMask && GiantsMask) || (BremenMask && CircusLeadersMask && CouplesMask && MaskOfTruth) || (BremenMask && CircusLeadersMask && CouplesMask && GibdosMask) || 
			(BremenMask && CircusLeadersMask && CouplesMask && GarosMask) || (BremenMask && CircusLeadersMask && CouplesMask && CaptainsHat) || (BremenMask && CircusLeadersMask && CouplesMask && GiantsMask) ||
			(BremenMask && CircusLeadersMask && MaskOfTruth && GibdosMask) || (BremenMask && CircusLeadersMask && MaskOfTruth && GarosMask) || (BremenMask && CircusLeadersMask && MaskOfTruth && CaptainsHat) ||
			(BremenMask && CircusLeadersMask && MaskOfTruth && GiantsMask) || (BremenMask && CircusLeadersMask && GibdosMask && GarosMask) || (BremenMask && CircusLeadersMask && GibdosMask && CaptainsHat) ||
			(BremenMask && CircusLeadersMask && GibdosMask && GiantsMask) || (BremenMask && CircusLeadersMask && GarosMask && CaptainsHat) || (BremenMask && CircusLeadersMask && GarosMask && GiantsMask) || 
			(BremenMask && CircusLeadersMask && CaptainsHat && GiantsMask) || (BremenMask && KafeisMask && CouplesMask && MaskOfTruth) || (BremenMask && KafeisMask && CouplesMask && GibdosMask) ||
			(BremenMask && KafeisMask && CouplesMask && GarosMask) || (BremenMask && KafeisMask && CouplesMask && CaptainsHat) || (BremenMask && KafeisMask && CouplesMask && GiantsMask) || 
			(BremenMask && KafeisMask && MaskOfTruth && GibdosMask) || (BremenMask && KafeisMask && MaskOfTruth && GarosMask) || (BremenMask && KafeisMask && MaskOfTruth && CaptainsHat) || 
			(BremenMask && KafeisMask && MaskOfTruth && GiantsMask) || (BremenMask && KafeisMask && GibdosMask && GarosMask) || (BremenMask && KafeisMask && GibdosMask && CaptainsHat) ||
			(BremenMask && KafeisMask && GibdosMask && GiantsMask) || (BremenMask && KafeisMask && GarosMask && CaptainsHat) || (BremenMask && KafeisMask && GarosMask && GiantsMask) || 
			(BremenMask && KafeisMask && CaptainsHat && GiantsMask) || (BremenMask && CouplesMask && MaskOfTruth && GibdosMask) || (BremenMask && CouplesMask && MaskOfTruth && GarosMask) ||
			(BremenMask && CouplesMask && MaskOfTruth && CaptainsHat) || (BremenMask && CouplesMask && MaskOfTruth && GiantsMask) || (BremenMask && CouplesMask && GibdosMask && GarosMask) ||
			(BremenMask && CouplesMask && GibdosMask && CaptainsHat) || (BremenMask && CouplesMask && GibdosMask && GiantsMask) || (BremenMask && CouplesMask && GarosMask && CaptainsHat) || 
			(BremenMask && CouplesMask && GarosMask && GiantsMask) || (BremenMask && CouplesMask && CaptainsHat && GiantsMask) || (BremenMask && MaskOfTruth && GibdosMask && GarosMask) ||
			(BremenMask && MaskOfTruth && GibdosMask && CaptainsHat) || (BremenMask && MaskOfTruth && GibdosMask && GiantsMask) || (BremenMask && MaskOfTruth && GarosMask && CaptainsHat) ||
			(BremenMask && MaskOfTruth && GarosMask && GiantsMask) || (BremenMask && MaskOfTruth && CaptainsHat && GiantsMask) || (BremenMask && GibdosMask && GarosMask && CaptainsHat) || 
			(BremenMask && GibdosMask && GarosMask && GiantsMask) || (BremenMask && GibdosMask && CaptainsHat && GiantsMask) || (BremenMask && GarosMask && CaptainsHat && GiantsMask) || 
			(BunnyHood && DonGerosMask && MaskOfScents && RomanisMask) || (BunnyHood && DonGerosMask && MaskOfScents && CircusLeadersMask) || (BunnyHood && DonGerosMask && MaskOfScents && KafeisMask) ||
			(BunnyHood && DonGerosMask && MaskOfScents && CouplesMask) || (BunnyHood && DonGerosMask && MaskOfScents && MaskOfTruth) || (BunnyHood && DonGerosMask && MaskOfScents && GibdosMask) ||
			(BunnyHood && DonGerosMask && MaskOfScents && GarosMask) || (BunnyHood && DonGerosMask && MaskOfScents && CaptainsHat) || (BunnyHood && DonGerosMask && MaskOfScents && GiantsMask) || 
			(BunnyHood && DonGerosMask && RomanisMask && CircusLeadersMask) || (BunnyHood && DonGerosMask && RomanisMask && KafeisMask) || (BunnyHood && DonGerosMask && RomanisMask && CouplesMask) ||
			(BunnyHood && DonGerosMask && RomanisMask && MaskOfTruth) || (BunnyHood && DonGerosMask && RomanisMask && GibdosMask) || (BunnyHood && DonGerosMask && RomanisMask && GarosMask) || 
			(BunnyHood && DonGerosMask && RomanisMask && CaptainsHat) || (BunnyHood && DonGerosMask && RomanisMask && GiantsMask) || (BunnyHood && DonGerosMask && CircusLeadersMask && KafeisMask) || 
			(BunnyHood && DonGerosMask && CircusLeadersMask && CouplesMask) || (BunnyHood && DonGerosMask && CircusLeadersMask && MaskOfTruth) || (BunnyHood && DonGerosMask && CircusLeadersMask && GibdosMask) ||
			(BunnyHood && DonGerosMask && CircusLeadersMask && GarosMask) || (BunnyHood && DonGerosMask && CircusLeadersMask && CaptainsHat) || (BunnyHood && DonGerosMask && CircusLeadersMask && GiantsMask) || 
			(BunnyHood && DonGerosMask && KafeisMask && CouplesMask) || (BunnyHood && DonGerosMask && KafeisMask && MaskOfTruth) || (BunnyHood && DonGerosMask && KafeisMask && GibdosMask) || 
			(BunnyHood && DonGerosMask && KafeisMask && GarosMask) || (BunnyHood && DonGerosMask && KafeisMask && CaptainsHat) || (BunnyHood && DonGerosMask && KafeisMask && GiantsMask) || 
			(BunnyHood && DonGerosMask && CouplesMask && MaskOfTruth) || (BunnyHood && DonGerosMask && CouplesMask && GibdosMask) || (BunnyHood && DonGerosMask && CouplesMask && GarosMask) || 
			(BunnyHood && DonGerosMask && CouplesMask && CaptainsHat) || (BunnyHood && DonGerosMask && CouplesMask && GiantsMask) || (BunnyHood && DonGerosMask && MaskOfTruth && GibdosMask) ||
			(BunnyHood && DonGerosMask && MaskOfTruth && GarosMask) || (BunnyHood && DonGerosMask && MaskOfTruth && CaptainsHat) || (BunnyHood && DonGerosMask && MaskOfTruth && GiantsMask) || 
			(BunnyHood && DonGerosMask && GibdosMask && GarosMask) || (BunnyHood && DonGerosMask && GibdosMask && CaptainsHat) || (BunnyHood && DonGerosMask && GibdosMask && GiantsMask) ||
			(BunnyHood && DonGerosMask && GarosMask && CaptainsHat) || (BunnyHood && DonGerosMask && GarosMask && GiantsMask) || (BunnyHood && DonGerosMask && CaptainsHat && GiantsMask) ||
			(BunnyHood && MaskOfScents && RomanisMask && CircusLeadersMask) || (BunnyHood && MaskOfScents && RomanisMask && KafeisMask) || (BunnyHood && MaskOfScents && RomanisMask && CouplesMask) ||
			(BunnyHood && MaskOfScents && RomanisMask && MaskOfTruth) || (BunnyHood && MaskOfScents && RomanisMask && GibdosMask) || (BunnyHood && MaskOfScents && RomanisMask && GarosMask) ||
			(BunnyHood && MaskOfScents && RomanisMask && CaptainsHat) || (BunnyHood && MaskOfScents && RomanisMask && GiantsMask) || (BunnyHood && MaskOfScents && CircusLeadersMask && KafeisMask) ||
			(BunnyHood && MaskOfScents && CircusLeadersMask && CouplesMask) || (BunnyHood && MaskOfScents && CircusLeadersMask && MaskOfTruth) || (BunnyHood && MaskOfScents && CircusLeadersMask && GibdosMask) || 
			(BunnyHood && MaskOfScents && CircusLeadersMask && GarosMask) || (BunnyHood && MaskOfScents && CircusLeadersMask && CaptainsHat) || (BunnyHood && MaskOfScents && CircusLeadersMask && GiantsMask) ||
			(BunnyHood && MaskOfScents && KafeisMask && CouplesMask) || (BunnyHood && MaskOfScents && KafeisMask && MaskOfTruth) || (BunnyHood && MaskOfScents && KafeisMask && GibdosMask) || 
			(BunnyHood && MaskOfScents && KafeisMask && GarosMask) || (BunnyHood && MaskOfScents && KafeisMask && CaptainsHat) || (BunnyHood && MaskOfScents && KafeisMask && GiantsMask) ||
			(BunnyHood && MaskOfScents && CouplesMask && MaskOfTruth) || (BunnyHood && MaskOfScents && CouplesMask && GibdosMask) || (BunnyHood && MaskOfScents && CouplesMask && GarosMask) || 
			(BunnyHood && MaskOfScents && CouplesMask && CaptainsHat) || (BunnyHood && MaskOfScents && CouplesMask && GiantsMask) || (BunnyHood && MaskOfScents && MaskOfTruth && GibdosMask) || 
			(BunnyHood && MaskOfScents && MaskOfTruth && GarosMask) || (BunnyHood && MaskOfScents && MaskOfTruth && CaptainsHat) || (BunnyHood && MaskOfScents && MaskOfTruth && GiantsMask) ||
			(BunnyHood && MaskOfScents && GibdosMask && GarosMask) || (BunnyHood && MaskOfScents && GibdosMask && CaptainsHat) || (BunnyHood && MaskOfScents && GibdosMask && GiantsMask) || 
			(BunnyHood && MaskOfScents && GarosMask && CaptainsHat) || (BunnyHood && MaskOfScents && GarosMask && GiantsMask) || (BunnyHood && MaskOfScents && CaptainsHat && GiantsMask) || 
			(BunnyHood && RomanisMask && CircusLeadersMask && KafeisMask) || (BunnyHood && RomanisMask && CircusLeadersMask && CouplesMask) || (BunnyHood && RomanisMask && CircusLeadersMask && MaskOfTruth) || 
			(BunnyHood && RomanisMask && CircusLeadersMask && GibdosMask) || (BunnyHood && RomanisMask && CircusLeadersMask && GarosMask) || (BunnyHood && RomanisMask && CircusLeadersMask && CaptainsHat) ||
			(BunnyHood && RomanisMask && CircusLeadersMask && GiantsMask) || (BunnyHood && RomanisMask && KafeisMask && CouplesMask) || (BunnyHood && RomanisMask && KafeisMask && MaskOfTruth) ||
			(BunnyHood && RomanisMask && KafeisMask && GibdosMask) || (BunnyHood && RomanisMask && KafeisMask && GarosMask) || (BunnyHood && RomanisMask && KafeisMask && CaptainsHat) || 
			(BunnyHood && RomanisMask && KafeisMask && GiantsMask) || (BunnyHood && RomanisMask && CouplesMask && MaskOfTruth) || (BunnyHood && RomanisMask && CouplesMask && GibdosMask) ||
			(BunnyHood && RomanisMask && CouplesMask && GarosMask) || (BunnyHood && RomanisMask && CouplesMask && CaptainsHat) || (BunnyHood && RomanisMask && CouplesMask && GiantsMask) || 
			(BunnyHood && RomanisMask && MaskOfTruth && GibdosMask) || (BunnyHood && RomanisMask && MaskOfTruth && GarosMask) || (BunnyHood && RomanisMask && MaskOfTruth && CaptainsHat) || 
			(BunnyHood && RomanisMask && MaskOfTruth && GiantsMask) || (BunnyHood && RomanisMask && GibdosMask && GarosMask) || (BunnyHood && RomanisMask && GibdosMask && CaptainsHat) || 
			(BunnyHood && RomanisMask && GibdosMask && GiantsMask) || (BunnyHood && RomanisMask && GarosMask && CaptainsHat) || (BunnyHood && RomanisMask && GarosMask && GiantsMask) ||
			(BunnyHood && RomanisMask && CaptainsHat && GiantsMask) || (BunnyHood && CircusLeadersMask && KafeisMask && CouplesMask) || (BunnyHood && CircusLeadersMask && KafeisMask && MaskOfTruth) ||
			(BunnyHood && CircusLeadersMask && KafeisMask && GibdosMask) || (BunnyHood && CircusLeadersMask && KafeisMask && GarosMask) || (BunnyHood && CircusLeadersMask && KafeisMask && CaptainsHat) ||
			(BunnyHood && CircusLeadersMask && KafeisMask && GiantsMask) || (BunnyHood && CircusLeadersMask && CouplesMask && MaskOfTruth) || (BunnyHood && CircusLeadersMask && CouplesMask && GibdosMask) ||
			(BunnyHood && CircusLeadersMask && CouplesMask && GarosMask) || (BunnyHood && CircusLeadersMask && CouplesMask && CaptainsHat) || (BunnyHood && CircusLeadersMask && CouplesMask && GiantsMask) ||
			(BunnyHood && CircusLeadersMask && MaskOfTruth && GibdosMask) || (BunnyHood && CircusLeadersMask && MaskOfTruth && GarosMask) || (BunnyHood && CircusLeadersMask && MaskOfTruth && CaptainsHat) ||
			(BunnyHood && CircusLeadersMask && MaskOfTruth && GiantsMask) || (BunnyHood && CircusLeadersMask && GibdosMask && GarosMask) || (BunnyHood && CircusLeadersMask && GibdosMask && CaptainsHat) || 
			(BunnyHood && CircusLeadersMask && GibdosMask && GiantsMask) || (BunnyHood && CircusLeadersMask && GarosMask && CaptainsHat) || (BunnyHood && CircusLeadersMask && GarosMask && GiantsMask) || 
			(BunnyHood && CircusLeadersMask && CaptainsHat && GiantsMask) || (BunnyHood && KafeisMask && CouplesMask && MaskOfTruth) || (BunnyHood && KafeisMask && CouplesMask && GibdosMask) ||
			(BunnyHood && KafeisMask && CouplesMask && GarosMask) || (BunnyHood && KafeisMask && CouplesMask && CaptainsHat) || (BunnyHood && KafeisMask && CouplesMask && GiantsMask) ||
			(BunnyHood && KafeisMask && MaskOfTruth && GibdosMask) || (BunnyHood && KafeisMask && MaskOfTruth && GarosMask) || (BunnyHood && KafeisMask && MaskOfTruth && CaptainsHat) || 
			(BunnyHood && KafeisMask && MaskOfTruth && GiantsMask) || (BunnyHood && KafeisMask && GibdosMask && GarosMask) || (BunnyHood && KafeisMask && GibdosMask && CaptainsHat) || 
			(BunnyHood && KafeisMask && GibdosMask && GiantsMask) || (BunnyHood && KafeisMask && GarosMask && CaptainsHat) || (BunnyHood && KafeisMask && GarosMask && GiantsMask) ||
			(BunnyHood && KafeisMask && CaptainsHat && GiantsMask) || (BunnyHood && CouplesMask && MaskOfTruth && GibdosMask) || (BunnyHood && CouplesMask && MaskOfTruth && GarosMask) ||
			(BunnyHood && CouplesMask && MaskOfTruth && CaptainsHat) || (BunnyHood && CouplesMask && MaskOfTruth && GiantsMask) || (BunnyHood && CouplesMask && GibdosMask && GarosMask) ||
			(BunnyHood && CouplesMask && GibdosMask && CaptainsHat) || (BunnyHood && CouplesMask && GibdosMask && GiantsMask) || (BunnyHood && CouplesMask && GarosMask && CaptainsHat) || 
			(BunnyHood && CouplesMask && GarosMask && GiantsMask) || (BunnyHood && CouplesMask && CaptainsHat && GiantsMask) || (BunnyHood && MaskOfTruth && GibdosMask && GarosMask) || 
			(BunnyHood && MaskOfTruth && GibdosMask && CaptainsHat) || (BunnyHood && MaskOfTruth && GibdosMask && GiantsMask) || (BunnyHood && MaskOfTruth && GarosMask && CaptainsHat) ||
			(BunnyHood && MaskOfTruth && GarosMask && GiantsMask) || (BunnyHood && MaskOfTruth && CaptainsHat && GiantsMask) || (BunnyHood && GibdosMask && GarosMask && CaptainsHat) ||
			(BunnyHood && GibdosMask && GarosMask && GiantsMask) || (BunnyHood && GibdosMask && CaptainsHat && GiantsMask) || (BunnyHood && GarosMask && CaptainsHat && GiantsMask) ||
			(DonGerosMask && MaskOfScents && RomanisMask && CircusLeadersMask) || (DonGerosMask && MaskOfScents && RomanisMask && KafeisMask) || (DonGerosMask && MaskOfScents && RomanisMask && CouplesMask) || 
			(DonGerosMask && MaskOfScents && RomanisMask && MaskOfTruth) || (DonGerosMask && MaskOfScents && RomanisMask && GibdosMask) || (DonGerosMask && MaskOfScents && RomanisMask && GarosMask) || 
			(DonGerosMask && MaskOfScents && RomanisMask && CaptainsHat) || (DonGerosMask && MaskOfScents && RomanisMask && GiantsMask) || (DonGerosMask && MaskOfScents && CircusLeadersMask && KafeisMask) ||
			(DonGerosMask && MaskOfScents && CircusLeadersMask && CouplesMask) || (DonGerosMask && MaskOfScents && CircusLeadersMask && MaskOfTruth) || (DonGerosMask && MaskOfScents && CircusLeadersMask && GibdosMask) ||
			(DonGerosMask && MaskOfScents && CircusLeadersMask && GarosMask) || (DonGerosMask && MaskOfScents && CircusLeadersMask && CaptainsHat) || (DonGerosMask && MaskOfScents && CircusLeadersMask && GiantsMask) || 
			(DonGerosMask && MaskOfScents && KafeisMask && CouplesMask) || (DonGerosMask && MaskOfScents && KafeisMask && MaskOfTruth) || (DonGerosMask && MaskOfScents && KafeisMask && GibdosMask) || 
			(DonGerosMask && MaskOfScents && KafeisMask && GarosMask) || (DonGerosMask && MaskOfScents && KafeisMask && CaptainsHat) || (DonGerosMask && MaskOfScents && KafeisMask && GiantsMask) || 
			(DonGerosMask && MaskOfScents && CouplesMask && MaskOfTruth) || (DonGerosMask && MaskOfScents && CouplesMask && GibdosMask) || (DonGerosMask && MaskOfScents && CouplesMask && GarosMask) ||
			(DonGerosMask && MaskOfScents && CouplesMask && CaptainsHat) || (DonGerosMask && MaskOfScents && CouplesMask && GiantsMask) || (DonGerosMask && MaskOfScents && MaskOfTruth && GibdosMask) || 
			(DonGerosMask && MaskOfScents && MaskOfTruth && GarosMask) || (DonGerosMask && MaskOfScents && MaskOfTruth && CaptainsHat) || (DonGerosMask && MaskOfScents && MaskOfTruth && GiantsMask) || 
			(DonGerosMask && MaskOfScents && GibdosMask && GarosMask) || (DonGerosMask && MaskOfScents && GibdosMask && CaptainsHat) || (DonGerosMask && MaskOfScents && GibdosMask && GiantsMask) ||
			(DonGerosMask && MaskOfScents && GarosMask && CaptainsHat) || (DonGerosMask && MaskOfScents && GarosMask && GiantsMask) || (DonGerosMask && MaskOfScents && CaptainsHat && GiantsMask) ||
			(DonGerosMask && RomanisMask && CircusLeadersMask && KafeisMask) || (DonGerosMask && RomanisMask && CircusLeadersMask && CouplesMask) || (DonGerosMask && RomanisMask && CircusLeadersMask && MaskOfTruth) ||
			(DonGerosMask && RomanisMask && CircusLeadersMask && GibdosMask) || (DonGerosMask && RomanisMask && CircusLeadersMask && GarosMask) || (DonGerosMask && RomanisMask && CircusLeadersMask && CaptainsHat) || 
			(DonGerosMask && RomanisMask && CircusLeadersMask && GiantsMask) || (DonGerosMask && RomanisMask && KafeisMask && CouplesMask) || (DonGerosMask && RomanisMask && KafeisMask && MaskOfTruth) ||
			(DonGerosMask && RomanisMask && KafeisMask && GibdosMask) || (DonGerosMask && RomanisMask && KafeisMask && GarosMask) || (DonGerosMask && RomanisMask && KafeisMask && CaptainsHat) || 
			(DonGerosMask && RomanisMask && KafeisMask && GiantsMask) || (DonGerosMask && RomanisMask && CouplesMask && MaskOfTruth) || (DonGerosMask && RomanisMask && CouplesMask && GibdosMask) ||
			(DonGerosMask && RomanisMask && CouplesMask && GarosMask) || (DonGerosMask && RomanisMask && CouplesMask && CaptainsHat) || (DonGerosMask && RomanisMask && CouplesMask && GiantsMask) ||
			(DonGerosMask && RomanisMask && MaskOfTruth && GibdosMask) || (DonGerosMask && RomanisMask && MaskOfTruth && GarosMask) || (DonGerosMask && RomanisMask && MaskOfTruth && CaptainsHat) ||
			(DonGerosMask && RomanisMask && MaskOfTruth && GiantsMask) || (DonGerosMask && RomanisMask && GibdosMask && GarosMask) || (DonGerosMask && RomanisMask && GibdosMask && CaptainsHat) ||
			(DonGerosMask && RomanisMask && GibdosMask && GiantsMask) || (DonGerosMask && RomanisMask && GarosMask && CaptainsHat) || (DonGerosMask && RomanisMask && GarosMask && GiantsMask) ||
			(DonGerosMask && RomanisMask && CaptainsHat && GiantsMask) || (DonGerosMask && CircusLeadersMask && KafeisMask && CouplesMask) || (DonGerosMask && CircusLeadersMask && KafeisMask && MaskOfTruth) ||
			(DonGerosMask && CircusLeadersMask && KafeisMask && GibdosMask) || (DonGerosMask && CircusLeadersMask && KafeisMask && GarosMask) || (DonGerosMask && CircusLeadersMask && KafeisMask && CaptainsHat) ||
			(DonGerosMask && CircusLeadersMask && KafeisMask && GiantsMask) || (DonGerosMask && CircusLeadersMask && CouplesMask && MaskOfTruth) || (DonGerosMask && CircusLeadersMask && CouplesMask && GibdosMask) ||
			(DonGerosMask && CircusLeadersMask && CouplesMask && GarosMask) || (DonGerosMask && CircusLeadersMask && CouplesMask && CaptainsHat) || (DonGerosMask && CircusLeadersMask && CouplesMask && GiantsMask) ||
			(DonGerosMask && CircusLeadersMask && MaskOfTruth && GibdosMask) || (DonGerosMask && CircusLeadersMask && MaskOfTruth && GarosMask) || (DonGerosMask && CircusLeadersMask && MaskOfTruth && CaptainsHat) ||
			(DonGerosMask && CircusLeadersMask && MaskOfTruth && GiantsMask) || (DonGerosMask && CircusLeadersMask && GibdosMask && GarosMask) || (DonGerosMask && CircusLeadersMask && GibdosMask && CaptainsHat) || 
			(DonGerosMask && CircusLeadersMask && GibdosMask && GiantsMask) || (DonGerosMask && CircusLeadersMask && GarosMask && CaptainsHat) || (DonGerosMask && CircusLeadersMask && GarosMask && GiantsMask) ||
			(DonGerosMask && CircusLeadersMask && CaptainsHat && GiantsMask) || (DonGerosMask && KafeisMask && CouplesMask && MaskOfTruth) || (DonGerosMask && KafeisMask && CouplesMask && GibdosMask) ||
			(DonGerosMask && KafeisMask && CouplesMask && GarosMask) || (DonGerosMask && KafeisMask && CouplesMask && CaptainsHat) || (DonGerosMask && KafeisMask && CouplesMask && GiantsMask) || 
			(DonGerosMask && KafeisMask && MaskOfTruth && GibdosMask) || (DonGerosMask && KafeisMask && MaskOfTruth && GarosMask) || (DonGerosMask && KafeisMask && MaskOfTruth && CaptainsHat) || 
			(DonGerosMask && KafeisMask && MaskOfTruth && GiantsMask) || (DonGerosMask && KafeisMask && GibdosMask && GarosMask) || (DonGerosMask && KafeisMask && GibdosMask && CaptainsHat) ||
			(DonGerosMask && KafeisMask && GibdosMask && GiantsMask) || (DonGerosMask && KafeisMask && GarosMask && CaptainsHat) || (DonGerosMask && KafeisMask && GarosMask && GiantsMask) ||
			(DonGerosMask && KafeisMask && CaptainsHat && GiantsMask) || (DonGerosMask && CouplesMask && MaskOfTruth && GibdosMask) || (DonGerosMask && CouplesMask && MaskOfTruth && GarosMask) || 
			(DonGerosMask && CouplesMask && MaskOfTruth && CaptainsHat) || (DonGerosMask && CouplesMask && MaskOfTruth && GiantsMask) || (DonGerosMask && CouplesMask && GibdosMask && GarosMask) || 
			(DonGerosMask && CouplesMask && GibdosMask && CaptainsHat) || (DonGerosMask && CouplesMask && GibdosMask && GiantsMask) || (DonGerosMask && CouplesMask && GarosMask && CaptainsHat) || 
			(DonGerosMask && CouplesMask && GarosMask && GiantsMask) || (DonGerosMask && CouplesMask && CaptainsHat && GiantsMask) || (DonGerosMask && MaskOfTruth && GibdosMask && GarosMask) || 
			(DonGerosMask && MaskOfTruth && GibdosMask && CaptainsHat) || (DonGerosMask && MaskOfTruth && GibdosMask && GiantsMask) || (DonGerosMask && MaskOfTruth && GarosMask && CaptainsHat) || 
			(DonGerosMask && MaskOfTruth && GarosMask && GiantsMask) || (DonGerosMask && MaskOfTruth && CaptainsHat && GiantsMask) || (DonGerosMask && GibdosMask && GarosMask && CaptainsHat) ||
			(DonGerosMask && GibdosMask && GarosMask && GiantsMask) || (DonGerosMask && GibdosMask && CaptainsHat && GiantsMask) || (DonGerosMask && GarosMask && CaptainsHat && GiantsMask) || 
			(MaskOfScents && RomanisMask && CircusLeadersMask && KafeisMask) || (MaskOfScents && RomanisMask && CircusLeadersMask && CouplesMask) || (MaskOfScents && RomanisMask && CircusLeadersMask && MaskOfTruth) ||
			(MaskOfScents && RomanisMask && CircusLeadersMask && GibdosMask) || (MaskOfScents && RomanisMask && CircusLeadersMask && GarosMask) || (MaskOfScents && RomanisMask && CircusLeadersMask && CaptainsHat) ||
			(MaskOfScents && RomanisMask && CircusLeadersMask && GiantsMask) || (MaskOfScents && RomanisMask && KafeisMask && CouplesMask) || (MaskOfScents && RomanisMask && KafeisMask && MaskOfTruth) || 
			(MaskOfScents && RomanisMask && KafeisMask && GibdosMask) || (MaskOfScents && RomanisMask && KafeisMask && GarosMask) || (MaskOfScents && RomanisMask && KafeisMask && CaptainsHat) || 
			(MaskOfScents && RomanisMask && KafeisMask && GiantsMask) || (MaskOfScents && RomanisMask && CouplesMask && MaskOfTruth) || (MaskOfScents && RomanisMask && CouplesMask && GibdosMask) ||
			(MaskOfScents && RomanisMask && CouplesMask && GarosMask) || (MaskOfScents && RomanisMask && CouplesMask && CaptainsHat) || (MaskOfScents && RomanisMask && CouplesMask && GiantsMask) || 
			(MaskOfScents && RomanisMask && MaskOfTruth && GibdosMask) || (MaskOfScents && RomanisMask && MaskOfTruth && GarosMask) || (MaskOfScents && RomanisMask && MaskOfTruth && CaptainsHat) ||
			(MaskOfScents && RomanisMask && MaskOfTruth && GiantsMask) || (MaskOfScents && RomanisMask && GibdosMask && GarosMask) || (MaskOfScents && RomanisMask && GibdosMask && CaptainsHat) || 
			(MaskOfScents && RomanisMask && GibdosMask && GiantsMask) || (MaskOfScents && RomanisMask && GarosMask && CaptainsHat) || (MaskOfScents && RomanisMask && GarosMask && GiantsMask) || 
			(MaskOfScents && RomanisMask && CaptainsHat && GiantsMask) || (MaskOfScents && CircusLeadersMask && KafeisMask && CouplesMask) || (MaskOfScents && CircusLeadersMask && KafeisMask && MaskOfTruth) || 
			(MaskOfScents && CircusLeadersMask && KafeisMask && GibdosMask) || (MaskOfScents && CircusLeadersMask && KafeisMask && GarosMask) || (MaskOfScents && CircusLeadersMask && KafeisMask && CaptainsHat) ||
			(MaskOfScents && CircusLeadersMask && KafeisMask && GiantsMask) || (MaskOfScents && CircusLeadersMask && CouplesMask && MaskOfTruth) || (MaskOfScents && CircusLeadersMask && CouplesMask && GibdosMask) ||
			(MaskOfScents && CircusLeadersMask && CouplesMask && GarosMask) || (MaskOfScents && CircusLeadersMask && CouplesMask && CaptainsHat) || (MaskOfScents && CircusLeadersMask && CouplesMask && GiantsMask) ||
			(MaskOfScents && CircusLeadersMask && MaskOfTruth && GibdosMask) || (MaskOfScents && CircusLeadersMask && MaskOfTruth && GarosMask) || (MaskOfScents && CircusLeadersMask && MaskOfTruth && CaptainsHat) ||
			(MaskOfScents && CircusLeadersMask && MaskOfTruth && GiantsMask) || (MaskOfScents && CircusLeadersMask && GibdosMask && GarosMask) || (MaskOfScents && CircusLeadersMask && GibdosMask && CaptainsHat) ||
			(MaskOfScents && CircusLeadersMask && GibdosMask && GiantsMask) || (MaskOfScents && CircusLeadersMask && GarosMask && CaptainsHat) || (MaskOfScents && CircusLeadersMask && GarosMask && GiantsMask) ||
			(MaskOfScents && CircusLeadersMask && CaptainsHat && GiantsMask) || (MaskOfScents && KafeisMask && CouplesMask && MaskOfTruth) || (MaskOfScents && KafeisMask && CouplesMask && GibdosMask) ||
			(MaskOfScents && KafeisMask && CouplesMask && GarosMask) || (MaskOfScents && KafeisMask && CouplesMask && CaptainsHat) || (MaskOfScents && KafeisMask && CouplesMask && GiantsMask) ||
			(MaskOfScents && KafeisMask && MaskOfTruth && GibdosMask) || (MaskOfScents && KafeisMask && MaskOfTruth && GarosMask) || (MaskOfScents && KafeisMask && MaskOfTruth && CaptainsHat) ||
			(MaskOfScents && KafeisMask && MaskOfTruth && GiantsMask) || (MaskOfScents && KafeisMask && GibdosMask && GarosMask) || (MaskOfScents && KafeisMask && GibdosMask && CaptainsHat) || 
			(MaskOfScents && KafeisMask && GibdosMask && GiantsMask) || (MaskOfScents && KafeisMask && GarosMask && CaptainsHat) || (MaskOfScents && KafeisMask && GarosMask && GiantsMask) ||
			(MaskOfScents && KafeisMask && CaptainsHat && GiantsMask) || (MaskOfScents && CouplesMask && MaskOfTruth && GibdosMask) || (MaskOfScents && CouplesMask && MaskOfTruth && GarosMask) || 
			(MaskOfScents && CouplesMask && MaskOfTruth && CaptainsHat) || (MaskOfScents && CouplesMask && MaskOfTruth && GiantsMask) || (MaskOfScents && CouplesMask && GibdosMask && GarosMask) ||
			(MaskOfScents && CouplesMask && GibdosMask && CaptainsHat) || (MaskOfScents && CouplesMask && GibdosMask && GiantsMask) || (MaskOfScents && CouplesMask && GarosMask && CaptainsHat) || 
			(MaskOfScents && CouplesMask && GarosMask && GiantsMask) || (MaskOfScents && CouplesMask && CaptainsHat && GiantsMask) || (MaskOfScents && MaskOfTruth && GibdosMask && GarosMask) || 
			(MaskOfScents && MaskOfTruth && GibdosMask && CaptainsHat) || (MaskOfScents && MaskOfTruth && GibdosMask && GiantsMask) || (MaskOfScents && MaskOfTruth && GarosMask && CaptainsHat) ||
			(MaskOfScents && MaskOfTruth && GarosMask && GiantsMask) || (MaskOfScents && MaskOfTruth && CaptainsHat && GiantsMask) || (MaskOfScents && GibdosMask && GarosMask && CaptainsHat) || 
			(MaskOfScents && GibdosMask && GarosMask && GiantsMask) || (MaskOfScents && GibdosMask && CaptainsHat && GiantsMask) || (MaskOfScents && GarosMask && CaptainsHat && GiantsMask) || 
			(RomanisMask && CircusLeadersMask && KafeisMask && CouplesMask) || (RomanisMask && CircusLeadersMask && KafeisMask && MaskOfTruth) || (RomanisMask && CircusLeadersMask && KafeisMask && GibdosMask) ||
			(RomanisMask && CircusLeadersMask && KafeisMask && GarosMask) || (RomanisMask && CircusLeadersMask && KafeisMask && CaptainsHat) || (RomanisMask && CircusLeadersMask && KafeisMask && GiantsMask) ||
			(RomanisMask && CircusLeadersMask && CouplesMask && MaskOfTruth) || (RomanisMask && CircusLeadersMask && CouplesMask && GibdosMask) || (RomanisMask && CircusLeadersMask && CouplesMask && GarosMask) || 
			(RomanisMask && CircusLeadersMask && CouplesMask && CaptainsHat) || (RomanisMask && CircusLeadersMask && CouplesMask && GiantsMask) || (RomanisMask && CircusLeadersMask && MaskOfTruth && GibdosMask) ||
			(RomanisMask && CircusLeadersMask && MaskOfTruth && GarosMask) || (RomanisMask && CircusLeadersMask && MaskOfTruth && CaptainsHat) || (RomanisMask && CircusLeadersMask && MaskOfTruth && GiantsMask) ||
			(RomanisMask && CircusLeadersMask && GibdosMask && GarosMask) || (RomanisMask && CircusLeadersMask && GibdosMask && CaptainsHat) || (RomanisMask && CircusLeadersMask && GibdosMask && GiantsMask) ||
			(RomanisMask && CircusLeadersMask && GarosMask && CaptainsHat) || (RomanisMask && CircusLeadersMask && GarosMask && GiantsMask) || (RomanisMask && CircusLeadersMask && CaptainsHat && GiantsMask) ||
			(RomanisMask && KafeisMask && CouplesMask && MaskOfTruth) || (RomanisMask && KafeisMask && CouplesMask && GibdosMask) || (RomanisMask && KafeisMask && CouplesMask && GarosMask) || 
			(RomanisMask && KafeisMask && CouplesMask && CaptainsHat) || (RomanisMask && KafeisMask && CouplesMask && GiantsMask) || (RomanisMask && KafeisMask && MaskOfTruth && GibdosMask) || 
			(RomanisMask && KafeisMask && MaskOfTruth && GarosMask) || (RomanisMask && KafeisMask && MaskOfTruth && CaptainsHat) || (RomanisMask && KafeisMask && MaskOfTruth && GiantsMask) || 
			(RomanisMask && KafeisMask && GibdosMask && GarosMask) || (RomanisMask && KafeisMask && GibdosMask && CaptainsHat) || (RomanisMask && KafeisMask && GibdosMask && GiantsMask) ||
			(RomanisMask && KafeisMask && GarosMask && CaptainsHat) || (RomanisMask && KafeisMask && GarosMask && GiantsMask) || (RomanisMask && KafeisMask && CaptainsHat && GiantsMask) ||
			(RomanisMask && CouplesMask && MaskOfTruth && GibdosMask) || (RomanisMask && CouplesMask && MaskOfTruth && GarosMask) || (RomanisMask && CouplesMask && MaskOfTruth && CaptainsHat) || 
			(RomanisMask && CouplesMask && MaskOfTruth && GiantsMask) || (RomanisMask && CouplesMask && GibdosMask && GarosMask) || (RomanisMask && CouplesMask && GibdosMask && CaptainsHat) ||
			(RomanisMask && CouplesMask && GibdosMask && GiantsMask) || (RomanisMask && CouplesMask && GarosMask && CaptainsHat) || (RomanisMask && CouplesMask && GarosMask && GiantsMask) || 
			(RomanisMask && CouplesMask && CaptainsHat && GiantsMask) || (RomanisMask && MaskOfTruth && GibdosMask && GarosMask) || (RomanisMask && MaskOfTruth && GibdosMask && CaptainsHat) || 
			(RomanisMask && MaskOfTruth && GibdosMask && GiantsMask) || (RomanisMask && MaskOfTruth && GarosMask && CaptainsHat) || (RomanisMask && MaskOfTruth && GarosMask && GiantsMask) || 
			(RomanisMask && MaskOfTruth && CaptainsHat && GiantsMask) || (RomanisMask && GibdosMask && GarosMask && CaptainsHat) || (RomanisMask && GibdosMask && GarosMask && GiantsMask) ||
			(RomanisMask && GibdosMask && CaptainsHat && GiantsMask) || (RomanisMask && GarosMask && CaptainsHat && GiantsMask) || (CircusLeadersMask && KafeisMask && CouplesMask && MaskOfTruth) ||
			(CircusLeadersMask && KafeisMask && CouplesMask && GibdosMask) || (CircusLeadersMask && KafeisMask && CouplesMask && GarosMask) || (CircusLeadersMask && KafeisMask && CouplesMask && CaptainsHat) || 
			(CircusLeadersMask && KafeisMask && CouplesMask && GiantsMask) || (CircusLeadersMask && KafeisMask && MaskOfTruth && GibdosMask) || (CircusLeadersMask && KafeisMask && MaskOfTruth && GarosMask) || 
			(CircusLeadersMask && KafeisMask && MaskOfTruth && CaptainsHat) || (CircusLeadersMask && KafeisMask && MaskOfTruth && GiantsMask) || (CircusLeadersMask && KafeisMask && GibdosMask && GarosMask) || 
			(CircusLeadersMask && KafeisMask && GibdosMask && CaptainsHat) || (CircusLeadersMask && KafeisMask && GibdosMask && GiantsMask) || (CircusLeadersMask && KafeisMask && GarosMask && CaptainsHat) ||
			(CircusLeadersMask && KafeisMask && GarosMask && GiantsMask) || (CircusLeadersMask && KafeisMask && CaptainsHat && GiantsMask) || (CircusLeadersMask && CouplesMask && MaskOfTruth && GibdosMask) || 
			(CircusLeadersMask && CouplesMask && MaskOfTruth && GarosMask) || (CircusLeadersMask && CouplesMask && MaskOfTruth && CaptainsHat) || (CircusLeadersMask && CouplesMask && MaskOfTruth && GiantsMask) ||
			(CircusLeadersMask && CouplesMask && GibdosMask && GarosMask) || (CircusLeadersMask && CouplesMask && GibdosMask && CaptainsHat) || (CircusLeadersMask && CouplesMask && GibdosMask && GiantsMask) ||
			(CircusLeadersMask && CouplesMask && GarosMask && CaptainsHat) || (CircusLeadersMask && CouplesMask && GarosMask && GiantsMask) || (CircusLeadersMask && CouplesMask && CaptainsHat && GiantsMask) ||
			(CircusLeadersMask && MaskOfTruth && GibdosMask && GarosMask) || (CircusLeadersMask && MaskOfTruth && GibdosMask && CaptainsHat) || (CircusLeadersMask && MaskOfTruth && GibdosMask && GiantsMask) || 
			(CircusLeadersMask && MaskOfTruth && GarosMask && CaptainsHat) || (CircusLeadersMask && MaskOfTruth && GarosMask && GiantsMask) || (CircusLeadersMask && MaskOfTruth && CaptainsHat && GiantsMask) || 
			(CircusLeadersMask && GibdosMask && GarosMask && CaptainsHat) || (CircusLeadersMask && GibdosMask && GarosMask && GiantsMask) || (CircusLeadersMask && GibdosMask && CaptainsHat && GiantsMask) ||
			(CircusLeadersMask && GarosMask && CaptainsHat && GiantsMask) || (KafeisMask && CouplesMask && MaskOfTruth && GibdosMask) || (KafeisMask && CouplesMask && MaskOfTruth && GarosMask) || 
			(KafeisMask && CouplesMask && MaskOfTruth && CaptainsHat) || (KafeisMask && CouplesMask && MaskOfTruth && GiantsMask) || (KafeisMask && CouplesMask && GibdosMask && GarosMask) ||
			(KafeisMask && CouplesMask && GibdosMask && CaptainsHat) || (KafeisMask && CouplesMask && GibdosMask && GiantsMask) || (KafeisMask && CouplesMask && GarosMask && CaptainsHat) ||
			(KafeisMask && CouplesMask && GarosMask && GiantsMask) || (KafeisMask && CouplesMask && CaptainsHat && GiantsMask) || (KafeisMask && MaskOfTruth && GibdosMask && GarosMask) || 
			(KafeisMask && MaskOfTruth && GibdosMask && CaptainsHat) || (KafeisMask && MaskOfTruth && GibdosMask && GiantsMask) || (KafeisMask && MaskOfTruth && GarosMask && CaptainsHat) ||
			(KafeisMask && MaskOfTruth && GarosMask && GiantsMask) || (KafeisMask && MaskOfTruth && CaptainsHat && GiantsMask) || (KafeisMask && GibdosMask && GarosMask && CaptainsHat) || 
			(KafeisMask && GibdosMask && GarosMask && GiantsMask) || (KafeisMask && GibdosMask && CaptainsHat && GiantsMask) || (KafeisMask && GarosMask && CaptainsHat && GiantsMask) || 
			(CouplesMask && MaskOfTruth && GibdosMask && GarosMask) || (CouplesMask && MaskOfTruth && GibdosMask && CaptainsHat) || (CouplesMask && MaskOfTruth && GibdosMask && GiantsMask) || 
			(CouplesMask && MaskOfTruth && GarosMask && CaptainsHat) || (CouplesMask && MaskOfTruth && GarosMask && GiantsMask) || (CouplesMask && MaskOfTruth && CaptainsHat && GiantsMask) || 
			(CouplesMask && GibdosMask && GarosMask && CaptainsHat) || (CouplesMask && GibdosMask && GarosMask && GiantsMask) || (CouplesMask && GibdosMask && CaptainsHat && GiantsMask) ||
			(CouplesMask && GarosMask && CaptainsHat && GiantsMask) || (MaskOfTruth && GibdosMask && GarosMask && CaptainsHat) || (MaskOfTruth && GibdosMask && GarosMask && GiantsMask) || 
			(MaskOfTruth && GibdosMask && CaptainsHat && GiantsMask) || (MaskOfTruth && GarosMask && CaptainsHat && GiantsMask) || (GibdosMask && GarosMask && CaptainsHat && GiantsMask) );

		AllMasks = (PostmansHat && AllNightMask && BlastMask && StoneMask && GreatFairyMask && KeatonMask && BremenMask && BunnyHood &&
				DonGerosMask && MaskOfScents && RomanisMask && CircusLeadersMask && KafeisMask && CouplesMask && MaskOfTruth && KamarosMask &&
				GibdosMask && GarosMask && CaptainsHat && GiantsMask);
	}

	bool SmallKeys(u8 dungeonKeyCount, u8 requiredAmount) {
		return(dungeonKeyCount >= requiredAmount);
	}

	bool EventsUpdated() {
		return true;
	}
	//Resets all logic to false
	void LogicReset() {
		noVariable = false;
		//item logic
		Ocarina = true;
		KokiriSword = true;
		HasBottle = true;
		Bombchus = false;
		DekuStick = true;
		MagicBean = true;
		MagicBeanPack = true;
		LensOfTruth = false;
		HerosBow = false;
		Bow = false;
		FireArrows = false;
		IceArrows = false;
		LightArrows = false;
		Hookshot = false;
		Pictobox = true;
		PowderKeg = true;
		Epona = true;


		 PowderKeg = true;
		 Seahorse = true;
		 DekuPrincess = true;
		 BigPoe = true;
		 ZoraEgg = true;
		 Mushroom = true;
		 SpringWater = true;
		 HotSpringWater = true;
		 SpinAttack = true;
		 Epona = true;
		 WitchBottle = true;
		 AlienBottle = true;
		 GoronRaceBottle = true;
		 BeaverRaceBottle = true;
		 DampeBottle = true;
		 ChateauBottle = true;
		 BombersNotebook = true;
		 MirrorShield = false;
		 HerosShield = true;
		 RazorSword = true;
		 GildedSword = true;
		 //GretFairysMask = false;
		 BombBag20 = true;
		 TownBombBag = true;
		 MountainBombBag = true;
		 TownArcheryQuiver = true;
		 SwampArcheryQuiver = true;
		 Townwallet200 = true;
		 OceanWallet500 = true;
		 MagicPower = true;
		 ExtendedMagicPower = true;
		 GreatFairySword = true;
		 StoneTowerMagicBean = true;
		 SwampScrubMagicBean = true;
		//mask logic
		DekuMask = true;
		GoronMask = true;
		ZoraMask = true;
		KeatonMask = true;
		BunnyHood = true;
		PostmansHat = true;
		AllNightMask = true;
		BlastMask = true;
		StoneMask = true;
		GreatFairyMask = true;
		BremenMask = true;
		DonGerosMask = true;
		MaskOfScents = true;
		RomanisMask = true;
		CircusLeadersMask = true;
		KafeisMask = true;
		CouplesMask = true;
		KamarosMask = true;
		GibdosMask = true;
		GarosMask = true;
		CaptainsHat = true;
		GiantsMask = true;
		FierceDietyMask = true;
		MaskOfTruth = true;
		OneMask = true;
		TwoMasks = true;
		ThreeMasks = true;
		FourMasks = true;
		AllMasks = true;
		//trade items logic
		LandTitle = true;
		SwampTitle = true;
		MountainTitle = true;
		OceanTitle = true;
		RoomKey = true;
		LetterKafei = true;
		PendantOfMemories = true;
		LetterMama = true;
		MoonsTear = true;
		//trade quest events
		LandTitleAccess = true;
		SwampTitleAccess = true;
		MountainTitleAccess = true;
		OceanTitleAccess = true;
		RoomKeyAccess = true;
		LetterKafeiAccess = true;
		PendantAccess = true;
		LetterMamaAccess = true;
		MoonsTearAccess = true;
		//Songs
		ScarecrowSong = true;
		SongOfStorms = true;
		SonataOfAwakening = true;
		GoronsLullaby = true;
		SongOfHealing = true;
		NewWaveBossaNova = true;
		ElegyOfEmptiness = true;
		OathToOrder = true;
		EponasSong = true;
		SongOfSoaring = true;
		//Remains
		OdolwaRemains = true;
		GohtRemains = true;
		GyorgRemains = true;
		TwinmoldRemains = true;
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
		BossKeyWoodfallTemple = true;
		BossKeySnowheadTemple = true;
		BossKeyGreatBayTemple = true;
		BossKeyStoneTowerTemple = true;
		//Skulltula Counts
		SwampSkulltulaTokens = 0;
		OceanSkulltulaTokens = 0;
		//Drops & Bottle Contents Access
		DekuNutDrop = true;
		NutPot = true;
		NutCrate = true;
		DekuBabaNuts = true;
		DekuStickDrop = true;
		StickPot = true;
		DekuBabaSticks = true;
		BugsAccess = true;
		BugShrub = true;
		WanderingBugs = true;
		BugRock = true;
		FishAccess = true;
		FishGroup = true;
		LoneFish = true;
		BombchuDrop = true;
		BuyBombchus5 = true;
		BuyBombchus10 = true;
		BuyBombchus20 = true;

		//Helpers, Events, Locations
		MagicMeter = true;
		BombBag = true;
		Explosives = true;
		Scarecrow = true;
		ScarecrowSong = true;
		Bombs = true;
		Nuts = true;
		Sticks = true;
		Bugs = true;
		Fish = true;
		HasBombchus = false;
		FoundBombchus = false;
		HasExplosives = true;
		CanBlastOrSmash = true;
		CanCutShrubs = true;
		CanDive = true;
		CanPlantBugs = true;
		CanRideEpona = true;
		CanPlantBean = true;
		CanOpenBombGrotto = true;
		CanOpenStormGrotto = true;
		HasFireSource = true;
		HasFireSourceWithTorch = true;
		HasShield = true;
		CanShield = true;
		IsItem = true;
		CanShootBubble = true;
		CanUseProjectile = true;

	    Arrows = false;
		AnyBottle = true;
		AnySword = true;
		AnyBombBag = true;
		AnyMagicBean = true;
		WaterForBeans = true;
		TwoBottles = true;
		 AnyWallet = true;
		 LimitlessBeans = true;
		 AnyShield = true;
		 AnyHealingPotion = true;
		 AnyRedPotion = true;
		 AnyBluePotion = true;
		 UseFireArrow = false;
		 UseIceArrow = false;
		 UseLightArrow = false;
		 AnyBSword = true;
		//Locational Helpers
		 PoisonSwampAccess = true;
		 WoodfallTempleAccess = true;
		 WoodfallClear = false;
		 NorthAccess = true;
		 SnowheadTempleAccess = false;
		 SnowheadClear = false;
		 EponaAccess = true;
		 WestAccess = true;
		 PiratesFortressAccess = true;
		 GreatBayTempleAccess = true;
		 GreatBayClear = false;
		 EastAccess = true;
		 IkanaCanyonAccess = true;
		 StoneTowerTempleAcccess = true;
		 InvertedStoneTowerTempleAccess = true;
		 StoneTowerClear = false;
		 MoonAccess = true;
		 OneWoodfallKey = true;
		 OneGreatBayKey = true;
		 OneSnowheadKey = true;
		 TwoSnowheadKeys = true;
		 OneStoneTowerKey = true;
		 TwoStoneTowerKeys = true;
		 ThreeStoneTowerKeys = true;
		 SwampSpiderhouseTreeRoom = true;
		 OceanSkulltulas = true;
		 IkanaGraveyardAccess = true;
		 FightTwinmold = true;
		 PinnacleRockAccess = true;
		 ExitOceanSpiderHouse = true;
		 NightInnAccess = true;
		 EnterSnowheadTemple = false;
		 GBTReverseWaterDirection = true;
		 Fighting = true;
		 CrossPoisonWater = true;
		 AccessToAllOceanSpiders = true;
		 AccessToAllSwampSpiders = true;
		 ClockTownStrayFairy = true;
		 AllWoodfallStrays = true;
		 AllSnowheadStrays = true;
		 AllGreatBayStrays = true;
		 AllStoneTowerStrays = true;
		 AnyPaper = true;
		//Tricks
		 DekuStickFighting = true;
		 PoisonWaterAsZora = true;
		 WFT2ndFloorSkip = true;
		 ExitOceanSpiderHouse = true;
		 TakeDamage = true;


		//placement tracking
		AddedProgressiveBombBags = 0;
		AddedProgressiveMagics = 0;
		AddedProgressiveBows = 0;
		AddedProgressiveWallets = 0;
		SwampTokensInPool = 0;
		OceanTokensInPool = 0;
	}
}

