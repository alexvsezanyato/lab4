#include "App.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
    App app;
    sf::VideoMode videoMode = sf::VideoMode{800, 600};
    // sf::VideoMode::getDesktopMode();
    std::string title = "Mover";
    auto windowStyle = sf::Style::Close;
    using Window = Point::Window;
    Window* window = new Window(videoMode, title, windowStyle);
    using Color = sf::Color;

    //
    // Add your shapes here

    app.addShapes({
        new Point{Point::PointSets{
            .position = {3.f, 7.f},
            .moveType = Point::MoveType::Straight,
            .color = Color::White
        }},
        new Point{Point::PointSets{
            .position = {25.f, 25.f},
            .moveType = Point::MoveType::Straight,
            .color = Color::Green
        }}
    });

    app.connect(window);
    app.run();
    delete window;
    return 0;
}
