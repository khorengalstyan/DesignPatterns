#include <functional>
#include <iostream>

class Shapes {
    public:
        virtual void print() = 0;
        virtual void add(Shapes* s) {};
        virtual void remove(Shapes* s) {};
        virtual ~Shapes() {};
};

class Rectangle : public Shapes {
    public:
        void print() {
            std::cout << "print Rectangle\n";
        }
};

class Circle : public Shapes {
    public:
        void print() {
            std::cout << "print Circle\n";
        }
};

class Line : public Shapes {
    public:
        void print() {
            std::cout << "print Line\n";
        }
};

class Slide : public Shapes {
    public:
        void print() { 
        
            for_each(List.begin(),List.end(),std::mem_fn(&Shapes::print));
        }
        
        void add(Shapes* shape) {
            List.push_back(shape);
        }
        
        void remove() {
            List.pop_back();
        }

        private:
            std::vector<Shapes*> List;
};

int main() {
    Line line;
    line.print();
    Rectangle rectangle;
    rectangle.print();
    Circle circle;
    circle.print();
    Slide slide;
    slide.add(&line);
    slide.add(&rectangle);
    slide.add(&circle);
    slide.print();
    return 0;
}
