#!/bin/bash
ifconfig | grep -o '\([0-9a-f]\{2\}:\)\{5\}[0-9a-f]\{2\}'
