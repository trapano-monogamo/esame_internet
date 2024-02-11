#pragma once

#include "./common.hpp"
#include <string>

netpacket* filter_bad_packets(netpacket*& pkts, int& len, int& bad_len);

std::string compose_message(netpacket* pkts, int len);
