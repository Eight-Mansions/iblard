#include "font.h"

const u8 widths[] = {
	0x03, //  	00
	0x12, // !	01
	0x08, // "	02
	0x0C, // #	03
	0x0B, // $	04
	0x0F, // %	05
	0x0E, // &	06
	0x05, // '	07
	0x07, // (	08
	0x07, // )	09
	0x0B, // *	0A
	0x0D, // +	0B
	0x05, // ,	0C
	0x0D, // -	0D
	0x00, // .	0E
	0x11, // /	0F
	0x0B, // 0	10
	0x08, // 1	11
	0x0B, // 2	12
	0x0B, // 3	13
	0x0C, // 4	14
	0x0B, // 5	15
	0x0B, // 6	16
	0x0B, // 7	17
	0x0B, // 8	18
	0x0B, // 9	19
	0x05, // :	1A
	0x12, // ;	1B
	0x0D, // <	1C
	0x0D, // =	1D
	0x0E, // >	1E
	0x0B, // ?	1F
	0x0F, // @	20
	0x0E, // A	21
	0x0D, // B	22
	0x0D, // C	23
	0x12, // D	24
	0x12, // E	25
	0x0C, // F	26
	0x0E, // G	27
	0x0E, // H	28
	0x08, // I	29
	0x0B, // J	2A
	0x0E, // K	2B
	0x0C, // L	2C
	0x0F, // M	2D
	0x0E, // N	2E
	0x12, // O	2F
	0x0C, // P	30
	0x0F, // Q	31
	0x0F, // R	32
	0x0C, // S	33
	0x0E, // T	34
	0x0F, // U	35
	0x0F, // V	36
	0x12, // W	37
	0x0F, // X	38
	0x10, // Y	39
	0x0D, // Z	3A
	0x08, // [	3B
	0x12, // \	3C
	0x07, // ]	3D
	0x00, // ^	3E
	0x10, // _	3F
	0x10, // `	40
	0x0C, // a	41
	0x0C, // b	42
	0x0A, // c	43
	0x0C, // d	44
	0x12, // e	45
	0x0A, // f	46
	0x0C, // g	47
	0x0D, // h	48
	0x07, // i	49
	0x08, // j	4A
	0x0C, // k	4B
	0x07, // l	4C
	0x0F, // m	4D
	0x0D, // n	4E
	0x0B, // o	4F
	0x0C, // p	50
	0x0C, // q	51
	0x0A, // r	52
	0x0A, // s	53
	0x09, // t	54
	0x0C, // u	55
	0x0D, // v	56
	0x0F, // w	57
	0x0C, // x	58
	0x0D, // y	59
	0x0B, // z	5A
	0x00, // {	5B
	0x10, // |	5C
	0x11, // }	5D
	0x11, // ~	5E
};


u32 GetLetterWidth(const u32 letter)
{
	if (letter >= 0x829F && letter <= 0x82FE)
	{
		u32 idx = letter - 0x829F;
		return widths[idx];
	}
	else
	{
		return 0x10;
	}
}

u32 GetSentenceWidth(const u16* text, const u16* end)
{
	int textWidth = 0;
	int length = end - text;
	for (int i = 0; i < length; i++) // There is also a check for <$09> but not sure what that does... maybe breaks too?
	{
		u32 letter = (text[i] & 0xFF) << 8 | text[i] >> 8;
		if (letter == 0x5C6E) // Not sure if it starts after or before the \n...
		{
			textWidth = 0;
		}
		else
		{
			textWidth += GetLetterWidth(letter);
		}
	}
	return textWidth;
}

//int GetYForCentering(const char* text, u32 length)
//{
//	u32 textwidth = GetSentenceWidth(text, length);
//
//	return (int)((256 >> 1) - (textwidth >> 1)); // 256 is the width of text box texture
//}