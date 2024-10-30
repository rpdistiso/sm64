#ifndef FRAMEBUFFERS_HPP
#define FRAMEBUFFERS_HPP

#include <cstdint>
#include <array>
#include <span>

namespace graphics {

class FrameBuffers {
public:
    static constexpr size_t SCREEN_WIDTH = 320;
    static constexpr size_t SCREEN_HEIGHT = 240;
    static constexpr size_t BUFFER_COUNT = 3;
    static constexpr size_t BUFFER_SIZE = SCREEN_WIDTH * SCREEN_HEIGHT;

    using PixelType = uint16_t;
    using BufferArray = std::array<PixelType, BUFFER_SIZE>;
    using BufferSpan = std::span<PixelType, BUFFER_SIZE>;

private:
    // Guaranteed contiguous memory layout
    std::array<BufferArray, BUFFER_COUNT> buffers;

public:
    // Modern span-based access
    [[nodiscard]] constexpr BufferSpan getBuffer(size_t index) noexcept {
        return BufferSpan{buffers[index]};
    }

    // Direct buffer access for legacy code compatibility
    [[nodiscard]] constexpr PixelType* getBufferPtr(size_t index) noexcept {
        return buffers[index].data();
    }

    // Named accessors for clarity
    [[nodiscard]] static FrameBuffers& instance() noexcept {
        static FrameBuffers instance;
        return instance;
    }
};

// Compatibility defines for existing code
inline auto& gFramebuffer0 = FrameBuffers::instance().getBufferPtr(0);
inline auto& gFramebuffer1 = FrameBuffers::instance().getBufferPtr(1);
inline auto& gFramebuffer2 = FrameBuffers::instance().getBufferPtr(2);

} // namespace graphics

#endif // FRAMEBUFFERS_HPP
