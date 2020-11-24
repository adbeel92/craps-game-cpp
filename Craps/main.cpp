//
//  main.cpp
//  Craps
//
//  Created by Eduardo Arenas on 24/11/20.
//

#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int numJugadores = 0;
    
    int primerTiroGana[] = { 7, 11 };
    int primerTiroPierde[] = { 2, 3, 12 };

    cout << "CRAPS!!!" << "\n\n";

    while (numJugadores < 1) {
        cout << "Introduce la cantidad de jugadores (>= 1)..." << "\n";
        scanf ("%d", &numJugadores);
    }
    
    for (int nJugador = 1; nJugador <= numJugadores; nJugador++) {
        cout << "\n\n" << "JUGANDO EL JUGADOR " << nJugador << "\n";
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

        bool gano = false;
        bool perdio = false;
        int turno = 1;
        int resultadoTurno1 = 0;
        
        while (!gano && !perdio) {
            cout << "Presione ENTER para Lanzar dados..." << "\n";
            cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

            int dado1 = rand() % (5) + 1;
            int dado2 = rand() % (5) + 1;
            int resultado = dado1 + dado2;
            cout << "Dado 1: " << dado1 << "\n";
            cout << "Dado 2: " << dado2 << "\n";
            cout << "Suman: " << resultado << "\n";
            
            if (turno == 1) {
                resultadoTurno1 = resultado;
                if (find(begin(primerTiroGana), end(primerTiroGana), resultado) != end(primerTiroGana)) {
                    gano = true;
                } else if (find(begin(primerTiroPierde), end(primerTiroPierde), resultado) != end(primerTiroPierde)) {
                    perdio = true;
                } else {
                    cout << "No perdió ni ganó. Para ganar, lance sus dados hasta sacar " << resultadoTurno1 << "\n";
                }
            } else {
                if (resultadoTurno1 == resultado) {
                    gano = true;
                } else if (resultado == 7) {
                    perdio = true;
                } else {
                    cout << "Inténtelo nuevamente. Para ganar debe sacar " << resultadoTurno1 << "\n";
                }
            }

            turno++;
        }

        if (gano) {
            cout << "EL JUGADOR " << nJugador << " GANÓ" << "\n";
        } else if (perdio) {
            cout << "EL JUGADOR " << nJugador << " PERDIÓ" << "\n";
        }
    }
    
    return 0;
}
