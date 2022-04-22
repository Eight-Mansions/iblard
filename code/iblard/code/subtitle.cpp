#include "subtitle.h"

int sec = 0;
const u8 test[] = { 0x88, 0xC4, 0x93, 0xE0, 0x90, 0x7D };

void DisplayLetter()
{
	currSub.parts = subs[0].parts;
	currSub.partsCount = subs[0].partsCount;
	currSub.nextPartIdx = 0;
	currSub.ticksTilNext = subs[0].parts[currSub.nextPartIdx].displayTime;
}

void DisplaySubtitle()
{
	currSub.ticksTilNext--;
	if (currSub.partsCount != 0 && currSub.ticksTilNext == 0)
	{
		for (int i = 0; i < currSub.parts[currSub.nextPartIdx].len; i++)
		{
			DisplayText(currSub.parts[currSub.nextPartIdx].text, i, 0, 0, 0);
		}

		currSub.nextPartIdx++;
		if (currSub.nextPartIdx < currSub.partsCount)
		{
			currSub.ticksTilNext = currSub.parts[currSub.nextPartIdx].displayTime;
		}
		else
		{
			currSub.partsCount = 0; // No parts left to show
		}
	}
}

void ClearText()
{
	DisplayText((const char*)0, 64, 1, 0, 0);
}