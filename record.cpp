#include "record.hpp"
#include <iostream>
using namespace std;

typedef deque<double>::const_iterator iter;
// adds a new score for the named player
void record::add_score(double score){
    sc.push_front(score); // add score to the record
}
//returns the best score ever added to the record (or 0 if none)
double record::best_score() const{
    if (sc.size() == 0 )  // if the record size is 0
        return 0;         // return 0
    iter b = sc.cbegin();
    double bestscore = *b;
    while (b != sc.cend()){ // while b is not equals to the end of the record
        if (*b > bestscore) // if b is bigger than bestscore
            bestscore = *b; // make bestscore = to b
        ++b; // increment b
    }
    return bestscore;
}
// returns the average of all scores added to the record (or 0 if none)
double record::overall_average() const{
    if(sc.size() == 0) // if the record size is 0
        return 0;      //return 0
    double sum = 0;
    for (iter ave = sc.cbegin(); ave != sc.cend() ; ++ave) // go through the whole record and
        sum += *ave;                                       // sum all the scores
    return sum/sc.size(); // divide the sum by the size of the record ( average )
}
//returns the average of the last 10 scores added to the record (or 0 if none)
double record::recent_average() const{
    if(sc.size() == 0) // if the record size if 0
        return 0;      // return 0
    double sum = 0;
    int count = 0;
    for(int i = 0; i < 10 && i < sc.size(); ++i){ // go through the record if i is smaller than 10 and
        sum += sc[i];                             // i is smaller than the size of the record
        ++count;                                  //sum the first 10 or less scores and increment count
    }
    return sum/count; // return the average
}
//whether fewer than 10 scores have been recorded
bool record::novice() const{
    return sc.size() < 10;
}











