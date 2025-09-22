
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996) // for Visual Studio Only

#define MAX_SONGS 20
#define MAX_SONG_NAME_LENGTH 40
#define MAX_SINGER_NAME_LENGTH 40

typedef enum
{
    unclassified = 0,
    Pop,
    Rock,
    Reggae,
    Country,
    Blues,
    Balad,
} genreType; // enum type

struct musicRepository
{
    // struct for song details
    unsigned int ID;
    char songName[MAX_SONG_NAME_LENGTH];
    char singerName[MAX_SINGER_NAME_LENGTH];
    genreType genre;
    unsigned int year;
};

struct musicRepository list[MAX_SONGS]; // declare the list of songs
int numSongs = 0;                       // the number of songs currently stored in the list (initialized to 0)

// Given functions
void initializeRepository(struct musicRepository repo[], int size);
void printRepository(struct musicRepository repo[], int numSongs);
void flushSngIn();

// functions that need to be implemented by you
int addSong(struct musicRepository repo[], char *songName, char *singerName, char *genre, unsigned int year, int numSongs);
struct musicRepository *searchSong(struct musicRepository repo[], char *songName, int numSongs);
void printSong(struct musicRepository repo[], int ID);
int editSong(struct musicRepository *repo, int numSongs, char *songName);
int deleteSongByName(struct musicRepository *repo, char *songName, int numSongs);

// This function takes in an array of musicRepository structures and the size of the array as parameters. It then loops through each index of the array and sets the values of id, year, genre, name, and singer to their respective initial values.
// NOTE that strcpy is used to copy an empty string to name and singer, rather than setting them equal to "". This is because arrays in C are not assignable, so the strcpy function must be used to copy the empty string into the array.
void initializeRepository(struct musicRepository repo[], int size)
{
    for (int i = 0; i < size; i++)
    {
        repo[i].ID = 0;
        repo[i].year = 0;
        repo[i].genre = 0;
        strcpy(repo[i].songName, "");
        strcpy(repo[i].singerName, "");
    }
}

// This function takes in the musicRepository array and iterates through each element. If the ID of the song is not 0, it prints the details of the song.

void printRepository(struct musicRepository repo[], int numSongs)
{
    printf("\n--- Song Repository ---\n");
    for (int i = 0; i < numSongs; i++)
    {
        if (repo[i].ID != 0)
        {
            printf("ID: %d\n", repo[i].ID);
            printf("Name: %s\n", repo[i].songName);
            printf("Singer: %s\n", repo[i].singerName);
            if (repo[i].genre == 0)
                printf("Genre: unclassified\n");
            else if (repo[i].genre == 1)
                printf("Genre: Pop\n");
            else if (repo[i].genre == 2)
                printf("Genre: Rock\n");
            else if (repo[i].genre == 3)
                printf("Genre: Reggae\n");
            else if (repo[i].genre == 4)
                printf("Genre: Country\n");
            else if (repo[i].genre == 5)
                printf("Genre: Blues\n");
            else if (repo[i].genre == 6)
                printf("Genre: Balad\n");
            printf("Year: %d\n", repo[i].year);
            printf("\n");
        }
    }
}

//  This function is used to add a song into the list. You can simply add the new song to the end of list (array of structs).
//  Do not allow the song to be added to the list if it already exists in the list. You can do that by checking song names OR IDs already in the list.
//  If the song already exists then return 0 without adding it to the list. If the song does not exist in the list then add the song at the end of the list and return 1.
//  If song list is full, then do not add new song to the list and return 2.
//  The list is case sensitive. For instance, 'Case' and 'case' should be considered two different names.
int addSong(struct musicRepository repo[], char *songName, char *singerName, char *genre, unsigned int year, int numSongs){
    if (numSongs >= MAX_SONGS) {
        return 2;
    }
    if (searchSong(repo,songName,numSongs) == NULL) {
        strcpy(repo[numSongs].songName, songName);
        strcpy(repo[numSongs].singerName, singerName);
        repo[numSongs].genre = genre;
        repo[numSongs].year = year;
        repo[numSongs].ID = numSongs+1;
        numSongs++;
        return 1;
    }
    else{
        return 0;
    }
}

//  This function takes in the name of a song as input and search for it in the musicRepository array. It returns a pointer to the musicRepository struct that contains information about the song.
//  NOTE that the input name of the song should match the name of the song in the array exactly, including any whitespace or special characters.
struct musicRepository *searchSong(struct musicRepository repo[], char *songName, int numSongs){
    // TODO: Implement function
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(repo[i].songName, songName) == 0) {
           return &repo[i];
        }
    }
    return NULL;
};

//  This function takes the ID of a song as input, which represents a single song in the repository. The function then prints out the details of the song, including its ID, name, singer, genre, and year. The genre is printed as a string, based on its corresponding enum value.
void printSong(struct musicRepository repo[], int songID){
    // TODO: Implement function
    for(int i = 0; i <= numSongs; i++) {
        if(repo[i].ID == songID) {
            printf("ID: %d\n", repo[i].ID);
            printf("Name: %s\n", repo[i].songName);
            printf("Singer: %s\n", repo[i].singerName);
            if(repo[i].genre == 0)
                printf("Genre: unclassified\n");
            else if (repo[i].genre == 1)
                printf("Genre: Pop\n");
            else if (repo[i].genre == 2)
                printf("Genre: Rock\n");
            else if (repo[i].genre == 3)
                printf("Genre: Reggae\n");
            else if (repo[i].genre == 4)
                printf("Genre: Country\n");
            else if (repo[i].genre == 5)
                printf("Genre: Blues\n");
            else if (repo[i].genre == 6)
                printf("Genre: Balad\n");
            printf("Year: %d\n", repo[i].year);
            return;
            
        }
    }
    printf("Song with ID %d not found\n", songID);
};

//  This function takes the name of a song as input, searches for the song, and allows the user to modify any field of the song except for the ID field. The function should prompt the user for the new values of the fields and update the corresponding fields of the song. If the song is not found, the function should return -1 to indicate failure, otherwise it should return 1 to indicate success.
int editSong(struct musicRepository *repo, int numSongs, char *songName) {
    // TODO: Implement function
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(repo[i].songName, songName) == 0) {
            // Prompt user for new values of the fields
            printf("Enter the updated song name: ");
            fgets(repo[i].songName, MAX_SONG_NAME_LENGTH, stdin);
            repo[i].songName[strlen(repo[i].songName) - 1] = '\0';
            printf("Enter the updated singer name: ");
            fgets(repo[i].singerName, MAX_SINGER_NAME_LENGTH, stdin);
            repo[i].singerName[strlen(repo[i].singerName) - 1] = '\0';
            printf("Enter the updated genre (Pop , Rock , Reggae , Country , Blues , Balad  or unclassified): ");
            scanf("%d", &repo[i].genre);
            flushSngIn();
            printf("Enter the updated year: ");
            scanf("%d", &repo[i].year);
            

            return 1;
        }
    }

    return -1; // Song was not found
}

//  This function takes the name of a song as input, searches for the song, and deletes the song by setting all its fields to default values. If the song is not found, the function should return -1 to indicate failure, otherwise it should return 1 to indicate success.
int deleteSongByName(struct musicRepository *repo, char *songName, int numSongs){
    // TODO: Implement function    
    struct musicRepository *songToDelete = searchSong(repo, songName, numSongs);
    if (songToDelete == NULL) {
        return -1;
    }

    for (int i = songToDelete->ID - 1; i < numSongs - 1; i++) {
        repo[i] = repo[i + 1];
        repo[i].ID--;
    }

    // Set the last song in the repository to default values
    repo[numSongs - 1].ID = 0;
    repo[numSongs - 1].genre = unclassified;
    repo[numSongs - 1].year = 0;
    memset(repo[numSongs - 1].songName, 0, MAX_SONG_NAME_LENGTH);
    memset(repo[numSongs - 1].singerName, 0, MAX_SINGER_NAME_LENGTH);

    return 1;
};

// Problem 2

// struct to hold information about a song
struct Song
{
    int id;
    char name[MAX_SONG_NAME_LENGTH];
    char singer[MAX_SINGER_NAME_LENGTH];
    genreType genre;
    int year;
    struct Song *next;
};

// Function declarations
struct Song *createSong(int id, char *name, char *singer, char *genre, int year);
void printPlaylist(struct Song *playlist);

void add_song(struct Song **playlist, struct Song *newSong);
struct Song *search_song(struct Song *playlist, char *name);
int edit_song(struct Song *playlist, char *name, char *singer, char *genre, int year);
int delete_song(struct Song *playlist, char *name);

// function to create a new song
struct Song *createSong(int id, char *name, char *singer, char *genre, int year)
{
    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
    newSong->id = id;
    strcpy(newSong->name, name);
    strcpy(newSong->singer, singer);
    if (strcmp(genre, "Pop") == 0)
        newSong->genre = 1;
    else if (strcmp(genre, "Rock") == 0)
        newSong->genre = 2;
    else if (strcmp(genre, "Reggae") == 0)
        newSong->genre = 3;
    else if (strcmp(genre, "Country") == 0)
        newSong->genre = 4;
    else if (strcmp(genre, "Blues") == 0)
        newSong->genre = 5;
    else if (strcmp(genre, "Balad") == 0)
        newSong->genre = 6;
    else
        newSong->genre = 0;
    newSong->year = year;
    newSong->next = NULL;
    return newSong;
}

// function to print the playlist
void printPlaylist(struct Song *playlist)
{
    struct Song *current = playlist;
    char* type;

    while (current != NULL)
    {
        if (current->genre == 0)
                type = "unclassified";
            else if (current->genre == 1)
                type = "Pop";
            else if (current->genre == 2)
                type = "Rock";
            else if (current->genre == 3)
                type = "Reggae";
            else if (current->genre == 4)
                type = "Country";
            else if (current->genre == 5)
                type = "Blues";
            else if (current->genre == 6)
                type = "Balad";
        printf("%d\t%s\t%s\t%s\t%d\n", current->id, current->name, current->singer, type, current->year);
        current = current->next;
    }
}

// function to add a song to the end of the playlist
void add_song(struct Song **playlist, struct Song *newSong)
{
    // TODO: Implement function
    if (*playlist == NULL) {
        *playlist = newSong;
    } else {
        struct Song *currentSong = *playlist;
        while (currentSong->next != NULL) {
            currentSong = currentSong->next;
        }
        currentSong->next = newSong;
    }
    newSong->next = NULL;

}

// function to search for a song by name
struct Song *search_song(struct Song *playlist, char *name)
{
    // TODO: Implement function
    struct Song *current_song = playlist;
    while (current_song != NULL) {
        if (strcmp(current_song->name, name) == 0) {
            return current_song;
        }
        current_song = current_song->next;
    }
    return NULL;
}

// function to edit a song by name
int edit_song(struct Song *playlist, char *name, char *singer, char *genre, int year)
{
    // TODO: Implement function
    struct Song *current = playlist;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {  // if current song name matches
            // edit the song details
            strcpy(current->singer, singer);
            if (strcmp(genre, "Pop") == 0)
                current->genre = 1;
            else if (strcmp(genre, "Rock") == 0)
                current->genre = 2;
            else if (strcmp(genre, "Reggae") == 0)
                current->genre = 3;
            else if (strcmp(genre, "Country") == 0)
                current->genre = 4;
            else if (strcmp(genre, "Blues") == 0)
                current->genre = 5;
            else if (strcmp(genre, "Balad") == 0)
                current->genre = 6;
            else
                current->genre = 0;          ///////its not printing the correct number/ is it supposed to be a number
            current->year = year;
            return 1;  // return 1 for success
        }
        current = current->next;
    }
    return -1;  // the song was not found
}

// function to delete a song by name
int delete_song(struct Song *playlist, char *name)
{
    // TODO: Implement function
    struct Song *current = playlist;
    struct Song **prev_next_ptr = playlist;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            *prev_next_ptr = current->next;
            free(current);
            while (*prev_next_ptr != NULL) {
                (*prev_next_ptr)->id--;
                prev_next_ptr = &(*prev_next_ptr)->next;
            }
            return 1;
        }
        prev_next_ptr = &current->next;
        current = current->next;
    }
}

void flushSngIn()
{
    char c;
    do
        c = getchar();
    while (c != '\n' && c != EOF);
}

int main()
{
    // Problem 1
    int choice = 0;
    int songCount = 0;
    char songName_input[MAX_SONG_NAME_LENGTH], singerName_input[MAX_SINGER_NAME_LENGTH];
    char genre_input[20];
    unsigned int year_input, add_result = 0;
    struct musicRepository music[20];
    struct musicRepository *song = NULL;

    initializeRepository(music, 20); 
    music[0].ID = numSongs + 1; numSongs++;
    strcpy(music[0].songName,"Shape of You");
    strcpy(music[0].singerName,"Ed Sheeran");
    music[0].genre=1;
    music[0].year=2017;
    songCount++;

    music[1].ID = numSongs + 1; numSongs++;
    strcpy(music[1].songName,"Despacito");
    strcpy(music[1].singerName,"Luis Fonsi");
    music[1].genre=1;
    music[1].year=2017;
    songCount++;

    music[2].ID = numSongs + 1; numSongs++;
    strcpy(music[2].songName,"Uptown Funk");
    strcpy(music[2].singerName,"Mark Ronson ft. Bruno Mars");
    music[2].genre=1;
    music[2].year=2014;
    songCount++;

    printf("Number of Songs: %d", songCount);

    do
    {
        printf("\n");
        printf("1. Add a song to the repository\n");
        printf("2. Search song by name\n");
        printf("3. Print a song\n");
        printf("4. Edit a song\n");
        printf("5. Delete a song\n");
	    printf("6. Print full list of songs\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        flushSngIn();

        switch (choice)
        {
        case 1:
            printf("\nEnter song name: ");
            fgets(songName_input, sizeof(songName_input), stdin);
            songName_input[strlen(songName_input) - 1] = '\0';
            // flushSngIn();
            // printf("Song name: %s\n", songName_input);
            printf("Enter singer name: ");
            fgets(singerName_input, sizeof(singerName_input), stdin);
            singerName_input[strlen(singerName_input) - 1] = '\0';
            // flushSngIn();
            printf("Enter genre ( Pop , Rock , Reggae , Country , Blues , Balad  or unclassified ):");
            fgets(genre_input, sizeof(genre_input), stdin);
            genre_input[strlen(genre_input) - 1] = '\0';
            // flushSngIn();
            printf("Enter release year: ");
            scanf("%d", &year_input);
            flushSngIn();

            add_result = addSong(music, songName_input, singerName_input, genre_input, year_input, songCount);
            if (add_result == 1)
            {
                printf("Song added successfully\n");
                // printf("Number of Songs: %d", songCount);
                // flushSngIn();
                songCount++;
                printRepository(music, songCount);
                break;
            }
            if (add_result == 2)
            {
                printf("Song directory full\n");
                break;
            }
            if (add_result == 0)
            {
                printf("Song already exists\n");
                break;
            }
        case 2:
            printf("Enter song name: ");
            fgets(songName_input, sizeof(songName_input), stdin);
            songName_input[strlen(songName_input) - 1] = '\0';
            flushSngIn();
            song = searchSong(music, songName_input, songCount);
            printf("Song found: %s, %s, %d, %d", song->songName, song->singerName, song->genre, song->year);
            flushSngIn();
            break;
        case 3:
            if (songCount > 0)
            {
                int songIndex;
                printf("Enter the ID of the song to print (1 to %d): ", songCount);
                scanf("%d", &songIndex);
                printSong(music, songIndex);
                flushSngIn();
                break;
            }
        case 4:
            printf("Enter song name: ");
            fgets(songName_input, sizeof(songName_input), stdin);
            songName_input[strlen(songName_input) - 1] = '\0';
            //flushSngIn();
            editSong(music, songCount, songName_input);
            break;
        case 5:
            printf("Enter song name: ");
            fgets(songName_input, sizeof(songName_input), stdin);
            songName_input[strlen(songName_input) - 1] = '\0';
            //flushSngIn();
            deleteSongByName(music, songName_input, songCount);
            songCount--;
            printRepository(music, songCount);
            break;
        case 6:
	        printRepository(music, songCount);
	        break;
	    case 7:
            printf("Exiting the program\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 7);

    // Problem 2
    // create some sample songs
    struct Song *s1 = createSong(1, "Shape of You", "Ed Sheeran", "Pop", 2017);
    struct Song *s2 = createSong(2, "Despacito", "Luis Fonsi", "Pop", 2017);
    struct Song *s3 = createSong(3, "Uptown Funk", "Mark Ronson ft. Bruno Mars", "Pop", 2014);

    // create the playlist and add the sample songs
    struct Song *playList = NULL;
    add_song(&playList, s1);
    add_song(&playList, s2);
    add_song(&playList, s3);

    // print the playlist
    printf("Initial Playlist:\n");
    printPlaylist(playList);

    // add a new song to the playlist
    struct Song *s4 = createSong(4, "Sorry", "Justin Bieber", "Pop", 2015);
    printf("\nAdding new song to playlist:\n");
    add_song(&playList, s4);
    printPlaylist(playList);

    // delete a song from the playlist
    printf("\nDeleting a song from the playlist:\n");
    struct Song *sToDelete = search_song(playList, "Despacito");
    if (sToDelete != NULL)
    {
        delete_song(playList, sToDelete->name);
        printf("Playlist after deletion:\n");
        printPlaylist(playList);
    }
    else
    {
        printf("Song not found in playlist.\n");
    }

    // search for a song that doesn't exist in the playlist
    printf("\nSearching for a song that doesn't exist in the playlist:\n");
    struct Song *searchResult = search_song(playList, "Non-existent Song");
    if (searchResult != NULL)
    {
        printf("Found song:\n");
        printf("Song ID: %d, Song Name: %s, Singer Name: %s, Genre: %s, Year: %d", searchResult->id, searchResult->name, searchResult->singer, searchResult->genre, searchResult->year);
    }
    else
    {
        printf("Song not found in playlist.\n");
    }

    // search for a song that exists in the playlist
    printf("\nSearching for a song that exists in the playlist:\n");
    searchResult = search_song(playList, "Uptown Funk");
    if (searchResult != NULL)
    {
        // printf("Found song:\n");
        // printSong(searchResult);
    }
    else
    {
        printf("Song not found in playlist.\n");
    }

    // edit a song in the playlist
    printf("\nEditing a song in the playlist:\n");
    int editResult = edit_song(playList, "Shape of You", "Ed Sheeran", "Pop", 2018);
    if (editResult == -1)
    {
        printf("Song not found in playlist.\n");
    }
    else
    {
        printf("Playlist after edit:\n");
        printPlaylist(playList);
    }

    return 0;
}