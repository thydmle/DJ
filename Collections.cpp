#include "List.h"
#include "Collection.h"
#include "PlayList.h"

/**
 * A class that holds a series of playlists
 */




/*
 * @Constructor: Takes in the name of the playList
 *               assigns null to the front node
 */
Collection::Collection(){
    this->playListHolder = new ArrayList<PlayList>();
}

/*
 * @Destructor:  Goes through each node and deletes the node
*/

Collection::~Collection(){
    delete playListHolder;
}

/*
 * @Task:  Goes through each node in the list and adds the name to a running string
 * @returns: a string list of names of the items contained
 * @if empty: nothing in list returns list is empty
 */

std::string Collection::getAllItems(){
    std::string playlists;
    if(playListHolder,getCurrItemCount() > 0) {
        for (int i = 0; i < playListHolder->getCurrItemCount(); i++) {
            playlists = playlists + " " + playListHolder->getItem(i)->getTitle() + " " +
                        std::to_string(playListHolder->getItem(i)->getTotalDuration());
        }
    }
    else{
        playlists = "{}";
    }
    return playlists;
}

std::string Collection::getPlayListInfo(std::string name) {
    return this->playListHolder->getItem(name)->getTitle() + " "  + std::to_string(this -> playListHolder->getItem(name)->getTotalDuration());
}

/* @arguments: Takes the item node to be added to the list
* @Task: Goes in and adds a new item to the list
*        increments the counter
*/

void Collection::addNewItem(PlayList*  item){
    this->playListHolder->addNewItem((*item));
}


/*
*  @arguments: Takes the item  name of the node to be remove
*  @task: Searches through the list until it finds the item to be removed and removes it
*  @Throws: invalid argument if item isn't present in List
*/

void Collection::removeItem(std::string name){
    this->playListHolder->removeItem(name);
}



/*
*  @task: checks the item count to see if it is > 0
*  @return: True or False
*/

bool Collection::isEmpty(){
    return this->playListHolder->isEmpty();
};


/*
*  @task: gets the number of play lists within the collection
*  @return: int
*/

int Collection::getCurrItemCount(){
    return this->playListHolder -> getCurrItemCount();
}

/*
*  @task: gets the playlist specified by the index
*  @return: playlist
*/


PlayList* Collection::getItem(int index){
    return playListHolder->getItem(index);
}

/*
*  @task: gets the item specified by the name
*  @return: playlist
*/


PlayList* Collection::getItem(std::string name){
    return playListHolder->getItem(name);
}