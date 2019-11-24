#! /bin/bash

grep -i "$1" << EOF
1 korea
2 china
3 japan
4 usa
5 kKorea
6 koreaa
EOF
