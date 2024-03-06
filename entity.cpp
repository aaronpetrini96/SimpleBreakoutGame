#include "entity.h"
sf::FloatRect entity::get_bounding_box() const noexcept
{
    return sprite.getGlobalBounds();
}

sf::Vector2f entity::get_centre() const noexcept
{
    auto box = get_bounding_box();
    return {box.width/2.0f, box.height/2.0f};
}


float entity::x() const noexcept
{
    return sprite.getPosition().x;
}

float entity::y() const noexcept
{
    return sprite.getPosition().y;
}

float entity::left() const noexcept
{
    auto box = get_bounding_box();
    return x()-box.width/2.f;
}

float entity::right() const noexcept
{
    auto box = get_bounding_box();
    return x()+box.width/2.f;
}

float entity::top() const noexcept
{
    auto box = get_bounding_box();
    return y()-box.width/2.f;
}

float entity::bottom() const noexcept
{
    auto box = get_bounding_box();
    return y()+box.width/2.f;
}

void entity::destroy() noexcept { destroyed = true; }
bool entity::is_destroyed() const noexcept { return destroyed; }

