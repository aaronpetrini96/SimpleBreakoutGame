#ifndef interactions_h
#define interactions_h

#include "ball.h"
#include "paddle.h"
#include "brick.h"

bool is_interacting(const entity& e1, const entity& e2);

void handle_collision(ball& b, const paddle& p);

void handle_collision(ball&b, brick& p);

#endif /* interactions_h */
