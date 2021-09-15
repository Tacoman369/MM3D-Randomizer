#pragma once

#include <3ds.h>

#include "keys.hpp"

namespace Logic {
	extern bool noVariable			=false;
	//item Logic	
	extern bool KokiriSword		=false;
	extern bool Bombchus			=false;
	extern bool Bombchus5			=false;
	extern bool Bombchus10			=false;
	extern bool Bombchus20			=false;
	extern bool MagicBean			=false;
	extern bool MagicBeanPack		=false;
	extern bool LensOfTruth		=false;
	extern bool MirrorShield		=false;
	extern bool BombersNotebook	=false;
	extern bool RoomKey			=false;
	extern bool KafeiLetter		=false;
	extern bool PendantMemories	=false;
	extern bool LetterMama			=false;
	extern bool SpinAttack			=false;
	extern bool FireArrows			=false;
	extern bool IceArrows			=false;
	extern bool LightArrows		=false;
	extern bool Hookshot			=false;
	extern bool OcarinaOfTime		=true;
	extern bool PictographBox		=false;
	extern bool PowderKeg			=false;
	extern bool Epona			=false;
	
	//Masks
	extern bool KeatonMask			=false;
	extern bool BunnyHood			=false;
	extern bool GoronMask			=false;
	extern bool DekuMask			=false;
	extern bool ZoraMask			=false;
	extern bool Postmanshat		=false;
	extern bool AllNightMssk		=false;
	extern bool BlastMask			=false;
	extern bool StoneMask			=false;
	extern bool GreatFairyMask		=false;
	extern bool BremenMask			=false;
	extern bool DonGerosMask		=false;
	extern bool ScentsMask			=false;
	extern bool RomaniMask			=false;
	extern bool CircusMask			=false;
	extern bool KafeiMask			=false;
	extern bool CoupleMask			=false;
	extern bool KamaroMaask		=false;
	extern bool GibdoMask			=false;
	extern bool GaroMask			=false;
	extern bool CaptainHat			=false;
	extern bool GiantsMask			=false;
	extern bool FierceMask			=false;
	extern bool MaskofTruth		=false;
	
	//Trading
	extern bool MoonsTear			=false;
	extern bool LandTitle			=false;
	extern bool SwampTitle			=false;
	extern bool MountainTitle		=false;
	extern bool OceanTitle			=false;
	
	//Songs
	extern bool SongOfTime			=true;
	extern bool InvertedSongOfTime	=true;
	extern bool SongOfDoubleTime	=true;
	extern bool SongOfHealing		=false;
	extern bool SongOfSoaring		=false;
	extern bool SonataOfAwakening  =false;
	extern bool GoronLullaby		=false;
	extern bool NewWaveBossaNova	=false;
	extern bool ElegyOfEmptiness	=false;
	extern bool OathToOrder		=false;
	extern bool EponasSong			=false;
	extern bool SongOfStorms		=false;
	
	//Boss Remains
	extern bool OdolwasRemains		=false;
	extern bool GohtsRemains		=false;
	extern bool GyorgsRemains		=false;
	extern bool TwinmoldsRemains	=false;
	
	//Dungeon Clears
	extern bool WoodfallClear		=false;
	extern bool SnowheadClear		=false;
	extern bool GreatBayClear		=false;
	extern bool StoneTowerClear	=false;
	
	//Progressive Items
	extern u8 ProgressiveSword		=0;
	extern u8 ProgressiveBombBag	=0;
	extern u8 ProgressiveMagic		=0;
	extern u8 ProgressiveWallet	=0;
	extern u8 ProgressiveBow		=0;
	
	//Logical KeySanity
	extern bool IsKeysanity		=false;
	
	//Keys
	extern u8 WoodfallTempleKeys	=0;
	extern u8 SnowheadTempleKeys	=0;
	extern u8 GreatBayTempleKeys	=0;
	extern u8 StoneTowerTempleKeys	=0;
	
	//Boos Keys
	extern bool BossKeyWoodfallTemple	=0;
	extern bool BossKeySnowheadTemple	=0;
	extern bool BossKeyGreatBayTemple	=0;
	extern bool BossKeyStoneTowerTemple=0;
	
	//Skulltula Counts
	extern u8 SwampSkulltulaTokens		=0;
	extern u8 OceansideSkulltulaTokens	=0;
	
	//Stray Fairies
	extern u8 ClockStray				=0;
	extern u8 WoodfallStrays			=0;
	extern u8 SnowheadStrays			=0;
	extern u8 GreatBayStrays			=0;
	extern u8 StoneTowerStrays			=0;
	
	//Drops and Bottle Contents Access
	extern bool DekuNutDrop      = false;
	extern bool NutPot           = false;
	extern bool NutCrate         = false;
	extern bool DekuBabaNuts     = false;
	extern bool BugsAccess       = false;
	extern bool BugShrub         = false;
	extern bool WanderingBugs    = false;
	extern bool BugRock          = false;
	extern bool FishAccess       = false;
	extern bool FishGroup        = false;
	extern bool LoneFish         = false;
	extern bool FairyAccess      = false;
	extern bool GossipStoneFairy = false;
	extern bool BeanPlantFairy   = false;
	extern bool ButterflyFairy   = false;
	extern bool FairyPot         = false;
	extern bool FreeFairies      = false;
	extern bool FairyPond        = false;
	extern bool BombchuDrop      = false;
	extern bool AmmoCanDrop      = false;
	extern bool BuyBombchus5     = false;
	extern bool BuyBombchus10    = false;
	extern bool BuyBombchus20    = false;
	extern bool BuySeed          = false;
	extern bool BuyArrow         = false;
	extern bool BuyBomb          = false;
	extern bool BuyGPotion       = false;
	extern bool BuyBPotion       = false;
	extern bool MagicRefill      = false;
	
	
	//Helpers, Evevnts, Location Access
	extern bool Bow			=false;
	extern bool BombBag		=false;
	extern bool MagicMeter		=false;
	extern bool Hookshot		=false;
	extern bool AdultsWallet	=false;
	extern bool ScarecrowSong	=false;
	extern bool Scarecrow		=false;
	extern bool Bombs			=false;
	extern bool HerosShield	=false;
	extern bool Nuts			=false;
	extern bool Bugs			=false;
	extern bool Fish			=false;
	extern bool Fairy			=false;
	extern bool BottleWithBigPoe=false;
	extern bool DekuPrincess	=false;
	extern bool HotSpringWater	=false;
	extern bool SpringWater	=false;
	extern bool GoldDust		=false;
	extern bool ZoraEgg		=false;
	extern bool Seahorse		=false;
	
	extern bool HasBombchus	=false;
	extern bool FoundBombchus	=false;
	extern bool HasExplosives	=false;
	extern bool CanBlastOrSmash=false;
	extern bool CanAttack		=false;
	extern bool CanCutShrubs	=false;
	extern bool CanDive		=false;
	extern bool CanPlantBugs	=false;
	extern bool CanStunDeku	=false;
	extern bool CanRideEpona	=false;
	extern bool CanTakeDamage	=false;
	extern bool CanOpenBombGrotto=false;
	extern bool CanOpenStormGrotto=false;
	extern bool CanGetStrayFairy =false;
	extern bool GuaranteeHint	=false;
	extern bool HasFireSource	=false;
	extern bool HasShield		=false;
	extern bool CanShield		=false;
	extern bool CanJumpslash	=false;
	extern bool CanUseProjectile =false;
	extern bool IsUsable		=false;
	extern bool CanGoToMoon	=false;
	
	//Moon Requirements
	extern u8 RemainsCount		=0;
	extern u8 DungeonCount		=0;
	extern bool HasAllRemains	=false;
	
	//END OF HELPERS & LOCATION ACCESS
	
	//Placement Tracking
	extern u8 AddedProgressiveBombBags	=0;
	extern u8 AddedProgressiveMagics	=0;
	extern u8 AddedProgressiveBows		=0;
	extern u8 AddedProgressiveWallets	=0;
	extern u8 AddedProgressiveSwords	=0;
	extern u8 SwampTokensInPool		=0;
	extern u8 OceanTokensInPool		=0;
	
	enum class HasProjectile { 
		Both,
		Either,
	};

	enum class GlitchType {
		  ISG,
		BombHover,
		Megaflip,
		HookshotClip,
		HookshotJump_Bonk,
		HookshotJump_Boots,
		LedgeClip,
		TripleSlashClip,
	 };

	enum class GlitchDifficulty {
		NOVICE = 1,
		INTERMEDIATE,
		ADVANCED,
		EXPERT,
		HERO,
	};

	void UpdateHelpers();
	bool CanPlay(bool song);
	bool CanUse(ItemKey itemName);
	bool HasProjectile(HasProjectileAge age);
	bool SmallKeys(u8 dungeonKeyCount, u8 requiredAmount);
	bool SmallKeys_ShadowTemple(u8 dungeonKeyCount, u8 requiredAmountGlitchless, u8 requiredAmountGlitched);
	bool CanDoGlitch(GlitchType glitch, GlitchDifficulty difficulty);
	bool EventsUpdated();
	void LogicReset();
}
