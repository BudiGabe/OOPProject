#include "AudioRecording.h"

const string &AudioRecording::getName() const {
    return name;
}

void AudioRecording::setName(const string &name) {
    AudioRecording::name = name;
}

int AudioRecording::getLength() const {
    return length;
}

void AudioRecording::setLength(int length) {
    AudioRecording::length = length;
}

double AudioRecording::getViews() const {
    return views;
}

void AudioRecording::setViews(double views) {
    AudioRecording::views = views;
}

AudioRecording::AudioRecording(const string &name, int length, double views) : name(name), length(length), views(views) {}

AudioRecording::AudioRecording(const AudioRecording& audioRec) {
    this->name = audioRec.name;
    this->views = audioRec.views;
    this->length = audioRec.length;
}

AudioRecording &AudioRecording::operator=(const AudioRecording &audioRec) {
    if(this == &audioRec) {
        return *this;
    }

    this->name = audioRec.name;
    this->views = audioRec.views;
    this->length = audioRec.length;

    return *this;
}

ostream &AudioRecording::virtualPrint(ostream &out) const {
    out << "\nName: " << name << "\nViews: " << views << "\nLength: " << length;
    return out;
}

istream &AudioRecording::virtualRead(istream &in) {
    cout << "\nName: ";
    in >> name;

    cout << "\nViews: ";
    in >> views;

    cout << "\nLength: ";
    in >> length;

    return in;
}

ostream &operator<<(ostream &out, const AudioRecording &audioRec) {
    return audioRec.virtualPrint(out);
}

istream &operator>>(istream &in, AudioRecording &audioRec) {
    return audioRec.virtualRead(in);
}












