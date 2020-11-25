#ifndef table_hpp
#define table_hpp
#include "record.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>


class table {
    std::map<std::string,record> tbl;
public:
    void add_score(const std::string &name, double score);
    int num_players() const;
    std::vector<std::string> print_best_recent(int n) const;
    double average_best() const;
    std::string best_overall() const;
    int novice_count() const;
};

#endif /* table_hpp */
