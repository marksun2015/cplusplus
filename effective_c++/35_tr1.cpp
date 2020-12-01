#include <iostream>
#include <functional>

using namespace std;

class GameCharacter;
short defaultHealthCalc(const GameCharacter& gc); //注意返回類型不是int

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

/*
「函式物件」(Function Object) 或 「函子」(Functor) 是實作 operator() 的任何類型。 
這個運算子稱為 「呼叫運算子」 (Call Operator)，有時也稱為 
「應用運算子」(Application Operator)。 C++ 標準程式庫主要是將函式物件當作容器的
排序準則來使用，以及用於演算法中。
 */
/* func object */
struct LoseHealthQuickly{
	int operator()(const GameCharacter& gc) const{
		int retVal = gc.getInitialValue();
		retVal /= 4;
		return retVal;
	}
};

/* member func */
class GameLevel{
public:
	float loseHealthSlowly(const GameCharacter& gc) const{  //注意返回類型不是int
		float retVal = static_cast<float>(gc.getInitialValue());
		retVal /= 2;
		return retVal;
	}
};

int main(){
	EvilBadGuy badGuy1;			//普通函數計算健康指數  
	cout << badGuy1.healthValue() << endl;

	LoseHealthQuickly loseHealthQuickly;	//函數物件(func object)計算健康指數 
	EvilBadGuy badGuy2(loseHealthQuickly);
	cout << badGuy2.healthValue() << endl;

	GameLevel currentLevel;			//成員函數(member function)計算健康指數  
	EvilBadGuy badGuy3(bind(&GameLevel::loseHealthSlowly, currentLevel, placeholders::_1));
	cout << badGuy3.healthValue() << endl;

	//system("pause");
	return 0;
}
