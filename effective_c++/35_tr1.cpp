#include <iostream>
#include <functional>

using namespace std;

class GameCharacter;
short defaultHealthCalc(const GameCharacter& gc);//注意其返回类型不是int

class GameCharacter{
public:
	typedef std::function<int(const GameCharacter&)> HealthCalcFunc;
	
	explicit GameCharacter(HealthCalcFunc hfc = defaultHealthCalc) 
	:healthFunc(hfc)
	{}
	int healthValue() const 
	{ return healthFunc(*this); }

	virtual int getInitialValue() const 
	{ return 50; }

private:
	HealthCalcFunc healthFunc;
};

short defaultHealthCalc(const GameCharacter& gc){
	return gc.getInitialValue();
}

////////////////////////////////////////
class EvilBadGuy :public GameCharacter{
public:
	explicit EvilBadGuy(HealthCalcFunc hcf = defaultHealthCalc) 
	:GameCharacter(hcf)
	{}

	virtual int getInitialValue() const
	{ return 400; }

};

struct LoseHealthQuickly{
	int operator()(const GameCharacter& gc) const{
		int retVal = gc.getInitialValue();
		retVal /= 4;
		return retVal;
	}
};

class GameLevel{
public:
	float loseHealthSlowly(const GameCharacter& gc) const{//注意返回类型不是int
		float retVal = static_cast<float>(gc.getInitialValue());
		retVal /= 2;
		return retVal;
	}
};

//////////////////////////////////////////////////
int main(){
	EvilBadGuy badGuy1;//默认普通函数计算健康指数
	cout << badGuy1.healthValue() << endl;

	LoseHealthQuickly loseHealthQuickly;//函数对象计算健康指数
	EvilBadGuy badGuy2(loseHealthQuickly);
	cout << badGuy2.healthValue() << endl;

	GameLevel currentLevel;//成员函数计算健康指数
	EvilBadGuy badGuy3(bind(&GameLevel::loseHealthSlowly, currentLevel, placeholders::_1));
	cout << badGuy3.healthValue() << endl;

	//system("pause");
	return 0;
}
