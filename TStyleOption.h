
#ifndef TSTYLE_OPTION_H
#define TSTYLE_OPTION_H

#include "TColor.h"

#ifndef ALIGNMENT
#define ALIGNMENT
enum TAlignment{
	AlignHCenter,
	AlignVCenter,
	AlignLeft,
	AlignRight,
	AlignTop,
	AlignBottom,
	AlignCenter = AlignHCenter | AlignVCenter
};
#endif
class TStyleOption
{
public:
	TStyleOption(__int8 texture = ' ', TColor color = TColor());

	struct _Pallete{
		TColor color, fcolor,
		textHightlight;
		__int8 texture;
	} _pallete;

	_Pallete pallete(){
		return _pallete;
	}
	void setTexture(__int8 texture){
		_pallete.texture = texture;
	}
	void setHighlight(TColor color){
		_pallete.color = color;
	}
	void setTextHightlight(TColor color){
		_pallete.textHightlight = color;
	}
};


#endif