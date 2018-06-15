#include "AbstractPushButton.h"

AbstractPushButton::AbstractPushButton(TBase *parent) 
:AbstractWidgetItem(parent)
{
}
AbstractPushButton::~AbstractPushButton()
{
}
void AbstractPushButton::setText(std::string txt){
	buttonText = txt;
}
std::string AbstractPushButton::text(){
	return buttonText;
}

void AbstractPushButton::setTextAlignment(TAlignment alignment){
		alignflag = alignment;
}
