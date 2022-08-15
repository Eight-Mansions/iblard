#include "subtitle.h"

int counter = 0;

int sdbmHash(const char* text) {
	int hash = 0;
	int i = 0;

	for (; text[i] != 0; i++) {
		hash = text[i] + (hash << 6) + (hash << 16) - hash;
	}
	return hash;
}

void InitSubtitle(const char* audioname, int idx)
{
	printf("name: %s - idx: %d", audioname, idx);
	int audionameHash = sdbmHash(audioname);
	for (int i = 0; i < subsCount; i++)
	{
		if (audionameHash == subs[i].id && idx == subs[i].idx)
		{
			counter = 0;
			currSub.parts = subs[i].parts;
			currSub.partsCount = subs[i].partsCount;
			currSub.nextPartIdx = 0;
			currSub.ticksTilNext = subs[i].parts[currSub.nextPartIdx].displayTime;
		}
	}
}

void DisplaySubtitle()
{
	
	if (currSub.parts != NULL)
	{
		printf("%d\n", counter++);
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
}

void ClearText()
{
	currSub.parts = NULL;
	DisplayText((const char*)0, 64, 1, 0, 0);
}

void InitMovieSubtitle(const char* videoname)
{
	printf("Movie: %s\n", videoname);
	movieSubIdx = -1;
	int videonameHash = sdbmHash(videoname);
	for (int i = 0; i < movieSubtitlesCount; i++)
	{
		if (videonameHash == movieSubtitles[i].id)
		{
			movieSubIdx = i;
			break;
		}
	}
}

void DrawMovieSubtitle(RECT* area, u16* image, u16* font, u32 curFrame)
{
	u32 sliceW = area->w;
	u32 sliceX = area->x;

	if (movieSubIdx >= 0)
	{
		MovieSubtitle subs = movieSubtitles[movieSubIdx];

		if (curFrame != currentMovieFrame)
		{
			currentMovieFrame = curFrame;
			currentMovieSubtitleIndexes[0] = -1;
			currentMovieSubtitleIndexes[1] = -1;
			currentMovieSubtitleIndexes[2] = -1;
			int idx = 0;

			for (int i = 0; i < subs.partsCount; i++)
			{
				if (subs.parts[i].startFrame <= curFrame && curFrame < subs.parts[i].endFrame)
				{
					currentMovieSubtitleIndexes[idx] = i;
					idx++;
				}
			}
		}

		for (int i = 0; i < 3 && currentMovieSubtitleIndexes[i] != -1; i++)
		{
			int idx = currentMovieSubtitleIndexes[i];

			const char* text = subs.parts[idx].text;

			if (sliceX <= subs.parts[idx].x && subs.parts[idx].x < sliceX + sliceW)
			{
				subs.parts[idx].textIdx = 0;
				subs.parts[idx].curX = subs.parts[idx].x - sliceX;
				subs.parts[idx].curY = subs.parts[idx].y * 16; // 16 comes from max width of a character = 8 * 2 (16bpp = 2 bytes)
			}

			u16 curX = subs.parts[idx].curX;
			u16 curY = subs.parts[idx].curY;
			while (subs.parts[idx].textIdx < subs.parts[idx].len)
			{
				u32 srcPixelPos = text[subs.parts[idx].textIdx] << 7; // 0x80 is half the width of our letters.  The entire byte count is (w * 2 (16bpp) * h).  We're using shorts or 2 bytes at a time so half.

				bool overflowed = false;
				for (u32 x = 0; x < 8; x++) // 8 is our max letter width... soon will be width of letter
				{
					u32 imgPos = curX + curY;
					for (u32 y = 0; y < 256;) // += 16 comes from max width of a character = 8 * 2 (16bpp = 2 bytes)  ----- 256 = may height times the 16 we get from the previous equation
					{
						// 0x8000 is the pixel color of the black background
						u16 sp = font[srcPixelPos++];
						if (sp != 0x8000) image[imgPos + y] = sp;

						y += 16;
					}

					curX++;
				}

				subs.parts[idx].textIdx++;

				if (curX >= sliceW)
				{
					subs.parts[idx].curX = 0;
					break;
				}
			}
		}
	}

	LoadImage(area, (u_long*)image);
}