#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "Channel.h"
#include "MediaPlayer.h"

using namespace std;

class View {
  public:
    View();

    void menu(vector<string>&, int& choice);
    void printAllChannels(const Array<Channel*>& channels);
    void channelMenu(const Array<Channel*>& channels, int& choice);
    void printChannel(const Channel*);
    void promptOwner(string& owner);
    void promptCategory(string& category);
    void printPlaylist(Array<Media*>&);
    void playPlaylist(Array<Media*>&);
    void promptVideo();
    void toggleVideo(bool);

  private:
    MediaPlayer* player;
    AudioPlayer audioPlayer;
    VideoPlayer videoPlayer;
};

#endif
