#include<iostream>
using namespace std;

class GameCharacter;
class HealthCalcFunc{
	public:
		virtual int calc(const GameCharacter& gc) const;
};

class LoseHealthQuickly :public HealthCalcFunc{
	public:
		virtual int calc(const GameCharacter& gc) const;
};

class LoseHealthSlowly :public HealthCalcFunc{
	public:
		virtual int calc(const GameCharacter& gc) const;
};

HealthCalcFunc defaultHealthCalc;

////////////////////////////////////////////////////////
class GameCharacter{
	public:
		explicit GameCharacter(HealthCalcFunc* phcf = &defaultHealthCalc) 
		: pHealthFunc(phcf)
		{}

		int healthValue() const 
		{ 
			return pHealthFunc->calc(*this); 
		}

		virtual int getInitialValue() const 
		{ 	
			return 50; 
		}

	private:
		HealthCalcFunc* pHealthFunc;
};


class EvilBadGuy :public GameCharacter{
	public:
		explicit EvilBadGuy(HealthCalcFunc* phcf = &defaultHealthCalc) 
		:GameCharacter(phcf)
		{}

		virtual int getInitialValue() const
		{ 
			return 400; 
		}
};

////////////////////////////////////
int HealthCalcFunc::calc(const GameCharacter& gc) const{
	int retVal = gc.getInitialValue();
	return retVal;
}
int LoseHealthQuickly::calc(const GameCharacter& gc) const{
	int retVal = gc.getInitialValue();
	retVal /= 4;
	return retVal;
}
int LoseHealthSlowly::calc(const GameCharacter& gc) const{
	int retVal = gc.getInitialValue();
	retVal /= 2;
	return retVal;
}


////////////////////////////////////

int main(){
	EvilBadGuy badGuy1;
	cout << badGuy1.healthValue() << endl;

	LoseHealthQuickly loseHealthQuickly;
	EvilBadGuy badGuy2(&loseHealthQuickly);
	cout << badGuy2.healthValue() << endl;

	LoseHealthSlowly loseHealthSlowly;
	EvilBadGuy badGuy3(&loseHealthSlowly);
	cout << badGuy3.healthValue() << endl;

	//system("pause");
	return 0;
}
