//
// Created by liam on 11/26/18.
//
// Completed by Thy Le 12/6/2018
//

#include "Song.h"

Song::Song(std::string artistIn, std::string titleIn, float durationIn){
    this->artist = artistIn;
    this->title = titleIn;
    this->duration = durationIn;
    this->playCount = 0;
    this->nextSong = nullptr;
}

std::string Song::getArtist(){
    return this->artist;
}

std::string Song::getTitle(){
    return this->title;
}

float Song::getDuration(){
    return this->duration;
}

int Song::getPlayCount(){
    return this->playCount;
}

void Song::addPlayCount(){
    this->playCount++;
}