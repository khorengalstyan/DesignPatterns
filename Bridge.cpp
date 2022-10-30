#include <iostream>

class MakeSound {
    public:
        virtual void someSound() = 0;
};

class Sing : public MakeSound {
    public:
        void someSound() {
            std::cout << "Sing beautiful song\n";
        }
};

class Cry : public MakeSound {
    public:
        void someSound() {
            std::cout << "Cry out loud\n";
        }
};

class People {
    public:
        virtual void kindOfSound() = 0;
};

class Singer : public People {
    public:
        Singer(MakeSound* obj) : makeSound(obj){}
        void kindOfSound() {
            makeSound -> someSound();
        }

    private:
        MakeSound* makeSound;
};

class Child : public People {
   public:
        Child(MakeSound* obj) : makeSound(obj){}
        void kindOfSound() {
            makeSound -> someSound();
        } 
    
    private:
        MakeSound* makeSound;
};

int main() {
    MakeSound* sing = new Sing();
    MakeSound* cry = new Cry();
    People* PeopleA = new Singer(sing);
    People* PeopleB = new Child(cry);
    PeopleA -> kindOfSound();
    PeopleB -> kindOfSound();
    return 0;
}
