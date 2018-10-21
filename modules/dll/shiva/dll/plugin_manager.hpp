//
// Created by Arthur on 20.10.2018.
//

#pragma once

#include <shiva/dll/plugins_registry.hpp>

namespace namespace shiva::plugins {
    class plugin_manager {

        /**
         * \note This function allow you to load the plugins of the plugins_registry and create systems
         * with the creator functions of each plugins.
         * \return true if all the plugins has been successfully loaded, false otherwise
         */
        bool load_plugins() noexcept;
        bool hot_reload_plugins() noexcept;
    };

    bool plugin_manager::load_plugins() noexcept
    {
        auto res = plugins_registry_.load_all_symbols();
        auto functor = [this](auto &&dlls) {
            system_ptr ptr = dlls.second.creator_function(this->dispatcher_, this->ett_registry_,
                                                          this->timestep_.get_fixed_delta_time());
            dlls.second.class_name = ptr->get_name();
            dlls.second.type = static_cast<unsigned int>(ptr->get_system_type_RTTI());
            add_system_(std::move(ptr), ptr->get_system_type_RTTI()).im_a_plugin();
        };

        plugins_registry_.apply_on_each_symbols(functor);
        dispatcher_.trigger<shiva::event::after_load_systems_plugins>();
        return res;
    }

    bool plugin_manager::hot_reload_plugins() noexcept
    {
        plugins_registry_.apply_on_each_symbols([this](auto &&dlls) {
            if (shiva::fs::last_write_time(dlls.first) != dlls.second.last_write_time) {
                this->log_->info("{} -> need hot reload", dlls.first);
                auto &&system_collection = systems_[static_cast<system_type>(dlls.second.type)];
                auto it = shiva::ranges::find_if(system_collection, [&dlls](auto &&sys) {
                    return sys->get_name() == dlls.second.class_name;
                });
                if (it != system_collection.end()) {
                    it->reset(nullptr);
                    *it = std::move(dlls.second.creator_function(this->dispatcher_, this->ett_registry_,
                                                                 this->timestep_.get_fixed_delta_time()));
                    this->dispatcher_.trigger<shiva::event::after_system_reload_plugins>((*it).get());
                }
                dlls.second.last_write_time = shiva::fs::last_write_time(dlls.first);
            }
        });
        return true;
    }
}
