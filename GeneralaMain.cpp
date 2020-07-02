#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
#include "FuncionesGenerala.h"
#include "rlutil.h"




int main() {
    int opcion, i, dados[5], puntuacionTotaljug1 = 0, contar[5], lanzamientos, lanzar = 0, elegirdado = 0, puntuacion, puntuacion2;
    int puntuacionTotaljug2 = 0, puntuacionTotalSolitario = 0, MaximaPuntuacion = 0, TurnosDeMaximaPuntuacion = 0, casos;
    bool bandera5 = true, prueba = false, bandera6 = false, cicloinfinito = true, Band_MayPun = true,CasoSinGeneralaSolo=true;
    char nombre[20], decision, jugador1[20], jugador2[20], NombreMaxPun[20];

    bool turnos = true;
    bool finjuego = false;
    bool tiroDeGracia = false;




    rlutil::setBackgroundColor(rlutil::BLACK);

    while (cicloinfinito) {


        rlutil::setBackgroundColor(rlutil::BLACK);
        casos = MenuPrincipalGenerala(); //LLamamos al menu Principal

        i = 1; puntuacion = 0;

        switch (casos) {



        case 18:
            system("cls");
            puntuacionTotalSolitario = 0;
            cout << "Ingrese su nombre:  " << endl;
            cin >> nombre;
            for (i = 1; i <= 10; i++) {
                lanzamientos = 1;
                system("cls");

                if (prueba == false) {
                    cargarAleatorio(dados, 5, 6);//En este caso es para agregar valores aleatorios
                }
                else {
                    cargarVector(dados, 5); //En este caso es para agregar los valores manualmente
                    system("pause");
                    system("cls");
                }
                cout << "TURNO DE:  " << nombre << " | RONDA NRO:" << i << " | PUNTOS TOTALES:  " << puntuacionTotalSolitario << endl;
                cout << "LANZAMIENTO NR0: " << lanzamientos << endl;

                contarRepetidos(dados, 5, contar); // Funcion esencial antes de la funcion "MenuDePuntos"
                puntuacion = MenuDePuntos(dados, contar); //De aca sacamos la puntuacion

                MenuDeDados(dados); cout << "\n" << "\n" << endl << endl << endl;
                

                puntuacionTotalSolitario += puntuacion;// Acumulador de puntuaciones

                cout << "PUNTUACION:  " << puntuacion << endl;//Mostramos la puntuacion
                if (lanzamientos == 1 && puntuacion == 50) {
                    lanzamientos = 3; TurnosDeMaximaPuntuacion = i; i = 10; system("cls");
                    Gana(puntuacion, puntuacionTotalSolitario); //Este IF es en el caso de que saque generala servida
                    CasoSinGeneralaSolo = false; //Bandera para no mostrar 2 veces el mismo mensaje
                    system("pause");
                    system("cls");
                }
                else { TurnosDeMaximaPuntuacion = i; } //Por defecto da 10, si saca generala servida cambia de valor

                while (lanzamientos != 3) {
                    cout << endl;
                    cout << "¿Tirar nuevamente?(S/N)" << endl; //Pregunta que aparece 2 veces maximo
                    cin >> decision; //Ingresa SI O NO


                    if (decision == 'S'|| decision== 's') {
                        puntuacionTotalSolitario = puntuacionTotalSolitario - puntuacion; //Resto la puntuacion ya que va a cambiar al tirar nuevamente uno o mas dados
                        lanzamientos++; //Este contador sirve para que el jugador no sobrepase los 2 lanzamientos
                        cout << "LANZAMIENT0 NRO: " << lanzamientos << endl;

                        cout << "¿Cuantos?" << endl;
                        cin >> lanzar; //Ingresa la cantidad de dados que desea modificiar el jugador
                        for (int x = 0; x < lanzar; x++) { //For que va a dar tantas vueltas como dados elige el usuario
                            cout << "¿Cual?" << endl;
                            cin >> elegirdado;
                            cout << endl;
                            elegirdado = elegirdado - 1; //El -1 es para que dentro del vector seleccione el correcto(comienzan en 0 los vectores)
                            NumeroAleatorio(dados, 6, elegirdado);//Doy valor aleatorio al dado que elige el jugador
                            contarRepetidos(dados, 5, contar); //Funcion esencial antes de la funcion "MenuDePuntos"
                            puntuacion = MenuDePuntos(dados, contar); //Consigo los puntos actualizados luego de tirar nuevamente los dados
                        }
                        system("cls");
                        cout << "TURNO DE:  " << nombre << " | RONDA NRO:" << i << " | PUNTOS TOTALES:  " << puntuacionTotalSolitario << endl;
                        cout << "LANZAMIENTO NR0: " << lanzamientos << endl;
                            MenuDeDados(dados); //Con esto mostramos los dados graficamente


                            cout << "\n" << endl << endl;
                            cout << "PUNTUACION:  " << puntuacion << endl;
                            puntuacionTotalSolitario += puntuacion; //Acumulo con los puntos actualizados

                            system("pause");




                    }
                    else {
                        lanzamientos = 3; //Forzamos a que termine el ciclo while
                    }
                }


            }//for
            if (CasoSinGeneralaSolo == true) {
                system("pause");
                system("cls");
                Gana(puntuacion, puntuacionTotalSolitario);
                system("pause");
                system("cls");
            }



                    system("cls");


                Band_MayPun = false;




                ; break;
        case 19:
            puntuacionTotaljug1 = 0; puntuacionTotaljug2 = 0;
            system("cls");

            cout << "Ingrese nombre del primer jugador: " << endl;
            cin >> jugador1;

            cout << "Ingrese nombre del segundo jugador:  " << endl;
            cin >> jugador2;



            for (int j = 1; j <= 10; j++) {

                if (turnos == true) {

                    system("cls");


                    rlutil::locate(45, 16);   cout << "TURNO DE: " << jugador1 << endl;
                    PasoDeTurno();
                    rlutil::locate(45, 18);  cout << "RONDA NUMERO:  " << j << endl;
                    rlutil::locate(45, 19);  cout << "Los puntos del jugador " << jugador1 << " son:  " << puntuacionTotaljug1 << endl;
                    rlutil::locate(45, 20);  cout << "Los puntos del jugador " << jugador2 << " son:  " << puntuacionTotaljug2 << endl;
                    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                    system("pause");

                    system("cls");

                    lanzamientos = 1;

                    if (prueba == false) {
                        cargarAleatorio(dados, 5, 6);//En este caso es para agregar valores aleatorios
                    }
                    else {
                        cargarVector(dados, 5); //En este caso es para agregar los valores manualmente
                    }


                    cout << "TURNO DE:  " << jugador1 << " | RONDA NRO: " << j << " | PUNTOS TOTALES:  " << puntuacionTotaljug1 << endl;
                    cout << "LANZAMIENTO NR0: " << lanzamientos << endl;


                    contarRepetidos(dados, 5, contar);                                  // Funcion esencial antes de la funcion "MenuDePuntos"
                    puntuacion = MenuDePuntos(dados, contar);                           //De aca sacamos la puntuacion

                    MenuDeDados(dados); cout << "\n"<<"\n"<<endl<<endl<<endl<<endl<<endl<<endl;

                    if (lanzamientos == 1 && puntuacion == 50) {
                        lanzamientos = 3; TurnosDeMaximaPuntuacion = j, j = 10;
                    }

                    puntuacionTotaljug1 += puntuacion;                                      // Acumulador de puntuaciones
                    cout << "PUNTUACION:  " << puntuacion << endl;                      //Mostramos la puntuacion


                    while (lanzamientos != 3) {


                        cout << "¿Tirar nuevamente?(S/N)" << endl; //Pregunta que aparece 2 veces maximo
                        cin >> decision; //Ingresa SI O NO

                        if (decision == 'S'|| decision== 's') {
                            puntuacionTotaljug1 = puntuacionTotaljug1 - puntuacion; //Resto la puntuacion ya que va a cambiar al tirar nuevamente uno o mas dados

                            lanzamientos++; //Este contador sirve para que el jugador no sobrepase los 2 lanzamientos
                            cout << "LANZAMIENT0 NRO: " << lanzamientos << endl;

                            cout << "¿Cuantos?" << endl;
                            cin >> lanzar; //Ingresa la cantidad de dados que desea modificiar el jugador
                            for (int x = 0; x < lanzar; x++) { //For que va a dar tantas vueltas como dados elige el usuario
                                cout << "¿Cual?" << endl;
                                cin >> elegirdado;
                                cout << endl;
                                elegirdado = elegirdado - 1; //El -1 es para que dentro del vector seleccione el correcto(comienzan en 0 los vectores)
                                NumeroAleatorio(dados, 6, elegirdado);//Doy valor aleatorio al dado que elige el jugador
                            }

                            contarRepetidos(dados, 5, contar); //Funcion esencial antes de la funcion "MenuDePuntos"
                            puntuacion = MenuDePuntos(dados, contar); //Consigo los puntos actualizados luego de tirar nuevamente los dados
                            system("cls");

                            cout << "TURNO DE:  " << jugador1 << " | RONDA NRO: " << j << " | PUNTOS TOTALES:  " << puntuacionTotaljug1 << endl;
                            cout << "LANZAMIENTO NR0: " << lanzamientos << endl;

                            puntuacionTotaljug1 += puntuacion; //Acumulo con los puntos actualizados
                            MenuDeDados(dados);

                            cout << "\n"<<endl<<endl<<endl;
                            cout << "PUNTUACION:  " << puntuacion << endl;
                            cout << endl;





                        }//TIRAR

                        else {
                            lanzamientos = 3; //Forzamos a que termine el ciclo while

                        }


                    }//WHILE



                    if (puntuacion == 50 && j == 10) { tiroDeGracia = true; }

                } // IF TURNOS
                turnos = false;


                if (turnos == false) {
                    system("cls");


                    rlutil::locate(45, 17); cout << "Turno de: " << jugador2 << endl;

                    PasoDeTurno();
                    rlutil::locate(45, 19); cout << "Los puntos del jugador " << jugador1 << " son:  " << puntuacionTotaljug1 << endl;
                    rlutil::locate(45, 20); cout << "Los puntos del jugador " << jugador2 << " son:  " << puntuacionTotaljug2 << endl;
                    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                    system("pause");
                    system("cls");

                    lanzamientos = 1;

                    if (prueba == false) {
                        cargarAleatorio(dados, 5, 6);//En este caso es para agregar valores aleatorios
                    }
                    else {
                        cargarVector(dados, 5); //En este caso es para agregar los valores manualmente
                    }

                    cout << "TURNO DE:  " << jugador2 << " | RONDA NRO: " << j << " | PUNTOS TOTALES:  " << puntuacionTotaljug2 << endl;
                    cout << "LANZAMIENTO NR0: " << lanzamientos << endl;


                    contarRepetidos(dados, 5, contar);                                  // Funcion esencial antes de la funcion "MenuDePuntos"
                    puntuacion2 = MenuDePuntos(dados, contar);                           //De aca sacamos la puntuacion

                    MenuDeDados(dados); cout << "\n"<<"\n"<<endl<<endl<<endl<<endl<<endl<<endl;

                    puntuacionTotaljug2 += puntuacion2;        // Acumulador de puntuaciones
                    if (lanzamientos == 1 && puntuacion2 == 50 && tiroDeGracia == false) {
                        system("cls"); GanaModo2jug(puntuacion2, puntuacionTotaljug2, jugador2); system("pause"); lanzamientos = 3; TurnosDeMaximaPuntuacion = j; j = 10;
                        system("cls");
                    }
                    else { TurnosDeMaximaPuntuacion = j; }

                    cout << "PUNTUACION:  " << puntuacion2 << endl;                      //Mostramos la puntuacion

                    if (j == 10 && puntuacion2 == 50 && tiroDeGracia == true) { system("cls"); cout << "Empate" << endl; system("pause"); lanzamientos = 3; system("cls"); }
                    if (j == 10 && puntuacion2 != 50 && tiroDeGracia == true) { system("cls"); GanaModo2jug(puntuacion, puntuacionTotaljug1, jugador1); system("pause"); lanzamientos = 3; system("cls"); }

                    while (lanzamientos != 3) {
                        cout << "¿Tirar nuevamente?(S/N)" << endl; //Pregunta que aparece 2 veces maximo
                        cin >> decision; //Ingresa SI O NO

                        if (decision == 'S'|| decision== 's') {

                            lanzamientos++; //Este contador sirve para que el jugador no sobrepase los 2 lanzamientos
                            cout << "LANZAMIENT0 NRO: " << lanzamientos << endl;
                            puntuacionTotaljug2 = puntuacionTotaljug2 - puntuacion2; //Resto la puntuacion ya que va a cambiar al tirar nuevamente uno o mas dados
                            cout << "¿Cuantos?" << endl;
                            cin >> lanzar; //Ingresa la cantidad de dados que desea modificiar el jugador
                            for (int x = 0; x < lanzar; x++) { //For que va a dar tantas vueltas como dados elige el usuario
                                cout << "¿Cual?" << endl;
                                cin >> elegirdado;
                                cout << endl;
                                elegirdado = elegirdado - 1; //El -1 es para que dentro del vector seleccione el correcto(comienzan en 0 los vectores)
                                NumeroAleatorio(dados, 6, elegirdado);//Doy valor aleatorio al dado que elige el jugador
                            }

                            contarRepetidos(dados, 5, contar); //Funcion esencial antes de la funcion "MenuDePuntos"
                            puntuacion2 = MenuDePuntos(dados, contar); //Consigo los puntos actualizados luego de tirar nuevamente los dados
                            system("cls");
                            cout << "TURNO DE:  " << jugador2 << " | RONDA NRO: " << j << " | PUNTOS TOTALES:  " << puntuacionTotaljug2 << endl;
                            cout << "LANZAMIENTO NR0: " << lanzamientos << endl;

                            puntuacionTotaljug2 += puntuacion2; //Acumulo con los puntos actualizados
                            MenuDeDados(dados);
                            cout << "\n"<<endl<<endl<<endl;
                            cout << "PUNTUACION:  " << puntuacion2 << endl;


                        }//TIRAR

                        else {
                            lanzamientos = 3; //Forzamos a que termine el ciclo while

                        }


                    }//WHILE



                    turnos = true;
                }


                Band_MayPun = false;

            }//FOR

            if (puntuacionTotaljug1 != 50 && puntuacionTotaljug2 != 50) {
                if (puntuacionTotaljug1>puntuacionTotaljug2) {
                    GanaModo2jug(puntuacion,puntuacionTotaljug1,jugador1);
                    system("pause");
                    system("cls");
                }
                else { GanaModo2jug(puntuacion2, puntuacionTotaljug2, jugador2);
                system("pause");
                system("cls");
                }
            }
            ; break;


        case 20:
            system("cls");

            if (Band_MayPun == true) { cout << "Aun no se han jugado partidas, debe finalizar un modo para obtenerla" << endl; }
            else {
                if (puntuacionTotalSolitario > puntuacionTotaljug1 && puntuacionTotalSolitario > puntuacionTotaljug2 && puntuacionTotalSolitario > MaximaPuntuacion) { MaximaPuntuacion = puntuacionTotalSolitario; NombreMaximo(nombre, NombreMaxPun); cout << "La maxima puntuacion es de " << nombre << " con un total de " << MaximaPuntuacion << " en " << TurnosDeMaximaPuntuacion << " tiros" << endl; }
                else {
                    if (puntuacionTotaljug1 > puntuacionTotalSolitario && puntuacionTotaljug1 > puntuacionTotaljug2 && puntuacionTotaljug1 > MaximaPuntuacion) { MaximaPuntuacion = puntuacionTotaljug1; NombreMaximo(jugador1, NombreMaxPun); cout << "La maxima puntuacion es de " << jugador1 << " con un total de " << MaximaPuntuacion << " en " << TurnosDeMaximaPuntuacion << " tiros" << endl; }
                    else {
                        if (puntuacionTotaljug2 > puntuacionTotalSolitario && puntuacionTotaljug2 > puntuacionTotaljug1 && puntuacionTotaljug2 > MaximaPuntuacion) { MaximaPuntuacion = puntuacionTotaljug2; NombreMaximo(jugador2, NombreMaxPun); cout << "La maxima puntuacion es de " << jugador2 << " con un total de " << MaximaPuntuacion << " en " << TurnosDeMaximaPuntuacion << " tiros " << endl; }
                        else { cout << "La maxima puntuacion es de " << NombreMaxPun << " con un total de " << MaximaPuntuacion << " en " << TurnosDeMaximaPuntuacion << " tiros" << endl; }
                    }
                }


            }
            cout << "\n" << "\n";
            system("pause");
            system("cls");
            break;


        case 21:

            system("cls");



            exit(0);

            break;
            };
            system("cls");
        }


        system("pause");
        return 0;

}
