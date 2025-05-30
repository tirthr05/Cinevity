#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <iostream>
#include <fstream>
#include "Media.h"

using namespace std;

class MediaPlayer {
  public:
    virtual ~MediaPlayer() {}

    virtual void play(ostream& ost, const Media& media) const = 0;

    friend MediaPlayer& operator<<(MediaPlayer& player, const Media& media) {
      player.play(cout, media);
      return player;
    }
};

class AudioPlayer : public MediaPlayer {
  public:
    void play(ostream& ost, const Media& media) const override;
};

class VideoPlayer : public AudioPlayer {
  public:
    void play(ostream& ost, const Media& media) const override;
};

#endif
