#include "Media.h"

// Constructor
Media::Media(const string& ch, const string& o, const string& m,
             const string& c, const string& a, const string& v)
  : channelTitle(ch), owner(o), mediaTitle(m),
    category(c), audioContent(a), videoFile(v) {}

// Getters
const string& Media::getChannelTitle() const {
  return channelTitle;
}

const string& Media::getOwner() const {
  return owner;
}

const string& Media::getMediaTitle() const {
  return mediaTitle;
}

const string& Media::getCategory() const {
  return category;
}

const string& Media::getAudioContent() const {
  return audioContent;
}

const string& Media::getVideoFile() const {
  return videoFile;
}

// Print
void Media::print(ostream& ost) const {
  ost << "Channel: " << channelTitle
      << " | Owner: " << owner
      << " | Category: " << category
      << " | Title: " << mediaTitle;
}

// << operator
ostream& operator<<(ostream& ost, const Media& m) {
  m.print(ost);
  return ost;
}
