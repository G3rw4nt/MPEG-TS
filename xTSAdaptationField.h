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
    uint32_t SPMask = 0b0000000000100000;
    uint32_t PRMask = 0b0000000000010000;
    uint32_t ORMask = 0b0000000000001000;
    uint32_t SFMask = 0b0000000000000100;
    uint32_t TPMask = 0b0000000000000010;
    uint32_t EXMask = 0b0000000000000001;
    uint32_t Tmp = *((uint32_t*)Input);
    //Tmp = xSwapBytes32(Tmp);
    //Tmp = Tmp >> 32;
    L = Input[5] & LMask;
    L = L >> 8;
    DC = Input[5] & DCMask;
    DC = DC >> 7;
    RA = Input[5] & RAMask;
    RA = RA >> 6;
    SP = Input[5] & SPMask;
    SP = SP >> 5;
    PR = Input[5] & PRMask;
    PR = PR >> 4;
    OR = Input[5] & ORMask;
    OR = OR >> 3;
    SF = Input[5] & SFMask;
    SF = SF >> 2;
    TP = Input[5] & TPMask;
    TP = TP >> 1;
    EX = Input[5] & EXMask;

    return Tmp;
}
void Print() const
{
    cout << "L = " << L << " DC = " << DC << " RA = " << RA << " SP = " << SP << " PR = " << PR << " OR = " << OR << " SF = " << SF << " TP = " << TP << " EX = " << EX;
}
public:
//derrived values
uint32_t getNumBytes() const { }
};