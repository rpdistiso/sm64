#pragma once
#include <span>
#include <ranges>
#include <concepts>
#include <memory>

template<std::unsigned_integral T = uint16_t>
class FrameBuffer {
private:
    static constexpr int SCREEN_WIDTH = 320;
    static constexpr int SCREEN_HEIGHT = 240;
    static constexpr int BUFFER_COUNT = 3;
    
    std::vector<T> buffers[BUFFER_COUNT];
    size_t currentBuffer = 0;

public:
    FrameBuffer() {
        for(auto& buffer : buffers) {
            buffer.resize(SCREEN_WIDTH * SCREEN_HEIGHT);
        }
    }

    constexpr auto swap() noexcept {
        currentBuffer = (currentBuffer + 1) % BUFFER_COUNT;
    }

    // Using std::span for better view semantics
    [[nodiscard]] std::span<T> getCurrentBuffer() noexcept {
        return std::span(buffers[currentBuffer]);
    }

    void clear(T value = 0) {
        std::ranges::fill(buffers[currentBuffer], value);
    }
};
