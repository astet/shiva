//
// Created by avendel on 24.10.2018.
//

#pragma once

#include <shiva/ecs/system.hpp>

namespace shiva::systems {
    class move_system final : public shiva::ecs::logic_update_system<move_system> {
    public:
        move_system(shiva::entt::dispatcher &dispatcher,
                    shiva::entt::entity_registry &registry,
                    const float &fixed_delta_time);

        static std::unique_ptr<shiva::ecs::base_system> create(entt::dispatcher &dispatcher,
                                                               entt::entity_registry &registry,
                                                               const float &fixed_delta_time);

        void update() noexcept final;

        reflect_class(render_system)

        static constexpr auto reflected_functions() noexcept;

        static constexpr auto reflected_members() noexcept;
    private:
    };
}
