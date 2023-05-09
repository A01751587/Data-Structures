/*----------------------------------------------------------
 * Proyecto: El ataque de los bots.
 *
 * Fecha: 30-Nov-2021
 * Autores:
 *           A01745912 Ricardo Antonio Cervantes Martínez
 *           A01751587 Paulo Ogando Gulias
 *----------------------------------------------------------*/

#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "linkedlist.h"

//Complejidad O(1)
//Función que recibe el mes en letras y devuelve el mes en número.
std::string obtener_mes(std::string mes)
{
    std::string num_mes;

    if (mes == "Jan"){
        num_mes = "01";
    } else if (mes == "Feb"){
        num_mes = "02";
    } else if (mes == "Mar"){
        num_mes = "03";
    } else if (mes == "Apr"){
        num_mes = "04";
    } else if (mes == "May"){
        num_mes = "05";
    } else if (mes == "Jun"){
        num_mes = "06";
    } else if (mes == "Jul"){
        num_mes = "07";
    } else if (mes == "Aug"){
        num_mes = "08";
    } else if (mes == "Sep"){
        num_mes = "09";
    } else if (mes == "Oct"){
        num_mes = "10";
    } else if (mes == "Nov"){
        num_mes = "11";
    } else if (mes == "Dec"){
        num_mes = "12";
    }

    return num_mes;
}

//Complejidad O(N^2)
// Función para la obtención de la semana con más ataques del año.
std::string semana_mayor(std::vector <std::string> fecha_numero, std::vector <int> frecuencia)
{
    std::ifstream infile2;
	infile2.open ("semanas_rango.txt");

    std::string semana_maxima;
	std::vector <int> semanas_frecuencia; //Vector con la frecuencia de ataque por semana.
    std::vector <std::string> rango_semana;
    std::vector <int> rango_inicial;
    std::vector <int> rango_final;

	while(!infile2.eof()){
    	int rango1;
    	int rango2;
        std::string rango_actual;

        getline(infile2,rango_actual,'-');
        rango1 = atoi(rango_actual.c_str());

        getline(infile2,rango_actual,'_');
        rango2 = atoi(rango_actual.c_str());

        getline(infile2,rango_actual,'\n');
        rango_semana.push_back(rango_actual);

        rango_inicial.push_back(rango1);
        rango_final.push_back(rango2);

        semanas_frecuencia.push_back(0);
	}

	infile2.close();

	for (int i = 0; i < fecha_numero.size(); ++i){
        int num_fecha = atoi(fecha_numero[i].c_str());
        for (int j = 0; j < rango_inicial.size(); ++j){
            if ((num_fecha >= rango_inicial[j]) & (num_fecha <= rango_final[j])){
                semanas_frecuencia[j] = semanas_frecuencia [j] + frecuencia[i];
            }
        }
	}

    int max = *max_element(semanas_frecuencia.begin(), semanas_frecuencia.end());
    int num_ataques;

    for (int i = 0; i < semanas_frecuencia.size() ; ++i){
	    if (semanas_frecuencia[i] == max){
	        semana_maxima = rango_semana[i];
	    }
	}
    semana_maxima = semana_maxima + " con ";
	semana_maxima = semana_maxima + std::to_string(max);

    return semana_maxima;
}

//Complejidad O(N^2)
//Función que responde la pregunta uno: Obtiene las 5 ip con más ataque de la bitácora.
void pregunta_uno (std::vector <std::string> ip)
{
    std::vector <std::string> dir_ip;
    std::vector <int> frecuencia;
    std::vector <std::string> top_ip;
    std::vector <int> top_frecuencia;


    for (int i = 0; i < ip.size(); ++i){
        bool estado = false;
        for (int j = 0; j < dir_ip.size(); ++j){
            if (ip[i] == dir_ip[j]){
                estado = true;
                break;
            }
        }
        if (estado == false){
            dir_ip.push_back(ip[i]);
        }
    }

    for (int i = 0; i < dir_ip.size(); ++i){
        frecuencia.push_back(0);
        for (int j = 0; j < ip.size(); ++j){
            if (ip[j] == dir_ip[i]){
                frecuencia[i] = frecuencia[i] + 1;
            }
        }
    }

    for(int j = 0; j < 5; ++j){
        int max = *max_element(frecuencia.begin(), frecuencia.end());
        int item;
        for (int i = 0; i < frecuencia.size(); ++i){
            if (frecuencia[i] == max){
                top_ip.push_back(dir_ip[i]);
                top_frecuencia.push_back(frecuencia[i]);
                item = i;
                break;
            }
        }
        dir_ip.erase(dir_ip.begin() + item);
        frecuencia.erase(frecuencia.begin() + item);
    }

    std::cout << "i ¿Cuáles son las cinco direcciones IP (sin el importar el número de puerto) que tuvieron más accesos ilegales?" << std::endl;

    for (int i = 0; i < top_ip.size(); ++i){
        std::cout << "Dirección IP: " << top_ip[i] << " Número de ataques: " << top_frecuencia[i] << std::endl;
    }
}

//Complejidad O(N)
//Funcion que calcula cuantas veces aparece cada mensaje de error en la bitacora
void pregunta_dos (std::vector <std::string> razones)
{
    LinkedList<std::string> razon;
    std::string razon_actual;
    int razon1 = 0;
    int razon2 = 0;
    int razon3 = 0;
    int razon4 = 0;
    std::string razon_mayor;

    for (int i = 0; i < razones.size(); ++i){
        razon_actual = razones[i];
        if (not(razon.contains(razon_actual))){
            razon.insert_front(razon_actual);
        }
    }

    for (int i = 0; i < razones.size(); ++i){
        razon_actual = razones[i];
        if (razon_actual == razon.get(0)){
            razon1 += 1;
        } else if (razon_actual == razon.get(1)){
            razon2 += 1;
        } else if (razon_actual == razon.get(2)){
            razon3 += 1;
        } else if (razon_actual == razon.get(3)){
            razon4 += 1;
        }
    }

    std::vector <int> frecuencia_razon {razon1, razon2, razon3, razon4};
    int max = *max_element(frecuencia_razon.begin(), frecuencia_razon.end());

    if (max == razon1){
        razon_mayor = razon.get(0);
    } else if (max == razon2){
        razon_mayor = razon.get(1);
    } else if (max == razon3){
        razon_mayor = razon.get(2);
    } else if (max == razon4){
        razon_mayor = razon.get(3);
    }

    std::cout << "\nii ¿Con qué frecuencia aparecen cada uno de los distintos mensajes de error (razón de la falla)?" << std::endl;
    std::cout << "El mensaje " << razon.get(0) << " aparece " << razon1 << " veces." << std::endl;
    std::cout << "El mensaje " << razon.get(1) << " aparece " << razon2 << " veces." << std::endl;
    std::cout << "El mensaje " << razon.get(2) << " aparece " << razon3 << " veces." << std::endl;
    std::cout << "El mensaje " << razon.get(3) << " aparece " << razon4 << " veces." << std::endl;
    std::cout << "La razon con mas frecuencia fue: " << razon_mayor << ", que se repitio " << max << " veces." << std::endl;
}

//Complejidad O(N)
//Funcion que calcula cuantos puertos distintos fueron atacados, dando el total de puertos como resultado
void pregunta_tres (std::vector <std::string> puertos)
{
    LinkedList<std::string> puerto;
    std::string puerto_actual;

    for (int i = 0; i < puertos.size(); ++i){
        puerto_actual = puertos[i];
        if (not(puerto.contains(puerto_actual))){
            puerto.insert_front(puerto_actual);
        }
    }

    std::cout << "\niii ¿Cuántos números de puertos distintos fueron atacados en total?" << std::endl;
    std::cout << "Se encontraron " << puerto.size() << " puertos distintos." << std::endl;
}

//Complejidad O(N^2)
//Función que responde la pregunta cuatro: Devuelve la semana con más ataques,
//evalúa las fechas en los rangos de semanas con mayores ataques.
void pregunta_cuatro (std::vector <std::string> fechas)
{
    std::vector <int> frecuencia; //Vector con la frecuencia de ataques por fecha.
    LinkedList<std::string> fecha_frecuencia;

    std::string fecha_actual;

    for (int i = 0; i < fechas.size(); ++i){
        fecha_actual = fechas[i];
        if (not(fecha_frecuencia.contains(fecha_actual))){
            fecha_frecuencia.insert_front(fecha_actual);
        }
    }

    for (int i = 0; i < fecha_frecuencia.size(); ++i){
        frecuencia.push_back(0);
        for (int j = 0; j < fechas.size(); ++j){
            if (fechas[j] == fecha_frecuencia.get(i)){
                frecuencia[i] = frecuencia[i] + 1;
            }
        }
    }

    std::vector <std::string> fecha_numero; //Vector con las fechas en número.

    for (int i = 0; i < fecha_frecuencia.size(); ++i){
        std::string dia;
        dia = fecha_frecuencia.get(i);
        dia = dia[3];
        dia = dia + dia[4]; //Se obtiene el día en número de la fecha mes día.

        std::string mes_num;
        std::string fecha = "2020";

        std::string mes = fecha_frecuencia.get(i); //Fecha completa mes y día.
        mes.pop_back();
        mes.pop_back(); //Pops para obtener solo las tres lestra del mes.

        mes_num = obtener_mes(mes);

        fecha = fecha + mes_num;
        fecha = fecha + dia; //Fecha en número "añomesdía".

        fecha_numero.push_back(fecha);
    }

    std::string semana_max;
    semana_max = semana_mayor(fecha_numero, frecuencia);

    std::cout << "\niv ¿En qué semana se detectaron una mayor cantidad de accesos ilegales?" << std::endl;
    std::cout << "Durante la semana: " << semana_max << " ataques." << std::endl;
}

//Complejidad O(N)
//Función que lee el archivo de la bitácora y almacena cada valor en distintos vectores.
void lectura_archivo(std::string nombre_texto)
{
	std::ifstream infile;
	infile.open (nombre_texto);

	std::vector <std::string> texto;
	std::vector <std::string> fechas;
	std::vector <std::string> horas;
	std::vector <std::string> ip;
	std::vector <std::string> puertos;
	std::vector <std::string> razones;

    while(!infile.eof()){
	    std::string linea;
	    std::string fecha;

	    getline(infile,linea,' ');
	    fecha = fecha + linea;
	    getline(infile,linea,' ');
        fecha = fecha + linea;
	    fechas.push_back(fecha);//Guarda la fecha en el vector fechas.

	    getline(infile,linea,' ');
	    horas.push_back(linea);

	    getline(infile,linea,':');
	    ip.push_back(linea);

	    getline(infile,linea,' ');
	    puertos.push_back(linea);

	    getline(infile,linea,'\n');
	    razones.push_back(linea);
    }

    pregunta_uno(ip);
    pregunta_dos(razones);
    pregunta_tres(puertos);
    pregunta_cuatro(fechas);

	infile.close();
}

//Complejidad O(1)
//Función principal en donde recibe el argumento de la bitácora.
int main(int argc, char* argv[])
{
    if (argc != 2){
        std::cerr << "Se espera el nombre del archivo de entrada.\n";
        std::exit(1);
    }

    std::string archivo = std::string(argv[1]);
    lectura_archivo(archivo);

    return 0;
}