#include <iostream>
#include <string>
#include <math.h>
using namespace std;

double strings[7];

class Guitar
{
public:
    // Constructor
    Guitar()
    {
        strings[0] = 0;
        strings[1] = 82.41;
        strings[2] = 110;
        strings[3] = 146.8;
        strings[4] = 196;
        strings[5] = 246.9;
        strings[6] = 329.6;
        numberOfFrets = 21;
    }
    


    // Getters
    double pitchAt(const char &stringNumber, const char &fret)
    {   
        return strings[stringNumber] * pow(2.0, (double)fret/12.); 
    }

    // Modifiers
    // changes tune of an individual guitar string
    void tuneString(const char &string, const double& pitch)
    {
        strings[string] = pitch; 
    }

    // sets numberOfFrets and verifies it is between 1 and 24
    bool setFretBoardLength(const char numFrets)
    {
        bool valid = false;
        if (numFrets < 0 || numFrets > 24) {
            cout << "Too many or too little number of frets." << "\n";
        } else {
            valid = true;
            numberOfFrets = numFrets;
        }
        return valid;
    }

    
    // returns a string and fret that can create the pitch given as a parameter
    std::pair<char, char> getStringAndFret( double pitch )
    {
        bool match = false;
        char testFret;
        char sString;
        std::pair<char, char> answer = pair<char, char>(0,0);
        for (int sString = 1; sString < 6 && !match; sString++) {
            for (testFret = 0; testFret < numberOfFrets && !match; testFret++) {
                if (abs(pitch - pitchAt(sString, testFret)) <= .1){
                    match = true;
                    answer.first = sString;
                    answer.second = testFret;
                }
            }
        }
        return answer;
    }
    
    // Returns number of frets
    int frets () { return numberOfFrets; }

    

private:
    char numberOfFrets;
    double strings[7];

};


// driver function to show that all of my functions work successfully
int main()
{
    Guitar myGuitar;

    // Shows working pitchAt method.
    cout << "pitchAt method --> Get pitch at string 3 and fret 5: " << myGuitar.pitchAt(3,5) << endl;

    // 2 examples of getStringAndFret method.
    pair<char,char> match;
    match = myGuitar.getStringAndFret(311.1);
    cout << "getStringAndFret method --> 311.1 Hz: String " << (int)match.first << " Fret " << (int)match.second << endl;
    match = myGuitar.getStringAndFret(155.5);
    cout << "getStringAndFret method --> 155.5 Hz: String " << (int)match.first << " Fret " << (int)match.second << endl;

    // Shows working setFretBoardLength method.
    cout << "setFretBoardLength method --> changing fret board to 24. " << endl;
    myGuitar.setFretBoardLength(24);
    cout << "Fret board length = " << myGuitar.frets() << endl;

    // Shows working tuneString method.
    cout << "tuneString method --> Changing string 2 tune to 115Hz. " << endl;
    myGuitar.tuneString(2, 115);
    cout << "Tune at string 2 = " << myGuitar.pitchAt(2,0) << endl;
    return 0; 
}