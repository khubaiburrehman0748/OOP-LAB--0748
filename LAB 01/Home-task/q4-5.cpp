#include <iostream>
#include <string>

using namespace std;

int main() {

    string cities[4];
    int dailyAQI[4][28];
    float averageAQI[4];
    int totalAQI;

    for (int cityIndex = 0; cityIndex < 4; cityIndex++) {
        totalAQI = 0;
        cout << "Enter the name of city " << cityIndex + 1 << ": ";
        cin >> cities[cityIndex];

        for (int dayIndex = 0; dayIndex < 28; dayIndex++) {
            cout << "Enter the AQI for " << cities[cityIndex] << " on day " << dayIndex + 1 << ": ";
            cin >> dailyAQI[cityIndex][dayIndex];
            totalAQI += dailyAQI[cityIndex][dayIndex];
        }
        averageAQI[cityIndex] = static_cast<float>(totalAQI) / 28;
    }

    cout << "\nWeekly AQI Report:\n";
    float weeklyAverageAQI[4][4];
    for (int cityIndex = 0; cityIndex < 4; cityIndex++) {
        for (int weekIndex = 0; weekIndex < 4; weekIndex++) {
            int weeklySum = 0;
            for (int dayIndex = weekIndex * 7; dayIndex < (weekIndex + 1) * 7; dayIndex++) {
                weeklySum += dailyAQI[cityIndex][dayIndex];
            }
            weeklyAverageAQI[cityIndex][weekIndex] = static_cast<float>(weeklySum) / 7;
            cout << "Week " << weekIndex + 1 << " average AQI for " << cities[cityIndex] << ": "
                 << weeklyAverageAQI[cityIndex][weekIndex] << endl;
        }
    }

    float maxAQIDecrease = 0;
    int bestImprovementCityIndex = 0;
    for (int cityIndex = 0; cityIndex < 4; cityIndex++) {
        float improvement = weeklyAverageAQI[cityIndex][0] - weeklyAverageAQI[cityIndex][3];
        if (improvement > maxAQIDecrease) {
            maxAQIDecrease = improvement;
            bestImprovementCityIndex = cityIndex;
        }
    }

    cout << "City with the most improved air quality: " << cities[bestImprovementCityIndex] 
         << " with a reduction of " << maxAQIDecrease << " AQI points.\n";

    cout << "\nFinal AQI Report:\n";
    for (int cityIndex = 0; cityIndex < 4; cityIndex++) {
        cout << "\nCity: " << cities[cityIndex] << endl;
        cout << "Monthly Average AQI: " << averageAQI[cityIndex] << endl;
        cout << "Weekly AQI Averages: ";
        
        for (int weekIndex = 0; weekIndex < 4; weekIndex++) {
            cout << "Week " << weekIndex + 1 << ": " << weeklyAverageAQI[cityIndex][weekIndex] << " ";
        }
        cout << endl;

        cout << "Critical Pollution Days (AQI > 150): ";
        bool criticalDaysFound = false;
        for (int dayIndex = 0; dayIndex < 28; dayIndex++) {
            if (dailyAQI[cityIndex][dayIndex] > 150) {
                cout << "Day " << dayIndex + 1 << " ";
                criticalDaysFound = true;
            }
        }
        if (!criticalDaysFound) {
            cout << "None";
        }
        cout << endl;

        int highestAQI = dailyAQI[cityIndex][0], lowestAQI = dailyAQI[cityIndex][0];
        for (int dayIndex = 1; dayIndex < 28; dayIndex++) {
            if (dailyAQI[cityIndex][dayIndex] > highestAQI) highestAQI = dailyAQI[cityIndex][dayIndex];
            if (dailyAQI[cityIndex][dayIndex] < lowestAQI) lowestAQI = dailyAQI[cityIndex][dayIndex];
        }

        cout << "Highest AQI recorded: " << highestAQI << endl;
        cout << "Lowest AQI recorded: " << lowestAQI << endl;
    }

    return 0;
}
