#ifndef ABSTRACT_WIDGET_ITEM_H
#define ABSTRACT_WIDGET_ITEM_H

#include "TBaseObject.h"
#include <curses.h>
#include "TBaseObject.h"
#include "TColor.h"
#include "Rect.h"
#include "TStyleOption.h"
#include "Event.h"


class AbstractWidgetItem : public TBase
{
public:
	AbstractWidgetItem(TBase *parent = 0);
	virtual ~AbstractWidgetItem();
	virtual void show() = 0;
	virtual void paint(TStyleOption &option) = 0;
	virtual void setbgColor(int color);
	virtual void setfgColor(int color);
	virtual void setColor(TColor color);
	virtual bool isMouseOn();
	bool isClicked() const;
    int bgColor() const;
	int fgColor() const;
	TColor color() const;
	bool isActive() const;
	Rect dimension() const;
	void timeUpdate();
	virtual void setDimension(int, int, int = 5, int = 3);
	void setDimension(Rect &&rect);
	virtual void setStyle(TStyleOption option = TStyleOption());
	virtual TStyleOption style() const;
	void setActive(bool );
	void setEnable(bool );
	void setBorderVisibility(bool);
	bool borderVisibility() const;
	bool isEnabled() const;
	virtual void setMouseHoverColor(TColor color = TColor());
	inline Rect &getRect(){
		return rect;
	}
	inline WINDOW *win(){
		return window;
	}
	inline Rect &geometry(){
		return rect;
	}
	inline void setWindow(WINDOW * win){
		window = win;
	}
protected:
	double frameCount;
	double endTime;
	bool active;
	void reset_flags(bool b);
	Rect rect;
	WINDOW *window;
	TStyleOption styleOption;
	TAlignment alignflag;
	int fColor, bColor;
	TColor hoverColor;
	bool click;
	bool enabled;
	bool _border_visibility;
	void showBorder() const;
};

#endif