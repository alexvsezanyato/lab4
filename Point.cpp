#include "Point.hpp"
using Sets = Point::Sets;

//
// Implementation

bool Point::setPointCount(Point::PointCount pointCount) {
    if (pointCount <= 0) return false;
    sets.position.resize(pointCount);
    sets.pointCount = pointCount;
    return false;
}

void Point::setPosition(Point::Position position) {
    sets.position = position;
    return;
}

void Point::setScale(Point::Scale scale) {
    sets.scale = scale;
    return;
}

bool Point::reflect() {
    return true;
}

//
// Interface

void Point::setMoveType(Point::MoveType moveType) {
    sets.moveType = moveType;
    return;
}

void Point::setColor(Point::Color color) {
    sets.color = color;
    return;
}

Point::Color Point::getColor() {
    Color color = sets.color;
    return color;
}

Point::Scale Point::getScale() {
    Scale scale = sets.scale;
    return scale;
}

Point::Position Point::getPosition(void) {
    Position position = sets.position;
    return position;
}

void Point::updatePosition() {
    // needs isOver and points
    // using MoveType = Point::MoveType;

    switch (sets.moveType) {
        case Point::Straight: {
            break;
        }
        case Point::Rotate: {
            break;
        }
    }
    return;
}

void Point::connect(Point::Window* window) {
    this->window = window;
    return;
}

void Point::disconnect() {
    this->window = nullptr;
    return;
}

Point::Window* Point::getConnection() {
    Point::Window* windowPoint = this->window;
    return windowPoint;
}

void Point::setDrawableShape() {
    if (drawableShape) dropDrawableShape();
    auto point = new sf::CircleShape(1);
    point->setPosition(sets.position.at(0));
    this->drawableShape = point;
    return;
}

void Point::dropDrawableShape() {
    if (!drawableShape) return;
    delete drawableShape;
    drawableShape = nullptr;
    return;
}

Point::DrawableShape* Point::get() {
    if (!drawableShape) setDrawableShape();
    return drawableShape;
}

//
// Virtual

bool Point::isOver() {
    // if () ..
    return false;
}

void Point::handleSets(Point::PointSets pointSets) {
    setPointCount(1);
    sets.position.at(0) = pointSets.position;
    return;
}

Point::Point(Point::PointSets sets) {
    this->handleSets(sets);
    return;
}

Point::Point(Point::Window* window, Point::PointSets sets) {
    this->window = window;
    this->handleSets(sets);
    return;
}

Point::~Point() {
    dropDrawableShape();
    return;
}
