#include "company.hpp"
#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
    CompanyTracker* track = new CompanyTracker(5);

    track->merge(2, 2); //Merge does nothing when i == j
    cout << boolalpha << track->inSameCompany(2, 2) << endl;    //inSameCompany returns true when i == j

    //Merge doesn't do anything when one or more of the companies is out of range. 
    //inSameCompany returns false when one or more of the companies is out of range
    track->merge(-1, 2);
    cout << boolalpha << track->inSameCompany(-1, 2) << endl;
    track->merge(3, 20);
    cout << boolalpha << track->inSameCompany(3, 20) << endl;
    track->merge(-5, 5);
    cout << boolalpha << track->inSameCompany(3, 20) << endl;

    //Split does nothing for a one person company
    track->split(4);    
    cout << boolalpha << track->inSameCompany(4, 3) << endl;    //Returns false. 4 and 3 were never in the same company, and split did not change anything. 
    //Split also does nothing when the company is out of range
    track->split(-1);
    track->split(7);
    cout << boolalpha << track->inSameCompany(-1, 7) << endl;   //Companies are out of range so inSameCompany returns false

    //At this point, all the companies are in their original states. 
    //Now testing implementations of merge, split and inSameCompany under normal conditions

    //Testing the example provided on the course website
    //I am printing the status of all companies after each of the commands below
    track->merge(0, 1);

    cout << boolalpha << track->inSameCompany(0, 1) << endl;
    cout << boolalpha << track->inSameCompany(0, 2) << endl;
    cout << boolalpha << track->inSameCompany(0, 3) << endl;
    cout << boolalpha << track->inSameCompany(0, 4) << endl;

    cout << boolalpha << track->inSameCompany(1, 2) << endl;
    cout << boolalpha << track->inSameCompany(1, 3) << endl;
    cout << boolalpha << track->inSameCompany(1, 4) << endl;

    cout << boolalpha << track->inSameCompany(2, 3) << endl;
    cout << boolalpha << track->inSameCompany(2, 4) << endl;

    cout << boolalpha << track->inSameCompany(3, 4) << endl;

    cout << boolalpha << track->inSameCompany(0, 0) << endl;
    cout << boolalpha << track->inSameCompany(1, 1) << endl;
    cout << boolalpha << track->inSameCompany(2, 2) << endl;
    cout << boolalpha << track->inSameCompany(3, 3) << endl;
    cout << boolalpha << track->inSameCompany(4, 4) << endl;

    track->merge(2, 3);

    cout << boolalpha << track->inSameCompany(0, 1) << endl;
    cout << boolalpha << track->inSameCompany(0, 2) << endl;
    cout << boolalpha << track->inSameCompany(0, 3) << endl;
    cout << boolalpha << track->inSameCompany(0, 4) << endl;

    cout << boolalpha << track->inSameCompany(1, 2) << endl;
    cout << boolalpha << track->inSameCompany(1, 3) << endl;
    cout << boolalpha << track->inSameCompany(1, 4) << endl;

    cout << boolalpha << track->inSameCompany(2, 3) << endl;
    cout << boolalpha << track->inSameCompany(2, 4) << endl;

    cout << boolalpha << track->inSameCompany(3, 4) << endl;

    cout << boolalpha << track->inSameCompany(0, 0) << endl;
    cout << boolalpha << track->inSameCompany(1, 1) << endl;
    cout << boolalpha << track->inSameCompany(2, 2) << endl;
    cout << boolalpha << track->inSameCompany(3, 3) << endl;
    cout << boolalpha << track->inSameCompany(4, 4) << endl;

    track->merge(0, 3);

    cout << boolalpha << track->inSameCompany(0, 1) << endl;
    cout << boolalpha << track->inSameCompany(0, 2) << endl;
    cout << boolalpha << track->inSameCompany(0, 3) << endl;
    cout << boolalpha << track->inSameCompany(0, 4) << endl;

    cout << boolalpha << track->inSameCompany(1, 2) << endl;
    cout << boolalpha << track->inSameCompany(1, 3) << endl;
    cout << boolalpha << track->inSameCompany(1, 4) << endl;

    cout << boolalpha << track->inSameCompany(2, 3) << endl;
    cout << boolalpha << track->inSameCompany(2, 4) << endl;

    cout << boolalpha << track->inSameCompany(3, 4) << endl;

    cout << boolalpha << track->inSameCompany(0, 0) << endl;
    cout << boolalpha << track->inSameCompany(1, 1) << endl;
    cout << boolalpha << track->inSameCompany(2, 2) << endl;
    cout << boolalpha << track->inSameCompany(3, 3) << endl;
    cout << boolalpha << track->inSameCompany(4, 4) << endl;

    track->split(2);

    cout << boolalpha << track->inSameCompany(0, 1) << endl;
    cout << boolalpha << track->inSameCompany(0, 2) << endl;
    cout << boolalpha << track->inSameCompany(0, 3) << endl;
    cout << boolalpha << track->inSameCompany(0, 4) << endl;

    cout << boolalpha << track->inSameCompany(1, 2) << endl;
    cout << boolalpha << track->inSameCompany(1, 3) << endl;
    cout << boolalpha << track->inSameCompany(1, 4) << endl;

    cout << boolalpha << track->inSameCompany(2, 3) << endl;
    cout << boolalpha << track->inSameCompany(2, 4) << endl;

    cout << boolalpha << track->inSameCompany(3, 4) << endl;

    cout << boolalpha << track->inSameCompany(0, 0) << endl;
    cout << boolalpha << track->inSameCompany(1, 1) << endl;
    cout << boolalpha << track->inSameCompany(2, 2) << endl;
    cout << boolalpha << track->inSameCompany(3, 3) << endl;
    cout << boolalpha << track->inSameCompany(4, 4) << endl;

    track->split(2);

    cout << boolalpha << track->inSameCompany(0, 1) << endl;
    cout << boolalpha << track->inSameCompany(0, 2) << endl;
    cout << boolalpha << track->inSameCompany(0, 3) << endl;
    cout << boolalpha << track->inSameCompany(0, 4) << endl;

    cout << boolalpha << track->inSameCompany(1, 2) << endl;
    cout << boolalpha << track->inSameCompany(1, 3) << endl;
    cout << boolalpha << track->inSameCompany(1, 4) << endl;

    cout << boolalpha << track->inSameCompany(2, 3) << endl;
    cout << boolalpha << track->inSameCompany(2, 4) << endl;

    cout << boolalpha << track->inSameCompany(3, 4) << endl;

    cout << boolalpha << track->inSameCompany(0, 0) << endl;
    cout << boolalpha << track->inSameCompany(1, 1) << endl;
    cout << boolalpha << track->inSameCompany(2, 2) << endl;
    cout << boolalpha << track->inSameCompany(3, 3) << endl;
    cout << boolalpha << track->inSameCompany(4, 4) << endl;

    track->merge(2, 4);

    cout << boolalpha << track->inSameCompany(0, 1) << endl;
    cout << boolalpha << track->inSameCompany(0, 2) << endl;
    cout << boolalpha << track->inSameCompany(0, 3) << endl;
    cout << boolalpha << track->inSameCompany(0, 4) << endl;

    cout << boolalpha << track->inSameCompany(1, 2) << endl;
    cout << boolalpha << track->inSameCompany(1, 3) << endl;
    cout << boolalpha << track->inSameCompany(1, 4) << endl;

    cout << boolalpha << track->inSameCompany(2, 3) << endl;
    cout << boolalpha << track->inSameCompany(2, 4) << endl;

    cout << boolalpha << track->inSameCompany(3, 4) << endl;

    cout << boolalpha << track->inSameCompany(0, 0) << endl;
    cout << boolalpha << track->inSameCompany(1, 1) << endl;
    cout << boolalpha << track->inSameCompany(2, 2) << endl;
    cout << boolalpha << track->inSameCompany(3, 3) << endl;
    cout << boolalpha << track->inSameCompany(4, 4) << endl;

    track->split(0);

    //This is the final status of all companies after all of the calls in the example case were executed
    cout << boolalpha << track->inSameCompany(0, 1) << endl;
    cout << boolalpha << track->inSameCompany(0, 2) << endl;
    cout << boolalpha << track->inSameCompany(0, 3) << endl;
    cout << boolalpha << track->inSameCompany(0, 4) << endl;

    cout << boolalpha << track->inSameCompany(1, 2) << endl;
    cout << boolalpha << track->inSameCompany(1, 3) << endl;
    cout << boolalpha << track->inSameCompany(1, 4) << endl;

    cout << boolalpha << track->inSameCompany(2, 3) << endl;
    cout << boolalpha << track->inSameCompany(2, 4) << endl;

    cout << boolalpha << track->inSameCompany(3, 4) << endl;

    cout << boolalpha << track->inSameCompany(0, 0) << endl;
    cout << boolalpha << track->inSameCompany(1, 1) << endl;
    cout << boolalpha << track->inSameCompany(2, 2) << endl;
    cout << boolalpha << track->inSameCompany(3, 3) << endl;
    cout << boolalpha << track->inSameCompany(4, 4) << endl;

    delete track;
    return 0;
}



