#include "Track.h"
int Track::pozitie = 0;

Track::Track(string n, int d):nume(n), durata(d)
    {
        pozitie++;
    }
