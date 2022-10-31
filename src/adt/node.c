#include <stdio.h>
#include <stdlib.h>

#include "node.h"

Address newNode(int val) {
    Address res = (Address)malloc(sizeof(Node));
    // ListDin lmao; CreateListDin(&lmao, 2);
    if (res != NULL) {
        INFO(res) = val;
        CHILD_COUNT(res) = 0;
        BUFFER(res) = NULL;
    }

    return res;
}

int getChildCount(Node a) {
    return CHILD_COUNT(&a);
}
