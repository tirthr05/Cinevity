#include "MediaPlayer.h"

// AudioPlayer implementation
void AudioPlayer::play(ostream& ost, const Media& media) const {
  ost << media.getAudioContent() << endl;
}

// VideoPlayer implementation
void VideoPlayer::play(ostream& ost, const Media& media) const {
  // Play audio first (from AudioPlayer)
  AudioPlayer::play(ost, media);

  // Now open and play video file (ASCII art)
  ifstream file(media.getVideoFile());
  if (!file) {
    ost << "[Unable to open video file: " << media.getVideoFile() << "]" << endl;
    return;
  }

  string line;
  while (getline(file, line)) {
    ost << line << endl;
  }

  file.close();
}
