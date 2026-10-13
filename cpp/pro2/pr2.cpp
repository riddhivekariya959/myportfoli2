#include <iostream>
#include <cstring>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:

    // Default Constructor
    Train()
    {
        trainNumber = 0;

        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");

        trainCount++;
    }

    // Parameterized Constructor
    Train(int number, const char name[],
          const char src[], const char dest[],
          const char time[])
    {
        trainNumber = number;

        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);

        trainCount++;
    }

    // Destructor
    ~Train()
    {
        trainCount--;
    }

    // Setters
    void setTrainNumber(int number)
    {
        trainNumber = number;
    }

    void setTrainName(const char name[])
    {
        strcpy(trainName, name);
    }

    void setSource(const char src[])
    {
        strcpy(source, src);
    }

    void setDestination(const char dest[])
    {
        strcpy(destination, dest);
    }

    void setTrainTime(const char time[])
    {
        strcpy(trainTime, time);
    }

    // Getters
    int getTrainNumber() const
    {
        return trainNumber;
    }

    const char* getTrainName() const
    {
        return trainName;
    }

    const char* getSource() const
    {
        return source;
    }

    const char* getDestination() const
    {
        return destination;
    }

    const char* getTrainTime() const
    {
        return trainTime;
    }

    static int getTrainCount()
    {
        return trainCount;
    }

    // Input Train Details
    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cin.ignore(1000, '\n');

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    // Display Train Details
    void displayTrainDetails() const
    {
        cout << "\nTrain Details:" << endl;

        cout << "Train Number: "
             << trainNumber << endl;

        cout << "Train Name: "
             << trainName << endl;

        cout << "Source: "
             << source << endl;

        cout << "Destination: "
             << destination << endl;

        cout << "Train Time: "
             << trainTime << endl;
    }
};

// Initialize Static Data Member
int Train::trainCount = 0;


// RailwaySystem Class
class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:

    // Constructor
    RailwaySystem()
    {
        totalTrains = 0;
    }

    // Add Train
    void addTrain()
    {
        if (totalTrains >= 100)
        {
            cout << "Train records are full!" << endl;
            return;
        }

        int number;

        cout << "\nEnter Train Number: ";
        cin >> number;

        // Check duplicate train number
        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "Train number already exists!"
                     << endl;
                return;
            }
        }

        trains[totalTrains].setTrainNumber(number);

        cin.ignore(1000, '\n');

        char name[50];
        char src[50];
        char dest[50];
        char time[10];

        cout << "Enter Train Name: ";
        cin.getline(name, 50);

        cout << "Enter Source: ";
        cin.getline(src, 50);

        cout << "Enter Destination: ";
        cin.getline(dest, 50);

        cout << "Enter Train Time: ";
        cin.getline(time, 10);

        trains[totalTrains].setTrainName(name);
        trains[totalTrains].setSource(src);
        trains[totalTrains].setDestination(dest);
        trains[totalTrains].setTrainTime(time);

        totalTrains++;

        cout << "\nTrain added successfully!" << endl;
    }

    // Display All Trains
    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "\nNo train records available."
                 << endl;
            return;
        }

        for (int i = 0; i < totalTrains; i++)
        {
            cout << "\nTrain " << i + 1;

            trains[i].displayTrainDetails();
        }

        cout << "\nTotal Train Records: "
             << totalTrains << endl;
    }

    // Search Train by Number
    void searchTrainByNumber(int number)
    {
        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain found!";

                trains[i].displayTrainDetails();

                return;
            }
        }

        cout << "\nTrain number "
             << number << " not found!" << endl;
    }
};


// Main Function
int main()
{
    RailwaySystem railway;

    int choice;
    int number;

    // Enter at least three train records initially
    cout << "Enter 3 Train Records Initially\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "\nEnter Details of Train "
             << i + 1 << endl;

        railway.addTrain();
    }

    do
    {
        cout << "\n--- Railway Reservation System Menu ---"
             << endl;

        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                railway.addTrain();
                break;

            case 2:
                railway.displayAllTrains();
                break;

            case 3:
                cout << "Enter Train Number to search: ";
                cin >> number;

                railway.searchTrainByNumber(number);
                break;

            case 4:
                cout << "Exiting the system. Goodbye!"
                     << endl;
                break;

            default:
                cout << "Invalid choice! Try again."
                     << endl;
        }

    } while (choice != 4);

    return 0;
}
