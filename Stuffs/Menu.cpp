#include "Menu.h"
#include <iostream>
#include <set>
#include <list>
#include "Song.h"
#include "Chord.h"
#include "TraditionalSong.h"
#include "Manelist.h"
#include <fstream>

using namespace std;


Menu* Menu::menu = nullptr;

Menu* Menu::getInstance() {
    if (!menu)
        menu = new Menu();

    return menu;
}

void Menu::open() {
    set<Song*> album;
    list<Chord> progression;

    int waitingForCommand = true;
    while (waitingForCommand) {
        cout << "\n1 Add random song to album";
        cout << "\n2 Add a traditional song";
        cout << "\n3 Print album";
        cout << "\n4 Find more about the countries";
        cout << "\n5 Delete album";
        cout << "\n6 Just give me a manea";
        cout << "\n7 Add a custom chord to your progression";
        cout << "\n8 Add a premade triad to your progression";
        cout << "\n9 Print chord progression";
        cout << "\n10 Print all chords from a key";
        cout << "\n11 Delete chord progression";
        cout << "\n12 Stop";

        int command;
        cin >> command;
        switch (command) {
            case 1: {
                string key;
                string tonality;
                int genre;

                cout << "\n Key: ";
                cin >> key;

                cout << "\n Tonality(ex. minor, maj)";
                cin >> tonality;

                cout << "\n1 Jazz";
                cout << "\n2 City Pop";
                cout << "\n3 Blues\n";
                cin >> genre;
                switch (genre) {
                    case 1: {
                        Song* song = new Song(Song::generateSong(key, tonality, Song::JAZZ, album.size() + 1));
                        album.insert(song);
                        break;
                    }
                    case 2: {
                        Song* song = new Song(Song::generateSong(key, tonality, Song::CITY_POP, album.size() + 1));
                        album.insert(song);
                        break;
                    }
                    case 3: {
                        Song* song = new Song(Song::generateSong(key, tonality, Song::BLUES, album.size() + 1));
                        album.insert(song);
                        break;
                    }
                }
                break;
            }
            case 2: {
                TraditionalSong* song = new TraditionalSong();
                cin >> *song;
                album.insert(song);
                break;
            }
            case 3: {
                ofstream out("album.txt");
                for (Song* song : album) {
                    out << *song;
                }
                out.close();
                break;
            }
            case 4: {
                for (Song* song: album) {
                    if(typeid(*song) == typeid(TraditionalSong)) {
                        dynamic_cast<TraditionalSong*>(song)->openWikiLink();
                    }
                }
                break;
            }
            case 5: {
                album.clear();
                break;
            }
            case 6: {
                Manelist manelist;
                manelist.playManea();
                break;
            }
            case 7: {
                Chord chord;
                cin >> chord;
                progression.push_back(chord);
                break;
            }
            case 8: {
                string root;
                string tonality;
                cout << "Root: ";
                cin >> root;
                cout << "Tonality(ex. minor, maj): ";
                cin >> tonality;
                progression.push_back(Chord::getTriad(root, tonality));
                break;
            }

            case 9: {
                ofstream out("progression.txt");
                for(const Chord& chord : progression) {
                    out << chord;
                }
                out.close();
                break;
            }
            case 10: {
                string root;
                string tonality;
                cout << "Root: ";
                cin >> root;
                cout << "Tonality(ex. minor, maj): ";
                cin >> tonality;
                map<int, Chord> keyMap = Chord::generateKeyChords(root, tonality);
                for(const auto& chord : keyMap) {
                    cout << chord.first << chord.second << endl;
                }
                break;
            }
            case 11: {
                progression.clear();
                break;
            }
            case 12: {
                waitingForCommand = false;
                break;
            }
        }
    }
}

Menu::Menu() = default;
