#include "setting_descriptions.hpp"

//Setting descriptions are mostly copied from OoT Randomizer tooltips with minor edits

/*------------------------------
|      RANDOMIZE SETTINGS      |                            *SCREEN WIDTH*
------------------------------*/       /*--------------------------------------------------*/
string_view openRandomize             = "Randomize all Open Settings except for Logic rules";
string_view worldRandomize            = "Randomize all World Settings except for MQ\n"     //
                                        "dungeons";                                        //
string_view shuffleRandomize          = "Randomize all Shuffle Settings";                  //
string_view dungeonRandomize          = "Randomize all Dungeon Shuffle Settings";          //
                                                                                           //
/*------------------------------                                                           //
|            LOGIC             |                                                           //
------------------------------*/                                                           //
string_view logicGlitchless           = "No glitches are required, but may require some\n" //
                                        "minor tricks. Add minor tricks to consider for\n" //
                                        "logic in Logical Tricks.";                        //
string_view logicGlitched             = "The glitches you enable at the set difficulty\n"  //
                                        "or below may be required.\n"                      //
                                        "\n"                                               //
                                        "In development, but still usable.";               //
string_view logicNoLogic              = "Maximize randomization, All locations are\n"      //
                                        "considered available. MAY BE IMPOSSIBLE TO BEAT.";//
string_view logicVanilla              = "For those who want to play the game normally but\n"
                                        "with the improvements of the randomizer. All\n"   //
                                        "locations will contain their vanilla items. This\n"
                                        "supercedes all item shuffle, logic, hint, and\n"  //
                                        "item pool settings. You can still use non-vanilla\n"
                                        "world settings such as adult start or entrance\n" //
                                        "shuffle, but the game may require glitches to\n"  //
                                        "complete if you do.";                             //

/*------------------------------                                                           //
|      SHUFFLE ENTRANCES       |                                                           //
------------------------------*/                                                           //
string_view shuffleEntrancesDesc      = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Shuffle where the entrances between areas lead to."
                                        "If turned on, select which kinds of entrances you\n"
                                        "want shuffled in the options below.";             //
                                                                                           //
/*------------------------------                                                           //
|       DUNGEON ENTRANCES      |                                                           //
------------------------------*/                                                           //
string_view dungeonEntrancesDesc =      "**OPTION CURRENTLY WIP**\n"                       //
                                        "Shuffle the pool of dungeon entrances, \n"        //
                                        "Stone Tower Temple is always Vanilla\n"           //
                                        "But Inverted Stone Tower Temple is Randomzied\n"; //                                    //
                                                                                           //
/*------------------------------                                                           //
|      OVERWORLD ENTRANCES     |                                                           //
------------------------------*/                                                           //
string_view overworldEntrancesDesc    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Shuffle the pool of Overworld entrances, which\n" //
                                        "corresponds to almost all loading zones between\n"//
                                        "Overworld areas.\n";                              //
/*------------------------------                                                           //
|      BOMBCHUS IN LOGIC       |                                                           //
------------------------------*/                                                           //
string_view bombchuLogicDesc          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Bombchus are properly considered in logic.\n"     //
                                        "They can be replenished in shops, or through\n"   //
                                        "bombchu drops, if those are enabled.\n"           //
                                        "\n";                                              //
/*------------------------------                                                           //
|          AMMO DROPS          |                                                           //
------------------------------*/                                                           //
string_view defaultAmmoDropsDesc      = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Bombs, arrows, seeds, nuts, sticks and\n"         //
                                        "magic jars appear as normal.\n";                  //
string_view bombchuDropsDesc          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Bombs, arrows, seeds, nuts, sticks and\n"         //
                                        "magic jars appear as normal.\n"                   //
                                        "Bombchus can sometimes replace bomb drops.";      //
string_view noAmmoDropsDesc           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All ammo drops will be replaced by blue rupees,\n"//
                                        "except for Deku Sticks.\n"                        //
                                        "Ammo upgrades will only refill ammo by 10 units.";//
/*------------------------------                                                           //
|    HEART DROPS AND REFILLS   |                                                           //
------------------------------*/                                                           //
string_view defaultHeartDropsDesc     = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Heart drops will appear as normal.\n"             //
                                        "Health upgrades fully heal Link when picked up.\n"//
                                        "Fairies heal Link as normal.";                    //
string_view noHeartDropsDesc          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Heart drops will be replaced by green rupees.\n"  //
                                        "Health upgrades fully heal Link when picked up.\n"//
                                        "Fairies heal Link as normal.";                    //
string_view noHeartRefillDesc         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Heart drops will appear as normal.\n"             //
                                        "Health upgrades don't heal Link when picked up.\n"//
                                        "Fairies heal Link by only 3 hearts.";             //
string_view scarceHeartsDesc          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Heart drops will be replaced by green rupees.\n"  //
                                        "Health upgrades don't heal Link when picked up.\n"//
                                        "Fairies heal Link by only 3 hearts.";             //
/*------------------------------                                                           //
|   SHUFFLE DUNGEON REWARDS    |                                                           //
------------------------------*/                                                           //
string_view shuffleRewardsEndOfDungeon= "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Remains will be given as\n"                  //
                                        "rewards for beating dungeons.\n";                 //
string_view shuffleRewardsAnyDungeon  = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Remains can only appear inside of dungeons.\n";                             //
string_view shuffleRewardsOverworld   = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Remains can only appear outside of dungeons.\n";                            //
string_view shuffleRewardsAnywhere    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Remains can appear anywhere.\n";             //                                       //
/*------------------------------                                                           //
|        LINK'S POCKET         |                                                           //
------------------------------*/                                                           //
string_view linksPocketDefault =        "Link will start with the default inventory: \n"   //
                                        "Deku Mask, Ocarina of Time, Bombers Notebook, \n" //
                                        "Song of Healing, Kokiri Sword, and Heros Shield"; //
string_view linksPocketDungeonReward  = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Link will start with a Dungeon Reward in his "    //
                                        "inventory.";                                      //
string_view linksPocketAdvancement    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Link will receive a random advancement item at the"
                                        "beginning of the playthrough.";                   //
string_view linksPocketAnything       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Link will receive a random item from the item pool"
                                        "at the beginning of the playthrough.";            //
string_view linksPocketNothing        = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Link will start with a very useful green rupee."; //
/*------------------------------                                                           //
|         SONG SHUFFLE         |                                                           //
------------------------------*/                                                           //
string_view songsSongLocations        = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Songs will only appear at locations that normally\n"
                                        "teach songs.";                                    //
string_view songsDungeonRewards       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Songs appear at the end of dungeons. For major\n" //
                                        "dungeons, they will be at the boss heart container"
                                        "location. ";                                      //
string_view songsAllLocations         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Songs can appear in any location.";               //
                                                                                           //
/*------------------------------                                                           //
|         SHOPSANITY           |                                                           //
------------------------------*/                                                           //
string_view shopsOff                  = "All shop items will be the same as vanilla.";     //
string_view shopsZero                 = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops.";                                //
string_view shopsOne                  = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "one non-vanilla shop item.";                      //
string_view shopsTwo                  = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "two non-vanilla shop items.";                     //
string_view shopsThree                = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "three non-vanilla shop items.";                   //
string_view shopsFour                 = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "four non-vanilla shop items.";                    //
string_view shopsRandom               = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "1-4 non-vanilla shop items.";                     //
/*------------------------------                                                           //
|         TOKENSANITY          |                                                           //
------------------------------*/                                                           //
string_view tokensOff                 = "**OPTION CURRENTLY WIP**\n"                       //
                                        "GS locations will not be shuffled.";              //
string_view tokensOverworld           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "This only shuffles the GS locations that are\n"   //
                                        "outside of dungeons.";                            //
string_view tokensAllTokens           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Effectively adds 60 new locations for items to\n"//
                                        "appear.";                                         //
                                                                                           //
/*------------------------------                                                           //
|        SCRUB SHUFFLE         |                                                           //
------------------------------*/                                                           //
string_view scrubsOff                 = "Deku Scrub Salesmen will not be randomized";      //
string_view scrubsAffordable          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All Scrub prices will be reduced to 10 rupees each";
string_view scrubsExpensive           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All Scrub prices will be their vanilla prices.\n";//
string_view scrubsRandomPrices        = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All Scrub prices will be between 0-95 rupees. This"
                                        "will on average be very, very expensive overall.";//
/*------------------------------                                                           //
|         SHUFFLE COWS         |                                                           //
------------------------------*/                                                           //
string_view shuffleCowsDesc           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enabling this will let cows give you items upon\n"//
                                        "performing Epona's song in front of them. There\n"//
                                        "are 8 cows";                                      //
                                                                                           //
/*------------------------------                                                           //
|     SHUFFLE KOKIRI SWORD     |                                                           //
------------------------------*/                                                           //
string_view kokiriSwordDesc           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enabling this shuffles the Kokiri Sword into the\n"
                                        "item pool.\n"                                     //
                                        "\n"                                               //
                                        "This will leave you quite vulnerable without any\n"
										"way to attack until an item is found";            //
/*------------------------------                                                           //
|       SHUFFLE OCARINAS       |                                                           //
------------------------------*/                                                           //
string_view ocarinasDesc              = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enabling this shuffles the Ocarina of Time into \n"//
                                        "the item pool."        					       //
                                        "\n"                                               //
                                        "This will require finding an Ocarina before being\n"
                                        "able to play songs. or restart the days";         //
/*------------------------------                                                           //
|      SHUFFLE MAGIC BEANS     |                                                           //
------------------------------*/                                                           //
string_view magicBeansDesc            = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Enabling this adds a pack of 10 beans to the item\n"
                                        "pool and changes the Magic Bean Salesman to sell a"
                                        "random item at a price of 60 rupees.";            //
/*------------------------------                                                           //
|      MAPS AND COMPASSES      |                                                           //
------------------------------*/                                                           //
string_view mapCompassStartWith       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Maps and Compasses are given to you from the\n"   //
                                        "start. This will add a small amount of money and\n"
                                        "refill items to the pool.";                       //
string_view mapCompassVanilla         = "Maps and Compasses will appear in their vanilla\n"//
                                        "locations.";                                      //
string_view mapCompassOwnDungeon      = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Maps and Compasses can only appear in their\n"    //
                                        "respective dungeon.";                             //
string_view mapCompassAnyDungeon      = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Maps and Compasses can only appear in a dungeon,\n"
                                        "but not necessarily the dungeon they are for.";   //
string_view mapCompassOverworld       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Maps and Compasses can only appear outside of\n"  //
                                        "dungeons.";                                       //
string_view mapCompassAnywhere        = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Maps and Compasses can appear anywhere in the\n"  //
                                        "world.";                                          //
/*------------------------------                                                           //
|         SMALL KEYS           |                                                           //
------------------------------*/                                                           //
string_view smallKeyStartWith         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Small Keys are given to you from the start so you\n"
                                        "won't have to worry about locked doors. An easier\n"
                                        "mode.";                                           //
string_view smallKeyVanilla           = "Small Keys will appear in their vanilla locations.";//
string_view smallKeyOwnDungeon        = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Small Keys can only appear in their respective\n" //
                                        "dungeon. ";                                       //
string_view smallKeyAnyDungeon        = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Small Keys can only appear inside of any dungeon,\n"
                                        "but won't necessarily be in the dungeon that the\n"
                                        "key is for. A difficult mode since it is more\n"  //
                                        "likely to need to enter a dungeon multiple times.";
string_view smallKeyOverworld         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Small Keys can only appear outside of dungeons.\n"//
                                        "You may need to enter a dungeon multiple times to\n"
                                        "gain items to access the overworld locations with\n"
                                        "the keys required to finish a dungeon.";          //
string_view smallKeyAnywhere          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Small Keys can appear anywhere in the world. A\n" //
                                        "difficult mode since it is more likely to need to\n"
                                        "enter a dungeon multiple times.";                 //
/*------------------------------                                                           //
|          BOSS KEYS           |                                                           //
------------------------------*/                                                           //
string_view bossKeyStartWith          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Keys are given to you from the start so you\n"
                                        "won't have to worry about boss doors. An easier\n"//
                                        "mode.";                                           //
string_view bossKeyVanilla            = "Boss Keys will appear in their vanilla locations.";
string_view bossKeyOwnDungeon         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Keys can only appear in their respective\n"  //
                                        "dungeon.";                                        //
string_view bossKeyAnyDungeon         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Keys can only appear inside of any dungeon,\n"
                                        "but won't necessarily be in the dungeon that the\n"
                                        "key is for. A difficult mode since it is more\n"  //
                                        "likely to need to enter a dungeon multiple times.";
string_view bossKeyOverworld          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Keys can only appear outside of dungeons.\n" //
                                        "You may need to enter a dungeon without the boss\n"
                                        "key to get items required to find the key in the\n"
                                        "overworld.";                                      //
string_view bossKeyAnywhere           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Boss Keys can appear anywhere in the world. A\n"  //
                                        "difficult mode since it is more likely to need to\n"
                                        "enter a dungeon multiple times.";                 //
/*------------------------------                                                           //
|     SKIP MINIGAME PHASES     |                                                           //
------------------------------*/                                                           //
string_view skipMinigamePhasesDesc    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Completing the Town Archery or Swamp Archery \n"  //
                                        "on the first attempt will give\n"                 //
                                        "both rewards at once for that minigame.";         //
/*------------------------------                                                           //
|        FREE SCARECROW        |                                                           //
------------------------------*/                                                           //
string_view freeScarecrowDesc         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Pulling out the Ocarina near a spot at which\n"   //
                                        "Pierre can spawn will do so, without needing\n"   //
                                        "the song.";                                       //
/*------------------------------                                                           //
|          QUICK TEXT          |                                                           //
------------------------------*/                                                           //
string_view quickTextDesc0            = "Quick text will be unchanged, requiring\n"        //
                                        "frame-perfect inputs like in the vanilla game.";  //
string_view quickTextDesc1            = "Every text box will be completable by pressing B\n"
                                        "at any point while it's scrolling.";              //
string_view quickTextDesc2            = "Every text box will auto-complete instantly.\n"   //
                                        "No scrolling allowed!";                           //
string_view quickTextDesc3            = "Holding B will advance and close text boxes\n"    //
                                        "automatically, except for choice selections.";    //
/*------------------------------                                                           //
|       SKIP SONG REPLAYS      |                                                           //
------------------------------*/                                                           //
string_view skipSongReplaysDesc       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "The automatic replay after you play a song will\n"//
                                        "be skipped.\n"                                    //
                                        "You can choose to keep the sfx anyway, but you\n" //
                                        "will have control of Link during it.";            //
/*------------------------------                                                           //
|     GOSSIP STONE HINTS       |                                                           //
------------------------------*/                                                           //
string_view gossipStonesHintsDesc     = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Gossip Stones can be made to give hints about\n"  //
                                        "where items can be found.\n"                      //
                                        "Different settings can be chosen to decide which\n"
                                        "item is needed to speak to Gossip Stones. Choosing"
                                        "to stick with the Mask of Truth will make the\n"  //
                                        "hints very difficult to obtain.\n"                //
                                        "Hints for 'on the way of the hero' are locations\n"
                                        "that contain items that are required to beat the\n"
                                        "game.";                                           //
                                                                                           //
/*------------------------------                                                           //
|        CLEARER HINTS         |                                                           //
------------------------------*/                                                           //
string_view clearerHintsDesc          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "The hints provided by Gossip Stones will be very\n"
                                        "direct if this option is enabled.";               //
/*------------------------------                                                           //
|      HINT DISTRIBUTION       |                                                           //
------------------------------*/                                                           //
string_view uselessHintsDesc          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Only junk hints.";                                //
string_view balancedHintsDesc         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Recommended hint spread.";                        //
string_view strongHintsDesc           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "More useful hints.";                              //
string_view veryStrongHintsDesc       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Many powerful hints.";                            //
                                                                                           //
/*------------------------------                                                           //
|       DAMAGE MULTIPLIER      |                                                           //
------------------------------*/                                                           //
string_view damageMultiDesc           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Changes the amount of damage taken.\n"            //
                                        "\n"                                               //
                                        "If set to OHKO, Link will die in one hit.";       //
/*------------------------------                                                           //
|   ALL LOCATIONS REACHABLE    |                                                           //
------------------------------*/                                                           //
string_view locationsReachableDesc    = "When this options is enabled, the randomizer will\n"
                                        "guarantee that every item is obtainable and every\n"
                                        "location is reachable. When disabled, only\n"     //
                                        "required items and locations to beat the game\n"  //
                                        "will be guaranteed reachable.";                   //
/*------------------------------                                                           //
|       CHEST ANIMATIONS       |                                                           //
------------------------------*/                                                           //
string_view chestAnimDesc             = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Choose if you want the slow animation to play\n"  //
                                        "if a chest contains a major item.\n";             //
                                                                                           //
/*------------------------------                                                           //
|     CHEST SIZE AND COLOR     |                                                           //
------------------------------*/                                                           //
string_view chestSizeDesc             = "**OPTION CURRENTLY WIP**\n"                       //
                                        "This option will change the appearance of all\n"  //
                                        "regular chests depending on their contents:\n"    //
                                        "Major Items    =    Big Gold Trimmed Chests\n"    //
                                        "Lesser Items   =    Small Gold Trimmed Chests\n"  //
                                        "Boss Keys      =    Big Fancy Chests\n"           //
                                        "Small Keys     =    Small Fancy Chests";          //
                                                                                           //
/*------------------------------                                                           //
|        INGAME SPOILERS       |                                                           //
------------------------------*/                                                           //
string_view ingameSpoilersShowDesc    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Every spoiler is shown.";                         //
string_view ingameSpoilersHideDesc    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Hides the spheres page and only shows a\n"        //
                                        "location's item after it has been found.";        //
                                                                                           //
/*------------------------------                                                           //
|      MENU OPENING BUTTON     |                                                           //
------------------------------*/                                                           //
string_view menuButtonDesc            = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Choose which button will bring up the Dungeon\n"  //
                                        "Information Menu. You can also use the menu to\n" //
                                        "buffer frame perfect inputs if you choose D-Pad"; //
                                                                                           //
/*------------------------------                                                           //
|     START WITH CONSUMABLES   |                                                           //
------------------------------*/                                                           //
string_view startWithConsumablesDesc  = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Start the game with maxed out Deku Nuts.";        //
																						   //
                                                                                           //
/*------------------------------                                                           //
|     START WITH MAX RUPEES    |                                                           //
------------------------------*/                                                           //
string_view startWithMaxRupeesDesc    = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Start the game with a full wallet.\n"             //
                                        "Wallet upgrades will also fill the wallet.";      //
                                                                                           //
/*------------------------------                                                           //
|          ITEM POOL           |                                                           //
------------------------------*/                                                           //
string_view itemPoolPlentiful         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Extra major items are added to the pool.";        //
string_view itemPoolBalanced          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Original item pool.";                             //
string_view itemPoolScarce            = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Some excess items are removed, including health\n"//
                                        "upgrades.";                                       //
string_view itemPoolMinimal           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Most excess items are removed.";                  //
                                                                                           //
/*------------------------------                                                           //
|          ICE TRAPS           |                                                           //
------------------------------*/                                                           //
string_view iceTrapsOff               = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All Ice Traps are removed.";                      //
string_view iceTrapsNormal            = "Only Ice Traps from the base item pool are placed.";
string_view iceTrapsExtra             = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Chance to add extra Ice Traps when junk items are\n"
                                        "added to the itempool.";                          //
string_view iceTrapsMayhem            = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All added junk items will be Ice Traps.";         //
string_view iceTrapsOnslaught         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All junk items will be replaced by Ice Traps, even"
                                        "those in the base pool.";                         //
/*------------------------------                                                           //
|    REMOVE DOUBLE DEFENSE     |                                                           //
------------------------------*/                                                           //
string_view removeDDDesc              = "**OPTION CURRENTLY WIP**\n"                       //
                                        "If set the double defense item will be removed\n" //
                                        "from the item pool for balanced and plentiful.";  //
                                                                                           //
/*------------------------------                                                           //
|         COLORED KEYS         |                                                           //
------------------------------*/                                                           //
string_view coloredKeysDesc           = "**OPTION CURRENTLY WIP**\n"                       //
                                        "If set, small key models will be colored\n"       //
                                        "differently depending on which dungeon they can be"
                                        "used in. Forest Temple keys are green. Fire Temple"
                                        "keys are red. etc.";                              //
string_view coloredBossKeysDesc       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "If set, boss key models will be colored\n"        //
                                        "differently depending on which dungeon they can be"
                                        "used in. The Forest Temple boss key is green. The "
                                        "Fire Temple boss key is red. etc.";               //
/*------------------------------                                                           //
|        SHUFFLE MUSIC         |                                                           //
------------------------------*/                                                           //
string_view musicRandoDesc           = "**OPTION CURRENTLY WIP**\n"                        //
                                       "Randomize the music in the game";                  //
string_view shuffleBGMDesc           = "**OPTION CURRENTLY WIP**\n"                        //
                                       "Randomize area background music";                  //
string_view fanfaresOffDesc          = "**OPTION CURRENTLY WIP**\n"                        //
                                       "Fanfares are not shuffled.";                       //
string_view onlyFanfaresDesc         = "**OPTION CURRENTLY WIP**\n"                        //
                                       "Fanfares and ocarina songs are shuffled in\n"      //
                                       "separate pools.";                                  //
string_view fanfaresOcarinaDesc      = "**OPTION CURRENTLY WIP**\n"                        //
                                       "Fanfares and ocarina songs are shuffled together\n"//
                                       "in the same pool.";                                //
string_view shuffleOcaMusicDesc      = "**OPTION CURRENTLY WIP**\n"                        //
                                       "The music that plays back after you play an ocarina"
                                       "song is randomized";                               //
                                                                                           //
/*------------------------------                                                           //
|    RANDOM TRAP DAMAGE TYPE   |                                                           //
------------------------------*/                                                           //
string_view randomTrapDmgDesc         = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All traps will be the base game ice trap";        //
                                                                                           //
string_view basicTrapDmgDesc          = "**OPTION CURRENTLY WIP**\n"                       //
                                        "All alternative traps will cause a small damage\n"//
                                        "and no other negative effects";                   //
                                                                                           //
string_view advancedTrapDmgDesc       = "**OPTION CURRENTLY WIP**\n"                       //
                                        "Some chest traps will burn your Deku Shield or\n" //
                                        "cause a lot of damage (with one-hit protection)"; //
                                                                                           //--------------//
/*------------------------------                                                                           //
|  DETAILED LOGIC EXPLANATIONS |                                                                           //
------------------------------*/
string_view ToggleLogicNoneDesc                       = "These are not implemented yet come back soon!.";  //
/*------------------------------                                                                           //
|           GLITCHES           |                                                                           //
------------------------------*/                                                                           //
const std::vector<string_view> GlitchDifficulties{"Novice", "Intermediate", "Advanced", "Expert", "Hero"};
