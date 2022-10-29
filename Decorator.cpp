#include <iostream>

class Shawarma {
public:
    virtual void print()
    {
        std::cout << "Simple Shawarma" << std::endl;
    }
};

class Sauce : public Shawarma
{

    private:
    	Shawarma* shawarma;

    public:
        Sauce(Shawarma* s){
            shawarma = s;
        }
        void print(){
            shawarma -> print();
            std::cout << "with sauce" << std::endl;
        }
};

class Onion : public Shawarma
{

    private:
        Sauce* sauce;

    public:
        Onion(Sauce* s){
            sauce = s;
        }
        
        void print(){
            sauce -> print();
            std::cout << "with onion" << std::endl;
        }
};

int main()
{
    Shawarma* shawarma = new Shawarma();
    Sauce* sauce = new Sauce(shawarma);
    Onion* onion = new Onion(sauce);
    onion -> print();
    return 0;
}
