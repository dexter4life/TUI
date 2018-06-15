#include "PushButton.h"
#include <typeinfo>

#define button window

PushButton::PushButton(TBase *parent, std::string text)
: AbstractPushButton(parent)
{
	handle = (unsigned)this;
	setStyle(TStyleOption());
	setMouseHoverColor(TColor(1, COLOR_WHITE, COLOR_CYAN));

	if (text != std::string(nullstr))
		setText(text);
	setBorderVisibility(true);
}

PushButton::~PushButton()
{
}
void PushButton::paint(TStyleOption &option)
{
	window = newwin(rect.height(), rect.width(), rect.y(), rect.x());
	if (window)
	{
		if (borderVisibility())
		box(button, 0, 0);

		wbkgd(button, styleOption._pallete.texture | styleOption._pallete.color.mixColor());

		if (text().length() > (unsigned)rect.width())
		{
			rect.setWidth(text().length());
			mvwprintw(button, rect.height() / 2, 2, text().c_str());
			return;
		}
		if (!text().empty()){
			switch (alignflag)
			{
			case AlignCenter:
				mvwprintw(button, rect.height() / 2, ((text().length() != rect.width()) ?
					(rect.width() / 2) : text().length()), text().c_str());
				break;
			case AlignLeft:
				mvwprintw(button, rect.height()/2, 1, text().c_str());
				break;
			case AlignRight:
				mvwprintw(button, rect.height() / 2, ((text().length() != rect.width()) ?
					(rect.width() - text().length() + (text().length()-1)) : text().length()), text().c_str());
				break;
			}
		}
		else throw std::runtime_error("Can't creat " + std::string(typeid(*this).name()));
	}
	wrefresh(button);
}
int PushButton::exec()
{
	static TColor color = styleOption._pallete.color;
	if (isEnabled())
	{
		if (isMouseOn())
			setColor(hoverColor);
	}
	return 0;
}
void PushButton::show()
{	
	paint(styleOption);
}
