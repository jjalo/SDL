// Copyright anssi.grohn@karelia.fi (c) 2014.
// Licensed under GPLv3.
#include <Logger.h>
////////////////////////////////////////////////////////////////////////////////
Logger * Logger::logger = NULL;
////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
string 
Logger::Time()
{
  char buf[256];
  time_t t;
  struct tm *timeinfo;
  time(&t);
  timeinfo = localtime(&t);
  strftime( buf, 256, "%Y-%m-%d %H:%M:%S", timeinfo);
  return string(buf);
}
////////////////////////////////////////////////////////////////////////////////
