#include "TBaseObject.h"
#include <stdexcept>
#include <algorithm>
#include <string>

TBase::~TBase()
{
	if (!deleteChildren())
		throw std::runtime_error("Error deleting children of" + std::string(typeid(*this).name()));
}
bool TBase::deleteChildren()
{
	bool flag = true;
	std::for_each(childrenItem.begin(), childrenItem.end(), [&flag](TBase *p)->void {
		if (p == nullptr) flag = false;
		delete p;
	});
	return flag;
}
void TBase::setParent(TBase *parent)
{
	parent->appendChild(this);
}
//parents are responsible for deleting of the children
TBase::TBase(TBase *parent) 
{ 
	if (parent) parent->appendChild(this); 
}

//append child to parent
void TBase::appendChild(TBase *child) 
{ 
	childrenItem.push_back(child); 
}
// get child counts
int TBase::childCount() const 
{ 
	return childrenItem.size();  
}
// get row counts 
int TBase::rowCount() const 
{ 
	return childCount();  
}
//get the child 
TBase *TBase::child(int row) 
{ 
	return childrenItem[row]; 
}

void TBase::installEventListener(Event *e)
{
	event = e;
}
Event *TBase::eventListener()
{
	return event;
}
TBase *TBase::parent() const {	return parentptr; }