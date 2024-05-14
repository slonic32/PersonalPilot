#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <chrono>
#include <ctime>

class DateTime
{
private:
    std::chrono::system_clock::time_point timePoint;

public:
    DateTime();

    // Method to input date and time from user
    static DateTime fromStr(const std::string &);

    // Method to print date and time
    static std::string toStr(const DateTime &);

    // Method to save date and time to file
    void saveToFile(const std::string &filename) const;

    // Method to read date and time from file
    void readFromFile(const std::string &filename);

    // Comparison operators
    bool operator==(const DateTime &other) const;

    bool operator<=(const DateTime &other) const;

    bool operator>=(const DateTime &other) const;

private:
    // Helper method to convert string to time_point
    static std::chrono::system_clock::time_point stringToTime(const std::string &timeStr);
};

#endif // DATE_H