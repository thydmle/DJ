//
// Created by elvis on 11/27/2018.
//

#ifndef INC_220_FINAL_PROJECT_PLAYLIST_H
#define INC_220_FINAL_PROJECT_PLAYLIST_H
/**
* A class that holds a series of songs as a play list
*/
#include "ArrayList.h"
#include "Song.h"
#include "SongList.h"



class PlayList{

private:
    std::string name;
    List<Song>* playList;
    int itemCount;
    int genRandInt(int min, int max);

public:

    ~PlayList();
    PlayList(std::string newName);
    PlayList(PlayList& playListToCopy);
    PlayList& operator=(const PlayList& playListToCopy);
    std::string getAllItems();
    void addNewItem(Song* item);
    void removeItem(std::string itemName);
    bool isEmpty();
    void genRandPlayList(float duration, SongList* library);
    float getTotalDuration();
    std::string getTitle();
    int getCurrItemCount();
    Song* getItem(int index);
    Song* getItem(std::string itemName);
    void setTitle(std::string newName);
    Song* playNext();
};


#endif //INC_220_FINAL_PROJECT_PLAYLIST_H
