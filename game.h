#ifndef game_h
#define game_h

#include <memory>
#include <typeinfo>
#include <vector>
#include <map>

#include <SFML/Graphics.hpp>
#include <string>
#include <algorithm>
#include "constants.h"
#include "background.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"

using entity_vector = std::vector<std::unique_ptr<entity>>;
using entity_alias_vector = std::vector<entity*>;

class entity_manager
{
    entity_vector all_entities;
    
    std::map<size_t, entity_alias_vector> grouped_entities;
    
public:
    template <typename T, typename... Args>
    T& create(Args&&... args) {
        // Check that the type parameter is derived from the entity base class
        static_assert(std::is_base_of<entity, T>::value,
        R"("T" type parameter in create() must be derived from "entity")");

        // Create a unique_ptr to the entity
        // Forward the arguments to the entity's constructor
        auto ptr{std::make_unique<T>(std::forward<Args>(args)...)};

        // Make an alias pointer to the allocated memory
        // This will be stored in the entity_type_vector
        auto ptr_alias = ptr.get();

        // Get the hash code for the entity object's type
        auto hash = typeid(T).hash_code();

        // Insert the alias pointer into the map
        grouped_entities[hash].emplace_back(ptr_alias);

        // Insert the object's pointer into the entities vector
        all_entities.emplace_back(std::move(ptr));

        // Return the new object
        return *ptr_alias;
    }
    
    void refresh();
    void clear();
   
    
    
    template <typename T>
    auto& get_all()
    {
        return grouped_entities[typeid(T).hash_code()];
    }
    
    template <typename T, typename Func>
    void apply_all(const Func& func)
    {
        auto& entity_group{get_all<T>()};
        
        for (auto ptr: entity_group)
            func(*dynamic_cast<T*>(ptr));
    }
    
    // Function to update all the entities
    void update();

    // Function to make all the entities draw themselves
    void draw(sf::RenderWindow& window);
};


class game {
    
    enum class game_state {paused, running, game_over,player_wins};
  
    sf::RenderWindow game_window {{constants::window_width,constants::window_height},
        "Simple Breakout Game"};
    
   
    entity_manager manager;
    
    sf::Font arial;
    sf::Text text_state, text_lives;
    
    game_state state {game_state::game_over};
    
    int lives{constants::player_lives};
    
public:
    game();
    
    void reset();
    void run();
};

#endif /* game_h */
