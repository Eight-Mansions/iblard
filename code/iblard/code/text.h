#ifndef TEXT_H_
#define TEXT_H_

#include "platform.h"

extern "C" {
	void ConvertTextToTwoBytes(u8* src, int srcIdx, u8* dest);
}

#endif