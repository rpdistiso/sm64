#ifndef BUFFERS_HPP
#define BUFFERS_HPP

#include <cstdint>
#include <array>
#include <span>
#include "game/save_file.hpp"
#include "game/game_init.hpp"
#include "config.hpp"

namespace memory {

// Main heaps
extern std::byte gDecompressionHeap[];
extern std::byte gAudioHeap[];

// Task buffers
extern std::byte gAudioSPTaskYieldBuffer[];
extern std::byte gGfxSPTaskYieldBuffer[];
extern std::byte gGfxSPTaskStack[];

// Thread stacks
extern std::byte gUnusedThread2Stack[];
extern std::byte gIdleThreadStack[];
extern std::byte gThread3Stack[];
extern std::byte gThread4Stack[];
extern std::byte gThread5Stack[];

#if ENABLE_RUMBLE
extern std::byte gThread6Stack[];
#endif

// Game state
extern SaveBuffer gSaveBuffer;
extern std::array<GfxPool, 2> gGfxPools;

// Modern span-based accessors for safe buffer access
[[nodiscard]] std::span<std::byte> getDecompressionHeap() noexcept;
[[nodiscard]] std::span<std::byte> getAudioHeap() noexcept;

} // namespace memory

#endif // BUFFERS_HPP
