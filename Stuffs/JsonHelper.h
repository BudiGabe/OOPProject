#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <iostream>

using namespace::std;


class JsonHelper {
public:
    static vector<string> getYoutubeIds(const string& jsonPath, const string& regexPattern);
};


