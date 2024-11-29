#!/bin/bash

os_info=$(uname -a)

cpu_cores=$(grep "physical id" /proc/cpuinfo | wc -l)
cpu_cores=$(printf "CPU cores\t:\t\t%i" "$cpu_cores")
cpu_vcores=$(grep "processor" /proc/cpuinfo | wc -l)
cpu_vcores=$(printf "vCPU cores\t:\t\t%i" "$cpu_vcores")
memory=$(free -m | grep "Mem:" | awk '{printf("Memory usage\t:\t\t%i / %i MB (%.2f%%)", $3, $2, 100 / $2 * $3)}')
disk_space=$(df -m | grep "/dev/" | grep -v "boot" | awk '{used += $3} {available += $4} END {printf("Diske usage\t:\t\t%i / %i (%i%%)\n", used / 1024, available / 1024, 100 / available * used)}')
cpu_load=$(vmstat 1 4 | tail -1 | awk '{printf("CPU load \t:\t\t%.1f%%", 100 - $15)}')
last_boot=$(who -b | grep "system" | awk '{printf("Last boot time\t:\t\t%s %s\n", $3, $4)}')
is_lvm=$(if lsblk | grep -q "lvm";  then echo yes; else echo no; fi)
is_lvm=$(printf "LVM active\t:\t\t%s" "$is_lvm")
tcp_con=$(ss -ta | grep "ESTAB" | wc -l)
tcp_con=$(printf "active TCP connectoin \t:\t\t%i" "$tcp_con")
user_nbr=$(printf "Logged-in users\t:\t\t%i" "$(users | wc -w)")
