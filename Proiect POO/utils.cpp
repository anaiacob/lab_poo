#include "utils.h"


int getCurrentYear() {
    using namespace std::chrono;
    auto now = system_clock::now();
    auto now_time_t = system_clock::to_time_t(now);
    tm localTime = *std::localtime(&now_time_t);
    return localTime.tm_year + 1900;
}
/*
int countCifreCNP(const string cnp)
{
    int contor = 0;

    for (auto caracter : cnp)
    {
        if (isdigit(caracter))
        {
            contor++;
        }
    }

    return contor;
}
*/

int getCurrentMonth() {
    time_t now = time(nullptr);
    tm* currentTime = localtime(&now);
    return currentTime->tm_mon + 1;
}
