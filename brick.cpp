#include "brick.h"

sf::Texture brick::texture;

const sf::Color brick_colour_hit1{0, 255, 0, 80}; //dull green
const sf::Color brick_colour_hit2{0, 255, 0, 170}; //Medium green
const sf::Color brick_colour_hit3{0, 255, 0, 255}; //Bright green

void brick::set_strength(int s) noexcept
{
    strength = s;
}
void brick::weaken() noexcept{
    --strength;
}
bool brick::is_too_weak() const noexcept
{
    return strength<=0;
}

brick::brick(float x, float y): entity()
{
    texture.loadFromFile("brick01.png");
    sprite.setTexture(texture);
    
    sprite.setPosition(x, y);
    
    sprite.setOrigin(get_centre());
}



void brick::update()
{
    if(strength==1)
        sprite.setColor(brick_colour_hit1);
    else if (strength==2)
        sprite.setColor(brick_colour_hit2);
    else if (strength==3)
        sprite.setColor(brick_colour_hit3);
}

void brick::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
