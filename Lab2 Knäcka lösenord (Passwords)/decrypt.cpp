#include <iostream>
#include <chrono>
#include <string>
#include "key.h"
#include <forward_list>
#include <unordered_map>
using namespace std;

struct hashfunktion
{
   
    size_t operator()(const Key& a)const
    {
        size_t r = 0;
        for (char c : a.digit)
        {
            r = c + (r << 6) + (r << 16) - r;
       
        }
        return r;
    }
};
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage:" << endl;
        cout << argv[0] << " <hashed password> < rand8.txt" << endl;
        return 1;
    }

    // Hashed password.
    Key hashed{argv[1]};

    // Table.
    Key table[N];

    // Read table.
    for (int i{0}; i < N; i++) {
        string buffer;
        if (!(cin >> buffer)) {
            cerr << "Too short table!" << endl;
            return 1;
        }
        table[i] = Key{buffer.c_str()};
    }

    auto begin = chrono::high_resolution_clock::now();
    //====================================================================================
    // Try all possible subsets of T.

    cout << "============================================================================\n";
    std::unordered_map<Key, forward_list<Key>, hashfunktion> m{};
    Key lowsignificantbits{},highsignificantbits{},zero{};
    ++highsignificantbits;
    int middle{N/2};    //Tar reda på vilken bit som är i mitten
    for (int i = 0; i < middle; i++)
    {    
        highsignificantbits += highsignificantbits; // bitshiftar till vänster för att nå biten i mitten
    }
 
    while (lowsignificantbits < highsignificantbits)
    {
        m[subset_sum(lowsignificantbits, table)].push_front(lowsignificantbits); // läger till alla msb i en symbol lista
        ++lowsignificantbits;
    }

    Key add = highsignificantbits; // sparar min msb för senare addition
    Key one{};
    highsignificantbits = one;
    
    do{
       // I och med att jag redan har hälften av bitarna i symbollistan räknar jag bara bitarna som är kvar
        if (m.find(hashed - subset_sum(highsignificantbits, table)) != m.end()) // letar efter min hashad nyckel minus hashad msb i symbollistan
        {
            const auto& it = m.find(hashed - subset_sum(highsignificantbits, table));// skapar en unordered_map iterator
            for (const auto & forward_list_iterator : it->second) //skapar en forwordlist iterator
            {
                cout << forward_list_iterator  + highsignificantbits<< "\n"; // lägger till msb till svaren som hittas i listan
            }     
        }
       
        highsignificantbits = highsignificantbits + add; //ökar min msb med ett
    }while (highsignificantbits > zero);
    //====================================================================================
    auto end = chrono::high_resolution_clock::now();
    cout << "Decryption took "
         << std::chrono::duration_cast<chrono::seconds>(end - begin).count()
         << " seconds." << endl;

    cout << "============================================================================\n";
    return 0;
}
