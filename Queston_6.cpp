#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
 
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fstream data;
    vector<string> date, price;
    data.open("April 22 NIFTY.csv");
    int i = 1;
    while (data.good())
    {
        string line;
        getline (data, line, '\n');
        stringstream ss(line);
        while (ss.good())
        {
            string element;
            getline (ss, element, ',');
            if (i % 7 == 1)
                date.push_back(element);
            if (i % 7 == 5)
                price.push_back(element);
            i ++;
        }
    }
    data.close();
    for (int i = 0; i < price.size(); i++)
        price[i] = price[i].substr(1, price[i].size() - 2); //Removing the double quotes from both the ends.
    vector<float> sma3, sma5;
    for (int i = 4; i < price.size(); i++)
        sma3.push_back((stoi(price[i - 3]) + stoi(price[i - 2]) + stoi(price[i - 1])) / 3);
    for (int i = 6; i < price.size(); i++)
        sma5.push_back((stoi(price[i - 5]) + stoi(price[i - 4]) + stoi(price[i - 3]) + stoi(price[i - 2]) + stoi(price[i - 1])) / 5);
    for (int i = 0; i < sma3.size(); i++)
        cout<< "The Simple moving average for 3 days on "<< date[i + 4]<< " is "<< sma3[i]<< '\n';
    for (int i = 0; i < sma5.size(); i++)
        cout<< "The Simple moving average for 5 days on "<< date[i + 6]<< " is "<< sma5[i]<< '\n';   
    return 0;
}