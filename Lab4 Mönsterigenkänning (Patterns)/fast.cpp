/*
 * fast < input.txt
 *
 * Compute and plot all line segments involving 4 points in input.txt
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <cmath>
#include "point.h"
#include "window.h"

using namespace std;

int main(int argc, const char* argv[]) {
    WindowPtr window = create_window(argc, argv);

    // The array of points
    vector<Point> points;

    // Read points from cin
    int N{};
    cin >> N;

    for (int i{0}; i < N; ++i) {
        unsigned int x, y;
        cin >> x >> y;
        points.push_back(Point{x, y});
    }

    // draw points to screen all at once
    window->draw(points);

    // sort points by natural order
    // makes finding endpoints of line segments easy
    sort(points.begin(), points.end());

    auto begin = chrono::high_resolution_clock::now();

    vector<Point> list{};
    for (size_t it = 0; it < N; it++)
    {
            for (size_t i {0} ; i< points.size(); i++)
        list.push_back(points[i]);     
        PolarSorter a(points[it]);
        sort(list.begin(),list.end(),a);
            for (int i = 2; i < list.size(); i++)
        {
            if(list.at(i).slopeTo(points[it]) == list.at(i-1).slopeTo(points[it]) 
                  && list.at(i).slopeTo(points[it]) == list.at(i-2).slopeTo(points[it]))
                window->draw(list[i], list[i-2]);
        }
        list.clear();
    }
    
   
  
   
    
    

    /////////////////////////////////////////////////////////////////////////////(double)(points.at(i).y-points.at(it).y)/(double)(points.at(i).x-points.at(it).x)
    // Draw any lines that you find in 'points' using the function 'window->draw'.
    /////////////////////////////////////////////////////////////////////////////

    auto end = chrono::high_resolution_clock::now();
    cout << "Computing line segments took "
         << std::chrono::duration_cast<chrono::milliseconds>(end - begin).count()
         << " milliseconds." << endl;

    // wait for user to terminate program
    window->run();

    return 0;
}
