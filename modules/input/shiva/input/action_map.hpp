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
        struct Func_t {
            virtual ~Func_t() = default;
        };

        template<typename ...A>
        struct Cb_t : public Func_t {
            using cb = std::function<void(A...)>;
            cb callback;
            Cb_t(cb p_callback) : callback(p_callback) {}
        };
    public:
        template<typename... Args>
        void register_action(TKey name, void (*fp)(Args...))
        {
            using func = Cb_t<Args...>;
            std::unique_ptr<func> f1(new func(fp));
            action_bindings.emplace(name, std::move(f1));
        }

        template<typename T, typename... Args>
        void register_action(TKey name, void (T::*fp)(Args...))
        {
            using func = Cb_t<Args...>;
            std::unique_ptr<func> f1(new func(fp));
            action_bindings.emplace(name, std::move(f1));
        }

        void bind_action(TKey name, keyboard::Key key)
        {
            key_bindings[key] = name;
        }

        template<typename ...A>
        void call(TKey name, A&& ... args)
        {
            using func_t = Cb_t<A...>;
            using cb_t = std::function<void(A...)>;
            if (auto it = action_bindings.find(name); it != action_bindings.end()) {
                const Func_t &base = *it->second;
                const cb_t &fun = static_cast<const func_t &>(base).callback;
                fun(std::forward<A>(args)...);
            }
        }

        template<typename ...A>
        inline void call(keyboard::Key key, A&& ... args)
        {
            if (auto it = key_bindings.find(key); it != key_bindings.end()) {
                call(it->second, std::forward<A>(args)...);
            }
        }
    private:
        std::unordered_map<keyboard::Key, TKey> key_bindings;
        std::unordered_map<TKey, std::unique_ptr<Func_t>> action_bindings;
    };
}
