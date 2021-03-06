/**      
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computacion
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: Funciones Matematicas
 * 
 * @date 19/05/2021
 * @author Andres Jacome
 * @author Gabriel Aguirre
 * @author Dalton Arevalo
 * @author Diego Jimenez
 * @author Lizzette Zapata
 */
#pragma once

class MathUtils {
    public:

        /**
         * @brief Calcula el seno de un angulo
         * 
         * @param angle angulo
         * @param precision total de terminos a iterarse en la serie de Taylor
         * @return double seno calculado
         */
        static double sin(double angle, int precision = 16);

        /**
         * @brief Calcula el coseno de un angulo
         * 
         * @param angle angulo
         * @param precision total de terminos a iterarse en la serie de Taylor
         * @return double coseno calculado
         */
        static double cos(double angle, int precision = 16);

        /**
         * @brief Calcula la tangente de un angulo
         * 
         * @param angle angulo
         * @param precision total de terminos a iterarse en la serie de Taylor
         * @return double tangente calculado
         */
        static double tan(double angle, int precision = 16);

        /**
         * @brief Calcula la cotangente de un angulo
         * 
         * @param angle angulo
         * @param precision total de terminos a iterarse en la serie de Taylor
         * @return double cotangente calculado
         */
        static double ctg(double angle);
        /**
         * @brief Calcula el cosecante de un angulo
         * 
         * @param angle angulo
         * @param presicion total de terminos a iterarse en la serie de Taylor
         * @return double seno calculado
         */
        static double csc(double angulo, int presicion = 16);

        /**
         * @brief Calcula el factorial de un numero
         * 
         * @param n el numero a ser calculado
         * @return long long factorial calculado
         */
        static long long factorial(int n);

        /**
         * @brief Calcula la potencia dada una base y un exponente
         * 
         * @param base la base
         * @param exponent el exponente, puede ser negativo o positivo
         * @return double 
         */
        static double pow(double base, int exponent);

        /**
         * @brief Calcular PI con la serie de Taylor
         * 
         * @param terms cantidad de terminos a iterarse en la serie de Taylor
         * @return double 
         */
        static double pi(int terms = 99999);

        /**
         * @brief transforma un angulo en grados a radianes
         * 
         * @param angle el angulo
         * @return double los radianes transformados
         */
        static double to_radians(double angle);

        /**
         * @brief calcula la raiz cuadrada de un numero dado
         * 
         * @param number numero a calcular la raiz
         * @return double raiz calculada
         */
        static double sqrt(float number);

        /**
         * @brief compara dos valores y regresa el mayor valor
         * 
         * @param a valor uno
         * @param b valor dos
         * @return T 
         */
        template<typename T>
        static T max(T a, T b);

        /**
         * @brief compara dos valores y regresa el menor valor
         * 
         * @param a valor uno
         * @param b valor dos
         */
        template<typename T>
        static T min(T a, T b);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
T MathUtils::max(T a, T b) {
    return (a > b ? a : b);
}

template<typename T>
T MathUtils::min(T a, T b) {
    return (a < b ? a : b);
}
