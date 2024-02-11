#pragma once
#include "common.hpp"

#include <string>

netpacket* load_from_file(const char* filename, int& len);

void write_to_file(const char* filename, netpacket* data, int len);
void write_to_file(const char* filename, std::string data);
