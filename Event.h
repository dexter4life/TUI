#ifndef EVENT_H
#define EVENT_H

#include <Windows.h>
#include "Rect.h"

#include <curses.h>

#define NCURSES_MOUSE_VERSION

enum WidgetEventType{
	BUTTON_CLICK, MOUSEMOVED_OVER_BUTT, MOUSE_FOCUS_ON_BUTT
};

typedef struct _Event{
	WidgetEventType eventType;
	DWORD eventState;
	Rect rect;
	unsigned objectTypeHandle;
}Event, *lpEvent;

static DWORD numberOfInput = 0;
static DWORD WINAPI inputThread( LPVOID event) {
	bool run = true;
#define _eventRef (static_cast<lpEvent> (event))
	MEVENT _mouse_event;
	nodelay(stdscr, true);
	mousemask(ALL_MOUSE_EVENTS, 0);
	char ch;
	while (run)
	{
		ch = getch();
		if (getmouse(&_mouse_event) == OK){
			 _eventRef->rect.setRect(_mouse_event.x, _mouse_event.y, 0, 0);
				_eventRef->eventState = _mouse_event.bstate;
			}
		refresh();
	}
	return 0;
}

#undef _WINDOW_ //avoid MOUSE_MOVED warning
#endif