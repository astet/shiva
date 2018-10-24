//
// Created by avendel on 24.10.2018.
//

#include "move_system.hpp"

namespace shiva::systems {

    void move_system::update() noexcept {
        sf::Time delta_time = sf::seconds(static_cast<float>(fixed_delta_time_));

        auto update_transform = []([[maybe_unused]] auto entity, auto &&transform, auto &&drawable) {
            auto transform_ptr = std::static_pointer_cast<shiva::sfml::drawable_component_impl>(
                    drawable.drawable_)->transformable;
            if (transform_ptr != nullptr) {
                //! Angle
                if (transform_ptr->getScale() != sf::Vector2f(transform.scale_x, transform.scale_y)) {
                    transform_ptr->setScale(sf::Vector2f(transform.scale_x, transform.scale_y));
                    transform.width = transform.original_width * transform.scale_x;
                    transform.height = transform.original_height * transform.scale_y;
                }

                //! Rotation
                if (static_cast<unsigned int>(transform_ptr->getRotation()) !=
                    static_cast<unsigned int>(transform.angle)) {
                    transform_ptr->setRotation(transform.angle);
                    auto rect = transform_ptr->getTransform().transformRect(
                            sf::FloatRect(0.f, 0.f, transform.original_width,
                                          transform.original_height));
                    transform.width = rect.width;
                    transform.height = rect.height;
                    transform.x = rect.left;
                    transform.y = rect.top;
                } else {
                    //! Position
                    transform_ptr->setPosition(transform.x, transform.y);
                }
            }
        };

        entity_registry_.view<shiva::ecs::transform_2d, shiva::ecs::drawable>().each(update_transform);
    }
}