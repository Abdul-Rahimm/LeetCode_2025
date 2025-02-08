class NumberContainers
{
public:
    NumberContainers()
    {
    }
    map<int, int> indexMap;
    map<int, set<int>> numberMap;

    void change(int index, int number)
    {
        if (indexMap.find(index) != indexMap.end())
        {
            int prevValue = indexMap[index];
            numberMap[prevValue].erase(index);

            if (numberMap[prevValue].size() == 0)
                numberMap.erase(prevValue);
        }

        indexMap[index] = number;
        numberMap[number].insert(index);
    }

    int find(int number)
    {
        if (numberMap.find(number) == numberMap.end())
            return -1;

        for (auto i : numberMap[number])
        {
            return i;
        }

        return 0;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */