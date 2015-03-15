#include "include/manager.h"

int main()
{
    Manager<std::string, int> m;
    int val = 1;
    m.set("val", val);
    std::fstream out("test.bin");
    m.write_binary(out);
    return 0;
}
