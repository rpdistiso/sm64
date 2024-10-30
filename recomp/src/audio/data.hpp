#pragma once
#include <array>
#include <span>
#include <cstdint>
#include "internal.hpp"
#include "types.hpp"

namespace audio {

// Audio buffer types using std::array for compile-time bounds checking
using AudioBuffer = std::array<uint8_t, AUDIO_BUFFER_SIZE>;
using WaveBuffer = std::array<int16_t, WAVE_BUFFER_SIZE>;

// Modern span-based views for zero-overhead access
[[nodiscard]] std::span<uint8_t> getAudioBuffer() noexcept;
[[nodiscard]] std::span<int16_t> getWaveBuffer() noexcept;

// Efficient audio processing functions
void processAudioData(std::span<const uint8_t> input, std::span<int16_t> output) noexcept;

} // namespace audio
