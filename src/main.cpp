#include "hash.hpp"

int main(){

    HashTable h;

    int M = 1000;

    Initialize(&h, M);

    int opcao, count_h = 0, max_size = 0;

    cout << "Enter with the size of the matrix (L x L): ";
    cin >> max_size;

    cout << endl << endl;


    while(opcao != 0){

        cout << endl << endl;

        cout << "----- OPTIONS MENU ------------------------------------" << endl << endl;

        cout << "1 - Add new coords to separate on a new matrix;" << endl; 
        
        cout << " . "<< endl;

        cout << "0- End program." << endl << endl;

        cout << "----- END OF THE OPTIONS MENU -----------------------------" << endl;

        cout << endl;

        cin >> opcao;

        cout << endl;

        if( opcao == 1){

            BeggingConfiguration(count_h, max_size, &h);
        }

        if ( opcao > 1){
            
            cout << "Invalid option, try again.";
       } 

        count_h++;

    }

    return 0;
}