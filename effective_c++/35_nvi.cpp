#include<iostream>
using namespace std;

class GameCharacter{
public:
	int healthValue() const;

private:
	virtual int getInitialValue() const;
	virtual int doHealthValue(int healthValue) const;
};

int GameCharacter::healthValue() const{
	int retVal = getInitialValue();
	int doretVal = doHealthValue(retVal);

	return doretVal;
}

int GameCharacter::getInitialValue() const{
	return 100;
}

int GameCharacter::doHealthValue(int healthValue) const{
	return healthValue;
}

////////////////
class EvilBadGuy:public GameCharacter{
private:
	virtual int getInitialValue() const;
	virtual int doHealthValue(int healthValue) const;
};

int EvilBadGuy::getInitialValue() const{
	return 400;
}

int EvilBadGuy::doHealthValue(int healthValue) const{
	return healthValue / 2;
}
////////////////

int main(){
	EvilBadGuy badGuy;
	cout << badGuy.healthValue() << endl;

	return 0;
}
