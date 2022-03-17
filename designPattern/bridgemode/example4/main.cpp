#include <iostream>
#include <cstdint>
#include <memory>

class CpuType {
    public: 
        virtual ~CpuType() = default;

    virtual uint64_t get_unique_id() = 0;
};

class CpuAm335x : public CpuType{
    public:
      uint64_t get_unique_id() override {
        return 0xabcd;
      }
};

class CpuImx6ull : public CpuType{
    public:
        uint64_t get_unique_id() override {
            return (((uint64_t) get_id()) << 32) | ((uint64_t) get_id());
        }

        uint32_t get_id() {
            return 0xaaaa1111;
        }
};

class NandDevice {
    public: 
        NandDevice(){};
        ~NandDevice(){};

        void write(unsigned char *buffer, int len){
            std::cout << "nand write "; 
            std::cout << "len " << len << std::endl; 
                printf("%x " ,buffer[0]); 
                printf("%x " ,buffer[1]); 
                printf("%x " ,buffer[19]); 
        }
    protected:
};

class CryptoProcess {
    public: 
        CryptoProcess(const std::shared_ptr<CpuType> platform_cpu_) : platform_cpu_(platform_cpu_) {}

        void generate_sha1_hash_key() {
            //auto hashkey = std::make_shared<unsigned char>(20);
            sha1_hash_key[0] = 0xa6;
            sha1_hash_key[1] = 0xb1;
            sha1_hash_key[19] = 0xc1;

            //....hash and return 20 byte hash key
            //std::cout << "generate_hash_key " << std::hex << platform_cpu->get_unique_id() << std::endl;
            std::cout << "generate_hash_key " << platform_cpu_->get_unique_id() << std::endl;
        }
        
        void write_hash_key(){
            nand_device_ = std::make_shared<NandDevice>();
            //std::shared_ptr<unsigned char> hashkey = std::make_shared<unsigned char>(20);
            generate_sha1_hash_key();
            nand_device_->write(sha1_hash_key, 10);

        }
    protected:
        std::shared_ptr<CpuType> platform_cpu_;
        std::shared_ptr<NandDevice> nand_device_;
        unsigned char sha1_hash_key[20]; 
};

int main() {
    std::shared_ptr<CpuType> imx6ull_cpu_ = std::make_shared<CpuImx6ull>();
    std::shared_ptr<CryptoProcess> crypto_proider_ = std::make_shared<CryptoProcess>(imx6ull_cpu_);
    crypto_proider_->write_hash_key();
}
