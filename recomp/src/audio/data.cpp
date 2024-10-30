#include "data.hpp"
#include "effects.hpp"

namespace audio {

// Aligned buffers for optimal memory access
alignas(16) AudioBuffer gAudioBuffer{};
alignas(16) WaveBuffer gWaveBuffer{};

std::span<uint8_t> getAudioBuffer() noexcept {
    return std::span(gAudioBuffer);
}

std::span<int16_t> getWaveBuffer() noexcept {
    return std::span(gWaveBuffer);
}

void processAudioData(std::span<const uint8_t> input, std::span<int16_t> output) noexcept {
    // Optimized SIMD processing could be added here
}

} // namespace audio
