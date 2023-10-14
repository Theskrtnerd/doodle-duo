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

sf::Color stringToColor(const std::string& color)
{
    static std::unordered_map<std::string, sf::Color> colorMap =
    {
        {"red", sf::Color::Red},
        {"blue", sf::Color::Blue},
        {"green", sf::Color::Green},
        {"black", sf::Color::Black}
    };

    if (colorMap.find(color) != colorMap.end())
    {
        return colorMap[color];
    }
    
    std::cout << "'" << color << "' not in colorMap in 'functions.cpp' Line 30" << std::endl;

    return sf::Color::White;
}


sf::Font stringToFont(const std::string& fontPath)
{
    std::string file_path = GetParentPath() + fontPath;
    
    // Check if the file exists
    if (!std::filesystem::exists(file_path)) {
        throw std::runtime_error("File not found: " + file_path);
    }
    
    
    sf::Font font;

    if (!font.loadFromFile(file_path)) {
        throw std::runtime_error("Failed to load font from: " + fontPath);
    }

    return font;
}

std::string GetParentPath() {
    // Get the path to the executable.
    std::filesystem::path exePath = std::filesystem::canonical(std::filesystem::path("/proc/self/exe"));

    // Get the parent directory (DoodleDuo directory).
    std::filesystem::path parentPath = exePath.parent_path();

    // Convert the path to a string and return it.
    //return "C:/Users/Tyler/Documents/GitHub/DoodleDuo/";
    return parentPath.string()+"/";
}

void generateGreenTicksForLevelMenu(int current_level){
    std::map<int, std::tuple<int, int>> objectMap;

    objectMap[1] = std::make_tuple(460, 270);
    objectMap[2] = std::make_tuple(460, 420);
    objectMap[3] = std::make_tuple(460, 570);
    objectMap[4] = std::make_tuple(860, 270);
    objectMap[5] = std::make_tuple(860, 420);
    objectMap[6] = std::make_tuple(860, 570);

    std::ifstream inputFile("assets/screens/levelMenu.json");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input JSON file." << std::endl;
    }

    Json::Value jsonData;
    inputFile >> jsonData;
    inputFile.close();
    for (int i =1;i<=current_level;i++){
        // Create a new object to add
        Json::Value newObject;
        std::tuple<int,int> value = objectMap[i];
        newObject["type"] = "ScreenButton";
        newObject["texture"] = "BlackTick.png";
        newObject["action"] = "doNothing";
        newObject["x"] = std::get<0>(value);
        newObject["y"] = std::get<1>(value);

        // Append the new object to the existing JSON array
        jsonData.append(newObject);

        std::cout << "added object number "+std::to_string(i) + " into game" << std::endl;
    }


    // Write the updated JSON data back to the file
    std::ofstream outputFile("assets/screens/levelMenu.json");

    if (!outputFile.is_open()) {
        std::cerr << "Failed to open the output JSON file." << std::endl;
    }

    Json::StreamWriterBuilder writer;
    writer["indentation"] = "\t";

    std::unique_ptr<Json::StreamWriter> jsonWriter(writer.newStreamWriter());
    jsonWriter->write(jsonData, &outputFile);
    outputFile.close();
}