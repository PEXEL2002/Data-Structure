#pragma once
#include "struct.h"
#include <iostream>
#include <string>

/**
 * @brief Funkcja generująca losowe liczby całkowite i zapisująca je do pliku
 * @param filename nazwa pliku
 * @param numElements ilość elementów
 * @param minGenerated minimalna wartość
 * @param maxGenerated maksymalna wartość
*/
void generateIntToFile(std::string filename, int numElements, int minGenerated, int maxGenerated);
/**
 * @brief Funkcja generująca losowe liczby całkowite
 * @param minGenerated minimalna wartość
 * @param maxGenerated maksymalna wartość
*/
int generateInt(int minGenerated, int maxGenerated);
/**
 * @brief Funkcja generująca tabele z wynikami czasowymi
 * @param nameStruct nazwa struktury
 * @param time czas operacji
*/
void generateTable(std::string* nameStruct, long long int* time);
/**
 * @brief Funkcja dodająca element do struktur
 * @param s tablica struktur
 * @param nameStruct nazway struktur
*/
void uiAddElement(Struct** s, std::string* nameStruct);
/**
 * @brief Funkcja dodawania elementu do struktury na początku
 * @param s tablica struktur
 * @param nameStruct nazwa struktury
*/
void uiAddElementFront(Struct** s, std::string* nameStruct);
/**
 * @brief Funkcja dodawania elementu do struktury na końcu
 * @param s tablica struktur
 * @param nameStruct nazwa struktury
*/
void uiAddElementBack(Struct** s, std::string* nameStruct);
/**
 * @brief Funkcja usuwająca element ze struktur
 * @param s tablica struktur
 * @param nameStruct nazwa struktury
*/
void uiDelElement(Struct** s, std::string* nameStruct);
/**
 * @brief Funkcja usuwająca element z przodu struktury
 * @param s tablica struktur
 * @param nameStruct nazwa struktury
*/
void uiDelElementFront(Struct** s, std::string* nameStruct);
/**
 * @brief Funkcja usuwająca element z tyłu struktury
 * @param s tablica struktur
 * @param nameStruct nazwa struktury
*/
void uiDelElementBack(Struct** s, std::string* nameStruct);
/**
 * @brief Funkcja znajdująca element w strukturze
 * @param s tablica struktur
 * @param nameStruct nazwa struktury
*/
void uiFindElement(Struct** s, std::string* nameStruct);
/**
 * @brief Funkcja wyświetlająca strukturę
 * @param s tablica struktur
 * @param nameStruct nazwa struktury
*/
void uiPrint(Struct** s, std::string* nameStruct);
/**
 * @brief Funkcja wyświetlająca informacje o strukturze
 * @param s tablica struktur
 * @param nameStruct nazwa struktury
*/
void uiPrintInfo(Struct** s, std::string* nameStruct);
/**
 * @brief Funkcja przeprowadzająca badania
*/
void tests();
