#include "server.hpp"
#include "utils.hpp"
#include <string>

using namespace std;

bool bad_pkt_pred(netpacket& a, netpacket&) {
	return a.db < 90.0;
}

netpacket* filter_bad_packets(netpacket*& pkts, int& len, int& bad_len) {
	inplace_selection_sort(pkts, len, bad_pkt_pred);
	int new_len = 0;
	for (int i=0; i<len; i++) {
		if (pkts[i].db < 90) {
			new_len = i;
			break;
		}
	}
	bad_len = len - new_len;

	netpacket* new_pkts = new netpacket[new_len];
	netpacket* bad_pkts = new netpacket[bad_len];

	for (int i=0; i<new_len; i++)
		new_pkts[i] = pkts[i];

	for (int i=0; i<bad_len; i++)
		bad_pkts[i] = pkts[new_len + i];

	delete[] pkts;
	pkts = new_pkts;
	len = new_len;

	return bad_pkts;
}

string compose_message(netpacket *pkts, int len) {
	string msg = "";
	char corrected_char;

	for (int i=0; i<len; i++) {
		switch (pkts[i].data) {
			case '?':
				corrected_char = '\n';
				break;
			case '#':
				corrected_char = ' ';
				break;
			default:
				corrected_char = pkts[i].data;
				break;
		}
		msg += corrected_char;
	}

	return msg;
}
