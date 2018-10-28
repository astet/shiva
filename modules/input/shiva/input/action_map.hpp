//
// Created by Arthur on 24.10.2018.
//

#pragma once

#include <functional>
#include <unordered_map>

#include <shiva/range/range.hpp>

#include "keyboard.hpp"
#include "dispatcher.hpp"

namespace shiva::input {
        
    template <typename ActionId = std::string_view>
    class action_map {
    public:
        using Dispatcher = dispatcher<ActionId>;

        void bind_action(ActionId name, keyboard::Key key)
        {
            key_bindings_[key] = name;
        }

        template<typename ...A>
        inline void emit(keyboard::Key key, A&& ... args)
        {
            if (auto it = key_bindings.find(key); it != key_bindings.end()) {
                call(it->second, std::forward<A>(args)...);
            }
        }

    private:
        std::unordered_map<keyboard::Key, ActionId> key_bindings_;
    };
}
