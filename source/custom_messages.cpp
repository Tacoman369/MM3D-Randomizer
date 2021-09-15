#include "custom_messages.hpp"
#include "patch_symbols.hpp"
#include "debug.hpp"
#include "shops.hpp"
#include "../code/src/message.h"

#include <array>
#include <set>
#include <sstream>

#include <unistd.h>

namespace CustomMessages {

using namespace std::literals::string_literals;

class MessageEntryComp {
public:
    bool operator()(const MessageEntry& lhs, const MessageEntry& rhs) const {
        return lhs.id < rhs.id;
    }
};

constexpr std::array EnglishDungeonNames = {
    "Woodfall Temple",
    "Snowhead Temple",
    "Great Bay Temple",
    "Stone Tower Temple",
	"Swamp Spider House",
	"Oceanside Spider House",
	"Pirates' Fortress",
	"Beneath the Well",
	"Ancient Castle of Ikana",
	"Secret Shrine",
    "The Moon",
};

constexpr std::array FrenchDungeonNames = {
    "Temple de Bois-Cascade",
    "Temple du Pic des Neiges",
    "Temple de la Grande Baie",
    "Temple de la Forteresse de Pierre",
    "Maison des Araignees des Marais",
    "Maison des Araignees de la Cote",
    "Forteresse des Pirates",
    "Au fond du Puits",
    "Vestiges du Chateau Ikana",
	"Autel Secret"
    "Interieur de la Lune",
};

constexpr std::array FrenchDungeonArticles = {
    "du ",
    "de la ",
    "du ",
    "du ",
    "du ",
    "du ",
    "du ",
    "du ",
    "du ",
    "de la ",
    "",
    "du ",
    "de la ",
    "du ",
};

constexpr std::array SpanishDungeonNames = {
    "Templo del Bosque Catarata",
    "Templo del Pico Nevado",
    "Templo de la Gran Bahia",
    "Templo de la Torre de Piedra",
	"Casa de las Aranas del Pantano",
	"Casa de las Aranas de la Playa",
	"Fortaleza de las Piratas",
	"Bajo el Pozo",
	"Antiguo Castillo de Ikana",
	"Santuario Secreto",
    "Interior de la Luna",
};

constexpr std::array SpanishDungeonArticles = {
    "del",
    "de la",
    "de la",
    "del",
    "del",
    "del",
    "del",
    "del",
    "del",
    "de la",
    "de la",
    "del",
    "de la",
    "del",
};
constexpr std::array DungeonColors = {
    QM_GREEN,
    QM_RED,
    QM_BLUE,
    QM_YELLOW,
	QM_GREEN,
	QM_LBLUE,
	QM_PINK,
	QM_PINK,
	QM_YELLOW,
	QM_BLACK,
    QM_BLACK,
	
	"Woodfall Temple",
    "Snowhead Temple",
    "Great Bay Temple",
    "Stone Tower Temple",
	"Swamp Spider House",
	"Oceanside Spider House",
	"Pirates' Fortress",
	"Beneath the Well",
	"Ancient Castle of Ikana",
	"Secret Shrine",
    "The Moon",
};

 std::set<MessageEntry, MessageEntryComp> messageEntries;
    std::vector<MessageEntry> arrangedMessageEntries;
    std::stringstream messageData;
    std::string arrangedMessageData;
	
  //textBoxType and textBoxPosition are defined here: https://wiki.cloudmodding.com/oot/Text_Format#Message_Id
void CreateMessage(u32 textId, u32 unk_04, u32 textBoxType, u32 textBoxPosition,
                    std::string englishText, std::string frenchText, std::string spanishText) {
            MessageEntry newEntry = { textId, unk_04, textBoxType, textBoxPosition, { 0 } };

            while ((englishText.size() % 4) != 0) {
              englishText += "\0"s;
            }
            messageData.seekg(0, messageData.end);
            newEntry.info[ENGLISH_U].offset = (char*)((int)messageData.tellg()) + RCUSTOMMESSAGES_ADDR;
            newEntry.info[ENGLISH_U].length = englishText.size();
            messageData << englishText;

            while ((frenchText.size() % 4) != 0) {
              frenchText += "\0"s;
            }
            messageData.seekg(0, messageData.end);
            newEntry.info[FRENCH_U].offset = (char*)((int)messageData.tellg()) + RCUSTOMMESSAGES_ADDR;
            newEntry.info[FRENCH_U].length = frenchText.size();
            messageData << frenchText;

            while ((spanishText.size() % 4) != 0) {
              spanishText += "\0"s;
            }
            messageData.seekg(0, messageData.end);
            newEntry.info[SPANISH_U].offset = (char*)((int)messageData.tellg()) + RCUSTOMMESSAGES_ADDR;
            newEntry.info[SPANISH_U].length = spanishText.size();
            messageData << spanishText;

            messageEntries.insert(newEntry);
    }

    void CreateMessageFromTextObject(u32 textId, u32 unk_04, u32 textBoxType, u32 textBoxPosition, const Text& text) {
        CreateMessage(textId, unk_04, textBoxType, textBoxPosition, text.GetEnglish(), text.GetFrench(), text.GetSpanish());
    }

    u32 NumMessages() {
        return messageEntries.size();
    }

    std::pair<const char*, u32> RawMessageEntryData() {
        arrangedMessageEntries.assign(messageEntries.begin(), messageEntries.end());
        const char* data = (const char*)arrangedMessageEntries.data();
        u32 size = arrangedMessageEntries.size() * sizeof(MessageEntry);
        return { data, size };
    }

    std::pair<const char*, u32> RawMessageData() {
        arrangedMessageData = messageData.str();
        const char* data = arrangedMessageData.data();
        u32 size = arrangedMessageData.size();
        return { data, size };
    }

    void CreateAlwaysIncludedMessages() {
        //Swamp Skulltula Tokens (need textIDs)
        for (const u32 textId : {/*0xB4, 0xB5*/}) {
            CreateMessage(textId, 0, 2, 3,
                INSTANT_TEXT_ON()+"You destroyed a "+COLOR(QM_GREEN)+"Swamp Skulltula"+COLOR(QM_WHITE)+". You got a"+NEWLINE()+"token proving you destroyed it!"+NEWLINE()+NEWLINE()+"You have "+COLOR(QM_RED)+SWAMP_SKULLTULAS_DESTROYED()+COLOR(QM_WHITE)+" tokens!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                INSTANT_TEXT_ON()+"Vous venez de détruire une "+COLOR(GREEN)+"Swamp Skulltula d'or"+COLOR(QM_WHITE)+"!"+NEWLINE()+"Ce symbole prouve votre prouesse!"+NEWLINE()+NEWLINE()+"Vous avez "+COLOR(QM_RED)+SWAMP_SKULLTULAS_DESTROYED()+COLOR(QM_WHITE)+" jetons!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                INSTANT_TEXT_ON()+"¡Has eliminado una "+COLOR(QM_GREEN)+"Swamp skulltula dorada"+COLOR(QM_WHITE)+" y has"+NEWLINE()+"conseguido un símbolo para probarlo!"+NEWLINE()+NEWLINE()+"¡Tienes "+COLOR(QM_RED)+SWAMP_SKULLTULAS_DESTROYED()+COLOR(QM_WHITE)+" símbolos!"+INSTANT_TEXT_OFF()+MESSAGE_END());
        }
		//Oceanside Skulltula Tokens (Need TextID)
		for (const u32 textId : {/*0xB4, 0xB5*/}) {
            CreateMessage(textId, 0, 2, 3,
                INSTANT_TEXT_ON()+"You destroyed a "+COLOR(QM_LBLUE)+"Oceanside Skulltula"+COLOR(QM_WHITE)+". You got a"+NEWLINE()+"token proving you destroyed it!"+NEWLINE()+NEWLINE()+"You have "+COLOR(QM_RED)+OCEANSIDE_SKULLTULAS_DESTROYED()+COLOR(QM_WHITE)+" tokens!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                INSTANT_TEXT_ON()+"Vous venez de détruire une "+COLOR(BLUE)+"Oceanside Skulltula d'or"+COLOR(QM_WHITE)+"!"+NEWLINE()+"Ce symbole prouve votre prouesse!"+NEWLINE()+NEWLINE()+"Vous avez "+COLOR(QM_RED)+OCEANSIDE_SKULLTULAS_DESTROYED()+COLOR(QM_WHITE)+" jetons!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                INSTANT_TEXT_ON()+"¡Has eliminado una "+COLOR(QM_LBLUE+"Oceanside skulltula dorada"+COLOR(QM_WHITE)+" y has"+NEWLINE()+"conseguido un símbolo para probarlo!"+NEWLINE()+NEWLINE()+"¡Tienes "+COLOR(QM_RED)+OCEANSIDE_SKULLTULAS_DESTROYED()+COLOR(QM_WHITE)+" símbolos!"+INSTANT_TEXT_OFF()+MESSAGE_END());
        }

        //Bombchu (10) Description
        CreateMessage(/*0xBC*/, 0, 2, 3,// <==ID?
            INSTANT_TEXT_ON()+COLOR(QM_RED)+"Bombchu (10): 99 Rupees"+NEWLINE()+COLOR(QM_WHITE)+"These look like toy mice, but they're"+NEWLINE()+"actually self-propelled time bombs!"+INSTANT_TEXT_OFF()+SHOP_MESSAGE_BOX()+MESSAGE_END(),
            INSTANT_TEXT_ON()+COLOR(QM_RED)+"Bombchus (10): 99 rubis"+NEWLINE()+COLOR(QM_WHITE)+"Profilée comme une souris mécanique, il"+NEWLINE()+"s'agit en fait d'une bombe à retardement"+NEWLINE()+"autopropulsée!"+INSTANT_TEXT_OFF()+SHOP_MESSAGE_BOX()+MESSAGE_END(),
            INSTANT_TEXT_ON()+COLOR(QM_RED)+"Bombchus (10): 99 rupias"+NEWLINE()+COLOR(QM_WHITE)+"Aunque parezcan ratoncitos de juguete,"+NEWLINE()+"¡son bombas de relojería autopropulsadas!"+INSTANT_TEXT_OFF()+SHOP_MESSAGE_BOX()+MESSAGE_END());
        //Boss Keys
        for (u32 bossKey = 0; bossKey <= (DUNGEON_STONETOWER_TEMPLE - DUNGEON_WOODFALL_TEMPLE); bossKey++) {
            u32 dungeon = DUNGEON_WOODFALL_TEMPLE + bossKey;
            CreateMessage(/*0x9D4*/ + bossKey, 0, 2, 3, // <==ID?
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_BOSS)+INSTANT_TEXT_ON()+"You got the "+COLOR(DungeonColors[dungeon])+EnglishDungeonNames[dungeon]+NEWLINE()+"Boss Key"+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_BOSS)+INSTANT_TEXT_ON()+"Vous trouvez la "+COLOR(DungeonColors[dungeon])+"clé d'or "+NEWLINE()+FrenchDungeonArticles[dungeon]+" "+FrenchDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_BOSS)+INSTANT_TEXT_ON()+"¡Tienes la "+COLOR(DungeonColors[dungeon])+"gran llave "+SpanishDungeonArticles[dungeon]+NEWLINE()+SpanishDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END());
        }
        
        //Compasses
        for (u32 dungeon = DUNGEON_WOODFALL_TEMPLE; dungeon <= DUNGEON_IKANA_CASTLE; dungeon++) {
            CreateMessage(/*(0x9DA*/ + dungeon, 0, 2, 3,//<==ID?
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_COMPASS)+INSTANT_TEXT_ON()+"You got the "+COLOR(DungeonColors[dungeon])+EnglishDungeonNames[dungeon]+NEWLINE()+"Compass"+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_COMPASS)+INSTANT_TEXT_ON()+"Vous trouvez la "+COLOR(DungeonColors[dungeon])+"boussole "+NEWLINE()+FrenchDungeonArticles[dungeon]+FrenchDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_COMPASS)+INSTANT_TEXT_ON()+"¡Tienes la "+COLOR(DungeonColors[dungeon])+"brújula "+SpanishDungeonArticles[dungeon]+NEWLINE()+SpanishDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END());
        }
        //Maps
        for (u32 dungeon = DUNGEON_WOODFALL_TEMPLE; dungeon <= DUNGEON_IKANA_CASTLE; dungeon++) {
            CreateMessage(/*0x9E4*/ + dungeon, 0, 2, 3,//ID?
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_DUNGEON_MAP)+INSTANT_TEXT_ON()+"You got the "+COLOR(DungeonColors[dungeon])+EnglishDungeonNames[dungeon]+NEWLINE()+"Map"+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_DUNGEON_MAP)+INSTANT_TEXT_ON()+"Vous trouvez la "+COLOR(DungeonColors[dungeon])+"carte "+NEWLINE()+FrenchDungeonArticles[dungeon]+FrenchDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_DUNGEON_MAP)+INSTANT_TEXT_ON()+"¡Has obtenido el "+COLOR(DungeonColors[dungeon])+"mapa "+SpanishDungeonArticles[dungeon]+NEWLINE()+SpanishDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END());
        }
        //Small Keys
        for (u32 smallKey = 0; smallKey <= (DUNGEON_WOODFALL_TEMPLE - DUNGEON_IKANA_CASTLE); smallKey++) {
            u32 dungeon = DUNGEON_FOREST_TEMPLE + smallKey;
            CreateMessage(/*0x9EE*/ + smallKey, 0, 2, 3,//<==ID?
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_SMALL)+INSTANT_TEXT_ON()+"You got a "+COLOR(DungeonColors[dungeon])+EnglishDungeonNames[dungeon]+NEWLINE()+"Small Key"+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_SMALL)+INSTANT_TEXT_ON()+"Vous trouvez une "+COLOR(DungeonColors[dungeon])+"petite clé"+NEWLINE()+FrenchDungeonArticles[dungeon]+FrenchDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_SMALL)+INSTANT_TEXT_ON()+"¡Has obtenido una "+COLOR(DungeonColors[dungeon])+"llave pequeña "+SpanishDungeonArticles[dungeon]+NEWLINE()+SpanishDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END());
        }
        //Ice Trap
        CreateMessage(/*0x9002*/, 0, 2, 3,//<==ID?
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+COLOR(QM_RED)+"FOOL!"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END(),
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+COLOR(QM_RED)+"IDIOT!"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END(),
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+COLOR(QM_RED)+"¡TONTO!"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END());
        
    Text AddColorsAndFormat(Text text, const std::vector<u8>& colors /*= {}*/) {

      //for each language
      for (std::string* textStr : {&text.english, &text.french, &text.spanish}) {

        //insert playername
        size_t atSymbol = textStr->find('@');
        while (atSymbol != std::string::npos) {
          textStr->replace(atSymbol, 1, PLAYER_NAME());
          atSymbol = textStr->find('@');
        }
        //insert newlines either manually or when encountering a '&'
        constexpr size_t lineLength = 44;
        size_t lastNewline = 0;
        while (lastNewline + lineLength < textStr->length()) {
          size_t carrot     = textStr->find('^', lastNewline);
          size_t ampersand  = textStr->find('&', lastNewline);
          size_t lastSpace  = textStr->rfind(' ', lastNewline + lineLength);
          size_t lastPeriod = textStr->rfind('.', lastNewline + lineLength);
          //replace '&' first if it's within the newline range
          if (ampersand < lastNewline + lineLength) {
            textStr->replace(ampersand, 1, NEWLINE());
            lastNewline = ampersand + NEWLINE().length();
          //or move the lastNewline cursor to the next line if a '^' is encountered
          } else if (carrot < lastNewline + lineLength) {
            lastNewline = carrot + 1;
          //some lines need to be split but don't have spaces, look for periods instead
          } else if (lastSpace == std::string::npos) {
            textStr->replace(lastPeriod, 1, "."+NEWLINE());
            lastNewline = lastPeriod + NEWLINE().length() + 1;
          } else {
            textStr->replace(lastSpace, 1, NEWLINE());
            lastNewline = lastSpace + NEWLINE().length();
          }
        }
        //clean up any remaining '&' characters
        size_t ampersand = textStr->find('&');
        while (ampersand != std::string::npos) {
          textStr->replace(ampersand, 1, NEWLINE());
          ampersand = textStr->find('&');
        }

        //insert box break
        size_t carrotSymbol = textStr->find('^');
        while (carrotSymbol != std::string::npos) {
          textStr->replace(carrotSymbol, 1, INSTANT_TEXT_OFF()+WAIT_FOR_INPUT()+INSTANT_TEXT_ON());
          carrotSymbol = textStr->find('^');
        }
        //add colors
        for (auto color : colors) {
          size_t firstHashtag = textStr->find('#');
          if (firstHashtag != std::string::npos) {
              textStr->replace(firstHashtag, 1, COLOR(color));
              size_t secondHashtag = textStr->find('#');
              if (secondHashtag == std::string::npos) {
                CitraPrint("ERROR: Couldn't find second '#' in " + (*textStr));
              } else {
                textStr->replace(secondHashtag, 1, COLOR(QM_WHITE));
              }
          }
        }
      }
      return Text{"","",""}+UNSKIPPABLE()+INSTANT_TEXT_ON()+text+INSTANT_TEXT_OFF()+MESSAGE_END();
    }

    void ClearMessages() {
        messageEntries.clear();
        arrangedMessageEntries.clear();
        messageData.str("");
        arrangedMessageData = "";
    }

    std::string MESSAGE_END()          { return  "\x7F\x00"s; }
    std::string WAIT_FOR_INPUT()       { return  "\x7F\x01"s; }
    std::string HORIZONTAL_SPACE(u8 x) { return  "\x7F\x02"s + char(x); }
    std::string GO_TO(u16 x)           { return  "\x7F\x03"s + char(x >> 8) + char(x & 0x00FF); }
    std::string INSTANT_TEXT_ON()      { return  "\x7F\x04"s; }
    std::string INSTANT_TEXT_OFF()     { return  "\x7F\x05"s; }
    std::string SHOP_MESSAGE_BOX()     { return  "\x7F\x06\x00"s; }
    std::string EVENT_TRIGGER()        { return  "\x7F\x07"s; }
    std::string DELAY_FRAMES(u8 x)     { return  "\x7F\x08"s + char(x); }
    std::string CLOSE_AFTER(u8 x)      { return  "\x7F\x0A"s + char(x); }
    std::string PLAYER_NAME()          { return  "\x7F\x0B"s; }
    std::string PLAY_OCARINA()         { return  "\x7F\x0C"s; }
    std::string ITEM_OBTAINED(u8 x)    { return  "\x7F\x0F"s + char(x); }
    std::string SET_SPEED(u8 x)        { return  "\x7F\x10"s + char(x); }
    std::string SKULLTULAS_DESTROYED() { return  "\x7F\x15"s; }
    std::string CURRENT_TIME()         { return  "\x7F\x17"s; }
    std::string UNSKIPPABLE()          { return  "\x7F\x19"s; }
    std::string TWO_WAY_CHOICE()       { return  "\x7F\x1A\xFF\xFF\xFF\xFF"s; }
    std::string NEWLINE()              { return  "\x7F\x1C"s; }
    std::string COLOR(u8 x)            { return  "\x7F\x1D"s + char(x); }
    std::string CENTER_TEXT()          { return  "\x7F\x1E"s; }
    std::string IF_NOT_MQ()            { return  "\x7F\x29"s; }
    std::string MQ_ELSE()              { return  "\x7F\x2A"s; }
    std::string MQ_END()               { return  "\x7F\x2B"s; }
}
