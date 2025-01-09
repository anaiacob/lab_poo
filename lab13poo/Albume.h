#include "Track.h"
#include <set>
#include <algorithm>

class Albume
{
    string nume_album;
    int an_aparitie;
    set<Track> tracks;
public:
    Albume()=default;
    Albume(string n, int an):nume_album(n),an_aparitie(an)
    {
    }
    void addTrack(const Track& track) {
        tracks.insert(track);
    }

    void removeTrack(const string& trackName) {
        auto it = find_if(tracks.begin(), tracks.end(), [&trackName](const Track& t) {
            return t.getNume() == trackName;
        });
        if (it != tracks.end()) {
            tracks.erase(it);
        }
    }

    void printTracks() const {
        int count = 1;
        for (const auto& track : tracks) {
            cout << count++ << ". " << track.getNume() << " - " << track.getDurata() << "s\n";
        }
    }

    int totalDuration() const {
        int total = 0;
        for (const auto& track : tracks) {
            total += track.getDurata();
        }
        return total;
    }

    bool operator<(const Albume& other) const {
        return an_aparitie < other.an_aparitie;
    }
};
