/**
 * License: MIT License
 * 
 * greensea <gs@bbxy.net>
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


unsigned int hostnum2subnet(uint32_t num) {
    unsigned int ret = 32;
    
    while (num != 1) {
        num >>= 1;
        ret--;
    }
    
    
    return ret;
}

void parse_line(char* line) {
    char* ip;
    char *numstr;
    int num;
    
    /// 过滤出中国的地址
    if (strstr(line, "CN") == NULL) {
        return;
    }
    if (strstr(line, "ipv4") == NULL) {
        return;
    }
    
    /// 提取 IP 地址和主机数量
    strtok(line, "|");
    strtok(NULL, "|");
    strtok(NULL, "|");
    
    ip = strtok(NULL, "|");
    numstr = strtok(NULL, "|");
    
    /// 输出网段
    num = atoi(numstr);
    printf("%s/%d\n", ip, hostnum2subnet(num));
}

int main(int argc, char* argv[]) {
    char* line;
    size_t linesize;
    

    while (getline(&line, &linesize, stdin) != -1) {
        parse_line(line);
    }
    
    return 0;
}
