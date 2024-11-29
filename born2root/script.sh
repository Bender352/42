#!/bin/bash

os_info=$(uname -a)

cpu_cores=$(grep "physical id" /proc/cpuinfo | wc -l)
cpu_cores=$(printf "%-22s %-3s %-25i\n" "CPU cores" ":" "$cpu_cores")

cpu_vcores=$(grep "processor" /proc/cpuinfo | wc -l)
cpu_vcores=$(printf "%-22s %-3s %-25i\n" "vCPU cores" ":" "$cpu_vcores")

memory=$(free -m | grep "Mem:" | awk '{printf("%-22s %-3s %i / %i MB (%.2f%%)\n", "Memory usage", ":", $3, $2, 100 * $3 / $2)}')

disk_space=$(df -m | grep "/dev/" | grep -v "boot" | awk '{used += $3} {available += $4} END {printf("%-22s %-3s %i / %i GB (%i%%)\n", "Disk usage", ":", used / 1024, available / 1024, 100 * used / available)}')

cpu_load=$(vmstat 1 4 | tail -1 | awk '{printf("%-22s %-3s %.1f%s\n", "CPU load", ":", 100 - $15, "%%")}')

last_boot=$(who -b | grep "system" | awk '{printf("%-22s %-3s %s %s\n", "Last boot time", ":", $3, $4)}')

is_lvm=$(if lsblk | grep -q "lvm";  then echo yes; else echo no; fi)
is_lvm=$(printf "%-22s %-3s %s\n" "LVM active" ":" "$is_lvm")

tcp_con=$(ss -ta | grep "ESTAB" | wc -l)
tcp_con=$(printf "%-22s %-3s %i\n" "Active TCP connections" ":" "$tcp_con")

user_nbr=$(users | wc -w)
user_nbr=$(printf "%-22s %-3s %i\n" "User logged" ":" "$user_nbr")

mac_add=$(ip address | grep "link/ether" | awk '{print $2}')
ip_add=$(hostname -I | awk '{print $1}')
nic=$(printf "%-22s %-3s %s (%s)\n" "Network" ":" "$ip_add" "$mac_add")

sudo_exe=$(journalctl _COMM=sudo | grep "sudo" | wc -l)
sudo_exe=$(printf "%-22s %-3s %i\n" "Sudo executions" ":" "$sudo_exe")


wall "$os_info
$cpu_cores
$cpu_vcores
$memory
$disk_space
$cpu_load
$last_boot
$is_lvm
$tcp_con
$user_nbr
$nic
$sudo_exe
"

