   1: // ln.cpp : print line numbers
   2:
   3: #include "stdafx.h"
   4: #include <vector>
   5: #include <string>
   6: #include <iterator>
   7: #include <fstream>
   8: #include <iostream>
   9: using namespace std;
  10:
  11: int main()
  12: {
  13:     const char bell = 7;
  14:     const char space = ' ';
  15:     const int width = 4;           // MUST BE < 9999
  16:     const int limit = 9999;        // !
  17:
  18:     string line;
  19:
  20:     cout << "? ";
  21:     cin >> line;
  22:     line += ".cpp";
  23:     cout << endl;
  24:
  25:     ifstream infile(line);
  26:     if (!infile)
  27:     {
  28:         cout << bell;
  29:         cout << "Nope" << endl;
  30:         return 0;
  31:     }
  32:
  33:     // read file and replace \t
  34:     auto spacetab = [](const char c) { c == '\t' ? cout << "    " : cout << c;};
  35:
  36:     int num = 0;
  37:     while (getline(infile, line))
  38:     {
  39:         cout.setf(ios::right, ios::adjustfield);
  40:         cout.width(width);
  41:         cout << ++num << ": ";
  42:
  43:         for (auto s_itr = line.begin(); s_itr != line.end(); ++s_itr)
  44:             spacetab(*s_itr);
  45:
  46:         cout << endl;
  47:
  48:         if (num == limit) break;
  49:     }
  50:
  51:     return 0;
  52: }
