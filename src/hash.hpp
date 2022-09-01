#ifndef __HASH_HPP
#define __HASH_HPP    

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;

typedef struct DataTable DataTable;
typedef struct HashTable HashTable;

struct DataTable
{
    string key;
    int **matrix;
};

struct HashTable
{
    DataTable *table;
    int M;
};


void BeggingConfiguration(int count_h, int max_size, HashTable* h);

void MatrixOperations(int starting_i_coord, int starting_j_coord,int  final_i_coord,int  final_j_coord,int  count_h, vector <int> token, HashTable* h, string coord1);



void Initialize(HashTable *h, int M);

void Insert(HashTable *h, string key, int **final_matrix, int count, int line_size);



#endif