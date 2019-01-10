//
// Created by liam on 12/10/18.
//

#include "ArrayList.h"
#include "Song.h"
#include "PlayList.h"
#include "TestLib.h"

//Basic tests

//Test Add New Items and getAllItems
void addGetTest(){
    //Make new arrayList
    List<Song>* testList = new ArrayList<Song>();

    //Make some new songs
    Song* s1 = new Song("s1", "t1", 2.50);
    Song* s2 = new Song("s2", "t2", 2.50);
    Song* s3 = new Song("s3", "t3", 2.50);
    Song* s4 = new Song("s4", "t4", 2.50);
    Song* s5 = new Song("s5", "t5", 2.50);

    testList->addNewItem(*s1);
    testList->addNewItem(*s2);
    testList->addNewItem(*s3);
    testList->addNewItem(*s4);
    testList->addNewItem(*s5);

    //If this works, then addItem and getAllItems both work
    std::cout << "---Testing add and get all items---" << std::endl;
    printAssertEquals("{t1, t2, t3, t4, t5}", testList->getAllItems());
    std::cout << "---Done---" << std::endl;

    //Test itemCount
    std::cout << "---Testing getCurrItemCount---" << std::endl;
    printAssertEquals(5, testList->getCurrItemCount());
    std::cout << "---Done---" << std::endl;

    //Test get items at index
    std::cout << "---Testing get item at index---" << std::endl;
    printAssertEquals("t1", testList->getItem(0));
    printAssertEquals("t2", testList->getItem(1));
    printAssertEquals("t3", testList->getItem(2));
    printAssertEquals("t4", testList->getItem(3));
    printAssertEquals("t5", testList->getItem(4));
    std::cout << "---Done---" << std::endl;

    //Test remove item
    testList->removeItem("t1");
    //std::cout << testList->getItem(0)->getTitle() << std::endl;
    printAssertEquals("t2", testList->getItem(0)->getTitle());
    testList->removeItem("t3");
    //std::cout << testList->getItem(1)->getTitle() << std::endl;
    printAssertEquals("t4", testList->getItem(1)->getTitle());

    //Add more
    testList->addNewItem(*s1);
    testList->addNewItem(*s2);
    testList->addNewItem(*s3);
    testList->addNewItem(*s4);
    testList->addNewItem(*s5);

    //std::cout << testList->getAllItems() << std::endl;

    //Test overloaded getItem search function
    std::cout << "---Testing overloaded search function---" << std::endl;
    printAssertEquals("t2", testList->getItem("t2"));
    printAssertEquals("t1", testList->getItem("t1"));
    printAssertEquals("t3", testList->getItem("t3"));
    printAssertEquals("t5", testList->getItem("t5"));
    std::cout << "---Done---" << std::endl;
}

void runAllArrayListTest(){
    addGetTest();

}