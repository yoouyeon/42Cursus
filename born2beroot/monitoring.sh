#!/bin/bash
arch=$(uname -a)
pcpu=$(cat /proc/cpuinfo | grep "physical id" | sort | uniq | wc -l)
vcpu=$(cat /proc/cpuinfo | grep "processor" | wc -l)
mem=$(free -m | grep "Mem" | awk '{printf "%d/%dMB (%.2f%%)", $3, $2, $3/$2*100}')
tdisk=$(fd -BM --total | grep "total" | tr -d "M" | awk "{print $2}")
udisk=$(fd -BM --total | grep "total" | tr -d "M" | awk "{print $3}")
pdisk=$(fd -BM --total | grep "total" | tr -d "%" | awk "{print $5}")
dusage="${udisk}/${tdisk}MB (${pdisk}%)"
cpul=$(mpstat | grep "all" | awk '{print 100 - $13}')
lb=$(who -b | awk '{print $3" "$4}')
lvmc=$(lsblk | grep "lvm" | wc -l)
lvmu=$(if [ ${lvmc} -gt 0 ]; then printf "yes"; else printf "no"; fi)
ctcp=$(ss | grep "tcp" | wc -l)
ulog=$(who | wc -l)
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')
cmds=$(cat /var/log/auth.log | grep "sudo" | grep "COMMAND=" | wc -l)

wall "	#Architecture: ${arch}
	#CPU physical: ${pcpu}
	#vCPU: ${vcpu}
	#Memory Usage: ${mem}
	#Disk Usage: ${dusage}
	#CPU load: ${cpul}
	#Last boot: ${lb}
	#LVM use: ${lvmu}
	#Connexions TCP: ${ctcp} ESTABLISHED
	#User log: ${ulog}
	#Network: IP ${ip} (${mac})
	#Sudo: ${cmds}cmd"