//
// Created by Arthur on 26.10.2018.
//

#pragma once

#include "keyboard.hpp"
#include "mouse.hpp"

class input_action {
    friend input_action operator|| (const input_action& lhs, const input_action& rhs);
    friend input_action operator&& (const input_action& lhs, const input_action& rhs);
    friend input_action operator! (const input_action& action);
public:
    enum Type
    {
        Hold,
        PressOnce,
        ReleaseOnce,
    };

    input_action() = default;

    explicit input_action(shiva::input::keyboard::TKey key, Type action = Hold);
    explicit input_action(shiva::input::mouse::Button mouseButton, Type action = Hold);
};

input_action::input_action(shiva::input::keyboard::TKey key, Type action) {

}

input_action::input_action(shiva::input::mouse::Button mouseButton, Type action) {

}

input_action operator|| (const input_action& lhs, const input_action& rhs)
{

}
input_action operator&& (const input_action& lhs, const input_action& rhs)
{

}
input_action operator! (const input_action& action)
{

}
