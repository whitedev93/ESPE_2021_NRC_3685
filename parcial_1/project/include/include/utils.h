#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cfloat>

#include "linked_list.h"
#include "person.h"

static inline std::string generateUniqueEmail(LinkedList<Person *> &list, Person person, std::string domain);
static inline std::string generateIdEmail(Person person);
static inline bool is_person_id_valid(std::string ci);
static inline void str_ltrim(std::string &s);
static inline void str_rtrim(std::string &s);
static inline void str_trim(std::string &s);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief verifica si una cadena es numerica
 * @param str cadena a ser evaluada
 * @return true si es numerica, caso contrario devuelve false
*/
static inline int is_numeric(std::string str) {
    return !str.empty() && std::find_if(str.begin(),
        str.end(), [](unsigned char c) {
            return !std::isdigit(c);
    }) == str.end();
}

/**
 * @brief transforma una cadena a minusculas
 * @param str la cadena por rerefencia a ser transformada
*/
static inline void tolowercase(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), [] (unsigned char c) {
        return std::tolower(c);
    });
}

/**
 * @brief lee una linea de texto por consola
 * @param label prompt mostrado al usuario
 * @return la cadena leida
*/
static inline std::string read_line(std::string label) {
    std::string output;

    do {
        std::cout << label;
        std::getline(std::cin, output);

        str_trim(output);

        if (output.empty()) {
            continue;
        }

        break;
    } while (true);

    return output;
}

/**
 * @brief lee un entero de la consola
 * @param label prompt mostrado al usuario
 * @param min valor minimo a leer
 * @param max valor maximo a leer
 * @return valor leido
*/
inline int read_int(std::string label, int min = INT_MIN, int max = INT_MAX) {
    std::string input;
    int output;

    do {
        std::cout << label;
        std::cin >> input;

        tolowercase(input);

        if (input == "c") {
            return INT_MAX;
        }

        if (std::cin.fail() || !is_numeric(input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        output = std::stoi(input);

        if (output < min || output > max) {
            continue;
        }

        break;
    } while (true);

    return output;
}

/**
 * @brief lee un valor de tipo double de la consola
 * @param label prompt mostrado al usuario
 * @param min valor minimo a leer
 * @param max valor maximo a leer
 * @return valor leido
*/
inline double read_double(std::string label, double min = DBL_MIN, double max = DBL_MAX) {
    double output;

    do {
        std::cout << label;
        std::cin >> output;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (output < min || output > max) {
            continue;
        }

        break;
    } while (true);

    return output;
}

/**
 * @brief genera un email unico dado una lista y una persona
 * @param list la lista de personas a evaluar
 * @param person la persona a la que se genera el email
 * @param domain el dominio del email
 * @return email unico generado
*/
static inline std::string generateUniqueEmail(LinkedList<Person> &list, Person person, std::string domain) {
    std::string identificador = generateIdEmail(person);
    int repetidos = 0;
    bool repetido = false;

    do {
        repetido = false;

        if (repetidos > 0) {
            char sufijo[5] = {'\0'};
            sprintf_s(sufijo, 5, "%d", repetidos + 1);
            identificador = generateIdEmail(person) + std::string(sufijo);
        }

        auto found = list.find([&](Person p) {
            std::string email = identificador + "@" + domain;
            return (email == p.email());
        });

        if (found != nullptr) {
            repetidos++;
            repetido = true;
        }
    } while (repetido);

    std::string email = identificador + "@" + domain;

    for (char &c : email) {
        c = std::tolower(c);
    }

    return email;
}

/**
 * @brief verifica si una cedula es valida o no
 * @param ci cedula a evaluarse
 * @return true si es valida, caso contrario devuelve false
*/
static inline bool is_person_id_valid(std::string ci) {
    str_trim(ci);
    std::string cedula = ci;

    if (cedula.size() != 10) {
        return false;
    }

    bool valido = true;

    for (char &c : ci) {
        if (!std::isdigit(c)) {
            valido = false;
            break;
        }
    }

    // la cedula es solo numerica
    if (!valido) {
        return false;
    }

    int lastDigit = cedula.at(cedula.size() - 1) - '0';
    int digit;
    int sumPairs = 0;
    int oddSum = 0;

    for (int i = 0; i < 9; i++) {
        digit = cedula.at(i) - '0';

        if ((i + 1) % 2 == 0) {
            sumPairs += digit;
        } else {
            oddSum += (digit * 2) > 9 ? (digit * 2) - 9 : (digit * 2);
        }
    }

    int total = sumPairs + oddSum;
    int higher = (10 - (total % 10)) + total;

    if ((total % 10) == 0) {
        return lastDigit == 0;
    }

    return lastDigit == (higher - total);
}

inline std::string generateIdEmail(Person person) {
    std::string lastname = person.lastname();
    std::string output = std::string(1, person.firstname().at(0)) + lastname;

    for (char &c : output) {
        c = std::tolower(c);

        if (c == ' ') {
            c = '_';
        }
    }

    return output;
}

static inline void str_ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); }));
}

static inline void str_rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
}

static inline void str_trim(std::string &s) {
    str_ltrim(s);
    str_rtrim(s);
}
