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

//EKI.XA | 0 | What in the world?
const u8 partdata_0[] = { 130, 214, 130, 231, 130, 224, 130, 243, 130, 159, 130, 232, 130, 237, 130, 159, 130, 243, 130, 231, 130, 228, 130, 159, 130, 246, 130, 238, 130, 241, 130, 235, 130, 227, 130, 190 };

//EKI.XA | 0 | Is that a station on the other side?
const u8 partdata_1[] = { 130, 200, 130, 242, 130, 159, 130, 243, 130, 231, 130, 224, 130, 243, 130, 159, 130, 224, 130, 159, 130, 242, 130, 243, 130, 224, 130, 243, 130, 232, 130, 238, 130, 237, 130, 159, 130, 238, 130, 237, 130, 159, 130, 243, 130, 231, 130, 228, 130, 159, 130, 238, 130, 243, 130, 231, 130, 228, 130, 241, 130, 159, 130, 242, 130, 232, 130, 227, 130, 228, 130, 190 };

const subtitle_part sub0_parts[] = {
    {(const char*)partdata_0, 18, 1},
    {(const char*)partdata_1, 36, 15},
};

const u32 subsCount = 1;
const subtitle subs[] = {
    {1544405569, 2, sub0_parts}
};

static subtitle_displayed currSub = {};

extern "C" {
    extern int printf(const char* fmt, ...);

	extern int DisplayText(const char* text, int pos, int wipe, int unk1, int type);

	//extern void GetLetterImage(u32 sjis, u_long* letterImage);
    
    void DisplaySubtitle();

	void DisplayLetter();

	void ClearText();
}

#endif