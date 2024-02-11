#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct netpacket {
	int time;
	double db;
	char data;
};

int righeNelFile();
void stampa( netpacket );
void stampaFile( ofstream&, netpacket );
int caricaArrayRestBuoni( netpacket* X, int dim );
void swap( netpacket&, netpacket& );
void sort( netpacket*, int );
char car( char );
