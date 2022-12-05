#include <iostream>


class Shower {
    public:
        void showerOn() {
            std::cout << "Shower is on\n";
        } 
};


class Shampoo {
    public:
        void addShampoo() {
            std::cout << "Shampoo is added\n";
        }
};

class Bath {

    private:
        Shower shower;
        Shampoo shampoo;
    
    public:
        void takeBath() {
            shower.showerOn();
            shampoo.addShampoo();
        }
};

int main()
{
    Bath bath;
    bath.takeBath();
    return 0;
}
