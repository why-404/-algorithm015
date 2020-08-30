//设置双端循环队列
class MyCircularDeque {
public:
    vector<int> v;
    int cur;
    int size;

    MyCircularDeque(int k) {
        size = k;
        cur = 0;
    }

    bool insertFront(int value) {
        if (cur >= size)  
            return false;

        v.insert(v.begin(), value);
        ++cur;
        return true;
    }

    bool insertLast(int value) {
        if (cur >= size)
            return false;

        v.push_back(value);
        ++cur;
        return true;
    }

    bool deleteFront() {
        if (cur == 0) 
            return false;

        v.erase(v.begin());
        --cur;
        return true;
    }

    bool deleteLast() {
        if (cur == 0) 
            return false;

        v.pop_back();
        --cur;
        return true;
    }

    int getFront() {
        if (cur != 0) 
            return v[0];
        else
            return -1;
    }

    int getRear() {
        if (cur != 0) 
            return v[cur - 1];
        else
            return -1;
    }

    bool isEmpty() {
        return cur == 0;
    }

    bool isFull() {
    	return cur == size; 
    }
};