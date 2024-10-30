#ifndef GFX_OUTPUT_BUFFER_HPP
#define GFX_OUTPUT_BUFFER_HPP

#include <cstdint>
#include <array>

namespace graphics {

#ifdef VERSION_EU
    // 0x17e00 bytes, aligned to 0x200-byte boundary
    static constexpr size_t GFX_OUTPUT_BUFFER_SIZE = 0x2fc0;
#else
    // 0x1f000 bytes, aligned to 0x1000-byte boundary
    static constexpr size_t GFX_OUTPUT_BUFFER_SIZE = 0x3e00;
#endif

// Aligned buffer declaration
extern alignas(0x1000) std::array<uint64_t, GFX_OUTPUT_BUFFER_SIZE> gGfxSPTaskOutputBuffer;

} // namespace graphics

#endif // GFX_OUTPUT_BUFFER_HPP
