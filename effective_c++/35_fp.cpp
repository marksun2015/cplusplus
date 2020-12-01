#include<iostream>

using namespace std;

class GameCharacter;
int defaultHealthCalc(const GameCharacter& gc);

class GameCharacter{
public:
	typedef int(*HealthCalcFunc)(const GameCharacter&);
	//函數指標類型宣告為HealthCalcFunc 的typedef, 返回int, 並接受參數const GameCharacter&  
	//using HealthCalcFunc = std::function<int(const GameCharacter&)>;

	explicit GameCharacter(HealthCalcFunc hfc = defaultHealthCalc)
	: healthFunc(hfc)
	{
		//cout << ">> GameCharacter: " << endl;
	}

	int healthValue() const 
	{ 
		return healthFunc(*this); 
	}
	virtual int getInitialValue() const 
	{ 
		return 50; 
	}

private:
	HealthCalcFunc healthFunc;
};

int defaultHealthCalc(const GameCharacter& gc){
	return gc.getInitialValue();
}


//////////////////////////////////
class EvilBadGuy :public GameCharacter{
public:
	explicit EvilBadGuy(HealthCalcFunc hcf = defaultHealthCalc) 
	: GameCharacter(hcf)
	{
		//cout << ">> EvilBadGuy " << endl;
	}

	virtual int getInitialValue() const
	{ 
		return 400; 
	}
};

int loseHealthQuickly(const GameCharacter& gc){
	int retVal = gc.getInitialValue();
	cout << "loseHealthQuickly: " << retVal << "/4" << endl;
	retVal /= 4;
	return retVal;
}

int loseHealthSlowly(const GameCharacter& gc){
	int retVal = gc.getInitialValue();
	cout << "loseHealthSlowly: " << retVal << "/2" << endl;
	retVal /= 2;
	return retVal;
}

////////////////////////////////////
int main(){
	EvilBadGuy badGuy1(loseHealthQuickly);
	cout << badGuy1.healthValue() << endl;

	EvilBadGuy badGuy2(loseHealthSlowly);
	cout << badGuy2.healthValue() << endl;

	return 0;
}
