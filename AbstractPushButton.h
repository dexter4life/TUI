
#ifndef ABSTRACT_PUSHBUTTON_H
#define ABSTRACT_PUSHBUTTON_H

#include "AbstractWidgetItem.h"

class AbstractPushButton : public AbstractWidgetItem
{
public:
	AbstractPushButton(TBase *parent = 0);
	virtual ~AbstractPushButton();
	void setText(std::string);
	std::string text();
	void setTextAlignment(TAlignment alignment);
	//void listenEvent( Event *event );

private:
	std::string buttonText;
};
#endif /*ABSTRACT_PUSHBUTTON_H*/