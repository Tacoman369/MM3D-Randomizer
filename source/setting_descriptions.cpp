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
string_view shuffleEntrancesDesc      = "Shuffle where the entrances between areas lead to."
                                        "If turned on, select which kinds of entrances you\n"
                                        "want shuffled in the options below.";             //
                                                                                           //
/*------------------------------                                                           //
|       DUNGEON ENTRANCES      |                                                           //
------------------------------*/                                                           //
string_view dungeonEntrancesDesc      = "Shuffle the pool of dungeon entrances, including\n"
                                        "Bottom of the Well, Ice Cavern, and Gerudo\n"     //
                                        "Training Grounds. However, Ganon's Castle is not\n"
                                        "shuffled.\n"                                      //
                                        "\n"                                               //
                                        "Additionally, the entrances of Deku Tree, Fire\n" //
                                        "Temple and Bottom of the Well are opened for both\n"
                                        "adult and child.";                                //
/*------------------------------                                                           //
|      OVERWORLD ENTRANCES     |                                                           //
------------------------------*/                                                           //
string_view overworldEntrancesDesc    = "Shuffle the pool of Overworld entrances, which\n" //
                                        "corresponds to almost all loading zones between\n"//
                                        "Overworld areas.\n"                               //
                                        "\n"                                               //
                                        "Some entrances are unshuffled to avoid issues:\n" //
                                        "- Hyrule Castle Courtyard and Garden entrance\n"  //
                                        "- Both Market Back Alley entrances\n"             //
                                        "- Gerudo Valley to Lake Hylia (unless entrances\n"//
                                        "  are decoupled)";                               //
/*------------------------------                                                           //
|      BOMBCHUS IN LOGIC       |                                                           //
------------------------------*/                                                           //
string_view bombchuLogicDesc          = "Bombchus are properly considered in logic.\n"     //
                                        "They can be replenished in shops, or through\n"   //
                                        "bombchu drops, if those are enabled.\n"           //
                                        "\n"                                               //
                                        "Bombchu Bowling is opened by bombchus.";          //
/*------------------------------                                                           //
|          AMMO DROPS          |                                                           //
------------------------------*/                                                           //
string_view defaultAmmoDropsDesc      = "Bombs, arrows, seeds, nuts, sticks and\n"         //
                                        "magic jars appear as normal.\n";                  //
string_view bombchuDropsDesc          = "Bombs, arrows, seeds, nuts, sticks and\n"         //
                                        "magic jars appear as normal.\n"                   //
                                        "Bombchus can sometimes replace bomb drops.";      //
string_view noAmmoDropsDesc           = "All ammo drops will be replaced by blue rupees,\n"//
                                        "except for Deku Sticks.\n"                        //
                                        "Ammo upgrades will only refill ammo by 10 units.";//
/*------------------------------                                                           //
|    HEART DROPS AND REFILLS   |                                                           //
------------------------------*/                                                           //
string_view defaultHeartDropsDesc     = "Heart drops will appear as normal.\n"             //
                                        "Health upgrades fully heal Link when picked up.\n"//
                                        "Fairies heal Link as normal.";                    //
string_view noHeartDropsDesc          = "Heart drops will be replaced by green rupees.\n"  //
                                        "Health upgrades fully heal Link when picked up.\n"//
                                        "Fairies heal Link as normal.";                    //
string_view noHeartRefillDesc         = "Heart drops will appear as normal.\n"             //
                                        "Health upgrades don't heal Link when picked up.\n"//
                                        "Fairies heal Link by only 3 hearts.";             //
string_view scarceHeartsDesc          = "Heart drops will be replaced by green rupees.\n"  //
                                        "Health upgrades don't heal Link when picked up.\n"//
                                        "Fairies heal Link by only 3 hearts.";             //
/*------------------------------                                                           //
|   SHUFFLE DUNGEON REWARDS    |                                                           //
------------------------------*/                                                           //
string_view shuffleRewardsEndOfDungeon= "Medallions and Spiritual Stones will be given as\n"
                                        "rewards for beating dungeons.\n"                  //
                                        "\n"                                               //
                                        "This setting will force Link's Pocket to be a\n"  //
                                        "Medallion or Spiritual Stone.";                   //
string_view shuffleRewardsAnyDungeon  = "Medallions and Spiritual Stones can only appear\n"//
                                        "inside of dungeons.";                             //
string_view shuffleRewardsOverworld   = "Medallions and Spiritual Stones can only appear\n"//
                                        "outside of dungeons.";                            //
string_view shuffleRewardsAnywhere    = "Medallions and Spiritual Stones can appear\n"     //
                                        "anywhere.";                                       //
/*------------------------------                                                           //
|        LINK'S POCKET         |                                                           //
------------------------------*/                                                           //
string_view linksPocketDungeonReward  = "Link will start with a Dungeon Reward in his\n"   //
                                        "inventory.";                                      //
string_view linksPocketAdvancement    = "Link will receive a random advancement item at the"
                                        "beginning of the playthrough.";                   //
string_view linksPocketAnything       = "Link will receive a random item from the item pool"
                                        "at the beginning of the playthrough.";            //
string_view linksPocketNothing        = "Link will start with a very useful green rupee."; //
/*------------------------------                                                           //
|         SONG SHUFFLE         |                                                           //
------------------------------*/                                                           //
string_view songsSongLocations        = "Songs will only appear at locations that normally\n"
                                        "teach songs.";                                    //
string_view songsDungeonRewards       = "Songs appear at the end of dungeons. For major\n" //
                                        "dungeons, they will be at the boss heart container"
                                        "location. The remaining 4 songs are placed at:\n" //
                                        "- Zelda's Lullaby Location\n"                     //
                                        "- Ice Cavern's Serenade of Water Location\n"      //
                                        "- Bottom of the Well's Lens of Truth Location\n"  //
                                        "- Gerudo Training Ground's Ice Arrow Location";   //
string_view songsAllLocations         = "Songs can appear in any location.";               //
                                                                                           //
/*------------------------------                                                           //
|         SHOPSANITY           |                                                           //
------------------------------*/                                                           //
string_view shopsOff                  = "All shop items will be the same as vanilla.";     //
string_view shopsZero                 = "Vanilla shop items will be shuffled among\n"      //
                                        "different shops.";                                //
string_view shopsOne                  = "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "one non-vanilla shop item.";                      //
string_view shopsTwo                  = "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "two non-vanilla shop items.";                     //
string_view shopsThree                = "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "three non-vanilla shop items.";                   //
string_view shopsFour                 = "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "four non-vanilla shop items.";                    //
string_view shopsRandom               = "Vanilla shop items will be shuffled among\n"      //
                                        "different shops, and each shop will contain\n"    //
                                        "1-4 non-vanilla shop items.";                     //
/*------------------------------                                                           //
|         TOKENSANITY          |                                                           //
------------------------------*/                                                           //
string_view tokensOff                 = "GS locations will not be shuffled.";              //
string_view tokensOverworld           = "This only shuffles the GS locations that are\n"   //
                                        "outside of dungeons.";                            //
string_view tokensAllTokens           = "Effectively adds 60 new locations for items to\n"//
                                        "appear.";                                         //
                                                                                           //
/*------------------------------                                                           //
|        SCRUB SHUFFLE         |                                                           //
------------------------------*/                                                           //
string_view scrubsOff                 = "Only the 3 Scrubs that give one-time items in the\n"
                                        "vanilla game (PoH, Deku Nut capacity, and Deku\n" //
                                        "Stick capacity) will have random items.";         //
string_view scrubsAffordable          = "All Scrub prices will be reduced to 10 rupees each";
string_view scrubsExpensive           = "All Scrub prices will be their vanilla prices.\n" //
                                        "This will require spending over 1000 rupees on\n" //
                                        "Scrubs.";                                         //
string_view scrubsRandomPrices        = "All Scrub prices will be between 0-95 rupees. This"
                                        "will on average be very, very expensive overall.";//
/*------------------------------                                                           //
|         SHUFFLE COWS         |                                                           //
------------------------------*/                                                           //
string_view shuffleCowsDesc           = "Enabling this will let cows give you items upon\n"//
                                        "performing Epona's song in front of them. There\n"//
                                        "are 9 cows, and an extra in MQ Jabu.";            //
                                                                                           //
/*------------------------------                                                           //
|     SHUFFLE KOKIRI SWORD     |                                                           //
------------------------------*/                                                           //
string_view kokiriSwordDesc           = "Enabling this shuffles the Kokiri Sword into the\n"
                                        "item pool.\n"                                     //
                                        "\n"                                               //
                                        "This will leave you quite vulnerable without any\n"
										"way to attack until an item is found";            //
/*------------------------------                                                           //
|       SHUFFLE OCARINAS       |                                                           //
------------------------------*/                                                           //
string_view ocarinasDesc              = "Enabling this shuffles the Ocarina of Time into \n"//
                                        "the item pool."        					       //
                                        "\n"                                               //
                                        "This will require finding an Ocarina before being\n"
                                        "able to play songs. or restart the days";         //
/*------------------------------                                                           //
|      SHUFFLE MAGIC BEANS     |                                                           //
------------------------------*/                                                           //
string_view magicBeansDesc            = "Enabling this adds a pack of 10 beans to the item\n"
                                        "pool and changes the Magic Bean Salesman to sell a"
                                        "random item at a price of 60 rupees.";            //
/*------------------------------                                                           //
|      MAPS AND COMPASSES      |                                                           //
------------------------------*/                                                           //
string_view mapCompassStartWith       = "Maps and Compasses are given to you from the\n"   //
                                        "start. This will add a small amount of money and\n"
                                        "refill items to the pool.";                       //
string_view mapCompassVanilla         = "Maps and Compasses will appear in their vanilla\n"//
                                        "locations.";                                      //
string_view mapCompassOwnDungeon      = "Maps and Compasses can only appear in their\n"    //
                                        "respective dungeon.";                             //
string_view mapCompassAnyDungeon      = "Maps and Compasses can only appear in a dungeon,\n"
                                        "but not necessarily the dungeon they are for.";   //
string_view mapCompassOverworld       = "Maps and Compasses can only appear outside of\n"  //
                                        "dungeons.";                                       //
string_view mapCompassAnywhere        = "Maps and Compasses can appear anywhere in the\n"  //
                                        "world.";                                          //
/*------------------------------                                                           //
|         SMALL KEYS           |                                                           //
------------------------------*/                                                           //
string_view smallKeyStartWith         = "Small Keys are given to you from the start so you\n"
                                        "won't have to worry about locked doors. An easier\n"
                                        "mode.";                                           //
string_view smallKeyVanilla           = "Small Keys will appear in their vanilla locations."
                                        "You start with 3 keys in Spirit Temple MQ because\n"
                                        "the vanilla key layout is not beatable in logic.";//
string_view smallKeyOwnDungeon        = "Small Keys can only appear in their respective\n" //
                                        "dungeon. If Fire Temple is not a Master Quest\n"  //
                                        "dungeon, the door to the Boss Key chest will be\n"//
                                        "unlocked.";                                       //
string_view smallKeyAnyDungeon        = "Small Keys can only appear inside of any dungeon,\n"
                                        "but won't necessarily be in the dungeon that the\n"
                                        "key is for. A difficult mode since it is more\n"  //
                                        "likely to need to enter a dungeon multiple times.";
string_view smallKeyOverworld         = "Small Keys can only appear outside of dungeons.\n"//
                                        "You may need to enter a dungeon multiple times to\n"
                                        "gain items to access the overworld locations with\n"
                                        "the keys required to finish a dungeon.";          //
string_view smallKeyAnywhere          = "Small Keys can appear anywhere in the world. A\n" //
                                        "difficult mode since it is more likely to need to\n"
                                        "enter a dungeon multiple times.";                 //
/*------------------------------                                                           //
|          BOSS KEYS           |                                                           //
------------------------------*/                                                           //
string_view bossKeyStartWith          = "Boss Keys are given to you from the start so you\n"
                                        "won't have to worry about boss doors. An easier\n"//
                                        "mode.";                                           //
string_view bossKeyVanilla            = "Boss Keys will appear in their vanilla locations.";
string_view bossKeyOwnDungeon         = "Boss Keys can only appear in their respective\n"  //
                                        "dungeon.";                                        //
string_view bossKeyAnyDungeon         = "Boss Keys can only appear inside of any dungeon,\n"
                                        "but won't necessarily be in the dungeon that the\n"
                                        "key is for. A difficult mode since it is more\n"  //
                                        "likely to need to enter a dungeon multiple times.";
string_view bossKeyOverworld          = "Boss Keys can only appear outside of dungeons.\n" //
                                        "You may need to enter a dungeon without the boss\n"
                                        "key to get items required to find the key in the\n"
                                        "overworld.";                                      //
string_view bossKeyAnywhere           = "Boss Keys can appear anywhere in the world. A\n"  //
                                        "difficult mode since it is more likely to need to\n"
                                        "enter a dungeon multiple times.";                 //
/*------------------------------                                                           //
|     SKIP MINIGAME PHASES     |                                                           //
------------------------------*/                                                           //
string_view skipMinigamePhasesDesc    = "Completing the second objective in the Dampe Race\n"
                                        "and Gerudo Archery on the first attempt will give\n"
                                        "both rewards at once for that minigame.";          //
/*------------------------------                                                           //
|        FREE SCARECROW        |                                                           //
------------------------------*/                                                           //
string_view freeScarecrowDesc         = "Pulling out the Ocarina near a spot at which\n"   //
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
string_view skipSongReplaysDesc       = "The automatic replay after you play a song will\n"//
                                        "be skipped.\n"                                    //
                                        "You can choose to keep the sfx anyway, but you\n" //
                                        "will have control of Link during it.";            //
/*------------------------------                                                           //
|     GOSSIP STONE HINTS       |                                                           //
------------------------------*/                                                           //
string_view gossipStonesHintsDesc     = "Gossip Stones can be made to give hints about\n"  //
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
string_view clearerHintsDesc          = "The hints provided by Gossip Stones will be very\n"
                                        "direct if this option is enabled.";               //
/*------------------------------                                                           //
|      HINT DISTRIBUTION       |                                                           //
------------------------------*/                                                           //
string_view uselessHintsDesc          = "Only junk hints.";                                //
string_view balancedHintsDesc         = "Recommended hint spread.";                        //
string_view strongHintsDesc           = "More useful hints.";                              //
string_view veryStrongHintsDesc       = "Many powerful hints.";                            //
                                                                                           //
/*------------------------------                                                           //
|       DAMAGE MULTIPLIER      |                                                           //
------------------------------*/                                                           //
string_view damageMultiDesc           = "Changes the amount of damage taken.\n"            //
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
string_view chestAnimDesc             = "Choose if you want the slow animation to play\n"  //
                                        "if a chest contains a major item.\n";             //
                                                                                           //
/*------------------------------                                                           //
|     CHEST SIZE AND COLOR     |                                                           //
------------------------------*/                                                           //
string_view chestSizeDesc             = "This option will change the appearance of all\n"  //
                                        "regular chests depending on their contents:\n"    //
                                        "Major Items    =    Big Gold Trimmed Chests\n"    //
                                        "Lesser Items   =    Small Gold Trimmed Chests\n"  //
                                        "Boss Keys      =    Big Fancy Chests\n"           //
                                        "Small Keys     =    Small Fancy Chests";          //
                                                                                           //
/*------------------------------                                                           //
|        INGAME SPOILERS       |                                                           //
------------------------------*/                                                           //
string_view ingameSpoilersShowDesc    = "Every spoiler is shown.";                         //
string_view ingameSpoilersHideDesc    = "Hides the spheres page and only shows a\n"        //
                                        "location's item after it has been found.";        //
                                                                                           //
/*------------------------------                                                           //
|      MENU OPENING BUTTON     |                                                           //
------------------------------*/                                                           //
string_view menuButtonDesc            = "Choose which button will bring up the Dungeon\n"  //
                                        "Information Menu. You can also use the menu to\n" //
                                        "buffer frame perfect inputs if you choose D-Pad"; //
                                                                                           //
/*------------------------------                                                           //
|     START WITH CONSUMABLES   |                                                           //
------------------------------*/                                                           //
string_view startWithConsumablesDesc  = "Start the game with maxed out Deku Nuts.";        //
																						   //
                                                                                           //
/*------------------------------                                                           //
|     START WITH MAX RUPEES    |                                                           //
------------------------------*/                                                           //
string_view startWithMaxRupeesDesc    = "Start the game with a full wallet.\n"             //
                                        "Wallet upgrades will also fill the wallet.";      //
                                                                                           //
/*------------------------------                                                           //
|          ITEM POOL           |                                                           //
------------------------------*/                                                           //
string_view itemPoolPlentiful         = "Extra major items are added to the pool.";        //
string_view itemPoolBalanced          = "Original item pool.";                             //
string_view itemPoolScarce            = "Some excess items are removed, including health\n"//
                                        "upgrades.";                                       //
string_view itemPoolMinimal           = "Most excess items are removed.";                  //
                                                                                           //
/*------------------------------                                                           //
|          ICE TRAPS           |                                                           //
------------------------------*/                                                           //
string_view iceTrapsOff               = "All Ice Traps are removed.";                      //
string_view iceTrapsNormal            = "Only Ice Traps from the base item pool are placed.";
string_view iceTrapsExtra             = "Chance to add extra Ice Traps when junk items are\n"
                                        "added to the itempool.";                          //
string_view iceTrapsMayhem            = "All added junk items will be Ice Traps.";         //
string_view iceTrapsOnslaught         = "All junk items will be replaced by Ice Traps, even"
                                        "those in the base pool.";                         //
/*------------------------------                                                           //
|    REMOVE DOUBLE DEFENSE     |                                                           //
------------------------------*/                                                           //
string_view removeDDDesc              = "If set the double defense item will be removed\n" //
                                        "from the item pool for balanced and plentiful.";  //
/*------------------------------                                                           //
|         GK DURABILITY        |                                                           //
------------------------------*/                                                           //
string_view gkDurabilityVanilla       = "The durability will always be set to 8.";         //
string_view gkDurabilityRandomRisk    = "Each Giant's Knife will get a random durability\n"//
                                        "between 1 and 128, with low being more common,\n" //
                                        "and with an average of 15.";                      //
string_view gkDurabilityRandomSafe    = "Each Giant's Knife will get a random durability\n"//
                                        "between 10 and 50, with an average of 30.";       //
                                                                                           //
/*------------------------------                                                           //
|         COLORED KEYS         |                                                           //
------------------------------*/                                                           //
string_view coloredKeysDesc           = "If set, small key models will be colored\n"       //
                                        "differently depending on which dungeon they can be"
                                        "used in. Forest Temple keys are green. Fire Temple"
                                        "keys are red. etc.";                              //
string_view coloredBossKeysDesc       = "If set, boss key models will be colored\n"        //
                                        "differently depending on which dungeon they can be"
                                        "used in. The Forest Temple boss key is green. The "
                                        "Fire Temple boss key is red. etc.";               //
/*------------------------------                                                           //
|        SHUFFLE MUSIC         |                                                           //
------------------------------*/                                                           //
string_view musicRandoDesc           = "Randomize the music in the game";                  //
string_view shuffleBGMDesc           = "Randomize area background music";                  //
string_view fanfaresOffDesc          = "Fanfares are not shuffled.";                       //
string_view onlyFanfaresDesc         = "Fanfares and ocarina songs are shuffled in\n"      //
                                       "separate pools.";                                  //
string_view fanfaresOcarinaDesc      = "Fanfares and ocarina songs are shuffled together\n"//
                                       "in the same pool.";                                //
string_view shuffleOcaMusicDesc      = "The music that plays back after you play an ocarina"
                                       "song is randomized";                               //
                                                                                           //
/*------------------------------                                                           //
|    RANDOM TRAP DAMAGE TYPE   |                                                           //
------------------------------*/                                                           //
string_view randomTrapDmgDesc         = "All traps will be the base game ice trap";        //
                                                                                           //
string_view basicTrapDmgDesc          = "All alternative traps will cause a small damage\n"//
                                        "and no other negative effects";                   //
                                                                                           //
string_view advancedTrapDmgDesc       = "Some chest traps will burn your Deku Shield or\n" //
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

string_view GlitchISGDescDisabled                     = "Shortened to ISG, allows Link's melee weapon to\n"//
                                                        "be in a constant swinging state. Simply touching\n"
                                                        "objects with this causes them to get hit.\n"      //
                                                        "Putting away the weapon while ISG is on hits\n"   //
                                                        "any object with a spherical hitbox,\n"            //
                                                        "such as small skulltulas. It is initiated by\n"   //
                                                        "interrupting a crouch stab.";                     //
string_view GlitchISGDescNovice                       = "ISG may be required to kill certain enemies,\n"   //
                                                        "or to Bomb Hover when enabled.";                  //
string_view GlitchHoverDescDisabled                   = "Hovering allows Link to consecutively backflip\n" //
                                                        "in the air without falling. By shielding\n"       //
                                                        "damage with ISG on, Link will stay in midair.\n"  //
                                                        "While bombs aren't always required, this option\n"//
                                                        "will always expect them to be used.\n"            //
                                                        "\n"                                               //
                                                        "Requires ISG to be enabled.";                     //
string_view GlitchHoverDescNovice                     = "Only bombchus are required for hovering.";        //
string_view GlitchHoverDescIntermediate               = "Some hovers may require that you start from flat\n"
                                                        "terrain, which requires somewhat precise timing.";//
string_view GlitchHoverDescAdvanced                   = "Usage of regular bombs will now also be expected,\n"
                                                        "which may require consecutive precise timings.";  //
string_view GlitchMegaflipDescDisabled                = "A Megaflip is a backflip/sidehop with high speed.\n"
                                                        "This can be done with several methods.";          //
string_view GlitchMegaflipDescNovice                  = "Only Megaflipping with bombs is required.";       //
string_view GlitchMegaflipDescIntermediate            = "Some Megaflips where you don't have a lot of room\n"
                                                        "to work with and positioning is more important\n" //
                                                        "may be required.";                                //
string_view GlitchHookshotClipDescDisabled            = "Hookshot Clipping allows Link to hookshot through\n"
                                                        "certain walls, which is useful if a valid\n"      //
                                                        "target is on the other side.";                    //
string_view GlitchHookshotClipDescNovice              = "Basic Hookshot Clipping may be required.";        //
string_view GlitchHookshotJump_BonkDescDisabled       = "A Hookshot Jump is an umbrella term for techniques"
                                                        "that launch Link into the sky using the Hookshot\n"
                                                        "in various ways, sometimes together with\n"       //
                                                        "other items. The bonk method only requires the\n" //
                                                        "Hookshot itself.";                                //
string_view GlitchHookshotJump_BonkDescIntermediate   = "Basic Hookshot Jumps with a bonk may be required.";
string_view GlitchHookshotJump_BootsDescDisabled      = "This Hookshot Jump technique is one of the easier\n"
                                                        "ones, and require any pair of boots.";            //
string_view GlitchHookshotJump_BootsDescNovice        = "Only relatively short Hookshot Jumps with boots\n"//
                                                        "may be required.";                                //
string_view GlitchHookshotJump_BootsDescIntermediate  = "Higher Hookshot Jumps with boots, where you look\n"
                                                        "further up or downwards may be required.";        //
string_view GlitchLedgeClipDescDisabled               = "A Ledge Clip allows Link to fall through a floor\n"
                                                        "or pass through an object by facing a wall\n"     //
                                                        "and dropping down to the left in a various ways.\n"
                                                        "These only work as an adult.";                    //
string_view GlitchLedgeClipDescNovice                 = "Basic Ledge Clips may be required.\n"             //
                                                        "Some require that you let go of the ledge with\n" //
                                                        "a specific timing.";                              //
string_view GlitchLedgeClipDescIntermediate           = "Certain harder clips may also be required.";      //
string_view GlitchTripleSlashClipDescDisabled         = "When doing a three-slash-combo with either the\n" //
                                                        "Kokiri Sword or the Master Sword and put it away,\n"
                                                        "Link will be placed back a small distance.\n"     //
                                                        "If, while slashing, you use the recoil of hitting\n"
                                                        "a wall and then put away the sword, Link may clip\n"
                                                        "into a wall behind him if angled correctly.";     //
string_view GlitchTripleSlashClipDescNovice           = "Basic Triple Slash Clipping may be required.";    //
