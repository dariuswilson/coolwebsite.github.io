#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Ingredient {
    string name;
    int quantity;
};

int main() {
    vector<Ingredient> ingredients;
    ifstream infile("DataFile.txt");
    if(!infile) {
        cout << "Could not open " << infile << endl;
        return 1;
    } 

    string header;
    getline(infile, header);
    string line;
    while (getline(infile, line)) {

    }



    return 0;
}