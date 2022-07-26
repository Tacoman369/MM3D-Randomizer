#include <string>
#include <array>
#include <vector>
#include <string_view>
#include <algorithm>
#include <3ds.h>
#include <cstdio>

#include "settings.hpp"
#include "logic.hpp"
#include "setting_descriptions.hpp"
#include "keys.hpp"

using namespace Settings;

namespace Logic {

	bool noVariable = false;
	//item logic
	bool Ocarina = true;
	bool KokiriSword = true;
	bool HasBottle = false;
	bool Bombchus = false;
	bool DekuStick = true;
	bool MagicBean = false;
	bool MagicBeanPack = false;
	bool LensOfTruth = false;
	bool Bow = false;
	bool HerosBow = false;
	bool FireArrows = false;
	bool IceArrows = false;
	bool LightArrows = false;
	bool Hookshot = false;
	bool Pictobox = false;
	bool PowderKeg = false;
	bool Seahorse = false;
	bool DekuPrincess = false;
	bool BigPoe = true;
	bool ZoraEgg = true;
	bool Mushroom = true;
	bool SpringWater = true;
	bool HotSpringWater = false;
	bool SpinAttack = true;
	bool Epona = false;
	bool WitchBottle = false;
	bool AlienBottle = false;
	bool GoronRaceBottle = false;
	bool BeaverRaceBottle = false;
	bool DampeBottle = false;
	bool ChateauBottle = false;
	bool BombersNotebook = true;
	bool MirrorShield = false;
	bool HerosShield = true;
	bool RazorSword = true;
	bool GildedSword = true;
	//bool GretFairysMask = false;
	bool BombBag20 = false;
	bool TownBombBag = false;
	bool MountainBombBag = false;
	bool TownArcheryQuiver = false;
	bool SwampArcheryQuiver = false;
	bool Townwallet200 = false;
	bool OceanWallet500 = false;
	bool MagicPower = true;
	bool ExtendedMagicPower = true;
	bool GreatFairySword = false;
	bool StoneTowerMagicBean = false;
	bool SwampScrubMagicBean = false;
	bool AllZoraEggs = false;
	//mask logic
	bool DekuMask = true;
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
	bool OneMask = true;
	bool TwoMasks = true;
	bool ThreeMasks = false;
	bool FourMasks = false;
	bool AllMasks = false;
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
	bool ScarecrowSong = true;
	bool SongOfStorms = false;
	bool SonataOfAwakening = false;
	bool SongOfHealing = true;
	bool GoronsLullaby = false;
	bool NewWaveBossaNova = false;
	bool ElegyOfEmptiness = false;
	bool OathToOrder = false;
	bool EponasSong = false;
	bool SongOfSoaring = false;
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
	bool BombchuDrop = false;
	bool BuyBombchus5 = false;
	bool BuyBombchus10 = false;
	bool BuyBombchus20 = false;
	bool Water = false;
	bool WaterAccess = false;
	bool HotSpringWaterAccess = false;
	//Helpers, Events, Locations
	bool MagicMeter = true;
	bool BombBag = false;
	bool Explosives = false;
	bool Scarecrow = true;
	bool Bombs = false;
	bool Nuts = true;
	bool Sticks = true;
	bool Bugs = true;
	bool Fish = true;
	bool HasBombchus = false;
	bool FoundBombchus = false;
	bool HasExplosives = false;
	bool CanBlastOrSmash = false;
	bool CanCutShrubs = true;
	bool CanDive = false;
	bool CanPlantBugs = true;
	bool CanRideEpona = false;
	bool CanPlantBean = false;
	bool CanOpenBombGrotto = true;
	bool CanOpenStormGrotto = false;
	bool HasFireSource = false;
	bool HasFireSourceWithTorch = true;
	bool HasShield = true;
	bool CanShield = true;
	bool IsItem = true;
	bool CanShootBubble = true;
	bool CanUseProjectile = false;
	bool Arrows = false;
	bool AnyBottle = true;
	bool AnySword = true;
	bool AnyBombBag = true;
	bool AnyMagicBean = false;
	bool WaterForBeans = false;
	bool TwoBottles = false;
	bool AnyWallet = false;
	bool LimitlessBeans = false;
	bool AnyShield = true;
	bool AnyHealingPotion = false;
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
	bool CrossPoisonWater = true;
	bool AccessToAllOceanSpiders = false;
	bool AccessToAllSwampSpiders = false;
	bool ClockTownStrayFairy = true;
	bool AllWoodfallStrays = false;
	bool AllSnowheadStrays = false;
	bool AllGreatBayStrays = false;
	bool AllStoneTowerStrays = false;
	bool AnyPaper = false;
	//Tricks
	bool DekuStickFighting = true;
	bool PoisonWaterAsZora = false;
	bool WFT2ndFloorSkip = false;
	bool TakeDamage = true;

	//NewHelpers
	bool SHSwitchPress = false;
	bool ReverseWaterFlow = false;
	bool RedSwitch = false;
	bool RedSwitch2 = false;
	bool GreenSwitch = false;
	bool GreenSwitch2 = false;
	bool GreenValve = false;
	bool PirateBees = false;
	bool MusicBoxOn = false;
	bool IkanaLightSwitch = false;
	bool IkanaCastleRoofHole = false;
	bool ArmosRoomLightHole = false;
	bool InvertedChestSpawn = false;
	bool EnterSakonHideout = false;
	bool AtDay = false;
	bool AtNight = false;
	u8 Day =0;
	bool IsDay1Day = false;
	bool IsDay2Day = false;
	bool IsDay3Day = false;
	bool IsDay1Night = false;
	bool IsDay2Night = false;
	bool IsDay3Night = false;

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

	static bool IsMagicItem(ItemKey item) {
		return item == LENS_OF_TRUTH || 
		       item == GIANTS_MASK;
	}

	static bool IsMagicArrow(ItemKey item) {
		return item == FIRE_ARROWS ||
			item == ICE_ARROWS ||
			item == LIGHT_ARROWS;
	}
	static bool IsItemOrMask(ItemKey item) {
		return (item == KOKIRI_SWORD) ||
			(item == DEKU_STICK) ||
			(item == LENS_OF_TRUTH) ||
			(item == HEROS_BOW) ||
			(item == SCARECROW) ||
			(item == FIRE_ARROWS) ||
			(item == ICE_ARROWS) ||
			(item == LIGHT_ARROWS) ||
			(item == DEKU_STICK) ||
			(item == PICTOGRAPH_BOX) ||
			(item == POWDER_KEG) ||
			(item == DEKU_MASK) ||
			(item == GORON_MASK) ||
			(item == ZORA_MASK) ||
			(item == BLAST_MASK) ||
			(item == GREAT_FAIRYS_MASK) ||
			(item == POSTMANS_HAT) ||
			(item == ALL_NIGHT_MASK) ||
			(item == BREMEN_MASK) ||
			(item == DON_GEROS_MASK) ||
			(item == MASK_OF_SCENTS) ||
			(item == ROMANIS_MASK) ||
			(item == CIRCUS_LEADERS_MASK) ||
			(item == KAFEIS_MASK) ||
			(item == KAFEIS_MASK) ||
			(item == COUPLES_MASK) ||
			(item == GIBDOS_MASK) ||
			(item == GAROS_MASK) ||
			(item == CAPTAINS_HAT) ||
			(item == GIANTS_MASK) ||
			(item == FIERCE_DIETY_MASK) ||
			(item == MASK_OF_TRUTH);
	}
	static bool HasItem(ItemKey itemName) {
		return (itemName == KOKIRI_SWORD && KokiriSword) ||
			(itemName == LENS_OF_TRUTH && LensOfTruth) ||
			(itemName == HEROS_BOW && Bow) ||
			(itemName == DEKU_STICK && DekuStick)||
			(itemName == SCARECROW && Scarecrow) ||
			(itemName == FIRE_ARROWS && FireArrows) ||
			(itemName == ICE_ARROWS && IceArrows) ||
			(itemName == LIGHT_ARROWS && LightArrows) ||
			(itemName == DEKU_STICK && Sticks) ||
			(itemName == PICTOGRAPH_BOX && Pictobox) ||
			(itemName == POWDER_KEG && PowderKeg) ||
			(itemName == DEKU_MASK && DekuMask) ||
			(itemName == GORON_MASK && GoronMask) ||
			(itemName == ZORA_MASK && ZoraMask) ||
			(itemName == BLAST_MASK && BlastMask) ||
			(itemName == GREAT_FAIRYS_MASK && GreatFairyMask) ||
			(itemName == POSTMANS_HAT && PostmansHat) ||
			(itemName == ALL_NIGHT_MASK && AllNightMask) ||
			(itemName == BREMEN_MASK && BremenMask) ||
			(itemName == DON_GEROS_MASK && DonGerosMask) ||
			(itemName == MASK_OF_SCENTS && MaskOfScents) ||
			(itemName == ROMANIS_MASK && RomanisMask) ||
			(itemName == CIRCUS_LEADERS_MASK && CircusLeadersMask) ||
			(itemName == KAFEIS_MASK && KafeisMask) ||
			(itemName == KAMAROS_MASK && KamarosMask) ||
			(itemName == COUPLES_MASK && CouplesMask) ||
			(itemName == GIBDOS_MASK && GibdosMask) ||
			(itemName == GAROS_MASK && GarosMask) ||
			(itemName == CAPTAINS_HAT && CaptainsHat) ||
			(itemName == GIANTS_MASK && GiantsMask) ||
			(itemName == FIERCE_DIETY_MASK && FierceDietyMask) ||
			(itemName == MASK_OF_TRUTH && MaskOfTruth);
	}

	bool CanUse(ItemKey itemName) {
		return (IsMagicItem(itemName) && HasItem(itemName) && MagicMeter) ||
			(IsMagicArrow(itemName) && HasItem(itemName) && MagicMeter && Bow) ||
			(IsItemOrMask(itemName) && HasItem(itemName));
	}

	bool HasProjectile(ItemKey itemName) {
		return (IsItemOrMask(itemName) && HasItem(itemName) && Bow);
	}

	bool SmallKeys(u8 dungeonKeyCount, u8 requiredAmount) {
		return (dungeonKeyCount >= requiredAmount);
	}

	void UpdateHelpers() {
		//Drop Access
		DekuStickDrop = StickPot || DekuBabaSticks;
		DekuNutDrop = NutPot || NutCrate || DekuBabaNuts;
		BugsAccess = BugShrub || WanderingBugs || BugRock;
		FishAccess = LoneFish || FishGroup;
		WaterAccess = SpringWater || CanPlay(SongOfStorms);
		HotSpringWaterAccess = HotSpringWater;
		WaterForBeans = (CanUse(BOTTLE_WITH_RED_POTION) && WaterAccess) || SongOfStorms;
		AnyMagicBean = (MagicBean || MagicBeanPack || LimitlessBeans);
		//refills
		Bombs = AnyBombBag;
		Nuts = DekuNutDrop || Nuts;
		Sticks = DekuStickDrop || Sticks;
		Bugs = HasBottle && BugsAccess;
		Fish = HasBottle && FishAccess;
		//Seahorse = CanUse(PICTOGRAPH_BOX) && CanPlay(EponasSong) && CanUse(ZORA_MASK);
		
		//Other Helpers
		CanBlastOrSmash = HasExplosives || CanUse(GORON_MASK);
		CanDive = CanUse(ZORA_MASK);
		CanPlantBugs = HasBottle && BugsAccess;
		CanRideEpona = Epona && CanPlay(EponasSong);
		CanPlantBean = AnyMagicBean || MagicBeanPack;
		CanOpenStormGrotto = CanPlay(SongOfStorms);
		CanOpenBombGrotto = CanBlastOrSmash;
		DekuStickFighting = CanUse(DEKU_STICK);
		HasFireSource = CanUse(FIRE_ARROWS);
		HasFireSourceWithTorch = CanUse(DEKU_STICK);
		AnySword = CanUse(GREAT_FAIRYS_SWORD) || AnyBSword;
		AnyBSword = CanUse(KOKIRI_SWORD) || CanUse(RAZOR_SWORD) || CanUse(GILDED_SWORD);
		NightInnAccess = CanUse(DEKU_MASK) || RoomKey;
		Fighting = CanUse(GORON_MASK) || CanUse(ZORA_MASK) || AnySword || DekuStickFighting;
		AnyShield = CanUse(HEROS_SHIELD) || CanUse(MIRROR_SHIELD);
		CanUseProjectile = HasExplosives || CanUse(HEROS_BOW);
		//WoodfallClear = CanPlay(SonataOfAwakening) && CanUse(DEKU_MASK) && CanUse(HEROS_BOW) && WoodfallTempleKeys>=1 && BossKeyWoodfallTemple && AnySword;
		//SnowheadClear = CanPlay(GoronsLullaby) && CanUse(FIRE_ARROWS) && CanUse(GORON_MASK) && MagicMeter && HasExplosives && SnowheadTempleKeys>=3 && BossKeySnowheadTemple && AnySword;
		//GreatBayClear = CanPlay(NewWaveBossaNova) && CanUse(ICE_ARROWS) && CanUse(ZORA_MASK) && MagicMeter && CanUse(HOOKSHOT) && GreatBayTempleKeys>=1 && BossKeyGreatBayTemple;
		//StoneTowerClear = CanPlay(ElegyOfEmptiness) && CanUse(LIGHT_ARROWS) && CanUse(ZORA_MASK) && CanUse(GORON_MASK) && CanUse(DEKU_MASK) && CanUse(GIANTS_MASK) && StoneTowerTempleKeys>=4 && BossKeyStoneTowerTemple && AnySword;
		//Item Helpers
		//AnyMagicBean = MagicBean || StoneTowerMagicBean || SwampScrubMagicBean || (DekuMask && PoisonSwampAccess);
		AnyWallet = Townwallet200 || OceanWallet500;
		//LimitlessBeans = PoisonSwampAccess && DekuMask;
		HasBottle = AnyBottle;
		MagicMeter = (ProgressiveMagic >= 1) || MagicPower || ExtendedMagicPower;
		//WaterForBeans = (AnyBottle && (SpringWater || HotSpringWater)) || SongOfStorms;
		Scarecrow = Hookshot && CanPlay(ScarecrowSong);
		AnyPaper = (LandTitle || SwampTitle || OceanTitle || MountainTitle || LetterKafei || LetterMama);
		
		//Bombs & Bombchus
		AnyBombBag = (ProgressiveBombBag >= 1) || BombBag20 || TownBombBag || MountainBombBag;
		//AnyBombBag = BombBag20 || TownBombBag || MountainBombBag || BombBag;
		Explosives = BlastMask || AnyBombBag;
		HasBombchus = (BuyBombchus5 || BuyBombchus10 || BuyBombchus20) && AnyBombBag;
		FoundBombchus = Bombchus;
		HasExplosives = Bombs || BlastMask;
		//Bow & Arrows
		Bow = (ProgressiveBow >= 1) || HerosBow;
		Arrows = Bow || TownArcheryQuiver || SwampArcheryQuiver;
		//UseFireArrow = Arrows && FireArrows && MagicMeter;
		//UseIceArrow = Arrows && IceArrows && MagicMeter;
		//UseLightArrow = Arrows && LightArrows && MagicMeter;
		//Bottle Items
		AnyBottle = WitchBottle || AlienBottle || BeaverRaceBottle || DampeBottle || GoronRaceBottle || ChateauBottle;
		DekuPrincess = WoodfallClear && AnyBottle;
		BigPoe = IkanaCanyonAccess && GibdosMask && AnyBottle && AnyBombBag;
		//HotSpringWater = NorthAccess && AnyBottle && (SnowheadClear || UseFireArrow);
		//SpringWater = AnyBottle;
		ZoraEgg = PiratesFortressAccess && Hookshot && AnyBottle && PinnacleRockAccess && ((DekuMask && MagicMeter) || Arrows);
		AllZoraEggs = CanUse(ZORA_MASK) && CanUse(HOOKSHOT) && AnyBottle && Seahorse && CanUse(DEKU_MASK) && MagicMeter;
		Mushroom = MaskOfScents && AnyBottle;
		AnyHealingPotion = AnyRedPotion || AnyBluePotion;
		AnyRedPotion = AnyBottle;
		AnyBluePotion = AnyBottle;
		TwoBottles = { (WitchBottle && AlienBottle) || (WitchBottle && BeaverRaceBottle) || (WitchBottle && DampeBottle) ||
			(WitchBottle && GoronRaceBottle) || (WitchBottle && ChateauBottle) || (AlienBottle && GoronRaceBottle) ||
			(AlienBottle && BeaverRaceBottle) || (AlienBottle && DampeBottle) || (AlienBottle && ChateauBottle) ||
			(GoronRaceBottle && BeaverRaceBottle) || (GoronRaceBottle && DampeBottle) || (GoronRaceBottle && ChateauBottle) ||
			(BeaverRaceBottle && DampeBottle) || (BeaverRaceBottle && ChateauBottle) || (DampeBottle && ChateauBottle) };
		//Location Logic Shortened
		//Swamp Logic Helpers
		PoisonSwampAccess = CrossPoisonWater;
		CrossPoisonWater = HasItem(DEKU_MASK);//DekuMask;
		AccessToAllSwampSpiders = PoisonSwampAccess && Bugs && MagicMeter && Fighting && HasItem(HOOKSHOT);
		WoodfallTempleAccess = CanPlay(SonataOfAwakening) && PoisonSwampAccess && Fighting;
		//WoodfallClear = WoodfallTempleAccess && Arrows && BossKeyWoodfallTemple;
		SwampSpiderhouseTreeRoom = PoisonSwampAccess;
		//Snowhead Logic Helpers
		EnterSnowheadTemple = NorthAccess && HasItem(GORON_MASK) && MagicMeter;
		NorthAccess = HasExplosives && Bow;
		SnowheadTempleAccess = NorthAccess && HasItem(GORON_MASK) && MagicMeter && CanPlay(GoronsLullaby);
		//SnowheadClear = SnowheadTempleAccess && BossKeySnowheadTemple && GoronMask && UseFireArrow;
		//Great Bay Logic Helpers
		WestAccess = EponasSong;
		PiratesFortressAccess = WestAccess && ZoraMask;
		GreatBayTempleAccess = PiratesFortressAccess && NewWaveBossaNova && Hookshot;
		GBTReverseWaterDirection = UseIceArrow;
		//GreatBayClear = GreatBayTempleAccess && BossKeyGreatBayTemple && ZoraMask && Hookshot && UseIceArrow;
		PinnacleRockAccess = ZoraMask && (Seahorse && AnyBottle);
		OceanSkulltulas = Explosives && WestAccess && ExitOceanSpiderHouse && Hookshot;
		AccessToAllOceanSpiders = OceanSkulltulas && UseFireArrow;
		ExitOceanSpiderHouse = GoronMask;
		//Ikana Logic Helpers
		EastAccess = Hookshot && IkanaGraveyardAccess && GarosMask;
		IkanaGraveyardAccess = EponasSong;
		IkanaCanyonAccess = EastAccess && UseIceArrow;
		StoneTowerTempleAcccess = IkanaCanyonAccess && Hookshot && ElegyOfEmptiness && ZoraMask && GoronMask && DekuMask;
		InvertedStoneTowerTempleAccess = StoneTowerTempleAcccess && UseLightArrow;
		//StoneTowerClear = InvertedStoneTowerTempleAccess && Hookshot && BossKeyStoneTowerTemple && GiantsMask && UseLightArrow;
		FightTwinmold = GiantsMask && AnySword && UseLightArrow;
		//Other Logic Helpers
		EponaAccess = GoronMask && PowderKeg;
		MoonAccess = StoneTowerClear && GreatBayClear && SnowheadClear && WoodfallClear;
		//Temple Keys
		OneSnowheadKey = SnowheadTempleKeys == 1;
		TwoSnowheadKeys = SnowheadTempleKeys == 2;
		OneStoneTowerKey = StoneTowerTempleKeys == 1;
		TwoStoneTowerKeys = StoneTowerTempleKeys == 2;
		ThreeStoneTowerKeys = StoneTowerTempleKeys == 3;
		OneWoodfallKey = WoodfallTempleKeys == 1;
		OneGreatBayKey = GreatBayTempleKeys == 1;
		//Stray Fairy Rewards
		AllWoodfallStrays = WoodfallClear;
		AllSnowheadStrays = SnowheadClear;
		AllGreatBayStrays = GreatBayClear;
		AllStoneTowerStrays = StoneTowerClear;
		//Tricks
		PoisonWaterAsZora = ZoraMask && TakeDamage;
		WFT2ndFloorSkip = Hookshot;
		//Mask helpers
		OneMask = (PostmansHat || AllNightMask || BlastMask || StoneMask || GreatFairyMask || KeatonMask || BremenMask || BunnyHood ||
			DonGerosMask || MaskOfScents || RomanisMask || CircusLeadersMask || KafeisMask || CouplesMask || MaskOfTruth || KamarosMask ||
			GibdosMask || GarosMask || CaptainsHat || GiantsMask);
		TwoMasks = true;
		ThreeMasks = true;
		FourMasks=true;
		AllMasks = (PostmansHat && AllNightMask && BlastMask && StoneMask && GreatFairyMask && KeatonMask && BremenMask && BunnyHood &&
				DonGerosMask && MaskOfScents && RomanisMask && CircusLeadersMask && KafeisMask && CouplesMask && MaskOfTruth && KamarosMask &&
				GibdosMask && GarosMask && CaptainsHat && GiantsMask);
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
	  MagicBean = false;
	  MagicBeanPack = false;
	  LensOfTruth = false;
	  Bow = false;
	  HerosBow = false;
	  FireArrows = false;
	  IceArrows = false;
	  LightArrows = false;
	  Hookshot = false;
	  Pictobox = false;
	  PowderKeg = false;
	  Seahorse = false;
	  DekuPrincess = false;
	  BigPoe = false;
	  ZoraEgg = true;
	  Mushroom = false;
	  SpringWater = false;
	  HotSpringWater = false;
	  SpinAttack = true;
	  Epona = false;
	  WitchBottle = true;
	  AlienBottle = false;
	  GoronRaceBottle = false;
	  BeaverRaceBottle = false;
	  DampeBottle = false;
	  ChateauBottle = false;
	  BombersNotebook = true;
	  MirrorShield = false;
	  HerosShield = true;
	  RazorSword = true;
	  GildedSword = true;
	//  GretFairysMask = false;
	  BombBag20 = true;
	  TownBombBag = false;
	  MountainBombBag = false;
	  TownArcheryQuiver = false;
	  SwampArcheryQuiver = false;
	  Townwallet200 = false;
	  OceanWallet500 = false;
	  MagicPower = true;
	  ExtendedMagicPower = true;
	  GreatFairySword = false;
	  StoneTowerMagicBean = false;
	  SwampScrubMagicBean = false;

	//mask logic
	  DekuMask = true;
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
	  OneMask = true;
	  TwoMasks = true;
	  ThreeMasks = false;
	  FourMasks = false;
	  AllMasks = false;
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
	  ScarecrowSong = true;
	  SongOfStorms = false;
	  SonataOfAwakening = false;
	  SongOfHealing = true;
	  GoronsLullaby = false;
	  NewWaveBossaNova = false;
	  ElegyOfEmptiness = false;
	  OathToOrder = false;
	  EponasSong = false;
	  SongOfSoaring = false;
	//Remains
	  OdolwaRemains = false;
	  GohtRemains = false;
	  GyorgRemains = false;
	  TwinmoldRemains = false;
	//Progressive Items
	//u8 ProgressiveBow = 0;
	//u8 ProgressiveMagic = 0;
	//u8 ProgressiveWallet = 0;
	//u8 ProgressiveBombBag = 0;
	//Keys
	//u8 WoodfallTempleKeys = 0;
	//u8 SnowheadTempleKeys = 0;
	//u8 GreatBayTempleKeys = 0;
	//u8 StoneTowerTempleKeys = 0;
	//Boss Keys
	  BossKeyWoodfallTemple = false;
	  BossKeySnowheadTemple = false;
	  BossKeyGreatBayTemple = false;
	  BossKeyStoneTowerTemple = false;
	//Skulltula Counts
	//u8 SwampSkulltulaTokens = 0;
	//u8 OceanSkulltulaTokens = 0;
	//Stray Fairies
	//u8 WoodfallStrayFairies = 0;
	//u8 SnowheadStrayFairies = 0;
	//u8 GBTStrayFairies = 0;
	//u8 StoneTowerStrayFairies = 0;
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
	  BombchuDrop = false;
	  BuyBombchus5 = false;
	  BuyBombchus10 = false;
	  BuyBombchus20 = false;
      Water = false;
	  WaterAccess = false;
	  HotSpringWaterAccess = false;
	//Helpers, Events, Locations
	  MagicMeter = true;
	  BombBag = true;
	  Explosives = true;
	  Scarecrow = true;
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
	  CanDive = false;
	  CanPlantBugs = true;
	  CanRideEpona = false;
	  CanPlantBean = false;
	  CanOpenBombGrotto = true;
	  CanOpenStormGrotto = false;
	  HasFireSource = false;
	  HasFireSourceWithTorch = true;
	  HasShield = true;
	  CanShield = true;
	  IsItem = true;
	  CanShootBubble = true;
	  CanUseProjectile = false;
	  Arrows = false;
	  AnyBottle = true;
	  AnySword = true;
	  AnyBombBag = true;
	  AnyMagicBean = false;
	  WaterForBeans = false;
	  TwoBottles = false;
	  AnyWallet = false;
	  LimitlessBeans = false;
	  AnyShield = true;
	  AnyHealingPotion = false;
	  AnyRedPotion = true;
	  AnyBluePotion = true;
	  UseFireArrow = false;
	  UseIceArrow = false;
	  UseLightArrow = false;
	  AnyBSword = true;
	  AllZoraEggs = false;
	//dungeon clears
	  WoodfallClear = false;
	  SnowheadClear = false;
	  GreatBayClear = false;
	  StoneTowerClear = false;
	//Locational Helpers
	  PoisonSwampAccess = true;
	  WoodfallTempleAccess = true;
	  NorthAccess = false;
	  SnowheadTempleAccess = false;
	  EponaAccess = false;
	  WestAccess = false;
	  PiratesFortressAccess = false;
	  GreatBayTempleAccess = false;
	  EastAccess = false;
	  IkanaCanyonAccess = false;
	  StoneTowerTempleAcccess = false;
	  InvertedStoneTowerTempleAccess = false;
	  MoonAccess = false;
	  OneWoodfallKey = false;
	  OneSnowheadKey = false;
	  TwoSnowheadKeys = false;
	  OneGreatBayKey = false;
	  OneStoneTowerKey = false;
	  TwoStoneTowerKeys = false;
	  ThreeStoneTowerKeys = false;
	  SwampSpiderhouseTreeRoom = false;
	  OceanSkulltulas = false;
	  IkanaGraveyardAccess = false;
	  FightTwinmold = false;
	  PinnacleRockAccess = false;
	  ExitOceanSpiderHouse = false;
	  NightInnAccess = false;
	  EnterSnowheadTemple = false;
	  GBTReverseWaterDirection = false;
	  Fighting = true;
	  CrossPoisonWater = true;
	  AccessToAllOceanSpiders = false;
	  AccessToAllSwampSpiders = false;
	  ClockTownStrayFairy = true;
	  AllWoodfallStrays = false;
	  AllSnowheadStrays = false;
	  AllGreatBayStrays = false;
	  AllStoneTowerStrays = false;
	  AnyPaper = false;
	//Tricks
	  DekuStickFighting = true;
	  PoisonWaterAsZora = false;
	  WFT2ndFloorSkip = false;
	  TakeDamage = true;

	//New Things
	SHSwitchPress = false;
	ReverseWaterFlow = false;
	RedSwitch = false;
	RedSwitch2 = false;
	GreenSwitch = false;
	GreenSwitch2 = false;
	GreenValve = false;
	PirateBees = false;
	MusicBoxOn = false;
	IkanaLightSwitch = false;
	IkanaCastleRoofHole = false;
	ArmosRoomLightHole = false;
	InvertedChestSpawn = false;
	EnterSakonHideout = false;

	AtDay = false;
	AtNight = false;
	Day =0;
	IsDay1Day = false;
	IsDay2Day = false;
	IsDay3Day = false;
	IsDay1Night = false;
	IsDay2Night = false;
	IsDay3Night = false;
	//placement tracking
	//u8 AddedProgressiveBombBags = 0;
	//u8 AddedProgressiveMagics = 0;
	//u8 AddedProgressiveBows = 0;
	//u8 AddedProgressiveWallets = 0;
	//u8 SwampTokensInPool = 0;
	//u8 OceanTokensInPool = 0;
	//u8 WFStraysInPool = 0;
	//u8 SHStraysInPool = 0;
	//u8 STStraysInPool = 0;
	//u8 PlacedMasks = 0;
	}
}

