
#ifndef RECT_H
#define RECT_H

class Rect
{
	int xpos;
	int ypos;
	int w;
	int h;

public:
	Rect(int x = 0, int y= 0, int _w= 0, int _h = 0){
		setRect(x, y, _w, _h);
	}
	inline int x() const { return xpos;  }
	inline int y() const { return ypos;  }
	inline int width() const { return w;  }
	inline int height() const { return h;  }

	void setX(int x) { xpos = x; }
	void setY(int y) { ypos = y; }
	void setWidth(int _w) { w = _w;  }
	void setHeight(int _h) { h = _h;  }
	//set the dimensions and position 
	void setRect(int x, int y, int _w, int _h){
		xpos = x;
		ypos = y;
		w = _w;
		h = _h;
	}
	void setRect(const Rect rect){
		setRect(rect.xpos, rect.ypos, rect.w, rect.h);
	}
};


#endif /* RECT_H */