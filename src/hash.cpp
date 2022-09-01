#include "hash.hpp"

void BeggingConfiguration(int count_h, int max_size, HashTable* h){
    
    int starting_i_coord = 0, final_i_coord = 0, starting_j_coord = 0, final_j_coord =0;

    ///////////////////////USER INPUT

    cout << "Starter point for 'i' (line): ";
    cin >> starting_i_coord;


    cout << "Arrival point for 'i' (line): ";
    cin >> final_i_coord;


    cout << "Starter point for 'j' (column): ";
    cin >> starting_j_coord;


    cout << "Arrival point for 'j' (column): ";
    cin >> final_j_coord;


    int lineSize = (final_i_coord - starting_i_coord + 1);

    string coord1 = to_string(starting_i_coord), coord2 = to_string(final_i_coord), 
    coord3 = to_string(starting_j_coord), coord4 = to_string(final_j_coord);

    coord1 += coord2;
    coord1 += coord3;
    coord1 += coord4;

    for(int i = 0; i < count_h; i++){

        if(coord1 == h->table[i].key){

            cout <<"\n----------------------------------------------------"<< endl;

            cout << " ! [WARNING] ! " << endl << endl;

            cout << "These coords are already registered, check it out: " << endl << endl;

            for(int j = 0; j < lineSize; j++){

                for( int k = 0; k < lineSize; k++){

                    cout << h->table[i].matrix[j][k] << "  ";

                }

                cout << endl;

            }
            
            return;
    
        }

    }

    /////////////////////////DESCOVERING THE MAXIMUM SIZE OF THE INTERNAL MATRIX
    int lil_matrix_size = ((final_i_coord - starting_i_coord + 1) * (final_j_coord - starting_j_coord + 1));


    ////////////////////////FILE OPENING AND TOKENIZATION
    int line, aux = 0, count = 0; 
    vector <int> token;

    ifstream matrix;

    matrix.open("matrix.txt");


    if(matrix.is_open()){
        
        ///////////////////////RANDOM LINES IGNORE
        for(int i = 0; i < starting_i_coord - 1; i++){

            matrix.istream::ignore(40000000, '\n');
            
        }

        while(! matrix.eof()){

            while(count < lil_matrix_size){

                matrix >> line;

                aux++;

                if(aux >= starting_j_coord && aux <= final_j_coord){

                    token.push_back(line);

                    count++;
                }

                if(aux == max_size){

                    aux = 0;
                }

            }
            matrix.istream::ignore(40000000, '\n');
        }


        matrix.close();

    }else
        cout<<"Unable to open file.";

    MatrixOperations(starting_i_coord, starting_j_coord, final_i_coord, final_j_coord, count_h, token, h, coord1);
    
}

void MatrixOperations(int starting_i_coord, int starting_j_coord,int  final_i_coord,int  final_j_coord,int  count_h, vector <int> token, HashTable* h, string coord1){

    int lineSize = (final_i_coord - starting_i_coord + 1);
    int columnSize = (final_j_coord - starting_j_coord + 1);

    int** new_matrix;

    new_matrix = ( int **) malloc (sizeof ( int *) * lineSize);

    for(int i = 0; i < lineSize; i++){

        new_matrix[i] = ( int *) malloc (sizeof( int ) * columnSize) ;

    }

    int a = 0;

    for(int i = 0; i < lineSize; i++) {

        for (int j = 0; j < columnSize; j++) {

            new_matrix[i][j] = token[a];

            a++;
        }
    }

    cout <<"\n----------------------------------------------------"<< endl;

    cout << "Your new matrix looks like: " << endl;

    for (int i = 0; i < lineSize; i++) {

        for (int j = 0; j < columnSize; j++) {

            cout << new_matrix[i][j] << "  ";

        }

        cout << endl;
    }

    int** matrix_trans;

    matrix_trans = ( int **) malloc (sizeof ( int *) * columnSize);

    for(int i = 0; i < columnSize; i++){

        matrix_trans[i] = ( int *) malloc (sizeof( int ) * lineSize) ;

    }

    for(int i = 0; i < lineSize; i++){

        for(int j = 0; j < columnSize; j++){

            matrix_trans[j][i] = new_matrix[i][j];
        }
    }
    
    cout <<"\n----------------------------------------------------"<< endl;

    cout << "The transpose of your new matrix looks like: " << endl;

    for(int i = 0; i < columnSize; i++){

        for(int j = 0; j < lineSize; j++){

            cout << matrix_trans[i][j] << "  ";
        }

        cout << endl;
    }

    cout <<"\n----------------------------------------------------"<< endl;

    cout << "The new matrix generated from the multiplication was: " << endl;

    int** final_matrix;

   final_matrix = ( int **) malloc (sizeof ( int *) * lineSize);

    for(int i = 0; i < lineSize; i++){

        final_matrix[i] = ( int *) malloc (sizeof( int ) * lineSize) ;

    }

    for(int i = 0; i < lineSize; i++){

        for(int j = 0; j < lineSize; j++){
            
            final_matrix[i][j]=0;

            for(int k = 0; k < columnSize; k++){

                final_matrix[i][j] += new_matrix[i][k] * matrix_trans[k][j];
            }
        }
    }

    Insert(h, coord1, final_matrix, count_h, lineSize);

    for(int i = 0; i < lineSize; i++){

        for(int j = 0; j < lineSize; j++){

            cout << final_matrix[i][j] << "  ";
        }

        cout << endl;
    }
}

void Initialize(HashTable *h, int M){

	h->table = (DataTable*) malloc (M * sizeof(DataTable));

	// for(int i = 0; i < M; i++){

	// 	h->table[i].key   = '\0';

	// }

	h->M = M;
}

void Insert(HashTable *h, string key, int **final_matrix, int count_h, int line_size){

	int idx = count_h;

	h->table[idx].key   = key;

	h->table[idx].matrix = ( int **) malloc (sizeof ( int *) * line_size);

    for(int i = 0; i < line_size; i++){

        h->table[idx].matrix[i] = ( int *) malloc (sizeof( int ) * line_size) ;

    }

    for( int i = 0; i < line_size; i++){

        for(int j = 0; j < line_size; j++){

            h->table[idx].matrix[i][j] = final_matrix[i][j];
        }
    }

}
