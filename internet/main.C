#include "lib.h"

int main() {

	int dim = righeNelFile();
	if ( dim == -1 ) {
		cout << "Problemi col file di dati!" << endl;
		return 1;
	} 
	if ( dim == 0 ) {
		cout << "File dati vuoto!" << endl;
		return 1;
	} 
	
	netpacket* S = new netpacket[dim];
	
	ofstream out;
	out.open( "risultati.dat" );
	
	int gp = caricaArrayRestBuoni( S, dim );
	
	cout << "\nNumero pacchetti caricati:\t\t" << dim << endl << endl;
	out  << "Numero pacchetti caricati:\t" << dim << endl << endl;
	cout << "Numero pacchetti di buona qualita':\t" << gp << endl << endl;
	out  << "Numero pacchetti di buona qualita':\t" << gp << endl << endl;
	cout << "Numero pacchetti di cattiva qualita':\t" << dim - gp << endl << endl;
	out  << "Numero pacchetti di cattiva qualita':\t" << dim - gp << endl << endl;
	
	sort( S, gp );

	cout << "\nPrimi cinque pacchetti dopo ordinamento" << endl;
        out << "\nPrimi cinque pacchetti dopo ordinamento" << endl;

	for ( int i = 0; i < 5; i++ ) {
		stampa( S[i] ); cout << endl;
		stampaFile( out, S[i] ); out << endl;
	}
	
        cout << "\nUltimi cinque pacchetti dopo ordinamento" << endl;
        out << "\nUltimi cinque pacchetti dopo ordinamento" << endl;

        for ( int i = gp - 5; i < gp; i++ ) {
                stampa( S[i] ); cout << endl;
                stampaFile( out, S[i] ); out << endl;
        }

	out.close();

	out.open( "messaggio.out" );

	cout << "\nMESSAGGIO FINALE" << endl;
        out << "MESSAGGIO FINALE" << endl;

	for ( int i = 0; i < gp; i++ ) {
		cout << car( S[i].data );
		out << car( S[i].data );
	}
	cout << endl;

	out.close();

	return 0;
}
