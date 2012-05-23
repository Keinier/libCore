#ifndef __CTIME_H__
#define __CTIME_H__

#include "plataform.h"

  namespace System
  {
         
      class APIEXPORT CClock
      {
      protected:
	time_t mTime;
      public:
	//Ctor
	CClock();
	// Dtor
	~CClock();
	void Update();
	time_t GetSeconds();
	String GetString(String& format);
	virtual String Now()=0;
	
      };
      
      // DATE_T
       class APIEXPORT Date_t:private CClock
      {
      protected:
	UINT mDay,mMonth,mYear;
      public:
	//ctor
	Date_t();
	Date_t(INT day, INT month, INT year);
	Date_t(Date_t& date);
	//dtor
	virtual ~Date_t(){}
	
	void SetDay(UINT value);
	void SetMonth(UINT value);
	void SetYear(UINT value);
	
	UINT GetDay(void);
	UINT GetMonth(void);
	UINT GetYear(void);
	
	String Now();
	
	bool operator >(Date_t b);
	bool operator <(Date_t b);
	bool operator >=(Date_t b);
	bool operator <=(Date_t b);
	bool operator ==(Date_t b);
	
      };
      
      //TIME_T
       class APIEXPORT Time_t:private CClock
      {
      protected:
	UINT mHour,mMin,mSec;
      public:
	//ctor
	Time_t();
	Time_t(UINT hours,UINT minutes,UINT seconds);
	Time_t(Time_t& time);
	//dtor
	virtual ~Time_t(){}
	
	void SetHours(UINT value);
	void SetMinutes(UINT value);
	void SetSeconds(UINT value);
	
	UINT GetHours(void);
	UINT GetMinutes(void);
	UINT GetSecond(void);
	String Now();
	
	bool operator >(Time_t b);
	bool operator <(Time_t b);
	bool operator >=(Time_t b);
	bool operator <=(Time_t b);
	bool operator ==(Time_t b);
	
      };
      
      
      
  }
#endif // __CTIME_H__
