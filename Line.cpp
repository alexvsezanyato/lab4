class Line: Shape {
public:
    using Vec2 = sf::Vector2;
    using Vec2f = sf::Vector2f;
    using Positon = std::pair<Vec2f, Vec2f>;

private:
    Position position;

public:
    void setPos(Position);
    Position getPos();
    float getLength();
};

void Line::setPos(Position position) {
    this->position = position;
    return;
}

Position Line::getPos() {
    Positon position = this->position;
    return position;
}

float getLength() {
    Position pos = getPos();
    Vec2f a = pos.first;
    Vec2f b = pos.second;
    float length;
    float x = abs(b.x - a.x);
    float y = abs(b.y - a.y);
    length = sqrt(pow(2, x) + pow(2, y));
    return length;
}
