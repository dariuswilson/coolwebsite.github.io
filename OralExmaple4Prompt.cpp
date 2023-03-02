/*
DISCLAIMER: This live coding prompt is purposely ambiguous.  We aren’t going to tell you exactly how to cout, exactly how to handle edge cases, etc.  There is no autograder and auto grading would defeat the purpose of the exercise.  Instead, you should talk through all of your thoughts and state any assumptions as you are solving the problem.  

You got this.  :D  

PROMPT:
**********************
About - The file contains a list of Cereals and their associated calories. 
        The first text in the file is a header/title for the file. 
        Each remaining item is a string of the cereal name and an int which represents its calories all separated by spaces with the calories being the last item on the line.

File reading - read the data in. Store header in a string variable and the rest of the data into a container of your choice.

Process/Calculations - Calculate the mean calories of the all the cereals and display this amount in joules (1 calorie = 4.184 J).  Print out the cereals that are less than the mean and greater than the mean, include helpful descriptions.  The two printed groups should each be in alphabetical order.  
Please do these calculations after the file reading is done and your container is filled.  

Creative component (if time permits) - create one cin and one cout for this problem.  Make sure your code uses the cin.  

****************

All the best, stay healthy, and have fun!
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Cereal {
    string name;
    int calories;
};

int main () {
    ifstream infile("DataFile.txt");
    vector<Cereal>cereals;

    if(!infile) {
        cout << "Could not open file!" << endl;
    }

    string header;
    getline(infile, header);
    string line;
    while(getline(infile, line)) {
        string name;
        int calories;

        size_t space_pos = line.find_last_of(' ');
        name = line.substr(0, space_pos);
        calories = stoi(line.substr(space_pos + 1));
        cereals.push_back({name, calories});
    }
    infile.close();

    int totalCalories = 0;
    for (int i = 0; i < cereals.size(); i++) {
        totalCalories += cereals[i].calories;
    }
}