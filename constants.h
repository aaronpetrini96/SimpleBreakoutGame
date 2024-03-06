#ifndef constants_h
#define constants_h

struct constants {
    static constexpr int window_width{500};
    static constexpr int window_height{400};
    static constexpr float ball_speed{5.0f};
    static constexpr float paddle_width{60.0f};
    static constexpr float paddle_height{20.0f};
    static constexpr float paddle_speed{8.0f};
    static constexpr float brick_width{43.0f};
    static constexpr float brick_height{20.0f};
    static constexpr float brick_offset{brick_width/2.f};
    static constexpr int brick_strength{3}; //how many times it can be hit
    static constexpr int brick_colums{10};
    static constexpr int brick_rows{4};
    static constexpr int player_lives{3};
};

#endif /* constants_h */
