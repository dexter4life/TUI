
#include "TColor.h"
#include <curses.h>

TColor::TColor(int id, int fg, int bg)
: color_id(id), fgcolor(fg), bgcolor(bg){
	init_pair(id, fgcolor, bgcolor);
	tempColor.b = bgcolor;
	tempColor.f = fgcolor;
	tempColor.id = id;
}
int TColor::fgColor() const{
	return fgcolor;
}
int TColor::bgColor() const{
	return bgcolor;
}
int TColor::colorId() const
{
	return color_id;
}
unsigned TColor::mixColor() const{
	return COLOR_PAIR(color_id);
}
TColor TColor::initialColor() const
{
	return TColor(tempColor.id, tempColor.f, tempColor.b);
}
void TColor::setbgColor(int bg)
{	
	bgcolor = bg;
}	
void TColor::setfgColor(int fg)
{
	fgcolor = fg;
}