#ifndef SOLOUD_SRC_AUDIOSOURCE_AY_SRC_CHIPPLAYER_H_
#define SOLOUD_SRC_AUDIOSOURCE_AY_SRC_CHIPPLAYER_H_

#include "sndchip.h"

namespace SoLoud {
class AyInstance;
}

class ChipPlayer {
 public:
  // play next song chunk to buffer
  unsigned play(float* dst, unsigned need_samples);

  // for internal use by ChipSong class
  void set_timings(
    unsigned system_clock_rate, unsigned chip_clock_rate, unsigned sample_rate);
  void set_volumes(SNDCHIP::CHIP_TYPE t, unsigned global_vol,
    const SNDCHIP_VOLTAB* vt, const SNDCHIP_PANTAB* pt);

  ChipPlayer(SoLoud::AyInstance* aInstance);
  ~ChipPlayer();

  // private:
  SoLoud::AyInstance* mInstance;
  SNDBUFFER buffer;
  SNDCHIP chip;
  SNDCHIP chip2;

  unsigned locate(unsigned tick);
  unsigned playtick;
  unsigned playpos;
  unsigned system_clock_rate;
  unsigned ticks_per_buffer;

  unsigned get_time(unsigned tick);
};

#endif  // SOLOUD_SRC_AUDIOSOURCE_AY_SRC_CHIPPLAYER_H_
