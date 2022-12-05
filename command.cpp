#include <iostream>

class Command
{
    public:
        virtual void execute() = 0;
};

class Engine 
{
    public:
        void startEngine() {
            std::cout<<"Engine in on\n";
        }
        
        void stopEngine() {
            std::cout<<"Engine is off\n";
        }
};

class EngineStartCommand : public Command 
{
    public:
        EngineStartCommand(Engine *engineLocal) : engine(engineLocal){}
        void execute() {
            engine -> startEngine();
        }
    private:
        Engine *engine;
};

class EngineStopCommand : public Command 
{
    public:
        EngineStopCommand(Engine *engineLocal) : engine(engineLocal){}
        void execute() {
            engine -> stopEngine();
        }
    private:
        Engine *engine;
};


class Control 
{
    public:
        void setCommand(Command* cmd) {
            command = cmd;
        }
        
        void StartStop() {
            command -> execute();
        }
    private:
        Command *command;
};

int main()
{
    Engine *engine = new Engine;
    EngineStartCommand *startEngine = new StartEngineCommand(engine);
    EngineStopCommand *stopEngine = new StopEngineCommand(engine);
    Control *control = new Control;
    control -> setCommand(startEngine);
    control -> StartStop();

    delete engine;
    delete startEngine;
    delete stopEngine;
    delete control;
    return 0;
}
