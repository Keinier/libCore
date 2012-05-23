#include <ctime>
#include "CTime.h"

namespace System
  {
        //Ctor 
	CClock::CClock()
	{
		mTime=0;
	}
	
	// Dtor
	CClock::~CClock()
	{
	}
	time_t CClock::GetSeconds()
	{
		return mTime;
	}
	
	void CClock::Update()
	{
		
		mTime = time (NULL);
	}
	
	String CClock::GetString(String& format)
	{
  		
  		struct tm * timeinfo;
  		char buffer [100];

  		Update();
  		timeinfo = localtime ( &mTime);

  		strftime (buffer,100,format.c_str(),timeinfo);
  		return String(buffer);
	}
      

	//ctor
	Date_t::Date_t()
	{
		mDay = mMonth = mYear = 0;
	}
	
	Date_t::Date_t(INT day, INT month, INT year)
	{
		struct tm timeinfo;
		timeinfo.tm_mday = mDay = day;
		timeinfo.tm_mon = mMonth = month;
		timeinfo.tm_year = mYear = year;
		mTime = mktime(&timeinfo);
	}
	
	Date_t::Date_t(Date_t& date)
	{
		struct tm timeinfo;
		timeinfo.tm_mday = mDay =  date.GetDay();
		timeinfo.tm_mon = mMonth = date.GetMonth();
		timeinfo.tm_year = mYear = date.GetYear();
		mTime = date.GetSeconds();
		
	}
	

	
	void Date_t::SetDay(UINT value)
	{
		struct tm timeinfo;
		timeinfo.tm_mday = value;
		mTime = mktime(&timeinfo);
	}
	
	void Date_t::SetMonth(UINT value)
	{
		struct tm timeinfo;
		timeinfo.tm_mon = value;
		mTime = mktime(&timeinfo);
	}
	
	void Date_t::SetYear(UINT value)
	{
		struct tm timeinfo;
		timeinfo.tm_year = value + 1900;
		mTime = mktime(&timeinfo);
	}
	
	UINT Date_t::GetDay(void)
	{
		struct tm* timeinfo;
		timeinfo = localtime(&mTime);
		
		return timeinfo->tm_mday;
	}
	
	UINT Date_t::GetMonth(void)
	{
	  	struct tm* timeinfo;
		timeinfo = localtime(&mTime);
		
		return timeinfo->tm_mon;
	}
	
	UINT Date_t::GetYear(void)
	{
	  	struct tm* timeinfo;
		timeinfo = localtime(&mTime);
		
		return timeinfo->tm_year;
	}
	
	bool Date_t::operator >(Date_t b)
	{
	  	return (mTime>b.GetSeconds());
	}
	
	bool Date_t::operator <(Date_t b)
	{
	  	return (mTime<b.GetSeconds());
	}
	
	bool Date_t::operator >=(Date_t b)
	{
	  	return (mTime>=b.GetSeconds());
	}
	
	bool Date_t::operator <=(Date_t b)
	{
	  	return (mTime<=b.GetSeconds());
	}
	
	bool Date_t::operator ==(Date_t b)
	{
	  	return (mTime==b.GetSeconds());
	}

      

	//ctor
	Time_t::Time_t()
	{
		mHour = mMin = mSec = 0;
	}
	
	Time_t::Time_t(UINT hours,UINT minutes,UINT seconds)
	{
		struct tm timeinfo;
		timeinfo.tm_hour = mHour = hours;
		timeinfo.tm_min = mMin = minutes;
		timeinfo.tm_sec = mSec = seconds;
		mTime = mktime(&timeinfo);
		
	}
	
	Time_t::Time_t(Time_t& time)
	{
		mTime = time.GetSecond();
		mHour = time.GetHours();
		mMin = time.GetMinutes();
		mSec = time.GetSecond();
	}
	

	void Time_t::SetHours(UINT value)
	{
		struct tm timeinfo;
		timeinfo.tm_hour = value;
		mTime = mktime(&timeinfo);
	}
	
	void Time_t::SetMinutes(UINT value)
	{
		struct tm timeinfo;
		timeinfo.tm_min = value;
		mTime = mktime(&timeinfo);
	}
	
	void Time_t::SetSeconds(UINT value)
	{
		struct tm timeinfo;
		timeinfo.tm_sec = value;
		mTime = mktime(&timeinfo);
	}
	
	UINT Time_t::GetHours(void)
	{
	  	struct tm* timeinfo;
		timeinfo = localtime(&mTime);
		
		return timeinfo->tm_hour;
	}
	
	UINT Time_t::GetMinutes(void)
	{
	  	struct tm* timeinfo;
		timeinfo = localtime(&mTime);
		
		return timeinfo->tm_min;
	}
	
	UINT Time_t::GetSecond(void)
	{
	  	struct tm* timeinfo;
		timeinfo = localtime(&mTime);
		
		return timeinfo->tm_sec;
	}
	
	bool Time_t::operator >(Time_t b)
	{
	  	return (mTime>b.GetSeconds());
	}
	
	bool Time_t::operator <(Time_t b)
	{
	  	return (mTime<b.GetSeconds());
	}
	
	bool Time_t::operator >=(Time_t b)
	{
	  	return (mTime>=b.GetSeconds());
	}
	
	bool Time_t::operator <=(Time_t b)
	{
	  	return (mTime<=b.GetSeconds());
	}
	
	bool Time_t::operator ==(Time_t b)
	{
	  	return (mTime==b.GetSeconds());
	}

    

	
  }
