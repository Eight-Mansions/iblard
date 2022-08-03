#ifndef FONT_H_
#define FONT_H_

#include "platform.h"

extern "C" {

	u32 curLetIdx;

	u32 GetLetterWidth(u32 letter);

	u32 GetSentenceWidth(const u8* text, const u8* end);

}

#endif