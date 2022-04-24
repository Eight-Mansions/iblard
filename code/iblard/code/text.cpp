#include "text.h"

void ConvertTextToTwoBytes(u8* src, int srcIdx, u8* dest)
{
	int destIdx = 0;
	for (; srcIdx < 0x800; srcIdx++)
	{
		u16 letter = src[srcIdx];
		if (letter != '\\')
		{
			letter += 0x827F;
			dest[destIdx++] = letter >> 8;
			dest[destIdx++] = letter & 0xFF;
		}
		else
		{
			dest[destIdx++] = (u8)letter;
			dest[destIdx++] = src[srcIdx + 1];
			srcIdx++;
		}

		if ((u8)letter == '\n' || (u8)letter == '\r')
		{
			dest[destIdx] = (u8)letter;
			break;
		}
	}

	return;
}