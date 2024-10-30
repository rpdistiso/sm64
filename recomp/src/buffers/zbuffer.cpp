#include "zbuffer.hpp"

namespace graphics {
    alignas(8) std::array<uint16_t, SCREEN_WIDTH * SCREEN_HEIGHT> gZBuffer{};
}
