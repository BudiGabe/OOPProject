#pragma once

#include <ostream>
#include "Sound.h"
#include <iostream>

class Note: public Sound{
private:
    int frequency;
    int volume;

public:
    Note(int frequency, int volume);
    Note(const Note& note);
    ~Note();

    int getFrequency() const;
    void setFrequency(int frequency);

    int getVolume() const;
    void setVolume(int volume);

    Note& operator=(const Note& note);
    friend std::ostream &operator<<(std::ostream &os, const Note &note);
    friend std::istream &operator>>(std::istream &is, Note &note);

    void calculateInterval(Note note);
};


