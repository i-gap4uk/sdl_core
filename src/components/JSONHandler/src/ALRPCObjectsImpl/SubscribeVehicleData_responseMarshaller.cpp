#include "../../include/JSONHandler/ALRPCObjects/SubscribeVehicleData_response.h"
#include "ResultMarshaller.h"
#include "VehicleDataResultMarshaller.h"

#include "SubscribeVehicleData_responseMarshaller.h"


/*
  interface	Ford Sync RAPI
  version	2.0L
  date		2012-09-13
  generated at	Wed Oct 24 13:40:36 2012
  source stamp	Wed Oct 24 13:40:27 2012
  author	robok0der
*/


bool SubscribeVehicleData_responseMarshaller::checkIntegrity(SubscribeVehicleData_response& s)
{
  return checkIntegrityConst(s);
}


bool SubscribeVehicleData_responseMarshaller::fromString(const std::string& s,SubscribeVehicleData_response& e)
{
  try
  {
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(s,json,false))  return false;
    if(!fromJSON(json,e))  return false;
  }
  catch(...)
  {
    return false;
  }
  return true;
}


const std::string SubscribeVehicleData_responseMarshaller::toString(const SubscribeVehicleData_response& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool SubscribeVehicleData_responseMarshaller::checkIntegrityConst(const SubscribeVehicleData_response& s)
{
  if(!ResultMarshaller::checkIntegrityConst(s.resultCode))  return false;
  if(s.info && s.info->length()>1000)  return false;
  if(s.dataResult)
  {
    unsigned int i=s.dataResult[0].size();
    if(i>100 || i<1)  return false;
    while(i--)
    {
    if(!VehicleDataResultMarshaller::checkIntegrityConst(s.dataResult[0][i]))   return false;
    }
  }
  return true;
}

Json::Value SubscribeVehicleData_responseMarshaller::toJSON(const SubscribeVehicleData_response& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["response"]=Json::Value(Json::objectValue);
  json["response"]["name"]=Json::Value("SubscribeVehicleData");
  json["response"]["correlationID"]=Json::Value(e.getCorrelationID());

  Json::Value j=Json::Value(Json::objectValue);

  j["success"]=Json::Value(e.success);

  j["resultCode"]=ResultMarshaller::toJSON(e.resultCode);

  if(e.info)
    j["info"]=Json::Value(*e.info);

  if(e.dataResult)
  {
    unsigned int sz=e.dataResult->size();
    j["dataResult"]=Json::Value(Json::arrayValue);
    j["dataResult"].resize(sz);
    for(unsigned int i=0;i<sz;i++)
      j["dataResult"][i]=VehicleDataResultMarshaller::toJSON(e.dataResult[0][i]);
  }

  json["response"]["parameters"]=j;
  return json;
}


bool SubscribeVehicleData_responseMarshaller::fromJSON(const Json::Value& js,SubscribeVehicleData_response& c)
{
  if(c.info)  delete c.info;
  c.info=0;

  if(c.dataResult)  delete c.dataResult;
  c.dataResult=0;

  try
  {
    if(!js.isObject())  return false;

    if(!js.isMember("response"))  return false;

    if(!js["response"].isObject())  return false;
    const Json::Value& j2=js["response"];

    if(!j2.isMember("name") || !j2["name"].isString() || j2["name"].asString().compare("SubscribeVehicleData"))  return false;
    if(!j2.isMember("correlationID") || !j2["correlationID"].isInt())  return false;
    c.setCorrelationID(j2["correlationID"].asInt());

    if(!j2.isMember("parameters"))  return false;
    const Json::Value& json=j2["parameters"];
    if(!json.isObject())  return false;
    if(!json.isMember("success"))  return false;
    {
      const Json::Value& j=json["success"];
      if(!j.isBool())  return false;
      c.success=j.asBool();
    }
    if(!json.isMember("resultCode"))  return false;
    {
      const Json::Value& j=json["resultCode"];
      if(!ResultMarshaller::fromJSON(j,c.resultCode))
        return false;
    }
    if(json.isMember("info"))
    {
      const Json::Value& j=json["info"];
      if(!j.isString())  return false;
      c.info=new std::string(j.asString());
    }
    if(json.isMember("dataResult"))
    {
      const Json::Value& j=json["dataResult"];
      if(!j.isArray())  return false;
      c.dataResult=new std::vector<VehicleDataResult>();
      c.dataResult->resize(j.size());
      for(unsigned int i=0;i<j.size();i++)
      {
        VehicleDataResult t;
        if(!VehicleDataResultMarshaller::fromJSON(j[i],t))
          return false;
        c.dataResult[0][i]=t;
      }

    }

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}

