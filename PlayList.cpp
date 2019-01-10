//
// Created by liam on 11/28/18.
//

#ifndef INC_220_FINAL_PROJECT_S_H
#define INC_220_FINAL_PROJECT_S_H

#include "PlayList.h"
#include "string"

//Generate random number - private function
// srand(time(NULL));  <-- put this in main
int PlayList::genRandInt(int min, int max){
    if(min > max){
        return (rand() % (min - max + 1) + max);
    }

    else{

        return (rand() % (max - min + 1) + min);
    }
}

//Destructor
PlayList::~PlayList() {
    //Delete the arrayList
    delete playList;
}

//Constructor
PlayList::PlayList(std::string newName) {
    //Set data and make an arrayList
    this->name = newName;
    this->playList = new ArrayList<Song>;
    this->itemCount = 0;
}

//Copy constructor
PlayList::PlayList(PlayList &playListToCopy) {
    //Copy new data
    this->name = playListToCopy.name;
    //Copy arrayList
    this->playList = new ArrayList<Song>(playListToCopy.playList);
}

//Assignment Operator
PlayList& PlayList::operator=(const PlayList &playListToCopy) {
    //Copy new data
    this->name = playListToCopy.name;
    //Copy arrayList
    this->playList = new ArrayList<Song>(playListToCopy.playList);
    return *this;

}

//Get all items, returns string of all songs
std::string PlayList::getAllItems() {
    return this->playList->getAllItems();
}


//Add new item
void PlayList::addNewItem(Song *item) {
    this->playList->addNewItem(*item);
}

//Remove item
void PlayList::removeItem(std::string itemName) {
    this->playList->removeItem(itemName);
}

//Is empty
bool PlayList::isEmpty() {
    if (playList->getCurrItemCount() < 1){
        return true;
    }
    return false;
}

//Generate random playlist
void PlayList::genRandPlayList(float duration, SongList* library) {
    //Pass a pointer to the main library on this function call
    //Delete anything currently in the playlist
    this->itemCount = 0;
    //Remove arraylist
    delete this->playList;
    this->playList = nullptr;
    this->playList = new ArrayList<Song>;
    float currDuration = 0;
    int tries = 0;
    Song* songToAdd;
    bool keepAdding = true;
    bool inList = false;

    while (keepAdding == true){
        //Pick a random song from library
        int randIndex = genRandInt(0, library->getCurrItemCount() - 1);
        //std::cout << randIndex << std::endl;
        songToAdd = library->getItem(genRandInt(0,(library->getCurrItemCount() - 1)));
        //std::cout << songToAdd->getTitle() << std::endl;
        //If adding will not put playlist over duration, add
        if ((this->getTotalDuration() + songToAdd->getDuration()) < duration){
            //Make sure song is not already in playlist
            inList = false;
            for (int i = 0; i < this->getCurrItemCount(); ++i) {
                if (this->playList->getItem(i)->getTitle() == songToAdd->getTitle()) {
                    tries++;
                    inList = true;
                }
            }
            //Add song to playlist
            if (inList == false){
                this->addNewItem(songToAdd);
            }
        }
        //Song would put list over time limit, try some other songs
        else{
            if (tries > 15){
                keepAdding = false;
            }
            tries++;
        }
    }
}

int PlayList::getCurrItemCount(){
    return this->playList->getCurrItemCount();
}


//Get total duration
float PlayList::getTotalDuration() {
    float toReturn = 0;
    for (int i = 0; i < playList->getCurrItemCount(); ++i) {
        toReturn += playList->getItem(i)->getDuration();
    }
    return toReturn;
}

//Get name
std::string PlayList::getTitle() {
    return this->name;
}

//Set name
void PlayList::setTitle(std::string newName) {
    this->name = newName;
}

//Get item by index
Song* PlayList::getItem(int index) {
    return this->playList->getItem(index);
}

//Get item by name
Song* PlayList::getItem(std::string itemName) {
    return this->playList->getItem(itemName);
}

//Playnext
//Returns a pointer to the next song to be played and removes it from the playlist
Song* PlayList::playNext() {
    Song* toRemove = this->playList->getItem(0);
    if (toRemove == nullptr){
        return nullptr;
    }

    else{
        this->playList->removeItem(toRemove->getTitle());
        return toRemove;
    }
}


#endif //INC_220_FINAL_PROJECT_S_H
