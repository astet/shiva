//
// Created by Arthur on 24.10.2018.
//

#pragma once

#include <functional>
#include <unordered_map>

#include "keyboard.hpp"

namespace shiva::input {
    template <typename TKey = std::string_view>
    class action_map {
    public:
        template<class T>
        void register_action(TKey name, void (T::*Func)(), T& obj)
        {
            action_bindings[key] = std::bind(Func, std::ref(obj));
        }

        void bind_action(TKey name, shiva::input::keyboard::TKey key)
        {
            key_bindings[name] = key;
        }

    private:
        std::unordered_map<TKey, shiva::input::keyboard::TKey> key_bindings;
        std::unordered_map<TKey, std::function<void()>> action_bindings;
    };
}
