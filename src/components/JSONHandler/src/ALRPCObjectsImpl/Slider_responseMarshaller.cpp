#include "../../include/JSONHandler/ALRPCObjects/Slider_response.h"
#include "ResultMarshaller.h"

#include "Slider_responseMarshaller.h"


/*
  interface	Ford Sync RAPI
  version	2.0L
  date		2012-09-13
  generated at	Wed Oct 24 13:40:36 2012
  source stamp	Wed Oct 24 13:40:27 2012
  author	robok0der
*/


bool Slider_responseMarshaller::checkIntegrity(Slider_response& s)
{
  return checkIntegrityConst(s);
}


bool Slider_responseMarshaller::fromString(const std::string& s,Slider_response& e)
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


const std::string Slider_responseMarshaller::toString(const Slider_response& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool Slider_responseMarshaller::checkIntegrityConst(const Slider_response& s)
{
  if(!ResultMarshaller::checkIntegrityConst(s.resultCode))  return false;
  if(s.sliderPosition>26)  return false;
  if(s.sliderPosition<1)  return false;
  return true;
}

Json::Value Slider_responseMarshaller::toJSON(const Slider_response& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["response"]=Json::Value(Json::objectValue);
  json["response"]["name"]=Json::Value("Slider");
  json["response"]["correlationID"]=Json::Value(e.getCorrelationID());

  Json::Value j=Json::Value(Json::objectValue);

  j["success"]=Json::Value(e.success);

  j["resultCode"]=ResultMarshaller::toJSON(e.resultCode);

  j["sliderPosition"]=Json::Value(e.sliderPosition);

  json["response"]["parameters"]=j;
  return json;
}


bool Slider_responseMarshaller::fromJSON(const Json::Value& js,Slider_response& c)
{
  try
  {
    if(!js.isObject())  return false;

    if(!js.isMember("response"))  return false;

    if(!js["response"].isObject())  return false;
    const Json::Value& j2=js["response"];

    if(!j2.isMember("name") || !j2["name"].isString() || j2["name"].asString().compare("Slider"))  return false;
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
    if(!json.isMember("sliderPosition"))  return false;
    {
      const Json::Value& j=json["sliderPosition"];
      if(!j.isInt())  return false;
      c.sliderPosition=j.asInt();
    }

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}

