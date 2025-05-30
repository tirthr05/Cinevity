#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>

using namespace std;

class Media {
  public:
    Media(const string& channelTitle, const string& owner, const string& mediaTitle,
          const string& category, const string& audioContent, const string& videoFile);

    const string& getChannelTitle() const;
    const string& getOwner() const;
    const string& getMediaTitle() const;
    const string& getCategory() const;
    const string& getAudioContent() const;
    const string& getVideoFile() const;

    void print(ostream& ost) const;

    friend ostream& operator<<(ostream& ost, const Media& m);

  private:
    string channelTitle;
    string owner;
    string mediaTitle;
    string category;
    string audioContent;
    string videoFile;
};

#endif
