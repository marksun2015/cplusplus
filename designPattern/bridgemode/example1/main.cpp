//https://www.bullforyou.com/article/read-11619055.html  
//bridge mode
//現實獨立出來，抽象依賴現實  。
//以下範例，將各類App，各類手機獨立出，
//實現各種App以及各種手機，自由橋接  
#include <bits/stdc++.h>
#include <iostream>


//抽象App。interface
class App {
public:
    virtual ~App() = default;

    virtual void run() = 0;
};

//具体的App实现类
class GameApp : public App {
public:
    void run() override {
        std::cout << "GameApp Running" << std::endl;
    }
};

//實體 App Implement  
class TranslateApp : public App {
public:
    void run() override {
        std::cout << "TranslateApp Running" << std::endl;
    }
};

//抽象手機class。interface  
class MobilePhone {
public:
    virtual ~MobilePhone() = default;

    //constructor 
    MobilePhone(const std::shared_ptr<App> pApp) : m_pApp(pApp) {}

    virtual void appRun() = 0;

protected:
    std::shared_ptr<App> m_pApp;
};

//mobile implement 
class XiaoMi : public MobilePhone {
public:
    XiaoMi(const std::shared_ptr<App> pApp) : MobilePhone(pApp) {}

    void appRun() override {
        std::cout << "XiaoMi: ";
        m_pApp->run();
    }
};

//mobile implement 
class HuaWei : public MobilePhone {
public:
    HuaWei(const std::shared_ptr<App> pApp) : MobilePhone(pApp) {}

    void appRun() override {
        std::cout << "HuaWei: ";
        m_pApp->run();
    }
};

int main() {
    std::shared_ptr<App> pGameApp = std::make_shared<GameApp>();
    std::shared_ptr<MobilePhone> pXiaoMi = std::make_shared<XiaoMi>(pGameApp);
    pXiaoMi->appRun();

    std::shared_ptr<App> pTranslateApp = std::make_shared<TranslateApp>();
    pXiaoMi = std::make_shared<XiaoMi>(pTranslateApp);
    pXiaoMi->appRun();

    std::cout << std::string(50, '-') << std::endl;

    std::shared_ptr<MobilePhone> pHuaWei = std::make_shared<HuaWei>(pGameApp);
    pHuaWei->appRun();

    pHuaWei = std::make_shared<HuaWei>(pTranslateApp);
    pHuaWei->appRun();

    return 0;
    //run 
    //XiaoMi: GameApp Running
    //XiaoMi: TranslateApp Running
    //--------------------------------------------------
    //HuaWei: GameApp Running
    //HuaWei: TranslateApp Running
}
