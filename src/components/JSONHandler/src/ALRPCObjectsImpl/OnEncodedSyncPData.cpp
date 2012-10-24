#include "../../include/JSONHandler/ALRPCObjects/OnEncodedSyncPData.h"
#include "OnEncodedSyncPDataMarshaller.h"
#include "../../include/JSONHandler/ALRPCObjects/Marshaller.h"

#define PROTOCOL_VERSION	1


/*
  interface	Ford Sync RAPI
  version	2.0L
  date		2012-09-13
  generated at	Wed Oct 24 13:40:36 2012
  source stamp	Wed Oct 24 13:40:27 2012
  author	robok0der
*/

OnEncodedSyncPData& OnEncodedSyncPData::operator =(const OnEncodedSyncPData& c)
{
  data= c.data ? new std::vector<std::string>(c.data[0]) : 0;
  URL= c.URL ? new std::string(c.URL[0]) : 0;
  Timeout= c.Timeout ? new int(c.Timeout[0]) : 0;

  return *this;}


OnEncodedSyncPData::~OnEncodedSyncPData(void)
{
  if(data)
    delete data;
  if(URL)
    delete URL;
  if(Timeout)
    delete Timeout;
}


OnEncodedSyncPData::OnEncodedSyncPData(const OnEncodedSyncPData& c)
{
  *this=c;
}


bool OnEncodedSyncPData::checkIntegrity(void)
{
  return OnEncodedSyncPDataMarshaller::checkIntegrity(*this);
}


OnEncodedSyncPData::OnEncodedSyncPData(void) : ALRPCNotification(PROTOCOL_VERSION,Marshaller::METHOD_ONENCODEDSYNCPDATA),
      data(0),
    URL(0),
    Timeout(0)
{
}



bool OnEncodedSyncPData::set_data(const std::vector<std::string>& data_)
{
  unsigned int i=data_.size();
  if(i>100 || i<1)  return false;
  while(i--)
  {
    if(data_[i].length()>10000)  return false;
  }
  delete data;
  data=0;

  data=new std::vector<std::string>(data_);
  return true;
}

void OnEncodedSyncPData::reset_data(void)
{
  if(data)
    delete data;
  data=0;
}

bool OnEncodedSyncPData::set_URL(const std::string& URL_)
{
  if(URL_.length()>1000)  return false;
  delete URL;
  URL=0;

  URL=new std::string(URL_);
  return true;
}

void OnEncodedSyncPData::reset_URL(void)
{
  if(URL)
    delete URL;
  URL=0;
}

bool OnEncodedSyncPData::set_Timeout(int Timeout_)
{
  if(Timeout_>2000000000)  return false;
  delete Timeout;
  Timeout=0;

  Timeout=new int(Timeout_);
  return true;
}

void OnEncodedSyncPData::reset_Timeout(void)
{
  if(Timeout)
    delete Timeout;
  Timeout=0;
}




const std::vector<std::string>* OnEncodedSyncPData::get_data(void) const 
{
  return data;
}

const std::string* OnEncodedSyncPData::get_URL(void) const 
{
  return URL;
}

const int* OnEncodedSyncPData::get_Timeout(void) const 
{
  return Timeout;
}

