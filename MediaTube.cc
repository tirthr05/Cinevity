#include "MediaTube.h"
#include <cstdlib>

// (a) addChannel
void MediaTube::addChannel(Channel* channel) {
  channels += channel;
}

// (b) addMedia
void MediaTube::addMedia(Media* media, const string& channelTitle) {
  for (int i = 0; i < channels.getSize(); ++i) {
    if (channels[i]->equals(channelTitle)) {
      channels[i]->add(media);
      return;
    }
  }
  cerr << "Error: Channel \"" << channelTitle << "\" not found when adding media." << endl;
}

// (c) getChannels
const Array<Channel*>& MediaTube::getChannels() const {
  return channels;
}

// (d-1) getChannel by index
Channel* MediaTube::getChannel(int index) const {
  if (index < 0 || index >= channels.getSize()) {
    cerr << "Error: Channel index out of bounds." << endl;
    exit(1);
  }
  return channels[index];
}

// (d-2) getChannel by title
Channel* MediaTube::getChannel(const string& title) const {
  for (int i = 0; i < channels.getSize(); ++i) {
    if (channels[i]->equals(title)) {
      return channels[i];
    }
  }
  cerr << "Error: Channel \"" << title << "\" not found." << endl;
  exit(1);
}

// (e) getMedia using Search
void MediaTube::getMedia(const Search& search, Array<Media*>& result) const {
  for (int i = 0; i < channels.getSize(); ++i) {
    Channel* ch = channels[i];
    for (int j = 0; j < ch->getSize(); ++j) {
      Media* media = ch->get(j);
      if (search.matches(media)) {
        result += media;
      }
    }
  }
}
