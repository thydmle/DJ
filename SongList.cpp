//
// Created by Thy Le on 11/27/18.
//
// Updated 12/12/2018

#include "SongList.h"

SongList::SongList(){
    this->songList = new ArrayList<Song>();
}


SongList::SongList(const SongList& listToCopy){
    ArrayList<Song> copyList = listToCopy.songList;
    this->songList = new ArrayList<Song>(copyList);

}


SongList& SongList::operator=(const SongList& listToCopy){
    delete songList;
    this->songList = listToCopy.songList;
    return *this;
}


SongList::~SongList(){
    delete songList;
}


std::string SongList::getAllItems(){
    return songList->getAllItems();
}


void SongList::addNewItem( Song& itemName){
    songList->addNewItem(itemName);

}

void SongList::removeItem(std::string itemName){
    songList->removeItem(itemName);
}



bool SongList::isEmpty(){
    return songList->isEmpty();
}



Song* SongList::getItem(std::string itemName) {
    return songList->getItem(itemName);
}

/**
 * Gets item at an index
 * @param index
 * @return song pointer
 */
Song* SongList::getItem(int index){
    return songList->getItem(index);
}

/**
 * Calls getCurrItemCount of the SongList arrayList
 * @return current item count in the song list
 */

int SongList::getCurrItemCount(){
    return songList->getCurrItemCount();
}
