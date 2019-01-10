// Created by Thy Le
// Latest Update: 12/16/2018



#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "SongList.h"
#include "ArrayList.h"
#include "TestLib.h"

void testSongListCopyConstructor(){
    std::cout << "------------ Testing Copy Constructor --------------" << std::endl;
    std::string artists[5] = {"Bach", "Brahms", "Dvorac", "Vivaldi", "Mendhelsson"};
    std::string title[5] = {"Opus 1", "Opus 2", "Opus 3", "Opus 4", "Opus 5"};
    float duration[5] = {3.5, 3.2, 3.1, 2.5, 3.7};

    //////Testing on a standard library
    SongList* testList = new SongList();
    for(int i=0; i<5; i++){
        testList->addNewItem(*(new Song(artists[i], title[i], duration[i])));
    }

    SongList* copyList = new SongList(*testList);
    for(int i=0;i<5;i++){
        std::cout << "Standard Library: ";
        printAssertEquals((copyList->getItem(i)->getArtist()), artists[i]);
    }
    //Testing on an empty library
    SongList* emptyList = new SongList();
    SongList* copyEmptyList = new SongList();
    copyEmptyList = emptyList;

    std::cout << "Empty Library: ";
    printAssertEquals(emptyList->isEmpty(), copyEmptyList->isEmpty());

    std::cout << "============= DONE =============" << std::endl;
    std::cout << "" << std::endl;
}

void testSongListGetAllItems(){
    std::cout << "---------- Testing Get All Items --------------" << std::endl;
    std::string artists[5] = {"Bach", "Brahms", "Dvorak", "Vivaldi", "Mendhelsson"};
    std::string title[5] = {"Opus 1", "Opus 2", "Opus 3", "Opus 4", "Opus 5"};
    float duration[5] = {3.5, 3.2, 3.1, 2.5, 3.7};

    //testing a standard library
    SongList* testList = new SongList();
    for(int i=0; i<5; i++){
        testList->addNewItem(*(new Song(artists[i], title[i], duration[i])));
    }

    std::string titlesTest = "{Opus 1, Opus 2, Opus 3, Opus 4, Opus 5}";
    std::string titlesFromSongList = testList->getAllItems();

    std::cout << "Standard Library: ";
    printAssertEquals(titlesTest, titlesFromSongList);

    //testing an empty library
    SongList* emptyList = new SongList();
    std::string resultForEmpty = "{}";
    std::cout << "Empty Library:";
    printAssertEquals(resultForEmpty, emptyList->getAllItems());
    std::cout << "============ DONE =============" << std::endl;
    std::cout << "" << std::endl;
}

void testSongListAddNewItem(){
    std::cout << "---------- Testing Add New Items --------------" << std::endl;
    std::string artists[5] = {"Bach", "Brahms", "Dvorak", "Vivaldi", "Mendhelsson"};
    std::string title[5] = {"Opus 1", "Opus 2", "Opus 3", "Opus 4", "Opus 5"};
    float duration[5] = {3.5, 3.2, 3.1, 2.5, 3.7};

    SongList* testList = new SongList();
    for(int i=0; i<5; i++){
        testList->addNewItem(*(new Song(artists[i], title[i], duration[i])));
    }


    for(int i=0;i<5;i++){
        std::cout << "Standard Library:" ;
        printAssertEquals( duration[i],(testList->getItem(title[i]))->getDuration());
    }

    std::cout << "============= DONE =============" << std::endl;
    std::cout << " " <<std::endl;

}

void testSongListRemoveItem(){
    std::cout << "-------------- Testing Remove Item ------------" << std::endl;

    std::string artists[5] = {"Bach", "Brahms", "Dvorak", "Vivaldi", "Mendhelsson"};
    std::string title[5] = {"Opus 1", "Opus 2", "Opus 3", "Opus 4", "Opus 5"};
    float duration[5] = {3.5, 3.2, 3.1, 2.5, 3.7};

    SongList* testList = new SongList();
    for(int i=0; i<5; i++){
        testList->addNewItem(*(new Song(artists[i], title[i], duration[i])));
    }

    for(int i=0; i<5; i++){
        testList->removeItem(title[i]);
    }

    std::cout << "Remove from a populated list: ";
    printAssertEquals(true, testList->isEmpty());

    std::cout << "Remove from an empty list:";
    SongList* emptyList = new SongList();
    try {
        emptyList->removeItem(title[0]);
    }
    catch(std::invalid_argument& e){
        printAssertEquals("Item not found", e.what());
    }

    std::cout << "============== DONE ============" << std::endl;
    std::cout << "" << std::endl;
}

void testSongListIsEmpty(){
    std::cout << "------------ Testing Is Empty ----------" << std::endl;
    SongList* testList = new SongList();
    printAssertEquals(true, testList->isEmpty());
    std::cout << "============= DONE ===============" << std::endl;
}

void testSongListGetItem(){
    std::cout << "------------ Testing Get Item -------------" << std::endl;
    std::string artists[5] = {"Bach", "Brahms", "Dvorak", "Vivaldi", "Mendhelsson"};
    std::string title[5] = {"Opus 1", "Opus 2", "Opus 3", "Opus 4", "Opus 5"};
    float duration[5] = {3.5, 3.2, 3.1, 2.5, 3.7};

    SongList* testList = new SongList();
    for(int i=0; i<5; i++){
        testList->addNewItem(*(new Song(artists[i], title[i], duration[i])));
    }

    std::cout << "Get Item from a populated list: "<< std::endl;
    for(int i=0; i<5; i++){
        printAssertEquals((testList->getItem(title[i]))->getTitle(), title[i]);
    }

    std::cout << "Get Item from an empty list:"<<std::endl;
    SongList* emptyList = new SongList();
    try{
        Song* returned = emptyList->getItem(title[0]);
    }
    catch(std::invalid_argument& e){
        printAssertEquals("List is empty", e.what());
    }

    std::cout << "============ DONE ============" << std::endl;
}

void runAllSongListTests(){
    std::cout << "" << std::endl;
    std::cout << "----------------------->Testing Song and Song Lists" << std::endl;
    testSongListGetAllItems();
    testSongListGetItem();
    testSongListIsEmpty();
    testSongListCopyConstructor();
    testSongListAddNewItem();
    testSongListRemoveItem();
}