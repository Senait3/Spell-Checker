/* 
--------------------------------- Simple Timer 
--------------------------------------------
- Vachik Dave
*/
#include <sys/time.h>
#include <cstddef>
/*struct timeval{
long    tv_sec;         // seconds
long    tv_usec;        // microseconds
};
*/
class TimeInterval{
public:
timeval start_time;
timeval end_time;
public:
TimeInterval();
void start();
void stop();
float GetInterval();
};
TimeInterval::TimeInterval(){}
void TimeInterval::start()
{
gettimeofday(&this->start_time, NULL);
}
void TimeInterval::stop()
{
gettimeofday(&this->end_time, NULL);
}
float TimeInterval::GetInterval()
{
float t =(float)(end_time.tv_sec-start_time.tv_sec)*1000000.0+(float)
(end_time.tv_usec-start_time.tv_usec); // in micro-sec
// t = t / 1000000.0 // in sec
return t;
}
