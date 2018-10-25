//
// Created by Arthur on 24.10.2018.
//

#pragma once

#include <functional>
#include <unordered_map>

#include <shiva/range/range.hpp>

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
            if (shiva::ranges::find_if(key_bindings_, [name](const auto& mo) {return mo.second == name; }) != key_bindings_.end()) {
                action_bindings_.emplace(name, std::move(f1));
            }
        }

        template<typename T, typename... Args>
        void register_action(TKey name, void (T::*fp)(Args...))
        {
            using func = Cb_t<Args...>;
            std::unique_ptr<func> f1(new func(fp));
            action_bindings_.emplace(name, std::move(f1));
        }

        void bind_action(TKey name, TKey group, keyboard::Key key)
        {
            key_bindings_[key] = name;
        }

        void bind_action(TKey name, keyboard::Key key)
        {
            key_bindings_[key] = name;
        }

        template<typename ...A>
        inline void call(keyboard::Key key, A&& ... args)
        {
            if (auto it = key_bindings_.find(key); it != key_bindings_.end()) {
                call(it->second, std::forward<A>(args)...);
            }
        }
    private:
        template<typename ...A>
        void call(TKey name, A&& ... args)
        {
            using func_t = Cb_t<A...>;
            using cb_t = std::function<void(A...)>;
            if (auto it = action_bindings_.find(name); it != action_bindings_.end()) {
                const Func_t &base = *it->second;
                const cb_t &fun = static_cast<const func_t &>(base).callback;
                fun(std::forward<A>(args)...);
            }
        }

        std::unordered_map<keyboard::Key, TKey> action_groups_;
        std::unordered_map<keyboard::Key, TKey> key_bindings_;
        std::unordered_map<TKey, std::unique_ptr<Func_t>> action_bindings_;
    };
}
