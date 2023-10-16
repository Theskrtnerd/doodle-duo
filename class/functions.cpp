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
        {"black", sf::Color::Black},
        {"cyan", sf::Color::Cyan},
        {"magenta", sf::Color::Magenta},
        {"yellow", sf::Color::Yellow},
        {"white", sf::Color::White}
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

void generateLevelMenu(int max_level){
    std::map<int, std::tuple<int, int, int, int, int, int>> objectMap;

    objectMap[1] = std::make_tuple(460,270,275,280,235,240);
    objectMap[2] = std::make_tuple(860,270,675,280,635,240);
    objectMap[3] = std::make_tuple(460,420,275,430,235,390);
    objectMap[4] = std::make_tuple(860,420,675,430,635,385);
    objectMap[5] = std::make_tuple(460,570,275,575,235,540);
    objectMap[6] = std::make_tuple(860,570,675,575,635,540);


    std::ifstream inputFile("assets/screens/baseLevelMenu.json");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input JSON file." << std::endl;
    }

    Json::Value jsonData;
    inputFile >> jsonData;
    inputFile.close();

    // Define Black Tick Object
    Json::Value BlackTick;
    BlackTick["type"] = "ScreenButton";
    BlackTick["texture"] = "BlackTick.png";
    BlackTick["action"] = "doNothing";

    // Define Level Text Object
    Json::Value LevelText;
    LevelText["type"] = "Text";
    LevelText["colour"] = "black";
    LevelText["fontSize"] = 36;

    // Define Level Box Object
    Json::Value LevelBox;
    LevelBox["type"] = "ScreenButton";
    LevelBox["texture"] = "RectangleBox.png";

    for (int i =1;i<=max_level;i++){

        if(i > 1){
            std::tuple<int,int,int,int,int,int> value = objectMap[i-1];
            BlackTick["x"] = std::get<0>(value);
            BlackTick["y"] = std::get<1>(value);
            jsonData.append(BlackTick);
        }

        if(i!=7){
            std::tuple<int,int,int,int,int,int> value = objectMap[i];
            LevelText["text"] = "Level "+std::to_string(i);
            LevelText["x"] = std::get<2>(value);
            LevelText["y"] = std::get<3>(value);
            jsonData.append(LevelText);

            LevelBox["action"] = "setLevel"+std::to_string(i);
            LevelBox["x"] = std::get<4>(value);
            LevelBox["y"] = std::get<5>(value);
            jsonData.append(LevelBox);
        }
    }

    Json::Value newObject;
    newObject["type"] = "Background";
    newObject["texture"] = "GameBackground.png";
    jsonData.append(newObject);
    

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

void updateCurrentLevel(int newLevel) {
    Json::CharReaderBuilder reader;
    Json::Value root;
    std::string filename = "user_data.json";
    std::ifstream file(filename, std::ifstream::binary);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open the JSON file." << std::endl;
        return;  // Change to void, so we just return without a value
    }
    
    Json::String errs;
    if (Json::parseFromStream(reader, file, &root, &errs)) {
        // Update the 'currentLevel' field
        root["currentLevel"] = newLevel;
        
        // Write the updated JSON back to the file
        std::ofstream outFile(filename, std::ofstream::binary);
        
        if (!outFile.is_open()) {
            std::cerr << "Failed to open the JSON file for writing." << std::endl;
            return;  // Change to void, so we just return without a value
        }
        
        Json::StreamWriterBuilder writer;
        std::string jsonString = Json::writeString(writer, root);
        outFile << jsonString;
        outFile.close();
    } else {
        std::cerr << "Failed to parse the JSON file: " << errs << std::endl;
        return;  // Change to void, so we just return without a value
    }
}