#include "tsTransportStream.h"
using namespace std;
//=============================================================================================================================================================================
// xTS_PacketHeader
//=============================================================================================================================================================================
void xTS_PacketHeader::Reset() {}

int32_t xTS_PacketHeader::Parse(const uint8_t* Input) {
  uint32_t Tmp = *((uint32_t*)Input);
  Tmp = xSwapBytes32(Tmp);

  //std::cout << Tmp << std::endl;

  uint32_t SBMask =  0b11111111000000000000000000000000;
  uint32_t EMask =   0b00000000100000000000000000000000;
  uint32_t SMask =   0b00000000010000000000000000000000;
  uint32_t PMask =   0b00000000001000000000000000000000;
  uint32_t PIDMask = 0b00000000000111111111111100000000;
  uint32_t TSCMask = 0b00000000000000000000000011000000;
  uint32_t AFMask =  0b00000000000000000000000000110000;
  uint32_t CCMask =  0b00000000000000000000000000001111;

  SB = Tmp & SBMask;
  SB  = SB >> 24;
  E = Tmp & EMask;
  E = E >> 23;
  S = Tmp & SMask;
  S = S >> 22;
  P = Tmp & PMask;
  P = P >> 21;
  PID = Tmp & PIDMask;
  PID = PID >> 8;
  TSC = Tmp & TSCMask;
  TSC = TSC >> 6;
  AF = Tmp & AFMask;
  AF = AF >> 4;
  CC = Tmp & CCMask;
   
  return 0;
}


void xTS_PacketHeader::Print() const {
  cout << "TS: SB=" << SB << " E=" << E << " S=" << S << " P=" << P << " PID=" << PID << " TSC=" << TSC << " AF=" << AF << " CC=" << CC;
}
//=============================================================================================================================================================================
