#include <iostream>
#include "Artist.h"
using namespace std;

int main()
{
    Artist artist("John", "Doe");

    // Add Albums
    artist.addAlbum(Albume("First Album", 2001));
    artist.addAlbum(Albume("Second Album", 2003));

    // Add Tracks to Albums (positions will be auto-assigned)
    artist.addTrackToAlbum("First Album", Track("Track 1", 180)); // 3 minutes
    artist.addTrackToAlbum("First Album", Track("Track 2", 240)); // 4 minutes
    artist.addTrackToAlbum("Second Album", Track("Track 1", 150)); // 2.5 minutes
    artist.addTrackToAlbum("Second Album", Track("Track 2", 300)); // 5 minutes

    // Print Discography
    artist.printDiscography();

    // Count tracks longer than 3 minutes in an album
    std::cout << "Tracks longer than 180 seconds in 'First Album': " << artist.getTrackCountForAlbum("First Album", 180) << std::endl;

    // Remove albums with fewer than 2 tracks
    artist.removeAlbumsWithFewTracks(2);
    artist.printAlbums();
    return 0;
}
