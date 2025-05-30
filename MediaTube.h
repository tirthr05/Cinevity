#ifndef MEDIATUBE_H
#define MEDIATUBE_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Channel.h"
#include "Search.h"

using namespace std;

class MediaTube {
  public:
    void addChannel(Channel* channel);
    void addMedia(Media* media, const string& channelTitle);

    const Array<Channel*>& getChannels() const;

    Channel* getChannel(int index) const;
    Channel* getChannel(const string& title) const;

    void getMedia(const Search& search, Array<Media*>& result) const;

  private:
    Array<Channel*> channels;
};

#endif
