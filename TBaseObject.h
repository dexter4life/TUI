#ifndef TBASE_H
#define TBASE_H


#include <vector>
#include "Event.h"


#define DIMENSION_RECT_ACCERT( dimension )\
if (Rect(dimension).width() < MINIMUM_DIMENSION || \
	Rect(dimension).height() < MINIMUM_DIMENSION){\
	DEBUG_MESSAGE("width must be 3 or higher and height above 1");\
	throw std::invalid_argument("width must be 3 or higher and height above 1");\
	}

#define MINIMUM_DIMENSION 0x00002L

#ifdef MOUSE_MOVED
#undef MOUSE_MOVED
#include <Windows.h>
#ifndef DEBUG_REPORT
#define DEBGU_REPORT
static std::string msg;
static void debugMessage(){
	printf(msg.c_str());
	MessageBoxA(NULL, msg.c_str(), "ERROR: ", MB_OK | MB_ICONERROR );
}
#undef _WINDOW_
#endif /*DEBUG_REPORT*/
#endif /*MOUSE_MOVED*/
#define TOSTRING( StrValue ) #StrValue
#define DEBUG_MESSAGE( str )\
	msg = TOSTRING(str); \
	set_terminate(debugMessage);

#ifndef CNULLSTR 
#define CNULLSTR ""
#define nullstr CNULLSTR
#endif

class TBase
{
	TBase *parentptr;
	std::vector< TBase * > childrenItem;
	bool deleteChildren();
protected:
	Event *event;
	unsigned handle;
public:
	explicit TBase(TBase *parent = 0);
	virtual ~TBase();
	void appendChild(TBase *);
	virtual int exec() = 0;
	int childCount() const;
	int rowCount() const;
	TBase *child(int);
	TBase *parent() const;
	void setParent(TBase *parent);
	void installEventListener(Event *e);
	Event *eventListener();
};


#endif /* TBASE_H */