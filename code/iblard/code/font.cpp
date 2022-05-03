#include "font.h"

const u8 widths[] = {
	3, //  	00
	3, // !	01
	5, // "	02
	8, // #	03
	8, // $	04
	11, // %	05
	11, // &	06
	3, // '	07
	5, // (	08
	5, // )	09
	8, // *	0A
	8, // +	0B
	3, // ,	0C
	4, // -	0D
	6, // .	0E
	3, // /	0F
	8, // 0	10
	6, // 1	11
	7, // 2	12
	9, // 3	13
	8, // 4	14
	8, // 5	15
	8, // 6	16
	8, // 7	17
	8, // 8	18
	8, // 9	19
	3, // :	1A
	3, // ;	1B
	8, // <	1C
	8, // =	1D
	8, // >	1E
	8, // ?	1F
	10, // @	20
	10, // A	21
	9, // B	22
	8, // C	23
	10, // D	24
	9, // E	25
	9, // F	26
	9, // G	27
	12, // H	28
	5, // I	29
	8, // J	2A
	10, // K	2B
	9, // L	2C
	15, // M	2D
	10, // N	2E
	10, // O	2F
	9, // P	30
	10, // Q	31
	10, // R	32
	8, // S	33
	10, // T	34
	9, // U	35
	10, // V	36
	15, // W	37
	10, // X	38
	10, // Y	39
	8, // Z	3A
	3, // [	3B
	6, // \	3C
	4, // ]	3D
	7, // ^	3E
	8, // _	3F
	4, // `	40
	8, // a	41
	8, // b	42
	8, // c	43
	8, // d	44
	7, // e	45
	6, // f	46
	8, // g	47
	9, // h	48
	4, // i	49
	4, // j	4A
	9, // k	4B
	4, // l	4C
	14, // m	4D
	9, // n	4E
	7, // o	4F
	8, // p	50
	7, // q	51
	6, // r	52
	7, // s	53
	5, // t	54
	9, // u	55
	8, // v	56
	12, // w	57
	8, // x	58
	9, // y	59
	7, // z	5A
	4, // {	5B
	2, // |	5C
	4, // }	5D
	7, // ~	5E
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