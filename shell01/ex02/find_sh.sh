#!/bin/bash
find . -name "*.sh" -type f -exec basename -s .sh {} \;
