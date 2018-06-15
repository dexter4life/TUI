#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include "AbstractPushButton.h"

class PushButton : public AbstractPushButton
{
public:
	PushButton(TBase *parent = 0, std::string text = nullstr);
	virtual ~PushButton();
	virtual void paint(TStyleOption &option);
	virtual void show();
	virtual int exec();
};

#endif /*PUSHBUTTON_H*/