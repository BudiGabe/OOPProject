cmake_minimum_required(VERSION 3.17)
project(OOPProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(OOPProject
        main.cpp
        Stuffs/Chord.cpp
        Stuffs/Chord.h
        Stuffs/Song.cpp
        Stuffs/Song.h
        Stuffs/Podcast.cpp
        Stuffs/Podcast.h
        Stuffs/Artist.cpp
        Stuffs/Artist.h
        Stuffs/RandomHelper.cpp
        Stuffs/RandomHelper.h
        Google_tests/ChordTest.cpp
        Google_tests/SongTest.cpp
        Google_tests/RandomGeneratorsTest.cpp Stuffs/TraditionalSong.cpp Stuffs/TraditionalSong.h Stuffs/Manelist.cpp Stuffs/Manelist.h Stuffs/JsonHelper.cpp Stuffs/JsonHelper.h Stuffs/AudioRecording.cpp Stuffs/AudioRecording.h Stuffs/Sound.cpp Stuffs/Sound.h Stuffs/Note.cpp Stuffs/Note.h)

add_subdirectory(Google_tests)
#include googletest/include dir
include_directories(Google_tests/googletest/include)

#include the googlemock/include dir
include_directories(Google_tests/googlemock/include)

#Link with GoogleTest
target_link_libraries(OOPProject gtest gtest_main)

#Link with GoogleMock
target_link_libraries(OOPProject gmock gmock_main)
