#include <iostream>
#include <map>
#include <random>
#include <fstream>

using namespace std;

mt19937 random_mt;

int Random(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(random_mt);
}

void displayMap(map<int, int> timesRolled){

    map<int, int>::iterator iter;
    for(iter = timesRolled.begin(); iter != timesRolled.end(); iter++){
        cout << iter -> first << ": " << iter -> second << endl;
    }

}

void rollDice(int numRoll, int numSides){
    map<int, int> timesRolled;
    int currRoll = 1;
    int currSide;

    for(int i = 1; i <= numSides; i ++){
        timesRolled[i] = 0;
    }

    while (currRoll <= numRoll){
        currSide = Random(1, numSides);
        timesRolled[currSide] += 1;
        currRoll ++;
    }
    displayMap(timesRolled);
}

class State{
    string stateName;
    int perCapitaIncome;
    int population;
    int medianHouseholdIncome;
    int numHouseholds;

public:
    State(string stateName = " ", int perCapitaIncome = 0, int population = 0, int medianHouseholdIncome = 0, int numHouseholds = 0){
        this -> stateName = stateName;
        this -> perCapitaIncome = perCapitaIncome;
        this -> population = population;
        this -> medianHouseholdIncome = medianHouseholdIncome;
        this -> numHouseholds = numHouseholds;
    }


    void DisplayStateInfo(){
        cout << stateName << endl;
        cout << "Population: " << population << endl;
        cout << "Per Capita Income: " << perCapitaIncome << endl;
        cout << "Median Household Income: " << medianHouseholdIncome << endl;
        cout << "Number of Households: " << numHouseholds << endl;
    }

};

int main() {
    cout << "1. Random Numbers\n";
    cout << "2. State Info\n";

    int option;
    cin >> option;

    if (option == 1) {
        int randomSeed;
        cout << "Random seed value: ";
        cin >> randomSeed;
        random_mt.seed(randomSeed);


        cout << "Number of times to roll the die: ";
        // user input
        int numRoll;
        cin >> numRoll;

        cout << "Number of sides on this die: ";
        // user input
        int numSides;
        cin >> numSides;

        cout << endl << endl;
        // Roll Dice
        rollDice(numRoll, numSides);

    } else if (option == 2) {
        // Load the states
        string temp;
        string stateName;
        int perCapitaIncome;
        int population;
        int medianHouseholdIncome;
        int numHouseholds;
        fstream inFile("states.csv", ios_base::in);
        // Create a map to store state name and its corresponding State object
        map<string, State> States;
        // Read a line from the input file
        getline(inFile, temp); // puts current value into temp
        // Iterate over the input file for 53 lines
        for(int i = 0; i < 53; i++){ // for as long as there is something in inFile
            // Read the state name
            getline(inFile, stateName, ',');

            // Read the per Capita income
            getline(inFile, temp, ','); // puts current value into temp
            perCapitaIncome = stoi(temp);
            // Read the population
            getline(inFile, temp, ',');
            population = stoi(temp);
            // Read the median household income
            getline(inFile, temp, ',');
            medianHouseholdIncome = stoi(temp);
            // Read the number of households
            getline(inFile, temp);
            numHouseholds = stoi(temp);
            //create instance of class
            State tempState = State(stateName, perCapitaIncome, population, medianHouseholdIncome, numHouseholds);
            States.emplace(stateName, tempState);
        }

        // Get input for option 1 (show all states) or 2 (do a search for a particular state)
        cout << "1. Print all states\n";
        cout << "2. Search for a state\n";

        int option2;
        cin >> option2;

        if(option2 == 1){
            map<string, State>::iterator iter;
            for(iter = States.begin(); iter != States.end(); iter++){
                iter -> second.DisplayStateInfo();
            }
        }
        else if(option2 == 2){
            cin >> stateName;
            if(States.find(stateName) != States.end()){
                States[stateName].DisplayStateInfo();
            }
            else{
                cout << "No match found for " << stateName << endl;
            }
        }
    }
}
