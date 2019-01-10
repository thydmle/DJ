//
// Created by elvis on 11/27/2018.
//

#ifndef INC_220_FINAL_PROJECT_LIST_H
#define INC_220_FINAL_PROJECT_LIST_H

#include "iostream"


/**
 * A generic list class that holds collections of items
 */

template <class T>
class List {
private:

public:

    List(List& listToCopy);

    List() {}

    List& operator=(const List& listToCopy);


    //virtual destructor that will delete the child elements within the list
    virtual ~List(){}

    /*
     * @Task:  Goes through each node in the list and adds the name to a running string
     * @returns: a string list of names of the items contained
     * @if empty: nothing in list returns list is empty
     */
    virtual T* getItem(std::string itemToGet)=0;

    //Overloaded getItem, gets at an index
    virtual T * getItem(int index)=0;

    virtual std::string getAllItems()=0;

    /* @arguments: Takes the item node to be added to the list
     * @Task: Goes in and adds a new item to the list
     *        increments the counter
     */
    virtual void addNewItem(T& item)=0;

    /*
     *  @arguments: Takes the item  name of the node to be remove
     *  @task: Searches through the list until it finds the item to be removed and removes it
     *  @Throws: invalid argument if item isn't present in List (try catch)
    */
    virtual void removeItem(std::string itemName)=0;

    /*
     *  @task: checks the item count to see if it is > 0
     *  @return: True or False
    */
    virtual bool isEmpty()=0;

    /*
     *  @task: gets the current number of items in the list
     *  @return: int of the current number of items in the list
    */
    virtual int getCurrItemCount()=0;




};

#endif //INC_220_FINAL_PROJECT_LIST_H
