#ifndef paddle_h
#define paddle_h


#include "entity.h"
#include "constants.h"

class paddle: public moving_entity
{
    static sf::Texture texture;
    
    void process_player_input();
    
public:
    
    paddle(float x, float y);
    
    void update() override;
    void draw(sf::RenderWindow& window) override;
    void move_up() noexcept override;
    void move_down() noexcept override;
    void move_right() noexcept override;
    void move_left() noexcept override;
};

#endif /* paddle_h */
