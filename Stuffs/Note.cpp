//
// Created by Budi on 11-Apr-21.
//

#include "Note.h"

int Note::getFrequency() const {
    return frequency;
}

void Note::setFrequency(int frequency) {
    Note::frequency = frequency;
}

int Note::getVolume() const {
    return volume;
}

void Note::setVolume(int volume) {
    Note::volume = volume;
}

Note::Note(int frequency, int volume) : frequency(frequency), volume(volume) {}

Note::~Note() {

}

Note::Note(const Note &note) {
    this->frequency = note.frequency;
    this->volume = note.volume;
}

Note &Note::operator=(const Note &note) {
    if(this == &note) {
        return *this;
    }

    this->volume = note.volume;
    this->frequency = note.frequency;
}

std::ostream &operator<<(std::ostream &os, const Note &note) {
    os <<"\nFrequency: " << note.frequency << "/nVolume: " << note.volume;
    return os;
}

std::istream &operator>>(std::istream &is, Note &note) {
    std::cout <<"\nFrequency: ";
    is >> note.frequency;

    std::cout <<"\nVolume: ";
    is >> note.volume;

    return is;
}

void Note::calculateInterval(Note note) {
    float ratio = (float)this->frequency / note.frequency;

    if(ratio == 1) {
        std::cout << "P1";
        return;
    }

    if(ratio == (16.0/15.0)) {
        std::cout << "m2";
        return;
    }

    if(ratio == (9.0/8.0)) {
        std::cout << "M2";
        return;
    }

    if(ratio == 6.0/5.0) {
        std::cout << "m3";
        return;
    }

    if(ratio == 5.0/4.0) {
        std::cout << "M3";
        return;
    }

    if(ratio == 4.0/3.0) {
        std::cout << "P4";
        return;
    }

    if(ratio == 45.0/32.0 || ratio == 25.0/18.0) {
        std::cout << "TT";
        return;
    }

    if(ratio == 3.0/2.0) {
        std::cout << "P5";
        return;
    }

    if(ratio == 8.0/5.0) {
        std::cout << "m6";
        return;
    }

    if(ratio == 5.0/3.0) {
        std::cout << "M6";
        return;
    }

    if(ratio == 16.0/9.0) {
        std::cout << "m7";
        return;
    }

    if(ratio == 15.0/8.0) {
        std::cout << "M7";
        return;
    }

    if(ratio == 2) {
        std::cout << "Octave";
        return;
    }

    std::cout << "\nNot an interval defined in western music theory";
}

