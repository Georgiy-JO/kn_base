#include <fstream>
#include <iostream>

using std::cout, std::endl, std::ios;
struct Database {
  int id;
  char name[100];
  bool activeness;
  char reference[50];
  double value;
};

int main() {
  Database data_in[]{{5, "Jack O'Neill", true, "StarGate", 55553.778},
                     {3, "Daniel Jackson", true, "StarGate", 58803.778},
                     {1, "Samantha Carter", true, "StarGate", 55512.99},
                     {2, "Teal'c", true, "StarGate", 59053.0},
                     {4, "Jonas Quinn", true, "StarGate", 553.3}};
  Database data_out[sizeof(data_in) / sizeof(data_in[0])];
  //-----write to file in binary form-----
  std::ofstream ofs("output.txt", ios::binary | ios::out);
  if (ofs.is_open()) {
    for (auto& ref : data_in) ofs.write((char*)&ref, sizeof(ref));
    ofs.close();
  }
  //-----read from file in binary form-----
  std::ifstream ifs("output.txt", ios::binary | ios::in);
  int count(0);
  if (ifs.is_open()) {
    while (ifs.read((char*)&data_out[count], sizeof(Database))) count++;
    ifs.close();
  }
  //-----print read data-----
  cout << "Read: " << count << endl;
  for (int i = 0; i < count; i++) {
    cout << '#' << i + 1 << ':' << endl;
    cout << "ID: " << data_out[i].id << endl;
    cout << "Full name: " << data_out[i].name << endl;
    cout << "Status: " << (data_out[i].activeness ? "Active" : "Off") << endl;
    cout << "Reference: " << data_out[i].reference << endl;
    cout << "Bersonal score: " << data_out[i].value << endl;
  }
  return 0;
}