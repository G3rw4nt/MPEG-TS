#include <string>
#include <iostream>

using namespace std;

class xTS_AdaptationField
{
protected:
//AF Length
uint32_t L;
//mandatory fields
uint32_t DC,RA,SP,PR,OR,SF,TP,EX;
public:
void Reset();
int32_t Parse(const uint8_t* Input, uint8_t AdaptationFieldControl)
{
    uint32_t LMask =  0b1111111100000000;
    uint32_t DCMask = 0b0000000010000000;
    uint32_t RAMask = 0b0000000001000000;
    uint32_t SPMask =  0b0000000000100000;
    uint32_t PRMask = 0b0000000000010000;
    uint32_t ORMask = 0b0000000000001000;
    uint32_t SFMask = 0b0000000000000100;
    uint32_t TPMask = 0b0000000000000010;
    uint32_t EXMask = 0b0000000000000001;
    uint32_t Tmp = *((uint32_t*)Input);
    Tmp = xSwapBytes32(Tmp);
    Tmp = Tmp >> 32;
    L = Tmp & LMask;
    L = L >> 8;
    L = L + 1;
    DC = Tmp & DCMask;
    DC = DC >> 7;
    RA = Tmp & RAMask;
    RA = RA >> 6;
    SP = SP & SPMask;
    SP = SP >> 5;
    PR = PR & PRMask;
    PR = PR >> 4;
    OR = OR & ORMask;
    OR = OR >> 3;
    SF = SF & SFMask;
    SF = SF >> 2;
    TP = TP & TPMask;
    TP = TP >> 1;
    EX = EX & EXMask;

    return 0;
}
void Print() const
{
    cout << "L = " << L << " DC = " << DC << " RA = " << RA << " SP = " << SP << " PR = " << PR << " OR = " << OR << " SF = " << SF << " TP = " << TP << " EX = " << EX;
}
public:
//derrived values
uint32_t getNumBytes() const { }
};