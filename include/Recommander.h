#ifndef __WD_KEYRECOMMANDER_H__
#define __WD_KEYRECOMMANDER_H__

#include "Dictionary.h"
#include "MinEditDist.h"
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class QueryResult
{
    friend bool operator<(const QueryResult &lhs, const QueryResult &rhs);

public:
    QueryResult(string word, int dist, int frequeycy)
        : _candidateWord(word), _editDist(dist), _frequency(frequeycy)
    {
    }

    string _candidateWord;
    int _editDist;
    int _frequency;
};

class Recommander
{
public:
    Recommander(string queryWord)
        : _queryWord(queryWord), _pDict(Dictionary::getDictSigleInstance()), _minDistCalculator()
    {
    }
    vector<string> query();

private:
    void splitWord(const string &word, vector<string> &ret); //词语分解成单个字符
    // void query();
private:
    string _queryWord;
    // priority_queue<QueryResult> _resultQue;
    Dictionary *_pDict;             //一定要在某个地方先执行其init()函数
    MinEditDist _minDistCalculator; //计算最小编辑距离的类
    set<QueryResult> _result;
};

#endif