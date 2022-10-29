#include <iostream>

class InputInterface {
    public:
        virtual void typeC() = 0;
};

class MobileInput : public InputInterface {
    public:
        void typeC() {
            std::cout << "Phone can be charged with only type C\n";
        }
};

class AdapterInterface {
    public:
        virtual void miniUSB() = 0;
};

class Adapter : public AdapterInterface {
    public:
        Adapter(InputInterface* myObj) {
            inputInterface = myObj;
        }

        void miniUSB() {
            inputInterface -> typeC();
        }

     private:
        InputInterface* inputInterface;

};

int main() {
    MobileInput* mobileInput = new MobileInput();
    AdapterInterface* adapter = new Adapter(mobileInput);
    adapter -> miniUSB();
    return 0;
}
