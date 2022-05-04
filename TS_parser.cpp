// telekom_multim_lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "tsCommon.h"
#include "tsTransportStream.h"
#include "xTSAdaptationField.h"

using namespace std;

int main(int argc, char* argv[], char* envp[]) {
  // TODO - open file

  FILE* file = std::fopen("C:/git/MPEG-TS/example_new.ts", "rb");
  if (!file) {
    cout << "File Error";
    delete file;
    return 0;
  }
  else cout << std::endl << "File successfully opened" << std::endl;

  xTS_PacketHeader TS_PacketHeader;
  xTS_AdaptationField xTS_AdaptationField;
  uint8_t Buffer[188];
  int32_t TS_PacketId = 0;

  while (!feof(file)) {
    // TODO - read from file
    fread(Buffer, 188, 1, file);
    
    TS_PacketHeader.Parse(Buffer);

    printf("%010d ", TS_PacketId);
    TS_PacketHeader.Print();
    if(TS_PacketHeader.getAF() == 2 || TS_PacketHeader.getAF() == 3)
    {
      cout << " AF: ";
      xTS_AdaptationField.Parse(Buffer,TS_PacketHeader.getAF());
      xTS_AdaptationField.Print();

    }
    printf("\n");

    TS_PacketId++;
    if(TS_PacketId == 100) break;
  }
  delete file;
  return 0;
}
