#include <iostream>

enum Phones {
    PNokia,
    PIphone,
    PSamsung,
    PXiaomi
};

class Phone {
    public: 
        virtual void printType() = 0;
        static Phone* Create(Phones type);
        virtual ~Phone(){}; 
};

class Nokia : public Phone {
    public:
        void printType() {
            std::cout << "It's Nokia\n";
        }
};

class Iphone : public Phone {
    public:
        void printType() {
            std::cout << "It's Iphine\n";
        }
};

class Samsung : public Phone {
    public:
        void printType() {
            std::cout << "It's Samsung\n";
        }
};

class Xiaomi : public Phone {
    public:
        void printType() {
            std::cout << "It's Xiaomi\n";
        }
};
   
Phone* Phone::Create(Phones type) {
    switch(type) {
        case 0: {
            return new Nokia();
            break;
        }
        
        case 1: {
            return new Iphone();
            break;
        }
        
        case 2: {
            return new Samsung();
            break;
        }
        
        case 3: {
            return new Xiaomi();
            break;
        }
        
        default:{
            return nullptr;

        }
    }
}

class Client {
    public:
        Client() {
            Phones phone = PNokia;
            pPhone = Phone::Create(phone);
        }

        ~Client() {
            if (pPhone != nullptr) {
                delete pPhone;
                pPhone = nullptr;
            }
        }
        
        Phone* getPhone() {
            return pPhone;
        }
        
    private:
        Phone* pPhone;
};


int main() {
    Client* pClient = new Client();
    Phone* pPhone = pClient -> getPhone();
    pPhone -> printType();
    delete pClient;
    return 0;
}
