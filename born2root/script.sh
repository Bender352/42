vmstat 1 4 | tail -1 | awk '{printf("CPU idle time\t\t%s\n", $15)}
df -m | grep "/dev/" | grep -v "boot" | awk '{used += $3} {available += $4} END {printf("Available space on disk\t\t%i / %i (%i%%)\n", used, available, 100 / available * used)}'
who -b | grep "system" | awk '{printf("Last boot time:\t\t%s %s\n", $3, $4)}'
