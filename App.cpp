#include "App.hpp"

void App::addShape(App::Shape* shape) {
    shapes.push_back(shape);
    return;
}

void App::addShapes(App::ShapePoints shapePoints) {
    short size = shapePoints.size();
    this->shapes.resize(size);
    for (int i = 0; i < size; i++)
        shapes.at(i) = shapePoints.at(i);
    return;
}

App::Shape* App::getShape(App::ID id) {
    App::Shape* shape = shapes.at(id);
    return shape;
}

void App::connect(App::Window* window) {
    this->window = window;
    return;
}

void App::disconnect() {
    this->window = nullptr;
    return;
}

void App::handleEvent(App::SfmlEvent e) {
    switch (e.type) {
    case SfmlEvent::Closed:
        window->close();
        break;
    }
    return;
}

void App::run() {
    for (auto i : shapes) i->connect(this->window);
    Window* w = this->window;

    while (w->isOpen()) {
        // check sfml events
        SfmlEvent e;
        while (w->pollEvent(e)) handleEvent(e);

        // if time came, update
        if (clock.getElapsedTime() < frameSpeed) continue;
        else clock.restart();
        for (auto i : shapes) i->updatePosition();

        // and render
        w->clear();
        for (auto i : shapes) w->draw(*i->get());
        w->display();
    }
    return;
}

App::~App() {
    for (int i = 0; i < shapes.size(); i++)
        delete shapes.at(i);
    return;
}
