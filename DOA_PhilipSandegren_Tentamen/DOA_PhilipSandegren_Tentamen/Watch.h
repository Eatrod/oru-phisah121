/* 
* File:   Watch.h
*
* Created on January 1, 2013, 1:43 PM
*/

#ifndef WATCH_H
#define	WATCH_H

#include <iostream>
#include <chrono>
using namespace std;

namespace Course
{
	using namespace std::chrono;

	typedef std::chrono::high_resolution_clock clock;
	typedef std::chrono::microseconds microseconds;
	typedef std::chrono::milliseconds milliseconds;

	class Watch {
	public:
		static clock::time_point now(){return clock::now();}

		static microseconds intervalUs(const clock::time_point& t1, const clock::time_point& t0)
		{
			return std::chrono::duration_cast<microseconds>(t1 - t0);
		}

		static milliseconds intervalMs(const clock::time_point& t1,const clock::time_point& t0)
		{
			return std::chrono::duration_cast<milliseconds>(t1 - t0);
		}
	private:
		clock::time_point start_;
	public:
		Watch() : start_(clock::now()) {}
		Watch(const Watch& orig) {}

		clock::time_point restart() { start_ = clock::now(); return start_;}
		microseconds elapsedUs()    { return intervalUs(clock::now(), start_);}
		milliseconds elapsedMs()    { return intervalMs(clock::now(), start_);}

		virtual ~Watch() {}

	};
}
#endif	/* WATCH_H */



