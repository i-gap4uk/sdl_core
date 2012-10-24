#include "../../include/JSONHandler/ALRPCObjects/GetVehicleData_response.h"
#include "GPSDataMarshaller.h"
#include "PRNDLMarshaller.h"
#include "ResultMarshaller.h"
#include "TireStatusMarshaller.h"

#include "GetVehicleData_responseMarshaller.h"


/*
  interface	Ford Sync RAPI
  version	2.0L
  date		2012-09-13
  generated at	Wed Oct 24 13:40:36 2012
  source stamp	Wed Oct 24 13:40:27 2012
  author	robok0der
*/


bool GetVehicleData_responseMarshaller::checkIntegrity(GetVehicleData_response& s)
{
  return checkIntegrityConst(s);
}


bool GetVehicleData_responseMarshaller::fromString(const std::string& s,GetVehicleData_response& e)
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


const std::string GetVehicleData_responseMarshaller::toString(const GetVehicleData_response& e)
{
  Json::FastWriter writer;
  return checkIntegrityConst(e) ? writer.write(toJSON(e)) : "";
}


bool GetVehicleData_responseMarshaller::checkIntegrityConst(const GetVehicleData_response& s)
{
  if(!ResultMarshaller::checkIntegrityConst(s.resultCode))  return false;
  if(s.info && s.info->length()>1000)  return false;
  if(s.gps && !GPSDataMarshaller::checkIntegrityConst(*s.gps))  return false;
  if(s.speed && *s.speed>500)  return false;
  if(s.speed && *s.speed<-100)  return false;
  if(s.rpm && *s.rpm>20000)  return false;
  if(s.fuelLevel && *s.fuelLevel>100)  return false;
  if(s.fuelLevel && *s.fuelLevel<0)  return false;
  if(s.avgFuelEconomy && *s.avgFuelEconomy>7000)  return false;
  if(s.avgFuelEconomy && *s.avgFuelEconomy<0)  return false;
  if(s.batteryVoltage && *s.batteryVoltage>26)  return false;
  if(s.batteryVoltage && *s.batteryVoltage<0)  return false;
  if(s.externalTemperature && *s.externalTemperature>100)  return false;
  if(s.externalTemperature && *s.externalTemperature<-40)  return false;
  if(s.vin && s.vin->length()>17)  return false;
  if(s.prndl && !PRNDLMarshaller::checkIntegrityConst(*s.prndl))  return false;
  if(s.tirePressure && !TireStatusMarshaller::checkIntegrityConst(*s.tirePressure))  return false;
  if(s.batteryPackVoltage && *s.batteryPackVoltage>1000)  return false;
  if(s.batteryPackVoltage && *s.batteryPackVoltage<-1000)  return false;
  if(s.batteryPackCurrent && *s.batteryPackCurrent>1000)  return false;
  if(s.batteryPackCurrent && *s.batteryPackCurrent<-1000)  return false;
  if(s.batteryPackTemperature && *s.batteryPackTemperature>250)  return false;
  if(s.batteryPackTemperature && *s.batteryPackTemperature<-50)  return false;
  if(s.engineTorque && *s.engineTorque>55000)  return false;
  if(s.engineTorque && *s.engineTorque<-10000)  return false;
  if(s.odometer && *s.odometer>2000000)  return false;
  if(s.tripOdometer && *s.tripOdometer>2000000)  return false;
  if(s.satRadioESN && s.satRadioESN->length()>500)  return false;
  return true;
}

Json::Value GetVehicleData_responseMarshaller::toJSON(const GetVehicleData_response& e)
{
  Json::Value json(Json::objectValue);
  if(!checkIntegrityConst(e))
    return Json::Value(Json::nullValue);

  json["response"]=Json::Value(Json::objectValue);
  json["response"]["name"]=Json::Value("GetVehicleData");
  json["response"]["correlationID"]=Json::Value(e.getCorrelationID());

  Json::Value j=Json::Value(Json::objectValue);

  j["success"]=Json::Value(e.success);

  j["resultCode"]=ResultMarshaller::toJSON(e.resultCode);

  if(e.info)
    j["info"]=Json::Value(*e.info);

  if(e.gps)
    j["gps"]=GPSDataMarshaller::toJSON(*e.gps);

  if(e.speed)
    j["speed"]=Json::Value(*e.speed);

  if(e.rpm)
    j["rpm"]=Json::Value(*e.rpm);

  if(e.fuelLevel)
    j["fuelLevel"]=Json::Value(*e.fuelLevel);

  if(e.avgFuelEconomy)
    j["avgFuelEconomy"]=Json::Value(*e.avgFuelEconomy);

  if(e.batteryVoltage)
    j["batteryVoltage"]=Json::Value(*e.batteryVoltage);

  if(e.externalTemperature)
    j["externalTemperature"]=Json::Value(*e.externalTemperature);

  if(e.vin)
    j["vin"]=Json::Value(*e.vin);

  if(e.prndl)
    j["prndl"]=PRNDLMarshaller::toJSON(*e.prndl);

  if(e.tirePressure)
    j["tirePressure"]=TireStatusMarshaller::toJSON(*e.tirePressure);

  if(e.batteryPackVoltage)
    j["batteryPackVoltage"]=Json::Value(*e.batteryPackVoltage);

  if(e.batteryPackCurrent)
    j["batteryPackCurrent"]=Json::Value(*e.batteryPackCurrent);

  if(e.batteryPackTemperature)
    j["batteryPackTemperature"]=Json::Value(*e.batteryPackTemperature);

  if(e.engineTorque)
    j["engineTorque"]=Json::Value(*e.engineTorque);

  if(e.odometer)
    j["odometer"]=Json::Value(*e.odometer);

  if(e.tripOdometer)
    j["tripOdometer"]=Json::Value(*e.tripOdometer);

  if(e.satRadioESN)
    j["satRadioESN"]=Json::Value(*e.satRadioESN);

  json["response"]["parameters"]=j;
  return json;
}


bool GetVehicleData_responseMarshaller::fromJSON(const Json::Value& js,GetVehicleData_response& c)
{
  if(c.info)  delete c.info;
  c.info=0;

  if(c.gps)  delete c.gps;
  c.gps=0;

  if(c.speed)  delete c.speed;
  c.speed=0;

  if(c.rpm)  delete c.rpm;
  c.rpm=0;

  if(c.fuelLevel)  delete c.fuelLevel;
  c.fuelLevel=0;

  if(c.avgFuelEconomy)  delete c.avgFuelEconomy;
  c.avgFuelEconomy=0;

  if(c.batteryVoltage)  delete c.batteryVoltage;
  c.batteryVoltage=0;

  if(c.externalTemperature)  delete c.externalTemperature;
  c.externalTemperature=0;

  if(c.vin)  delete c.vin;
  c.vin=0;

  if(c.prndl)  delete c.prndl;
  c.prndl=0;

  if(c.tirePressure)  delete c.tirePressure;
  c.tirePressure=0;

  if(c.batteryPackVoltage)  delete c.batteryPackVoltage;
  c.batteryPackVoltage=0;

  if(c.batteryPackCurrent)  delete c.batteryPackCurrent;
  c.batteryPackCurrent=0;

  if(c.batteryPackTemperature)  delete c.batteryPackTemperature;
  c.batteryPackTemperature=0;

  if(c.engineTorque)  delete c.engineTorque;
  c.engineTorque=0;

  if(c.odometer)  delete c.odometer;
  c.odometer=0;

  if(c.tripOdometer)  delete c.tripOdometer;
  c.tripOdometer=0;

  if(c.satRadioESN)  delete c.satRadioESN;
  c.satRadioESN=0;

  try
  {
    if(!js.isObject())  return false;

    if(!js.isMember("response"))  return false;

    if(!js["response"].isObject())  return false;
    const Json::Value& j2=js["response"];

    if(!j2.isMember("name") || !j2["name"].isString() || j2["name"].asString().compare("GetVehicleData"))  return false;
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
    if(json.isMember("gps"))
    {
      const Json::Value& j=json["gps"];
      c.gps=new GPSData();
      if(!GPSDataMarshaller::fromJSON(j,c.gps[0]))
        return false;
    }
    if(json.isMember("speed"))
    {
      const Json::Value& j=json["speed"];
      if(!j.isDouble())  return false;
      c.speed=new float(j.asDouble());
    }
    if(json.isMember("rpm"))
    {
      const Json::Value& j=json["rpm"];
      if(!j.isInt())  return false;
      c.rpm=new unsigned int(j.asInt());
    }
    if(json.isMember("fuelLevel"))
    {
      const Json::Value& j=json["fuelLevel"];
      if(!j.isDouble())  return false;
      c.fuelLevel=new float(j.asDouble());
    }
    if(json.isMember("avgFuelEconomy"))
    {
      const Json::Value& j=json["avgFuelEconomy"];
      if(!j.isDouble())  return false;
      c.avgFuelEconomy=new float(j.asDouble());
    }
    if(json.isMember("batteryVoltage"))
    {
      const Json::Value& j=json["batteryVoltage"];
      if(!j.isDouble())  return false;
      c.batteryVoltage=new float(j.asDouble());
    }
    if(json.isMember("externalTemperature"))
    {
      const Json::Value& j=json["externalTemperature"];
      if(!j.isDouble())  return false;
      c.externalTemperature=new float(j.asDouble());
    }
    if(json.isMember("vin"))
    {
      const Json::Value& j=json["vin"];
      if(!j.isString())  return false;
      c.vin=new std::string(j.asString());
    }
    if(json.isMember("prndl"))
    {
      const Json::Value& j=json["prndl"];
      c.prndl=new PRNDL();
      if(!PRNDLMarshaller::fromJSON(j,c.prndl[0]))
        return false;
    }
    if(json.isMember("tirePressure"))
    {
      const Json::Value& j=json["tirePressure"];
      c.tirePressure=new TireStatus();
      if(!TireStatusMarshaller::fromJSON(j,c.tirePressure[0]))
        return false;
    }
    if(json.isMember("batteryPackVoltage"))
    {
      const Json::Value& j=json["batteryPackVoltage"];
      if(!j.isDouble())  return false;
      c.batteryPackVoltage=new float(j.asDouble());
    }
    if(json.isMember("batteryPackCurrent"))
    {
      const Json::Value& j=json["batteryPackCurrent"];
      if(!j.isDouble())  return false;
      c.batteryPackCurrent=new float(j.asDouble());
    }
    if(json.isMember("batteryPackTemperature"))
    {
      const Json::Value& j=json["batteryPackTemperature"];
      if(!j.isInt())  return false;
      c.batteryPackTemperature=new int(j.asInt());
    }
    if(json.isMember("engineTorque"))
    {
      const Json::Value& j=json["engineTorque"];
      if(!j.isInt())  return false;
      c.engineTorque=new int(j.asInt());
    }
    if(json.isMember("odometer"))
    {
      const Json::Value& j=json["odometer"];
      if(!j.isInt())  return false;
      c.odometer=new unsigned int(j.asInt());
    }
    if(json.isMember("tripOdometer"))
    {
      const Json::Value& j=json["tripOdometer"];
      if(!j.isInt())  return false;
      c.tripOdometer=new unsigned int(j.asInt());
    }
    if(json.isMember("satRadioESN"))
    {
      const Json::Value& j=json["satRadioESN"];
      if(!j.isString())  return false;
      c.satRadioESN=new std::string(j.asString());
    }

  }
  catch(...)
  {
    return false;
  }
  return checkIntegrity(c);
}

