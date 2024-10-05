#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    if (a == "Kim")
    {
        if (b == "Thuy")
            cout << "Kim sinh Thuy";
        if (b == "Tho")
            cout << "Tho sinh Kim";
        if (b == "Moc")
            cout << "Kim khac Moc";
        if (b == "Hoa")
            cout << "Hoa khac Kim";
    }
    if (a == "Thuy")
    {
        if (b == "Moc")
            cout << "Thuy sinh Moc";
        if (b == "Kim")
            cout << "Kim sinh Thuy";
        if (b == "Hoa")
            cout << "Thuy khac Hoa";
        if (b == "Tho")
            cout << "Tho khac Thuy";
    }
    if (a == "Moc")
    {
        if (b == "Hoa")
            cout << "Moc sinh Hoa";
        if (b == "Thuy")
            cout << "Thuy sinh Moc";
        if (b == "Tho")
            cout << "Moc khac Tho";
        if (b == "Kim")
            cout << "Kim khac Moc";
    }
    if (a == "Hoa")
    {
        if (b == "Tho")
            cout << "Hoa sinh Tho";
        if (b == "Moc")
            cout << "Moc sinh Hoa";
        if (b == "Kim")
            cout << "Hoa khac Kim";
        if (b == "Thuy")
            cout << "Thuy khac Hoa";
    }
    if (a == "Tho")
    {
        if (b == "Kim")
            cout << "Tho sinh Kim";
        if (b == "Hoa")
            cout << "Hoa sinh Tho";
        if (b == "Thuy")
            cout << "Tho khac Thuy";
        if (b == "Moc")
            cout << "Moc khac Tho";
    }

    return 0;
}