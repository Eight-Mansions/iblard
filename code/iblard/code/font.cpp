#include "font.h"

const u8 widths[] = {
	0x00, //  
	0x12, // !
	0x08, // "
	0x0C, // #
	0x0B, // $
	0x0F, // %
	0x0E, // &
	0x05, // '
	0x07, // (
	0x07, // )
	0x0B, // *
	0x0D, // +
	0x05, // ,
	0x0D, // -
	0x00, // .
	0x11, // /
	0x0B, // 0
	0x08, // 1
	0x0B, // 2
	0x0B, // 3
	0x0C, // 4
	0x0B, // 5
	0x0B, // 6
	0x0B, // 7
	0x0B, // 8
	0x0B, // 9
	0x05, // :
	0x12, // ;
	0x0D, // <
	0x0D, // =
	0x0E, // >
	0x0B, // ?
	0x0F, // @
	0x0E, // A
	0x0D, // B
	0x0D, // C
	0x12, // D
	0x12, // E
	0x0C, // F
	0x0E, // G
	0x0E, // H
	0x08, // I
	0x0B, // J
	0x0E, // K
	0x0C, // L
	0x0F, // M
	0x0E, // N
	0x12, // O
	0x0C, // P
	0x0F, // Q
	0x0F, // R
	0x0C, // S
	0x0E, // T
	0x0F, // U
	0x0F, // V
	0x12, // W
	0x0F, // X
	0x10, // Y
	0x0D, // Z
	0x08, // [
	0x12, // \
	0x07, // ]
	0x00, // ^
	0x10, // _
	0x10, // `
	0x0C, // a
	0x0C, // b
	0x0A, // c
	0x0C, // d
	0x12, // e
	0x0A, // f
	0x0C, // g
	0x0D, // h
	0x07, // i
	0x08, // j
	0x0C, // k
	0x07, // l
	0x0F, // m
	0x0D, // n
	0x0B, // o
	0x0C, // p
	0x0C, // q
	0x0A, // r
	0x0A, // s
	0x09, // t
	0x0C, // u
	0x0D, // v
	0x0F, // w
	0x0C, // x
	0x0D, // y
	0x0B, // z
	0x00, // {
	0x10, // |
	0x11, // }
	0x11, // ~
};

int GetLetterWidth(const u32 letter)
{
	if (letter >= 0x8260 && letter <= 0x82BF)
	{
		u32 idx = letter - 0x824F;
		return widths[idx];
	}
	else
	{
		return 0x0F;
	}
}

int GetSentenceWidth(const char* text, u32 length)
{
	int textWidth = 0;
	for (int i = 0; i < length; i++) // There is also a check for <$09> but not sure what that does... maybe breaks too?
	{
		int letter = 0;
		
		if (text[i] == 0x0A || text[i] == 0x00)
			break;

		if (text[i] > 0x80)
		{  letter = (text[i] << 0x8) + text[i + 1];
			i++;
		}
		else
		{
			letter = text[i] + 0x823F;
		}

		textWidth += GetLetterWidth(letter);
	}
	return textWidth;
}

int GetYForCentering(const char* text, u32 length)
{
	u32 textwidth = GetSentenceWidth(text, length);

	return (int)((256 >> 1) - (textwidth >> 1)); // 256 is the width of text box texture
}