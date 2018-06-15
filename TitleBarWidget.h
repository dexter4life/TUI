
#ifndef WIDGET_H
#define WIDGET_H

#include "AbstractWidgetItem.h"

class PushButton;

/*
	---------------------------------------
	|								|+|-|X|
	|--------------------------------------
	|									  |	
	|									  |
	|									  |
	|_____________________________________|
*/
#include <curses.h>
#include "TStyleOption.h"

class TitleBarWidget : public AbstractWidgetItem
{
public:
	TitleBarWidget(TBase *parent = 0, TStyleOption option = TStyleOption(' ', TColor(2, COLOR_WHITE, COLOR_BLUE)));
	~TitleBarWidget();
	virtual int exec();
	virtual void show();
	virtual void paint(TStyleOption &option);
	virtual void setStyle(TStyleOption option);
	virtual void setDimension(int x, int y, int w, int h = 3);
private:
	PushButton *minimize;
	PushButton *maximize;
	PushButton *close;
};

#endif /*WIDGET_H*/