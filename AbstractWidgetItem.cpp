
#include "AbstractWidgetItem.h"

AbstractWidgetItem::AbstractWidgetItem( TBase *parent )
: TBase(parent)
{
	setStyle();
}
AbstractWidgetItem::~AbstractWidgetItem()
{
	delwin(window);
}
void AbstractWidgetItem::setbgColor(int color){
	bColor = color;
}

void AbstractWidgetItem::setfgColor(int color){
	fColor = color;
}

Rect AbstractWidgetItem::dimension() const{
	return rect;
}
void AbstractWidgetItem::setDimension(int x, int y, int w, int h)
{
	DIMENSION_RECT_ACCERT(Rect(x, y, w, h));
	rect.setRect(Rect(x, y, w, h));
}
void AbstractWidgetItem::setDimension(Rect &&rect) throw(...)
{
	DIMENSION_RECT_ACCERT(rect);
	rect.setRect(rect.x(), rect.y(), rect.width(), rect.height());
}
void AbstractWidgetItem::setStyle(TStyleOption option){
	styleOption = option;
	setbgColor(option._pallete.color.bgColor());
	setfgColor(option.pallete().color.fgColor());
}

TStyleOption AbstractWidgetItem::style() const{
	return styleOption;
}

bool AbstractWidgetItem::isClicked() const {
	return click;
}
int AbstractWidgetItem::bgColor() const{
	return bColor;
}
int AbstractWidgetItem::fgColor() const{
	return fColor;
}
TColor AbstractWidgetItem::color() const
{
	return styleOption._pallete.color;
}
bool AbstractWidgetItem::isActive() const{
	return active;
}
void AbstractWidgetItem::setActive(bool a)
{
	active = a;
}
void AbstractWidgetItem::reset_flags(bool b)
{
	active = b;
	click = b;
}
void AbstractWidgetItem::setEnable(bool value)
{
	enabled = value;
}
void AbstractWidgetItem::setBorderVisibility(bool value)
{
	_border_visibility = value;
}
bool AbstractWidgetItem::borderVisibility() const
{
	return _border_visibility;
}
bool AbstractWidgetItem::isEnabled() const
{
	return enabled;
}
void AbstractWidgetItem::setColor(TColor color)
{
	styleOption._pallete.color = color;
}
void AbstractWidgetItem::setMouseHoverColor(TColor color)
{
	hoverColor = color;
}
bool AbstractWidgetItem::isMouseOn()
{
	int x = 0, y = 0;
	wmouse_position(window, &y, &x);
	if (x != -1 && y != -1)
	{
		setActive(true);
		return  true;
	}

	setActive(false);
	return false;
}
void AbstractWidgetItem::timeUpdate()
{
	double currentTime = timeGetTime() - endTime;

	if (currentTime < 30)
		return;

	endTime = timeGetTime();
}