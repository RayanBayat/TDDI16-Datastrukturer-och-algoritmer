#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<string> Dictionary;


vector<string> find_shortest(const Dictionary& dict, const string& start, const string& the_word)
{
    vector <string> chains{};
    unordered_map<string, string> my_word_map{};
    set<string> my_word_set(dict.begin(), dict.end());

    if(my_word_set.find(the_word) == my_word_set.end())
    {
        return chains;
    }

    int wordlength = the_word.size();
    bool found = false;
    queue<string> queue_line;

    queue_line.push(start); // vi pushar in första orden i queue, därefter kommer ordet automatisk
    while(!queue_line.empty())
    {
        if(found == true)
        {
            break;

        }
        int size_of_queue_line = queue_line.size();

        for(int i = 0; i < size_of_queue_line; i++)
        {
            if(found == true)
            {
                break;

            }
            string word = queue_line.front();
            queue_line.pop();
            for(int position = 0; position < wordlength; ++position)
            {
                if(found == true)
                {
                    break;

                }
                char old_char = word[position];

                for(char letter = 'a'; letter <= 'z'; ++letter)
                {
                    if(found == true)
                    {
                        break;

                    }
                    word[position] = letter;
                    if(word == the_word)
                    {
                        found = true; // vi hittade ordet, nu bryter vi alla loopar
                        my_word_set.erase(word);
                        string old = word;
                        old[position] = old_char;
                        pair<string, string> a(word, old);
                        my_word_map.insert(a);;
                        break;
                    }
                    if(my_word_set.find(word) == my_word_set.end())
                        continue;
                    my_word_set.erase(word);

                    queue_line.push(word);
                    string old = word;
                    old[position] = old_char;
                    pair<string, string> a(word, old);
                    my_word_map.insert(a);
                }
                word[position] = old_char;
            }
        }
    }
    if(!(my_word_set.find(the_word) == my_word_set.end()))
    {
        chains.clear();
        return chains;
    }

    chains.push_back(the_word);
    auto ia = my_word_map.find(chains.back());
    while(!(ia->first == start))
    {
         ia = my_word_map.find(chains.back());
 
        chains.push_back(ia->second);
    }
    reverse(chains.begin(), chains.end());
    return chains;
}


vector<string> find_longest(const Dictionary& dict, const string& the_word)
{
    vector <string> chains{};
    unordered_map<string, string> my_word_map{};
    set<string> my_word_set(dict.begin(), dict.end());

    if(my_word_set.find(the_word) == my_word_set.end())
    {
        return chains;
    }
    string target;
    int wordlength = the_word.size();

    queue<string> queue_line;
    queue_line.push(the_word);

    while(!queue_line.empty())
    {
        int size_of_queue_line = queue_line.size();

        for(int i = 0; i < size_of_queue_line; i++)
        {

            string word = queue_line.front();
            queue_line.pop();
            for(int position = 0; position < wordlength; ++position)
            {
                char old_char = word[position];

                for(char letter = 'a'; letter <= 'z'; ++letter)
                {
                    word[position] = letter;
                    if(my_word_set.find(word) == my_word_set.end())
                        continue;

                    my_word_set.erase(word);

                    queue_line.push(word);

                    string old = word;
                    old[position] = old_char;
                    my_word_map.insert({ word, old });

                    target = word;
                }
                word[position] = old_char;
            }
        }
    }

    if(!(my_word_set.find(the_word) == my_word_set.end()))
    {
        chains.clear();  // om ordet finns fortfarande i set d.v.s. vi kunde inte kedja till den, vi har misslyckats
        return chains;
    }

    chains.push_back(target);
    auto map_iterator = my_word_map.find(target);
    while(!(map_iterator->first == the_word))//när vi kommer från längsta till första orden bryt loopen
    {

        chains.push_back(map_iterator->second);
        map_iterator = my_word_map.find(map_iterator->second);
    }

    return chains;
}


Dictionary read_dictionary()
{
    string line;
    vector<string> result;
    while(std::getline(std::cin, line))
    {
        if(line == "#")
            break;

        result.push_back(line);
    }

    return Dictionary(result.begin(), result.end());
}

void print_chain(const vector<string>& chain)
{
    if(chain.empty())
        return;

    vector<string>::const_iterator i = chain.begin();
    cout << *i;

    for(++i; i != chain.end(); ++i)
        cout << " -> " << *i;

    cout << endl;
}

void print_answer(const vector<string>& chain)
{
    if(chain.empty())
    {
        cout << "ingen lösning" << endl;
    }
    else
    {
        cout << chain.size() << " ord" << endl;
        print_chain(chain);
    }
}

void read_questions(const Dictionary& dict)
{
    string line;
    while(std::getline(std::cin, line))
    {
        size_t space = line.find(' ');
        if(space != string::npos)
        {
            string first = line.substr(0, space);
            string second = line.substr(space + 1);
            vector<string> chain = find_shortest(dict, first, second);

            cout << first << " " << second << ": ";
            print_answer(chain);
        }
        else
        {
            vector<string> chain = find_longest(dict, line);

            cout << line << ": ";
            print_answer(chain);
        }
    }
}

int main()
{

    Dictionary dict = read_dictionary();
    read_questions(dict);

}
