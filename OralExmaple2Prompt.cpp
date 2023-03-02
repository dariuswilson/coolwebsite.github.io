/*
DISCLAIMER: This live coding prompt is purposely ambiguous.  We aren’t going to tell you exactly how to cout, exactly how to handle edge cases, etc.  There is no autograder and auto grading would defeat the purpose of the exercise.  Instead, you should talk through all of your thoughts and state any assumptions as you are solving the problem.  

You got this.  :D  

PROMPT:
****************
About - The file contains a header and then a list of people (unique first names) waiting in line at a restaurant with an integer indicating how much money they will spend at this restaurant. 
The first line represents the first person to be served (i.e., the front of the line), while the last line represents the last person to be served (back of the line).
The values are separated by spaces. As you work through the problem state any assumptions.

File reading - Read the data in. Store the header in a string (will not be needed), Store the data on each line in a container of structs.  

Process/Calculations - 
1. Calculate the total amount of money the restaurant will make from serving this line of customers.
2. If the restaurant is closing soon but wants to make at least $30 more, write a code that can determine the least amount of people to serve while still making at least $30.
Please do this calculation after the container is already filled, and the file has been closed.  You may use additional containers if you’d like.  


Creative component (if time permits) - create one cin and one cout for this problem.  Make sure your code uses the cin.  
****************

Good luck!!
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string name;
    int spend;
};

int main() {
    vector <Person> people;
    ifstream infile("DataFile.txt");
    if(!infile) {
        cout << "Could not open file!" << endl;
        return 1;
    }
    string header;
    getline(infile, header);
    string line;
    while(getline(infile, line)) {
        string name;
        int spend;
        size_t space_pos = line.find(" ");
        name = line.substr(0, space_pos);
        spend = stoi(line.substr(space_pos + 1));
        people.push_back({name, spend});
    }
    infile.close();

    int indiv_amount = 0;
    int total = 0;
    for(const auto& amount : people) {
        total += amount.spend;
    }

    int remaining_money = 30;
    cout << "The total amount total of money the restaurant will make from serving this line of customers is: $" << total << endl;

    return 0;
}