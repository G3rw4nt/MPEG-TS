#pragma once
#include <string>
#include <iostream>
#include "tsCommon.h"
using namespace std;
/*
MPEG-TS packet:
`        3                   2                   1                   0  `
`      1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0  `
`     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ `
`   0 |                             Header                            | `
`     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ `
`   4 |                  Adaptation field + Payload                   | `
`     |                                                               | `
` 184 |                                                               | `
`     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ `


MPEG-TS packet header:
`        3                   2                   1                   0  `
`      1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0  `
`     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ `
`   0 |       SB      |E|S|T|           PID           |TSC|AFC|   CC  | `
`     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ `

Sync byte                    (SB ) :  8 bits
Transport error indicator    (E  ) :  1 bit
Payload unit start indicator (S  ) :  1 bit
Transport priority           (T  ) :  1 bit
Packet Identifier            (PID) : 13 bits
Transport scrambling control (TSC) :  2 bits
Adaptation field control     (AFC) :  2 bits
Continuity counter           (CC ) :  4 bits
*/

//=============================================================================================================================================================================

class xTS {
 public:
  static constexpr uint32_t TS_PacketLength = 188;
  static constexpr uint32_t TS_HeaderLength = 4;

  static constexpr uint32_t PES_HeaderLength = 6;

  static constexpr uint32_t BaseClockFrequency_Hz = 90000;         // Hz
  static constexpr uint32_t ExtendedClockFrequency_Hz = 27000000;  // Hz
  static constexpr uint32_t BaseClockFrequency_kHz = 90;           // kHz
  static constexpr uint32_t ExtendedClockFrequency_kHz = 27000;    // kHz
  static constexpr uint32_t BaseToExtendedClockMultiplier = 300;
};

//=============================================================================================================================================================================

class xTS_PacketHeader {
 public:
  enum class ePID : uint16_t {
    PAT = 0x0000,
    CAT = 0x0001,
    TSDT = 0x0002,
    IPMT = 0x0003,
    NIT = 0x0010,  // DVB specific PID
    SDT = 0x0011,  // DVB specific PID
    NuLL = 0x1FFF,
  };

 protected:
  uint32_t SB,E,S,P,PID,TSC,AF,CC;

 public:
  void Reset();
  int32_t Parse(const uint8_t* Input);
  void Print() const;

 public:
  uint32_t getSB(){return SB;}
  uint32_t getE(){return E;}
  uint32_t getS(){return S;}
  uint32_t getP(){return P;}
  uint32_t getPID(){return PID;}
  uint32_t getTSC(){return TSC;}
  uint32_t getAF(){return AF;}
  uint32_t getCC(){return CC;}

 public:
  bool     hasAdaptationField() const { return AF != 0; }
  bool     hasPayload        () const { return P != 0; }
};

//=============================================================================================================================================================================
