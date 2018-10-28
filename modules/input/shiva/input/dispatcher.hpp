//
// Created by Arthur on 26.10.2018.
//

#pragma once

#include <functional>

namespace shiva::input {
    template <typename ActionId>
    class dispatcher
    {
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
        dispatcher();

        template<typename... Args>
        void register_action(ActionId name, void (*fp)(Args...))
        {
            using func = Cb_t<Args...>;
            std::unique_ptr<func> f1(new func(fp));
            auto it = shiva::ranges::find_if(key_bindings, [name](const auto& mo) {return mo.second == name; });
            if (it != key_bindings.end()) {
                action_bindings.emplace(name, std::move(f1));
            }
        }

        template<typename Func>
        void register_action(ActionId name, Func fn)
        {
            using func = Cb_t<Args...>;
            std::unique_ptr<func> f1(new func(fn));
            action_bindings.emplace(name, std::move(f1));
        }

        template<typename ...A>
        void call(ActionId name, A&& ... args)
        {
            using func_t = Cb_t<A...>;
            using cb_t = std::function<void(A...)>;
            if (auto it = action_bindings_.find(name); it != action_bindings_.end()) {
                const Func_t &base = *it->second;
                const cb_t &fun = static_cast<const func_t &>(base).callback;
                fun(std::forward<A>(args)...);
            }
        }

    private:
        std::unordered_map<ActionId, std::unique_ptr<Func_t>> action_bindings_;
    };
}
