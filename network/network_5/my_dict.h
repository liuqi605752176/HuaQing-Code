//
// Created by liuqi on 18-4-13.
//

#ifndef NETWORK_5_MY_DICT_H
#define NETWORK_5_MY_DICT_H

#define PORT 50000

#if 0
#define IP "192.168.40.133"
#endif
#if 1
#define IP "172.25.1.176"
#endif
#define REGISTER 1
#define LOGIN 2
#define QUIT 3

#define QUERY_WORD 4
#define HISTORY_RECORD 5



typedef struct msg{
    int type;
    char name[20];
    char data[256];

}MSG;

#endif //NETWORK_5_MY_DICT_H
