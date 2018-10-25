//
// Created by Arthur on 26.10.2018.
//

#pragma once

template <typename Event, typename EventId = Event>
class action_listener
{
public:
    action_listener();

    template<typename ...A>
    inline void emit(keyboard::Key key, A&& ... args)
    {
        if (auto it = key_bindings.find(key); it != key_bindings.end()) {
            call(it->second, std::forward<A>(args)...);
        }
    }

    template<typename... Args>
    void register_action(TKey name, void (*fp)(Args...))
    {
        using func = Cb_t<Args...>;
        std::unique_ptr<func> f1(new func(fp));
        if (shiva::ranges::find_if(key_bindings, [name](const auto& mo) {return mo.second == name; }) != key_bindings.end()) {
            action_bindings.emplace(name, std::move(f1));
        }
    }

    template<typename T, typename... Args>
    void register_action(TKey name, void (T::*fp)(Args...))
    {
        using func = Cb_t<Args...>;
        std::unique_ptr<func> f1(new func(fp));
        action_bindings.emplace(name, std::move(f1));
    }

private:
    // Container type
    typedef detail::ListenerMap<EventId, const Event&>	EventListenerMap;


    // ---------------------------------------------------------------------------------------------------------------------------
    // Private variables
private:
    EventListenerMap			mListeners;
};
