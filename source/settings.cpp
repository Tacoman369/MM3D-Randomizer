#include "settings.hpp"

#include <unistd.h>

#include "cosmetics.hpp"
#include "dungeon.hpp"
#include "fill.hpp"
#include "item_location.hpp"
#include "music.hpp"
#include "random.hpp"
#include "randomizer.hpp"
#include "setting_descriptions.hpp"
#include "trial.hpp"
#include "keys.hpp"

using namespace Cosmetics;
using namespace Dungeon;
using namespace Trial;
using namespace Music;

namespace Settings {
  std::string seed;
  std::string version = RANDOMIZER_VERSION "-" COMMIT_NUMBER;
  std::array<u8, 5> hashIconIndexes;

  //                                        Setting name,              Options,                                                                     Setting Descriptions (assigned in setting_descriptions.cpp)                                                 Category (default: Setting),Default index (default: 0), Default hidden (default: false)
  //Open Settings                                                                                                                                   Any option index past the last description will use the last description
 //World Settings
  Option RandomizeWorld            = Option::Bool("Randomize Settings",     {"No","Yes"},                                                      {worldRandomize},                                                                                                OptionCategory::Toggle);
  Option ShuffleEntrances          = Option::Bool("Shuffle Entrances",      {"Off", "On"},                                                     {shuffleEntrancesDesc});
  Option ShuffleDungeonEntrances   = Option::Bool("  Dungeon Entrances",    {"Off", "On"},                                                     {dungeonEntrancesDesc});
  Option ShuffleOverworldEntrances = Option::Bool("  Overworld Entrances",  {"Off", "On"},                                                     {overworldEntrancesDesc});
  Option BombchusInLogic           = Option::Bool("Bombchus in Logic",      {"Off", "On"},                                                     {bombchuLogicDesc});
  Option AmmoDrops                 = Option::U8  ("Ammo Drops",             {"On", "On + Bombchu", "Off"},                                     {defaultAmmoDropsDesc, bombchuDropsDesc, noAmmoDropsDesc},                                                       OptionCategory::Setting,    AMMODROPS_VANILLA);
  Option HeartDropRefill           = Option::U8  ("Heart Drops and Refills",{"On", "No Drop", "No Refill", "Off"},                             {defaultHeartDropsDesc, noHeartDropsDesc, noHeartRefillDesc, scarceHeartsDesc},                                  OptionCategory::Setting,    HEARTDROPREFILL_VANILLA);
  std::vector<Option *> worldOptions = {
    &RandomizeWorld,
    &ShuffleEntrances,
    &ShuffleDungeonEntrances,
    &ShuffleOverworldEntrances,
    &BombchusInLogic,
    &AmmoDrops,
    &HeartDropRefill,
  };

  //Shuffle Settings
  Option RandomizeShuffle       = Option::Bool("Randomize Settings",     {"No","Yes"},                                                      {shuffleRandomize},                                                                                                    OptionCategory::Toggle);
  Option ShuffleRewards         = Option::U8  ("Shuffle Dungeon Rewards",{"End of Dungeons", "Any Dungeon", "Overworld", "Anywhere"},       {shuffleRewardsEndOfDungeon, shuffleRewardsAnyDungeon, shuffleRewardsOverworld, shuffleRewardsAnywhere});
  Option LinksPocketItem        = Option::U8  ("Link's Pocket",          {"Dungeon Reward", "Advancement", "Anything", "Nothing"},          {linksPocketDungeonReward, linksPocketAdvancement, linksPocketAnything, linksPocketNothing});
  Option ShuffleSongs           = Option::U8  ("Shuffle Songs",          {"Song Locations", "Dungeon Rewards", "Anywhere"},                 {songsSongLocations, songsDungeonRewards, songsAllLocations});
  Option Shopsanity             = Option::U8  ("Shopsanity",             {"Off", "0", "1", "2", "3", "4", "Random"},                        {shopsOff, shopsZero, shopsOne, shopsTwo, shopsThree, shopsFour, shopsRandom});
  Option Tokensanity            = Option::U8  ("Tokensanity",            {"Off", "Dungeons", "Overworld", "All Tokens"},                    {tokensOff, tokensDungeon, tokensOverworld, tokensAllTokens});
  Option Scrubsanity            = Option::U8  ("Scrub Shuffle",          {"Off", "Affordable", "Expensive", "Random Prices"},               {scrubsOff, scrubsAffordable, scrubsExpensive, scrubsRandomPrices});
  Option ShuffleCows            = Option::Bool("Shuffle Cows",           {"Off", "On"},                                                     {shuffleCowsDesc});
  Option ShuffleKokiriSword     = Option::Bool("Shuffle Kokiri Sword",   {"Off", "On"},                                                     {kokiriSwordDesc});
  Option ShuffleOcarinas        = Option::Bool("Shuffle Ocarinas",       {"Off", "On"},                                                     {ocarinasDesc});
  Option ShuffleMagicBeans      = Option::Bool("Shuffle Magic Beans",    {"Off", "On"},                                                     {magicBeansDesc});
  std::vector<Option *> shuffleOptions = {
    &RandomizeShuffle,
    &ShuffleRewards,
    &LinksPocketItem,
    &ShuffleSongs,
    &Shopsanity,
    &Tokensanity,
    &Scrubsanity,
    &ShuffleCows,
    &ShuffleKokiriSword,
    &ShuffleOcarinas,
    &ShuffleMagicBeans,
  };

  //Shuffle Dungeon Items
  Option RandomizeDungeon    = Option::Bool("Randomize Settings",     {"No","Yes"},                                                      {dungeonRandomize},                                                                                                    OptionCategory::Toggle);
  Option MapsAndCompasses    = Option::U8  ("Maps/Compasses",         {"Start With", "Vanilla", "Own Dungeon", "Any Dungeon", "Overworld", "Anywhere"},
                                                                      {mapCompassStartWith, mapCompassVanilla, mapCompassOwnDungeon, mapCompassAnyDungeon, mapCompassOverworld, mapCompassAnywhere},                                                            OptionCategory::Setting,    MAPSANDCOMPASSES_VANILLA);
  Option Keysanity           = Option::U8  ("Small Keys",             {"Start With", "Vanilla", "Own Dungeon", "Any Dungeon", "Overworld", "Anywhere"},
                                                                      {smallKeyStartWith, smallKeyVanilla, smallKeyOwnDungeon, smallKeyAnyDungeon, smallKeyOverworld, smallKeyAnywhere},                                                                        OptionCategory::Setting,    KEYSANITY_VANILLA);
  Option BossKeysanity       = Option::U8  ("Boss Keys",              {"Start With", "Vanilla", "Own Dungeon", "Any Dungeon", "Overworld", "Anywhere"},
                                                                      {bossKeyStartWith, bossKeyVanilla, bossKeyOwnDungeon, bossKeyAnyDungeon, bossKeyOverworld, bossKeyAnywhere},                                                                              OptionCategory::Setting,    BOSSKEYSANITY_VANILLA);
  std::vector<Option *> shuffleDungeonItemOptions = {
    &RandomizeDungeon,
    &MapsAndCompasses,
    &Keysanity,
    &BossKeysanity,
  };

  //Timesaver Settings
  Option SkipEponaRace       = Option::Bool("Skip Epona Race",        {"Don't Skip", "Skip"},                                                 {skipEponaRaceDesc});
  Option SkipMinigamePhases  = Option::Bool("Minigames repetitions",  {"Don't Skip", "Skip"},                                                 {skipMinigamePhasesDesc});
  Option FreeScarecrow       = Option::Bool("Free Scarecrow",         {"Off", "On"},                                                          {freeScarecrowDesc});
  Option QuickText           = Option::U8  ("Quick Text",             {"0: Vanilla", "1: Skippable", "2: Instant", "3: Turbo"},               {quickTextDesc0, quickTextDesc1, quickTextDesc2, quickTextDesc3},                                                 OptionCategory::Setting,    QUICKTEXT_SKIPPABLE);
  Option SkipSongReplays     = Option::U8  ("  Skip Song Replays",    {"Don't Skip", "Skip (No SFX)", "Skip (Keep SFX)"},                     {skipSongReplaysDesc});
  std::vector<Option *> timesaverOptions = {
    &SkipEponaRace,
    &SkipMinigamePhases,
    &FreeScarecrow,
    &QuickText,
    &SkipSongReplays,
  };

  //Misc Settings
  Option GossipStoneHints    = Option::U8  ("Gossip Stone Hints",     {"No Hints", "Need Nothing", "Mask of Truth", "Shard of Agony"},        {gossipStonesHintsDesc},                                                                                          OptionCategory::Setting,    HINTS_NEED_NOTHING);
  Option ClearerHints        = Option::Bool("  Clearer Hints",        {"Off", "On"},                                                          {clearerHintsDesc});
  Option HintDistribution    = Option::U8  ("  Hint Distribution",    {"Useless", "Balanced", "Strong", "Very Strong"},                       {uselessHintsDesc, balancedHintsDesc, strongHintsDesc, veryStrongHintsDesc},                                      OptionCategory::Setting,    1); // Balanced
  Option DamageMultiplier    = Option::U8  ("Damage Multiplier",      {"x1/2", "x1", "x2", "x4", "x8", "x16", "OHKO"},                        {damageMultiDesc},                                                                                                OptionCategory::Setting,    DAMAGEMULTIPLIER_DEFAULT);
  Option ChestAnimations     = Option::Bool("Chest Animations",       {"Always Fast", "Match Contents"},                                      {chestAnimDesc});
  Option ChestSize           = Option::Bool("Chest Size and Color",   {"Vanilla", "Match Contents"},                                          {chestSizeDesc});
  Option GenerateSpoilerLog  = Option::Bool("Generate Spoiler Log",   {"No", "Yes"},                                                          {"", ""},                                                                                                         OptionCategory::Setting,    1); // On
  Option IngameSpoilers      = Option::Bool("Ingame Spoilers",        {"Hide", "Show"},                                                       {ingameSpoilersHideDesc, ingameSpoilersShowDesc });
  Option MenuOpeningButton   = Option::U8  ("Open Info Menu with",    {"Select","Start","D-Pad Up","D-Pad Down","D-Pad Right","D-Pad Left",}, {menuButtonDesc});
  Option RandomTrapDmg       = Option::U8  ("Random Trap Damage",     {"Off", "Basic", "Advanced"},                                           {randomTrapDmgDesc, basicTrapDmgDesc, advancedTrapDmgDesc});
  bool HasNightStart         = false;
  std::vector<Option *> miscOptions = {
    &GossipStoneHints,
    &ClearerHints,
    &HintDistribution,
    &DamageMultiplier,
    &ChestAnimations,
    &ChestSize,
    &GenerateSpoilerLog,
    &IngameSpoilers,
    &MenuOpeningButton,
    &RandomTrapDmg,
  };


  //Item Pool Settings
  Option ItemPoolValue         = Option::U8  ("Item Pool",             {"Plentiful", "Balanced", "Scarce", "Minimal"},                        {itemPoolPlentiful, itemPoolBalanced, itemPoolScarce, itemPoolMinimal},                                           OptionCategory::Setting,    ITEMPOOL_BALANCED);
  Option IceTrapValue          = Option::U8  ("Ice Traps",             {"Off", "Normal", "Extra", "Mayhem", "Onslaught"},                     {iceTrapsOff, iceTrapsNormal, iceTrapsExtra, iceTrapsMayhem, iceTrapsOnslaught},                                  OptionCategory::Setting,    ICETRAPS_NORMAL);
  Option RemoveDoubleDefense   = Option::Bool("Remove Double Defense", {"No", "Yes"},                                                         {removeDDDesc});
  std::vector<Option *> itemPoolOptions = {
    &ItemPoolValue,
    &IceTrapValue,
    &RemoveDoubleDefense,
  };

  //Excluded Locations (Individual definitions made in ItemLocation class)
  std::vector<Option *> excludeLocationsOptions = {};

  std::vector<std::string> bottleOptions = {"None", "Empty Bottle", "Red Potion", "Green Potion", "Blue Potion", "Fairy", "Fish", "Milk", "Blue Fire", "Bugs", "Big Poe", "Half Milk", "Poe"};
  std::vector<std::string> healthOptions = { "3 hearts",  "4 hearts",  "5 hearts",  "6 hearts",  "7 hearts",  "8 hearts",  "9 hearts", "10 hearts", "11 hearts", "12 hearts",
                                            "13 hearts", "14 hearts", "15 hearts", "16 hearts", "17 hearts", "18 hearts", "19 hearts", "20 hearts"};//,  "1 heart",   "2 hearts"}; // TODO: logic for lower health
  Option StartingConsumables      = Option::Bool("Start with Consumables", {"No",               "Yes"},                                                     {startWithConsumablesDesc});
  Option StartingMaxRupees        = Option::Bool("Start with Max Rupees",  {"No",               "Yes"},                                                     {startWithMaxRupeesDesc});
  Option StartingInventoryToggle  = Option::U8  ("Inventory",              {"All Off",          "All On",           "Choose"},                              {""});
  Option StartingNutCapacity      = Option::U8  ("  Deku Nuts",            {"20 Deku Nuts",     "30 Deku Nuts",     "40 Deku Nuts"},                        {""});
  Option StartingOcarina          = Option::U8  ("  Ocarina",              {"None",             "Fairy Ocarina",    "Ocarina of Time"},                     {""});
  Option StartingBombBag          = Option::U8  ("  Bomb Bag",             {"None",             "Bomb Bag 20",      "Bomb Bag 30",      "Bomb Bag 40"},     {""});
  Option StartingBombchus         = Option::U8  ("  Bombchus",             {"None",             "Bombchus"},                                                {""});
  Option StartingHookshot         = Option::U8  ("  Hookshot",             {"None",             "Hookshot",         "Longshot"},                            {""});
  Option StartingBow              = Option::U8  ("  Bow",                  {"None",             "Bow + Quiver 30",  "Bow + Quiver 40",  "Bow + Quiver 50"}, {""});
  Option StartingFireArrows       = Option::U8  ("  Fire Arrow",           {"None",             "Fire Arrow"},                                              {""});
  Option StartingIceArrows        = Option::U8  ("  Ice Arrow",            {"None",             "Ice Arrow"},                                               {""});
  Option StartingLightArrows      = Option::U8  ("  Light Arrow",          {"None",             "Light Arrow"},                                             {""});
  Option StartingLensOfTruth      = Option::U8  ("  Lens of Truth",        {"None",             "Lens of Truth"},                                           {""});
  Option StartingMagicBean        = Option::U8  ("  Magic Beans",          {"None",             "Magic Beans"},                                             {""});
  Option StartingBottle1          = Option::U8  ("  Bottle Slot 1",        bottleOptions,                                                                   {""});
  Option StartingBottle2          = Option::U8  ("  Bottle Slot 2",        bottleOptions,                                                                   {""});
  Option StartingBottle3          = Option::U8  ("  Bottle Slot 3",        bottleOptions,                                                                   {""});
  Option StartingBottle4          = Option::U8  ("  Bottle Slot 4",        bottleOptions,                                                                   {""});
  Option StartingBottle5          = Option::U8  ("  Bottle Slot 5",        bottleOptions,                                                                   {""});
  Option StartingBottle6          = Option::U8  ("  Bottle Slot 6",        bottleOptions,                                                                   {""});
  Option StartingBottle7          = Option::U8  ("  Bottle Slot 7",        bottleOptions,                                                                   {""});
  Option StartingBottle8          = Option::U8  ("  Bottle Slot 8",        bottleOptions,                                                                   {""});
  Option StartingSongsToggle      = Option::U8  ("Ocarina Songs",          {"All Off",          "All On",           "Choose"},                              {""});
  Option StartingOathToOrder      = Option::U8  ("  Oath To Order",        {"None",             "Oath to Order"},                                           {""});
  Option StartingEponasSong       = Option::U8  ("  Epona's Song",         {"None",             "Epona's Song"},                                            {""});
  Option StartingInvertedSong     = Option::U8  ("  Inverted Song of Time",{"None",             "I. Song of Time"},                                         {""});
  Option StartingDoubleSong       = Option::U8  ("  Song of Double Time",  {"None",             "Song of D. Time"},                                         {""});
  Option StartingSongOfTime       = Option::U8  ("  Song of Time",         {"None",             "Song of Time"},                                            {""});
  Option StartingSongOfStorms     = Option::U8  ("  Song of Storms",       {"None",             "Song of Storms"},                                          {""});
  Option StartingSonataOfAwakening= Option::U8  ("  Sonata of Awakening",  {"None",             "Sonata of A."},                                            {""});
  Option StartingGoronsLullaby    = Option::U8  ("  Gorons Lullaby",       {"None",             "Gorons Lullaby"},                                          {""});
  Option StartingNewWaveBossaNova = Option::U8  ("  New Wave Bossa Nova",  {"None",             "New Wave Bossa Nova"},                                     {""});
  Option StartingElegyOfEmptiness = Option::U8  ("  Elegy of Emptiness",   {"None",             "Elegy of Emptiness"},                                      {""});
  Option StartingSongOfHealing    = Option::U8  ("  Song of Healing",  	   {"None",             "Song of Healing"},                                         {""});
  Option StartingSongOfSoaring    = Option::U8  ("  Song of Soaring",      {"None",             "Song of Soaring"},                                         {""});
  Option StartingUpgradesToggle   = Option::U8  ("Equipment & Upgrades",   {"All Off",          "All On",           "Choose"},                              {""});
  Option StartingKokiriSword      = Option::U8  ("  Kokiri Sword",         {"None",             "Kokiri Sword"},                                            {""});
  Option StartingGreatFairySword  = Option::U8  ("  Great Fairy Sword",    {"None",             "Great Fairys Sword"}, 				                        {""});
  Option StartingHerosShield     = Option::U8  ("  Hero's Shield",        {"None",             "Hero's Shield"},                                           {""});
  Option StartingMirrorShield     = Option::U8  ("  Mirror Shield",        {"None",             "Mirror Shield"},                                           {""});
  Option StartingWallet           = Option::U8  ("  Wallet Upgrade",       {"None",             "Adult's Wallet",   "Giant's Wallet" ,  "Tycoon's Wallet"}, {""});
  Option StartingHealth           = Option::U8  ("  Health",               healthOptions,                                                                   {""});
  Option StartingMagicMeter       = Option::U8  ("  Magic Meter",          {"None",             "Single Magic",     "Double Magic"},                        {""});
  Option StartingDoubleDefense    = Option::U8  ("  Double Defense",       {"None",             "Double Defence"},                                          {""});
  Option StartingQuestToggle      = Option::U8  ("Quest Items",            {"All Off",          "All On",           "Choose"},                              {""});
  Option StartingOdolwaRemains    = Option::U8  ("  Odolwa's Remains",     {"None",             "Odolwa's R."},                                             {""});
  Option StartingGohtRemains      = Option::U8  ("  Goht's Remains",       {"None",             "Goht's R."},       	                                    {""});
  Option StartingGyorgRemains     = Option::U8  ("  Gyorg's Remains",      {"None",             "Gyorg's R."},                                              {""});
  Option StartingTwinmoldRemains  = Option::U8  ("  Twinmold's Remains",   {"None",             "TwinMold's R."},                                           {""});
  Option StartingSwampToken  	  = Option::U8  ("Swamp Skulltula Tokens",  {/*Options 0-30 defined in InitSettings()*/},                                   {""},                                                                                               OptionCategory::Setting,    0,                          false);
  Option StartingOceanToken   	  = Option::U8  ("Ocean Skulltula Tokens",  {/*Options 0-30 defined in InitSettings()*/},                                   {""},                                                                                               OptionCategory::Setting,    0,                          false);
  std::vector<Option *> startingInventoryOptions = {
    &StartingConsumables,
    &StartingMaxRupees,
    &StartingInventoryToggle,
    &StartingNutCapacity,
    &StartingSlingshot,
    &StartingOcarina,
    &StartingBombBag,
    &StartingBombchus,
    &StartingHookshot,
    &StartingBow,
    &StartingFireArrows,
    &StartingIceArrows,
    &StartingLightArrows,
    &StartingLensOfTruth,
    &StartingMagicBean,
    &StartingBottle1,
    &StartingBottle2,
    &StartingBottle3,
    &StartingBottle4,
    &StartingBottle5,
    &StartingBottle6,
    &StartingBottle7,
    &StartingSongsToggle,
    &StartingOathToOrder,
    &StartingEponasSong,
    &StartingInvertedSong,
    &StartingDoubleSong,
    &StartingSongOfTime,
    &StartingSongOfStorms,
    &StartingSonataOfAwakening,
    &StartingGoronRuby,
    &StartingNewWaveBossaNova,
    &StartingElegyOfEmptiness,
    &StartingSongOfHealing,
    &StartingSongOfSoaring,
    &StartingUpgradesToggle,
    &StartingKokiriSword,
    &StartingGreatFairySword,
    &StartingHerosShield,
    &StartingMirrorShield,
    &StartingWallet,
    &StartingHealth,
    &StartingMagicMeter,
    &StartingDoubleDefense,
    &StartingQuestToggle,
    &StartingOdolwaRemains,
    &StartingGohtRemains,
    &StartingGyorgRemains,
    &StartingTwinmoldRemains,
    &StartingSwampToken,
    &StartingOceanToken,
  };

  Option Logic              = Option::U8  ("Logic",                   {"Glitchless", "Glitched", "No Logic", "Vanilla"}, {logicGlitchless, logicGlitched, logicNoLogic, logicVanilla});
  Option LocationsReachable = Option::Bool("All Locations Reachable", {"Off", "On"},                                     {locationsReachableDesc},                                                                                                              OptionCategory::Setting,    1); //All Locations Reachable On
  std::vector<Option *> logicOptions = {
    &Logic,
    &LocationsReachable,
  };
/*TODO MM3D LOGIC TRICKS
  //Function to make defining logic tricks easier to read
  Option LogicTrick(std::string setting, std::string_view description) {
    return Option::Bool(setting, {"Disabled", "Enabled"}, {description});
  }

  //Detailed Logic Tricks                               ---------------------
  Option ToggleAllTricks                  = Option::U8("All Tricks", {"None", "Novice", "Intermediate", "Expert"},  {ToggleLogicNoneDesc, ToggleLogicNoviceDesc, ToggleLogicIntermediateDesc, ToggleLogicExpertDesc},                                           OptionCategory::Toggle);
  Option LogicGrottosWithoutAgony         = LogicTrick(" Grotto Access\n   w/o Shard of Agony",       LogicGrottosWithoutAgonyDesc);
  Option LogicVisibleCollision            = LogicTrick(" Go Through Visible\n   One-Way Collisions",  LogicVisibleCollisionDesc);
  Option LogicFewerTunicRequirements      = LogicTrick(" Fewer Tunic\n   Requirements",               LogicFewerTunicRequirementsDesc);
  Option LogicLostWoodsGSBean             = LogicTrick(" LW Adult Tree GS\n   w/o Magic Beans",       LogicLostWoodsGSBeanDesc);
  Option LogicLabDiving                   = LogicTrick(" LH Lab Dive\n   w/o Gold Scale",             LogicLabDivingDesc);
  Option LogicLabWallGS                   = LogicTrick(" LH Lab Wall GS\n   w/ Jump Slash",           LogicLabWallGSDesc);
  Option LogicGraveyardPoH                = LogicTrick(" GY Crate PoH\n   w/ Boomerang",              LogicGraveyardPoHDesc);
  Option LogicChildDampeRacePoH           = LogicTrick(" GY Second Dampe\n   Race as Child",          LogicChildDampeRacePoHDesc);
  Option LogicGerudoKitchen               = LogicTrick(" GF Through Kitchen\n   w/ Nothing",          LogicGerudoKitchenDesc);
  Option LogicLensWasteland               = LogicTrick(" Haunted Wasteland\n   w/o Lens of Truth",    LogicLensWastelandDesc);
  Option LogicReverseWasteland            = LogicTrick(" Haunted Wasteland\n   in Reverse",           LogicReverseWastelandDesc);
  Option LogicColossusGS                  = LogicTrick(" Colossus Hill GS\n   w/ Hookshot",           LogicColossusGSDesc);
  Option LogicOutsideGanonsGS             = LogicTrick(" Outside GaC GS\n   w/ Jump Slash",           LogicOutsideGanonsGSDesc);
  Option LogicManOnRoof                   = LogicTrick(" Kak Roof Guy\n   w/o Hookshot",              LogicManOnRoofDesc);
  Option LogicDMTBombable                 = LogicTrick(" DMT Wall Chest\n   w/ Strength",             LogicDMTBombableDesc);
  Option LogicDMTSoilGS                   = LogicTrick(" DMT Soil GS\n   w/o Opening DC",             LogicDMTSoilGSDesc);
  Option LogicLinkGoronDins               = LogicTrick(" GoC Adult Goron\n   w/ Din's Fire",          LogicLinkGoronDinsDesc);
  Option LogicGoronCityLeftMost           = LogicTrick(" GoC Maze Left Chest\n   w/ Hover Boots",     LogicGoronCityLeftMostDesc);
  Option LogicGoronCityPot                = LogicTrick(" GoC Goron Vase PoH\n   w/ Bombchu",          LogicGoronCityPotDesc); //Needs Testing
  Option LogicGoronCityPotWithStrength    = LogicTrick(" GoC Goron Vase PoH\n   w/ Strength",         LogicGoronCityPotWithStrengthDesc);
  Option LogicChildRollingWithStrength    = LogicTrick(" GoC Child Goron\n   w/ Strength",            LogicChildRollingWithStrengthDesc);
  Option LogicCraterUpperToLower          = LogicTrick(" DMC Upper to Lower\n   w/ Hammer",           LogicCraterUpperToLowerDesc); //Needs Testing
  Option LogicCraterBeanPoHWithHovers     = LogicTrick(" DMC Bean PoH\n   w/ Hover Boots",            LogicCraterBeanPoHWithHoversDesc);
  Option LogicBiggoronBolero              = LogicTrick(" DMC Deliver Eyedrops\n   w/ Bolero of Fire", LogicBiggoronBoleroDesc);
  Option LogicZoraRiverLower              = LogicTrick(" ZR Lower PoH\n   w/ Nothing",                LogicZoraRiverLowerDesc);
  Option LogicZoraRiverUpper              = LogicTrick(" ZR Upper PoH\n   w/ Nothing",                LogicZoraRiverUpperDesc);
  Option LogicDekuB1WebsWithBow           = LogicTrick(" DT B1 Web\n   w/ Bow",                       LogicDekuB1WebsWithBowDesc);
  Option LogicDekuB1Skip                  = LogicTrick(" DT B1 Navigation\n   w/o Slingshot",         LogicDekuB1SkipDesc);
  Option LogicDekuBasementGS              = LogicTrick(" DT B1 Vines GS\n   w/ Jump Slash",           LogicDekuBasementGSDesc);
  Option LogicDCStaircase                 = LogicTrick(" DC Staircase\n   w/ Bow",                    LogicDCStaircaseDesc);
  Option LogicDCJump                      = LogicTrick(" DC Spike Trap Room\n   w/o Hover Boots",     LogicDCJumpDesc);
  Option LogicDCSlingshotSkip             = LogicTrick(" DC Eye Switches\n   w/o Slingshot",          LogicDCSlingshotSkipDesc);
  Option LogicDCScarecrowGS               = LogicTrick(" DC Scarecrow GS\n   w/ Armos Statue",        LogicDCScarecrowGSDesc);
  Option LogicJabuBossGSAdult             = LogicTrick(" JJB Near Boss GS\n   as Adult",              LogicJabuBossGSAdultDesc); //Needs Testing
  Option LogicJabuScrubJumpDive           = LogicTrick(" JJB Deku Scrub\n   as Adult",                LogicJabuScrubJumpDiveDesc); //Needs Testing
  Option LogicForestOutsideBackdoor       = LogicTrick(" FoT West Backdoor\n   w/ Jump Slash",        LogicForestOutsideBackdoorDesc); //Needs Testing
  Option LogicForestDoorFrame             = LogicTrick(" FoT East Scarecrow\n   w/ Hover Boots",      LogicForestDoorFrameDesc); //Needs Testing
  Option LogicForestOutdoorEastGS         = LogicTrick(" FoT East Yard GS\n   w/ Boomerang",          LogicForestOutdoorEastGSDesc);
  Option LogicFireBossDoorJump            = LogicTrick(" FiT Boss Door\n   w/o Hover Boots",          LogicFireBossDoorJumpDesc);
  Option LogicFireStrength                = LogicTrick(" FiT Climb Block\n   w/o Strength",           LogicFireStrengthDesc);
  Option LogicFireScarecrow               = LogicTrick(" FiT East Tower\n   w/o Scarecrow",           LogicFireScarecrowDesc);
  Option LogicFireFlameMaze               = LogicTrick(" FiT Firewall Maze\n   w/ Nothing",           LogicFireFlameMazeDesc);
  Option LogicFireSongOfTime              = LogicTrick(" FiT SoT Room GS\n   w/o SoT",                LogicFireSongOfTimeDesc);
  Option LogicWaterTempleTorchLongshot    = LogicTrick(" WaT Torch Longshot\n   Shortcut",            LogicWaterTempleTorchLongshotDesc);
  Option LogicWaterTempleUpperBoost       = LogicTrick(" WaT Boss Ledge\n   w/ Bombs",                LogicWaterTempleUpperBoostDesc);
  Option LogicWaterCentralBow             = LogicTrick(" WaT Bow Target\n   w/o Longshot/Hover",      LogicWaterCentralBowDesc);
  Option LogicWaterCentralGSFW            = LogicTrick(" WaT Center Room GS\n   w/ Farore's Wind",    LogicWaterCentralGSFWDesc);
  Option LogicWaterCrackedWallNothing     = LogicTrick(" WaT Cracked Wall\n   w/ Nothing",            LogicWaterCrackedWallNothingDesc);
  Option LogicWaterCrackedWallHovers      = LogicTrick(" WaT Cracked Wall\n   w/ Hover Boots",        LogicWaterCrackedWallHoversDesc);
  Option LogicWaterBossKeyRegion          = LogicTrick(" WaT B1 North Area\n   w/ Hover Boots",       LogicWaterBossKeyRegionDesc);
  Option LogicWaterBKJumpDive             = LogicTrick(" WaT Boss Key Room\n   w/o Iron Boots",       LogicWaterBKJumpDiveDesc);
  Option LogicWaterNorthBasementLedgeJump = LogicTrick(" WaT Boss Key Rooms\n   w/ Precise Jump",     LogicWaterNorthBasementLedgeJumpDesc);
  Option LogicWaterDragonAdult            = LogicTrick(" WaT Whirlpool\n   w/o Iron Boots",           LogicWaterDragonAdultDesc);
  Option LogicWaterDragonJumpDive         = LogicTrick(" WaT Whirlpool Up\n   w/o Iron Boots",        LogicWaterDragonJumpDiveDesc);
  Option LogicWaterRiverGS                = LogicTrick(" WaT River GS\n   w/o Iron Boots",            LogicWaterRiverGSDesc);
  Option LogicWaterFallingPlatformGS      = LogicTrick(" WaT Waterfall GS\n   w/ Hookshot",           LogicWaterFallingPlatformGSDesc);
  Option LogicSpiritLowerAdultSwitch      = LogicTrick(" SpT Ceiling Switch\n   w/ Bombs",            LogicSpiritLowerAdultSwitchDesc);
  Option LogicSpiritChildBombchu          = LogicTrick(" SpT Child Bridge\n   w/ Bombchu",            LogicSpiritChildBombchuDesc);
  Option LogicSpiritWall                  = LogicTrick(" SpT Shifting Wall\n   w/ Nothing",           LogicSpiritWallDesc);
  Option LogicSpiritLobbyGS               = LogicTrick(" SpT Main Room GS\n   w/ Boomerang",          LogicSpiritLobbyGSDesc);
  Option LogicSpiritMapChest              = LogicTrick(" SpT Map Chest\n   w/ Bow",                   LogicSpiritMapChestDesc);
  Option LogicSpiritSunChest              = LogicTrick(" SpT Sun Block Room\n   w/ Bow",              LogicSpiritSunChestDesc); //Needs Testing
  Option LogicShadowFireArrowEntry        = LogicTrick(" ShT Entry\n   w/ Fire Arrows",               LogicShadowFireArrowEntryDesc); //Needs Testing
  Option LogicShadowUmbrella              = LogicTrick(" ShT Stone Umbrella\n   w/ Hover Boots",      LogicShadowUmbrellaDesc);
  Option LogicShadowFreestandingKey       = LogicTrick(" ShT Skull Vase Key\n   w/ Bombchu",          LogicShadowFreestandingKeyDesc);
  Option LogicShadowStatue                = LogicTrick(" ShT River Statue\n   w/ Bombchu",            LogicShadowStatueDesc);
  Option LogicChildDeadhand               = LogicTrick(" BotW Deadhand\n   w/o Sword",                LogicChildDeadhandDesc);
  Option LogicGtgWithoutHookshot          = LogicTrick(" GTG West Silver Rupee\n   w/o Hookshot",     LogicGtgWithoutHookshotDesc);
  Option LogicGtgFakeWall                 = LogicTrick(" GTG Invisible Wall\n   w/ Hover Boots",      LogicGtgFakeWallDesc);
  Option LogicLensSpirit                  = LogicTrick(" SpT Navigate\n   w/o Lens of Truth",         LogicLensSpiritDesc);
  Option LogicLensShadow                  = LogicTrick(" ShT Early Rooms\n   w/o Lens of Truth",      LogicLensShadowDesc);
  Option LogicLensShadowBack              = LogicTrick(" ShT Later Rooms\n   w/o Lens of Truth",      LogicLensShadowBackDesc);
  Option LogicLensBotw                    = LogicTrick(" BotW Navigate\n   w/o Lens of Truth",        LogicLensBotwDesc);
  Option LogicLensGtg                     = LogicTrick(" GTG Navigate\n   w/o Lens of Truth",         LogicLensGtgDesc);
  Option LogicLensCastle                  = LogicTrick(" GaC Navigate\n   w/o Lens of Truth",         LogicLensCastleDesc);
  Option LogicLensJabuMQ                  = LogicTrick(" JJB MQ Navigate\n   w/o Lens of Truth",      LogicLensJabuMQDesc);
  Option LogicLensSpiritMQ                = LogicTrick(" SpT MQ Navigate\n   w/o Lens of Truth",      LogicLensSpiritMQDesc);
  Option LogicLensShadowMQ                = LogicTrick(" ShT MQ Early Rooms\n   w/o Lens of Truth",   LogicLensShadowMQDesc);
  Option LogicLensShadowMQBack            = LogicTrick(" ShT MQ Later Rooms\n   w/o Lens of Truth",   LogicLensShadowMQBackDesc);
  Option LogicLensBotwMQ                  = LogicTrick(" BotW MQ Nagivate\n   w/o Lens of Truth",     LogicLensBotwMQDesc);
  Option LogicLensGtgMQ                   = LogicTrick(" GTG MQ Navigate\n   w/o Lens of Truth",      LogicLensGtgMQDesc);
  Option LogicLensCastleMQ                = LogicTrick(" GaC MQ Navigate\n   w/o Lens of Truth",      LogicLensCastleMQDesc);
  Option LogicSpiritTrialHookshot         = LogicTrick(" Spirit Trial\n   w/o Hookshot",              LogicSpiritTrialHookshotDesc);
  std::vector<Option *> trickOptions = {
    &ToggleAllTricks,
    &LogicGrottosWithoutAgony,
    &LogicVisibleCollision,
    &LogicFewerTunicRequirements,
    &LogicLostWoodsGSBean,
    &LogicLabDiving,
    &LogicLabWallGS,
    &LogicGraveyardPoH,
    &LogicChildDampeRacePoH,
    &LogicGerudoKitchen,
    &LogicLensWasteland,
    &LogicReverseWasteland,
    &LogicColossusGS,
    &LogicOutsideGanonsGS,
    &LogicManOnRoof,
    &LogicDMTBombable,
    //&LogicDMTSoilGS, Needs Testing
    &LogicLinkGoronDins,
    &LogicGoronCityLeftMost,
    //&LogicGoronCityPot, Needs Testing
    &LogicGoronCityPotWithStrength,
    &LogicChildRollingWithStrength,
    //&LogicCraterUpperToLower, Needs Testing
    &LogicCraterBeanPoHWithHovers,
    &LogicBiggoronBolero,
    &LogicZoraRiverLower,
    &LogicZoraRiverUpper,
    &LogicDekuB1WebsWithBow,
    &LogicDekuB1Skip,
    &LogicDekuBasementGS,
    &LogicDCStaircase,
    &LogicDCJump,
    &LogicDCSlingshotSkip,
    &LogicDCScarecrowGS,
    //&LogicJabuBossGSAdult, Needs Testing
    //&LogicJabuScrubJumpDive, Needs Testing
    //&LogicForestOutsideBackdoor, Needs Testing
    //&LogicForestDoorFrame, Needs Testing
    &LogicForestOutdoorEastGS,
    &LogicFireBossDoorJump,
    &LogicFireStrength,
    &LogicFireScarecrow,
    &LogicFireFlameMaze,
    &LogicFireSongOfTime,
    &LogicWaterTempleTorchLongshot,
    &LogicWaterTempleUpperBoost,
    &LogicWaterCentralBow,
    &LogicWaterCentralGSFW,
    &LogicWaterCrackedWallNothing,
    &LogicWaterCrackedWallHovers,
    &LogicWaterBossKeyRegion,
    &LogicWaterBKJumpDive,
    &LogicWaterNorthBasementLedgeJump,
    &LogicWaterDragonJumpDive,
    &LogicWaterDragonAdult,
    &LogicWaterRiverGS,
    &LogicWaterFallingPlatformGS,
    &LogicSpiritLowerAdultSwitch,
    &LogicSpiritChildBombchu,
    &LogicSpiritWall,
    &LogicSpiritLobbyGS,
    &LogicSpiritMapChest,
    //&LogicSpiritSunChest, Needs Testing
    //&LogicShadowFireArrowEntry, Needs Testing
    &LogicShadowUmbrella,
    &LogicShadowFreestandingKey,
    &LogicShadowStatue,
    &LogicChildDeadhand,
    &LogicGtgWithoutHookshot,
    &LogicGtgFakeWall,
    &LogicLensSpirit,
    &LogicLensShadow,
    &LogicLensShadowBack,
    &LogicLensBotw,
    &LogicLensGtg,
    &LogicLensCastle,
    &LogicLensJabuMQ,
    &LogicLensSpiritMQ,
    &LogicLensShadowMQ,
    &LogicLensShadowMQBack,
    &LogicLensBotwMQ,
    &LogicLensGtgMQ,
    &LogicLensCastleMQ,
    &LogicSpiritTrialHookshot,
  };
*/
  //Function to avoid accidentally naming the options wrong, as logic.cpp requires these exact names
  std::vector<std::string> GlitchDifficultyOptions(u8 enabledDifficulties) {
    static constexpr std::array glitchDifficulties{"Novice", "Intermediate", "Advanced", "Expert", "Hero"};

    std::vector<std::string> selectableDifficulties;
    selectableDifficulties.push_back("Disabled");
    for (size_t i = 0; i < glitchDifficulties.size(); i++) {
      if ((enabledDifficulties >> i) & 1) {
        selectableDifficulties.push_back(glitchDifficulties[i]);
      }
    }

    return selectableDifficulties;
  }

  Option GlitchISG                = Option::U8("Infinite Sword Glitch", GlitchDifficultyOptions(0b00001), {GlitchISGDescDisabled, GlitchISGDescNovice});
  Option GlitchHover              = Option::U8("Bomb Hover",            GlitchDifficultyOptions(0b00111), {GlitchHoverDescDisabled, GlitchHoverDescNovice, GlitchHoverDescIntermediate, GlitchHoverDescAdvanced});
  Option GlitchMegaflip           = Option::U8("Megaflip",              GlitchDifficultyOptions(0b00011), {GlitchMegaflipDescDisabled, GlitchMegaflipDescNovice, GlitchMegaflipDescIntermediate});
  Option GlitchHookshotClip       = Option::U8("Hookshot Clip",         GlitchDifficultyOptions(0b00001), {GlitchHookshotClipDescDisabled, GlitchHookshotClipDescNovice});
  Option GlitchHookshotJump_Bonk  = Option::U8("Hookshot Jump (Bonk)",  GlitchDifficultyOptions(0b00010), {GlitchHookshotJump_BonkDescDisabled, GlitchHookshotJump_BonkDescIntermediate});
  Option GlitchHookshotJump_Boots = Option::U8("Hookshot Jump (Boots)", GlitchDifficultyOptions(0b00011), {GlitchHookshotJump_BootsDescDisabled, GlitchHookshotJump_BootsDescNovice, GlitchHookshotJump_BootsDescIntermediate});
  Option GlitchLedgeClip          = Option::U8("Ledge Clip",            GlitchDifficultyOptions(0b00011), {GlitchLedgeClipDescDisabled, GlitchLedgeClipDescNovice, GlitchLedgeClipDescIntermediate});
  Option GlitchTripleSlashClip    = Option::U8("Triple Slash Clip",     GlitchDifficultyOptions(0b00001), {GlitchTripleSlashClipDescDisabled, GlitchTripleSlashClipDescNovice});
  std::vector<Option*> glitchOptions = {
    &GlitchISG,
    &GlitchHover,
    &GlitchMegaflip,
    &GlitchHookshotClip,
    &GlitchHookshotJump_Bonk,
    &GlitchHookshotJump_Boots,
    &GlitchLedgeClip,
    &GlitchTripleSlashClip,
  };

  static std::vector<std::string> tunicOptions = {
    std::string(RANDOM_CHOICE_STR),
    std::string(RANDOM_COLOR_STR),
    std::string(CUSTOM_COLOR_STR),
    "Kokiri Green",
    "Goron Red",
    "Zora Blue",
    "Black",
    "White",
    "Azure Blue",
    "Vivid Cyan",
    "Light Red",
    "Fuchsia",
    "Purple",
    "Majora Purple",
    "Twitch Purple",
    "Magenta",
    "Violet",
    "Persian Rose",
    "Dirty Yellow",
    "Blush Pink",
    "Hot Pink",
    "Rose Pink",
    "Orange",
    "Gray",
    "Yellow",
    "Silver",
    "Beige",
    "Teal",
    "Blood Red",
    "Blood Orange",
    "Royal Blue",
    "NES Green",
    "Dark Green",
    "Lumen",
  };
  static std::vector<std::string_view> cosmeticDescriptions = {
    RANDOM_CHOICE_DESC,
    RANDOM_COLOR_DESC,
    CUSTOM_COLOR_DESC,
    "This will only affect the color on Link's model.",
  };

  Option CustomTunicColors          = Option::Bool("Custom Tunic Colors",    {"Off", "On"},   {""},                                                                                                                                                             OptionCategory::Cosmetic);
  Option ChildTunicColor            = Option::U8  ("  Child Tunic Color",    tunicOptions,    cosmeticDescriptions,                                                                                                                                             OptionCategory::Cosmetic,               3); // Kokiri Green
  std::string finalChildTunicColor      = ChildTunicColor.GetSelectedOptionText();

  Option ColoredKeys =     Option::Bool("Colored Small Keys", {"Off", "On"}, {coloredKeysDesc},                                                                                                                                                                 OptionCategory::Cosmetic);
  Option ColoredBossKeys = Option::Bool("Colored Boss Keys",  {"Off", "On"}, {coloredBossKeysDesc},                                                                                                                                                             OptionCategory::Cosmetic);

  static std::vector<std::string> fanfareOptions = {"Off", "Only Fanfares", "Fanfares +\n                         Ocarina Music"};
  static std::vector<std::string_view> fanfareDescriptions = {fanfaresOffDesc, onlyFanfaresDesc, fanfaresOcarinaDesc};

  Option ShuffleMusic =    Option::Bool("Shuffle Music",           {"Off", "On"},    {musicRandoDesc},                                                                                                                                                          OptionCategory::Cosmetic,               0); // Off
  Option ShuffleBGM =      Option::Bool("  Shuffle BGM",           {"Off", "On"},    {shuffleBGMDesc},                                                                                                                                                          OptionCategory::Cosmetic,               1); // On
  Option ShuffleFanfares = Option::U8  ("  Shuffle Fanfares",      {fanfareOptions}, {fanfareDescriptions},                                                                                                                                                     OptionCategory::Cosmetic,               1); // Fanfares only
  Option ShuffleOcaMusic = Option::Bool("  Shuffle Ocarina Music", {"Off", "On"},    {shuffleOcaMusicDesc},                                                                                                                                                     OptionCategory::Cosmetic,               1); // On

  std::vector<Option *> cosmeticOptions = {
    &CustomTunicColors,
    &ChildTunicColor,
    &ColoredKeys,
    &ColoredBossKeys,
    &ShuffleMusic,
    &ShuffleBGM,
    &ShuffleFanfares,
    &ShuffleOcaMusic,
  };

  Menu loadSettingsPreset       = Menu::Action("Load Settings Preset",       LOAD_PRESET);
  Menu saveSettingsPreset       = Menu::Action("Save Settings Preset",       SAVE_PRESET);
  Menu deleteSettingsPreset     = Menu::Action("Delete Settings Preset",     DELETE_PRESET);
  Menu resetToDefaultSettings   = Menu::Action("Reset to Default Settings",  RESET_TO_DEFAULTS);

  std::vector<Menu *> settingsPresetItems = {
    &loadSettingsPreset,
    &saveSettingsPreset,
    &deleteSettingsPreset,
    &resetToDefaultSettings,
  };

  //Detailed Logic Options Submenu
  Menu logicSettings    = Menu::SubMenu("Logic Options",     &logicOptions);
  Menu excludeLocations = Menu::SubMenu("Exclude Locations", &excludeLocationsOptions, false);
  Menu tricks           = Menu::SubMenu("Logical Tricks",    &trickOptions, false);
  Menu glitchSettings   = Menu::SubMenu("Glitch Options",    &glitchOptions, false);
  std::vector<Menu *> detailedLogicOptions = {
    &logicSettings,
    &excludeLocations,
    &tricks,
    &glitchSettings,
  };

  Menu open                     = Menu::SubMenu("Open Settings",              &openOptions);
  Menu world                    = Menu::SubMenu("World Settings",             &worldOptions);
  Menu shuffle                  = Menu::SubMenu("Shuffle Settings",           &shuffleOptions);
  Menu shuffleDungeonItems      = Menu::SubMenu("Shuffle Dungeon Items",      &shuffleDungeonItemOptions);
  Menu detailedLogic            = Menu::SubMenu("Detailed Logic Settings",    &detailedLogicOptions);
  Menu startingInventory        = Menu::SubMenu("Starting Inventory",         &startingInventoryOptions, false);
  Menu timesaverSettings        = Menu::SubMenu("Timesaver Settings",         &timesaverOptions);
  Menu miscSettings             = Menu::SubMenu("Misc Settings",              &miscOptions);
  Menu itemPoolSettings         = Menu::SubMenu("Item Pool Settings",         &itemPoolOptions);
  Menu itemUsabilitySettings    = Menu::SubMenu("Item Usability Settings",    &itemUsabilityOptions);
  Menu settingsPresets          = Menu::SubMenu("Settings Presets",           &settingsPresetItems);
  Menu cosmetics                = Menu::SubMenu("Cosmetic Settings",          &cosmeticOptions);
  Menu generateRandomizer       = Menu::Action ("Generate Randomizer",        GENERATE_MODE);

  //adding a menu with no options crashes, might fix later
  std::vector<Menu *> mainMenu = {
    &open,
    &world,
    &shuffle,
    &shuffleDungeonItems,
    &timesaverSettings,
    &detailedLogic,
    &startingInventory,
    &miscSettings,
    &itemPoolSettings,
    &itemUsabilitySettings,
    &cosmetics,
    &settingsPresets,
    &generateRandomizer,
  };

  //declared here, set in fill.cpp
  u32 LinksPocketRewardBitMask = 0;
  std::array<u32, 9> rDungeonRewardOverrides{};

  //declared here, set in menu.cpp
  u8 PlayOption;

  //Fills and returns a SettingsContext struct.
  //This struct is written to the code.ips patch and allows the game
  //to read what settings the player selected to make in game decisions.
  SettingsContext FillContext() {
    SettingsContext ctx = {};
    ctx.hashIndexes[0] = hashIconIndexes[0];
    ctx.hashIndexes[1] = hashIconIndexes[1];
    ctx.hashIndexes[2] = hashIconIndexes[2];
    ctx.hashIndexes[3] = hashIconIndexes[3];
    ctx.hashIndexes[4] = hashIconIndexes[4];

    ctx.logic                = Logic.Value<u8>();
/*    ctx.openForest           = OpenForest.Value<u8>();
    ctx.openKakariko         = OpenKakariko.Value<u8>();
    ctx.openDoorOfTime       = OpenDoorOfTime.Value<u8>();
    ctx.zorasFountain        = ZorasFountain.Value<u8>();
    ctx.gerudoFortress       = GerudoFortress.Value<u8>();
    ctx.rainbowBridge        = Bridge.Value<u8>();
    ctx.bridgeStoneCount     = BridgeStoneCount.Value<u8>();
    ctx.bridgeMedallionCount = BridgeMedallionCount.Value<u8>();
    ctx.bridgeRewardCount    = BridgeRewardCount.Value<u8>();
    ctx.bridgeDungeonCount   = BridgeDungeonCount.Value<u8>();
    ctx.bridgeTokenCount     = BridgeTokenCount.Value<u8>();
    ctx.randomGanonsTrials   = (RandomGanonsTrials) ? 1 : 0;
    ctx.ganonsTrialsCount    = GanonsTrialsCount.Value<u8>();

    ctx.startingAge          = StartingAge.Value<u8>();
    ctx.resolvedStartingAge  = ResolvedStartingAge;
    ctx.shuffleDungeonEntrances = (ShuffleDungeonEntrances) ? 1 : 0;
    ctx.shuffleOverworldEntrances = (ShuffleOverworldEntrances) ? 1 : 0; */
    ctx.bombchusInLogic         = (BombchusInLogic) ? 1 : 0;
    ctx.ammoDrops            = AmmoDrops.Value<u8>();
    ctx.heartDropRefill      = HeartDropRefill.Value<u8>();
//    ctx.randomMQDungeons        = (MQDungeonCount.Value<u8>() == 13) ? 1 : 0;
//    ctx.mqDungeonCount          = MQSet;

    ctx.shuffleRewards       = ShuffleRewards.Value<u8>();
    ctx.linksPocketItem      = LinksPocketItem.Value<u8>();
    ctx.shuffleSongs         = ShuffleSongs.Value<u8>();
    ctx.tokensanity          = Tokensanity.Value<u8>();
    ctx.scrubsanity          = Scrubsanity.Value<u8>();
    ctx.shuffleCows          = (ShuffleCows) ? 1 : 0;
    ctx.shuffleKokiriSword   = (ShuffleKokiriSword) ? 1 : 0;
    ctx.shuffleOcarinas      = (ShuffleOcarinas) ? 1 : 0;
//    ctx.shuffleWeirdEgg      = (ShuffleWeirdEgg) ? 1 : 0;
//    ctx.shuffleGerudoToken   = (ShuffleGerudoToken) ? 1 : 0;
    ctx.shuffleMagicBeans    = (ShuffleMagicBeans) ? 1 : 0;
//    ctx.shuffleMerchants     = ShuffleMerchants.Value<u8>();
//    ctx.shuffleAdultTradeQuest = (ShuffleAdultTradeQuest) ? 1 : 0;

    ctx.mapsAndCompasses     = MapsAndCompasses.Value<u8>();
    ctx.keysanity            = Keysanity.Value<u8>();
//    ctx.gerudoKeys           = GerudoKeys.Value<u8>();
    ctx.bossKeysanity        = BossKeysanity.Value<u8>();

    ctx.skipEponaRace        = (SkipEponaRace) ? 1 : 0;
    ctx.skipMinigamePhases   = (SkipMinigamePhases) ? 1 : 0;
    ctx.freeScarecrow        = (FreeScarecrow) ? 1 : 0;
    ctx.quickText            = QuickText.Value<u8>();
    ctx.skipSongReplays      = SkipSongReplays.Value<u8>();

    ctx.gossipStoneHints     = GossipStoneHints.Value<u8>();
    ctx.damageMultiplier     = DamageMultiplier.Value<u8>();
    ctx.chestAnimations      = (ChestAnimations) ? 1 : 0;
    ctx.chestSize            = (ChestSize) ? 1 : 0;
    ctx.generateSpoilerLog   = (GenerateSpoilerLog) ? 1 : 0;
    ctx.ingameSpoilers       = (IngameSpoilers) ? 1 : 0;
    ctx.menuOpeningButton    = MenuOpeningButton.Value<u8>();
    ctx.randomTrapDmg        = RandomTrapDmg.Value<u8>();

    ctx.itemPoolValue        = ItemPoolValue.Value<u8>();
    ctx.iceTrapValue         = IceTrapValue.Value<u8>();

    ctx.customTunicColors    = (CustomTunicColors) ? 1 : 0;
    ctx.coloredKeys          = (ColoredKeys) ? 1 : 0;
    ctx.coloredBossKeys      = (ColoredBossKeys) ? 1 : 0;

    ctx.linksPocketRewardBitMask = LinksPocketRewardBitMask;

    //Starting Inventory
    ctx.startingConsumables   = (StartingConsumables) ? 1 : 0;
    ctx.startingMaxRupees     = (StartingMaxRupees) ? 1 : 0;
    ctx.startingNutCapacity   = StartingNutCapacity.Value<u8>();
    ctx.startingBombBag       = StartingBombBag.Value<u8>();
    ctx.startingBombchus      = StartingBombchus.Value<u8>();
    ctx.startingBow           = StartingBow.Value<u8>();
    ctx.startingFireArrows    = StartingFireArrows.Value<u8>();
    ctx.startingIceArrows     = StartingIceArrows.Value<u8>();
    ctx.startingLightArrows   = StartingLightArrows.Value<u8>();
    ctx.startingLensOfTruth   = StartingLensOfTruth.Value<u8>();
    ctx.startingMagicBean     = StartingMagicBean.Value<u8>();
    ctx.startingBottle1       = StartingBottle1.Value<u8>();
    ctx.startingBottle2       = StartingBottle2.Value<u8>();
    ctx.startingBottle3       = StartingBottle3.Value<u8>();
    ctx.startingBottle4       = StartingBottle4.Value<u8>();
    ctx.startingBottle5       = StartingBottle5.Value<u8>();
    ctx.startingBottle6       = StartingBottle6.Value<u8>();
    ctx.startingBottle7       = StartingBottle7.Value<u8>();
    ctx.startingOcarina       = StartingOcarina.Value<u8>();
    ctx.startingKokiriSword   = StartingKokiriSword.Value<u8>();
    ctx.startingGreatFairySword = StartingGreatFairySword.Value<u8>();
    ctx.startingHealth        = (StartingHealth.Value<u8>() + 2) % 20 + 1;
    ctx.startingMagicMeter    = StartingMagicMeter.Value<u8>();
    ctx.startingDoubleDefense = StartingDoubleDefense.Value<u8>();

    //Starting Quest Items
    ctx.startingQuestItems |= StartingSonataOfAwakening.Value<u8>()   << 6;
    ctx.startingQuestItems |= StartingGoronsLullaby.Value<u8>()     << 7;
    ctx.startingQuestItems |= StartingNewWaveBossaNova.Value<u8>()  << 8;
    ctx.startingQuestItems |= StartingElegyOfEmptiness.Value<u8>()  << 9;
    ctx.startingQuestItems |= StartingSongOfHealing.Value<u8>() << 10;
    ctx.startingQuestItems |= StartingSongOfSoaring.Value<u8>()   << 11;
    ctx.startingQuestItems |= StartingOathToOrder.Value<u8>()    << 12;
    ctx.startingQuestItems |= StartingEponasSong.Value<u8>()       << 13;
    ctx.startingQuestItems |= StartingDoubleSong.Value<u8>()       << 14;
    ctx.startingQuestItems |= StartingInvertedSong.Value<u8>()      << 15;
    ctx.startingQuestItems |= StartingSongOfTime.Value<u8>()       << 16;
    ctx.startingQuestItems |= StartingSongOfStorms.Value<u8>()     << 17;
    ctx.startingDungeonReward |= StartingOdolwaRemains.Value<u8>()    << 18;
    ctx.startingDungeonReward |= StartingGohtRemains.Value<u8>()        << 19;
    ctx.startingDungeonReward |= StartingGyorgRemains.Value<u8>()     << 20;
    ctx.startingDungeonReward |= StartingTwinmoldRemains.Value<u8>()   << 5;

    ctx.startingTokens        = StartingSwampToken.Value<u8>();
    ctx.startingTokens        = StartingOceanToken.Value<u8>();


    //Starting Equipment
    ctx.startingEquipment |= StartingKokiriSword.Value<u8>();
    ctx.startingEquipment |= (StartingGreatFairySword.Value<u8>() ? 1: 0) << 2;
    ctx.startingEquipment |= StartingHerosShield.Value<u8>()  << 5;
    ctx.startingEquipment |= StartingMirrorShield.Value<u8>()  << 6;
 
    //Starting Upgrades
    ctx.startingUpgrades |= StartingWallet.Value<u8>() << 12;

    return ctx;
  }

  //Set default cosmetics where the default is not the first option
  static void SetDefaultCosmetics() {
    for (auto op : cosmeticOptions) {
      op->SetToDefault();
    }
  }

  //One-time initialization
  void InitSettings() {
    //Set up token options
    //TODO: Create new 'number range' option type so this isn't necessary
    std::vector<std::string> StokenOptions;
    StokenOptions.reserve(31);
    for (int i = 0; i <= 30; i++) {
      StokenOptions.push_back(std::to_string(i));
    }
    std::vector<std::string> OtokenOptions;
    OtokenOptions.reserve(31);
    for (int i = 0; i <= 30; i++) {
      OtokenOptions.push_back(std::to_string(i));
    }
	StartingSwampTokenToken.SetOptions(StokenOptions);
    StartingOceanToken.SetOptions(OtokenOptions);
    
    //Create Location Exclude settings
    AddExcludedOptions();

    SetDefaultSettings();
  }

  //Set default settings for all settings
  void SetDefaultSettings() {
    for (auto op : openOptions) {
      op->SetToDefault();
    }
    for (auto op : worldOptions) {
      op->SetToDefault();
    }
    for (auto op : shuffleOptions) {
      op->SetToDefault();
    }
    for (auto op : shuffleDungeonItemOptions) {
      op->SetToDefault();
    }
    for (auto op : timesaverOptions) {
      op->SetToDefault();
    }
    for (auto op : miscOptions) {
      op->SetToDefault();
    }
    for (auto op : itemUsabilityOptions) {
      op->SetToDefault();
    }
    for (auto op : itemPoolOptions) {
      op->SetToDefault();
    }
    for (auto op : excludeLocationsOptions) {
      op->SetToDefault();
    }
    for (auto op : startingInventoryOptions) {
      op->SetToDefault();
    }
    for (auto op : logicOptions) {
      op->SetToDefault();
    }
    for (auto op : trickOptions) {
      op->SetToDefault();
    }
    for (auto op : glitchOptions) {
      op->SetToDefault();
    }

    for (auto loc : allLocations) {
      Location(loc)->GetExcludedOption()->SetToDefault();
    }
    //Don't let users exclude these locations
    //TODO: Make sure the defaults are set appropriately for these?
	//Also TODO: make sure some checks cant be skpped?
//    Location(HC_ZELDAS_LETTER)->GetExcludedOption()->Hide();
//    Location(MARKET_BOMBCHU_BOWLING_BOMBCHUS)->GetExcludedOption()->Hide();
    Location(GANON)->GetExcludedOption()->Hide();

    SetDefaultCosmetics();
  }

  //Include and Lock the desired locations
  static void IncludeAndHide(std::vector<LocationKey> locations) {
    for (LocationKey loc : locations) {
      Location(loc)->GetExcludedOption()->SetSelectedIndex(INCLUDE);
      Location(loc)->GetExcludedOption()->Hide();
    }
  }

  //Unlock the desired locations
  static void Unhide(std::vector<LocationKey> locations) {
    for (LocationKey loc : locations) {
      Location(loc)->GetExcludedOption()->Unhide();
    }
  }


  //Used for Starting Inventory options, enables/disables the options or expands/collapses each category based on their index number
  void CollapseCategory(Option startingInventorySections, int startNum, int endNum) {
    for(int i = startNum; i < endNum ;++i){
      switch(startingInventorySections.Value<u8>()) {
        case 0:
          startingInventoryOptions[i]->Hide();
          startingInventoryOptions[i]->SetSelectedIndex(0);
          break;
        case 1:
          startingInventoryOptions[i]->Hide();
          startingInventoryOptions[i]->SetSelectedIndex((startingInventoryOptions[i]->GetOptionCount())-1);
          break;
        case 2:
          startingInventoryOptions[i]->Unhide();
          break;
      }
    }
  }

  //This function will hide certain locations from the Excluded Locations
  //menu if the player's current settings would require non-junk to be placed
  //at those locations. Excluded locations will have junk placed at them.
  static void ResolveExcludedLocationConflicts() {

    std::vector<LocationKey> shopLocations = GetLocations(everyPossibleLocation, Category::cShop);
    //For now, just always hide shop locations, as not sure how to handle hiding them-
    //1-4 should always be hidden, while the others should be settings dependent, but random shopsanity makes that more complicated...
    //Excluded shop locations are also wonky
    IncludeAndHide(shopLocations);

    //Force include song locations
    std::vector<LocationKey> songLocations = GetLocations(everyPossibleLocation, Category::cSong);
    std::vector<LocationKey> songDungeonRewards = GetLocations(everyPossibleLocation, Category::cSongDungeonReward);

    //Unhide all song locations, then lock necessary ones
    Unhide(songLocations);
    Unhide(songDungeonRewards);

    if (ShuffleSongs.Is(SONGSHUFFLE_SONG_LOCATIONS)) {
      IncludeAndHide(songLocations);
    } else if (ShuffleSongs.Is(SONGSHUFFLE_DUNGEON_REWARDS)) {
      IncludeAndHide(songDungeonRewards);
    }

    //Force Include Vanilla Skulltula locations
    std::vector<LocationKey> SwampSkulltulaLocations = GetLocations(everyPossibleLocation, Category::cSwampSkulltula);
    std::vector<LocationKey> OceanSkulltulaLocations = GetLocations(everyPossibleLocation, Category::cOceanSkulltula);
    Unhide(SwampSkulltulaLocations);
	Unhide(OceanSkulltulaLocations);
    if (Tokensanity.IsNot(TOKENSANITY_ALL_TOKENS)) {
      if (Tokensanity.Is(TOKENSANITY_OVERWORLD)) {
        //filter overworld skulls so we're just left with dungeons
        FilterAndEraseFromPool(SwampSkulltulaLocations, [](const LocationKey loc1){return Location(loc1)->GetScene() >= 0x0A;});
		FilterAndEraseFromPool(OceanSkulltulaLocations, [](const LocationKey loc2){return Location(loc2)->GetScene() >= 0x0A;});
      } else if (Tokensanity.Is(TOKENSANITY_DUNGEONS)) {
        //filter dungeon skulls so we're just left with overworld
        FilterAndEraseFromPool(SwampSkulltulaLocations, [](const LocationKey loc1){return Location(loc1)->GetScene() < 0x0A;});
		FilterAndEraseFromPool(OceanSkulltulaLocations, [](const LocationKey loc2){return Location(loc2)->GetScene() < 0x0A;});
      }
      IncludeAndHide(SwampSkulltulaLocations);
	  IncludeAndHide(OceanSkulltulaLocations);
    }

    //Force Include scrubs if Scrubsanity is Off
    std::vector<LocationKey> scrubLocations = GetLocations(everyPossibleLocation, Category::cDekuScrub, Category::cDekuScrubUpgrades);
    if (Scrubsanity.Is(OFF)) {
      IncludeAndHide(scrubLocations);
    } else {
      Unhide(scrubLocations);
    }

    //Force include Cows if Shuffle Cows is Off
    std::vector<LocationKey> cowLocations = GetLocations(everyPossibleLocation, Category::cCow);
    if (ShuffleCows) {
      Unhide(cowLocations);
    } else {
      IncludeAndHide(cowLocations);
    }

    //Force include the Kokiri Sword Chest if Shuffle Kokiri Sword is Off
    if (ShuffleKokiriSword) {
      Unhide({HMS_KOKIRI_SWORD});
    } else {
      IncludeAndHide({HMS_KOKIRI_SWORD});
    }

    //Force include the ocarina locations if Shuffle Ocarinas is Off
    std::vector<LocationKey> ocarinaLocations = {LW_GIFT_FROM_SARIA, HF_OCARINA_OF_TIME_ITEM};
    if (ShuffleOcarinas) {
      Unhide(ocarinaLocations);
    } else {
      IncludeAndHide(ocarinaLocations);
    }

    //Force include Magic Bean salesman if Shuffle Magic Beans is off
    if (ShuffleMagicBeans) {
      Unhide({ZR_MAGIC_BEAN_SALESMAN});
    } else {
      IncludeAndHide({ZR_MAGIC_BEAN_SALESMAN});
    }
    }
    //Force include Map and Compass Chests when Vanilla
    std::vector<LocationKey> mapChests = GetLocations(everyPossibleLocation, Category::cVanillaMap);
    std::vector<LocationKey> compassChests = GetLocations(everyPossibleLocation, Category::cVanillaCompass);
    if (MapsAndCompasses.Is(MAPSANDCOMPASSES_VANILLA)) {
      IncludeAndHide(mapChests);
      IncludeAndHide(compassChests);
    } else {
      Unhide(mapChests);
      Unhide(compassChests);
    }

    //Force include Vanilla Small Key Locations (except gerudo Fortress) on Vanilla Keys
    std::vector<LocationKey> smallKeyChests = GetLocations(everyPossibleLocation, Category::cVanillaSmallKey);
    if (Keysanity.Is(KEYSANITY_VANILLA)) {
      IncludeAndHide(smallKeyChests);
    } else {
      Unhide(smallKeyChests);
    }

    //Force include Boss Key Chests if Boss Keys are Vanilla
    std::vector<LocationKey> bossKeyChests = GetLocations(everyPossibleLocation, Category::cVanillaBossKey);
    if (BossKeysanity.Is(BOSSKEYSANITY_VANILLA)) {
      IncludeAndHide(bossKeyChests);
    } else {
      Unhide(bossKeyChests);
    }


  u8 DungeonsOfType(u8 type) {
    u8 count = 0;

    for (Option *option : dungeonOptions) {
      count += (option->Value<u8>() == type) ? 1 : 0;
    }

    return count;
  }

  //Hide certain settings if they aren't relevant or Lock settings if they
  //can't be changed due to another setting that was chosen. (i.e. Closed Forest
  //will force Starting Age to Child).
  void ForceChange(u32 kDown, Option* currentSetting) {

    //Groups the item categories; bottles are handled separately because the proper item is Empty Bottle (1)
    CollapseCategory(StartingInventoryToggle, 3, 23);
    CollapseCategory(StartingSongsToggle, 29, 41);
    CollapseCategory(StartingUpgradesToggle, 42, 56);
    CollapseCategory(StartingQuestToggle, 57, 66);
    for(int i = 23; i < 28 ;++i){
      switch(StartingInventoryToggle.Value<u8>()) {
        case 0:
          startingInventoryOptions[i]->Hide();
          startingInventoryOptions[i]->SetSelectedIndex(0);
          break;
        case 1:
          startingInventoryOptions[i]->Hide();
          startingInventoryOptions[i]->SetSelectedIndex(1);
          break;
        case 2:
          startingInventoryOptions[i]->Unhide();
          break;
      }
    }

    //Only hide the options for now, select them later in UpdateSettings()
    RandomizeAllSettings();
      

    //Force Link's Pocket Item to be a dungeon reward if Shuffle Rewards is end of dungeons
    if (ShuffleRewards.Is(REWARDSHUFFLE_END_OF_DUNGEON)) {
      LinksPocketItem.Lock();
      LinksPocketItem.SetSelectedIndex(LINKSPOCKETITEM_DUNGEON_REWARD);
      if (RandomizeShuffle) {
        //Even if it is supposed to be locked, still hide it to keep the surprise
        LinksPocketItem.Unlock();
        LinksPocketItem.Hide();
      }
    } else {
      LinksPocketItem.Unlock();
    }

      //Only show Medallion Count if setting Ganons Boss Key to LACS Medallions
      if (GanonsBossKey.Is(GANONSBOSSKEY_LACS_MEDALLIONS)) {
        LACSMedallionCount.Unhide();
      } else {
        LACSMedallionCount.SetSelectedIndex(6);
        LACSMedallionCount.Hide();
      }

      //Only show Stone Count if setting Ganons Boss Key to LACS Stones
      if (GanonsBossKey.Is(GANONSBOSSKEY_LACS_STONES)) {
        LACSStoneCount.Unhide();
      } else {
        LACSStoneCount.SetSelectedIndex(3);
        LACSStoneCount.Hide();
      }

      //Only show Reward Count if setting Ganons Boss Key to LACS Rewards
      if (GanonsBossKey.Is(GANONSBOSSKEY_LACS_REWARDS)) {
        LACSRewardCount.Unhide();
      } else {
        LACSRewardCount.SetSelectedIndex(9);
        LACSRewardCount.Hide();
      }

      //Only show Dungeon Count if setting Ganons Boss Key to LACS Dungeons
      if (GanonsBossKey.Is(GANONSBOSSKEY_LACS_DUNGEONS)) {
        LACSDungeonCount.Unhide();
      } else {
        LACSDungeonCount.SetSelectedIndex(8);
        LACSDungeonCount.Hide();
      }

      //Only show Token Count if setting Ganons Boss Key to LACS Tokens
      if (GanonsBossKey.Is(GANONSBOSSKEY_LACS_TOKENS)) {
        LACSTokenCount.Unhide();
      } else {
        LACSTokenCount.SetSelectedIndex(100);
        LACSTokenCount.Hide();
      }
    }

    //Only show Skip Song Replays if Quick Text is enabled
    if (QuickText.Is(QUICKTEXT_VANILLA)) {
      SkipSongReplays.SetSelectedIndex(DONT_SKIP);
      SkipSongReplays.Hide();
    } else {
      SkipSongReplays.Unhide();
    }

    //Only show hint options if hints are enabled
    if (GossipStoneHints.Is(HINTS_NO_HINTS)) {
      ClearerHints.Hide();
      HintDistribution.Hide();
    } else {
      ClearerHints.Unhide();
      HintDistribution.Unhide();
    }

    if (RemoveDoubleDefense) {
      StartingDoubleDefense.SetSelectedIndex(0);
      StartingDoubleDefense.Lock();
    } else {
      StartingDoubleDefense.Unlock();
    }


    //Tunic Colors
    if (CustomTunicColors) {
      ChildTunicColor.Unhide();
      
    } else {
      ChildTunicColor.Hide();
      ChildTunicColor.SetSelectedIndex(3);  //Kokiri Green
     }

    // Music
    if (ShuffleMusic) {
      ShuffleBGM.Unhide();
      ShuffleFanfares.Unhide();
      if(ShuffleFanfares.Is(2)) // Fanfares + ocarina
        ShuffleOcaMusic.Hide();
      else
        ShuffleOcaMusic.Unhide();
    } else {
      ShuffleBGM.Hide();
      ShuffleFanfares.Hide();
      ShuffleOcaMusic.Hide();
    }

    ResolveExcludedLocationConflicts();
  }


  // Randomizes all settings in a category if chosen
  // Hides all relevant options
  void RandomizeAllSettings(const bool selectOptions /*= false*/) {

    // Open Settings
    if (RandomizeOpen) {
      // Skip RandomizeOpen Option
      for (size_t i = 1; i < openOptions.size(); i++) {
        //hide options
        openOptions[i]->Hide();

        //randomize options
        if (selectOptions) {
          openOptions[i]->SetSelectedIndex(Random(0,openOptions[i]->GetOptionCount()));
        }
      }
      
    }
    else {
      for (size_t i = 1; i < openOptions.size(); i++) {
        openOptions[i]->Unhide();
      }
    }

   
    // Shuffle Settings
    if (RandomizeShuffle) {
      // Still displays if previously locked
      LinksPocketItem.Unlock();
      // Skip RandomizeShuffle Option
      for (size_t i=1; i < shuffleOptions.size(); i++) {
        shuffleOptions[i]->Hide();
        //randomize options
        if (selectOptions) {
          shuffleOptions[i]->SetSelectedIndex(Random(0,shuffleOptions[i]->GetOptionCount()));
        }
      }
      // Double check that this is the case in case of randomization on init
      if (ShuffleRewards.Is(REWARDSHUFFLE_END_OF_DUNGEON)) {
        LinksPocketItem.SetSelectedIndex(LINKSPOCKETITEM_DUNGEON_REWARD);
      }
    }
    else {
      for (size_t i=1; i < shuffleOptions.size(); i++) {
        shuffleOptions[i]->Unhide();
      }
    }

    // Dungeon Shuffle Settings
    if (RandomizeDungeon) {
      // Skip RandomizeDungeon Option
      for (size_t i=1; i < shuffleDungeonItemOptions.size(); i++) {
        shuffleDungeonItemOptions[i]->Hide();
        //randomize options
        if (selectOptions) {
          shuffleDungeonItemOptions[i]->SetSelectedIndex(Random(0,shuffleDungeonItemOptions[i]->GetOptionCount()));
        }
      }
    }
    else {
      for (size_t i=1; i < shuffleDungeonItemOptions.size(); i++) {
        shuffleDungeonItemOptions[i]->Unhide();
      }
    }

    //resolve any settings that need to change
    if (selectOptions) {
      ForceChange(0, nullptr);
    }
  }

  //eventual settings
  bool ShuffleInteriorEntrances         = false;
  bool ShuffleSpecialIndoorEntrances    = false;

  template <typename colorsArray>
  static void ChooseFinalColor(const Option& cosmeticOption, std::string& colorStr, const colorsArray& colors) {
    if (cosmeticOption.Is(CUSTOM_COLOR)) {
      colorStr = GetCustomColor(cosmeticOption.GetSelectedOptionText());
    } else if (cosmeticOption.Is(RANDOM_CHOICE)) {
      colorStr = colors[rand() % colors.size()]; //use default rand to not interfere with seed
    } else if (cosmeticOption.Is(RANDOM_COLOR)) {
      colorStr = RandomColor();
    } else {
      colorStr = colors[cosmeticOption.GetSelectedOptionIndex() - NON_COLOR_COUNT];
    }
  }

  //Function to update cosmetics options depending on choices
  static void UpdateCosmetics() {

    ChooseFinalColor(ChildTunicColor, finalChildTunicColor, tunicColors);
    }

  //Function to set flags depending on settings
  void UpdateSettings() {

    RandomizeAllSettings(true); //now select any random options instead of just hiding them

    //shuffle the dungeons and then set MQ for as many as necessary
    auto dungeons = dungeonList;
    if (SetDungeonTypes) {
      u8 dungeonCount = 0;
      

      for (size_t i = 0; i < dungeons.size(); i++) {
        

        dungeonOptions[i]->Value<u8>());
      }
	UpdateCosmetics();

    //If vanilla logic, we want to set all settings which unnecessarily modify vanilla behavior to off
    if (Logic.Is(LOGIC_VANILLA)) {
      ShuffleRewards.SetSelectedIndex(0);
      LinksPocketItem.SetSelectedIndex(0);
      ShuffleSongs.SetSelectedIndex(0);
      Scrubsanity.SetSelectedIndex(0);
      ShuffleCows.SetSelectedIndex(0);
      ShuffleMagicBeans.SetSelectedIndex(0);
      Keysanity.SetSelectedIndex(3); //Set small keys to any dungeon so FiT basement door will be locked
      GossipStoneHints.SetSelectedIndex(0);
    }

    InitMusicRandomizer();
    if (ShuffleMusic) {
      if (ShuffleBGM) {
        ShuffleSequences(SeqType::SEQ_BGM);
      }

      if (ShuffleFanfares.Is(2)) {
        ShuffleSequences(SeqType::SEQ_FANFARE | SeqType::SEQ_OCARINA);
      } else {
        if (ShuffleFanfares.Is(1)) {
          ShuffleSequences(SeqType::SEQ_FANFARE);
        }

        if (ShuffleOcaMusic) {
          ShuffleSequences(SeqType::SEQ_OCARINA);
        }
      }
    }
  }

  //If this is an option menu, return th options
  //Else, recursively call each sub menu of this sub menu
  const std::vector<Menu*> GetMenusRecursive(Menu* menu) {
    std::vector<Menu*> menus;
    if (menu->mode == OPTION_SUB_MENU) {
      menus.push_back(menu);
    } else if (menu->mode == SUB_MENU) {
        for (Menu* subMenu : *menu->itemsList) {
          std::vector<Menu*> foundMenus = GetMenusRecursive(subMenu);
          menus.insert(menus.end(), foundMenus.begin(), foundMenus.end());
        }
    }
    return menus;
  }

  //Recursively look through each menu from the main menu to get all settings
  const std::vector<Menu*> GetAllMenus() {
    std::vector<Menu*> allMenus;
    for (Menu* menu : Settings::mainMenu) {
      std::vector<Menu*> foundMenus = GetMenusRecursive(menu);
      allMenus.insert(allMenus.end(), foundMenus.begin(), foundMenus.end());
    }
    return allMenus;
  }

} // namespace Settings
