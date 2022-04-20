// telekom_multim_lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "tsCommon.h"
#include "tsTransportStream.h"

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

  int32_t TS_PacketId = 0;
  uint8_t TS_PacketBuffer[188];
  while (!feof(file)) {
    // TODO - read from file
    int readBytes = fread(TS_PacketBuffer, 188, 1, file);
    
    TS_PacketHeader.Parse(TS_PacketBuffer);

    printf("%010d ", TS_PacketId);
    TS_PacketHeader.Print();

    printf("\n");

    TS_PacketId++;
  }
  delete file;
  return 0;
}
