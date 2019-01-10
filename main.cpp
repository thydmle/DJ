////
//// Group Members: Elvis Okumu, Liam Pfaff, Thy Doan Mai Le
//// Class: COMP 220 - Intro to Data Structures in C++
//// Automated DJ program
////
////
#include "SongList.h"
#include "Song.h"
#include "Collection.h"
#include "PlayList.h"
#include "ArrayListTest.cpp"
#include "CollectionsTest.cpp"
#include "SongListTest.cpp"
#include "PlayListTest.cpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

//// When Import is called, the program will look for the <importfile.txt> in the cmake-build-debug folder
/// So make sure that the file that you'd like to import from is in the cmake-build-debug



/**
 * STUB FUNCTION
 * creates a string representation of an string array for easy printing
 * Note: we just use this to view array contents, so we don't need to time it...
 * @return a string representing the given array in the exact format shown below
 *  {1, 2, 3, 4, 5}
 *  {} for size < 1
 *
 *  Thy Le
 */
std::string toString(const std::string* arrayPtr, int size){
    std::string strResult;

    if(size <= 0){
        std::cout << "{}" << std::endl;
    }
    else{
        for(int i = 0; i < size; i++){
            strResult += arrayPtr[i];
            if(i < (size - 1)){
                strResult += ", ";
            }
            if(i == (size - 1)){
                strResult += ".";
            }
        }

    }

    return strResult;

}


/*
 * STUB FUNCTION
 * findByArtist
 * finds all song names associated with an artist
 * puts all these song names into a DYNAMIC array
 * use a to strong function that takes the string array
 * convert it into a SORTED string representation
 * returns the string of songs, alphabetized, by a certain artist
 *
 * Thy Le
 */
std::string findByArtist(std::string artistName, SongList& library){
    int librarySize = library.getCurrItemCount();
    std::string titles[librarySize];
    int currItemCount = 0;

    //loop through the library
    for(int i=0; i<librarySize; i++) {
        try {
            if (library.getItem(i)->getArtist() == artistName) {
                titles[currItemCount] = library.getItem(i)->getTitle();
                currItemCount++;
            }
        }
        catch(std::invalid_argument& e){
            std::cout << "Your Library is empty" << std::endl;
        }
    }

    //now sort the array of strings alphabetically
    for (int i = 0; i < (currItemCount - 1); i++) {
        for (int j = 0; j < (currItemCount - i - 1); j++) {
            if (titles[i + j].compare(titles[i]) < 0) {
                std::string temp = titles[i];
                titles[i] = titles[i + j];
                titles[i + j] = temp;
            }

        }
    }


    std::string result = toString(titles, currItemCount);
    return result;

}

/**
 * STUB FUNCTION
 * check to see if a certain artist is already in the array
 * @param artistName
 * @param array
 * @param sizeToCheck
 * @return true if artist is already in the list of artists
 *
 * Thy Le
 */
bool find(const std::string* arrayPtr, int size, std::string artistName){
    for(int i = 0; i<size; i++) {
        if(arrayPtr[i] == artistName){
            return true;
        }
        return false;
    }

}


/*
 *  Library : displays all songs in library in alphabetical order by artist
 *  Used stub functions:
 *      find
 *      findByArtist
 *
 *      Thy Le
 */
void displayAllSongsInLibrary(SongList& library){
    if(library.getCurrItemCount() == 0){
        std::cout << "Your Library is empty" << std::endl;
        return;
    }

    int librarySize = library.getCurrItemCount();
    std::string artistsInLibrary[librarySize];

    std::string currentArtist;
    int currArtistCount = 0;

    //extract artist names out of the library
    for(int i=0; i<librarySize; i++){
        try {
            currentArtist = library.getItem(i)->getArtist();
            if (!(find(artistsInLibrary, i + 1, currentArtist))) {
                artistsInLibrary[currArtistCount] = currentArtist;
                currArtistCount++;
            }
        }
        catch(std::invalid_argument& e){
            std::cout << "Your library is empty" << std::endl;
        }
    }



    std::cout << "--------All Songs in Library--------" << std::endl;

    for(int i=0; i<currArtistCount; i++){
        std::cout << "=====> Songs by " << artistsInLibrary[i] << " are:" << std::endl;
        std::cout << findByArtist(artistsInLibrary[i], library) << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

}


/*
 * Artist<artist> : display all songs for the given artist
 *
 * Thy Le
 */
void displayAllSongsByArtist(std::string artistName, SongList& library){
    if(library.getCurrItemCount() == 0){
        std::cout << "Your library is empty" << std::endl;
        return;
    }
    std::string currentArtist;
    bool found = false;

    for(int i = 0; i<library.getCurrItemCount() ; i++){
        try{
            currentArtist = library.getItem(i)->getArtist();
            if(currentArtist == artistName){
                found = true;
            }
        }
        catch(std::invalid_argument& e){
            std::cout << e.what() << std::endl;
        }
    }
    if(found) {
        std::string allSongsByArtist = findByArtist(artistName, library);
        std::cout << "All Songs by " << artistName << " are:" << std::endl;
        std::cout << allSongsByArtist << std::endl;
    }
    else{
        std::cout << "This artist does not exist in your library" << std::endl;
    }
}

/*
 *  Song<Artist, title> : display all information for the given song
 *
 *  Thy Le
 *
 */
void displayAllInfoBySong(std::string songName, std::string artistName, SongList& library){
    if(library.getCurrItemCount() == 0){
        std::cout << "Your Library has no songs, please enter a valid song name" << std::endl;
        return;
    }
    Song* current;
    int librarySize = library.getCurrItemCount();
    bool found = false;
    Song* foundSong;

    for(int i=0; i<librarySize; i++){
        try {
            current = library.getItem(i);
            if (current->getTitle() == songName) {
                if (current->getArtist() == artistName) {
                    found = true;
                    foundSong = current;
                }
            }
        }
        catch(std::invalid_argument& e){
            std::cout << "Your library has no songs" << std::endl;
        }
    }

    if(found) {
        std::string artist = foundSong->getArtist();
        int playCount = foundSong->getPlayCount();
        float duration = foundSong->getDuration();

        std::cout << "====> About " << "'" << songName << "'" << std::endl;
        std::cout << "====> Artist: " << artist << std::endl;
        std::cout << "====> Duration: " << duration << std::endl;
        std::cout << "====> Has been played: " << std::to_string(playCount) << " times" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
    }
    else{
        std::cout << "-----This song does not exist in your library" << std::endl;
    }
}


/*
 *  Playlists : display all the names of all playlists and their durations
 *
 *  Thy Le
 */
void displayAllPlaylistNames(Collection& collection){
    if(collection.getCurrItemCount() == 0){
        std::cout << "Your Collection is currently empty. No Item to display" << std::endl;
        return;
    }
    else {
        int collectionSize = collection.getCurrItemCount();
        std::cout << "Here are all of the playlists in your collection: " << std::endl;
        std::cout << "Name" << "      " << "Duration" << std::endl;
        for (int i = 0; i < collectionSize; i++) {
            try {
                std::cout << collection.getPlayListInfo(collection.getItem(i)->getTitle()) << std::endl;
            }
            catch (std::invalid_argument &e) {
                std::cout << "Your collection has no playlists" << std::endl;
            }
        }
    }
}



void helpCommand(){
    std::cout << "" << std::endl;
    std::cout << "Here is a list of all available commands " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Library: Display a list of all available songs" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Artist <artist>: Display all songs for the given artist."<< std::endl;
    std::cout << "" << std::endl;
    std::cout << "Song < Artist title>: Display all information for the given song." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Import <ImportFile.txt>: Add all songs from the import file to the library. "<< std::endl;
    std::cout << "" << std::endl;
    std::cout << "Discontinue <DiscontinueFile.txt>: Remove all songs from the discontinue file from the library."<< std::endl;
    std::cout << "" << std::endl;
    std::cout << "Playlists: display the names of all playlists and their durations" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Playlist <name>: display all songs left in the given playlist, and the duration" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "New <name>: Make a new empty playlist with the given name" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Add <PlayListName songArtist songTitle>: Add the given song to the end of the given playlist"<< std::endl;
    std::cout << "" << std::endl;
    std::cout << "Remove <PlayListName songArtist songTitle >: remove the given song from the playlist" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Playnext <PlayListName>: Print all information about the next song to be played from the given playlist to the screen." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Random <PlayListName  duration>: Make a new playlist with the given name, and populate it with a random group of songs that do not repeat" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Save:	Save the library and all playlists and terminate execution." << std::endl;
    std::cout << "" << std::endl;

}



std::string getArguments(std::string command){
    int argStart = command.find(" ");
    return command.substr(argStart+1);
}



void saveLibrary(SongList* library){
    std::ofstream saveLib;
    saveLib.open("LibrarySaveFile.txt");
    if(saveLib.is_open()){
        for(int i =0; i<library->getCurrItemCount(); i++){
            Song* song = library->getItem(i);
            saveLib << song->getTitle() + " " + song->getArtist() + " " + std::to_string(song->getDuration()) + " " + std::to_string(song->getPlayCount()) << std::endl;
        }
    }
    saveLib.close();
}



SongList* initializeLibrary(std::string fileToUploadFrom){
    //create a new library object
    SongList* library = new SongList();

    // initialize a new ifstream object and pass it the file name string
    std::ifstream infile(fileToUploadFrom);
    std::string line;
    std::string songArtist;
    std::string songDuration;
    std::string songTitle;

    if(infile){
        // if the infile is valid as in if the infile is ready to be used
        while(infile){
            //while the infile is open
            //get a line which will look like this:   "songTitle songArtist songDuration"
            getline(infile, line);

            //get the position of the first space
            int songNameEnd = line.find(" ");
            // use substring function of the string class to get the first item:  substring(startIndex, stringLength)
            songTitle = line.substr(0, songNameEnd);
            //find the next space and inilalize a last space
            int nextSpace = songNameEnd;
            int lastSpace = 0;
            std::string item = "";
            songArtist;
            songDuration;
            int calculatedLength;
            //initialize the variables for the loop
            for (int i = 0; i < 2; i++){
                // get the indexies of the first space and the next space
                lastSpace = nextSpace;
                nextSpace = line.find(" ", nextSpace+1);
                //calculate the string length
                calculatedLength = (nextSpace) - (lastSpace+1);
                // get the string
                item = line.substr(lastSpace+1, calculatedLength);
                // figure out which item the string is in
                if(i == 0){
                    songArtist = item;
                }
                else if(i == 1){
                    songDuration = item;

                }
            }
            if(line != "") {
                //create a song and add it to the library
                Song *song = new Song(songArtist, songTitle, std::stof(songDuration));
                library->addNewItem((*song));
            }
        }

    }
    return library;
}



PlayList* initializePlaylist(std::string name, SongList* library){
    //get a song name from the playlist, will need to rewrite this so that you can store multiple playlists in one file
    PlayList* playList = new PlayList(name);
    std::ifstream infile("PlayListSaveFile.txt");
    std::string line;
    int numOfSongs;

    if(infile){
        while(infile) {
            getline(infile, line);
            int songNameEnd = line.find(" ");
            std::string playlistname = line.substr(0, songNameEnd);
            if (playlistname == name) {
                int songAmountEnd = line.find(" ", songNameEnd + 1);
                std::string num = line.substr(songNameEnd + 1, ((songAmountEnd) - (songNameEnd + 1)));
                if (num != "") {
                    numOfSongs = stoi(num);
                }
                int nextSpace = line.find(" ", songAmountEnd);
                int lastSpace;
                std::string item = "";
                int calculatedLength;
                for (int i = 0; i < numOfSongs - 1; i++) {
                    lastSpace = nextSpace;
                    nextSpace = line.find(" ", nextSpace + 1);
                    calculatedLength = (nextSpace) - (lastSpace + 1);
                    item = line.substr(lastSpace + 1, calculatedLength);
                    Song *song = library->getItem(item);
                    playList->addNewItem(song);
                }
                std::string lastSong = line.substr(nextSpace + 1);
                if (lastSong != "") {
                    if (lastSong.find(" ") != std::string::npos) {
                        int unwantedSpace = lastSong.find(" ");
                        lastSong = lastSong.substr(0, unwantedSpace);
                    }
                    Song *song = library->getItem(lastSong);
                    playList->addNewItem(song);
                }


            }
        }

    }
    return playList;

}



void saveCollectionsAndPlayList(Collection* mainCollection){
    std::ofstream saveCollections;
    std::ofstream savePlayList;
    savePlayList.open("PlayListSaveFile.txt");
    saveCollections.open("CollectionsSaveFile.txt");
    if(saveCollections.is_open() && savePlayList.is_open()){
        for(int i =0; i < mainCollection->getCurrItemCount(); i++){
            PlayList* playList = mainCollection->getItem(i);
            savePlayList << playList->getTitle() << " " << playList -> getCurrItemCount() << " ";
            for(int i =0; i < playList -> getCurrItemCount(); i++){
                Song* song = playList -> getItem(i);
                savePlayList << song -> getTitle() + " ";
            }
            savePlayList << std::endl;
            saveCollections << playList->getTitle() << std::endl;
        }
        saveCollections.close();
        savePlayList.close();
    }
}


Collection* initializeCollections(SongList* library){
    // get a playlist name from the collection initialize a playlist
    Collection* collection = new Collection();
    std::ifstream infile("CollectionsSaveFile.txt");
    if(infile){
        while(infile) {
            std::string line;
            getline(infile, line);
            std::string item = "";
            if(line!= "") {
                PlayList *playList = initializePlaylist(line, library);
                collection->addNewItem(playList);
            }
        }
    }
    return collection;
}




void runTestsCommand(){
    //runs all the tests
    CollectionsTests();
    runAllSongListTests();
    runAllPlayListTests();
    //runAllArrayListTest();

}


void commandList(std::string command, SongList* library, Collection* collection){
    int firstSpace = command.find(" ");
    std::string commandArgument;
    if(firstSpace != -1){
         commandArgument = command.substr(0, firstSpace);
    }
    else{
        commandArgument = command;
    }
    if(commandArgument == "help" || commandArgument == "Help" ){
        helpCommand();
    }
    else if(commandArgument.find("Library") != std::string::npos || commandArgument.find("library") != std::string::npos){
        //"Library: Display a list of all available songs"
        displayAllSongsInLibrary((*library));


    }

    else if (commandArgument.find("Artist")!= std::string::npos || commandArgument.find("artist")!= std::string::npos){
        //"Artist <artist>: Display all songs for the given artist."
        std::string arguments = getArguments(command);
        displayAllSongsByArtist(arguments, (*library));


    }
    else if(commandArgument.find( "Song")!= std::string::npos|| commandArgument.find("song")!= std::string::npos){
        //"Song <Artist title>: Display all information for the given song."
        //needs guards for invalid artist names
        std::string arguments = getArguments(command);
        int endOfArgument1 = arguments.find(" ");
        std::string artist = arguments.substr(0,endOfArgument1);
        std::string title = arguments.substr(endOfArgument1+1);
        displayAllInfoBySong(title,artist,(*library));
    }
    else if(commandArgument.find("Import") != std::string::npos || commandArgument.find("import") != std::string::npos) {
        //"Import <filename>:Add all songs from the given file to the library. "
        //needs guards for invalid library names add try catch
        std::string arguments = getArguments(command);
        Song * newSong;
        SongList *newLibrary = initializeLibrary(arguments);
        if(newLibrary -> getCurrItemCount() > 0) {
            for (int i = 0; i < newLibrary -> getCurrItemCount(); i++) {
                newSong = newLibrary->getItem(i);
                try {
                    library->getItem(newSong->getTitle());
                    std::cout << newSong->getTitle() + " " + "is already in the Library and as such was not imported"
                              << std::endl;
                } catch (std::invalid_argument &e) {
                    std::cout << newSong->getTitle() + " " + "isn't already in the Library and as such was added"
                              << std::endl;
                    library->addNewItem((*newSong));
                }
            }
        }
        else{
            std::cout << newSong->getTitle() + " " + "isn't already in the Library and as such was added" << std::endl;

        }

    }
    else if(commandArgument.find("Discontinue") != std::string::npos || commandArgument.find("discontinue") != std::string::npos){
        //"Discontinue <filename>: Remove all songs from the given file from the library."
        std::string arguments = getArguments(command);
        Song * newSong;
        SongList *newLibrary = initializeLibrary(arguments);
        if(newLibrary -> getCurrItemCount() > 0) {
            for (int i = 0; i < newLibrary->getCurrItemCount(); i++) {
                newSong = newLibrary->getItem(i);
                try {
                    library->removeItem(newSong->getTitle());
                    std::cout << "Removing song " + newSong->getTitle()  + " from library, and all playlists"<<std::endl;
                    std::cout << "" << std::endl;
                    for(int i = 0; i< collection->getCurrItemCount(); i++){
                        PlayList* playList = collection->getItem(i);
                        for(int i =0; i<playList->getCurrItemCount(); i++){
                            Song* song = playList->getItem(i);
                            if(song->getTitle() == newSong->getTitle() && song->getArtist() == newSong->getArtist()){
                                playList->removeItem(song->getTitle());
                            }
                        }
                    }
                } catch (std::invalid_argument &e) {
                    std::cout << "Song " + newSong->getTitle()  + " wasn't in the library and so could not be removed "<<std::endl;
                    std::cout << "" << std::endl;

                }
            }
        }



    }
    else if(commandArgument.find("Playlists") != std::string::npos || commandArgument.find("playlists") != std::string::npos){
       // "Playlists: display the names of all playlists and their durations"
        std::string arguments = getArguments(command);
        //needs guards for invalid playlist names
        displayAllPlaylistNames((*collection));


    }
    else if(commandArgument.find("Playlist") != std::string::npos || commandArgument.find("playlist") != std::string::npos){
       // "Playlist <name>: display all songs left in the given playlist, and the duration"
        std::string arguments = getArguments(command);
            try {
                PlayList *playList = collection->getItem(arguments);
                std::cout << "Here are all the play list names and durations for  " + arguments << std::endl;
                for (int i = 0; i < playList->getCurrItemCount(); i++) {
                    Song *song = playList->getItem(i);
                    std::cout << "Song: ==> " + song->getTitle() + " " + std::to_string(song->getDuration()) + " ";
                }
                std::cout << std::endl;
                std::cout << "total duration for this playlist is " << std::endl;
                std::cout << std::to_string(playList->getTotalDuration()) + " mins" << std::endl;
                std::cout << "" << std::endl;

            }
            catch (std::invalid_argument &e) {
                std::cout
                        << "Playlist entered is not in collection use new <Playlist> command to add new playlist to collection "
                        << std::endl;
                std::cout << "" << std::endl;

            }


    }
    else if(commandArgument.find("New") != std::string::npos || commandArgument.find("new") != std::string::npos){
        //"New <name>: Make a new empty playlist with the given name"
        std::string arguments = getArguments(command);
        int first = arguments.find(" ", firstSpace+1);
        std::string playListName = arguments.substr(0, first);
        PlayList* newPlayList = new PlayList(playListName);
        collection->addNewItem(newPlayList);
        std::cout << " Added new Playlist " + newPlayList->getTitle() <<std::endl;

    }
    else if(commandArgument.find("Add") != std::string::npos || commandArgument.find("add") != std::string::npos){
        //"Add <name artist title>: Add the given song to the end of the given playlist"
        std::string arguments = getArguments(command);
        int first = arguments.find(" ", firstSpace+1);
        std::string playListName = arguments.substr(0, first);
        int second = arguments.find(" ", first+1);
        std::string artist = arguments.substr(first+1, (second) - (first+1));
        std::string title = arguments.substr(second+1);
        Song* song;
        PlayList* playList;

        if(library->getCurrItemCount() > 0) {
            bool songAdded   = false;
            try {
                song = library->getItem(title);
                songAdded = true;
            }
            catch (std::invalid_argument& e){
                std::cout << "New song  could not be added " + title + "  wasn't previously in the library  " << std::endl;
                std::cout << "Please add the song  " + title + " to the library before trying to add it to a playlist" << std::endl;
                std::cout << "" <<std::endl;
            }
            if(collection->getCurrItemCount() > 0 ){
                if(songAdded == true) {
                    try {
                        playList = collection->getItem(playListName);
                        playList->addNewItem(song);
                        std::cout << "Added song " + title + " to PlayList " + playListName << std::endl;

                    }
                    catch (std::invalid_argument &e) {
                        std::cout << "The playlist by the name " + playListName + " isn't in the collection"
                                  << std::endl;
                        std::cout << "Check spelling or add the playlist using command New: <playlistName>"
                                  << std::endl;
                        std::cout << "" << std::endl;
                    }
                }

            }
            else{
                std::cout << "Collection is empty  add new playlist " +  playListName + " using command New: <PlaylistName>" << std::endl;
                std::cout << "" << std::endl;

            }
        }
        else{
            std::cout << "Library empty please import a populated library " << std::endl;
            std::cout << "" << std::endl;
        }

    }
    else if(commandArgument.find("Remove") != std::string::npos || commandArgument.find("remove") != std::string::npos){
        //"Remove <name  artist title>: remove the given song from the playlist"
        std::string arguments = getArguments(command);
        int first = arguments.find(" ");
        std::string name = arguments.substr(0, first);
        int second = arguments.find(" ", first+1);
        std::string artist = arguments.substr(first+1, (second) - (first+1));
        std::string title = arguments.substr(second+1);
        PlayList* playlist;
        if(collection->getCurrItemCount() > 0) {
            bool removed = false;
            try {
                  playlist = collection->getItem(name);
                  for(int i = 0; i < playlist->getCurrItemCount(); i++){
                      if (playlist->getItem(i)->getTitle() == title && playlist->getItem(i)->getArtist() == artist) {
                          playlist->removeItem(title);
                          std::cout << "Song " + title + " was removed from play list " + name << std::endl;
                          std::cout << "" << std::endl;
                          removed = true;
                      }

                  }
                  if(removed == false){
                      std::cout << "Song " + title + " artist " + artist + " combination does not exist in this playlist" << std::endl;

                  }

            }
            catch (std::invalid_argument& e) {
                std::cout << "Playlist " + name + " does not exist in collection" << std::endl;
                std::cout << "Check spelling of your playlist  or use command Playlists: to check all playlists available in collection " << std::endl;
                std::cout << "" << std::endl;

            }
        }
        else{
            std::cout << " Collection is empty no need to remove anything " << std::endl;
            std::cout << "" << std::endl;
        }

    }
    else if(commandArgument.find("Playnext") != std::string::npos || commandArgument.find("playnext") != std::string::npos){
        //"Playnext <name>: Print all information about the next song to be played from the given playlist to the screen."
        std::string arguments = getArguments(command);

        std::cout << arguments << std::endl;
        PlayList* playlist;
        Song* nextSong;
        //Try to get the playlist from the collection
        try{
            playlist = collection->getItem(arguments);
            nextSong = playlist->playNext();
            if (nextSong == nullptr){
                std::cout << "The playlist is empty" << std::endl;
            }
            else{
                std::cout << "Artist: " << nextSong->getArtist() << std::endl;
                std::cout << "Title: " << nextSong->getTitle() << std::endl;
                std::cout << "Duration: " << nextSong->getDuration() << std::endl;
                std::cout << "PlayCount: " << nextSong->getPlayCount() << std::endl;
                //Add to the play count of the song
                nextSong->addPlayCount();
            }

        }
        catch (std::invalid_argument &e){
            std::cout << "The playlist, " + arguments + ", you requested was not found in library" << std::endl;

        }


    }
    else if(commandArgument.find("Random") != std::string::npos || commandArgument.find("random") != std::string::npos){
        //"Newrandom <name  duration>: Make a new playlist with the given name, and populate it with a random group of songs that do not repeat"
        std::string arguments = getArguments(command);
        //get rand duration
        float inDuration;
        int first = arguments.find(" ");
        std::string playListName = arguments.substr(0, first);
        int second = arguments.find(" ", first+1);
        std::string duration = arguments.substr(first+1, (second) - (first+1));
        PlayList* newRandomList;


        try{
            inDuration = std::stof(duration);
            newRandomList = new PlayList(playListName);
            newRandomList->genRandPlayList(inDuration, library);
        }
        catch(std::invalid_argument &e){
            std::cout << "You entered the something wrong, no changes made" << std::endl;
        }
    }

    else if(commandArgument.find("Save") != std::string::npos || commandArgument.find("save") != std::string::npos){
        //"save:	Save the library and all playlists and terminate execution."
        saveCollectionsAndPlayList(collection);
        saveLibrary(library);
        std::cout << "Files saved. Please submit 'exit' to exit dj program.  " << std::endl;


    }
    else if(commandArgument.find("Exit") != std::string::npos || commandArgument.find("Exit") != std::string::npos) {
        std::cout << "Not a valid commandArgument use the commandArgument:  Help  to see valid commands  " << std::endl;
    }
}

void startProgram() {
    std::string command = "";
    SongList *songList = initializeLibrary("LibrarySaveFile.txt");
    Collection *collection = initializeCollections(songList);

    while (command != "exit") {
        std::cout << "Please enter a command or enter Help for a list of commands " << std::endl;
        std::cout << "" << std::endl;
        std::getline(std::cin, command);
        //std::cout << command << std::endl;
        commandList(command, songList, collection);
    }
    std::cout << "Thank You for using the Auto-DJ good-bye " << std::endl;
}



int main() {
    srand(time(NULL));
    startProgram();
    //runTestsCommand();


}