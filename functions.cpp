#include "functions.h"

// Function to read and parse a JSON file
Json::Value readJSONFile(const std::string& filePath) {
    Json::CharReaderBuilder reader;
    Json::Value root;
    std::string errors;

    std::ifstream jsonFile(filePath);

    if (!jsonFile.is_open()) {
        std::cerr << "Error opening JSON file: " << filePath << std::endl;
        // You can handle this error in your own way, e.g., by returning an empty Json::Value.
        // Alternatively, you can throw an exception to indicate an error.
    }

    // Parse the JSON file
    if (!Json::parseFromStream(reader, jsonFile, &root, &errors)) {
        std::cerr << "Error parsing JSON file: " << errors << std::endl;
        // You can handle this error in your own way, e.g., by returning an empty Json::Value.
        // Alternatively, you can throw an exception to indicate an error.
    }

    jsonFile.close();
    return root;
}



