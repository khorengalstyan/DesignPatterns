//Machine has only one engine
#include <iostream>

class EngineSingleton{
    public:
        static EngineSingleton *getObject(){
            if (object == nullptr) {
                object = new EngineSingleton();
            }
            return object;
        }
        
        double getPower(){
            return power;
        }
        
        void setPower(double myPower){
            power = myPower;
        } 
    private:
        static EngineSingleton* object;
        double power;
};

EngineSingleton *EngineSingleton::object = nullptr;

int main() {
        EngineSingleton *single = single -> getObject();
        std::cout<<single -> getPower()<<"\n";
        single -> setPower(2.5); 
        std::cout<<single -> getPower()<<"\n";
        //testing
        EngineSingleton *a = a -> getObject();
        std::cout<<a -> getPower()<<"\n";
        return 0;
}
