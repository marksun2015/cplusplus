#include<iostream>
#include<string>

using namespace std;

class Shape{
public:
	virtual void draw(const string& color = "red") const = 0;
};

class Rectangle :public Shape{
public:
	virtual void draw(const string& color = "green") const{
		cout << "Rectangle draw" << color << endl;
	}
};

class Circle :public Shape{
public:
	virtual void draw(const string& color) const{
		cout << "Circle draw: "  << color << endl;
	}
	// draw() with no default value
    	// 這個寫法，在使用者以物件呼叫此 function時，
    	// 一定要指定參數值，因為 statically binding 下，
    	// 這個 function 並不會從其 base class 繼承 default value。
    	// 但若是以 pointer 或 reference 呼叫此 function，
    	// 則可以不指定參數值，因為 dynamically binding 下，
    	// 這個 function 會從其 base class 繼承 default value。
};

int main(){
	//case1
	Shape* pr = new Rectangle;
	pr->draw(); //Red
	//因為宣告為Shape(statically bind), 編譯時statically binding已經榜了default:red  
	//virtual在dynamic binding時, c++效率關係, 會去找靜態榜定的default:red   

	//case2
	Shape* pc = new Circle;  	
	pc->draw(); //Red  		//可以不指定參數, 因為dynamic binding, 會從base class繼承draw  

	//case4
	Circle c;
	c.draw("black"); //black 	//要指定參數, 因為statically binding, 不會從base class繼承default draw  
					//不指定的話, 編議會失敗 
	
	//case5
	//Rectangle* pr1 = new Rectangle;
	//pr1->draw(); //Green

	//system("pause");
	return 0;
}
