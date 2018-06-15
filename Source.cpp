
#include "TApplication.h"
#include "PushButton.h"
#include "TitleBarWidget.h"


int main( int argc, char *argv[])
{
	TApplication app(argc, argv);
	
	TitleBarWidget widget;
	widget.setDimension(10, 5, 60, 10);
	widget.installEventListener(app.eventListener());
	//widget.setStyle(TStyleOption(' ', TColor(2, COLOR_WHITE, COLOR_BLUE)));
	widget.show();
	
	PushButton button1;
	button1.setDimension(30, 18, 2, 3);
	button1.setText("X");
	button1.setTextAlignment(AlignCenter);
	button1.setStyle(TStyleOption());
	button1.installEventListener(app.eventListener());
	//button1.show();

	app.addWidgetComponent(&widget);

	refresh();

	return app.exec();
}