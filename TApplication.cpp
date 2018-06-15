
#include "TApplication.h"

#pragma comment(lib, "winmm.lib")

TApplication::TApplication(int argc, char *argv[])
{
	
	//set the commandline arguments
	handle = CreateThread(0, 0, inputThread, &event, 0, &dwThreadId);
	for (int i = 0; i < argc; ++i)
		cParams.push_back(argv[i]);

	initscr();
	cbreak();
	noecho();
	curs_set(0);

	if (has_colors()){
		color_enabled = true;
		start_color();
	}	
	refresh();
}
TApplication::~TApplication()
{
	nocbreak();
	noraw();
	echo();
	endwin();
}

void TApplication::displayBorders()
{
	box(stdscr, 0, 0);
}
void TApplication::addWidgetComponent(TBase *widget){
	widgets.push_back(widget);
}
int TApplication::exec()
{
	bool run = true;
	keypad(stdscr, true);
	
	while (run)
	{ 
		while (true)
		{
			std::for_each(widgets.begin(), widgets.end(), [](TBase *base)->void 
			{
				base->exec();
			});
		}
	}
	return 0;
}

int TApplication::argumentCount() const{
	return this->cParams.size();
}
std::string TApplication::argument(int index) const{
	return this->cParams[index];
}
Event *TApplication::eventListener()
{
	return &event;
}