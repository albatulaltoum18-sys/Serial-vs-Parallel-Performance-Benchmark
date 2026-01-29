#!/bin/bash
echo "=== Parallel Lab  ==="
echo "User:     $(whoami)"
echo "Now:      $(date -Iseconds)"
echo "Host:     $(hostnamectl --static 2>/dev/null || hostname)"
echo "Kernel:   $(uname -r)"
echo "MACs:"
ip link | awk '/link\/ether/ {print "  - "$2}'
echo "machine-id: $(cat /etc/machine-id 2>/dev/null)"
echo "UUID:       $(cat /sys/class/dmi/id/product_uuid 2>/dev/null)"
echo "CWD:        $(pwd)"
echo "====================="