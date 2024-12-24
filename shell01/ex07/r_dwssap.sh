cat /etc/passwd | sed -n 'n;p' | awk -F ":" '{print $1}' | rev | sort -r | sed -E 's/,[ ]$/./' | sed -n "${FT_LINE1},${FT_LINE2}p" | tr -s '\n' ", " | sed -E 's/[,]$/./' | sed -E 's/,/, /g'
