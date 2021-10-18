#ifndef _MM3D_ITEM_H
#define _MM3D_ITEM_H

#include "m3Dvec.h"

typedef enum {
	/* 0x00 */ SLOT_STICK,
	/* 0x01 */ SLOT_NUT,
	/* 0x02 */ SLOT_STICK,
	/* 0x03 */ SLOT_BOMB,
	/* 0x04 */ SLOT_BOW,
	/* 0x05 */ SLOT_ARROW_FIRE,
	/* 0x06 */ SLOT_ARROW_ICE,
	/* 0x07 */ SLOT_ARROW_LIGHT,
	/* 0x08 */ SLOT_OCARINA,
	/* 0x09 */ SLOT_BOMBCHU,
	/* 0x0A */ SLOT_HOOKSHOT,
	/* 0x0B */ SLOT_LENS,
	/* 0x0C */ SLOT_BEAN,
	/* 0x0D */ SLOT_KEG,
	/* 0x0E */ SLOT_LETTER,
	/* 0x0F */ SLOT_STICK,
	/* 0x10 */ SLOT_STICK,
	/* 0x11 */ SLOT_STICK,
	/* 0x12 */ SLOT_STICK,
	/* 0x13 */ SLOT_STICK,
	/* 0x14 */ SLOT_STICK,
	/* 0x15 */ SLOT_STICK,
	/* 0x16 */ SLOT_STICK,
	/* 0x17 */ SLOT_STICK,
	/* 0x18 */ SLOT_STICK,
	/* 0xFF */ SLOT_NONE = 0xFF

} InventorySlot;