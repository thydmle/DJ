//
// Created by elvis on 12/4/2018.
//



#include "PlayList.h"
#include "TestLib.h"
#include "Song.h"
#include "Collection.h"
#include <iostream>






void EmptyCollectionsTests(Collection* testList){
    std::cout << "=============== Initializing a Collections and testing initialization =======================" << std::endl;
    std::cout <<"======== Testing is empty =========" << std::endl;
    printAssertEquals(true,  testList->isEmpty());
    std::cout << "====== end ======" << std::endl;
    std::cout << "" << std::endl;
    std::cout <<"======= Testing Item count ========" << std::endl;
    printAssertEquals(0, testList->getCurrItemCount());
    std::cout << "====== end ======" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "======= Testing get playlist info on empty list ======" << std::endl;
    try {
         testList->getPlayListInfo("");
    }catch (std::invalid_argument& e){
        printAssertEquals("Item not found", e.what());

    }
    std::cout << "====== end ======" << std::endl;
    std::cout << "" << std::endl;



    std::cout << "===== Checking remove item =====" << std::endl;
    try {
        testList->removeItem("");
    }catch (std::invalid_argument& e){
        printAssertEquals("Item not found", e.what());
    }
    std::cout << "====== end ======" << std::endl;
    std::cout << "" << std::endl;


    std::cout << "====== Checking getAllItems ======" << std::endl;
    printAssertEquals("{}", testList->getAllItems());
    std::cout << "====== end ======" << std::endl;
    std::cout << "" << std::endl;

}


void fillPlayList(PlayList* testList, int fillTo){
    Song* item1 = new Song("Lil Wayne", "Right Above it", 3.00);
    Song* item2 = new Song("Lil Wayne", "Lolly Pop", 2.00);
    Song* item3 = new Song("Lil Wayne", "Love me", 1.50);
    Song* item4 = new Song("Lil Wayne", "6 foot 7 foot", 4.00);
    Song* item5 = new Song("Lil Wayne", "Drop the world", 5.00);
    Song* item6 = new Song("Lil Wayne", "Go DJ", 2.50);
    Song* item7 = new Song("Lil Wayne", "Right Above it", 3.50);
    Song* item8 = new Song("Lil Wayne", "Blunt Blowing", 3.00);
    Song* songs[8] = {item1, item2, item3, item4, item5, item6, item7, item8};

    for(int i =0; i < fillTo; i++){
        testList->addNewItem(songs[i]);
    }
    std::cout << testList->getAllItems() << std::endl;
}

void emptyCollections(Collection *collection1){

    std::cout << "========== Removing items from collection ======= " << std::endl;
    collection1->getAllItems();
    for(int i =0; i<8; i++){
        std::cout << " Removing item " << i << std::endl;
        collection1->removeItem("TestPlayList" + std::to_string(i));
        std::cout << collection1->getAllItems() << std::endl;

        std::cout << "" << std::endl;

    }
    std::cout << "====== end ======" << std::endl;
    std::cout << "" << std::endl;

    EmptyCollectionsTests(collection1);

}

void fillingCollectionTest( Collection* collection1){
    PlayList* playlists[8] = {};

    std::cout <<"============ Filling collection =============" << std::endl;
    for(int i =0; i<8; i++){
        playlists[i] = new PlayList("TestPlayList" + std::to_string(i));
        fillPlayList(playlists[i], i+1);
        collection1->addNewItem(playlists[i]);
        printAssertEquals(i+1, collection1->getCurrItemCount());
        std::cout << collection1->getPlayListInfo("TestPlayList" + std::to_string(i))<< std::endl;
    }
    std::cout << "======== end ===========" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "========= Displaying Collection ======== " << std::endl;
    std::cout << collection1->getAllItems() << std::endl;
    std::cout << "========= end ==========" << std::endl;
    std::cout << "" << std::endl;


    std::cout << "========== Checking is empty =========== " << std::endl;
    printAssertEquals(false, collection1->isEmpty());
    std::cout << "======== end ========" << std::endl;
    std::cout << "" << std::endl;


}

void CollectionsTests(){

    std::cout << "========== Collections Tests =========== " << std::endl;

    Collection* collection1 = new Collection();
    EmptyCollectionsTests(collection1);
    fillingCollectionTest(collection1);
    emptyCollections(collection1);
    delete collection1;
    std::cout << "========== Deletion successful =========== " << std::endl;
    std::cout << "========== Done =========== " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

}



