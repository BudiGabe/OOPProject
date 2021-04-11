#pragma once

class Note;
class Sound {
public:
    /*
     * Names the interval between notes.
     * Interval names are based on the ratio of the 2 frequencies.
     * Based on https://en.wikipedia.org/wiki/Interval_(music)#Size_of_intervals_used_in_different_tuning_systems
     */
    virtual void calculateInterval(Note note) = 0;
};