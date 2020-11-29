#include<iostream>
#include<string>
using namespace std;

class Shape{
public:
	//宣告為non-virtual  
	void draw(const string& color = "red") const{
		doDraw(color);
	}

private:
	virtual void doDraw(const string& color) const = 0;
};

class Rectangle :public Shape{
public:
	virtual void doDraw(const string& color) const{
		cout << "Rectangle draw: " << color << endl;
	}
};

class Circle :public Shape{
public:
	virtual void doDraw(const string& color) const{
		cout << "circle draw: " << color << endl;
	}
};

int main(){
	Shape* pr = new Rectangle;
	pr->draw();

	Shape* pc = new Circle;
	pc->draw();

	Circle c;
	c.draw("black");

	//system("pause");
	return 0;
}
