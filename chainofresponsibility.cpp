#include <iostream>

class Handler
{
    public:
        virtual bool handle(int request) = 0;
};

class DefaultHandler : public Handler
{
    public:
        bool handle(int request) {
            std::cout<<"prime\n";
            return false;
        }
};

class Division2 : public DefaultHandler
{
    public:
        bool handle(int request) {
            if (request % 2 == 0 && request != 2) {
                return true;
            } else {
                return DefaultHandler::handle(request);
            }
        }
};

class Division3 : public Division2
{

    public:
        bool handle(int request) {
            if (request % 3 == 0 && request != 3) {
                return true;
            } else {
                return Division2::handle(request);  
            }
        }
};


class Division5 : public Division3
{

    public:
        bool handle(int request) {
            if (request % 5 == 0 && request != 5) {
                return true;
            } else {
                return Division3::handle(request);  
            }
        }
};


class Division7 : public Division5
{

    public:
        bool handle(int request) {
            if (request % 7 == 0 && request != 7) {
                return true;
            } else {
                return Division5::handle(request);  
            }
        }
};

int main()
{
    Handler *q = new Division7();
    for (int i = 2; i < 100; ++i) {
        q -> handle(i);
    }
    delete q;
}
