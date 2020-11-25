#include "table.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
typedef map<string,record>::const_iterator iter;

//adds a new score for the named player
void table::add_score(const string &name, double score){
    tbl[name].add_score(score); //
}
//returns the total number of players for whom a score has been recorded.
int table::num_players() const{
    int count = 0;
    for(iter name = tbl.cbegin(); name != tbl.cend(); ++name){
        if (name->second.scores() > 0)
            ++count;
    }
    return count;
}
// returns the average of the best scores of all players
double table::average_best() const {
    int count = 0;
    for ( iter m = tbl.cbegin(); m != tbl.cend(); ++m){
        count += m->second.best_score();
    }
    return count / num_players();
}
//returns the name of the player with the highest overall average.
string table::best_overall() const{
    iter m = tbl.cbegin();
    iter highestavg = m;
    // while is not the end of the table and if m is bigger than the highesaverage stored in the begining make highestaverage equals to m
    while ( m != tbl.cend()){
        if (m->second.overall_average() > highestavg->second.overall_average())
            highestavg = m;
        ++m; // increment m
    }
    return highestavg->first; //
}
bool novice(const pair<string, record> player){
    return player.second.novice(); // check if the player is a novice ( less than 10 matches )
}

//returns the number of novice players. Your implementation should use a library algorithm.
int table::novice_count() const{
    return count_if(tbl.cbegin(), tbl.cend(), novice);
}
