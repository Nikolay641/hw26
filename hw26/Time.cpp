#include "Time.h"

Time_::Time_()
{
    struct tm* tim = new tm;
    time_t tt = time(NULL);
    localtime_s(tim, &tt);

    seconds = tim->tm_sec;
    minutes = tim->tm_min;
    hour = tim->tm_hour;
    format = true;
}

Time_::Time_(int hour, int minutes, int seconds, bool format)
{
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
    this->format = format;
}

Time_::Time_(const Time_& obj)
{
    this->hour = obj.hour;
    this->minutes = obj.minutes;
    this->seconds = obj.seconds;
    this->format = obj.format;
}

Time_& Time_::operator=(const Time_& obj)
{
    this->hour = obj.hour;
    this->minutes = obj.minutes;
    this->seconds = obj.seconds;
    this->format = obj.format;
    return *this;
}

void Time_::setHour(int hour)
{
    this->hour = hour;
}

int Time_::getHour() const
{
    return hour;
}

void Time_::setMinutes(int minutes)
{
    this->minutes = minutes;
}

int Time_::getMinutes() const
{
    return minutes;
}

void Time_::setSeconds(int seconds)
{
    this->seconds = seconds;
}

int Time_::getSeconds() const
{
    return seconds;
}

void Time_::setFormat(bool format)
{
    this->format = format;
}

bool Time_::getFormat() const
{
    return format;
}

bool Time_::valid() const
{
    if (hour < 0 || hour > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {
        return false;
    }
    if (format == true) {
        return true;
    }
    else {
        if (hour < 1 || hour > 12) {
            return false;
        }
        return true;
    }
}

void Time_::tickTime()
{
    seconds++;
    if (seconds > 59) {
        seconds = 0;
        minutes++;
        if (minutes > 59) {
            minutes = 0;
            hour++;
            if (hour > 23 && format == true) {
                hour = 0;
            }
            if (hour > 12 && format != true) {
                hour = 1;
            }
        }
    }
}

void Time_::untickTime()
{
    seconds--;
    if (seconds < 0) {
        seconds = 59;
        minutes--;
        if (minutes < 0) {
            minutes = 59;
            hour--;
            if (hour < 0 && format == true) {
                hour = 23;
            }
            if (hour < 0 && format != true) {
                hour = 12;
            }
        }
    }
}

void Time_::showTime() const
{
    if (format == true) {
        cout << hour << ":" << minutes << ":" << seconds;
    }
    else {
        int hourCheck = hour % 12;
        if (hourCheck == 0) hourCheck = 12;
        cout << hourCheck << ":" << minutes << ":" << seconds << (hour < 12 ? " AM" : " PM");
    }
}

bool Time_::operator==(const Time_& obj) const&
{
    return this->seconds == obj.seconds && this->minutes == obj.minutes && this->hour == obj.hour;
}

bool Time_::operator!=(const Time_& obj) const&
{
    return !(*this == obj);
}

bool Time_::operator>(const Time_& obj) const&
{
    if (this->hour > obj.hour) return true;
    if (this->hour < obj.hour) return false;
    if (this->minutes > obj.minutes) return true;
    if (this->minutes < obj.minutes) return false;
    return this->seconds > obj.seconds;
}

bool Time_::operator<(const Time_& obj) const&
{
    if (this->hour < obj.hour) return true;
    if (this->hour > obj.hour) return false;
    if (this->minutes < obj.minutes) return true;
    if (this->minutes > obj.minutes) return false;
    return this->seconds < obj.seconds;
}

bool Time_::operator>=(const Time_& obj) const&
{
    return (*this > obj) || *this == obj;
}

bool Time_::operator<=(const Time_& obj) const&
{
    return (*this < obj) || *this == obj;
}

Time_& Time_::operator+=(int s)
{
    for (int i = 0; i < s; i++) {
        tickTime();
    }
    return *this;
}

Time_& Time_::operator-=(int s)
{
    for (int i = 0; i < s; i++) {
        untickTime();
    }
    return *this;
}

Time_& Time_::operator+=(float m)
{
    int toMinToSec = (int)(m * 60);
    *this += toMinToSec;
    return *this;
}

Time_& Time_::operator-=(float m)
{
    int toMinToSec = (int)(m * 60);
    *this -= toMinToSec;
    return *this;
}

Time_& Time_::operator+=(long h)
{
    this->hour += h;

    if (hour > 23 && format == true) {
        hour = hour % 24;
    }

    if (hour > 12 && format != true) {
        hour = hour % 12;
    }

    return *this;
}

Time_& Time_::operator-=(long h)
{
    this->hour -= h;
    if (hour < 0 && format == true) {
        hour = (hour % 24) + 24;
    }

    if (hour < 0 && !format != true) {
        hour = (hour % 12) + 12;
    }
    return *this;
}

Time_ Time_::operator+(int s) const&
{
    Time_ tmp = *this;
    tmp += s;
    return tmp;
}

Time_ Time_::operator-(int s) const&
{
    Time_ tmp = *this;
    tmp -= s;
    return tmp;
}

Time_ Time_::operator+(float m) const&
{
    Time_ tmp = *this;
    tmp += m;
    return tmp;
}

Time_ Time_::operator-(float m) const&
{
    Time_ tmp = *this;
    tmp -= m;
    return tmp;
}

Time_ Time_::operator+(long h) const&
{
    Time_ tmp = *this;
    tmp += h;
    return tmp;
}

Time_ Time_::operator-(long h) const&
{
    Time_ tmp = *this;
    tmp -= h;
    return tmp;
}

Time_& Time_::operator--()
{
    this->untickTime();
    return *this;
}

Time_ Time_::operator--(int)
{
    Time_ tmp = *this;
    this->untickTime();
    return tmp;
}

Time_& Time_::operator++()
{
    this->tickTime();
    return *this;
}

Time_ Time_::operator++(int)
{
    Time_ tmp = *this;
    this->tickTime();
    return tmp;
}

Time_ operator+(int seconds, const Time_& a)
{
    return a + seconds;
}

Time_ operator-(int seconds, const Time_& a)
{
    return a - seconds;
}

Time_ operator+(float minutes, const Time_& a)
{
    return a + minutes;
}

Time_ operator-(float minutes, const Time_& a)
{
    return a - minutes;
}

Time_ operator+(long hours, const Time_& a)
{
    return a + hours;
}

Time_ operator-(long hours, const Time_& a)
{
    return a - hours;
}

ostream& operator<<(ostream& os, const Time_& t)
{
    os << t.hour << ":" << t.minutes << ":" << t.seconds;
    return os;
}

istream& operator>>(istream& is, Time_& t)
{
    do
    {
        cout << "Input time(hour:minutes:seconds): ";
        is >> t.hour >> t.minutes >> t.seconds;
    } while (!t.valid());
    return is;
}
