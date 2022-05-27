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

//\EKI\EKI.XA;1 | 1 | It's... a rail pass?
const u8 partdata_2[] = { 130, 200, 130, 243, 130, 166, 130, 242, 130, 173, 130, 173, 130, 173, 130, 159, 130, 224, 130, 159, 130, 241, 130, 224, 130, 232, 130, 235, 130, 159, 130, 239, 130, 224, 130, 242, 130, 242, 130, 190 };

const subtitle_part sub1_parts[] = {
	{(const char*)partdata_2, 20, 1},
};

//\EKI\EKI.XA;1 | 5 | Augh!
const u8 partdata_3[] = { 130, 192, 130, 244, 130, 230, 130, 231, 130, 160 };

const subtitle_part sub2_parts[] = {
	{(const char*)partdata_3, 5, 1},
};

//\HIKOU\HIKOU.XA;1 | 0 | I see. Guess that does it!
const u8 partdata_4[] = { 130, 200, 130, 159, 130, 242, 130, 228, 130, 228, 130, 173, 130, 159, 130, 198, 130, 244, 130, 228, 130, 242, 130, 242, 130, 159, 130, 243, 130, 231, 130, 224, 130, 243, 130, 159, 130, 227, 130, 238, 130, 228, 130, 242, 130, 159, 130, 232, 130, 243, 130, 160 };

const subtitle_part sub3_parts[] = {
	{(const char*)partdata_4, 26, 1},
};

//\HIKOU\HIKOU.XA;1 | 4 | *Gargle, gargle*
const u8 partdata_5[] = { 130, 169, 130, 198, 130, 224, 130, 241, 130, 230, 130, 235, 130, 228, 130, 171, 130, 159, 130, 230, 130, 224, 130, 241, 130, 230, 130, 235, 130, 228, 130, 169 };

const subtitle_part sub4_parts[] = {
	{(const char*)partdata_5, 16, 1},
};

//\LAPUTA01\LAPUTA01.XA;1 | 0 | It's Ninya's airship!
const u8 partdata_6[] = { 130, 200, 130, 243, 130, 166, 130, 242, 130, 159, 130, 205, 130, 232, 130, 237, 130, 248, 130, 224, 130, 166, 130, 242, 130, 159, 130, 224, 130, 232, 130, 241, 130, 242, 130, 231, 130, 232, 130, 239, 130, 160 };

//\LAPUTA01\LAPUTA01.XA;1 | 0 | Let's go!
const u8 partdata_7[] = { 130, 203, 130, 228, 130, 243, 130, 166, 130, 242, 130, 159, 130, 230, 130, 238, 130, 160 };

const subtitle_part sub5_parts[] = {
	{(const char*)partdata_6, 21, 1},
	{(const char*)partdata_7, 9, 28},
};

//\LAPUTA02\LAPUTA02.XA;1 | 0 | The megezo reflect the heart. 
const u8 partdata_8[] = { 130, 211, 130, 231, 130, 228, 130, 159, 130, 236, 130, 228, 130, 230, 130, 228, 130, 249, 130, 238, 130, 159, 130, 241, 130, 228, 130, 229, 130, 235, 130, 228, 130, 226, 130, 243, 130, 159, 130, 243, 130, 231, 130, 228, 130, 159, 130, 231, 130, 228, 130, 224, 130, 241, 130, 243, 130, 173, 130, 159 };

//\LAPUTA02\LAPUTA02.XA;1 | 0 | Open your heart!
const u8 partdata_9[] = { 130, 206, 130, 239, 130, 228, 130, 237, 130, 159, 130, 248, 130, 238, 130, 244, 130, 241, 130, 159, 130, 231, 130, 228, 130, 224, 130, 241, 130, 243, 130, 160 };

const subtitle_part sub6_parts[] = {
	{(const char*)partdata_8, 30, 1},
	{(const char*)partdata_9, 16, 95},
};

//\MEKIN\MEKIN.XA;1 | 2 | Augh!
const u8 partdata_10[] = { 130, 192, 130, 244, 130, 230, 130, 231, 130, 160 };

const subtitle_part sub7_parts[] = {
	{(const char*)partdata_10, 5, 1},
};

//NONA\NONA.XA;1 | 0 | Augh!
const u8 partdata_11[] = { 130, 192, 130, 244, 130, 230, 130, 231, 130, 160 };

const subtitle_part sub8_parts[] = {
	{(const char*)partdata_11, 5, 1},
};

//TOMO\TOMO.XA;1 | 0 | Is that someone's home?
const u8 partdata_12[] = { 130, 200, 130, 242, 130, 159, 130, 243, 130, 231, 130, 224, 130, 243, 130, 159, 130, 242, 130, 238, 130, 236, 130, 228, 130, 238, 130, 237, 130, 228, 130, 166, 130, 242, 130, 159, 130, 231, 130, 238, 130, 236, 130, 228, 130, 190 };

const subtitle_part sub9_parts[] = {
	{(const char*)partdata_12, 23, 1},
};

//TOMO\TOMO.XA;1 | 1 | Is it safe to feed them?
const u8 partdata_13[] = { 130, 200, 130, 242, 130, 159, 130, 232, 130, 243, 130, 159, 130, 242, 130, 224, 130, 229, 130, 228, 130, 159, 130, 243, 130, 238, 130, 159, 130, 229, 130, 228, 130, 228, 130, 227, 130, 159, 130, 243, 130, 231, 130, 228, 130, 236, 130, 190 };

const subtitle_part sub10_parts[] = {
	{(const char*)partdata_13, 24, 1},
};

//YOZORA\YOZORA.XA;1 | 0 | Darn, it's locked.
const u8 partdata_14[] = { 130, 195, 130, 224, 130, 241, 130, 237, 130, 171, 130, 159, 130, 232, 130, 243, 130, 166, 130, 242, 130, 159, 130, 235, 130, 238, 130, 226, 130, 234, 130, 228, 130, 227, 130, 173 };

const subtitle_part sub11_parts[] = {
	{(const char*)partdata_14, 18, 1},
};

//YOZORA\YOZORA.XA;1 | 1 | I heard a noise.
const u8 partdata_15[] = { 130, 200, 130, 159, 130, 231, 130, 228, 130, 224, 130, 241, 130, 227, 130, 159, 130, 224, 130, 159, 130, 237, 130, 238, 130, 232, 130, 242, 130, 228, 130, 173 };

//YOZORA\YOZORA.XA;1 | 1 | Was it that door I saw earlier?
const u8 partdata_16[] = { 130, 214, 130, 224, 130, 242, 130, 159, 130, 232, 130, 243, 130, 159, 130, 243, 130, 231, 130, 224, 130, 243, 130, 159, 130, 227, 130, 238, 130, 238, 130, 241, 130, 159, 130, 200, 130, 159, 130, 242, 130, 224, 130, 246, 130, 159, 130, 228, 130, 224, 130, 241, 130, 235, 130, 232, 130, 228, 130, 241, 130, 190 };

const subtitle_part sub12_parts[] = {
	{(const char*)partdata_15, 16, 1},
	{(const char*)partdata_16, 31, 15},
};

//\MORI01\MORI01.XA;1 | 0 | What is this?
const u8 partdata_17[] = { 130, 214, 130, 231, 130, 224, 130, 243, 130, 159, 130, 232, 130, 242, 130, 159, 130, 243, 130, 231, 130, 232, 130, 242, 130, 190 };

//\MORI01\MORI01.XA;1 | 0 | I don't understand anything!
const u8 partdata_18[] = { 130, 200, 130, 159, 130, 227, 130, 238, 130, 237, 130, 166, 130, 243, 130, 159, 130, 244, 130, 237, 130, 227, 130, 228, 130, 241, 130, 242, 130, 243, 130, 224, 130, 237, 130, 227, 130, 159, 130, 224, 130, 237, 130, 248, 130, 243, 130, 231, 130, 232, 130, 237, 130, 230, 130, 160 };

const subtitle_part sub13_parts[] = {
	{(const char*)partdata_17, 13, 1},
	{(const char*)partdata_18, 28, 15},
};

//\MORI01\MORI01.XA;1 | 1 | I can't board without a rail pass.
const u8 partdata_19[] = { 130, 200, 130, 159, 130, 226, 130, 224, 130, 237, 130, 166, 130, 243, 130, 159, 130, 225, 130, 238, 130, 224, 130, 241, 130, 227, 130, 159, 130, 246, 130, 232, 130, 243, 130, 231, 130, 238, 130, 244, 130, 243, 130, 159, 130, 224, 130, 159, 130, 241, 130, 224, 130, 232, 130, 235, 130, 159, 130, 239, 130, 224, 130, 242, 130, 242, 130, 173 };

const subtitle_part sub14_parts[] = {
	{(const char*)partdata_19, 34, 1},
};

//\MORI01\MORI01.XA;1 | 2 | Augh!
const u8 partdata_20[] = { 130, 192, 130, 244, 130, 230, 130, 231, 130, 160 };

const subtitle_part sub15_parts[] = {
	{(const char*)partdata_20, 5, 1},
};

//\MORI01\MORI01.XA;1 | 3 | (Forest language.) 
const u8 partdata_21[] = { 130, 167, 130, 197, 130, 238, 130, 241, 130, 228, 130, 242, 130, 243, 130, 159, 130, 235, 130, 224, 130, 237, 130, 230, 130, 244, 130, 224, 130, 230, 130, 228, 130, 173, 130, 168, 130, 159 };

const subtitle_part sub16_parts[] = {
	{(const char*)partdata_21, 19, 1},
};

//\MORI01\MORI01.XA;1 | 4 | What did you say?
const u8 partdata_22[] = { 130, 214, 130, 231, 130, 224, 130, 243, 130, 159, 130, 227, 130, 232, 130, 227, 130, 159, 130, 248, 130, 238, 130, 244, 130, 159, 130, 242, 130, 224, 130, 248, 130, 190 };

const subtitle_part sub17_parts[] = {
	{(const char*)partdata_22, 17, 1},
};

//\MORI01\MORI01.XA;1 | 5 | (Forest language.)
const u8 partdata_23[] = { 130, 167, 130, 197, 130, 238, 130, 241, 130, 228, 130, 242, 130, 243, 130, 159, 130, 235, 130, 224, 130, 237, 130, 230, 130, 244, 130, 224, 130, 230, 130, 228, 130, 173, 130, 168 };

const subtitle_part sub18_parts[] = {
	{(const char*)partdata_23, 18, 1},
};

//\MORI01\MORI01.XA;1 | 6 | What's this negative energy?!
const u8 partdata_24[] = { 130, 214, 130, 231, 130, 224, 130, 243, 130, 166, 130, 242, 130, 159, 130, 243, 130, 231, 130, 232, 130, 242, 130, 159, 130, 237, 130, 228, 130, 230, 130, 224, 130, 243, 130, 232, 130, 245, 130, 228, 130, 159, 130, 228, 130, 237, 130, 228, 130, 241, 130, 230, 130, 248, 130, 190, 130, 160 };

//\MORI01\MORI01.XA;1 | 6 | I'd better brush it off!
const u8 partdata_25[] = { 130, 200, 130, 166, 130, 227, 130, 159, 130, 225, 130, 228, 130, 243, 130, 243, 130, 228, 130, 241, 130, 159, 130, 225, 130, 241, 130, 244, 130, 242, 130, 231, 130, 159, 130, 232, 130, 243, 130, 159, 130, 238, 130, 229, 130, 229, 130, 160 };

const subtitle_part sub19_parts[] = {
	{(const char*)partdata_24, 29, 1},
	{(const char*)partdata_25, 24, 15},
};

//\MORI01\MORI01.XA;1 | 7 | A rail pass?
const u8 partdata_26[] = { 130, 192, 130, 159, 130, 241, 130, 224, 130, 232, 130, 235, 130, 159, 130, 239, 130, 224, 130, 242, 130, 242, 130, 190 };

//\MORI01\MORI01.XA;1 | 7 | Wow, thank you!
const u8 partdata_27[] = { 130, 214, 130, 238, 130, 246, 130, 171, 130, 159, 130, 243, 130, 231, 130, 224, 130, 237, 130, 234, 130, 159, 130, 248, 130, 238, 130, 244, 130, 160 };

const subtitle_part sub20_parts[] = {
	{(const char*)partdata_26, 12, 1},
	{(const char*)partdata_27, 15, 15},
};

//\MORI01\MORI01.XA;1 | 8 | Augh!
const u8 partdata_28[] = { 130, 192, 130, 244, 130, 230, 130, 231, 130, 160 };

const subtitle_part sub21_parts[] = {
	{(const char*)partdata_28, 5, 1},
};

//\MORI01\MORI01.XA;1 | 9 | Augh!
const u8 partdata_29[] = { 130, 192, 130, 244, 130, 230, 130, 231, 130, 160 };

const subtitle_part sub22_parts[] = {
	{(const char*)partdata_29, 5, 1},
};

//\MORI02\MORI02.XA;1 | 0 | (Forest language.)
const u8 partdata_30[] = { 130, 167, 130, 197, 130, 238, 130, 241, 130, 228, 130, 242, 130, 243, 130, 159, 130, 235, 130, 224, 130, 237, 130, 230, 130, 244, 130, 224, 130, 230, 130, 228, 130, 173, 130, 168 };

const subtitle_part sub23_parts[] = {
	{(const char*)partdata_30, 18, 1},
};

//\MORI02\MORI02.XA;1 | 1 | Ah, it's you.
const u8 partdata_31[] = { 130, 192, 130, 231, 130, 171, 130, 159, 130, 232, 130, 243, 130, 166, 130, 242, 130, 159, 130, 248, 130, 238, 130, 244, 130, 173 };

const subtitle_part sub24_parts[] = {
	{(const char*)partdata_31, 13, 1},
};

//\MORI02\MORI02.XA;1 | 2 | (The decipher stone may help here.)
const u8 partdata_32[] = { 130, 167, 130, 211, 130, 231, 130, 228, 130, 159, 130, 227, 130, 228, 130, 226, 130, 232, 130, 239, 130, 231, 130, 228, 130, 241, 130, 159, 130, 242, 130, 243, 130, 238, 130, 237, 130, 228, 130, 159, 130, 236, 130, 224, 130, 248, 130, 159, 130, 231, 130, 228, 130, 235, 130, 239, 130, 159, 130, 231, 130, 228, 130, 241, 130, 228, 130, 173, 130, 168 };

const subtitle_part sub25_parts[] = {
	{(const char*)partdata_32, 35, 1},
};

//\MORI02\MORI02.XA;1 | 3 | Hoho! You seem tougher now!
const u8 partdata_33[] = { 130, 199, 130, 238, 130, 231, 130, 238, 130, 160, 130, 159, 130, 216, 130, 238, 130, 244, 130, 159, 130, 242, 130, 228, 130, 228, 130, 236, 130, 159, 130, 243, 130, 238, 130, 244, 130, 230, 130, 231, 130, 228, 130, 241, 130, 159, 130, 237, 130, 238, 130, 246, 130, 160 };

//\MORI02\MORI02.XA;1 | 3 | How goes your adventure in Iblard?
const u8 partdata_34[] = { 130, 199, 130, 238, 130, 246, 130, 159, 130, 230, 130, 238, 130, 228, 130, 242, 130, 159, 130, 248, 130, 238, 130, 244, 130, 241, 130, 159, 130, 224, 130, 227, 130, 245, 130, 228, 130, 237, 130, 243, 130, 244, 130, 241, 130, 228, 130, 159, 130, 232, 130, 237, 130, 159, 130, 200, 130, 225, 130, 235, 130, 224, 130, 241, 130, 227, 130, 190 };

const subtitle_part sub26_parts[] = {
	{(const char*)partdata_33, 27, 1},
	{(const char*)partdata_34, 34, 15},
};

//\MORI02\MORI02.XA;1 | 4 | I keep brushing off the megezo,
const u8 partdata_35[] = { 130, 200, 130, 159, 130, 234, 130, 228, 130, 228, 130, 239, 130, 159, 130, 225, 130, 241, 130, 244, 130, 242, 130, 231, 130, 232, 130, 237, 130, 230, 130, 159, 130, 238, 130, 229, 130, 229, 130, 159, 130, 243, 130, 231, 130, 228, 130, 159, 130, 236, 130, 228, 130, 230, 130, 228, 130, 249, 130, 238, 130, 171 };

//\MORI02\MORI02.XA;1 | 4 | but they won't go away!
const u8 partdata_36[] = { 130, 225, 130, 244, 130, 243, 130, 159, 130, 243, 130, 231, 130, 228, 130, 248, 130, 159, 130, 246, 130, 238, 130, 237, 130, 166, 130, 243, 130, 159, 130, 230, 130, 238, 130, 159, 130, 224, 130, 246, 130, 224, 130, 248, 130, 160 };

const subtitle_part sub27_parts[] = {
	{(const char*)partdata_35, 31, 1},
	{(const char*)partdata_36, 23, 15},
};

//\MORI02\MORI02.XA;1 | 5 | You can't brush off the megezo!
const u8 partdata_37[] = { 130, 216, 130, 238, 130, 244, 130, 159, 130, 226, 130, 224, 130, 237, 130, 166, 130, 243, 130, 159, 130, 225, 130, 241, 130, 244, 130, 242, 130, 231, 130, 159, 130, 238, 130, 229, 130, 229, 130, 159, 130, 243, 130, 231, 130, 228, 130, 159, 130, 236, 130, 228, 130, 230, 130, 228, 130, 249, 130, 238, 130, 160 };

//\MORI02\MORI02.XA;1 | 5 | They're incarnations of self-doubt!
const u8 partdata_38[] = { 130, 211, 130, 231, 130, 228, 130, 248, 130, 166, 130, 241, 130, 228, 130, 159, 130, 232, 130, 237, 130, 226, 130, 224, 130, 241, 130, 237, 130, 224, 130, 243, 130, 232, 130, 238, 130, 237, 130, 242, 130, 159, 130, 238, 130, 229, 130, 159, 130, 242, 130, 228, 130, 235, 130, 229, 130, 172, 130, 227, 130, 238, 130, 244, 130, 225, 130, 243, 130, 160 };

const subtitle_part sub28_parts[] = {
	{(const char*)partdata_37, 31, 1},
	{(const char*)partdata_38, 35, 15},
};

//\MORI02\MORI02.XA;1 | 6 | Then how do I stop them?!
const u8 partdata_39[] = { 130, 211, 130, 231, 130, 228, 130, 237, 130, 159, 130, 231, 130, 238, 130, 246, 130, 159, 130, 227, 130, 238, 130, 159, 130, 200, 130, 159, 130, 242, 130, 243, 130, 238, 130, 239, 130, 159, 130, 243, 130, 231, 130, 228, 130, 236, 130, 190, 130, 160 };

const subtitle_part sub29_parts[] = {
	{(const char*)partdata_39, 25, 1},
};

//\MORI02\MORI02.XA;1 | 7 | Simple! Open your heart to them.
const u8 partdata_40[] = { 130, 210, 130, 232, 130, 236, 130, 239, 130, 235, 130, 228, 130, 160, 130, 159, 130, 206, 130, 239, 130, 228, 130, 237, 130, 159, 130, 248, 130, 238, 130, 244, 130, 241, 130, 159, 130, 231, 130, 228, 130, 224, 130, 241, 130, 243, 130, 159, 130, 243, 130, 238, 130, 159, 130, 243, 130, 231, 130, 228, 130, 236, 130, 173 };

const subtitle_part sub30_parts[] = {
	{(const char*)partdata_40, 32, 1},
};

//\MORI02\MORI02.XA;1 | 8 | What?! But self-doubt is bad!
const u8 partdata_41[] = { 130, 214, 130, 231, 130, 224, 130, 243, 130, 190, 130, 160, 130, 159, 130, 193, 130, 244, 130, 243, 130, 159, 130, 242, 130, 228, 130, 235, 130, 229, 130, 172, 130, 227, 130, 238, 130, 244, 130, 225, 130, 243, 130, 159, 130, 232, 130, 242, 130, 159, 130, 225, 130, 224, 130, 227, 130, 160 };

//\MORI02\MORI02.XA;1 | 8 | It's bad to have self-doubt, right?
const u8 partdata_42[] = { 130, 200, 130, 243, 130, 166, 130, 242, 130, 159, 130, 225, 130, 224, 130, 227, 130, 159, 130, 243, 130, 238, 130, 159, 130, 231, 130, 224, 130, 245, 130, 228, 130, 159, 130, 242, 130, 228, 130, 235, 130, 229, 130, 172, 130, 227, 130, 238, 130, 244, 130, 225, 130, 243, 130, 171, 130, 159, 130, 241, 130, 232, 130, 230, 130, 231, 130, 243, 130, 190 };

const subtitle_part sub31_parts[] = {
	{(const char*)partdata_41, 29, 1},
	{(const char*)partdata_42, 35, 15},
};

//\MORI02\MORI02.XA;1 | 9 | Not always.
const u8 partdata_43[] = { 130, 205, 130, 238, 130, 243, 130, 159, 130, 224, 130, 235, 130, 246, 130, 224, 130, 248, 130, 242, 130, 173 };

//\MORI02\MORI02.XA;1 | 9 | A megezo is more like a mirror.
const u8 partdata_44[] = { 130, 192, 130, 159, 130, 236, 130, 228, 130, 230, 130, 228, 130, 249, 130, 238, 130, 159, 130, 232, 130, 242, 130, 159, 130, 236, 130, 238, 130, 241, 130, 228, 130, 159, 130, 235, 130, 232, 130, 234, 130, 228, 130, 159, 130, 224, 130, 159, 130, 236, 130, 232, 130, 241, 130, 241, 130, 238, 130, 241, 130, 173 };

const subtitle_part sub32_parts[] = {
	{(const char*)partdata_43, 11, 1},
	{(const char*)partdata_44, 31, 15},
};

//\MORI02\MORI02.XA;1 | 10 | A megezo only reflects your heart
const u8 partdata_45[] = { 130, 192, 130, 159, 130, 236, 130, 228, 130, 230, 130, 228, 130, 249, 130, 238, 130, 159, 130, 238, 130, 237, 130, 235, 130, 248, 130, 159, 130, 241, 130, 228, 130, 229, 130, 235, 130, 228, 130, 226, 130, 243, 130, 242, 130, 159, 130, 248, 130, 238, 130, 244, 130, 241, 130, 159, 130, 231, 130, 228, 130, 224, 130, 241, 130, 243 };

//\MORI02\MORI02.XA;1 | 10 | so you can face your true self!
const u8 partdata_46[] = { 130, 242, 130, 238, 130, 159, 130, 248, 130, 238, 130, 244, 130, 159, 130, 226, 130, 224, 130, 237, 130, 159, 130, 229, 130, 224, 130, 226, 130, 228, 130, 159, 130, 248, 130, 238, 130, 244, 130, 241, 130, 159, 130, 243, 130, 241, 130, 244, 130, 228, 130, 159, 130, 242, 130, 228, 130, 235, 130, 229, 130, 160 };

const subtitle_part sub33_parts[] = {
	{(const char*)partdata_45, 33, 1},
	{(const char*)partdata_46, 31, 15},
};

//\MORI02\MORI02.XA;1 | 11 | My...true self?
const u8 partdata_47[] = { 130, 204, 130, 248, 130, 173, 130, 173, 130, 173, 130, 243, 130, 241, 130, 244, 130, 228, 130, 159, 130, 242, 130, 228, 130, 235, 130, 229, 130, 190 };

const subtitle_part sub34_parts[] = {
	{(const char*)partdata_47, 15, 1},
};

//\MORI02\MORI02.XA;1 | 12 | Now, hurry. 
const u8 partdata_48[] = { 130, 205, 130, 238, 130, 246, 130, 171, 130, 159, 130, 231, 130, 244, 130, 241, 130, 241, 130, 248, 130, 173, 130, 159 };

//\MORI02\MORI02.XA;1 | 12 | The Laputa will emerge soon!
const u8 partdata_49[] = { 130, 211, 130, 231, 130, 228, 130, 159, 130, 203, 130, 224, 130, 239, 130, 244, 130, 243, 130, 224, 130, 159, 130, 246, 130, 232, 130, 235, 130, 235, 130, 159, 130, 228, 130, 236, 130, 228, 130, 241, 130, 230, 130, 228, 130, 159, 130, 242, 130, 238, 130, 238, 130, 237, 130, 160 };

const subtitle_part sub35_parts[] = {
	{(const char*)partdata_48, 12, 1},
	{(const char*)partdata_49, 28, 15},
};

//\MORI02\MORI02.XA;1 | 13 | Here. You can use this.
const u8 partdata_50[] = { 130, 199, 130, 228, 130, 241, 130, 228, 130, 173, 130, 159, 130, 216, 130, 238, 130, 244, 130, 159, 130, 226, 130, 224, 130, 237, 130, 159, 130, 244, 130, 242, 130, 228, 130, 159, 130, 243, 130, 231, 130, 232, 130, 242, 130, 173 };

const subtitle_part sub36_parts[] = {
	{(const char*)partdata_50, 23, 1},
};

//\MORI02\MORI02.XA;1 | 14 | Now, you'd best be off!
const u8 partdata_51[] = { 130, 205, 130, 238, 130, 246, 130, 171, 130, 159, 130, 248, 130, 238, 130, 244, 130, 166, 130, 227, 130, 159, 130, 225, 130, 228, 130, 242, 130, 243, 130, 159, 130, 225, 130, 228, 130, 159, 130, 238, 130, 229, 130, 229, 130, 160 };

const subtitle_part sub37_parts[] = {
	{(const char*)partdata_51, 23, 1},
};

const u32 subsCount = 38;
const subtitle subs[] = {
	{-550948737, 0, 2, sub0_parts},
	{-550948737, 1, 1, sub1_parts},
	{-550948737, 5, 1, sub2_parts},
	{-642465179, 0, 1, sub3_parts},
	{-642465179, 4, 1, sub4_parts},
	{1143355725, 0, 2, sub5_parts},
	{-1424341235, 0, 2, sub6_parts},
	{-1108527787, 2, 1, sub7_parts},
	{-1591652367, 0, 1, sub8_parts},
	{842966193, 0, 1, sub9_parts},
	{842966193, 1, 1, sub10_parts},
	{505577841, 0, 1, sub11_parts},
	{505577841, 1, 2, sub12_parts},
	{-1778463795, 0, 2, sub13_parts},
	{-1778463795, 1, 1, sub14_parts},
	{-1778463795, 2, 1, sub15_parts},
	{-1778463795, 3, 1, sub16_parts},
	{-1778463795, 4, 1, sub17_parts},
	{-1778463795, 5, 1, sub18_parts},
	{-1778463795, 6, 2, sub19_parts},
	{-1778463795, 7, 2, sub20_parts},
	{-1778463795, 8, 1, sub21_parts},
	{-1778463795, 9, 1, sub22_parts},
	{2025015821, 0, 1, sub23_parts},
	{2025015821, 1, 1, sub24_parts},
	{2025015821, 2, 1, sub25_parts},
	{2025015821, 3, 2, sub26_parts},
	{2025015821, 4, 2, sub27_parts},
	{2025015821, 5, 2, sub28_parts},
	{2025015821, 6, 1, sub29_parts},
	{2025015821, 7, 1, sub30_parts},
	{2025015821, 8, 2, sub31_parts},
	{2025015821, 9, 2, sub32_parts},
	{2025015821, 10, 2, sub33_parts},
	{2025015821, 11, 1, sub34_parts},
	{2025015821, 12, 2, sub35_parts},
	{2025015821, 13, 1, sub36_parts},
	{2025015821, 14, 1, sub37_parts},
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