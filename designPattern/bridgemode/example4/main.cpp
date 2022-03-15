#include <iostream>
#include <cstdint>
#include <memory>

class PlatformCpu {
    public: 
        virtual ~PlatformCpu() = default;

    virtual uint64_t get_unique_id() = 0;
};

class AM335X_cpu : public PlatformCpu{
    public:
      uint64_t get_unique_id() override {
        return 0xabcd;
      }
};

class IMX6ULL_cpu : public PlatformCpu{
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

class CryptoProider {
    public: 
        CryptoProider(const std::shared_ptr<PlatformCpu> platform_cpu) : platform_cpu(platform_cpu) {}

        void generate_sha1_hash_key() {
            //auto hashkey = std::make_shared<unsigned char>(20);
            sha1_hash_key[0] = 0xa6;
            sha1_hash_key[1] = 0xb1;
            sha1_hash_key[19] = 0xc1;

            //....hash and return 20 byte hash key
            //std::cout << "generate_hash_key " << std::hex << platform_cpu->get_unique_id() << std::endl;
            std::cout << "generate_hash_key " << platform_cpu->get_unique_id() << std::endl;
        }
        
        void write_hash_key(){
            nand_device = std::make_shared<NandDevice>();
            //std::shared_ptr<unsigned char> hashkey = std::make_shared<unsigned char>(20);
            generate_sha1_hash_key();
            nand_device->write(sha1_hash_key, 10);

        }
    protected:
        std::shared_ptr<PlatformCpu> platform_cpu;
        std::shared_ptr<NandDevice> nand_device;
        unsigned char sha1_hash_key[20]; 
};

int main() {
    std::shared_ptr<PlatformCpu> imx6ull_cpu = std::make_shared<IMX6ULL_cpu>();
    std::shared_ptr<CryptoProider> crypto_proider = std::make_shared<CryptoProider>(imx6ull_cpu);
    crypto_proider->write_hash_key();
}
