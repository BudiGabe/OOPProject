#pragma once
#include <string>
#include <iostream>

using namespace std;

class AudioRecording {
protected:
    string name;
    int length;
    double views;

public:
    AudioRecording(const string &name = "", int length = 0, double views = 0);
    AudioRecording(const AudioRecording& audioRec);

    const string &getName() const;
    void setName(const string &name);

    int getLength() const;
    void setLength(int length);

    double getViews() const;
    void setViews(double views);

    AudioRecording& operator=(const AudioRecording& audioRec);
    virtual ostream& virtualPrint(ostream& out) const;
    virtual istream& virtualRead(istream& in);
    friend ostream& operator<<(ostream& out, const AudioRecording& audioRec);
    friend istream& operator>>(istream& in, AudioRecording& audioRec);

    virtual void play() = 0;
};



