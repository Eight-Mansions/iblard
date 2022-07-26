
#ifndef LOADFILE_H_
#define LOADFILE_H_

#include "platform.h"

extern "C" {
	extern void LoadFile(u_long* filepos, const char* filename, u32 unk1);
	void LoadSubtitles(u_long* filepos);
}

#endif