#include "../../include/Dictionary.h"

Dictionary *Dictionary::_pDictSigleInstance = nullptr;
Dictionary::AutoRelease Dictionary::_ar;


//获取词典单例对象
Dictionary *Dictionary::getDictSigleInstance()
{
    if (_pDictSigleInstance == nullptr)
    {
        _pDictSigleInstance = new Dictionary();
        // init("/home/joy/sousuo/server/datadict.data");
    }
    return _pDictSigleInstance;
}

//初始化词典和词典索引
void Dictionary::init(const string &dictPath, const string &dictIndexPath)
{

    _dict = make_shared<vector<pair<string, int>>>();
    _index = make_shared<map<string, set<int>>>();
    ifstream ifs4Dict(dictPath);
    if (!ifs4Dict)
    {
        cout << "open dictPath error" << endl;
    }

    //获取词典
    string line;
    string word;
    int frequency;
    while (getline(ifs4Dict, line))
    {                                 //读取一整行
        istringstream ifs4Dict(line); //将一行记录分解成pair<string,int>
        ifs4Dict >> word >> frequency;
        _dict->push_back(make_pair(word, frequency));
    }

    //获取（单个字，词语行号）的索引
    ifstream ifs2Index(dictIndexPath);
    if (!ifs2Index.is_open())
    {
        cout << "open " << dictIndexPath << " error" << endl;
        return;
    }
    int lineNo;
    while (getline(ifs2Index, line))
    {
        istringstream ifs2Index(line);

        ifs2Index >> word;
        while (ifs2Index >> lineNo)
        {
            (*_index)[word].insert(lineNo);
        }
    }
}