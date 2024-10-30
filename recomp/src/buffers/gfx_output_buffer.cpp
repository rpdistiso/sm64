#include "gfx_output_buffer.hpp"

namespace graphics {
    alignas(0x1000) std::array<uint64_t, GFX_OUTPUT_BUFFER_SIZE> gGfxSPTaskOutputBuffer{};
}
