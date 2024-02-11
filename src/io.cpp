#include "./io.hpp"

#include <fstream>
#include <string>
using namespace std;

netpacket* load_from_file(const char* filename, int& len) {
	ifstream f(filename);
	string line;
	len = 0;
	while (getline(f, line)) { len++; }

	f.close(); f.open(filename);

	netpacket* pkts = new netpacket[len];
	for (int i=0; i<len; i++) {
		f >> pkts[i].time >> pkts[i].db >> pkts[i].data;
	}

	return pkts;
}

void write_to_file(const char *filename, netpacket* data, int len) {
	ofstream f(filename);
	for (int i=0; i<len; i++) {
		f << data[i].time << ", " << data[i].db << ", " << data[i].data << endl;
	}
}

void write_to_file(const char *filename, string data) {
	ofstream f(filename);
	f << data;
}
