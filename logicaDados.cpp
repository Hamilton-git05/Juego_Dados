#include <iostream>
#include <clocale>

using namespace std;


bool menosDeSeisDadosIguales(int dados[]){
    int frecuencia[7] = {0};

    for (int i = 0; i < 6; ++i) {
        frecuencia[dados[i]]++;
    }

    for (int i = 1; i <= 6; ++i) {
        //Si todos los dados son iguales, no cumple.
        if (frecuencia[i] >= 6) {
            return false;
        }
    }

    return true;
}

bool esSextetoX(int dados[]){
    int i, contSexteto = 1;
    int dadoAnterior = dados[0];

    for (i=1; i<6; i++){
        if(dadoAnterior == dados[i] && dados[i] != 6){
            contSexteto++;
        }
        dadoAnterior = dados[i];
    }

    return (contSexteto == 6);
}

bool esEscalera(int dados[]) {
    // 3 4 1 2 5 6
    int i, contador[7] = {0};

    for (i = 0; i<6; i++){
        contador[dados[i]]++;
    }

    for (i = 1; i<= 6; i++){

        if (contador[i] != 1){
            // Si esto es falso, significa que hubo mas de 1 dado con el mismo valor, o que ese dado salio, por lo tanto no es escalera.
            return false;
        }
    }

    return true;
}

bool esSexteto6(int dados[]){
    int i, cont = 0;
//  6 6 6 6 6 6
    for(i=0; i<6; i++){
        if(dados[i] == 6){
            cont++;
        }
    }

    if(cont == 6){
        return true;
    }
    return false;
}

bool lanzarDados(int dados[]){
    int i;
    for(i=0; i<6; i++){
        dados[i] = (rand() % 6) + 1;
    }
    return true;
}

void ingresarDados(int dados[]){
    system("cls");
    cout << "MODO SIMULADO" << endl;

    for(int i=0; i<6; i++){
        cout << "VALOR DEL DADO #" << i+1 << ": ";
        cin >> dados[i];
    }
    system("cls");
}


int determinarPuntajeRonda(int dados[], int &combinacion){
    int puntosLanzamiento = 0;

    /*
    //Hardcodeada para testing
    for (int x=0; x<6; x++){
        dados[x] = x+1;
    }

    */
    if(menosDeSeisDadosIguales(dados)){
        combinacion = 1;
        for(int j=0; j<6; j++){
            puntosLanzamiento+=dados[j];
        }
    }
    if(esSextetoX(dados)){

        combinacion = 2;
        puntosLanzamiento = dados[3] * 10;
    }
    if(esEscalera(dados)){
        combinacion = 3;
        return 100; // GANO EL JUEGO, HIZO ESCALERA.
    }
    if(esSexteto6(dados)){
        combinacion = 4;
    }

    return puntosLanzamiento;

}

