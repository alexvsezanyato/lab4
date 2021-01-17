#pragma once
#include "Point.hpp"
#include <vector>

class App {
public:
    using Time = sf::Time;
    using Clock = sf::Clock;
    // using Window = sf::Window;
    using Window = sf::RenderWindow;
    using ID = unsigned short;
    using Shape = Point;
    using ShapePoints = std::vector<Shape*>;
    using SfmlEvent = sf::Event;

private:
    ShapePoints shapes;
    Window* window;
    Clock clock;
    Time frameSpeed = sf::microseconds(100000);

public:
    void addShape(Shape*);
    void removeShape(ID);
    void dropAllShapes();
    Shape* getShape(ID);
    void addShapes(ShapePoints);
    void connect(Window*);
    void disconnect();
    void handleEvent(SfmlEvent);
    void run();
    ~App();
};
