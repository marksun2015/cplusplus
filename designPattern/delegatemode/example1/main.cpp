// 大話設計模式  

#include<iostream>
#include<string>
using namespace std;

//SchoolGirl類
class SchoolGirl final // 添加 final 關鍵字 表明該類不能做一個基類
{
private:
	std::string m_name;
public:
	void setName(std::string name)
	{
		m_name = name;
	}
	string getName() { return m_name; }
};


// 抽象主題類（Subject）類，定義了 實際主題類（RealSubject）和代理類（Proxy）的共用接口，這樣就可以在任何使用 RealSubject 的地方使用Proxy
class IGiveGift
{
public:
	virtual ~IGiveGift() = default;
	virtual void GiveDolls() = 0;
	virtual void GiveFlowers() = 0;
	virtual void GiveChocolate() = 0;
};

//實際主題（RealSubject）類，定義了代理類（Proxy）真正需要調用的方法
class Pursuit final : public IGiveGift 
{
public:
	explicit Pursuit(SchoolGirl *mm);
	void GiveDolls() override;
	 void GiveFlowers()override;
	 void GiveChocolate() override;
private:
	SchoolGirl *m_girl;

};
Pursuit::Pursuit(SchoolGirl *mm)
{
	m_girl = mm;
}
void Pursuit::GiveDolls() 
{
	m_girl->setName("洋娃娃");
	std::cout << "送給 m_girl：" << m_girl->getName() << endl;
}
void Pursuit::GiveFlowers()
{
	m_girl->setName("鮮花");
	std::cout << "送給 m_girl：" << m_girl->getName() << endl;
}
void Pursuit::GiveChocolate()
{
	m_girl->setName("巧克力");
	std::cout << "送給 m_girl：" << m_girl->getName() << endl;
}


//代理類（Proxy），保存一個引用使的代理對可以訪問實體，並提供一個與Subject的接口相同的接口，這樣代理就可以用來替代實體
class Proxy final :public IGiveGift 
{
private:
	Pursuit *purObject;
public:
	explicit Proxy(SchoolGirl *pur);
	void GiveDolls() override;
	void GiveFlowers()override;
	void GiveChocolate() override;
};

Proxy::Proxy(SchoolGirl *pur)
{
	purObject = new Pursuit(pur);
}

void Proxy::GiveDolls()
{
	purObject->GiveDolls();
}
void Proxy::GiveFlowers()
{
	purObject->GiveFlowers();
}
void Proxy::GiveChocolate()
{
	purObject->GiveChocolate();
}
int main()
{
	SchoolGirl *jiaojiao = new SchoolGirl;
	jiaojiao->setName("李嬌嬌");

	Proxy *daili = new Proxy(jiaojiao);

	daili->GiveDolls();
	daili->GiveFlowers();
	daili->GiveChocolate();

	delete jiaojiao;
	jiaojiao = nullptr;
	delete daili;
	daili = nullptr;

	system("pause");
	return 0;
}
