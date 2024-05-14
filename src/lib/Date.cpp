#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <chrono>
#include <ctime>
#include "Date.h"
#include <sstream>

DateTime::DateTime() {}

// Method to input date and time from user
DateTime DateTime::fromStr(const std::string &strDate)
{

    DateTime date;

    // Convert string to time_point
    date.timePoint = stringToTime(strDate);
    return date;
}

// Method to print date and time
std::string DateTime::toStr(const DateTime &date)
{
    std::stringstream ss;
    std::time_t time = std::chrono::system_clock::to_time_t(date.timePoint);
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");

    return ss.str();
}

// Method to save date and time to file
void DateTime::saveToFile(const std::string &filename) const
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        throw std::runtime_error("Failed to open file for writing.");
    }
    std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
    outFile << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
}

// Method to read date and time from file
void DateTime::readFromFile(const std::string &filename)
{
    std::ifstream inFile(filename);
    if (!inFile)
    {
        throw std::runtime_error("Failed to open file for reading.");
    }
    std::string dateTimeStr;
    std::getline(inFile, dateTimeStr);
    timePoint = stringToTime(dateTimeStr);
}

// Comparison operators
bool DateTime::operator==(const DateTime &other) const
{
    return timePoint == other.timePoint;
}

bool DateTime::operator<=(const DateTime &other) const
{
    return timePoint <= other.timePoint;
}

bool DateTime::operator>=(const DateTime &other) const
{
    return timePoint >= other.timePoint;
}

// Helper method to convert string to time_point
std::chrono::system_clock::time_point DateTime::stringToTime(const std::string &timeStr)
{
    std::tm tm = {};
    std::istringstream ss(timeStr);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    if (ss.fail())
    {
        throw std::runtime_error("Failed to parse date and time string.");
    }
    std::time_t t = std::mktime(&tm);
    if (t == -1)
    {
        throw std::runtime_error("Invalid date and time.");
    }
    return std::chrono::system_clock::from_time_t(t);
}
