#include <iostream>

class Goal{
    public:
        double size;
};

class Tribune{
    public:
        int capacity;
};

class Grass{
    public:
        std::string quality;
};

class Stadium{
    public:
        Goal* goals[2];
        Tribune* tribune;
        Grass *grass; 
        
        void info(){
            std::cout << goals[0] -> size << "\n";
            std::cout << tribune -> capacity << "\n";
            std::cout << grass -> quality << "\n";
        }
};

class Builder{
    public:
        virtual Goal* getGoal() = 0;
        virtual Tribune* getTribune() = 0;
        virtual Grass* getGrass() = 0;
};

class Director{
    Builder* builder;
    public:
        void setBuilder(Builder* myBuilder){
            builder = myBuilder;
        }
        
        Stadium* getStadium(){
            Stadium* stadium = new Stadium();
            stadium -> goals[0] = builder -> getGoal();
            stadium -> goals[1] = builder -> getGoal();
            stadium -> tribune = builder -> getTribune();
            stadium -> grass = builder ->getGrass();

            return stadium;
        }
};

class OldTraffordBuilder : public Builder{
    public:
        Goal* getGoal(){
            Goal* goal = new Goal();
            goal -> size = 1.5;
            return goal;
        }
    
        Tribune* getTribune(){
            Tribune* tribune = new Tribune();
            tribune -> capacity = 74310;
            return tribune;
        }

        Grass* getGrass(){
            Grass* grass = new Grass();
            grass -> quality = "high";  
            return grass;
        }
};

int main()
{
    Stadium* stadium;
    Director director;
    OldTraffordBuilder oldTraffordBuilder;
    director.setBuilder(&oldTraffordBuilder);
    stadium = director.getStadium();
    stadium -> info();
    return 0;
}

