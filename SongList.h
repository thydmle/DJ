//
// Created by Thy Le on 11/27/18.
//

#ifndef INC_220_FINAL_PROJECT_SONGLIST_H
#define INC_220_FINAL_PROJECT_SONGLIST_H

#include <cstdlib>
#include "ArrayList.h"
#include "Song.h"

class SongList{
private:
    List<Song>* songList;

public:
    SongList();
    SongList(const SongList& listToCopy);
    SongList& operator=(const SongList& listToCopy);
    ~SongList();

    /**
     *
     * @return a string representation of all songs within a library
     * if the list is empty, returns "{}"
     */
    std::string getAllItems();
    /**
     * adds a new song to the library
     * @param inItem - a song object
     */
    void addNewItem(Song& inItem);
    /**
     * removes the song with the given name
     * @param itemName - string representation of a song name
     */
    void removeItem(std::string itemName);
    /**
     * checks to see if the library is empty
     * @return true if library is empty
     */
    bool isEmpty();
    /**
     * gets the song with a given name
     * @param itemName - name of song
     * @return a song object with the given name
     */
    Song* getItem(std::string itemName);
    /**
     * gets the song with an index in the library's array list
     * @param index - index of the song in the list
     * @return the song object at the given index
     */
    Song* getItem(int index);
    /**
     * finds the current amount of songs in the library
     * @return the amount of songs in the library
     */
    int getCurrItemCount();

};

#endif //INC_220_FINAL_PROJECT_SONGLIST_H
