//
// Created by Arthur on 20.10.2018.
//

#pragma once

namespace namespace shiva::plugins {
    template<typename T>
    class plugin {
    public:
        plugin(const plugin &) = delete;
        plugin& operator=(const plugin&) = delete;
    };
}
