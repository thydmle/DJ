//
// Created by Thy Le on 12/6/18.
//
// Writing in progress: Liam 12/06/2018
//Updated Thy Le 12/12/2018

#ifndef INC_220_FINAL_PROJECT_ARRAYLIST_H
#define INC_220_FINAL_PROJECT_ARRAYLIST_H

#include "List.h"
#include <string>


template <class T>
class ArrayList : public List<T> {
private:
    T** array;
    int currItemCount;
    int currCapacity;
    void doubleCapacity();

public:

    //Destructor
    ~ArrayList();
    //Constructor
    ArrayList();
    ArrayList( List<T>* listToCopy);
    //Copy Constructor
    ArrayList(const ArrayList<T>& arrayListToCopy);
    //Assignment Operator
    ArrayList& operator=(const ArrayList<T>& arrayListToCopy);
    //getAllItems
    std::string getAllItems();
    //addNewItem
    void addNewItem(T &inItem);
    //removeItem
    void removeItem(std::string itemName);
    //isEmpty
    bool isEmpty();
    //getItem (string)
    T* getItem(std::string itemName);
    //GetItem - overloaded (get by index)
    T* getItem(int index);
    //getCurrItemCount
    int getCurrItemCount();


};

#include "ArrayList.inl"
#endif //INC_220_FINAL_PROJECT_ARRAYLIST_H

