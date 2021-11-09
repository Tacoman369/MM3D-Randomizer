#include "custom_messages.hpp"
#include "patch_symbols.hpp"
#include "debug.hpp"
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
    "The Moon",

};

constexpr std::array FrenchDungeonNames = {
    "Temple de Bois-Cascade",
    "Temple du Pic des neiges",
    "Temple de la Grande Baie",
    "Temple de la forteresse de pierre",
    "La Lune",
};

constexpr std::array FrenchDungeonArticles = {
    "de",
    "du",
    "de la",
    "de la",
    "la",
};

constexpr std::array SpanishDungeonNames = {
    "Templo del Bosque Catarata",
    "Templo del Pico Nevado",
    "Templo de la Gran Bahia",
    "Templo de la Torra de Piedra",
    "La Luna",
};

constexpr std::array SpanishDungeonArticles = {
    "del",
    "del",
    "de la",
    "de la",
    "la",
};

constexpr std::array DungeonColors = {
    QM_GREEN,
    QM_RED,
    QM_BLUE,
    QM_GREEN,
    QM_RED,
    QM_BLUE,
    QM_YELLOW,
    QM_PINK,
    QM_PINK,
    QM_LBLUE,
    QM_BLACK,
    QM_YELLOW,
    QM_YELLOW,
    QM_RED,
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
        // Bombchu (10) Purchase Prompt
        CreateMessage(0x8C, 0, 2, 3,
            INSTANT_TEXT_ON()+"Bombchu (10): 99 Rupees"+INSTANT_TEXT_OFF()+NEWLINE()+NEWLINE()+TWO_WAY_CHOICE()+COLOR(QM_GREEN)+"Buy"+NEWLINE()+"Don't buy"+COLOR(QM_WHITE)+MESSAGE_END(),
            INSTANT_TEXT_ON()+"Bombchus (10): 99 rubis"+INSTANT_TEXT_OFF()+NEWLINE()+NEWLINE()+TWO_WAY_CHOICE()+COLOR(QM_GREEN)+"Acheter"+NEWLINE()+"Ne pas acheter"+COLOR(QM_WHITE)+MESSAGE_END(),
            INSTANT_TEXT_ON()+"Bombchus (10): 99 rupias"+INSTANT_TEXT_OFF()+NEWLINE()+NEWLINE()+TWO_WAY_CHOICE()+COLOR(QM_GREEN)+"Comprar"+NEWLINE()+"No comprar"+COLOR(QM_WHITE)+MESSAGE_END());
        //Gold Skulltula Tokens (there are two text IDs the game uses)
        for (const u32 textId : {0xB4, 0xB5}) {
            CreateMessage(textId, 0, 2, 3,
                INSTANT_TEXT_ON()+"You destroyed a "+COLOR(QM_RED)+"Gold Skulltula"+COLOR(QM_WHITE)+". You got a"+NEWLINE()+"token proving you destroyed it!"+NEWLINE()+NEWLINE()+"You have "+COLOR(QM_RED)+SKULLTULAS_DESTROYED()+COLOR(QM_WHITE)+" tokens!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                INSTANT_TEXT_ON()+"Vous venez de détruire une "+COLOR(QM_RED)+"Skulltula d'or"+COLOR(QM_WHITE)+"!"+NEWLINE()+"Ce symbole prouve votre prouesse!"+NEWLINE()+NEWLINE()+"Vous avez "+COLOR(QM_RED)+SKULLTULAS_DESTROYED()+COLOR(QM_WHITE)+" jetons!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                INSTANT_TEXT_ON()+"¡Has eliminado una "+COLOR(QM_RED)+"skulltula dorada"+COLOR(QM_WHITE)+" y has"+NEWLINE()+"conseguido un símbolo para probarlo!"+NEWLINE()+NEWLINE()+"¡Tienes "+COLOR(QM_RED)+SKULLTULAS_DESTROYED()+COLOR(QM_WHITE)+" símbolos!"+INSTANT_TEXT_OFF()+MESSAGE_END());
        }

        //Bombchu (10) Description
        CreateMessage(0xBC, 0, 2, 3,
            INSTANT_TEXT_ON()+COLOR(QM_RED)+"Bombchu (10): 99 Rupees"+NEWLINE()+COLOR(QM_WHITE)+"These look like toy mice, but they're"+NEWLINE()+"actually self-propelled time bombs!"+INSTANT_TEXT_OFF()+SHOP_MESSAGE_BOX()+MESSAGE_END(),
            INSTANT_TEXT_ON()+COLOR(QM_RED)+"Bombchus (10): 99 rubis"+NEWLINE()+COLOR(QM_WHITE)+"Profilée comme une souris mécanique, il"+NEWLINE()+"s'agit en fait d'une bombe à retardement"+NEWLINE()+"autopropulsée!"+INSTANT_TEXT_OFF()+SHOP_MESSAGE_BOX()+MESSAGE_END(),
            INSTANT_TEXT_ON()+COLOR(QM_RED)+"Bombchus (10): 99 rupias"+NEWLINE()+COLOR(QM_WHITE)+"Aunque parezcan ratoncitos de juguete,"+NEWLINE()+"¡son bombas de relojería autopropulsadas!"+INSTANT_TEXT_OFF()+SHOP_MESSAGE_BOX()+MESSAGE_END());
        //Boss Keys
        for (u32 bossKey = 0; bossKey <= (DUNGEON_STONE_TOWER - DUNGEON_WOODFALL); bossKey++) {
            u32 dungeon = DUNGEON_WOODFALL + bossKey;
            CreateMessage(0x9D4 + bossKey, 0, 2, 3,
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_BOSS)+INSTANT_TEXT_ON()+"You got the "+COLOR(DungeonColors[dungeon])+EnglishDungeonNames[dungeon]+NEWLINE()+"Boss Key"+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_BOSS)+INSTANT_TEXT_ON()+"Vous trouvez la "+COLOR(DungeonColors[dungeon])+"clé d'or "+NEWLINE()+FrenchDungeonArticles[dungeon]+" "+FrenchDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_BOSS)+INSTANT_TEXT_ON()+"¡Tienes la "+COLOR(DungeonColors[dungeon])+"gran llave "+SpanishDungeonArticles[dungeon]+NEWLINE()+SpanishDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END());
        }
        //Compasses
        for (u32 dungeon = DUNGEON_WOODFALL; dungeon <= DUNGEON_STONE_TOWER; dungeon++) {
            CreateMessage(0x9DA + dungeon, 0, 2, 3,
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_COMPASS)+INSTANT_TEXT_ON()+"You got the "+COLOR(DungeonColors[dungeon])+EnglishDungeonNames[dungeon]+NEWLINE()+"Compass"+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_COMPASS)+INSTANT_TEXT_ON()+"Vous trouvez la "+COLOR(DungeonColors[dungeon])+"boussole "+NEWLINE()+FrenchDungeonArticles[dungeon]+FrenchDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_COMPASS)+INSTANT_TEXT_ON()+"¡Tienes la "+COLOR(DungeonColors[dungeon])+"brújula "+SpanishDungeonArticles[dungeon]+NEWLINE()+SpanishDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END());
        }
        //Maps
        for (u32 dungeon = DUNGEON_WOODFALL; dungeon <= DUNGEON_STONE_TOWER; dungeon++) {
            CreateMessage(0x9E4 + dungeon, 0, 2, 3,
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_DUNGEON_MAP)+INSTANT_TEXT_ON()+"You got the "+COLOR(DungeonColors[dungeon])+EnglishDungeonNames[dungeon]+NEWLINE()+"Map"+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_DUNGEON_MAP)+INSTANT_TEXT_ON()+"Vous trouvez la "+COLOR(DungeonColors[dungeon])+"carte "+NEWLINE()+FrenchDungeonArticles[dungeon]+FrenchDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_DUNGEON_MAP)+INSTANT_TEXT_ON()+"¡Has obtenido el "+COLOR(DungeonColors[dungeon])+"mapa "+SpanishDungeonArticles[dungeon]+NEWLINE()+SpanishDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END());
        }
        //Small Keys
        for (u32 smallKey = 0; smallKey <= (DUNGEON_WOODFALL - DUNGEON_STONE_TOWER); smallKey++) {
            u32 dungeon = DUNGEON_WOODFALL + smallKey;
            CreateMessage(0x9EE + smallKey, 0, 2, 3,
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_SMALL)+INSTANT_TEXT_ON()+"You got a "+COLOR(DungeonColors[dungeon])+EnglishDungeonNames[dungeon]+NEWLINE()+"Small Key"+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_SMALL)+INSTANT_TEXT_ON()+"Vous trouvez une "+COLOR(DungeonColors[dungeon])+"petite clé"+NEWLINE()+FrenchDungeonArticles[dungeon]+FrenchDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_KEY_SMALL)+INSTANT_TEXT_ON()+"¡Has obtenido una "+COLOR(DungeonColors[dungeon])+"llave pequeña "+SpanishDungeonArticles[dungeon]+NEWLINE()+SpanishDungeonNames[dungeon]+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+MESSAGE_END());
        }
        //Tycoon's Wallet
        CreateMessage(0x09F7, 0, 2, 3,
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_WALLET_GIANT)+INSTANT_TEXT_ON()+"You got a "+COLOR(QM_RED)+"Tycoon's Wallet"+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+NEWLINE()+"It's gigantic! Now you can carry"+NEWLINE()+"up to "+COLOR(QM_YELLOW)+"999 "+COLOR(QM_WHITE)+COLOR(QM_YELLOW)+"Rupees"+COLOR(QM_WHITE)+"!"+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_WALLET_GIANT)+INSTANT_TEXT_ON()+"Vous obtenez la "+COLOR(QM_RED)+"bourse de star"+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+NEWLINE()+"Elle peut contenir jusqu'à "+COLOR(QM_YELLOW)+"999 "+COLOR(QM_WHITE)+COLOR(QM_YELLOW)+"rubis"+COLOR(QM_WHITE)+"!"+NEWLINE()+"C'est gigantesque!"+MESSAGE_END(),
                UNSKIPPABLE()+ITEM_OBTAINED(ITEM_WALLET_GIANT)+INSTANT_TEXT_ON()+"¡Has conseguido una "+COLOR(QM_RED)+"bolsa para ricachones"+COLOR(QM_WHITE)+"!"+INSTANT_TEXT_OFF()+NEWLINE()+"¡Qué descomunal! Ya puedes llevar"+NEWLINE()+"hasta "+COLOR(QM_YELLOW)+"999 "+COLOR(QM_WHITE)+COLOR(QM_YELLOW)+"rupias"+COLOR(QM_WHITE)+"!"+MESSAGE_END());
        //Ice Trap
        CreateMessage(0x9002, 0, 2, 3,
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+COLOR(QM_RED)+"FOOL!"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END(),
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+COLOR(QM_RED)+"IDIOT!"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END(),
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+COLOR(QM_RED)+"¡TONTO!"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END());
        //Business Scrubs
        //The less significant byte represents the price of the item
        for (u32 price = 0; price <= 95; price += 5) {
            CreateMessage(0x9000 + price, 0, 0, 0,
                INSTANT_TEXT_ON()+"I'll sell you something good for "+COLOR(QM_RED)+std::to_string(price)+" Rupees"+COLOR(QM_WHITE)+"!"+NEWLINE()+NEWLINE()+TWO_WAY_CHOICE()+COLOR(QM_GREEN)+"OK"+NEWLINE()+"No way"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END(),
                INSTANT_TEXT_ON()+"Je te vends un truc super pour "+COLOR(QM_RED)+std::to_string(price)+" Rubis"+COLOR(QM_WHITE)+"!"+NEWLINE()+NEWLINE()+TWO_WAY_CHOICE()+COLOR(QM_GREEN)+"D'accord"+NEWLINE()+"Hors de question"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END(),
                INSTANT_TEXT_ON()+"¡Te puedo vender algo bueno por "+COLOR(QM_RED)+std::to_string(price)+" rupias"+COLOR(QM_WHITE)+"!"+NEWLINE()+NEWLINE()+TWO_WAY_CHOICE()+COLOR(QM_GREEN)+"Vale"+NEWLINE()+"Ni hablar"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END());
        }
       /*
        //Shopsanity items
        //64 textboxes, 2 for each of 32 potential shopsanity items
        for(u32 shopitems = 0; shopitems < NonShopItems.size(); shopitems++) {
            Text name = NonShopItems[shopitems].Name;
            std::string price = std::to_string(NonShopItems[shopitems].Price);
            //Prevent names from being too long and overflowing textbox
            if (name.GetEnglish() == "Piece of Heart (Treasure Chest Minigame)") {
                name = Text{"Piece of Heart", "Quart de coeur", "Pieza de corazón"};
            } else if (name.GetEnglish() == "Green Rupee (Treasure Chest Minigame)") {
                name = Text{"Green Rupee", "Rubis vert", "Rupia verde"};
            }
            //Message to display when hovering over the item
            if (NonShopItems[shopitems].Repurchaseable) { //Different checkbox for repurchaseable items
                CreateMessage(0x9200+shopitems*2, 0, 0, 0,
                    INSTANT_TEXT_ON()+COLOR(QM_RED)+name.GetEnglish()+": "+price+" Rupees"+NEWLINE()+COLOR(QM_WHITE)+"Special deal!"+NEWLINE()+"Buy as many as you want!"+SHOP_MESSAGE_BOX()+MESSAGE_END(),
                    INSTANT_TEXT_ON()+COLOR(QM_RED)+name.GetFrench()+": "+price+" rubis"+NEWLINE()+COLOR(QM_WHITE)+"Offre spéciale!"+NEWLINE()+"Achetez-en à volonté!"+SHOP_MESSAGE_BOX()+MESSAGE_END(),
                    INSTANT_TEXT_ON()+COLOR(QM_RED)+name.GetSpanish()+": "+price+" rupias"+NEWLINE()+COLOR(QM_WHITE)+"¡Oferta especial!"+NEWLINE()+"¡Compra todo lo que quieras!"+SHOP_MESSAGE_BOX()+MESSAGE_END());
            }
            else { //Normal textbox
                CreateMessage(0x9200+shopitems*2, 0, 0, 0,
                    INSTANT_TEXT_ON()+COLOR(QM_RED)+name.GetEnglish()+": "+price+" Rupees"+NEWLINE()+COLOR(QM_WHITE)+"Special deal! ONE LEFT!"+NEWLINE()+"Get it while it lasts!"+SHOP_MESSAGE_BOX()+MESSAGE_END(),
                    INSTANT_TEXT_ON()+COLOR(QM_RED)+name.GetFrench()+": "+price+" rubis"+NEWLINE()+COLOR(QM_WHITE)+"Offre spéciale! DERNIER EN STOCK!"+NEWLINE()+"Faites vite!"+SHOP_MESSAGE_BOX()+MESSAGE_END(),
                    INSTANT_TEXT_ON()+COLOR(QM_RED)+name.GetSpanish()+": "+price+" rupias"+NEWLINE()+COLOR(QM_WHITE)+"¡Oferta especial! ¡SOLO QUEDA UNA UNIDAD!"+NEWLINE()+"¡Hazte con ella antes de que se agote!"+SHOP_MESSAGE_BOX()+MESSAGE_END());
            }
            //Message to display when going to buy the item
            CreateMessage(0x9200+shopitems*2+1, 0, 0, 0,
                INSTANT_TEXT_ON()+name.GetEnglish()+": "+price+" Rupees"+INSTANT_TEXT_OFF()+NEWLINE()+NEWLINE()+TWO_WAY_CHOICE()+COLOR(QM_GREEN)+"Buy"+NEWLINE()+"Don't buy"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END(),
                INSTANT_TEXT_ON()+name.GetFrench()+": "+price+" rubis"+INSTANT_TEXT_OFF()+NEWLINE()+NEWLINE()+TWO_WAY_CHOICE()+COLOR(QM_GREEN)+"Acheter"+NEWLINE()+"Ne pas acheter"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END(),
                INSTANT_TEXT_ON()+name.GetSpanish()+": "+price+" rupias"+INSTANT_TEXT_OFF()+NEWLINE()+NEWLINE()+TWO_WAY_CHOICE()+COLOR(QM_GREEN)+"Comprar"+NEWLINE()+"No comprar"+COLOR(QM_WHITE)+INSTANT_TEXT_OFF()+MESSAGE_END());
        }
        */
        //easter egg
        CreateMessage(0x96F, 0, 2, 2,
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+"Oh hey, you watched all the credits!"+NEWLINE()+CENTER_TEXT()+"Here's a prize for your patience."+NEWLINE()+CENTER_TEXT()+"Unlocking MQ and saving..."+NEWLINE()+NEWLINE()+CENTER_TEXT()+COLOR(QM_RED)+"Do not remove the Game Card"+NEWLINE()+CENTER_TEXT()+"or turn the power off."+INSTANT_TEXT_OFF()+MESSAGE_END(),
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+"The Legend of Zelda Ocarina of Time 3D"+NEWLINE()+CENTER_TEXT()+"Master Quest va être déverrouillé."+NEWLINE()+CENTER_TEXT()+"Sauvegarde... Veuillez patienter."+NEWLINE()+NEWLINE()+CENTER_TEXT()+COLOR(QM_RED)+"N'éteignez pas la console et"+NEWLINE()+CENTER_TEXT()+"ne retirez pas la carte de jeu"+INSTANT_TEXT_OFF()+MESSAGE_END(),
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+"Desbloqueando The Legend of Zelda"+NEWLINE()+CENTER_TEXT()+"Ocarina of Time 3D Master Quest."+NEWLINE()+CENTER_TEXT()+"Guardando. Espera un momento..."+NEWLINE()+NEWLINE()+CENTER_TEXT()+COLOR(QM_RED)+"No saques la tarjeta de juego"+NEWLINE()+CENTER_TEXT()+"ni apagues la consola."+INSTANT_TEXT_OFF()+MESSAGE_END());
        CreateMessage(0x970, 0, 2, 3,
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+"Master Quest doesn't affect the Randomizer,"+NEWLINE()+CENTER_TEXT()+"so you can use 3 more save slots now."+NEWLINE()+NEWLINE()+CENTER_TEXT()+"Thanks for playing!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+"Vous pouvez désormais jouer à"+NEWLINE()+CENTER_TEXT()+"The Legend of Zelda Ocarina of Time 3D"+NEWLINE()+CENTER_TEXT()+"Master Quest!"+INSTANT_TEXT_OFF()+MESSAGE_END(),
            UNSKIPPABLE()+INSTANT_TEXT_ON()+CENTER_TEXT()+"¡Ya puedes jugar The Legend of Zelda"+NEWLINE()+CENTER_TEXT()+"Ocarina of Time 3D Master Quest!"+INSTANT_TEXT_OFF()+MESSAGE_END());

       
    }

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
}
