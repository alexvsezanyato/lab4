#pragma once
#include "Reflection.hpp"
#include <SFML/Graphics.hpp>
// #include <SFML/Graphics/Color>
// #include <SFML/Window/RenderWindow>
#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

class Point {
public:
    using Vec2f = sf::Vector2f;
    using Vec2u = sf::Vector2u;
    using Time = sf::Time;
    using Clock = sf::Clock;
    // using Window = sf::Window;
    using Window = sf::RenderWindow;
    using PointCount = unsigned short;
    using Position = std::vector<Vec2f>;
    using Color = sf::Color;
    using Speed = float;
    using Scale = short;
    using Rectangle = sf::RectangleShape;
    using Circle = sf::CircleShape;
    using DrawableShape = sf::Shape;

    enum MoveType {
        Straight,
        Rotate,
    };

    struct PointSets {
        Vec2f position;
        MoveType moveType;
        Color color = Color::White;
    };

    struct Sets : PointSets {
        PointCount pointCount = 0;
        Position position;
        Color color = Color::White;
        MoveType moveType;
        Speed speed = 1; // per update
        Scale scale = 0; // in degrees
    };

private:
    Sets sets;
    void reflectFrom(WindowSide);
    void setScale(Scale); // deg
    void updateSets(Sets);
    void handleSets(PointSets);

protected:
    Window* window = nullptr;
    DrawableShape* drawableShape = nullptr;
    bool setPointCount(PointCount);
    void setPosition(Position);
    bool reflect();

public:
    void connect(Window*);
    void disconnect();
    Window* getConnection();
    DrawableShape* get();
    virtual void setDrawableShape();
    void dropDrawableShape();
    void setMoveType(MoveType);
    void setColor(Color);
    Color getColor(void);
    short getScale(); // deg
    Position getPosition(void);
    void updatePosition();
    virtual bool isOver();
    Point(Window*, PointSets);
    Point(PointSets);
    ~Point();
};
