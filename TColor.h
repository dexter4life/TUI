
#ifndef TCOLOR_H
#define TCOLOR_H

class TColor
{
public:
	explicit TColor(int id = 0, int fg = 0, int bg = 0);
	unsigned mixColor() const;
	//TColor &operator=(const TColor &);
	int fgColor() const;
	int bgColor() const;
	void setbgColor(int bg);
	void setfgColor(int fg);
	int colorId() const;
	TColor initialColor() const;
private:
	int color_id, fgcolor, bgcolor;
	
	struct TempColor{
		int id;
		int f;
		int b;
	} tempColor;
};

#endif /* TCOLOR_H */