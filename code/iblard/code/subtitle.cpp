#include "subtitle.h"

int sec = 0;
const u8 test[] = { 0x88, 0xC4, 0x93, 0xE0, 0x90, 0x7D };

void DisplayLetter()
{
	currSub.parts = subs[0].parts;
	currSub.partsCount = subs[0].partsCount;
	currSub.currentPart = 0;

	for (int i = 0; i < currSub.parts[currSub.currentPart].len; i++)
	{
		DisplayText(currSub.parts[currSub.currentPart].text, i, 0, 0, 0);
	}
}

void ClearText()
{
	DisplayText((const char*)0, 64, 1, 0, 0);
}