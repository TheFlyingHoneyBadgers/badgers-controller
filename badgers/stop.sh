#!/bin/bash

echo "=========================="
echo "Stopping App badgers"

systemctl stop rosnodeChecker
systemctl stop badgerscontroller
