#include "../../include/JSONHandler/ALRPCObjects/DeleteFile_request.h"
#include "DeleteFile_requestMarshaller.h"
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

DeleteFile_request& DeleteFile_request::operator =(const DeleteFile_request& c)
{
  syncFileName= c.syncFileName ? new std::string(c.syncFileName[0]) : 0;

  return *this;}


DeleteFile_request::~DeleteFile_request(void)
{
  if(syncFileName)
    delete syncFileName;
}


DeleteFile_request::DeleteFile_request(const DeleteFile_request& c)
{
  *this=c;
}


bool DeleteFile_request::checkIntegrity(void)
{
  return DeleteFile_requestMarshaller::checkIntegrity(*this);
}


DeleteFile_request::DeleteFile_request(void) : ALRPCRequest(PROTOCOL_VERSION,Marshaller::METHOD_DELETEFILE_REQUEST),
      syncFileName(0)
{
}



bool DeleteFile_request::set_syncFileName(const std::string& syncFileName_)
{
  if(syncFileName_.length()>500)  return false;
  delete syncFileName;
  syncFileName=0;

  syncFileName=new std::string(syncFileName_);
  return true;
}

void DeleteFile_request::reset_syncFileName(void)
{
  if(syncFileName)
    delete syncFileName;
  syncFileName=0;
}




const std::string* DeleteFile_request::get_syncFileName(void) const 
{
  return syncFileName;
}

