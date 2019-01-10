//
// Created by liam on 11/26/18.
//
// Completed by Thy Le on 12/06/2018
//

#ifndef INC_220_FINAL_PROJECT_SONG_H
#define INC_220_FINAL_PROJECT_SONG_H

#include <string>

class Song{
private:
    std::string artist;
    std::string title;
    float duration;
    int playCount;
    Song* nextSong;


public:
    Song(std::string artistIn, std::string titleIn, float durationIn);
    /**
     * @return the string representation of the artist of a song
     */
    std::string getArtist();
    /*
     * @return the string representation of the title of a song
     */
    std::string getTitle();
    /**
     *
     * @return the duration of a song
     */
    float getDuration();
    /**
     *
     * @return the play count of a song
     */
    int getPlayCount();
    /**
     * Increments the playCount of a song
     */
    void addPlayCount();

};

#endif //INC_220_FINAL_PROJECT_SONG_H
