#ifndef ZBUFFER_HPP
#define ZBUFFER_HPP

#include <array>
#include <cstdint>
#include "config.hpp"
#include "macros.hpp"

namespace graphics {
    extern std::array<uint16_t, SCREEN_WIDTH * SCREEN_HEIGHT> gZBuffer;
    extern int32_t gZBufferEnd;
}

#endif // ZBUFFER_HPP
