// https://blog.csdn.net/leonardohaig/article/details/106594702
#include <iostream>
#include <memory>

class AbstractServer{
    public:
        virtual void Request() = 0;
        virtual ~AbstractServer() = default;
};

class RealServer : public AbstractServer{
    void Request() override{
        std::cout << "server start" << std::endl;
    }
};

class ProxyServer : public AbstractServer{
    public:
        ProxyServer(const std::string &name, const std::string &pwd)
            : m_name(name), m_pwd(pwd) {
                m_pserver = std::make_shared<RealServer>();
            }

        void Request() override {
            if(!CheckUser()){
                std::cout << "check [ user name]  and [ password ] error" << std::endl;
                return;
            }
            std::cout << "check [ user name ] and [ password ] successful" << std::endl;

            PreRequest(); 
            m_pserver->Request();
            PostRequest();
        }

    private:
        bool CheckUser() {
            if("admin" == m_name && "123456" == m_pwd) {
                return true;
            }
            return false;
        }
        void PreRequest() {
            std::cout << "enter proxy server" << std::endl;
        }

        void PostRequest() {
            std::cout << "proxy server access end" << std::endl;
        }

    private:
        std::shared_ptr<AbstractServer> m_pserver;
        std::string m_name;
        std::string m_pwd;
};


int main(int argc, char *argv[]){
    std::shared_ptr<AbstractServer> proxy = std::make_shared<ProxyServer>("admin","123456");
    proxy->Request();
    return 0;
}

