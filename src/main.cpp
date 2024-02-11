#include "common.hpp"
#include "io.hpp"
#include "server.hpp"
#include "utils.hpp"

#include <iostream>
using namespace std;

bool timestamp_pred(netpacket& a, netpacket& b) {
	return b.time < a.time;
}

int main() {
	int len;
	netpacket* pkts = load_from_file("./internet/pacchetti.dat", len);

	int bad_len;
	netpacket* bad_pkts = filter_bad_packets(pkts, len, bad_len);
	write_to_file("corrupt.out", bad_pkts, bad_len);

	inplace_selection_sort<netpacket>(pkts, len,
			[](netpacket& a, netpacket& b){ return b.time < a.time; });
	write_to_file("message.out", compose_message(pkts, len));

	for (int i=0; i<len; i++) {
		cout << pkts[i].time << ", " << pkts[i].db << ", " << pkts[i].data << endl;
	}

	return 0;
}
