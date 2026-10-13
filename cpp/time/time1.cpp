#include <iostream>
using namespace std;

class TimeConverter
{
public:
    int seconds;
    int hours, minutes, secs;

    // Convert seconds to HH:MM:SS
    void secondsToTime()
    {
        cout << "Enter total seconds: ";
        cin >> seconds;

        hours = seconds / 3600;
        seconds = seconds % 3600;

        minutes = seconds / 60;
        secs = seconds % 60;

        cout << "HH:MM:SS => "
             << hours << ":"
             << minutes << ":"
             << secs << endl;
    }

    // Convert HH:MM:SS to seconds
    void timeToSeconds()
    {
        cout << "Enter hours: ";
        cin >> hours;

        cout << "Enter minutes: ";
        cin >> minutes;

        cout << "Enter seconds: ";
        cin >> secs;

        int totalSeconds = (hours * 3600) +
                           (minutes * 60) +
                           secs;

        cout << "Total seconds: " << totalSeconds << endl;
    }
};

int main()
{
    TimeConverter t;

    cout << "----- Seconds to HH:MM:SS -----" << endl;
    t.secondsToTime();

    cout << endl;

    cout << "----- HH:MM:SS to Seconds -----" << endl;
    t.timeToSeconds();

    return 0;
}
