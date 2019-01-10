//
// Created by Thy Le on 12/6/18.
//
// Writing in progress: Liam 12/06/2018
// Updated Thy Le 12/12/2018

#include "ArrayList.h"
#include "Song.h"


//Destructor
template <class T>
ArrayList<T>::~ArrayList(){
    //Only delete the array, memory addresses to songs/playlists not touched
    delete[] this->array;
}

//Constructor
template <class T>
ArrayList<T>::ArrayList() {
    //Set data members
    this->currItemCount = 0;
    this->currCapacity = 100;
    //Create array
    this->array = new T*[100];
}

template<class T>
ArrayList<T>::ArrayList( List<T>* listToCopy){
    //Copy data members from input arrayList
    this->currItemCount = listToCopy->getCurrItemCount();
    this->currCapacity = (listToCopy->getCurrItemCount()) + 10;
    this->array = new T*[this->currCapacity];
    //Copy all items from input arrayList
    for (int i = 0; i < this->currItemCount; ++i) {
        //Memory addresses of objects copied
        this->array[i] = listToCopy->getItem(i);
    }
}

//Copy Constructor
template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& arrayListToCopy) {
    //Copy data members from input arrayList
    this->currItemCount = arrayListToCopy.currItemCount;
    this->currCapacity = arrayListToCopy.currCapacity;
    this->array = new T*[this->currCapacity];
    //Copy all items from input arrayList
    for (int i = 0; i < this->currItemCount; ++i) {
        //Memory addresses of objects copied
        this->array[i] = arrayListToCopy.array[i];
    }
}

//Assignment Operator
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& arrayListToCopy) {
    //Copy data members from input arrayList
    this->currItemCount = arrayListToCopy.currItemCount;
    this->currCapacity = arrayListToCopy.currCapacity;
    this->array = new T*[this->currCapacity];
    //Copy all items from input arrayList
    for (int i = 0; i < this->currItemCount; ++i) {
        //Memory addresses of objects copied
        this->array[i] = arrayListToCopy.array[i];
    }

    return *this;
}

//Get All Items
template <class T>
std::string ArrayList<T>::getAllItems() {
    //String of item names to return
    std::string toReturn = "{";
    if (this->currItemCount > 1) {
        for (int i = 0; i < this->currItemCount - 1; ++i) {
            toReturn += this->array[i]->getTitle();
            toReturn += ", ";
        }
    }
    if (this->currItemCount > 0) {
        toReturn += this->array[this->currItemCount - 1]->getTitle();
    }
    toReturn += "}";
    return toReturn;
}

//Add New Items
template  <class T>
void ArrayList<T>::addNewItem(T &inItem) {
    //Throw new item at the end, unless full, then doubleCapacity
    if (this->currItemCount == this->currCapacity){
        doubleCapacity();
    }
    T* toAdd = &inItem;

    this->array[this->currItemCount] = toAdd;
    this->currItemCount++;
}

//Remove Item
template <class T>
void ArrayList<T>::removeItem(std::string itemName) {
    //Throw invalidArgument if item does not exist in the array
    //Removes the first item found - assuming no duplicates
    //Get index of item to remove
    int iToRemove = -1;
    bool notFound = true;
    int currIndex = 0;
    while (notFound == true and currIndex < this->currItemCount){
        if (this->array[currIndex]->getTitle() == itemName){
            iToRemove = currIndex;
            notFound = false;
        }
        currIndex++;
    }
    if (notFound == true){
        throw std::invalid_argument("Item not found");
    }
    //Item was found, remove and shift array
    for (int i = iToRemove; i < this->currItemCount - iToRemove; ++i) {
        //Start at removed index and shift whole array
        this->array[i] = this->array[i + 1];
    }
    this->currItemCount--;
}

//Is Empty
template <class T>
bool ArrayList<T>::isEmpty() {
    if (this->currItemCount < 1){
        return true;
    }
    return false;
}

//Get item - search
template <class T>
T* ArrayList<T>::getItem(std::string itemName) {
    //If the list is empty, throw an exception
    if (this->currItemCount < 1){
        throw std::invalid_argument("List is empty");
    }
    //Iterate through (Linear search)
    int iFound = -1;
    bool notFound = true;
    int currIndex = 0;
    while (notFound == true and currIndex < this->currItemCount){
        if (this->array[currIndex]->getTitle() == itemName){
            iFound = currIndex;
            notFound = false;
        }
        currIndex++;
    }
    if (notFound == true){
        throw std::invalid_argument("Item not found");
    }
    return this->array[iFound];
}

//Get item at index
template <class T>
T* ArrayList<T>::getItem(int index){
    if (index < 0 or index > this->currItemCount - 1){
        throw std::invalid_argument("Given index is out of range");
    }
    return this->array[index];
}

//Get Current Item Count
template <class T>
int ArrayList<T>::getCurrItemCount() {
    return this->currItemCount;
}



//Double Capacity - internal function
template  <class T>
void ArrayList<T>::doubleCapacity() {
    //Create new array with larger capacity
    T** newArray = new T*[this->currCapacity * 2];
    for (int i = 0; i < this->currItemCount; ++i) {
        newArray[i] = this->array[i];
    }
    this->currCapacity = this->currCapacity * 2;
    delete this->array;
    this->array = newArray;
    newArray = nullptr;
}