#pragma once
#include <string_view>
#include <vector>

using string_view = std::string_view;

extern string_view openRandomize;
extern string_view worldRandomize;
extern string_view shuffleRandomize;
extern string_view dungeonRandomize;

extern string_view logicGlitchless;
extern string_view logicGlitched;
extern string_view logicNoLogic;
extern string_view logicVanilla;

extern string_view shuffleEntrancesDesc;

extern string_view dungeonEntrancesDesc;

extern string_view overworldEntrancesDesc;

extern string_view bombchuLogicDesc;

extern string_view defaultAmmoDropsDesc;
extern string_view bombchuDropsDesc;
extern string_view noAmmoDropsDesc;

extern string_view defaultHeartDropsDesc;
extern string_view noHeartDropsDesc;
extern string_view noHeartRefillDesc;
extern string_view scarceHeartsDesc;

extern string_view shuffleRewardsEndOfDungeon;
extern string_view shuffleRewardsAnyDungeon;
extern string_view shuffleRewardsOverworld;
extern string_view shuffleRewardsAnywhere;

extern string_view linksPocketDungeonReward;
extern string_view linksPocketAdvancement;
extern string_view linksPocketAnything;
extern string_view linksPocketNothing;
extern string_view linksPocketDefault;

extern string_view songsSongLocations;
extern string_view songsDungeonRewards;
extern string_view songsAllLocations;

extern string_view shopsOff;
extern string_view shopsZero;
extern string_view shopsOne;
extern string_view shopsTwo;
extern string_view shopsThree;
extern string_view shopsFour;
extern string_view shopsRandom;

extern string_view tokensOff;
//extern string_view tokensDungeon;
extern string_view tokensOverworld;
extern string_view tokensAllTokens;

extern string_view scrubsOff;
extern string_view scrubsAffordable;
extern string_view scrubsExpensive;
extern string_view scrubsRandomPrices;

extern string_view shuffleCowsDesc;

extern string_view kokiriSwordDesc;

extern string_view ocarinasDesc;

extern string_view magicBeansDesc;

extern string_view mapCompassStartWith;
extern string_view mapCompassVanilla;
extern string_view mapCompassOwnDungeon;
extern string_view mapCompassAnyDungeon;
extern string_view mapCompassOverworld;
extern string_view mapCompassAnywhere;

extern string_view smallKeyStartWith;
extern string_view smallKeyVanilla;
extern string_view smallKeyOwnDungeon;
extern string_view smallKeyAnyDungeon;
extern string_view smallKeyOverworld;
extern string_view smallKeyAnywhere;

extern string_view bossKeyStartWith;
extern string_view bossKeyVanilla;
extern string_view bossKeyOwnDungeon;
extern string_view bossKeyAnyDungeon;
extern string_view bossKeyOverworld;
extern string_view bossKeyAnywhere;

extern string_view skipMinigamePhasesDesc;

extern string_view freeScarecrowDesc;

extern string_view quickTextDesc0;
extern string_view quickTextDesc1;
extern string_view quickTextDesc2;
extern string_view quickTextDesc3;
extern string_view skipSongReplaysDesc;

extern string_view gossipStonesHintsDesc;

extern string_view clearerHintsDesc;

extern string_view uselessHintsDesc;
extern string_view balancedHintsDesc;
extern string_view strongHintsDesc;
extern string_view veryStrongHintsDesc;

extern string_view damageMultiDesc;

extern string_view locationsReachableDesc;

extern string_view chestAnimDesc;

extern string_view chestSizeDesc;

extern string_view ingameSpoilersShowDesc;
extern string_view ingameSpoilersHideDesc;

extern string_view menuButtonDesc;

extern string_view startWithConsumablesDesc;

extern string_view startWithMaxRupeesDesc;

extern string_view itemPoolPlentiful;
extern string_view itemPoolBalanced;
extern string_view itemPoolScarce;
extern string_view itemPoolMinimal;

extern string_view iceTrapsOff;
extern string_view iceTrapsNormal;
extern string_view iceTrapsExtra;
extern string_view iceTrapsMayhem;
extern string_view iceTrapsOnslaught;

extern string_view removeDDDesc;

extern string_view coloredKeysDesc;
extern string_view coloredBossKeysDesc;

extern string_view musicRandoDesc;
extern string_view shuffleBGMDesc;
extern string_view fanfaresOffDesc;
extern string_view onlyFanfaresDesc;
extern string_view fanfaresOcarinaDesc;
extern string_view shuffleOcaMusicDesc;

extern string_view randomTrapDmgDesc;
extern string_view basicTrapDmgDesc;
extern string_view advancedTrapDmgDesc;


extern string_view ToggleAllTricksDesc;

extern string_view ToggleLogicNoneDesc;
extern const std::vector<string_view> GlitchDifficulties;
