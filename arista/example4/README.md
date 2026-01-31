### Much simpler way to write a C script to manage devices using ssh
- I've read that this is NOT the recommended way to access devices..... And that the libssh is the more appropriate method (So go back to example3 for more details), the reason being reponse and error handling by the system is not equipped to deal with called application responses programatically. But for quick easy use this is fine.
- Cleaned up safer version of the script is c_sshv2.c
  - use of snprintf() is considered better practice to avoid buffer overruns 
- So I will say this was a hell of a lot easier than using libssh.
- I used **stdlib.h** with **system()** which can call shell commands, and in my case ssh.
- I did install sshpass to call the password in the script so I didn't have to keep entering it while the script was running.
- This script was a good lesson in utilizing tools that are already at our disposal, its just a matter of taking advantage of them.

Commands file
```
$ cat commands.txt 
enable
show ip int brief
show version
show bgp evpn
$
```
Execute script
```
$ ./c_sshv2 admin
Running c version: 202000
Connecting to leaf1a
Running command: sshpass -p 'admin' ssh admin@leaf1a < commands.txt
Pseudo-terminal will not be allocated because stdin is not a terminal.
Warning: Permanently added 'leaf1a' (ED25519) to the list of known hosts.
                                                                        Address
Interface       IP Address          Status     Protocol          MTU    Owner  
--------------- ------------------- ---------- ------------- ---------- -------
Ethernet49      10.1.0.1/31         up         up               1500           
Loopback0       1.1.1.1/32          up         up              65535           
Loopback1       1.1.1.101/32        up         up              65535           
Management0     10.0.0.4/24         up         up               1500           
Vlan20          10.0.20.2/24        up         up               1500           
Vlan4094        10.255.255.5/30     up         up               1500           

Arista cEOSLab
Hardware version: 
Serial number: FB1C1889E98DF0D0209179451A0F65AA
Hardware MAC address: 001c.73c2.ce1d
System MAC address: 001c.73c2.ce1d

Software image version: 4.34.1F-41910228.orinocorel (engineering build)
Architecture: aarch64
Internal build version: 4.34.1F-41910228.orinocorel
Internal build ID: 81163ad0-9b7a-4970-994c-32d9d3d2ccdb
Image format version: 1.0
Image optimization: None

Kernel version: 6.17.8-orbstack-00308-g8f9c941121b1

Uptime: 50 minutes
Total memory: 8186988 kB
Free memory: 289764 kB

BGP routing table information for VRF default
Router identifier 1.1.1.1, local AS number 65001
Route status codes: * - valid, > - active, S - Stale, E - ECMP head, e - ECMP
                    c - Contributing to ECMP, % - Pending best path selection
Origin codes: i - IGP, e - EGP, ? - incomplete
AS Path Attributes: Or-ID - Originator ID, C-LST - Cluster List, LL Nexthop - Link Local Nexthop

          Network                Next Hop              Metric  LocPref Weight  Path
 * >      RD: 65000:20020 imet 20020 1.1.1.101
                                 -                     -       -       0       i
 * >      RD: 65000:20020 imet 20020 1.1.1.103
                                 1.1.1.103             -       100     0       65000 65002 i
Connecting to leaf1b
Running command: sshpass -p 'admin' ssh admin@leaf1b < commands.txt
Pseudo-terminal will not be allocated because stdin is not a terminal.
Warning: Permanently added 'leaf1b' (ED25519) to the list of known hosts.
                                                                        Address
Interface       IP Address          Status     Protocol          MTU    Owner  
--------------- ------------------- ---------- ------------- ---------- -------
Ethernet49      10.1.0.3/31         up         up               1500           
Loopback0       1.1.1.2/32          up         up              65535           
Loopback1       1.1.1.102/32        up         up              65535           
Management0     10.0.0.5/24         up         up               1500           
Vlan20          10.0.20.3/24        up         up               1500           
Vlan4094        10.255.255.6/30     up         up               1500           

Arista cEOSLab
Hardware version: 
Serial number: F263EA0C3ED7F9BBCE835C04B68C3464
Hardware MAC address: 001c.73ff.675e
System MAC address: 001c.73ff.675e

Software image version: 4.34.1F-41910228.orinocorel (engineering build)
Architecture: aarch64
Internal build version: 4.34.1F-41910228.orinocorel
Internal build ID: 81163ad0-9b7a-4970-994c-32d9d3d2ccdb
Image format version: 1.0
Image optimization: None

Kernel version: 6.17.8-orbstack-00308-g8f9c941121b1

Uptime: 50 minutes
Total memory: 8186988 kB
Free memory: 283688 kB

BGP routing table information for VRF default
Router identifier 1.1.1.2, local AS number 65001
Route status codes: * - valid, > - active, S - Stale, E - ECMP head, e - ECMP
                    c - Contributing to ECMP, % - Pending best path selection
Origin codes: i - IGP, e - EGP, ? - incomplete
AS Path Attributes: Or-ID - Originator ID, C-LST - Cluster List, LL Nexthop - Link Local Nexthop

          Network                Next Hop              Metric  LocPref Weight  Path
 * >      RD: 65000:20020 imet 20020 1.1.1.102
                                 -                     -       -       0       i
 * >      RD: 65000:20020 imet 20020 1.1.1.103
                                 1.1.1.103             -       100     0       65000 65002 i
Connecting to leaf2
Running command: sshpass -p 'admin' ssh admin@leaf2 < commands.txt
Pseudo-terminal will not be allocated because stdin is not a terminal.
Warning: Permanently added 'leaf2' (ED25519) to the list of known hosts.
                                                                        Address
Interface        IP Address        Status      Protocol          MTU    Owner  
---------------- ----------------- ----------- ------------- ---------- -------
Ethernet1        10.1.0.5/31       up          up               1500           
Ethernet2        10.1.0.7/31       up          up               1500           
Loopback0        1.1.1.3/32        up          up              65535           
Loopback1        1.1.1.103/32      up          up              65535           
Management0      10.0.0.6/24       up          up               1500           
Vlan20           10.1.20.1/24      up          up               1500           

Arista cEOSLab
Hardware version: 
Serial number: 6F51963E504EA214D458B3E24DC1E3BF
Hardware MAC address: 001c.7313.535d
System MAC address: 001c.7313.535d

Software image version: 4.34.1F-41910228.orinocorel (engineering build)
Architecture: aarch64
Internal build version: 4.34.1F-41910228.orinocorel
Internal build ID: 81163ad0-9b7a-4970-994c-32d9d3d2ccdb
Image format version: 1.0
Image optimization: None

Kernel version: 6.17.8-orbstack-00308-g8f9c941121b1

Uptime: 50 minutes
Total memory: 8186988 kB
Free memory: 284532 kB

BGP routing table information for VRF default
Router identifier 1.1.1.3, local AS number 65002
Route status codes: * - valid, > - active, S - Stale, E - ECMP head, e - ECMP
                    c - Contributing to ECMP, % - Pending best path selection
Origin codes: i - IGP, e - EGP, ? - incomplete
AS Path Attributes: Or-ID - Originator ID, C-LST - Cluster List, LL Nexthop - Link Local Nexthop

          Network                Next Hop              Metric  LocPref Weight  Path
 * >      RD: 65000:20020 imet 20020 1.1.1.101
                                 1.1.1.101             -       100     0       65000 65001 i
 * >      RD: 65000:20020 imet 20020 1.1.1.102
                                 1.1.1.102             -       100     0       65000 65001 i
 * >      RD: 65000:20020 imet 20020 1.1.1.103
                                 -                     -       -       0       i
toddriemenschneider@clab:~/cloned_repo/containerlabs_sandbox/ceos_lab/lab4/scripts$
```
  
```
todd@todd-TOSHIBA-DX735:~/Code_folder/containerlab/containerlabs_sandbox/ceos_lab/lab1$ ./c_ssh admin
Connecting to clab-lab1-ceos1
Running command sshpass -p admin ssh admin@clab-lab1-ceos1 < commands.txt
Pseudo-terminal will not be allocated because stdin is not a terminal.
Warning: Permanently added 'clab-lab1-ceos1' (ED25519) to the list of known hosts.
                                                                        Address
Interface       IP Address          Status      Protocol         MTU    Owner  
--------------- ------------------- ----------- ------------- --------- -------
Management0     172.20.20.2/24      up          up              1500           

interface Loopback1
   description test_script
   ip address 1.1.1.1/32
                                                                        Address
Interface       IP Address         Status      Protocol          MTU    Owner  
--------------- ------------------ ----------- ------------- ---------- -------
Loopback1       1.1.1.1/32         up          up              65535           
Management0     172.20.20.2/24     up          up               1500           

                                                                        Address
Interface       IP Address          Status      Protocol         MTU    Owner  
--------------- ------------------- ----------- ------------- --------- -------
Management0     172.20.20.2/24      up          up              1500           

Connecting to clab-lab1-ceos2
Running command sshpass -p admin ssh admin@clab-lab1-ceos2 < commands.txt
Pseudo-terminal will not be allocated because stdin is not a terminal.
Warning: Permanently added 'clab-lab1-ceos2' (ED25519) to the list of known hosts.
                                                                        Address
Interface       IP Address          Status      Protocol         MTU    Owner  
--------------- ------------------- ----------- ------------- --------- -------
Management0     172.20.20.5/24      up          up              1500           

interface Loopback1
   description test_script
   ip address 1.1.1.1/32
                                                                        Address
Interface       IP Address         Status      Protocol          MTU    Owner  
--------------- ------------------ ----------- ------------- ---------- -------
Loopback1       1.1.1.1/32         up          up              65535           
Management0     172.20.20.5/24     up          up               1500           

                                                                        Address
Interface       IP Address          Status      Protocol         MTU    Owner  
--------------- ------------------- ----------- ------------- --------- -------
Management0     172.20.20.5/24      up          up              1500           


```
