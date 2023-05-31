#include <fstream>

int main()
{
    std::ifstream in("anniversary.in");
    std::ofstream out("anniversary.out");

    long long w, h, a[2], b[2];
    in >> w >> h >> a[0] >> b[0] >> a[1] >> b[1];

    if (b[0] == b[1])
    {
        out << a[0] << " " << 0 << " " << a[1] << " " << h;
    }
    else
    {
        out << 0 << " " << b[0]  << " " << w << " " << b[1];
    }
    in.close();
    out.close();
    return 0;
}
