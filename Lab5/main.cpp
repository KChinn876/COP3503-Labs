#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Ship {
    string shipName;
    string className;
    short shipLength;
    int shieldCapacity;
    float warpSpeed;
    int weaponCount;

    struct Weapon{
        string weaponName;
        int powerRating;
        float powerConsumption;

        Weapon(string weaponName, int powerRating, float powerConsumption){
            this->weaponName = weaponName;
            this->powerRating = powerRating;
            this->powerConsumption = powerConsumption;
        }

        void WeaponDisplayInfo(){
            cout << weaponName << ", " << powerRating << ", " << powerConsumption << endl;
        }
    };

    vector<Weapon> weapons;

    Ship(string shipName, string className, short shipLength, int shieldCapacity, float warpSpeed, int weaponCount, vector<Weapon>& weapons){
        this->shipName = shipName;
        this->className = className;
        this->shipLength = shipLength;
        this->shieldCapacity = shieldCapacity;
        this->warpSpeed = warpSpeed;
        this->weaponCount = weaponCount;
        this->weapons = weapons;
    }

    int combinedPower(){
        int total;
        for(long unsigned int i = 0; i < weapons.size(); i++){
            total += weapons.at(i).powerRating;
        }
        return total;
    }

    void DisplayInfo(){
        cout << "Name: " << shipName << endl;
        cout << "Class: " << className << endl;
        cout << "Length: " << shipLength << endl;
        cout << "Shield capacity: " << shieldCapacity << endl;
        cout << "Maximum Warp: " << warpSpeed << endl;
        cout << "Armaments: " << endl;
        if(weapons.size() == 0){
            cout << "Unarmed" << endl;
        }
        else {
            for (long unsigned int i = 0; i < weapons.size(); i++) {
                weapons.at(i).WeaponDisplayInfo();
            }
            cout << "Total firepower: " << combinedPower() << endl;
        }
        cout << endl;
    }

    int mostPowerful(){
        int mostPower = 0;
        if(weapons.size() != 0) {
            mostPower = weapons.at(0).powerRating;
            for (long unsigned int i = 1; i < weapons.size(); i++) {
                if (weapons.at(i).powerRating > mostPower) {
                    mostPower = weapons.at(i).powerRating;
                }
            }
        }
        return mostPower;
    }

};

void readFile(string path, vector<Ship>& ships){
    fstream inFile(path, ios_base::in | ios_base::binary);
    //create unsigned int called enemy count
    unsigned int shipCount = 0;
    //read bin from input file stream into variable
    inFile.read((char*)&shipCount, sizeof(shipCount));

    //start for loop
    for(unsigned int i = 0 ; i < shipCount; i++){
        int length;
        inFile.read((char*)&length, sizeof(length));
        char* buffer = new char[length];//temp value
        inFile.read(buffer, length);
        string shipName = buffer;
        delete[] buffer;

        //read class
        inFile.read((char*)&length, sizeof(length));
        buffer = new char[length];
        inFile.read(buffer, length);
        string className = buffer;
        delete[] buffer;

        //read length
        short shipLength;
        inFile.read((char*)&shipLength, sizeof(shipLength));

        int shieldCapacity;
        inFile.read((char*)&shieldCapacity, sizeof(shieldCapacity));

        float warpSpeed;
        inFile.read((char*)&warpSpeed, sizeof(warpSpeed));

        int weaponCount;
        inFile.read((char*)&weaponCount, sizeof(weaponCount));


        vector<Ship::Weapon> weapons;

        for(int j = 0; j < weaponCount; j++){
            inFile.read((char*)&length, sizeof(length));
            char* buffer = new char[length];//temp value
            inFile.read(buffer, length);
            string weaponName = buffer;
            delete[] buffer;

            int powerRating;
            inFile.read((char*)&powerRating, sizeof(powerRating));

            float powerConsumption;
            inFile.read((char*)&powerConsumption, sizeof(powerConsumption));

            Ship::Weapon temporaryWeapon = Ship::Weapon(weaponName, powerRating, powerConsumption);
            weapons.push_back(temporaryWeapon);
        }
        Ship temporaryShip = Ship(shipName, className, shipLength, shieldCapacity, warpSpeed, weaponCount, weapons);
        ships.push_back(temporaryShip);
        /*
        for(int k = 0; k < weaponCount; k++){
            temporaryShip.weapons.push_back(weapons.at(k));
        }
        */
    }
}

int main()
{
    vector<Ship> ships;

    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;

    int option;
    cin >> option;
    string path = "";
    /* Load files here */
    if(option == 1){
        path = "friendlyships.shp";
        readFile(path, ships);
    }
    else if(option == 2){
        path = "enemyships.shp";
        readFile(path, ships);
    }
    else if(option == 3){
        path = "friendlyships.shp";
        readFile(path, ships);
        path = "enemyships.shp";
        readFile(path, ships);
    }

    cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl;
    
    cin >> option;

    if(option == 1){
        for(long unsigned int i = 0; i < ships.size(); i++){
            ships.at(i).DisplayInfo();
        }
    }
    else if(option == 2){
        int greatestWeapon = 0;
        int shipPower1;
        int shipPower2;
        for(long unsigned int i = 0; i < ships.size(); i++){
            shipPower1 = ships.at(greatestWeapon).mostPowerful();
            shipPower2 = ships.at(i).mostPowerful();
            if(shipPower1 <= shipPower2){
                //cout << shipPower1 << " vs " << shipPower2 << endl;
                greatestWeapon = i;
            }
        }
        ships.at(greatestWeapon).DisplayInfo();
    }
    else if(option == 3){
        int greatestPower = 0;
        int shipPower1;
        int shipPower2;
        for(long unsigned int i = 0; i < ships.size(); i++){
            shipPower1 = ships.at(greatestPower).combinedPower();
            shipPower2 = ships.at(i).combinedPower();
            if(shipPower1 <= shipPower2){
                //cout << shipPower1 << " vs " << shipPower2 << endl;
                greatestPower = i;
            }
        }
        ships.at(greatestPower).DisplayInfo();
    }
    else if(option == 4){
        int leastPower = 0;
        int shipPower1;
        int shipPower2;
        for(long unsigned int i = 0; i < ships.size(); i++){
            shipPower1 = ships.at(leastPower).combinedPower();
            shipPower2 = ships.at(i).combinedPower();
            if(shipPower1 == 0 || shipPower2 == 0){
                continue;
            }
            else if(shipPower1 >= shipPower2){
                //cout << shipPower1 << " vs " << shipPower2 << endl;
                leastPower = i;
            }
        }
        ships.at(leastPower).DisplayInfo();
    }
    else if(option == 5){
        for(long unsigned int i = 0; i < ships.size(); i++){
            if(ships.at(i).mostPowerful() == 0){
                ships.at(i).DisplayInfo();
            }
        }
    }

    return 0;
}

