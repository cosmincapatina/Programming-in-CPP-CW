#ifndef record_hpp
#define record_hpp
#include <iostream>
#include <deque>

class record{
    std::deque<double> sc;
public:
    record(){}
    record(double score);
    void add_score(double score);
    double best_score() const;
    double overall_average() const;
    double recent_average() const;
    bool novice() const;
    unsigned scores() const { return sc.size(); } // return the size of the record
};

#endif /* record_hpp */
