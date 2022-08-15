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

	void InitMovieSubtitle(const char* videoname);

	void DrawMovieSubtitle(RECT* area, u16* image, u16* font, u32 curFrame);

	extern int LoadImage(RECT* rect, u_long* p);

	static int movieSubIdx = -1;
	static int currentMovieFrame = -1;
	static int currentMovieSubtitleIndexes[3] = { -1, -1 , -1 };
}

#endif