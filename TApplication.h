#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <vector>
#include <string>
#include <algorithm>
#include "Rect.h"


#include <curses.h>
#pragma comment(lib, "pdcurses.lib")

#ifdef MOUSE_MOVED
#undef MOUSE_MOVED
#include "Event.h"
#endif



using std::string;
using std::vector;

#include "TBaseObject.h"
#include "Event.h"

class TApplication
{
public:
	explicit TApplication( int argc, char *argv[] );
	~TApplication();
	void displayBorders();
	int argumentCount() const;
	std::string argument(int index) const;
	void queryUserInput();
	void addWidgetComponent(TBase *base);
	int exec();
	void timeUpdate();
	Event *eventListener();
protected:
	Event event;
private:
	//holds the commandline arguments;
	vector<string> cParams;
	vector<TBase*> widgets;
	bool color_enabled;
	INPUT_RECORD input_record[16];
	DWORD dwThreadId;
	HANDLE handle;
};


#endif