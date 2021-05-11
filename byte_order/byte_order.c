#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>


int main(int argc,char * argv[]) {
    u_int32_t ipv4_h, ipv4_n;
    u_int16_t port_h, port_n;

    ipv4_n = atoi(argv[1]);

    // Divide ipv4_net in four bytes
    unsigned char a[4] = {0};
    inet_pton(AF_INET,argv[1], a);
    ipv4_n = a[0]*16*16*16 + a[1]*16*16 + a[2]*16 + a[3]*1;
    ipv4_h = ntohl(ipv4_n);
    printf("%04X", ipv4_h);

    port_n = atoi(argv[2]); // Convert string to integer
    port_h = ntohs(port_n); // Convert network byte order to host byte order

    // ...
    port_n = htons(port_h);
    port_h = ntohl(port_n);

    // Ipv4_net, char by char, dot_decimal
    printf("[ipv4_n_cbc_d]%s\n", argv[1]);



    // Ipv4_net, char by char, hexadecimal
    printf("[ipv4_n_cbc_x]");
    for (int i = 0; i < sizeof a/sizeof a[1]; i++)
    {
        printf("%X", a[i]);
    }
    printf("\n");

    // Ipv4_net, as whole, hexadecimal
    printf("[ipv4_n_asw_x]");
    for (int i = sizeof a/sizeof a[1] - 1; i >= 0; i--)
    {
        printf("%02X", a[i]);
    }
    printf("\n");

    // Port_net, char by char, hexadecimal
    printf("[port_n_cbc_x]%04X\n",port_n);

    // Port_net, as whole, hexadecimal
    printf("[port_n_asw_x]%04X\n", port_h);

    // Port_net, as whole, hexadecimal
    printf("[port_n_asw_d]%d\n", port_h);

    // Ipv4_host, char by char, dot_decimal
    printf("[ipv4_h_cbc_d]");
    for (int i = sizeof a/sizeof a[1] - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
        if (i != 0)
        {
            printf(".");
        }
    }
    printf("\n");

    // Ipv4_host, char by char, hexadecimal
    printf("[ipv4_h_cbc_x]");
    for (int i = sizeof a/sizeof a[1] - 1; i >= 0; i--)
    {
        printf("%02X", a[i]);
    }
    printf("\n");

    // Ipv4_host, as whole, hexadecimal
    printf("[ipv4_h_asw_x]");
    for (int i = 0; i < sizeof a/sizeof a[1]; i++)
    {
        printf("%02X", a[i]);
    }
    printf("\n");

    // Port_host, char by char, hexadecimal
    printf("[port_h_cbc_x]%04X\n", port_h);

    // Port_host, as whole, hexadecimal
    printf("[port_h_asw_x]%X\n", port_n);

    // Port_host, as whole, dat_decimal
    printf("[port_h_asw_d]%d\n", port_n);

    return 0;
}
