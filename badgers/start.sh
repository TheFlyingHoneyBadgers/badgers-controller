#!/bin/bash

echo "=========================="
echo "Starting App badgers for {APP_PRETTY_NAME}"


systemctl start badgerscontroller
systemctl start rosnodeChecker
