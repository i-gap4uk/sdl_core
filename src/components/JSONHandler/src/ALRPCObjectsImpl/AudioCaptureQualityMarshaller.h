#ifndef AUDIOCAPTUREQUALITYMARSHALLER_INCLUDE
#define AUDIOCAPTUREQUALITYMARSHALLER_INCLUDE

#include <string>
#include <jsoncpp/json.h>

#include "PerfectHashTable.h"

#include "../../include/JSONHandler/ALRPCObjects/AudioCaptureQuality.h"


/*
  interface	Ford Sync RAPI
  version	2.0L
  date		2012-09-13
  generated at	Wed Oct 24 13:40:36 2012
  source stamp	Wed Oct 24 13:40:27 2012
  author	robok0der
*/


//! marshalling class for AudioCaptureQuality

class AudioCaptureQualityMarshaller
{
public:

  static std::string toName(const AudioCaptureQuality& e) 	{ return getName(e.mInternal) ?: ""; }

  static bool fromName(AudioCaptureQuality& e,const std::string& s)
  { 
    return (e.mInternal=getIndex(s.c_str()))!=AudioCaptureQuality::INVALID_ENUM;
  }

  static bool checkIntegrity(AudioCaptureQuality& e)		{ return e.mInternal!=AudioCaptureQuality::INVALID_ENUM; } 
  static bool checkIntegrityConst(const AudioCaptureQuality& e)	{ return e.mInternal!=AudioCaptureQuality::INVALID_ENUM; } 

  static bool fromString(const std::string& s,AudioCaptureQuality& e);
  static const std::string toString(const AudioCaptureQuality& e);

  static bool fromJSON(const Json::Value& s,AudioCaptureQuality& e);
  static Json::Value toJSON(const AudioCaptureQuality& e);

  static const char* getName(AudioCaptureQuality::AudioCaptureQualityInternal e)
  {
     return (e>=0 && e<2) ? mHashTable[e].name : NULL;
  }

  static const AudioCaptureQuality::AudioCaptureQualityInternal getIndex(const char* s);

  static const PerfectHashTable mHashTable[2];
};

#endif
