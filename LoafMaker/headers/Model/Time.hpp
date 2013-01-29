#ifndef _TIME_HPP_
#define _TIME_HPP_

// Includes:
#include <sstream>
#include <cstring> // memset
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Time
{
    private:
        time_t timestamp;

    public:
       ~Time ();
        Time ( int minute = -1,
               int hour	= -1,
               int day = -1,
               int month	= -1,
               int year	= -1 );

//Time::~Time ();

        Time& operator= ( const Time &time );
        bool operator== ( const Time &time ) const;
        bool operator!= ( const Time &time ) const;
        bool operator< ( const Time &time ) const;
        bool operator> ( const Time &time ) const;
        bool operator<= ( const Time &time ) const;
        bool operator>= ( const Time &time ) const;

        void setWeek ( const int &week );
        void setDate ( int minute = -1, int hour = -1,
                        int day = -1, int month = -1, int year = -1 );
        void nextDay ();
        void previousDay ();

        int getMinute () const;
        int getHour	() const;
        int getDay	() const;
        int getWeek	() const;
        int getWeekDay () const;
        int getMonth () const;
        int getYear	() const;
        string getSimpleDate	() const;
        string getXmlDate	() const;
        string getReadableDate	() const;
};

#endif
