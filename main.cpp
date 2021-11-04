#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const string colors[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};
string *generatedColors;
string *userColors;
bool positionCompare[4];
bool colorCompare[4];
int attempts = 0;
bool check = false;

void counter();

string *generateColors();

string *userInput();

bool compare();

void startOutput();

void game();

void menu(int choice);

int main();


void counter() {
    attempts++;
}

string *generateColors() {
    srand(time(nullptr));

    string *generatedColors;
    generatedColors = new string[4];
    int seq[7];

    //    Color sequence generation in indexes
    for (int i = 0; i < 7; i++) {
        int j = rand() % (i + 1);
        seq[i] = seq[j];
        seq[j] = i;
    }

    //    Filling in the generated colors
    int temp;
    for (int i = 0; i < 4; i++) {
        temp = seq[i];
        generatedColors[i] = colors[temp];
    }

    return generatedColors;
}

string *userInput() {
    string *userColors;
    userColors = new string[4];

    cout << "Please enter 4 colors: " << endl;
    for (int i = 0; i < 4; i++) {
        cin >> userColors[i];
    }

    return userColors;
}

//    Comparing generated and users entered colors
bool compare() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (generatedColors[i] == userColors[j] && i == j) {
                positionCompare[j] = true;
                colorCompare[j] = true;
            } else if (generatedColors[i] == userColors[j] && i != j) {
                colorCompare[j] = true;
                positionCompare[j] = false;
            }
        }
    }

    cout << "===================================" << endl;
    for (int i = 0; i < 4; i++) {
        cout << userColors[i] << "\t| Color: " << colorCompare[i] << "\t| Position: " << positionCompare[i] << endl;
    }

    for (int i = 0; i < 4; i++) {
        if (!colorCompare[i] || !positionCompare[i]) {
            check = false;
            break;
        } else {
            check = true;
        }
    }

    if (check) {
        cout << "============== YOU WIN ==============" << endl;
        cout << "Attempts: " << attempts << endl;
    } else {
        cout << "===================================" << endl;
    }

    return check;
}


void startOutput() {
    cout << "========== START ==========" << endl;
    cout << endl;
    cout << "Available colors: " << endl;
    cout << endl;

    for (int i = 0; i < 7; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;
    cout << "===================================" << endl;
}

void game() {
    startOutput();
    generatedColors = generateColors();
    cout << endl;

//    Output the generated colors for testing
//    cout << "Generated colors(for test): " << endl;
//    for (int i = 0; i < 4; i++) {
//        cout << generatedColors[i] << " ";
//    }
//    cout << endl;

    while (!check) {
        if (attempts < 5) {
            counter();
            userColors = userInput();
            compare();
        } else {
            cout << "============== YOU LOSE ==============" << endl;
            main();
        }

    }
}

void menu(int choice) {
    cout << "1 - New Game" << endl;
    cout << "2 - Last Result" << endl;
    cout << "0 - Exit" << endl;

    cout << "Your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            game();
            break;
        case 2:
            cout << "Last Result: " << attempts << endl;
            break;
        case 0:
            exit(0);
        default:
            cout << "Select a number from the menu" << endl;
    }
}


int main() {
    int choice;

    while (true) {
        menu(choice);
        attempts = 0;
    }
}