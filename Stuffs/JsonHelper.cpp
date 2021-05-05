#include "JsonHelper.h"

/*
 * Get all YouTube IDs from manele json
 */
vector<string> JsonHelper::getYoutubeIds(const string& jsonPath, const string& regexPattern) {
    ifstream jsonFile(jsonPath);
    smatch matches;
    regex r(regexPattern);
    string idLine;
    vector<string> youtubeIds;

    while(getline(jsonFile, idLine)) {
        regex_search(idLine, matches, r);
        for(string match : matches) {
            // Cut the "" from each end
            match = match.substr(1, match.size() - 2);
            youtubeIds.push_back(match);
        }
    }

    jsonFile.close();
    return youtubeIds;
}