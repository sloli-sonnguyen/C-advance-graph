#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
#include "jrb.h"
#include "dllist.h"
#include "jval.h"

int main()
{
    // khai bao cay va nut trung gian
    JRB root = make_jrb();
    JRB traverNode;
    int count = 0; // dem khi nhap 3 chuoi thi dung
    // doc input string
    IS is;
    is = new_inputstruct(NULL);
    // check input
    while (get_line(is) >= 0)
    {
        // add key voi kieu string
        // de new jval null vi o bai nay ta khogn dung den value
        jrb_insert_str(root, strdup(is->text1), new_jval_v(NULL));
        count++;
        if (count == 3)
            break;
    }

    // duyet cay ( than so--> nut trung gian va root)
    jrb_traverse(traverNode, root)
    {
        // edit code minh muon
        // o day muon in ra key
        printf("\nKey cua cay nay ne: %s", jval_s(traverNode->key));
    }

    exit(0);
}