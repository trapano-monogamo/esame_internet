#include "lib.h"

int righeNelFile() {
	ifstream in;
	in.open( "pacchetti.dat" );
	if ( in.fail() )
		return -1;
	string s;
	int k = 0;
	getline( in, s );
	while ( !in.eof() ) {
		k++;
		getline( in, s );
	}
	in.close();
	return k;
}

void stampa( netpacket p ) {
	cout << "tempo = " << p.time << "\tdecibel = " << p.db << "\tcarattere = " << p.data;
}

void stampaFile( ofstream& out, netpacket p ) {
	out << "tempo = " << p.time << "\tdecibel = " << p.db << "\tcarattere = " << p.data;
}

int caricaArrayRestBuoni( netpacket* X, int dim ) {
	ifstream in;
	in.open( "pacchetti.dat" );
	ofstream out;
	out.open( "corrotti.out" );
	out << "PACCHETTI CORROTTI" << endl;
	netpacket p;
	int i = 0, t = dim - 1;
	while ( i <= t ) {
		in >> p.time >> p.db >> p.data;
		if ( p.db < 90 ) {
			stampaFile( out, p ); out << endl;
			X[t] = p;
			t--;
		}
		else {
			X[i] = p;
			i++;
		}
	}
	in.close();
	out.close();
	return i;
}

void swap( netpacket& x, netpacket& y ) {
	netpacket t = x;
	x = y;
	y = t;
}

void sort( netpacket* X, int dim ) {
	for ( int i = 0; i < dim - 1; i++ )
		for ( int j = i + 1; j < dim; j++ )
			if ( X[j].time < X[i].time )
				swap( X[i], X[j] );
}


char car( char c ) {
	return c == '#' ? ' ' : ( c == '?' ? '\n' : c );
}
