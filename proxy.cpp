#include <iostream>

class IMath 
{
    public:
        virtual void sum() = 0;
};

class RealMath : public IMath
{
    public:
        void sum() {
            std::cout<<"sum of 2 numbers\n";
        }
};

class Proxy : public IMath
{
    private:
        IMath *realMath;

    public:
        Proxy() : realMath(new RealMath()) {}
        ~Proxy() {
            delete realMath;
        }
        
        void sum() {
            this->realMath->sum();
        }
};

int main()
{
    Proxy *proxy = new Proxy;
    proxy->sum();
    delete proxy;
    return 0;
}
