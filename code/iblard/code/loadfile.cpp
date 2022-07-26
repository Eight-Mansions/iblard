#include "loadfile.h"

void LoadSubtitles(u_long* filepos)
{
	const char* filename = "\\ETC\\SUBTITLES.DAT;1";
	LoadFile(filepos, filename, 0);
}
