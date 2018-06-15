
#include "TColor.h"
#include "TStyleOption.h"

TStyleOption::TStyleOption( __int8 texture, TColor color)
{
	_pallete.color = color;
	_pallete.texture = texture;
}
