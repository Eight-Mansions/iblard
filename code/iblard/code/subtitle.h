#ifndef SUBTITLE_H_
#define SUBTITLE_H_

#include "platform.h"
#include "core.h"

struct subtitle_part {
    const char* text;
    const u8 len;
    const u16 displayTime;
};

struct subtitle {
    const i16 id;
    const u8 partsCount;
    const subtitle_part* parts;
};

struct subtitle_displayed {
    const subtitle_part* parts;
    u8 partsCount;
    u8 nextPartIdx;
    u8 ticksTilNext;
};

// Test1
const u8 partdata_0_0[] = { 0x82, 0x73, 0x82, 0x85, 0x82, 0x93, 0x82, 0x94, 0x82, 0x50 };
// Test2
const u8 partdata_1_0[] = { 0x82, 0x73, 0x82, 0x85, 0x82, 0x93, 0x82, 0x94, 0x82, 0x51 };

const subtitle_part sub0_parts[] = {
    {(const char*)partdata_0_0, 5, 1},
    {(const char*)partdata_1_0, 5, 15}
};

const u32 subsCount = 1;
const subtitle subs[] = {
    {1544405569, 2, sub0_parts}
};

static subtitle_displayed currSub = {};

extern "C" {
	extern int DisplayText(const char* text, int pos, int wipe, int unk1, int type);

	//extern void GetLetterImage(u32 sjis, u_long* letterImage);
    
    void DisplaySubtitle();

	void DisplayLetter();

	void ClearText();
}

#endif