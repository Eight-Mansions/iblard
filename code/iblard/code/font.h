#ifndef FONT_H_
#define FONT_H_

#include "platform.h"

extern "C" {

	int GetLetterWidth(u32 letter);

	int GetSentenceWidth(const u16* text, u32 length);

	//int GetYForCentering(const char* text, u32 length);
}

#endif