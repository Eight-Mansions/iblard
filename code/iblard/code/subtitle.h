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
    const i32 id;
    const i16 idx;
    const u8 partsCount;
    const subtitle_part* parts;
};

struct subtitle_displayed {
    const subtitle_part* parts;
    u8 partsCount;
    u8 nextPartIdx;
    u8 ticksTilNext;
};

//\EKI\EKI.XA;1 | 0 | Great, now where do I go?
const u8 partdata_0[] = { 130, 198, 130, 241, 130, 228, 130, 224, 130, 243, 130, 171, 130, 159, 130, 237, 130, 238, 130, 246, 130, 159, 130, 246, 130, 231, 130, 228, 130, 241, 130, 228, 130, 159, 130, 227, 130, 238, 130, 159, 130, 200, 130, 159, 130, 230, 130, 238, 130, 190 };

//\EKI\EKI.XA;1 | 0 | There's another station\nover there.
const u8 partdata_1[] = { 130, 211, 130, 231, 130, 228, 130, 241, 130, 228, 130, 166, 130, 242, 130, 159, 130, 224, 130, 237, 130, 238, 130, 243, 130, 231, 130, 228, 130, 241, 130, 159, 130, 242, 130, 243, 130, 224, 130, 243, 130, 232, 130, 238, 130, 237, 92, 110, 130, 238, 130, 245, 130, 228, 130, 241, 130, 159, 130, 243, 130, 231, 130, 228, 130, 241, 130, 228, 130, 173 };

const subtitle_part sub0_parts[] = {
    {(const char*)partdata_0, 25, 1},
    {(const char*)partdata_1, 35, 45},
};
const u32 subsCount = 1;
const subtitle subs[] = {
    {-550948737, 0, 2, sub0_parts},
};

static subtitle_displayed currSub = {};

extern "C" {
    extern int printf(const char* fmt, ...);

	extern int DisplayText(const char* text, int pos, int wipe, int unk1, int type);

	//extern void GetLetterImage(u32 sjis, u_long* letterImage);


    void InitSubtitle(const char* audioname, int idx);

    void DisplaySubtitle();

	void ClearText();
}

#endif