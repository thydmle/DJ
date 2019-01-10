//
// Created by elvis on 11/29/2018.
//

#ifndef INC_220_FINAL_PROJECT_COLLECTION_H
#define INC_220_FINAL_PROJECT_COLLECTION_H

#include "List.h"
#include "ArrayList.h"
#include "Collection.h"
#include "PlayList.h"

/**
 * A class that holds a series of playlists
 */



class Collection  {
private:

    List<PlayList>* playListHolder;

public:
    /*
     * @Constructor: initializes the list
     */

    Collection();

    /*
     * @Destructor:  Goes through and deletes the list
    */
    ~Collection();

    /*
     * @Task:  Goes through  the list and adds the name to running string for items
     * @returns: a string list of names of the items contained
     * @if empty: nothing in list returns list is empty
     */
    std::string getAllItems();

    /* @arguments: Takes the item to be added to the list
    * @Task: Goes in and adds a new item to the list
    *        increments the counter
    */
    void addNewItem(PlayList* item);


    /*
    *  @arguments: Takes the item name to be removed
    *  @task: Searches through the list until it finds the item to be removed and removes it
    *
    */
    void removeItem(std::string name);

    /*
    *  @task: checks the item count to see if it is > 0
    *  @return: True or False
   */
    bool isEmpty();

    /*
  *  @task: gets the number of playlists
  *  @return: int of number of playlists
 */
    int getNumOfPlayLists();

    /*
*  @task: gets the names and durations of the playlists
*  @return: string represntation of the playlists contained
*/
    std::string getPlayListInfo(std::string name);

    /*
*  @task: gets the current item count for the collections
*  @return: int count of number of items
*/
    int getCurrItemCount();

    /*
*  @task: gets a playlist item
*  @return: Playlist object item via index
*/
    PlayList*  getItem(int index);

    /*
*  @task: gets a playlist item
*  @return: Playlist object item via name
*/
    PlayList*  getItem(std::string name);







};

#endif //INC_220_FINAL_PROJECT_COLLECTION_H
