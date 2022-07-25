#ifndef SUBTITLE_H_
#define SUBTITLE_H_

#include "platform.h"
#include "core.h"
#include "generated.h"

static subtitle_displayed currSub = {};

extern "C" {
	extern int printf(const char* fmt, ...);

	extern int DisplayText(const char* text, int pos, int wipe, int unk1, int type);

	//extern void GetLetterImage(u32 sjis, u_long* letterImage);


    void InitSubtitle(const char* audioname, int idx);

    void DisplaySubtitle();

	void ClearText();

	static int movieSubIdx = -1;
}

#endif