/*
DISCLAIMER: This live coding prompt is purposely ambiguous.  We aren’t going to tell you exactly how to cout, exactly how to handle edge cases, etc.  There is no autograder and auto grading would defeat the purpose of the exercise.  Instead, you should talk through all of your thoughts and state any assumptions as you are solving the problem.  

You got this.  :D  

PROMPT:

**********************
About - The file contains a list of Anime series and movies along with their episode count.
        The first row in the file contains the file header
        Each remaining row contains the name of the anime, followed by a comma, and then the number of episodes associated with it.

File Reading - Read the data in. Store header in a string (you can print it in the beginning)
               Rest of the data can be stored in a container, multiple containers, or a container with structs.
               
Process/Calculations - Print out the anime with the highest number of episodes
                       Print out the list of all movies (that have an episode count of 1)

Creative component (if time permits) - create one cin and one cout for this problem.  Make sure your code uses the cin.  
***********************

Good luck!
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Anime {
    string name;
    int episode_count;
};

int main () {
    string header;
    vector <Anime> animeList;

    ifstream infile("DataFile.txt");

    if(!infile) {
        cout << "Could Not Open File!" << endl;
        return 1;
    }

    getline(infile, header);

    string line;
    while(getline(infile, line)) {
        string name;
        int episode_count;
        size_t comma_pos = line.find(',');  

        if(comma_pos != string::npos) {
            name = line.substr(0, comma_pos);
            episode_count = stoi(line.substr(comma_pos + 1));
            animeList.push_back({name, episode_count});     
        }
    }
    infile.close();
    cout << header << endl;
    int highest_number = -1;
    string biggest_episode;
    for(const auto& anime: animeList) {
        if (anime.episode_count > highest_number){
            highest_number = anime.episode_count;
            biggest_episode = anime.name;
        }
    } 
    cout << "The Anime with the highest number of episodes is: " << biggest_episode << endl;

    cout << "List of all movies that have 1 episode count: " << endl;
    for(const auto& anime : animeList) {
        if(anime.episode_count == 1) {
            cout << "-" << anime.name << endl;
        }
    }
    return 0;
};