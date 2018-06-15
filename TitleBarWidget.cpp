
#include "TitleBarWidget.h"
#include "PushButton.h"

TitleBarWidget::TitleBarWidget(TBase *parent, TStyleOption option)
 : AbstractWidgetItem(parent)
{
	setStyle(option);
	handle = unsigned(this);
	setBorderVisibility(true);

	setEnable(true);
	minimize = new PushButton(this, "-");
	minimize->setDimension(40, 0, 10, 10);
	minimize->setTextAlignment(AlignCenter);
	minimize->setEnable(true);
	minimize->setStyle(TStyleOption( ' ', TColor(3, COLOR_RED, COLOR_WHITE )));
	minimize->setMouseHoverColor(style().pallete().color);


	maximize = new PushButton(this, "+");
	maximize->setDimension(63, 5, 3, 3);
	maximize->setEnable(true);
	maximize->setTextAlignment(AlignCenter);
	maximize->setStyle(TStyleOption());
	maximize->installEventListener(eventListener());
	//maximize->show();
	
	close = new PushButton(this, "x");
	close->setDimension(66, 5, 3, 3);
	close->setTextAlignment(AlignCenter);
	close->setStyle(TStyleOption());
	close->installEventListener(eventListener());
	//close->show();
}
TitleBarWidget::~TitleBarWidget()
{

}

void TitleBarWidget::paint(TStyleOption &option)
{
	DIMENSION_RECT_ACCERT(rect)
	window = newwin(rect.height(), rect.width(), rect.y(), rect.x());
	
	WINDOW *sub = subwin(window, 10, 10, rect.y() + minimize->geometry().y(), rect.x() + minimize->geometry().x());
	
	init_pair(6, COLOR_WHITE, COLOR_RED);
	box(sub, 0, 0);
	wbkgd(sub,minimize->color().mixColor() |' ');
	minimize->setWindow(sub);
	if (borderVisibility())
	     box(window, 0, 0);
	wbkgd(window, styleOption._pallete.texture | styleOption._pallete.color.mixColor());

	wrefresh(window);
}

void TitleBarWidget::setStyle(TStyleOption option)
{
	this->styleOption = option;
}
int TitleBarWidget::exec()
{
	timeUpdate();

	if (isEnabled())
	{
		if (isMouseOn()){
			;
		}
			
	}
	
	minimize->exec();
	//minimize->show();
	
	/*
	maximize->exec();
	maximize->show();

	close->show();
	close->exec();
	*/
	refresh();
	return 0;
}
void TitleBarWidget::setDimension(int x, int y, int w, int h)
{
	AbstractWidgetItem::setDimension(x, y, w, h);
}
void TitleBarWidget::show()
{
	paint(styleOption);
}