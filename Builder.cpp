#include <iostream>

class Goal{
    public:
        int size;
}

class Tribune{
    public:
        int capacity;
}

class Grass{
    public:
        std::string quality;
}

class Stadium{
    public:
        Goal* goals[2];
        Tribune* tribune;
        Grass *grass; 
        
        void info(){
            std::cout << goals[0] -> size;
            std::cout << tribune -> capacity;
            std::cout << grass -> quality;
        }
};

