#include "Albume.h"
#include <map>

class Artist {
    string firstName;
    string lastName;
    multimap<int, Albume> albums;
public:
    Artist()=default;
    Artist(string fn, string ln) : firstName(fn), lastName(ln) {}

    void addAlbum(const Albume& album) {
        albums.insert({album.year, album});
    }

    void removeAlbum(const string& albumName) {
        for (auto it = albums.begin(); it != albums.end();) {
            if (it->second.name == albumName) {
                it = albums.erase(it);
            } else {
                ++it;
            }
        }
    }

    void addTrackToAlbum(const string& albumName, const Track& track) {
        for (auto& entry : albums) {
            if (entry.second.name == albumName) {
                entry.second.addTrack(track);
                break;
            }
        }
    }

    void removeTrackFromAlbum(const string& albumName, const string& trackName) {
        for (auto& entry : albums) {
            if (entry.second.name == albumName) {
                entry.second.removeTrack(trackName);
                break;
            }
        }
    }

    void printAlbums() const {
        for (const auto& entry : albums) {
            cout << entry.second.year << " - " << entry.second.name << "\n";
        }
    }

    void printDiscography() const {
        for (const auto& entry : albums) {
            cout << firstName << " " << lastName << " - " << entry.second.year << " - " << entry.second.name << "\n";
            entry.second.printTracks();
        }
    }

    int getTrackCountForAlbum(const string& albumName, int minDuration) const {
        for (const auto& entry : this.albums) {
            if (entry.second.name == albumName) {
                int count = 0;
                for (const auto& track : entry.second.tracks) {
                    if (track.duration > minDuration) {
                        ++count;
                    }
                }
                return count;
            }
        }
        return 0;
    }

    void removeAlbumsWithFewTracks(int threshold) {
        for (auto it = this.albums.begin(); it != this.albums.end();) {
            if (it->second.tracks.size() < threshold) {
                it = albums.erase(it);
            } else {
                ++it;
            }
        }
    }
};
