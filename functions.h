#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <json/json.h>
#include <string>
#include <iostream>
#include <fstream>

Json::Value readJSONFile(const std::string& filePath);

#endif