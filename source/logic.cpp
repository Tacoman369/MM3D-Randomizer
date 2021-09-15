#include "logic.hpp"

#include <3ds.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <string_view>
#include <vector>

#include "settings.hpp"
#include "dungeon.hpp"
#include "setting_descriptions.hpp"

using namespace Settings;

namespace Logic {
	bool noVariable			=false;
	//item Logic	
	bool KokiriSword		=false;
	bool Bombchus			=false;
	bool Bombchus5			=false;
	bool Bombchus10			=false;
	bool Bombchus20			=false;
	bool MagicBean			=false;
	bool MagicBeanPack		=false;
	bool LensOfTruth		=false;
	bool MirrorShield		=false;
	bool BombersNotebook	=false;
	bool RoomKey			=false;
	bool KafeiLetter		=false;
	bool PendantMemories	=false;
	bool LetterMama			=false;
	bool SpinAttack			=false;
	bool FireArrows			=false;
	bool IceArrows			=false;
	bool LightArrows		=false;
	bool Hookshot			=false;
	bool OcarinaOfTime		=true;
	bool PictographBox		=false;
	bool PowderKeg			=false;
	bool Epona			=false;
	
	//Masks
	bool KeatonMask			=false;
	bool BunnyHood			=false;
	bool GoronMask			=false;
	bool DekuMask			=false;
	bool ZoraMask			=false;
	bool Postmanshat		=false;
	bool AllNightMssk		=false;
	bool BlastMask			=false;
	bool StoneMask			=false;
	bool GreatFairyMask		=false;
	bool BremenMask			=false;
	bool DonGerosMask		=false;
	bool ScentsMask			=false;
	bool RomaniMask			=false;
	bool CircusMask			=false;
	bool KafeiMask			=false;
	bool CoupleMask			=false;
	bool KamaroMaask		=false;
	bool GibdoMask			=false;
	bool GaroMask			=false;
	bool CaptainHat			=false;
	bool GiantsMask			=false;
	bool FierceMask			=false;
	bool MaskofTruth		=false;
	
	//Trading
	bool MoonsTear			=false;
	bool LandTitle			=false;
	bool SwampTitle			=false;
	bool MountainTitle		=false;
	bool OceanTitle			=false;
	
	//Songs
	bool SongOfTime			=true;
	bool InvertedSongOfTime	=true;
	bool SongOfDoubleTime	=true;
	bool SongOfHealing		=false;
	bool SongOfSoaring		=false;
	bool SonataOfAwakening  =false;
	bool GoronLullaby		=false;
	bool NewWaveBossaNova	=false;
	bool ElegyOfEmptiness	=false;
	bool OathToOrder		=false;
	bool EponasSong			=false;
	bool SongOfStorms		=false;
	
	//Boss Remains
	bool OdolwasRemains		=false;
	bool GohtsRemains		=false;
	bool GyorgsRemains		=false;
	bool TwinmoldsRemains	=false;
	
	//Dungeon Clears
	bool WoodfallClear		=false;
	bool SnowheadClear		=false;
	bool GreatBayClear		=false;
	bool StoneTowerClear	=false;
	
	//Progressive Items
	u8 ProgressiveSword		=0;
	u8 ProgressiveBombBag	=0;
	u8 ProgressiveMagic		=0;
	u8 ProgressiveWallet	=0;
	u8 ProgressiveBow		=0;
	
	//Logical KeySanity
	bool IsKeysanity		=false;
	
	//Keys
	u8 WoodfallTempleKeys	=0;
	u8 SnowheadTempleKeys	=0;
	u8 GreatBayTempleKeys	=0;
	u8 StoneTowerTempleKeys	=0;
	
	//Boos Keys
	bool BossKeyWoodfallTemple	=0;
	bool BossKeySnowheadTemple	=0;
	bool BossKeyGreatBayTemple	=0;
	bool BossKeyStoneTowerTemple=0;
	
	//Skulltula Counts
	u8 SwampSkulltulaTokens		=0;
	u8 OceansideSkulltulaTokens	=0;
	
	//Stray Fairies
	u8 ClockStray				=0;
	u8 WoodfallStrays			=0;
	u8 SnowheadStrays			=0;
	u8 GreatBayStrays			=0;
	u8 StoneTowerStrays			=0;
	
	//Drops and Bottle Contents Access
	bool DekuNutDrop      = false;
	bool NutPot           = false;
	bool NutCrate         = false;
	bool DekuBabaNuts     = false;
	bool BugsAccess       = false;
	bool BugShrub         = false;
	bool WanderingBugs    = false;
	bool BugRock          = false;
	bool FishAccess       = false;
	bool FishGroup        = false;
	bool LoneFish         = false;
	bool FairyAccess      = false;
	bool GossipStoneFairy = false;
	bool BeanPlantFairy   = false;
	bool ButterflyFairy   = false;
	bool FairyPot         = false;
	bool FreeFairies      = false;
	bool FairyPond        = false;
	bool BombchuDrop      = false;
	bool AmmoCanDrop      = false;
	bool BuyBombchus5     = false;
	bool BuyBombchus10    = false;
	bool BuyBombchus20    = false;
	bool BuySeed          = false;
	bool BuyArrow         = false;
	bool BuyBomb          = false;
	bool BuyGPotion       = false;
	bool BuyBPotion       = false;
	bool MagicRefill      = false;
	
	
	//Helpers, Evevnts, Location Access
	bool Bow			=false;
	bool BombBag		=false;
	bool MagicMeter		=false;
	bool Hookshot		=false;
	bool AdultsWallet	=false;
	bool ScarecrowSong	=false;
	bool Scarecrow		=false;
	bool Bombs			=false;
	bool HerosShield	=false;
	bool Nuts			=false;
	bool Bugs			=false;
	bool Fish			=false;
	bool Fairy			=false;
	bool BottleWithBigPoe=false;
	bool DekuPrincess	=false;
	bool HotSpringWater	=false;
	bool SpringWater	=false;
	bool GoldDust		=false;
	bool ZoraEgg		=false;
	bool Seahorse		=false;
	
	bool HasBombchus	=false;
	bool FoundBombchus	=false;
	bool HasExplosives	=false;
	bool CanBlastOrSmash=false;
	bool CanAttack		=false;
	bool CanCutShrubs	=false;
	bool CanDive		=false;
	bool CanPlantBugs	=false;
	bool CanStunDeku	=false;
	bool CanRideEpona	=false;
	bool CanTakeDamage	=false;
	bool CanOpenBombGrotto=false;
	bool CanOpenStormGrotto=false;
	bool CanGetStrayFairy =false;
	bool GuaranteeHint	=false;
	bool HasFireSource	=false;
	bool HasShield		=false;
	bool CanShield		=false;
	bool CanJumpslash	=false;
	bool CanUseProjectile =false;
	bool IsUsable		=false;
	bool CanGoToMoon	=false;
	
	//Moon Requirements
	u8 RemainsCount		=0;
	u8 DungeonCount		=0;
	bool HasAllRemains	=false;
	
	//END OF HELPERS & LOCATION ACCESS
	
	//Placement Tracking
	u8 AddedProgressiveBombBags	=0;
	u8 AddedProgressiveMagics	=0;
	u8 AddedProgressiveBows		=0;
	u8 AddedProgressiveWallets	=0;
	u8 AddedProgressiveSwords	=0;
	u8 SwampTokensInPool		=0;
	u8 OceanTokensInPool		=0;
	
	bool CanPlay(bool song)
	{
		return OcarinaOfTime && song;
	}
	
	static bool IsMagicItem(ItemKey item) 
	{
		return  item == SPIN_ATTACK ||
				item == LENS_OF_TRUTH ;
	}
	
	static bool IsMagicArrow(ItemKey item)
	{
		return  item == FIRE_ARROWS ||
				item == ICE_ARROWS ||
				item == LIGHT_ARROWS;
	}
	
	static bool IsItem(ItemKey item) 
	{
		return  item == SPIN_ATTACK 	||
				item == LENS_OF_TRUTH   ||
			    item == BOW				||
		   	    item == HOOKSHOT		||
			    item == SCARECROW		||
			    item == KOKIRI_SWORD	||
			    item == HEROS_SHIELD	||
			    item == DEKU_MASK		||
			    item == ZORA_MASK		||
			    item == GORON_MASK		||
			    item == FIRE_ARROWS		||
			    item == ICE_ARROWS		||
			    item == LIGHT_ARROWS;
	}
	
	bool HasItem(ItemKey itemName) 
	{
		return (itemName == SPIN_ATTACK		&& SpinAttack)  ||
			   (itemName == LENS_OF_TRUTH	&& LensOfTruth)	||
			   (itemName == BOW				&& Bow)			||
			   (itemName == HOOKSHOT		&& Hookshot)	||
			   (itemName == SCARECROW		&& Scarecrow) 	||
			   (itemName == KOKIRI_SWORD	&& KokiriSword)	||
			   (itemName == HEROS_SHIELD	&& HerosShield) ||
			   (itemName == DEKU_MASK		&& DekuMask)	||
			   (itemName == ZORA_MASK		&& ZoraMask) 	||
			   (itemName == GORON_MASK		&& GoronMask)	||
			   (itemName == FIRE_ARROWS		&&FireArrows)	||
			   (itemName == ICE_ARROWS		&& IceArrows)	||
			   (itemName == LIGHT_ARROWS	&& LightArrows);
	}
	//can the passed in item be used?
	bool CanUse(ItemKey itemName) 
	{
		return  (IsMagicItem(itemName) && HasItem(itemName) && MagicMeter) ||
				(IsMagicArrow(itemName) && HasItem(itemName) && MagicMeter && Bow) ||
				(IsItem(itemName) && HasItem(itemName && IsUsable);
	}
	
	bool HasProjectile(DoHasProjectile link) 
	{
		return HasExplosives ||
				(link == DoHasProjectile && (Hookshot || Bow ));
	}
	
    u8 GetDifficultyValueFromString(Option& glitchOption) {
    for (size_t i = 0; i < GlitchDifficulties.size(); i++) {
      if (glitchOption.GetSelectedOptionText() == GlitchDifficulties[i]) {
        return i + 1;
      }
    }
    return 0;
   }
   //TO-DO get list of MM3D Glitches 
	bool CanDoGlitch(GlitchType glitch, GlitchDifficulty difficulty) {
    u8 setDifficulty;
    switch (glitch) {
    //Infinite Sword Glitch
    case GlitchType::ISG:
      setDifficulty = GetDifficultyValueFromString(GlitchISG);
      if (setDifficulty < static_cast<u8>(difficulty)) {
        return false;
      }
      return HasShield && (IsAdult || (IsChild && (KokiriSword || Sticks)));
    //Bomb Hover
    case GlitchType::BombHover:
      setDifficulty = GetDifficultyValueFromString(GlitchHover);
      if (setDifficulty < static_cast<u8>(difficulty)) {
        return false;
      }
      return CanDoGlitch(GlitchType::ISG, GlitchDifficulty::NOVICE) && (HasBombchus || (Bombs && setDifficulty >= static_cast<u8>(GlitchDifficulty::ADVANCED)));
    //Megaflip
    case GlitchType::Megaflip:
      setDifficulty = GetDifficultyValueFromString(GlitchMegaflip);
      if (setDifficulty < static_cast<u8>(difficulty)) {
        return false;
      }
      return HasShield && Bombs;
    //Hookshot Clip
    case GlitchType::HookshotClip:
      setDifficulty = GetDifficultyValueFromString(GlitchHookshotClip);
      if (setDifficulty < static_cast<u8>(difficulty)) {
        return false;
      }
      return IsAdult && Hookshot;
    //Hookshot Jump: Bonk
    case GlitchType::HookshotJump_Bonk:
      setDifficulty = GetDifficultyValueFromString(GlitchHookshotJump_Bonk);
      if (setDifficulty < static_cast<u8>(difficulty)) {
        return false;
      }
      return IsAdult && Hookshot;
    //Hookshot Jump: Boots
    case GlitchType::HookshotJump_Boots:
      setDifficulty = GetDifficultyValueFromString(GlitchHookshotJump_Boots);
      if (setDifficulty < static_cast<u8>(difficulty)) {
        return false;
      }
      return IsAdult && Hookshot && (IronBoots || HoverBoots);
    //Ledge Clip
    case GlitchType::LedgeClip:
      setDifficulty = GetDifficultyValueFromString(GlitchLedgeClip);
      if (setDifficulty < static_cast<u8>(difficulty)) {
        return false;
      }
      return IsAdult;
    //Triple Slash Clip
    case GlitchType::TripleSlashClip:
      setDifficulty = GetDifficultyValueFromString(GlitchTripleSlashClip);
      if (setDifficulty < static_cast<u8>(difficulty)) {
        return false;
      }
      return IsAdult || (IsChild && KokiriSword);
    }
    //Shouldn't be reached
    return false;
  }
  
  //Updates all logic helpers. Should be called whenever a non-helper is changed
  void UpdateHelpers() 
  {
	  Bow			= (ProgressiveBow		>=1) &&  (BuyArrow || AmmoCanDrop);
	  MagicMeter	= (ProgressiveMagic		>=1) &&	 (AmmoCanDrop || (HasBottle && (BuyGPotion || BuyBPotion)));
	  BombBag		= (ProgressiveBombBag	>=1) &&	 (BuyBomb	||	AmmoCanDrop);
	  AdultsWallet	= ProgressiveWallet		>=1;
	  Sword			= (ProgressiveSword		>=1) &&	 (CanCutShrubs || CanJumpslash);
	  
	  Scarecrow		= Hookshot && CanPlay(ScarecrowSong);
	  
	  //Drop Access
	  DekuNutDrop 	= (NutPot || NutCrate		||	DekuBabaNuts) && AmmoCanDrop;
	  BugsAccess	= BugShrub || WanderingBugs || BugRock;
	  FishAccess	= LoneFish || FishGroup;
	  FairyAccess	= FairyPot || GossipStoneFairy || BeanPlantFairy || ButterflyFairy || FreeFairies || FairyPond;
	  
	  //Refills
	  Bombs			= BombBag;
	  Nuts			= DekuNutDrop || Nuts;
	  Bugs			= HasBottle && BugsAccess;
	  Fish 			= HasBottle && FishAccess;
	  Fairy			= HasBottle && FairyAccess;
	  
	  HasBombchus	= (BuyBombchus5 || BuyBombchus10 || BuyBombchus20 || AmmoDrops.Is(AMMODROPS_BOMBCHU)) && FoundBombchus;
	  FoundBombchus	= (Bombchus || Bombchus5 || Bombchus10 || Bombchus20)) || (!BombchusInLogic && BombBag);
	  HasExplosives = Bombs || HasBombchus;
	  
	  CanBlastOrSmash = HasExplosives;
	  CanAttack		  = (Bow || Hookshot || KokiriSword || HasExplosives);
	  CanStunDeku	  = (Bow || KokiriSword || HasExplosives || Nuts || HerosShield);
	  CanDive		  = ZoraMask;
	  CanPlantBugs	  = Bugs;
	  CanRideEpona	  = Epona && CanPlay(EponasSong);
	  CanTakeDamage	  = DamageMultiplier.IsNot(DAMAGEMULTIPLIER_OHKO) || DamageMultiplier.IsNot(DAMAGEMULTIPLIER_OCTUPLE) || DamageMultiplier.IsNot(DAMAGEMULTIPLIER_SEXDECUPLE) || Fairy;
	  CanOpenBombGrotto = CanBlastOrSmash;
	  CanOpenStormGrotto = CanPlay(SongOfStorms);
	  CanGetStrayFairy = GreatFairyMask;
	  HasFireSource	  = CanUse(FIRE_ARROWS);
	  
	  HasShield		  = HerosShield || MirrorShield;
	  CanShield		  = HerosShield || MirrorShield;
	  CanJumpslash	  = KokiriSword;
	  CanUseProjectile = HasExplosives || Bow || Hookshot;
	  
	  RemainsCount = (OdolwasRemains ? 1:0) + (GohtsRemains ? 1:0) + (GyorgsRemains ? 1:0) + (TwinmoldsRemains ? 1:0);
	  DungeonCount = (WoodfallClear ? 1:0) + (SnowheadClear ? 1:0) + (GreatBayClear ? 1:0) + (StoneTowerClear ? 1:0);
	  
	  HasAllRemains = RemainsCount == 4;
	  
	  CanGoToMoon = HasAllRemains;
  }
  
  bool SmallKeys(u8 dungeonKeyCount, u8 requiredAmount) {
	  return (dungeonKeyCount >= requiredAmount);
  }
  
  bool EventsUpdated() 
  {
	  //used to check events
  }
  
  //Reset ALL Logic to false
  void LogicReset()
  {
	  KokiriSword		=false;
	  Bombchus			=false;
	  Bombchus5			=false;
	  Bombchus10		=false;
	  Bombchus20		=false;
	  MagicBean			=false;
	  MagicBeanPack		=false;
	  LensOfTruth		=false;
	  MirrorShield		=false;
	  BombersNotebook	=false;
	  RoomKey			=false;
	  KafeiLetter		=false;
	  PendantMemories	=false;
	  LetterMama		=false;
	  SpinAttack		=false;
	  FireArrows		=false;
	  IceArrows			=false;
	  LightArrows		=false;
	  Hookshot			=false;
	  OcarinaOfTime		=true;
	  PictographBox		=false;
	  PowderKeg			=false;
	  Epona				=false;
	
	//Masks
	  KeatonMask		=false;
	  BunnyHood			=false;
	  GoronMask			=false;
	  DekuMask			=false;
	  ZoraMask			=false;
	  Postmanshat		=false;
	  AllNightMssk		=false;
	  BlastMask			=false;
	  StoneMask			=false;
	  GreatFairyMask	=false;
	  BremenMask		=false;
	  DonGerosMask		=false;
	  ScentsMask		=false;
	  RomaniMask		=false;
	  CircusMask		=false;
	  KafeiMask			=false;
	  CoupleMask		=false;
	  KamaroMaask		=false;
	  GibdoMask			=false;
	  GaroMask			=false;
	  CaptainHat		=false;
	  GiantsMask		=false;
	  FierceMask		=false;
	  MaskofTruth		=false;
	
	//Trading
	  MoonsTear			=false;
	  LandTitle			=false;
	  SwampTitle		=false;
	  MountainTitle		=false;
	  OceanTitle		=false;
	
	//Songs
	  SongOfTime		=true;
	  InvertedSongOfTime=true;
	  SongOfDoubleTime	=true;
	  SongOfHealing		=false;
	  SongOfSoaring		=false;
	  SonataOfAwakening =false;
	  GoronLullaby		=false;
	  NewWaveBossaNova	=false;
	  ElegyOfEmptiness	=false;
	  OathToOrder		=false;
	  EponasSong		=false;
	  SongOfStorms		=false;
	
	//Boss Remains
	  OdolwasRemains	=false;
	  GohtsRemains		=false;
	  GyorgsRemains		=false;
	  TwinmoldsRemains	=false;
	
	//Dungeon Clears
	  WoodfallClear		=false;
	  SnowheadClear		=false;
	  GreatBayClear		=false;
	  StoneTowerClear	=false;
	
	//Progressive Items
	  ProgressiveSword		=0;
	  ProgressiveBombBag	=0;
	  ProgressiveMagic		=0;
	  ProgressiveWallet		=0;
	  ProgressiveBow		=0;
	
	//Logical KeySanity
	  IsKeysanity		=false;
	
	//Keys
	  WoodfallTempleKeys	=0;
	  SnowheadTempleKeys	=0;
	  GreatBayTempleKeys	=0;
	  StoneTowerTempleKeys	=0;
	
	//Boos Keys
	  BossKeyWoodfallTemple	=0;
	  BossKeySnowheadTemple	=0;
	  BossKeyGreatBayTemple	=0;
	  BossKeyStoneTowerTemple=0;
	
	//Skulltula Counts
	  SwampSkulltulaTokens		=0;
	  OceansideSkulltulaTokens	=0;
	
	//Stray Fairies
	  ClockStray				=0;
	  WoodfallStrays			=0;
	  SnowheadStrays			=0;
	  GreatBayStrays			=0;
	  StoneTowerStrays			=0;
	
	//Drops and Bottle Contents Access
	  DekuNutDrop      = false;
	  NutPot           = false;
	  NutCrate         = false;
	  DekuBabaNuts     = false;
	  BugsAccess       = false;
	  BugShrub         = false;
	  WanderingBugs    = false;
	  BugRock          = false;
	  FishAccess       = false;
	  FishGroup        = false;
	  LoneFish         = false;
	  FairyAccess      = false;
	  GossipStoneFairy = false;
	  BeanPlantFairy   = false;
	  ButterflyFairy   = false;
	  FairyPot         = false;
	  FreeFairies      = false;
	  FairyPond        = false;
	  BombchuDrop      = false;
	  AmmoCanDrop      = false;
	  BuyBombchus5     = false;
	  BuyBombchus10    = false;
	  BuyBombchus20    = false;
	  BuySeed          = false;
	  BuyArrow         = false;
	  BuyBomb          = false;
	  BuyGPotion       = false;
	  BuyBPotion       = false;
	  MagicRefill      = false;
	
	
	//Helpers, Evevnts, Location Access
	  Bow			=false;
	  BombBag		=false;
	  MagicMeter	=false;
	  Hookshot		=false;
	  AdultsWallet	=false;
	  ScarecrowSong	=false;
	  Scarecrow		=false;
	  Bombs			=false;
	  HerosShield	=false;
	  Nuts			=false;
	  Bugs			=false;
	  Fish			=false;
	  Fairy			=false;
	  BottleWithBigPoe=false;
	  DekuPrincess	=false;
	  HotSpringWater=false;
	  SpringWater	=false;
	  GoldDust		=false;
	  ZoraEgg		=false;
	  Seahorse		=false;
	
	  HasBombchus	=false;
	  FoundBombchus	=false;
	  HasExplosives	=false;
	  CanBlastOrSmash=false;
	  CanAttack		=false;
	  CanCutShrubs	=false;
	  CanDive		=false;
	  CanPlantBugs	=false;
	  CanStunDeku	=false;
	  CanRideEpona	=false;
	  CanTakeDamage	=false;
	  CanOpenBombGrotto=false;
	  CanOpenStormGrotto=false;
	  CanGetStrayFairy =false;
	  GuaranteeHint	=false;
	  HasFireSource	=false;
	  HasShield		=false;
	  CanShield		=false;
	  CanJumpslash	=false;
	  CanUseProjectile =false;
	  IsUsable		=false;
	  CanGoToMoon	=false;
	
	//Moon Requirements
	  RemainsCount		=0;
	  DungeonCount		=0;
	  HasAllRemains	=false;
	
	//END OF HELPERS & LOCATION ACCESS
	
	//Placement Tracking
	  AddedProgressiveBombBags	=0;
	  AddedProgressiveMagics	=0;
	  AddedProgressiveBows		=0;
	  AddedProgressiveWallets	=0;
	  AddedProgressiveSwords	=0;
	  SwampTokensInPool			=0;
	  OceanTokensInPool			=0;
  }
  
}