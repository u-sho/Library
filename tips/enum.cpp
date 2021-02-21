#include <cassert>  // assert
#include <iostream>

enum Query {
    operation = 1,
    outputs   = 2,
};
std::istream &operator>>(std::istream &is, Query &q) {
    short qin;
    is >> qin;
    assert((qin == Query::operation || qin == Query::outputs));
    if (qin == Query::operation) q = Query::operation;
    if (qin == Query::outputs) q = Query::outputs;
    return is;
}
