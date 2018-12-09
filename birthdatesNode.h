//
// Created by eldoradocoder on 12/8/18.
// Hash node template class that assigns keys
//

#ifndef LAB6_CRS_HASHNODE_H
#define LAB6_CRS_HASHNODE_H

#include <cstring>

template <typename birthday, typename name> // K = bday, V = name
class birthdatesNode {
public:

    birthdatesNode(const birthday &key, const name &value) :
            key(key), value(value), next(NULL) {
    }

    birthday getBday() const {
        return key;
    }

    name getName() const {
        return value;
    }

    void setName(name value) {
        birthdatesNode::value = value;
    }

    birthdatesNode *getNext() const {
        return next;
    }

    void setNext(birthdatesNode *next) {
        birthdatesNode::next = next;
    }

private:
    //Key & value pair
    birthday key;
    name value;

    //Points to the next bucket with matching key
    birthdatesNode *next;
};


#endif //LAB6_CRS_HASHNODE_H
