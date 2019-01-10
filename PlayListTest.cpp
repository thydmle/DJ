//
// Created by liam on 12/4/18.
//

// Last minute edit: Thy Le 12/18/18
// Notified Liam of faulty code on lines 43 to 45 but no response so
// I took over and edited the code
#include "PlayList.h"
#include "Song.h"
#include "string"
#include "TestLib.h"

void testGetAll(){
    std::cout << "---Testing getAllItems---" << std::endl;
    PlayList* testList = new PlayList("testList");
    Song* toAdd = new Song("test1", "title1", 10.5);
    testList->addNewItem(toAdd);
    toAdd = new Song("test1", "title1", 11.5);
    testList->addNewItem(toAdd);
    toAdd = new Song("test2", "title2", 12.5);
    testList->addNewItem(toAdd);
    toAdd = new Song("test3", "title3", 13.5);
    testList->addNewItem(toAdd);
    toAdd = new Song("test4", "title4", 14.5);
    printAssertEquals("{title1, title1, title2, title3}", testList->getAllItems());
    //std::cout << testList->getAllItems() << std::endl;
    delete testList;
    std::cout << "---Done---" << std::endl;
}

void testEmpty(){
    std::cout << "---Testing isEmpty---" << std::endl;
    PlayList* testList = new PlayList("testList");
    printAssertEquals(true, testList->isEmpty());
    Song* toAdd = new Song("test1", "title1", 1.5);
    testList->addNewItem(toAdd);
    printAssertEquals(false, testList->isEmpty());
    delete testList;
    std::cout << "---Done---" << std::endl;
}

void testGetSetName(){
    std::cout << "---Testing get and set name---" << std::endl;
    PlayList* testList = new PlayList("testList");
    printAssertEquals("testList", testList->getTitle());
    testList->setTitle("testList1");
    printAssertEquals("testList1", testList->getTitle());
    delete testList;
    std::cout << "---Done---" << std::endl;
}

void testGetTotalDuration(){
    std::cout << "---Testing getTotalDuration---" << std::endl;
    PlayList* testList = new PlayList("testList");
    Song* toAdd = new Song("test1", "title1", 10.5);
    testList->addNewItem(toAdd);
    toAdd = new Song("test1", "title1", 11.5);
    testList->addNewItem(toAdd);
    printAssertEquals(22.0, testList->getTotalDuration());
    delete testList;
    std::cout << "---Done---" << std::endl;
}

void testGenRandAndNext(){
    std::cout << "---Testing GenRand and PlayNext---" << std::endl;
    //Make a few songs
    Song* s1 = new Song("test1", "title1", 10.5);
    Song* s2 = new Song("test2", "title2", 10.5);
    Song* s3 = new Song("test3", "title3", 10.5);
    Song* s4 = new Song("test4", "title4", 10.5);
    Song* s5 = new Song("test5", "title5", 10.5);
    //Make a mock song libray
    SongList* Library = new SongList();
    Library->addNewItem(*s1);
    Library->addNewItem(*s2);
    Library->addNewItem(*s3);
    Library->addNewItem(*s4);
    Library->addNewItem(*s5);
    PlayList* testList = new PlayList("testList");
    testList->genRandPlayList(40.0, Library);
    std::cout << "Randomly generated playlist" << std::endl;
    std::cout << testList->getAllItems() << std::endl;
    testList->playNext();
    std::cout << "Playnext: ";
    printAssertEquals(2, testList->getCurrItemCount());

    //Cleanup
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete Library;
    delete testList;
    std::cout << "---Done---" << std::endl;


}

void runAllPlayListTests(){
    testGetTotalDuration();
    testEmpty();
    testGetSetName();
    testGetAll();
    testGenRandAndNext();
}
