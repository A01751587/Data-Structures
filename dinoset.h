/*----------------------------------------------------------
 * Práctica #1: DinoSets
 * Implementación de la clase DinoSet.
 *
 * Fecha: 13-Ago-2021
 * Autores:
 *           A01751587 Paulo Ogando Gulias
 *           A0 Ricardo Antonio Cervantes Martinez
 *----------------------------------------------------------*/
#pragma once

#include <string>

const int total_dinos = 8; // al ser constante, no cambia su valor

enum class DinoId {
    velocirraptor,      // 0
    estegosaurio,       // 1
    tiranosaurio,       // 2
    procompsagnatus,    // 3
    triceratops,        // 4
    paquicefalosaurio,  // 5
    parasaurolofus,     // 6
    pteranodon          // 7
};

std::string dino_names[] = {
    "velocirraptor",
    "estegosaurio",
    "tiranosaurio",
    "procompsagnatus",
    "triceratops",
    "paquicefalosaurio",
    "parasaurolofus",
    "pteranodon"
};

class DinoSet{

    public:

        void add(DinoId id)
        {
            int index = static_cast<int>(id); //transforma el id recibido en el valor entero que le corresponde
            _dino[index] = true;
        }

        void remove(DinoId id)
        {
            int index = static_cast<int>(id); //convierte el id a entero, el valor de DinoId a entero.
            _dino[index] = false;
        }

        bool contains(DinoId id) const
        {
            int index = static_cast<int>(id);
            // if (_dino[index]) {
            //     return true;
            // } else {
            //     return false;
            // }
            return _dino[index]; //en este caso, esto puede simplificar el if
        }

        int size() const
        {
            int result = 0;
            for (int i = 0; i < total_dinos; ++i){
                if (_dino[i]){
                    ++result;
                }
            }
            return result;
        }

        bool is_empty() const
        {
            for (int i = 0; i < total_dinos; ++i) {
                if (_dino[i]) {
                    return false;
                }
            }
            return true;
        }

        DinoSet operator+(const DinoSet& other) const
        {
            DinoSet result;
            for (int i = 0; i < total_dinos; ++i ){
                DinoId id = static_cast<DinoId>(i);
                if (contains(id) or other.contains(id)){
                    result.add(id);
                }
            }
            return result;
        }

        DinoSet operator*(const DinoSet& other) const
        {
            DinoSet result;
            for (int i = 0; i < total_dinos; ++i ){
                DinoId id = static_cast<DinoId>(i);
                if (contains(id) and other.contains(id)){
                    result.add(id);
                }
            }
            return result;
        }

        DinoSet operator-(const DinoSet& other) const
        {
            DinoSet result;
            for (int i = 0; i < total_dinos; ++i ){
                DinoId id = static_cast<DinoId>(i);
                if (contains(id) and not(other.contains(id))){
                    result.add(id);
                }
            }
            return result;
        }

        DinoSet operator!() const
        {
            DinoSet result;
            for (int i = 0; i < total_dinos; ++i){
                DinoId id = static_cast<DinoId>(i);
                if (not(contains(id))){
                    result.add(id);
                }
            }
            return result;
        }

        bool operator==(const DinoSet& other) const
        {
            for (int i = 0; i < total_dinos; ++i){
                DinoId id = static_cast<DinoId>(i);
                if (contains(id) != other.contains(id)){
                    return false;
                }
            }
            return true;
        }

        std::string to_string() const //la palabra const significa que la operacion no modifica al objeto en cuestión
        {
            std::string result = "{"; //cada que se usa string se debe anteponer std
            for (int i = 0; i < total_dinos; ++i) {
                // DinoId id = static_cast<DinoId>(i);
                if (_dino[i]){// no se iguala a true porque el if ya lo hace por default
                    result += dino_names[i];
                    result += ", ";
                }
            }
            if (is_empty()){
                result += "}";
                return result;
            }
            result.pop_back();
            result.pop_back();
            result += "}";
            return result;
        }


    private:
        bool _dino[total_dinos] {}; //Los corchetes inicializan el booleano con 0 o false
}; // Poner ; al final de cada clase