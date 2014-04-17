// Copyright anssi.grohn@karelia.fi (c) 2014.
// Licensed under GPLv3.
#ifndef __Updateable_h__
#define __Updateable_h__
////////////////////////////////////////////////////////////////////////////////
struct Updateable 
{
  virtual ~Updateable(){}
  virtual void Update() = 0;
};
////////////////////////////////////////////////////////////////////////////////
#endif
